//
// File        : $RCSfile: $ 
//               $Workfile: main.cpp $
// Version     : $Revision: 64 $ 
//               $Author: Aviad $
//               $Date: 16/12/04 6:18 $ 
// Description :
//    main routine for the seed-searcher program
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//
#include "main.h"
#include "Parser.h"

#include "SequenceDB.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"
#include "HyperGeoScore.h"
#include "PSSM.h"
#include "SeedSearcherMain.h"

#include "StdOptions.h"
#include "DebugLog.h"

#include "core/AutoPtr.h"
#include "persistance/StdInputStream.h"
#include "persistance/StrOutputStream.h"

#include "status_reporter/BaseStatusReporter.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <boost/filesystem/path.hpp>

using namespace std;
using namespace Persistance;


//
//
enum {
   SeqFileIndex = 0,
   WgtFileIndex = 1,
   StubFileIndex = 2,
   RequiredParams = 3,
   TestWgtFileIndex = 3,
};






static void printGoodbye (time_t start, time_t finish)
{
   std::string timeStr = ctime (&finish);
   //
   // remove the NEWLINE at the end of the string
   timeStr [timeStr.length () - 1] = '\0';

   DLOG << '#' << DLOG.EOL ()
      << "# summary" << DLOG.EOL ()
      << "Execution ended on " <<  timeStr.c_str ()
      << " after running " << (finish - start) << " seconds."
      << DLOG.EOL ();
   DLOG.flush ();
}



static void welcomeMessage ()
{
   //
   // (1) write header, and execution time
   DLOG  << "SeedSearcher v" 
         << main_definitions::__versionMajor << '.' 
         << main_definitions:: __versionMinor;
   debug_only (
      DLOG << " (Debug)";
   );
#ifdef __TIMESTAMP__
   DLOG << " Compiled on " << __TIMESTAMP__;
#endif

   DLOG << DLOG.EOL ()
        << "by Yoseph Barash (hoan@cs.huji.ac.il)" << DLOG.EOL ()
        << "and Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ()
        << DLOG.EOL ();
   DLOG.flush ();
}


static void welcomeMessage (const Parser& parser)
{
   time_t ltime;
   time( &ltime );
   DLOG << DLOG.EOL ()
        << "Execution started on " << ctime( &ltime ) << DLOG.EOL ();
   //
   // (2) write execution line
   DLOG  << '#' << DLOG.EOL () 
         << "# command line" << DLOG.EOL ();

   for (int i=0 ;i<parser.__argv.argc (); i++)
      DLOG << parser.__argv.argv ()[i] << ' ';
   DLOG << DLOG.EOL ();

   DLOG  << DLOG.EOL ();
   DLOG  << '#' << DLOG.EOL () 
         << "# execution parameters " << DLOG.EOL ();
   parser.logParams (DLOG);
}




static time_t cleanupStart = 0, cleanupFinish;
static time_t start = time (NULL), finish;

static void mainRoutine (int argc, 
                        char* argv []);

//
// Copied/Adapted from legacy SeedSearcher
int cpp_main(int argc, char* argv [])
{
int exit_value = 0;
   try {
	   Argv anArgv;
      StatusReportManager::Sentry report( argc, argv, anArgv );
   
      //
      // setup basic logging
      SeedSearcherLog::setupConsoleLogging ( /* dont supress */ false);
      mainRoutine ( anArgv.argc(), anArgv.argv() );

      if (cleanupStart) {
         cleanupFinish = time(NULL);
         DLOG << (cleanupFinish - cleanupStart) << " seconds." << DLOG.EOL ();
         DLOG.flush ();
      }

      StatusReportManager::setJobDone ();
   }
   catch (BaseStatusReporter::StatusException& x) {
      //
      // write exception info
      cerr << endl;
      x.explain (cerr);
      cerr << endl;
      exit_value = 1;

      try {
	//
	// aborted by user, 
	StatusReportManager::setJobCancelled ();
      }
      catch (...) {
	cerr << endl << "StatusReportManager Error" << endl;
      }
   }
   catch (BaseException& x) {
      //
      // processing error
      std::string buffer;
      {  std::ostringstream stream;
         x.explain(stream);
         buffer = stream.str ();
      }

      //
      // write exception info
      cerr << endl;
      cerr << buffer;
      cerr << endl;
      exit_value = 1;

      try {
	StatusReportManager::setJobError(Str (buffer));
      }
      catch (...) {
	cerr << endl << "StatusReportManager Error" << endl;

      }
   }
   catch (...) {
     try {
      StatusReportManager::setJobError("Unknown Error");
     }
     catch (...) {
	cerr << endl << "StatusReportManager Error" << endl;
     }
      throw;
   }

   return exit_value;
}

const char main_definitions::MOTIF_FILE_STUB[] = "motifs";
const char main_definitions::PSSM_FILE_STUB[] = "pssm";
const char main_definitions::SAMPLE_FILE_STUB[] = "sample";
const char main_definitions::SEEDS_FILE_STUB[] = "seeds";
const char main_definitions::MATRIX_FILE_STUB[] = "matrix";


static void printSeedFile (TextTableReport::TextOutput& seedsFile,
                           FeatureInvestigator& printer,
                           Parser::OutputType gPSSM,
                           Parser::OutputType gMotif,
                           Parser::OutputType gSample,
                           PositionVector pos,
                           PositionVector neg,
                           const char* fileStub,
                           Feature& feature,
                           int index)
{
   printer.printSeed (seedsFile, feature, pos);
   Parser::OutputType outputs [3] = { gMotif, gPSSM, gSample };
   const char* names [] = { main_definitions::MOTIF_FILE_STUB, 
                            main_definitions::PSSM_FILE_STUB, 
                            main_definitions::SAMPLE_FILE_STUB };

   for (int i=0 ; i<3; i++) {
      if (outputs[i] != Parser::_out_none_)  {
         char buffer [8096];
         main_definitions::getOutputFileName(buffer, true, index, fileStub, names [i]);
         boost::filesystem::path leaf (buffer);
         seedsFile << Str (leaf.leaf ()) << '\t';
      }
      else {
         seedsFile << "-----" << '\t';
      }
   }

   seedsFile.writeln();
}

static void printSeqMatrix (SeedSearcherMain::Results& results)
{
   TextTableReport::TextOutput matrixFile (
      main_definitions::openFile (true, -1, 
                                 StrBuffer (results.getParameters ().name ()), 
                                 main_definitions::MATRIX_FILE_STUB));
   //
   // create the format of the table
   // the first column is the name of the sequence
   // the next columns are names of the motifs
   Persistance::TextTableReport::Format format;
   format.addField("Seq-Name", 13);
   FeatureSet::Iterator feature_it = results.getFeatures ().getIterator();
   for (; feature_it.hasNext() ; feature_it.next()) {
      std::string feature_name;
      {  Persistance::TextWriter writer (new Persistance::StrOutputStream (feature_name));
         writer << Format ((*feature_it)->assignment ());
      }
      format.addField (Str (feature_name), feature_name.length () + 1);
   }

   //
   // get the seq iterator and the weight function
   SequenceDB::SequenceIterator it = 
      results.getParameters ().db ().sequenceIterator ();
   const SeqWeightFunction& wf = results.getParameters ().wf ();

   //
   // go over all sequences
   for (; it.hasNext () ; it.next ()){
      //
      // skip non positive sequences
      const Sequence* seq = it.get ();
      if (!wf.isPositive (*seq))
         continue;

      Persistance::TextTableReport::Data data (format);
      data.writeField((*it)->name ());

      //
      // go over all results
      FeatureSet::Iterator feature_it = results.getFeatures ().getIterator ();
      for (; feature_it.hasNext() ; feature_it.next ()) {
         Feature& feature = *(feature_it.get ());
         debug_mustbe (feature.cluster ().hasPositions ());
         PosCluster* posCluster = feature.cluster ().getPositions(*it);
         //
         // 
         if (posCluster != NULL) {
            int numPositions = posCluster->size ();
            data.writeField (FixedStrBuffer <128> ("%d", numPositions));
         }
         else
            data.writeField ("0");
      }

      matrixFile << data;
   }
}


class ApplicationMain : public SeedSearcherMain {
public:
protected:
   virtual void beforeSearch (Parameters& nextParameters) {
      DLOG << DLOG.EOL () << DLOG.EOL ();
      DLOG << "Performing search";
      if (!nextParameters.name ().empty ()) {
         boost::filesystem::path leaf (nextParameters.name ().getChars ());
         DLOG << ' ' << Str(leaf.leaf ());
      }

      DLOG << ':' << DLOG.EOL();
      DLOG.flush ();
   }
   //
   // prints results after a search
   virtual void afterSearch (Results& results) {
      SeedSearcherMain::afterSearch (results);

      SeedSearcherMain::CmdLineParameters& params = 
         *safe_cast (CmdLineParameters*, &results.getParameters ());

      int bonfN = 
         params.parser ().__score_bonf? results.numSeedsSearched () : 0;
      FeatureInvestigator printer ( params                     , 
                                    params.parser ().__seed_o  ,
                                    bonfN                      ,
                                    results.numProjectionsSearched ()
                                    );

      Parser::OutputType gPSSM = params.parser ().__generatePSSM;
      Parser::OutputType gMotif = params.parser ().__generateMotif;
      Parser::OutputType gBayesian = params.parser ().__generateBayesian;
      

      //
      // should we generate a file that contains only the seeds?
      bool gSeeds =  (gMotif  != Parser::_out_none_)  ||
                     (gPSSM   != Parser::_out_none_)  ||
                     (gBayesian != Parser::_out_none_);

      StrBuffer fileStub (params.name ());

      TextTableReport::TextOutput seedsFile (
         gSeeds? 
         main_definitions::openFile (true, -1, fileStub, main_definitions::SEEDS_FILE_STUB) : new NullOutputStream ()
      );
      seedsFile.skipHeader ();
      seedsFile.noNewlineAfterRecord ();

      //
      // we print the results to the log
      PositionVector pos;
      PositionVector neg;
      Persistance::TextTableReport::TextOutput dlog (DLOG);
      FeatureSet::Iterator feature_it = results.getFeatures ().getIterator();
      for (int i=0; feature_it.hasNext() ; feature_it.next(), ++i) {

         Feature& feature = *(feature_it.get ());

         //
         // first we find the positive and negative positions
         // of this feature
         pos.clear();
         neg.clear();
         printer.addPositions (feature, pos, neg);

         main_definitions::printMotif (dlog, printer, 
                     gPSSM, gMotif, gBayesian, 
                     pos, neg, 
                     fileStub, feature, i
                     );
         dlog.writeln ();

	      if (gSeeds) {
	         printSeedFile (seedsFile, printer,
			      gPSSM, gMotif, gBayesian,
			      pos, neg, 
			      fileStub, feature, i
			      );
	      }
      }
      seedsFile.flush ();
      if (gSeeds) {
         printSeqMatrix (results);
      }
   }
}; 



static void mainRoutine (int argc, 
                        char* argv [])
{
   welcomeMessage ();

   //
   // parse the arguments
   ConfParameterIterator confParamaters (argc, argv);
   const Parser& parser = confParamaters.getInitParser ();

   //
   // write welcome message with all parameters
   welcomeMessage(parser);

   //
   // check that we have enough arguments
   // needs SeqFile RegFile and output-stub
   int numOfFileArgs = parser.getNumFileArgs ();
   if(numOfFileArgs < RequiredParams)
      parser.usage ("Missing arguments");

   //
   // create the preprocessor and other initial data
   confParamaters.setup (  argv [parser.__firstFileArg + SeqFileIndex],
                           argv [parser.__firstFileArg + WgtFileIndex],
                           argv [parser.__firstFileArg + StubFileIndex]);

   //
   // this takes care of all searching and printing of seeds
   ApplicationMain application;
   application.search (confParamaters);

   finish = time(NULL);
   printGoodbye (start, finish);
   DLOG << DLOG.EOL () << "Cleaning up...";
   time (&cleanupStart);
}


#if SEED_DL_MALLOC_OPTIMIZATION

#include "core/dlmalloc.h"

void* operator new (size_t inSize) 
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void* operator new (size_t inSize, const std::nothrow_t&) 
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void operator delete (void* inPtr) 
{
   if (inPtr)
	   dlfree (inPtr);
}

void* operator new[] (size_t inSize) 
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void* operator new[] (size_t inSize, const std::nothrow_t& nothrow) 
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void operator delete[] (void* inPtr) 
{
   if (inPtr)
	   dlfree (inPtr);
}

#endif


