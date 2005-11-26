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




PrefixTreePreprocessor* ___kuku;


//
// Copied/Adapted from legacy SeedSearcher
static void Err(std::string const & s) {
   debug_mustfail ();
   cerr<<s<<DLOG.EOL ();
   cerr.flush();
   exit(1);
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

   for (int i=0 ;i<Parser::__argc ; i++)
      DLOG << Parser::__argv [i] << ' ';

   DLOG << DLOG.EOL ();
/*
   //
   // (3) write execution parameters
   DLOG << "Seed length: " << __SeedL << DLOG.EOL ();
   DLOG << "No of Random Positions (dist): " << __dist << DLOG.EOL ();
   DLOG << "Use reverse: " << (__UseRev? "true" : "false") << DLOG.EOL ();
   DLOG << "No of Random Projections: " << Parser::__proj_n << DLOG.EOL ();
   DLOG << "Use all possible projections: " << (__allProjections? "true" : "false") << DLOG.EOL ();
   DLOG << "PSSM length: " << Parser::__seed_o << DLOG.EOL ();
   DLOG << "No of PSSMs: " << Parser::__seed_n << DLOG.EOL ();
   DLOG << "Randomization seed: " << __randSeed  << DLOG.EOL ();
   DLOG << "Threshold for pos/neg cluster assignment: " << __thresh << DLOG.EOL ();
   DLOG << "Maximum offset to check for seed redundancy: " << Parser::__seed_r << DLOG.EOL ();
   DLOG << "Partial count: " << (Parser::__score_partial? "on" : "off") << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << Parser::__score_min_seq << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << Parser::__score_min_seq_per << '%' << DLOG.EOL ();
   DLOG << "Minimum score for seed: log (" << Parser::__score_min << ") = " << log (Parser::__score_min) << DLOG.EOL ();
   DLOG << "Use Total-Counts: " << (Parser::__count == Parser::total? "true" : "false") << DLOG.EOL ();
   DLOG << "Use Bonferroni statistical fix: " << (Parser::__score_bonf? "true" : "false") << DLOG.EOL ();
   DLOG << "Use FDR statistical fix: " << (Parser::__score_fdr? "true" : "false") << DLOG.EOL ();
   DLOG.flush ();
*/
}








static void setupRandomProjections (const AlphabetCode& code,
                                    AutoPtr <RandomProjections>& projections)
{
   //
   // initialize the random seed
   RandomProjections::srand (Parser::__proj_i);
   if (Parser::__proj_e) {
      projections = new RandomProjections (
         RandomProjections::all,
         code.cardinality (),
         Parser::__seed_l,
         Parser::__proj_d);
   }
   else {
      projections = new RandomProjections (
         Parser::__proj_n,
         code.cardinality (),
         Parser::__seed_l,
         Parser::__proj_d);
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
   new TFactory <Position> (factories);

   return factories.release ();
}


static void saveTreeFile (SequenceDB* db,
                          PrefixTreePreprocessor* tree)
{
   time_t start, finish;
   time (&start);

   std::string treeFile (Parser::__argv[Parser::__lastFileArg]);
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
   // SequenceDB::TextFileStorage::assignWeights (*db, Parser::__argv [Parser::__firstFileArg], true);
}

#endif




static void setupDB (AutoPtr <SequenceDB>& db, const AlphabetCode& acgt)
{
   DLOG << '#' << DLOG.EOL ()
        << "# SequenceDB: " << DLOG.EOL ();

   DLOG  << "Reading Sequence File: " 
         << Parser::__argv[Parser::__firstFileArg] 
         << DLOG.EOL ();

   DLOG  << "Reading Weights File: " 
         << Parser::__argv[Parser::__firstFileArg+1] 
         << DLOG.EOL ();

   DLOG.flush ();

   //
   // load the sequence files
   time_t start, finish;
   time (&start);
   db = SequenceDB::TextFileStorage::loadFastaAndWeights (acgt,
      Parser::__argv[Parser::__firstFileArg],
      Parser::__argv[Parser::__firstFileArg+1]);

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
         setupDB (db, acgt);

      DLOG << '#' << DLOG.EOL ()
           << "# PrefixTreePreprocessor "<< DLOG.EOL ();
      DLOG << "Creating a new PrefixTree Preprocessor from sequence data: " << DLOG.EOL ();
      DLOG.flush ();

      tree  = new PrefixTreePreprocessor (
         PrefixTreePreprocessor::build (  Parser::__proj_spec, 
                                          wf,
                                          *db,
                                          Parser::__seed_l
         )
      );
   }
}



static void openLogFile (ofstream& logOut)
{
   string outStub;
   outStub = string(Parser::__argv[Parser::__lastFileArg]);
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
                        const Position& position,
                        const std::string& allignment)
{
   //
   // write the motif: LeftPadding Seed RightPadding
   
   //
   // left padding
   const int leftPaddingLength = 
      getMotifLeftOffset (Parser::__seed_o, assg.length ());

   if (leftPaddingLength > 0) {
      Str leftPad = position.getDataString (-leftPaddingLength, leftPaddingLength);
      writer.write (allignment.c_str (), leftPaddingLength - leftPad.length ());
      writer.write (leftPad);
   }
   
   //
   // separate left padding from seed
   writer << ' ';
   
   //
   // write the actual seed
   const int seedLength = tmin (Parser::__seed_o - 2 * leftPaddingLength, assg.length ());
   Str motif = position.getSeedString (seedLength);
   writer << motif;

   //
   // separate right padding from seed
   writer << ' ';

   //
   // right padding
   const int rightPaddingPosition = Parser::__seed_o - seedLength - leftPaddingLength;
   const int rightPaddingLength =  rightPaddingPosition;
   if (rightPaddingLength > 0) {
      Str rightPad = position.getDataString (rightPaddingPosition, rightPaddingLength);
      writer.write (rightPad);
      writer.write (allignment.c_str (), rightPaddingLength - rightPad.length ());
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
                            const SeedSearcher::Feature& feature_i,
                            const PositionVector& positions,
                            const std::string& allignment,
                            int index)
{
   //
   // create the motif file name
   char motifFileName [256];
   if (isPositives)
      sprintf (motifFileName, "%s.%d.motifs", Parser::__argv[Parser::__lastFileArg], (index+1));
   else
      sprintf (motifFileName, "%s.%d.neg.motifs", Parser::__argv[Parser::__lastFileArg], (index+1));

   ofstream motifFile (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile.is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   TextWriter writer (new StdOutputStream (motifFile));

   CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next ()) {
      printMotif (writer, *feature_i._assg, *(*it), allignment);
   }

   writer.flush ();
}



static void printPSSMFile ( const AlphabetCode& code,
                            const SeedSearcher::Feature& feature_i,
                            const PositionVector& positions,
                            int index)
                           
{
   const int seed_length = feature_i._assg->length ();
   const int offset = getMotifLeftOffset (Parser::__seed_o, seed_length);
   PSSM pssm(code, offset, Parser::__seed_o, positions);

   char motifFileName [256];
   sprintf (motifFileName, "%s.%d.pssm", Parser::__argv[Parser::__lastFileArg], (index+1));

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
                        SeedSearcher::ScoreFunction& scoreFunc,
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
   if (Parser::__score_fdr) {
      int K = StatFix::FDR (  bestFeatures, 
                              totalNumOfSeedsFound, 
                              Parser::__score_min);

      lastIndexToShow = tmin (lastIndexToShow, K);

      DLOG << "# Using FDR fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }
   if (Parser::__score_bonf) {
      int K = StatFix::bonferroni ( bestFeatures, 
                                    totalNumOfSeedsFound, 
                                    Parser::__score_min);

      lastIndexToShow = tmin (lastIndexToShow, K);

      DLOG << "# Using Bonferroni fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }

   DLOG.flush ();

   //
   // print (do not print less than 3)
   int index;
   lastIndexToShow = tmin (size, tmax (lastIndexToShow, 3));
   for (index=0 ; index<lastIndexToShow ; index++) {
      const SeedSearcher::Feature& feature_i = bestFeatures [index];
      DLOG << (-feature_i._score)
         << '\t'
         << Format (*feature_i._assg);

      if (feature_i._params) {
         DLOG << "\t[";
         scoreFunc.writeAsText (DLOG, feature_i._params);
         DLOG << ']';
      }

      DLOG << DLOG.EOL ();
   }

   //
   // now print the motif files
   std::string allignment (Parser::__seed_o, '-');
   for (index=0 ; index<lastIndexToShow ; index++) {
      const SeedSearcher::Feature& feature_i = bestFeatures [index];

      //
      // TODO: use the positions in the cluster if they are available
      Preprocessor::NodeCluster motifNodes;
      preprocessor.add2Cluster (motifNodes, *feature_i._assg);
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
   //exit (0);
}

static AutoPtr <SeqWeightFunction> createWeightFunction ()
{
   AutoPtr <SeqWeightFunction> wf;
   switch (Parser::__weightType) {
   case Parser::simple:
      wf = new SimpleWeightFunction (Parser::__weight_t);
      break;
   
   case Parser::border:
      wf = new BorderWeightFunction (Parser::__weight_lowt, Parser::__weight_t);
      break;
   case Parser::interval:
      wf = new IntervalWeightFunction (Parser::__weight_lowt, Parser::__weight_t);
      break;

   default:
      mustfail ();
      break;
   };

   if (Parser::__weight_invert)
      wf->invert ();

   return wf;
}

static AutoPtr <Preprocessor> createPreprocessor (const AlphabetCode& code,
                                                  const SequenceDB& db,
                                                  const SeqWeightFunction& wf)
{
   AutoPtr <Preprocessor> prep;
   if (Parser::__prep == Parser::leaf) {
      LeafPreprocessor::Rep* rep;
      if (Parser::__proj_spec) {
         rep = LeafPreprocessor::buildNoNegatives (  
            Parser::__seed_l, 
            db, 
            code, 
            SeedSearcherLog::assgWriter (),
            wf
         );
      }
      else {
         rep = LeafPreprocessor::build (  
            Parser::__seed_l, 
            db, 
            code, 
            SeedSearcherLog::assgWriter ()
         );
      }

      prep = new LeafPreprocessor (rep);
   }
   else {
      mustbe (Parser::__prep == Parser::tree);
      PrefixTreePreprocessor::TreeRep* rep = 
         PrefixTreePreprocessor::build (  Parser::__proj_spec,
                                          wf,
                                          db,
                                          Parser::__seed_l);

      prep = new PrefixTreePreprocessor (rep);
      ___kuku = dynamic_cast <PrefixTreePreprocessor*> (prep.get ());
   }

   return prep;
}

static AutoPtr <SeedSearcher::ScoreFunction> 
   createScoreFunc ( const SequenceDB& db,
                     const SeqWeightFunction& wf)
{
   AutoPtr <SeedSearcher::ScoreFunction> score;
   if (Parser::__count == Parser::total) {
      score = 
         new HyperGeoScore::FixedTotalCount (Parser::__seed_l, 
                                             Parser::__score_partial, 
                                             wf, 
                                             db);
   }
   else {
      score = 
         new HyperGeoScore::Simple (Parser::__score_partial, 
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
      new KBestFeatures (Parser::__seed_n, Parser::__seed_r),
      true,
      SeqCluster (db),
      wf,
      Parser::__score_min,
      Parser::__score_min_seq,
      Parser::__score_min_seq_per);

   return bestFeatures;
}




//
// Copied/Adapted from legacy SeedSearcher
int main(int argc, char* argv [])
{
   time_t cleanupStart, cleanupFinish;

   try {
      //
      // parse arguments
      Parser::parse (argc, argv);

      ofstream logOut;
      openLogFile (logOut);

      //
      // setup program output
      StdUnbufferedOutput consoleChannel (cout);
      StdUnbufferedOutput fileChannel (logOut);

      UnbufferedOutput* channels [] = { &consoleChannel, &fileChannel };
      const int numOfChannels = sizeof (channels) / sizeof (UnbufferedOutput*);

      ACGTWriter assgWriter;

      TextWriter consoleWriter (
         new SmallChannelOutput (
            new UnbufferedOutputMux (channels, numOfChannels , false), true));

      SeedSearcherLog::setup (assgWriter);
      SeedSearcherLog::setup (consoleWriter);

      //
      // welcome message
      welcomeMessage ();
      long start = time(NULL);

      //
      // for now, only ACGT code is available
      // TODO: add more alphabets
      const AlphabetCode& acgt = ACGTAlphabet::get (/*include N */ true);


      AutoPtr <SequenceDB> db;
      AutoPtr <SeqWeightFunction> wf;
      AutoPtr <Preprocessor> preprocessor;
      AutoPtr <SeedSearcher::ScoreFunction> score;
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
      // TODO: what should we do when Parser::__seed_r 
      // is too large for the length of seed?
      bestFeatures = createFeatureContainer (*db, *wf);

      //
      // now run over all projections, searching for seeds.
      // the seeds are stored inside kbestFeatures.
      Assignment assg;
      int totalNumOfSeedsFound = 0;
      int numOfProjections = projections->numOfProjections ();
      for (int i=0 ; i<numOfProjections ; i++) {
         projections->getAssignment (  assg, i,
                                       ACGTPosition (Assignment::together),
                                       ACGTPosition (Assignment::discrete));
         //
         //
         DLOG << "Searching for " << Format (assg) << ": ";
         DLOG.flush ();
         int save = totalNumOfSeedsFound;
         time_t start, finish;
         time (&start);

         if (Parser::__prep == Parser::tree) {
            totalNumOfSeedsFound +=
               SeedSearcher::prefixTreeSearch (
                  dynamic_cast <PrefixTreePreprocessor&> (*preprocessor),
                  assg,
                  *wf,
                  *score,
                  *bestFeatures,
                  Parser::__proj_spec
               );
         }
         else {
            totalNumOfSeedsFound +=
               SeedSearcher::tableSearch (
                  Parser::__count == Parser::total,
                  Parser::__proj_spec,
                  acgt,
                  *preprocessor,
                  assg,
                  assgWriter,
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
                  ACGTAlphabet::get (/*include N */ false),
                  *preprocessor, 
                  totalNumOfSeedsFound, 
                  *bestFeatures);

      long finish = time(NULL);
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

   time(&cleanupFinish);
   cerr << (cleanupFinish - cleanupStart) << " seconds." << endl;

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




