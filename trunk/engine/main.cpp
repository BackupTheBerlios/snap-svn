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

//
//
static Persistance::OutputStream* openPerfFile (  
      const char* fileStub)
{
   //
   // create the motif file name
   char motifFileName [1024];
   sprintf (motifFileName, "%s.perf", fileStub);
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


//
// how to score position for which no feature in
// the results matches?
//
// IDEA: the score for each of the features is > 0
// so the unrecognizedPosition score should be 
// somehow compareable with the worst feature score
// but not too close.
// 
// we choose unrecognizedPositionScore = worstFeatureScore / (M+1)
static double unrecognizedPositionScore (
            SeedSearcherMain::Results& results,
            SeedSearcherMain::CmdLineParameters& trainParams)
{
   const int MBestPositions = trainParams.parser ().__perf_m;

   results.lastFeature ();
   const Feature& worstFeature = results.getFeature ();
   double worstFeatureScore = - worstFeature.log2score ();
   if (worstFeatureScore > 0)
      return (worstFeatureScore / (MBestPositions + 1));
   else
      return (worstFeatureScore * (MBestPositions + 1));
}

static void initPositionScoreQueue (
                  SeedSearcherMain::Results& results,
                  SeedSearcherMain::CmdLineParameters& trainParams,
                  std::priority_queue <double>& q)
{
   const int MBestPositions = trainParams.parser ().__perf_m;

   mustbe (q.empty ());

   double dblUnrecognizedPositionScore = 
      unrecognizedPositionScore (results, trainParams);

   std::priority_queue <double> M_unrecognizedPositionScores;
   for (int i=0 ; i<MBestPositions ; i++)
      q.push (dblUnrecognizedPositionScore);
}

//
// 0) print seed scores on test data
// a) normalize scores
// b) score each position in each sequence
// c) the sequence's score is the average of the best M position scores
// D) output all positions with likelihood of having binding site
//   Name best-position-score average-sequence-score
static void testSeedPerformance (
            int argc, char* argv[],
            SeedSearcherMain::Results& results,
            SeedSearcherMain::CmdLineParameters& trainParams)
{
   const int MBestPositions = trainParams.parser ().__perf_m;
   const Parser::PerfLenComp comp_l = trainParams.parser ().__perf_comp_l;

   DLOG << "#" << DLOG.EOL ()
        << "# Performing on test data:" << DLOG.EOL ();

   //
   // the fourth arguemnt is a wgt test file
   SeedSearcherMain::CmdLineParameters testParams (argc, argv);
   testParams.setup ( 
      argv [trainParams.parser ().__firstFileArg + SeqFileIndex],
      argv [trainParams.parser ().__firstFileArg + TestWgtFileIndex]);
   DLOG.flush ();

   FeatureInvestigator printer ( testParams                     , 
                                 testParams.parser ().__seed_o  );
   printer.printSeedHeader (DLOG);

   for (results.firstFeature ();results.hasMoreFeatures();results.nextFeature ()) {
      //
      // create a feature for the seed in the test data
      const Feature& trainFeature = results.getFeature ();;
      AutoPtr <Feature> feature = 
         testParams.createFeature ( trainFeature.assignment (), 
                                    *trainFeature.projection ());

      //
      // discover positive/negative 
      PositionVector posPositions;
      PositionVector negPositions;
      printer.addPositions (*feature, posPositions, negPositions);

      //
      // now print the seed score on the test data
      printer.printSeed (DLOG, *feature, posPositions);
      DLOG.flush ();
   }

   //
   // first we normalize the seeds (if necessary)
   switch (trainParams.parser ().__score_norm) {
      case Parser::_norm_none_:
         break;

      case Parser::_norm_logit_:
         trainParams.bestFeatures ()->normalizeScoresSigmoid ();
         break;

      case Parser::_norm_linear_background_: {
         BookkeeperFilter& bookkeeper = 
            dynamic_cast <BookkeeperFilter&> (trainParams.bestFeatures ());
         bookkeeper.normalizeBackgroundScoresLinear ();
      }
      break;

         //case Parser::_norm_linear_:
         //trainParams.bestFeatures ()->normalizeScoresLinear ();
         //break;
      default:
         mustfail ();
         break;
   }

   //
   // we open file for test-data performance output
   // and begin with header line
   TextWriter perfWriter (openPerfFile (
      argv [trainParams.parser ().__firstFileArg + StubFileIndex]));

   perfWriter << "SeqName\t\tSeqWeight\tBestScoringPosition\t\tSeqScore" 
              << perfWriter.EOL ();

   std::priority_queue <double> MUnrecognizedPositions;
   initPositionScoreQueue (results,
                           trainParams,
                           MUnrecognizedPositions);

   //
   // for each sequence in the training data,
   // we want to know the score of each position 
   // (e.g. what is the best feature that it matches)
   SequenceDB::SequenceIterator seqit = testParams.db().sequenceIterator ();
   for (; seqit.hasNext (); seqit.next ()) {
      //
      // create a priority queue to hold the scores of
      // each position in this sequence.
      // the priority queue is initialized with M scores
      // for the unrecognized positions
/*
      std::priority_queue <double> positionScores =
         MUnrecognizedPositions;
*/
      std::priority_queue <double> positionScores;

      //
      // score each position in the sequence
      int seqlen = (*seqit)->length ();
      for (int i=0 ; i<seqlen ; i++) {
         bool foundMatch = false;
         results.firstFeature ();
         //
         // find the first feature that matches
         // the first feature is the 'best' feature
         // (e.g. it has the best (lowest) score
         // we negate the scores to get a positive score on a position
         do {
            const Feature& trainFeature = results.getFeature ();
            int trainFeatureLength = trainFeature.assignment ().length ();
            Str posData = (*seqit)->data (i, trainFeatureLength);
            //
            // if the position's lookahead is small than the feature's length
            // then this is not considered to be a matching
            if (posData.length () < trainFeatureLength) {
               results.nextFeature ();
               continue;
            }

            Assignment posAssignment (posData, testParams.langauge ().code ());
            if (trainFeature.assignment ().contains (posAssignment)) {
               //
               // we score this position with this best feature's score (negated)
               positionScores.push (- trainFeature.log2score ());
               foundMatch = true;
            }

            results.nextFeature ();
         }
         while (!foundMatch && results.hasMoreFeatures ());
      }
      //
      // now I know the best scores of positions in the sequence
      // we need the average of the M best
      // 
      // 
      if (positionScores.empty ()) {
         //
         // no score available
         perfWriter << (*seqit)->name () << "\t\t"
                    << (*seqit)->weight () << '\t'
                    << "-----" << "\t\t"
                    << "-----"
                    << perfWriter.EOL ();
      }
      else {
         double score = 0;
         /** 
         changes made by Yoseph on 18.4.04:
         to make the linear combination of the exponential socres and not their logs
         */
         score = -HUGE_VAL; // Yoseph
         double bestScore = positionScores.top (); 
/*
      for (int i=0 ; i<MBestPositions ; i++) {
         score += positionScores.top ();
         positionScores.pop ();
      }
      score = (score / MBestPositions);
*/
         int j;
         for (j=0 ; !positionScores.empty () && j<MBestPositions ; j++) {
            //score += positionScores.top (); 
            score = AddLog2(score,positionScores.top ()); // Yoseph
            positionScores.pop ();
         }
         //score = (score / j);
         score -= log2(static_cast<double>(j)); // Yoseph

         //
         // we compensate sequence's score by dividing
         switch (comp_l) {
            case Parser::_perflencomp_none_:
               break;

            case Parser::_perflencomp_linear_: 
               score = (score / seqlen);
               break;

            case Parser::_perflencomp_log_:
	      score = (score / log2 (static_cast<double>(seqlen)));
               break;

            default:
               mustfail ();
         };
         
         //
         // now we print the sequence information
	 // we transform from log2 internal representation to log10 in the output:
	 static const double LOG2_10 = 
	   log2 (static_cast<double> (10));
	 
         perfWriter << (*seqit)->name () << "\t\t"
                  << (*seqit)->weight () << '\t'
                  << bestScore/ LOG2_10 << "\t\t"
                  << score / LOG2_10
                  << perfWriter.EOL ();
      }
   }
}

static time_t cleanupStart = 0, cleanupFinish;
static time_t start = time (NULL), finish;

static void mainRoutine (int argc, 
                        char* argv [], 
                        SeedSearcherLog::Sentry& logging);

//
// Copied/Adapted from legacy SeedSearcher
int cpp_main(int argc, char* argv [])
{
   int exit_value = 0;

   try {
      //
      // setup basic logging
      SeedSearcherLog::Sentry logging;
      mainRoutine (argc, argv, logging);

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



static AutoPtr <SeedSearcherMain::Results> 
   mainSearch (SeedSearcherMain::CmdLineParameters& params,
   const StrBuffer& fileStub)
{
   SeedSearcherMain main (params);
   AutoPtr <SeedSearcherMain::Results> results = main.search ();

   int bonfN = 
      params.parser ().__score_bonf? results->numSeedsSearched () : 0;
   FeatureInvestigator printer ( params                     , 
                                 params.parser ().__seed_o  ,
                                 bonfN                      );
   printer.printSeedHeader (DLOG);

   bool gPSSM = params.parser ().__generatePSSM;
   Parser::MotifType gMotif = params.parser ().__generateMotif;

   //
   // we print the results to the log
   for (; results->hasMoreFeatures () ; results->nextFeature ()) {

      Feature& feature = results->getFeature ();

      //
      // first we find the positive and negative positions
      // of this feature
      PositionVector pos;
      PositionVector neg;
      printer.addPositions (feature, pos, neg);

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
                                                   results->featureIndex (),
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
         TextWriter pssmFile (openPSSMFile ( results->featureIndex (),
                                             fileStub
                                             ));

         printer.printPSSM (pssmFile, feature, pos);
      }
   }

   return results;
}


//
//
typedef Impl1WayDataNode <SeedSearcherMain::CmdLineParameters> ParamNode;
class ParamList {
public:
   ~ParamList () {
      //
      // delete the nodes
      while (!_list.empty ())
         delete _list.removeFirst();
   }
   void addLast (SeedSearcherMain::CmdLineParameters& in) {
      _list.addLast (new ParamNode (in));
   }

   //
   // add a new default parameters object to the list
   // and return it
   SeedSearcherMain::CmdLineParameters& addLast () {
      ParamNode* newOne = new ParamNode ();
      _list.addLast (newOne);
      return newOne->data;
   }
   const SeedSearcherMain::CmdLineParameters& getLast () const {
      return _list.getLast ()->data;
   }
private:
   ImplCyclicList <ParamNode> _list;
};



static AutoPtr <SeedSearcherMain::Results> 
   mainMultipleSearch (
            SeedSearcherMain::CmdLineParameters& firstParams,
            const StrBuffer& fileStub,
            ConfReader& conf,
            const Argv& confline,
            const Argv& cmdline) 
{
   AutoPtr <SeedSearcherMain::Results> results;
   ParamList paramList;
   //
   // we insert the original parameters as the first parameters in the list
   paramList.addLast (firstParams);

   StrBuffer stub;
   StrBuffer args;
   StrBuffer name;
   StrBuffer test;
   bool shouldTest;
   bool shouldClear;
   int runNumber = 1;

   //
   // now we read our run parameters from the conf
   ConfReader::Package seed (conf.getPackage ("Seed"));
   ConfReader::Package runs (seed.createSubPackage ("Runs"));
   ConfReader::Iterator it (runs);
   for (; !it.atEnd () ; it.next ()) {
      DLOG << "Performing: "<< it.getName () << DLOG.EOL ();
      
      //
      // get the last paramters
      const SeedSearcherMain::CmdLineParameters& lastParams = paramList.getLast ();
      //
      // add a new parameter to the list
      SeedSearcherMain::CmdLineParameters& newParams = paramList.addLast ();
      //
      // copy settings from the last paramters
      newParams.set (lastParams);

      shouldClear = false;
      runs.get ("Clear", shouldClear);
      if (shouldClear) {
         //
         // we first restore the defaults
         newParams.parser ().restoreDefaults ();
         //
         // then re-apply the original arguments
         newParams.parser ().parse (confline);
         newParams.parser ().parse (cmdline);
      }

      runs.mustGet (it + "Args", args);
      Argv params_argv (cmdline.argv ()[0], args);
      newParams.secondarySetup ( params_argv.argc (),
                                 params_argv.argv ());

      //
      // check for seed evaluation
      test.set (0);
      shouldTest = runs.get (it + "Test", test)? !test.empty () : false;

      //
      // run the search, different stub name every time
      stub = fileStub; stub.append ('.'); stub.append (it.getName ());
      results = mainSearch (newParams, stub);

      runNumber++;

      // perform seed perfomance check
      // testSeedPerformance (argc, argv, *results, params);
   }

   return results;
}

//
// this functin checks if a conf is specified and if it is valid
static void checkConf (int argc, char* argv [], Argv& outInitArgs)
{
   Parser parser;
   parser.parse (argc, argv);

   if (!parser.__conf.empty ()) {
      ConfReader conf (parser.__conf);
      DLOG << "Checking correctness of " << conf.source () << ':' << DLOG.EOL ();
      if (!conf.valid ()) {
         mmustfail ("The file could not be found");
      }
      DLOG.flush ();

      //
      // now we validate the arguments in the conf
      StrBuffer args;
      ConfReader::Package seed (conf.getPackage ("Seed"));
      ConfReader::Package init (seed.tryCreateSubPackage ("Init"));
      if (init.get ("Args", args)) {
         DLOG << "Validating initial arguments..." 
	      << args 
	      << DLOG.EOL ();
         //
         //
	 DLOG.flush ();
         outInitArgs.set (argv[0], args);
         parser.parse (outInitArgs);
      }

      //
      // now we read and validate run parameters from the conf
      ConfReader::Package runs (seed.createSubPackage ("Runs"));
      ConfReader::Iterator it (runs);
      for (; !it.atEnd () ; it.next ()) {
         DLOG << "Validating  " << it.getName () << DLOG.EOL ();
         if (runs.get (it + "Args", args))
            parser.parse (args);
      }
   }
   DLOG << "OK!" << DLOG.EOL () << DLOG.EOL ();
}

static void mainRoutine (int argc, 
                        char* argv [], 
                        SeedSearcherLog::Sentry& logging)
{
   welcomeMessage ();

   Argv confInit;
   checkConf (argc, argv, confInit);

   //
   // initialize parameters
   SeedSearcherMain::CmdLineParameters params;
   if (!confInit.empty ()) {
      //
      // initialize first with conf parameters
     params.parser ().parse (confInit);
   }
   //
   // cmdline parameters has precedence
   Argv cmdlineInit (argc, argv);
   params.parser ().parse (cmdlineInit);

   //
   // check that we have enough arguments
   // needs SeqFile RegFile and output-stub
   int numOfFileArgs = params.parser ().__lastFileArg - 
         params.parser ().__firstFileArg +1;

   if(numOfFileArgs < RequiredParams)
      params.parser ().usage ("Missing arguments");

   //
   // now setup file logging
   const char* fileStub = 
      argv [params.parser ().__firstFileArg + StubFileIndex];

   logging.setupFileLogging (StrBuffer (fileStub, ".log"));

   //
   // write welcome message
   welcomeMessage(params.parser ());

   AutoPtr <SeedSearcherMain::Results> results;
   if (!params.parser ().__conf.empty ()) {
      //
      // the conf parameter for multiple runs was specified
      // create the conf reader
      ConfReader conf (params.parser ().__conf);

      //
      // create the preprocessor
      params.setup ( argv [params.parser ().__firstFileArg + SeqFileIndex],
                     argv [params.parser ().__firstFileArg + WgtFileIndex]);

      //
      // run all the searches
      results = mainMultipleSearch (params, 
                                    fileStub, 
                                    conf,
                                    confInit,
                                    cmdlineInit);
   }
   else {
      //
      // create the preprocessor
      params.setup ( argv [params.parser ().__firstFileArg + SeqFileIndex],
                     argv [params.parser ().__firstFileArg + WgtFileIndex]);

      //
      // just a single run
      results = mainSearch (params, fileStub);
   }
    
   //
   //
   if (numOfFileArgs > RequiredParams) {
      testSeedPerformance (argc, argv, *results, params);
   }


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


