#include "Parser.h"

#include "SequenceDB.h"
#include "PrefixTreePreprocessor.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"
#include "HyperGeoScore.h"
#include "PSSM.h"

#include "LeafPreprocessor.h"

#include "StdOptions.h"
#include "DebugLog.h"

#include "Core/AutoPtr.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StdOutputStream.h"
#include "Persistance/StdInputStream.h"
#include "Persistance/TFactory.h"
#include "Persistance/OArchive.h"
#include "Persistance/IArchive.h"


#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;
using namespace Persistance;

static const int __versionMajor = 2;
static const int __versionMinor = 0;

Parser parser;



PrefixTreePreprocessor* ___kuku;

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
   DLOG << "By Yoseph Barash (hoan@cs.huji.ac.il)" << DLOG.EOL ();
   DLOG << "Implemented by: Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ();
   time_t ltime;
   time( &ltime );
   DLOG << DLOG.EOL ()
        << "Execution started on " << ctime( &ltime ) << DLOG.EOL ();


   //
   // (2) write execution line
   DLOG << '#' << DLOG.EOL () << "# execution parameters " << DLOG.EOL ();

   for (int i=0 ;i<parser.__argc ; i++)
      DLOG << parser.__argv [i] << ' ';

   DLOG << DLOG.EOL ();

   //
   // (3) write execution parameters
   DLOG << "Seed length: " << parser.__seed_l << DLOG.EOL ();
   DLOG << "No of Random Positions (dist): " << parser.__proj_d << DLOG.EOL ();
   DLOG << "Use reverse: " << (parser.__count_reverse? "true" : "false") << DLOG.EOL ();
   DLOG << "No of Random Projections: " << parser.__proj_n << DLOG.EOL ();
   DLOG << "Use all possible projections: " << (parser.__proj_e? "true" : "false") << DLOG.EOL ();
   DLOG << "PSSM length: " << parser.__seed_o << DLOG.EOL ();
   DLOG << "No of PSSMs: " << parser.__seed_n << DLOG.EOL ();
   DLOG << "Randomization seed: " << parser.__proj_i << DLOG.EOL ();
   DLOG << "Threshold for pos/neg cluster assignment: " << parser.__weight_t << DLOG.EOL ();
   DLOG << "Maximum offset to check for seed redundancy: " << parser.__seed_r << DLOG.EOL ();
   DLOG << "Partial count: " << (parser.__score_partial? "on" : "off") << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << parser.__score_min_seq << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << parser.__score_min_seq_per << '%' << DLOG.EOL ();
   DLOG << "Minimum score for seed: log (" << parser.__score_min << ") = " << log (parser.__score_min) << DLOG.EOL ();
   DLOG << "Use Total-Counts: " << (parser.__count == _count_total_? "true" : "false") << DLOG.EOL ();
   DLOG << "Use Bonferroni statistical fix: " << (parser.__score_bonf? "true" : "false") << DLOG.EOL ();
   DLOG << "Use FDR statistical fix: " << (parser.__score_fdr? "true" : "false") << DLOG.EOL ();
   DLOG.flush ();
}






#if 0

static void setupRandomProjections (const AlphabetCode& code,
                                    AutoPtr <RandomProjections>& projections)
{
   //
   // initialize the random seed
   RandomProjections::srand (parser.__proj_i);
   if (parser.__proj_e) {
      projections = new RandomProjections (
         RandomProjections::all,
         code.cardinality (),
         parser.__seed_l,
         parser.__proj_d);
   }
   else {
      projections = new RandomProjections (
         parser.__proj_n,
         code.cardinality (),
         parser.__seed_l,
         parser.__proj_d);
   }
}


#if 0 
static TFactoryList* createFactories ()
{
   AutoPtr <TFactoryList> factories = new TFactoryList;
   PrefixTreePreprocessor::createFactories (*factories);
   new TFactory <PrefixTreePreprocessor> (factories);
   new TFactory <SequenceDB> (factories);
   new TFactory <Sequence> (factories);
   new TFactory <SeqPosition> (factories);

   return factories.release ();
}


static void saveTreeFile (SequenceDB* db,
                          PrefixTreePreprocessor* tree)
{
   time_t start, finish;
   time (&start);

   std::string treeFile (parser.__argv[parser.__lastFileArg]);
   treeFile.append (".tree");

   ofstream treeOut (treeFile.c_str (),
      ios_base::out | ios_base::trunc | ios_base::binary);
   if(!treeOut.is_open() )
      Err(string("Cannot open preprocessed file ") + treeFile);

   //
   // we save the DB and the Tree to archive
   /*
   debug_only (
   DLOG << "Writing SequenceDB and PrefixTree into "
   << treeFile.c_str ()
   << "... ";
   DLOG.flush ();
   );
   */

   {  Persistance::OArchive out (new BufferedStdOutputStream (treeOut), createFactories ());
   out.registerObject (db);
   out.writeObject (tree);
   }

   time (&finish);
   DLOG << "SequenceDB and PrefixTree written into "
      << treeFile.c_str () << " ("
      << (finish - start) << " seconds.)"
      << DLOG.EOL ();

   debug_only (
      DLOG << "Finished." << DLOG.EOL ();
   DLOG.flush ();
   );

}



static void readTreeFile (AutoPtr <SequenceDB>& db,
                          AutoPtr <PrefixTreePreprocessor>& tree)
{
   time_t start, finish, linkStart, linkFinish;
   time (&start);

   //
   // we must retrieve the tree from a file
   ifstream treeIn (__readPreprocessedName, ios_base::in | ios_base::binary);
   if(!treeIn.is_open() )
      Err(string("Cannot open preprocessed file ")+__readPreprocessedName);

   SequenceDB* dbPtr;
   PrefixTreePreprocessor* treePtr;

   {  Persistance::IArchive in (new StdInputStream (treeIn), createFactories ());
   in.registerObject (dbPtr);
   in.readObject (treePtr);

   time (&linkStart);
   in.registry ().link ();
   time (&linkFinish);
   }

   db = dbPtr;
   tree = treePtr;

   time (&finish);

   DLOG << "SequenceDB and PrefixTree read from "
      << __readPreprocessedName << " ("
      << (finish - start) << " seconds, of which "
      << (linkFinish - linkStart) << " used for linking)"
      << DLOG.EOL ();
   //
   // assign new weights to the sequence db
   // SequenceDB::TextFileStorage::assignWeights (*db, parser.__argv [parser.__firstFileArg], true);
}

#endif




static void setupDB (AutoPtr <SequenceDB>& db, 
                     const AlphabetCode& acgt)
{
   DLOG << '#' << DLOG.EOL ()
        << "# SequenceDB: " << DLOG.EOL ();

   DLOG  << "Reading Sequence File: " 
         << parser.__argv[parser.__firstFileArg] 
         << DLOG.EOL ();

   DLOG  << "Reading Weights File: " 
         << parser.__argv[parser.__firstFileArg+1] 
         << DLOG.EOL ();

   DLOG.flush ();

   //
   // load the sequence files
   time_t start, finish;
   time (&start);
   db = SequenceDB::TextFileStorage::loadFastaAndWeights (acgt,
      parser.__argv[parser.__firstFileArg],
      parser.__argv[parser.__firstFileArg+1]);

   time (&finish);

   DLOG << "Loaded " << db->size () <<  " Sequences. ("
        << (finish - start) << " seconds )." << DLOG.EOL ();
}




static void setupDBAndTree (const AlphabetCode& acgt,
                            AutoPtr <SequenceDB>& db,
                            AutoPtr <PrefixTreePreprocessor>& tree,
                            const SeqWeightFunction& wf)
{
#if 0 
   //
   // create the prefix tree.
   if (__readPreprocessed) {

      DLOG << '#' << DLOG.EOL ()
           << "# SequenceDB & PrefixTreePreprocessor "<< DLOG.EOL ();
      readTreeFile (db, tree);
      db->getSequencesAbove (__thresh, positiveSequences);
   }
   else 
#endif
   {
      if (!db.valid ())
         setupDB (parser, db, acgt);

      DLOG << '#' << DLOG.EOL ()
           << "# PrefixTreePreprocessor "<< DLOG.EOL ();
      DLOG << "Creating a new PrefixTree Preprocessor from sequence data: " << DLOG.EOL ();
      DLOG.flush ();

      tree  = new PrefixTreePreprocessor (
         PrefixTreePreprocessor::build (  parser.__proj_spec, 
                                          wf,
                                          *db,
                                          parser.__seed_l
         )
      );
   }
}



static void openLogFile (ofstream& logOut)
{
   string outStub;
   outStub = string(parser.__argv[parser.__lastFileArg]);
   logOut.open ((outStub+".log").c_str(),
      ios_base::out | ios_base::trunc | ios_base::binary);
   if( ! logOut.is_open() )
      Err(string("Cannot open logFile for ")+outStub);
}




inline static int getMotifLeftOffset (int motifLen, int seedLen)
{
   const int leftPaddingLength = 
      tmax ((motifLen - seedLen) / 2, 0);

   return leftPaddingLength;
}



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



static void printPSSMFile ( const AlphabetCode& code,
                            const Feature& feature_i,
                            const PositionVector& positions,
                            int index)
                           
{
   const int seed_length = feature_i.assignment ().length ();
   const int offset = getMotifLeftOffset (parser.__seed_o, seed_length);
   PSSM pssm(code, offset, parser.__seed_o, positions);

   char motifFileName [256];
   sprintf (motifFileName, "%s.%d.pssm", 
	    parser.__argv[parser.__lastFileArg], (index+1));

   ofstream motifFile (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile.is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   TextWriter writer (new BufferedStdOutputStream (motifFile));

   int size = pssm.length ();          
   int cardinality = code.cardinality ();    debug_mustbe (cardinality > 0);
   for (int j=0 ; j<cardinality ; j++) {
      //
      // write the first position
      writer << pssm [0][j];

      //
      // write all other positions with a prepending '\t'
      for (int i=1 ; i<size ; i++) {
         writer << "\t\t\t" << pssm [i][j];
      }

      //
      //
      writer.writeln ();
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

#if 0 

static AutoPtr <SeqWeightFunction> createWeightFunction ()
{
   AutoPtr <SeqWeightFunction> wf;
   switch (parser.__weightType) {
   case _weight_simple_:
      wf = new SimpleWeightFunction (parser.__weight_t);
      break;
   
   case _weight_border_:
      wf = new BorderWeightFunction (parser.__weight_lowt, parser.__weight_t);
      break;
   case _weight_interval_:
      wf = new IntervalWeightFunction (parser.__weight_lowt, parser.__weight_t);
      break;

   default:
      mustfail ();
      break;
   };

   if (parser.__weight_invert)
      wf->invert ();

   return wf;
}

static AutoPtr <Preprocessor> createPreprocessor (const AlphabetCode& code,
                                                  const SequenceDB& db,
                                                  const SeqWeightFunction& wf)
{
   AutoPtr <Preprocessor> prep;
   if (parser.__prep == _prep_leaf_) {
      LeafPreprocessor::Rep* rep;
      if (parser.__proj_spec) {
         rep = LeafPreprocessor::buildNoNegatives (  
            parser.__seed_l, 
            db, 
            code, 
            SeedSearcherLog::assgWriter (),
            wf
         );
      }
      else {
         rep = LeafPreprocessor::build (  
            parser.__seed_l, 
            db, 
            code, 
            SeedSearcherLog::assgWriter ()
         );
      }

      prep = new LeafPreprocessor (rep);
   }
   else {
      mustbe (parser.__prep == _prep_tree_);
      PrefixTreePreprocessor::TreeRep* rep = 
         PrefixTreePreprocessor::build (  parser.__proj_spec,
                                          wf,
                                          db,
                                          parser.__seed_l);

      prep = new PrefixTreePreprocessor (rep);
      ___kuku = dynamic_cast <PrefixTreePreprocessor*> (prep.get ());
   }

   return prep;
}

static AutoPtr <ScoreFunction> 
   createScoreFunc ( const SequenceDB& db,
                     const SeqWeightFunction& wf)
{
   AutoPtr <ScoreFunction> score;
   if (parser.__count == _count_total_) {
      score = 
         new HyperGeoScore::FixedTotalCount (parser.__seed_l, 
                                             parser.__score_partial, 
                                             wf, 
                                             db);
   }
   else {
      score = 
         new HyperGeoScore::Simple (parser.__score_partial, 
                                    wf, 
                                    db);
   }

   return score;
}

static AutoPtr <SeedSearcher::BestFeatures> 
   createFeatureContainer (const SequenceDB& db,
                           const SeqWeightFunction& wf)
{
   AutoPtr <SeedSearcher::BestFeatures> bestFeatures;
   
   //
   // use GoodFeatures to allow only features above a threshold
   bestFeatures = new GoodFeatures (
      new KBestFeatures (parser.__seed_n, parser.__seed_r),
      true,
      SeqCluster (db),
      wf,
      parser.__score_min,
      parser.__score_min_seq,
      parser.__score_min_seq_per);

   return bestFeatures;
}

#endif 

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


#include "SeedSearcherMain.h"

enum {
   SeqFileIndex = 0,
   WgtFileIndex = 1,
   StubFileIndex = 2,
   RequiredParams = 3
};

//
// Copied/Adapted from legacy SeedSearcher
int main(int argc, char* argv [])
{
   time_t cleanupStart =0, cleanupFinish;
   time_t start, finish;

   time(&start);
   try {
      SeedSearcherMain::CmdLineParameters params (argc, argv);

      //
      // check that we have enough arguments
      // needs SeqFile RegFile and output-stub
      int numOfFileArgs = params.parser ().__lastFileArg - 
            params.parser ().__firstFileArg +1;

      if(numOfFileArgs < RequiredParams)
         params.parser ().usage ("Missing arguments");

      const char* fileStub = params.parser ().__argv [StubFileIndex];
      
      params.setup ();
      SeedSearcherMain main (params);
      AutoPtr <SeedSearcherMain::Results> results = main.search ();

      FeatureInvestigator printer ( params, 
                                    params.parser ().__seed_o);

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
         for (bool isPos = true ; isPos ; isPos = false) {
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

         //
         // now we print the PSSM files
         TextWriter pssmFile (openPSSMFile ( results->featureIndex (),
                                             fileStub
                                             ));

         printer.printPSSM (pssmFile, feature, pos);
      }



      //
      // now the seeds are waiting in the KBestFeatures 

/*

      //
      // parse arguments
      parser.parse (argc, argv);

      ofstream logOut;
      openLogFile (logOut);

      //
      // setup program output
      StdUnbufferedOutput consoleChannel (cout);
      StdUnbufferedOutput fileChannel (logOut);

      UnbufferedOutput* channels [] = { &consoleChannel, &fileChannel };
      const int numOfChannels = sizeof (channels) / sizeof (UnbufferedOutput*);

      ACGTLangauge langauge;

      TextWriter consoleWriter (
         new SmallChannelOutput (
            new UnbufferedOutputMux (channels, numOfChannels , false), true));

      SeedSearcherLog::setup (langauge);
      SeedSearcherLog::setup (consoleWriter);

      //
      // welcome message
      welcomeMessage ();
      long start = time(NULL);

      //
      // for now, only ACGT code is available
      // TODO: add more alphabets
      const AlphabetCode& acgt = ACGTLangauge::getCode (//include N 
                                                         true);
      /*

      AutoPtr <SequenceDB> db;
      AutoPtr <SeqWeightFunction> wf;
      AutoPtr <Preprocessor> preprocessor;
      AutoPtr <ScoreFunction> score;
      AutoPtr <RandomProjections> projections;
      AutoPtr <SeedSearcher::BestFeatures> bestFeatures;

      //
      // setup the db
      setupDB (db, acgt);

      //
      // create the weight function
      wf = createWeightFunction ();

      //
      // create the preprocessor
      preprocessor = createPreprocessor (acgt, *db, *wf);

      //
      // create random projections
      setupRandomProjections (acgt, projections);

      //
      // TODO: if we have read the tree file from archive,
      // and we need longer seeds than the tree's depth,
      // then continue to build the tree until the required size
#if 0 
      if (__generatePreprocessed) {
         saveTreeFile (db, tree);
      }
#endif

      //
      // create the hyper-geometric scoring scheme
      score = createScoreFunc (*db, *wf);

      //
      // keep only the best features
      // TODO: what should we do when parser.__seed_r 
      // is too large for the length of seed?
      bestFeatures = createFeatureContainer (*db, *wf);

      //
      // now run over all projections, searching for seeds.
      // the seeds are stored inside kbestFeatures.

      int totalNumOfSeedsFound = 0;
      int numOfProjections = projections->numOfProjections ();
      for (int i=0 ; i<numOfProjections ; i++) {
         const Assignment& assg = 
            projections->getAssignment (  
               i, 
               langauge.wildcard (Assignment::together),
               langauge.wildcard (Assignment::discrete)
            );

         //
         //
         DLOG << "Searching for " << Format (assg) << ": ";
         DLOG.flush ();
         int save = totalNumOfSeedsFound;
         time_t start, finish;
         time (&start);


         if (parser.__prep == _prep_tree_) {
            totalNumOfSeedsFound +=
               SeedSearcher::prefixTreeSearch (
                  dynamic_cast <PrefixTreePreprocessor&> (*preprocessor),
                  assg,
                  *wf,
                  *score,
                  *bestFeatures,
                  parser.__proj_spec,
                  parser.__count == _count_total_
               );
         }
         else {
            totalNumOfSeedsFound +=
               SeedSearcher::tableSearch (
                  parser.__count == _count_total_,
                  parser.__proj_spec,
                  acgt,
                  *preprocessor,
                  assg,
                  lan,
                  *wf,
                  *score,
                  *bestFeatures
               );
         }

         time (&finish);
         DLOG << (finish - start) << " seconds, Found "
              << totalNumOfSeedsFound - save << " seeds." << DLOG.EOL ();
      }

      //
      // now output all the seeds
      bestFeatures->sort ();



      //
      // do not include N when printing PSSMs
      printSeeds (*wf,
                  *score,
                  ACGTAlphabet::get (//include N
                                       false),
                  *preprocessor, 
                  totalNumOfSeedsFound, 
                  *bestFeatures);
      */

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




