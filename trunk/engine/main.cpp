#include "SequenceDB.h"
#include "PrefixTreePreprocessor.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"

#include "StdOptions.h"
#include "DebugLog.h"

#include "Core/AutoPtr.h"

#if ENV_COMPILER==ENV_MICROSOFT
#include "Legacy/GetOpt.h"
#else
#include <getopt.h>
#endif 


#include "Persistance/TextWriter.h"
#include "Persistance/StdOutputStream.h"


#include <iostream>
#include <fstream>
#include <time.h>



using namespace std;
using namespace Persistance;


//
// Copied/Adapted from legacy SeedSearcher
static void Err(std::string const & s) {
   debug_mustfail ();
   cerr<<s<<endl;
   cerr.flush();
   exit(1);
}

//
// Copied/Adapted from legacy SeedSearcher
void
Usage(string err = "")
{
  cerr << "Usage: seedSearch <options> <SeqFile> <RegFile> <output stub> " << endl;
  cerr << "  " << endl;
  //  cerr << "  <SeqFile>     - file of sequences in format >name <tab> weight <tab> sequecne" << endl;
  cerr << "  <SeqFile>     - Fasta Format file for sequences" << endl;
  cerr << "  <RegFile>     - file of P(Reg) per sequences in format >name <tab> PReg" << endl;
  cerr << "" << endl;
  cerr << "Options:" << endl;
  cerr << "  -n <N>           - Number of seeds to output (default = 3)" << endl;
  cerr << "  -l <Length>      - seed length (defualt = 10)" << endl;
  cerr << "  -L <Length>      - motif length (default = 20)" << endl;
  cerr << "  -m <Num>         - Number of random projections to try (default = 3)" << endl;
  cerr << "  -M               - exhaustive random projections" << endl;
  cerr << "  -o               - length of offset to compare seed redundancy (default = 2)" << endl;
  cerr << "  -d <Dist>        - Number of wildcard positions in seed (default = 2)" << endl;
  cerr << "  -t <thresh>      - Threshold for hard assignment of regulation (default = 0.5)" << endl;
  cerr << "  -T <thresh>      - Threshold for minimum seed score (default = 0)" << endl;
  cerr << "  -f <frequency>   - Minimum positivie seqs that the seed apears in (default = 1)" << endl;
  cerr << "  -F <frequency>   - Minimum positivie seqs in percents that the seed apears in (default = 10%)" << endl;
  cerr << "  -r           - Use reverse strand as well (default = false)" << endl;
  cerr << "  -R           - Use weights to count sequences (default = false)" << endl;
  cerr << endl;
  if( err != "" )
    cerr << "Error: " << err << endl;
  exit(-1);
}


//
// Copied/Adapted from legacy SeedSearcher
int main(int argc, char* argv []) 
{
   //
   // welcome message
  const char* version = "release version";
  debug_only (version = "debug version");
  cerr << "SeedSearcher: " << version << endl << endl;

  long start = time(NULL);

   int SeedL;
   int dist;
   bool UseRev;
   int projNum;
   int PSSML;
   int NumPSSM;
   double thresh;
   int offsetRedundancy;
   bool weightCount;
   int minPosSeqs;
   int minPosSeqsPercent;
   int minScore;

  
  // init:
  SeedL = 9;
  dist = 3;
  UseRev = false;
  projNum = 3;
  bool allProjections = false;
  PSSML = 20;
  NumPSSM = 3;
  thresh = 0.5;
  offsetRedundancy = 2;
  weightCount = false;
  minPosSeqs = 1;
  minPosSeqsPercent = 10;
  minScore = 0;

  char c;
  
  // parse commandLine:
  while( (c = getopt(argc,argv, "a:n:L:l:d:m:M:o:t:T:p:r:R:f:F")) != EOF )
  {
    switch(c)
    {
    case 'n':
      NumPSSM = atoi(optarg);
      break;
    case 'd':
      dist = atoi(optarg);
      break;
    case 'l':
      SeedL = atoi(optarg);
      break;
    case 'L':
      PSSML = atoi(optarg);
      break;
    case 'm':
      projNum = atoi(optarg);
      break;
    case 'M':
       allProjections = true;
       break;
    case 'o':
      offsetRedundancy = atoi (optarg);
      break;
    case 't':
      thresh = atof(optarg);
      break;      
    case 'T':
      minScore = atof(optarg);
      break;      
    case 'r':
      UseRev = true;
      break;
    case 'R':
      weightCount = true;
      break;
    case 'f':
       minPosSeqs = atoi (optarg);
       break;
    case 'F':
       minPosSeqsPercent = atoi (optarg);
       break;
    case 'h':
      Usage();
      break;
    default:
      Usage("Unknown option");
    }
  }

 //////////////// test we get the right file names, do ouput formating:
  
  if( optind+3 > argc )
    Usage("Missing arguments");

  string outStub = string(argv[optind+2]);
  ofstream logOut((outStub+".log").c_str());
  if( ! logOut.is_open() )
    Err(string("Cannot open logFile for ")+outStub);


  //
  // for now, only ACGT code is available
  // TODO: add more alphabets
  const AlphabetCode& acgt = ACGTAlphabet::get ();
  
  ACGTWriter assgWriter;
  TextWriter consoleWriter (new StdOutputStream (std::cout));
  DebugLog::setup (assgWriter);
  DebugLog::setup (consoleWriter);

  //
  // load the sequence files
  AutoPtr <SequenceDB> db (
      SequenceDB::TextFileStorage::load (acgt, 
                                         string(argv[optind]).c_str (),
                                         string(argv[optind+1]).c_str ()
                                         )
                             );
   //
   // create random projections
   AutoPtr <RandomProjections> projections;
   if (allProjections) {
      projections = new RandomProjections (
         RandomProjections::all,
         acgt.cardinality (), 
         SeedL, 
         dist);
   }
   else {
      projections = new RandomProjections (
         projNum,
         acgt.cardinality (), 
         SeedL, 
         dist);
   }

   //
   // create the prefix tree.
   // TODO: ability to persist the prefix tree
   PrefixTreePreprocessor tree (
      PrefixTreePreprocessor::build (db.get (), SeedL +1));

   //
   // discover positively labeled sequences
   SequenceDB::Cluster positiveSequences;
   db->getSequencesAbove (thresh, positiveSequences);
   
   
   //
   // keep only the best features
   // TODO: what should we do when offsetRedundancy is too large for the length of seed?
   SeedSearcher::BestFeatures* bestFeatures = NULL;
   KBestFeatures kbestFeatures (NumPSSM, offsetRedundancy);
   // use GoodFeatures to allow only features above a threshold   
   GoodFeatures goodFeatures (&kbestFeatures, 
                              positiveSequences,
                              minScore, 
                              minPosSeqs, 
                              minPosSeqsPercent);
   if (goodFeatures.minPositiveSequences () > 0)
      bestFeatures = &goodFeatures;
   else
      bestFeatures = &kbestFeatures;

   //
   // create the hyper-geometric scoring scheme
   // TODO: create more scoring schemes
   HyperGeoScore score (weightCount, positiveSequences, *db);

   //
   // now run over all projections, searching for seeds.
   // the seeds are stored inside kbestFeatures.
   int numOfProjections = projections->numOfProjections ();
   for (int i=0 ; i<numOfProjections ; i++) {
      SeedSearcher::prefixTreeSearch (
         tree, 
         projections->getAssignment (i, 
                                    ACGTPosition (Assignment::together),
                                    ACGTPosition (Assignment::discrete)),
         positiveSequences, 
         score, 
         *bestFeatures);
   }

   //
   // TODO:now output all the seeds
   int size = bestFeatures->size ();
   for (i=0 ; i<size ; i++) {
      const SeedSearcher::Feature& feature_i = (*bestFeatures)[i];
      DLOG << Format (*feature_i._assg)
           << " : " 
           << (*bestFeatures)[i]._score 
           << DLOG.EOL ();
   }
   DLOG.flush ();

   long finish = time(NULL);
   cerr<<"SeedSearcher finished after "<<finish - start<<" seconds"<<endl;
   return 0;
}



