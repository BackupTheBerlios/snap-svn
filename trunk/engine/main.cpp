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

#include "Core/AutoPtr.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StdOutputStream.h"
#include "Persistance/StdInputStream.h"

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;
using namespace Persistance;

static const int __versionMajor = 2;
static const int __versionMinor = 1;

//
//
enum {
   SeqFileIndex = 0,
   WgtFileIndex = 1,
   StubFileIndex = 2,
   RequiredParams = 3
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




#if 0
static void printMotif (TextWriter& writer, 
                        const Assignment& assg,
                        const SeqPosition& position,
                        const std::string& allignment)
{
   //
   // write the motif: LeftPadding Seed RightPadding
   
   //
   // left padding
   const int leftPaddingLength = 
      getMotifLeftOffset (parser.__seed_o, assg.length ());

   if (leftPaddingLength > 0) {
      Str leftPad = 
	position.getDataString (-leftPaddingLength, leftPaddingLength);
      writer.write (allignment.c_str (), leftPaddingLength - leftPad.length ());
      writer.write (leftPad);
   }
   
   //
   // separate left padding from seed
   writer << ' ';
   
   //
   // write the actual seed
   const int seedLength = 
     tmin (parser.__seed_o - 2 * leftPaddingLength, assg.length ());
   Str motif = position.getSeedString (seedLength);
   writer << motif;

   //
   // separate right padding from seed
   writer << ' ';

   //
   // right padding
   const int rightPaddingPosition =
     parser.__seed_o - seedLength - leftPaddingLength;
   const int rightPaddingLength =  rightPaddingPosition;
   if (rightPaddingLength > 0) {
      Str rightPad = 
	position.getDataString (rightPaddingPosition, rightPaddingLength);
      writer.write (rightPad);
      writer.write (allignment.c_str (), 
		    rightPaddingLength - rightPad.length ());
   }
  
   //
   // write seq id and name
   writer << '\t' << position.sequence ()->id () 
          << '\t' << position.sequence ()->name ();
   
   //
   // TODO: what does [iYML101C 13 70088 70624 TSL1] [0.0000] mean?
   
   //
   // output sequence weight 
   debug_mustbe (position.sequence ()->hasWeight ());
   writer << " [" << position.sequence ()->weight () << ']';
   
   //
   // output the position index
   writer << '\t' << position.position ();
   
   //
   // TODO: print +/- if it is on normal/reverse strand
   writer.writeln ();
}




//
// print the positions in the positively labels set in .motif file
// the other positions are printed in .net.motifs file  
static void printMotifFile (bool isPositives,
                            const Feature& feature_i,
                            const PositionVector& positions,
                            const std::string& allignment,
                            int index)
{
   //
   // create the motif file name
   char motifFileName [256];
   if (isPositives)
      sprintf (motifFileName, "%s.%d.motifs", 
	       parser.__argv[parser.__lastFileArg], (index+1));
   else
      sprintf (motifFileName, "%s.%d.neg.motifs", 
	       parser.__argv[parser.__lastFileArg], (index+1));

   ofstream motifFile (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile.is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   TextWriter writer (new StdOutputStream (motifFile));

   CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next ()) {
      printMotif (writer, feature_i.assignment (), *(*it), allignment);
   }

   writer.flush ();
}



static void printSeeds (SeqWeightFunction& wf,
                        ScoreFunction& scoreFunc,
                        const AlphabetCode& code,
                        Preprocessor& preprocessor,
                        int totalNumOfSeedsFound,
                        SeedSearcher::BestFeatures& bestFeatures)
{
   int size = bestFeatures.size ();

   DLOG << '#' << DLOG.EOL ()
      << "# Seeds: " << totalNumOfSeedsFound << " found, kept the "
      << size << " best."
      << DLOG.EOL ();

   //
   // apply stat fixes
   int lastIndexToShow = bestFeatures.size ();
   if (parser.__score_fdr) {
      int K = StatFix::FDR (  bestFeatures, 
                              totalNumOfSeedsFound, 
                              parser.__score_min);

      lastIndexToShow = tmin (lastIndexToShow, K);

      DLOG << "# Using FDR fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }
   if (parser.__score_bonf) {
      int K = StatFix::bonferroni ( bestFeatures, 
                                    totalNumOfSeedsFound, 
                                    parser.__score_min);

      lastIndexToShow = tmin (lastIndexToShow, K);

      DLOG << "# Using Bonferroni fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }

   DLOG.flush ();

   //
   // print header
   DLOG << DLOG.EOL ();
   if (parser.__score_bonf) {
      DLOG <<"Bonf(-log10)\t";
   }
   DLOG << "Score(-log10)\tSeed\t\tParameters\t\t\tProjection" << DLOG.EOL ();

   static const double Log_2_10 = ::log2 (10);
   const double log_10_numOfSeeds = ::log10 (totalNumOfSeedsFound);

   //
   // print (do not print less than 3)
   int index;
   lastIndexToShow = tmin (size, tmax (lastIndexToShow, 3));
   for (index=0 ; index<lastIndexToShow ; index++) {
      const Feature& feature_i = bestFeatures [index];
      
      double log_10_of_score = (feature_i.score ()) / Log_2_10;
      
      //
      // print bonf correction
      if (parser.__score_bonf) {
         //
         // log10 (score * K) = log10 (score) + log10 (K)
         double bonfScore = log_10_of_score + log_10_numOfSeeds;
         DLOG  <<  (- bonfScore)
               << '\t';
      }

      DLOG  <<  (- log_10_of_score)
            << '\t'
            << Format (feature_i.assignment ());

      //
      // print score params if available
      if (feature_i.scoreParameters ()) {
         DLOG << "\t[";
         scoreFunc.writeAsText (DLOG, feature_i.scoreParameters ());
         DLOG << ']';
      }

      //
      // print projection details if available
      if (feature_i.projection ()) {
         DLOG << '\t' << Format (*feature_i.projection ());
      }

      DLOG << DLOG.EOL ();
   }

   //
   // now print the motif files
   std::string allignment (parser.__seed_o, '-');
   for (index=0 ; index<lastIndexToShow ; index++) {
      const Feature& feature_i = bestFeatures [index];

      //
      // TODO: use the positions in the cluster if they are available
      Preprocessor::NodeCluster motifNodes;
      preprocessor.add2Cluster (motifNodes, feature_i.assignment ());
      //motifNodes.addAssignmentNodes (tree, *feature_i._assg);

      PositionVector posPositions;
      PositionVector negPositions;
      motifNodes.positions (wf, posPositions, negPositions);

      //
      // print motif in positive set
      printMotifFile (  true,
                        feature_i, 
                        posPositions, 
                        allignment, 
                        index);

      //
      // print motif in negative set
      printMotifFile (  false,
                        feature_i, 
                        negPositions, 
                        allignment, 
                        index);

      //
      // build PSSM from positive positions only
      // TODO: is this correct?
      printPSSMFile (code, feature_i, posPositions, index);
   }
}

#endif

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

   ofstream* motifFile = new ofstream (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile->is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   return new StdOutputStream (motifFile, true);
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

   ofstream* motifFile = new ofstream (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile->is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   return new StdOutputStream (motifFile, true);
}




static void welcomeMessage (const Parser& parser)
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
   DLOG << "By Yoseph Barash (hoan@cs.huji.ac.il)" << DLOG.EOL ();
   DLOG << "And Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ();
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
// Copied/Adapted from legacy SeedSearcher
int main(int argc, char* argv [])
{
   time_t cleanupStart =0, cleanupFinish;
   time_t start, finish;

   time(&start);
   try {
      //
      // setup basic logging
      SeedSearcherLog::setupConsoleLogging (false);

      //
      // initialize parameters
      SeedSearcherMain::CmdLineParameters params (argc, argv);


      //
      // check that we have enough arguments
      // needs SeqFile RegFile and output-stub
      int numOfFileArgs = params.parser ().__lastFileArg - 
            params.parser ().__firstFileArg +1;

      if(numOfFileArgs < RequiredParams)
         params.parser ().usage ("Missing arguments");

      //
      // now setup file logging
      int fileStubArg = 
         params.parser ().__firstFileArg + StubFileIndex;

      const char* fileStub = 
         params.parser ().__argv [fileStubArg];
      
      {  TextWriter* oldWriter = 
            SeedSearcherLog::setupFileLogging (
		       StrBuffer (fileStub, ".log"), false);
         delete oldWriter;
      }

      //
      // write welcome message
      welcomeMessage(params.parser ());

      //
      // begin 
      params.setup ();
      SeedSearcherMain main (params);
      AutoPtr <SeedSearcherMain::Results> results = main.search ();

      int bonfN = 
         params.parser ().__score_bonf? results->numSeedsSearched () : 0;
      FeatureInvestigator printer ( params                     , 
                                    params.parser ().__seed_o  ,
                                    bonfN                      );
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

         
         //
         // now we print pos & neg motif files
         bool isPos = true;
         for (int i = 0 ; i <= 1; i++) {
            //
            // we open a file for the motif
            TextWriter motifFile (openMotifFile (  isPos, 
                                                results->featureIndex (),
                                                fileStub
                                                ));
            printer.printMotif ( motifFile, 
                                 feature, 
                                 isPos? pos : neg);
            isPos = !isPos;
         }

         //
         // now we print the PSSM files
         TextWriter pssmFile (openPSSMFile ( results->featureIndex (),
                                             fileStub
                                             ));

         printer.printPSSM (pssmFile, feature, pos);
      }

      finish = time(NULL);
      printGoodbye (start, finish);
      cerr << endl << "Cleaning up...";
      time (&cleanupStart);
   }
   catch (BaseException& x) {
      cerr << endl;
      x.explain (cerr);
      cerr << endl;
   }
   catch (std::exception& x) {
      cerr << endl << x.what () << endl ;
   }
   catch (...) {
      cerr << endl << "Unknown Error! aborting..." << endl;
   }
   if (cleanupStart) {
      time(&cleanupFinish);
      cerr << (cleanupFinish - cleanupStart) << " seconds." << endl;
   }

   return 0;
}


#if SEED_DL_MALLOC_OPTIMIZATION

#include "Core/dlmalloc.h"


void * operator new (size_t size)
{
   return dlmalloc (size);
}

void operator delete (void* p)
{
   dlfree (p);
}

#endif





