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

#include "Core/ImplList.h"
#include "Core/AutoPtr.h"
#include "Util/ConfReader.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StdOutputStream.h"
#include "Persistance/StdInputStream.h"

#include "StatusReporter/DummyStatusReporter.hpp"

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <queue>

using namespace std;
using namespace Persistance;

static const int __versionMajor = 2;
static const int __versionMinor = 2;

//
//
enum {
   SeqFileIndex = 0,
   WgtFileIndex = 1,
   StubFileIndex = 2,
   RequiredParams = 3,
   TestWgtFileIndex = 3,
};



struct MainError : public BaseException {
   MainError (std::string const & s) : _error (s) {
   }

   virtual void explain (std::ostream& out) {
      out << "Error in main: " << _error;
   }

   std::string _error;
};

//
// Copied/Adapted from legacy SeedSearcher
static void Err(std::string const & s) {
   throw MainError (s);
}


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

static Persistance::OutputStream* openFile (const char* filename)
{
    ofstream* file = new ofstream (filename,
                    ios::out | ios::trunc | ios::binary);

   if( ! file->is_open() )
      Err(string("Cannot open file for ") + filename);

   return new StdOutputStream (file, true);
}



//
//
static Persistance::OutputStream* openMotifFile (  
      bool isPositives, int index, const char* fileStub)
{
   //
   // create the motif file name
   char motifFileName [1024];
   if (isPositives)
      sprintf (motifFileName, "%s.%d.motifs", 
	       fileStub, (index+1));
   else
      sprintf (motifFileName, "%s.%d.neg.motifs", 
	       fileStub, (index+1));

   return openFile (motifFileName);
}


//
//
static Persistance::OutputStream* openPSSMFile (  
      int index, const char* fileStub)
{
   //
   // create the motif file name
   char motifFileName [1024];
   sprintf (motifFileName, "%s.%d.PSSM", 
	      fileStub, (index+1));

   return openFile (motifFileName);
}






static void welcomeMessage ()
{
   //
   // (1) write header, and execution time
   DLOG << "SeedSearcher v" << __versionMajor << '.' << __versionMinor;
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
   struct auto_report {
      auto_report () {
         //
         // setup the status report manager
         StatusReportManager::setup (
            boost::shared_ptr <BaseStatusReporter> (
               new DummyStatusReporter (NULL, NULL, NULL, NULL, 0)
            )
         );

         StatusReportManager::setJobStarted ();
      }
      ~auto_report () {
         StatusReportManager::setJobDone ();
      }
   };

   auto_report report;

   int exit_value = 0;
   try {
      //
      // setup basic logging
      SeedSearcherLog::setupConsoleLogging ( /* dont supress */ false);
      mainRoutine (argc, argv);

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


static void printMotif (FeatureInvestigator& printer,
                        bool gPSSM,
                        Parser::MotifType gMotif,
                        PositionVector pos,
                        PositionVector neg,
                        const char* fileStub,
                        SeedSearcherMain::Results& results
                        )
{
   Feature& feature = results.getFeature ();

   //
   // now we print the seed result line,
   // which includes the seed, score projection etc.
   printer.printSeed (DLOG, feature, pos);

   if (gMotif != Parser::_motif_none_) {
      //
      // now we print pos & neg motif files
      bool isPos = true;
      for (int i = 0 ; i <= 1; i++) {
         //
         // print neg only if Parser::_motif_all_ is specified
         if ((gMotif == Parser::_motif_all_) || isPos) {
            //
            // we open a file for the motif
            TextWriter motifFile (openMotifFile (  isPos, 
               results.featureIndex (),
               fileStub
               ));
            printer.printMotif ( motifFile, 
               feature, 
               isPos? pos : neg);
         }

         isPos = !isPos;
      }
   }

   //
   // now we print the PSSM files
   if (gPSSM) {
      TextWriter pssmFile (openPSSMFile ( results.featureIndex (),
         fileStub
         ));

      printer.printPSSM (pssmFile, feature, pos);
   }
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
                                    bonfN                      );
      printer.printSeedHeader (DLOG);

      bool gPSSM = params.parser ().__generatePSSM;
      Parser::MotifType gMotif = params.parser ().__generateMotif;


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

         printMotif (printer, gPSSM, gMotif, pos, neg, StrBuffer (params.name ()), results);
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
   cerr << endl << "Cleaning up...";
   time (&cleanupStart);
}


#if SEED_DL_MALLOC_OPTIMIZATION

#include "Core/dlmalloc.h"

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


