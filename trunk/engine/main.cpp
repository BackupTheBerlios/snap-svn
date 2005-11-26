//
// File        : $RCSfile: $ 
//               $Workfile: main.cpp $
// Version     : $Revision: 56 $ 
//               $Author: Aviad $
//               $Date: 1/09/04 1:24 $ 
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

#include "status_reporter/BaseStatusReporter.hpp"

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>

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

   DLOG << DLOG.EOL ();
   DLOG << "by Yoseph Barash (hoan@cs.huji.ac.il)" << DLOG.EOL ();
   DLOG << "and Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ();
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

   for (int i=0 ;i<parser.__argc ; i++)
      DLOG << parser.__argv [i] << ' ';
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
   }
   catch (BaseException& x) {
      cerr << endl;
      x.explain (cerr);
      cerr << endl;
      exit_value = 1;
   }

   return exit_value;
}

const char main_definitions::MOTIF_FILE_STUB[] = "motifs";
const char main_definitions::PSSM_FILE_STUB[] = "pssm";
const char main_definitions::SAMPLE_FILE_STUB[] = "sample";
const char main_definitions::SEEDS_FILE_STUB[] = "seeds";




static void printSeedFile (TextWriter& seedsFile,
                           FeatureInvestigator& printer,
                           Parser::OutputType gPSSM,
                           Parser::OutputType gMotif,
                           Parser::OutputType gSample,
                           PositionVector pos,
                           PositionVector neg,
                           const char* fileStub,
                           SeedSearcherMain::Results& results)
{
   printer.printSeed (seedsFile, results.getFeature (), pos);
   Parser::OutputType outputs [3] = { gMotif, gPSSM, gSample };
   const char* names [] = { main_definitions::MOTIF_FILE_STUB, 
                            main_definitions::PSSM_FILE_STUB, 
                            main_definitions::SAMPLE_FILE_STUB };

   char buffer [8096];
   for (int i=0 ; i<3; i++) {
      if (outputs[i] != Parser::_out_none_) 
         main_definitions::getOutputFileName(buffer, true, results.featureIndex (), fileStub, names [i]);
      else
         strcpy (buffer , "-----");

         seedsFile << '\t'
                   << buffer;
   }

   seedsFile.writeln();
}


class ApplicationMain : public SeedSearcherMain {
public:
protected:
   virtual void beforeSearch (Parameters& nextParameters) {
      DLOG << DLOG.EOL () << DLOG.EOL ();
      DLOG << "Performing search";
      if (!nextParameters.name ().empty ())
         DLOG << ' ' << nextParameters.name ();

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
      printer.printSeedHeader (DLOG);

      Parser::OutputType gPSSM = params.parser ().__generatePSSM;
      Parser::OutputType gMotif = params.parser ().__generateMotif;
      Parser::OutputType gBayesian = params.parser ().__generateBayesian;
      

      //
      // should we generate a file that contains only the seeds?
      bool gSeeds =  (gMotif  != Parser::_out_none_)  ||
                     (gPSSM   != Parser::_out_none_)  ||
                     (gBayesian != Parser::_out_none_);

      StrBuffer fileStub (params.name ());

      TextWriter seedsFile (
         gSeeds? 
         main_definitions::openFile (true, -1, fileStub, main_definitions::SEEDS_FILE_STUB) : new NullOutputStream ()
      );

      //
      // we print the results to the log
      for (; results.hasMoreFeatures () ; results.nextFeature ()) {

         Feature& feature = results.getFeature ();

         //
         // first we find the positive and negative positions
         // of this feature
         PositionVector pos;
         PositionVector neg;
         printer.addPositions (feature, pos, neg);

         main_definitions::printMotif (printer, 
                     gPSSM, gMotif, gBayesian, 
                     pos, neg, 
                     fileStub, feature, results.featureIndex ()
                     );

	 if (gSeeds) {
	   printSeedFile (seedsFile, printer,
			  gPSSM, gMotif, gBayesian,
			  pos, neg, 
			  fileStub, results
			  );
	 }
      }

      seedsFile.flush ();
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
   cerr << endl << "Cleaning up...";
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


