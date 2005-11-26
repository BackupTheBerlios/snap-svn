#include "SequenceDB.h"
#include "PrefixTreePreprocessor.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"
#include "HyperGeoScore.h"
#include "PrefixTreeWalker.h"
#include "PSSM.h"



#include "StdOptions.h"
#include "DebugLog.h"

#include "Core/AutoPtr.h"

#if ENV_COMPILER==ENV_MICROSOFT
#  include "Legacy/GetOpt.h"
#else
#  include <getopt.h>
#endif



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

static int __argc = 0;
static char** __argv = NULL;

static int __SeedL = 9;
static int __dist = 3;
static bool __UseRev = false;
static int __projNum = 3;
static int __PSSML = 20;
static int __NumPSSM = 3;
static double __thresh = 0.5;
static int __offsetRedundancy = 2;
static bool __weightCount = false;
static int __minPosSeqs = 1;
static int __minPosSeqsPercent = 10;
static double __minScore = 0.4;
static int __randSeed = 1;
static bool __allProjections = false;
static bool __totalCount = false;
static bool __useBonferroni = false;
static bool __useFDR = false;
static bool __readPreprocessed = false;
static bool __generatePreprocessed = false;
static const char* __readPreprocessedName = NULL;
static int __firstFileArg;
static int __lastFileArg;




//
// Copied/Adapted from legacy SeedSearcher
static void Err(std::string const & s) {
   debug_mustfail ();
   cerr<<s<<DLOG.EOL ();
   cerr.flush();
   exit(1);
}

//
// Copied/Adapted from legacy SeedSearcher
void
Usage(string err = "")
{
   cerr << "Usage: seedSearch <options> <SeqFile> <RegFile> <output stub> " << endl;
   cerr << "Usage: seedSearch <options> -p <preprocessed_file> <RegFile> <output stub> " << std::endl;
   cerr << "Usage: seedSearch <options> -P <preprocessed_file> <SeqFile>" << std::endl;
   cerr << "  " << std::endl;
   //  cerr << "  <SeqFile>     - file of sequences in format >name <tab> weight <tab> sequecne" << std::endl;
   cerr << "  <SeqFile>     - Fasta Format file for sequences" << std::endl;
   cerr << "  <RegFile>     - file of P(Reg) per sequences in format >name <tab> PReg" << std::endl;
   cerr << "" << std::endl;
   cerr << "Options:" << std::endl;
   cerr << "  -n <N>           - Number of seeds to output (default = 3)" << std::endl;
   cerr << "  -l <Length>      - seed length (defualt = 10)" << std::endl;
   cerr << "  -L <Length>      - motif length (default = 20)" << std::endl;
   cerr << "  -m <Num>         - Number of random projections to try (default = 3)" << std::endl;
   cerr << "  -M               - exhaustive random projections" << std::endl;
   cerr << "  -o <offset>      - length of offset to compare seed redundancy (default = 2)" << std::endl;
   cerr << "  -d <Dist>        - Number of wildcard positions in seed (default = 2)" << std::endl;
   cerr << "  -t <thresh>      - Threshold for hard assignment of regulation (default = 0.5)" << std::endl;
   cerr << "  -T <thresh>      - Threshold for minimum seed score (default = 0.5)" << std::endl;
   cerr << "  -f <frequency>   - Minimum positive seqs that seed appears in (default = 1)" << std::endl;
   cerr << "  -F <frequency>   - Minimum positive seqs (percents) that seed appears in (default = 10%)" << std::endl;
   cerr << "  -i <rand seed>   - Initialize random seed generator with a user defined seed (default = time)" << std::endl;
   cerr << "  -s               - Statistical fix (Bonferroni)" << std::endl;
   cerr << "  -S               - Statistical fix (FDR)" << std::endl;
   cerr << "  -r               - Use reverse strand as well (default = false)" << std::endl;
   cerr << "  -R               - Use weights to count sequences (default = false)" << std::endl;
   cerr << "  -C               - Use total counts instead of sequence counts (default = false)" << std::endl;
   cerr << "  -p <preprocess>  - Use preprocessed sequence file" << std::endl;
   cerr << "  -P <preprocess>  - Generate preprocessed sequence file" << std::endl;
   cerr << std::endl;
   if( err != "" )
      cerr << "Error: " << err << std::endl;
   exit(-1);
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

   for (int i=0 ;i<__argc ; i++)
      DLOG << __argv [i] << ' ';

   DLOG << DLOG.EOL ();

   //
   // (3) write execution parameters
   DLOG << "Seed length: " << __SeedL << DLOG.EOL ();
   DLOG << "No of Random Positions (dist): " << __dist << DLOG.EOL ();
   DLOG << "Use reverse: " << (__UseRev? "true" : "false") << DLOG.EOL ();
   DLOG << "No of Random Projections: " << __projNum << DLOG.EOL ();
   DLOG << "Use all possible projections: " << (__allProjections? "true" : "false") << DLOG.EOL ();
   DLOG << "PSSM length: " << __PSSML << DLOG.EOL ();
   DLOG << "No of PSSMs: " << __NumPSSM << DLOG.EOL ();
   DLOG << "Randomization seed: " << __randSeed  << DLOG.EOL ();
   DLOG << "Threshold for pos/neg cluster assignment: " << __thresh << DLOG.EOL ();
   DLOG << "Maximum offset to check for seed redundancy: " << __offsetRedundancy << DLOG.EOL ();
   DLOG << "Partial count: " << (__weightCount? "on" : "off") << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << __minPosSeqs << DLOG.EOL ();
   DLOG << "Minimum positive sequences a Seed must contain: " << __minPosSeqsPercent << '%' << DLOG.EOL ();
   DLOG << "Minimum score for seed: log (" << __minScore << ") = " << log (__minScore) << DLOG.EOL ();
   DLOG << "Use Total-Counts: " << (__totalCount? "true" : "false") << DLOG.EOL ();
   DLOG << "Use Bonferroni statistical fix: " << (__useBonferroni? "true" : "false") << DLOG.EOL ();
   DLOG << "Use FDR statistical fix: " << (__useFDR? "true" : "false") << DLOG.EOL ();
   DLOG.flush ();
}



static void parseArguments (int argc, char* argv[])
{
   __argc = argc;
   __argv = argv;

   // parse commandLine:
   char c;
   while( (c = getopt(argc,argv, "a:n:L:l:d:m:o:t:T:p:r:f:F:p:P:i:CMRsS")) != EOF )
   {
      switch(c)
      {
      case 'n':
         __NumPSSM = atoi(optarg);
         break;
      case 'd':
         __dist = atoi(optarg);
         break;
      case 'l':
         __SeedL = atoi(optarg);
         break;
      case 'L':
         __PSSML = atoi(optarg);
         break;
      case 'm':
         __projNum = atoi(optarg);
         break;
      case 'M':
         __allProjections = true;
         break;
      case 'o':
         __offsetRedundancy = atoi (optarg);
         break;
      case 't':
         __thresh = atof(optarg);
         break;
      case 'T':
         __minScore = atof(optarg);
         break;
      case 'r':
         __UseRev = true;
         break;
      case 'R':
         __weightCount = true;
         break;
      case 'f':
         __minPosSeqs = atoi (optarg);
         break;
      case 'F':
         __minPosSeqsPercent = atoi (optarg);
         break;
      case 'C':
         __totalCount = true;
         break;
      case 's':
         __useBonferroni = true;
         break;
      case 'S':
         __useFDR = true;
         break;
      case 'i':
         __randSeed = atoi (optarg);
         break;
      case 'p':
         __readPreprocessed = true;
         __readPreprocessedName = optarg;
         break;
      case 'P':
         __generatePreprocessed = true;
         break;
      case 'h':
         Usage();
         break;
      default:
         Usage("Unknown option");
      }
   }

   //////////////// test we get the right file names, do ouput formating:

   if (__readPreprocessed) { // needs RegFile and output-stub
      __firstFileArg = optind;
      __lastFileArg = optind+1;
   }
   else {   // needs SeqFile RegFile and output-stub
      __firstFileArg = optind;
      __lastFileArg = optind + 2;
   }

   if( __lastFileArg >= argc )
      Usage("Missing arguments");
}




static void setupRandomProjections (const AlphabetCode& code,
                                    AutoPtr <RandomProjections>& projections)
{
   //
   // initialize the random seed
   RandomProjections::srand (__randSeed);
   if (__allProjections) {
      projections = new RandomProjections (
         RandomProjections::all,
         code.cardinality (),
         __SeedL,
         __dist);
   }
   else {
      projections = new RandomProjections (
         __projNum,
         code.cardinality (),
         __SeedL,
         __dist);
   }


}


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

   std::string treeFile (__argv[__lastFileArg]);
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
   // SequenceDB::TextFileStorage::assignWeights (*db, __argv [__firstFileArg], true);
}



static void setupDBAndTree (const AlphabetCode& acgt,
                            AutoPtr <SequenceDB>& db,
                            AutoPtr <PrefixTreePreprocessor>& tree,
                            SequenceDB::Cluster& positiveSequences)
{
   DLOG << '#' << DLOG.EOL ()
      << "# SequenceDB & PrefixTreePreprocessor "<< DLOG.EOL ();

   //
   // create the prefix tree.
   if (__readPreprocessed) {
      readTreeFile (db, tree);
      db->getSequencesAbove (__thresh, positiveSequences);
   }
   else {
      debug_only (
         DLOG << "Reading Sequence File: " << __argv[__firstFileArg] << DLOG.EOL ();
      DLOG << "Reading Weights File: " << __argv[__firstFileArg+1] << DLOG.EOL ();
      DLOG.flush ();
      );

      //
      // load the sequence files
      time_t start, finish;
      time (&start);
      db = SequenceDB::TextFileStorage::loadFastaAndWeights (acgt,
         __argv[__firstFileArg],
         __argv[__firstFileArg+1]);
      time (&finish);
      DLOG << "Loaded " << db->size () <<  " Sequences. ("
           << (finish - start) << " seconds )." << DLOG.EOL ();

      debug_only (
         DLOG << "Creating a new PrefixTree Preprocessor from sequence data: " << DLOG.EOL ();
         DLOG.flush ();
      );

      DLOG.flush ();
      db->getSequencesAbove (__thresh, positiveSequences);

      tree  = new PrefixTreePreprocessor (PrefixTreePreprocessor::build (
         positiveSequences,
         db.get (),
         __SeedL));
   }
}

static void openLogFile (ofstream& logOut)
{
   string outStub;
   outStub = string(__argv[__lastFileArg]);
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
      getMotifLeftOffset (__PSSML, assg.length ());

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
   const int seedLength = tmin (__PSSML - 2 * leftPaddingLength, assg.length ());
   Str motif = position.getSeedString (seedLength);
   writer << motif;

   //
   // separate right padding from seed
   writer << ' ';

   //
   // right padding
   const int rightPaddingPosition = __PSSML - seedLength - leftPaddingLength;
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
                            const PrefixTreePreprocessor& tree,
                            const SeedSearcher::Feature& feature_i,
                            const Preprocessor::PositionVector& positions,
                            const std::string& allignment,
                            int index)
{
   //
   // create the motif file name
   char motifFileName [256];
   if (isPositives)
      sprintf (motifFileName, "%s.%d.motifs", __argv[__lastFileArg], (index+1));
   else
      sprintf (motifFileName, "%s.%d.neg.motifs", __argv[__lastFileArg], (index+1));

   ofstream motifFile (motifFileName,
                   ios_base::out | ios_base::trunc | ios_base::binary);

   if( ! motifFile.is_open() )
      Err(string("Cannot open logFile for ") + motifFileName);

   TextWriter writer (new StdOutputStream (motifFile));

   Preprocessor::CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next ()) {
      printMotif (writer, *feature_i._assg, *(*it), allignment);
   }

   writer.flush ();
}

static void printPSSMFile ( const AlphabetCode& code,
                            const PrefixTreePreprocessor& tree,
                            const SeedSearcher::Feature& feature_i,
                            const Preprocessor::PositionVector& positions,
                            int index)
                           
{
   const int seed_length = feature_i._assg->length ();
   const int offset = getMotifLeftOffset (__PSSML, seed_length);
   PSSM pssm(code, offset, __PSSML, positions);

   char motifFileName [256];
   sprintf (motifFileName, "%s.%d.pssm", __argv[__lastFileArg], (index+1));

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


static void printSeeds (const AlphabetCode& code,
                        const SeqCluster& postivelyLabeled,
                        PrefixTreePreprocessor& tree,
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
   if (__useFDR) {
      int K = StatFix::FDR (bestFeatures, totalNumOfSeedsFound, __minScore);
      lastIndexToShow = min (lastIndexToShow, K);
      DLOG << "# Using FDR fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }
   if (__useBonferroni) {
      int K = StatFix::bonferroni (bestFeatures, totalNumOfSeedsFound, __minScore);
      lastIndexToShow = min (lastIndexToShow, K);
      DLOG << "# Using Bonferroni fix: showing "
         << lastIndexToShow << " of " << size << " seeds."
         << DLOG.EOL ();
   }

   DLOG.flush ();

   //
   // print (do not print less than 3)
   lastIndexToShow = min (size, max (lastIndexToShow, 3));
   for (int index=0 ; index<lastIndexToShow ; index++) {
      const SeedSearcher::Feature& feature_i = bestFeatures [index];
      DLOG << feature_i._score
         << ' '
         << Format (*feature_i._assg)
         << DLOG.EOL ();
   }

   //
   // now print the motif files
   std::string allignment (__PSSML, '-');
   for (index=0 ; index<lastIndexToShow ; index++) {
      const SeedSearcher::Feature& feature_i = bestFeatures [index];

      //
      // TODO: use the positions in the cluster if they are available
      PrefixTreeWalker::Nodes motifNodes;
      motifNodes.addAssignmentNodes (tree, *feature_i._assg);

      Preprocessor::PositionVector posPositions;
      Preprocessor::PositionVector negPositions;
      motifNodes.positions (__thresh, posPositions, negPositions);

      //
      // print motif in positive set
      printMotifFile (  true,
                        tree, 
                        feature_i, 
                        posPositions, 
                        allignment, 
                        index);

      //
      // print motif in negative set
      printMotifFile (  false,
                        tree, 
                        feature_i, 
                        negPositions, 
                        allignment, 
                        index);

      //
      // build PSSM from positive positions only
      // TODO: is this correct?
      printPSSMFile (code, tree, feature_i, posPositions, index);
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


//
// Copied/Adapted from legacy SeedSearcher
int main(int argc, char* argv [])
{
   time_t cleanupStart, cleanupFinish;
   __randSeed = time (NULL);
   try {
      //
      // parse arguments
      parseArguments (argc, argv);

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

      //
      // create random projections
      AutoPtr <RandomProjections> projections;
      setupRandomProjections (acgt, projections);

      AutoPtr <SequenceDB> db;
      AutoPtr <PrefixTreePreprocessor> tree;
      SequenceDB::Cluster positiveSequences;
      setupDBAndTree (acgt, db, tree, positiveSequences);

      //
      // TODO: if we have read the tree file from archive,
      // and we need longer seeds than the tree's depth,
      // then continue to build the tree until the required size

      if (__generatePreprocessed) {
         saveTreeFile (db, tree);
      }

      //
      // keep only the best features
      // TODO: what should we do when __offsetRedundancy is too large for the length of seed?
      SeedSearcher::BestFeatures* bestFeatures = NULL;
      KBestFeatures kbestFeatures (__NumPSSM, __offsetRedundancy);
      //
      // use GoodFeatures to allow only features above a threshold
      GoodFeatures goodFeatures (&kbestFeatures,
         positiveSequences,
         __minScore,
         __minPosSeqs,
         __minPosSeqsPercent);

      if (goodFeatures.minPositiveSequences () > 0)
         bestFeatures = &goodFeatures;
      else
         bestFeatures = &kbestFeatures;

      //
      // create the hyper-geometric scoring scheme
      AutoPtr <SeedSearcher::ScoreFunction> score;
      if (__totalCount)
         score = new HyperGeoScore::FixedTotalCount (__SeedL, __weightCount, positiveSequences, *db);
      else
         score = new HyperGeoScore::Simple (__weightCount, positiveSequences, *db);

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

         if (!__totalCount) {
            totalNumOfSeedsFound +=
               SeedSearcher::prefixTreeSearch (
               *tree,
               assg,
               positiveSequences,
               *score,
               *bestFeatures);
         }
         else {
            totalNumOfSeedsFound +=
               SeedSearcher::totalCountSearch (
               *tree,
               assg,
               assgWriter,
               positiveSequences,
               *score,
               *bestFeatures);
         }

         time (&finish);
         DLOG << (finish - start) << " seconds, Found "
              << totalNumOfSeedsFound - save << " seeds." << DLOG.EOL ();
      }

      //
      // now output all the seeds
      kbestFeatures.sort ();
      //
      // do not include N when printing PSSMs
      printSeeds (ACGTAlphabet::get (/*include N */ false),
                  positiveSequences,
                  *tree, 
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

//
// for each seed - we need to go over all positions - 


/*
typedef 

static void computePSSM (const SeedSearcher::Feature& feature, 

void 

void
computePSSM(map<codeVec,Vec<tMultinomial> > & motifsPSSM ,map<codeVec,Vec<pair<codeVec,Location> > > const & motifSamples)
{
   for (map<codeVec,Vec<pair<codeVec,Location> > >::const_iterator p = motifSamples.begin();
   p!= motifSamples.end();p++) {
      
      codeVec const & code = p->first;
      Vec<pair<codeVec,Location> >  const & currMotifSamples = p->second;
      for (int index = 0;index<PSSML;index++) {
         vector<double> counts(4,0.0);      
         
         Vec<pair<codeVec,Location> >::const_iterator sit = currMotifSamples.begin()
         for (;sit != currMotifSamples.end();sit++) {
            codeVec const & sample = (*sit).first;
            int val = (int) (sample[index]);
            if (  val < 4) 
               counts[val]++;
         }// over all samples in this position

         motifsPSSM[code].push_back(tMultinomial(counts,false));	  
      } // over all positions
   } // over all motifs
}
*/