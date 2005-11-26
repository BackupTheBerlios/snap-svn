#include "SequenceDB.h"
#include "PrefixTreePreprocessor.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"

#include "StdOptions.h"

#include "Core/AutoPtr.h"
#include "Legacy/GetOpt.h"

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
  cerr << "  -n <N>       - Number of seeds to output (default = 3)" << endl;
  cerr << "  -l <Length>  - seed length (defualt = 10)" << endl;
  cerr << "  -L <Length>  - motif length (default = 20)" << endl;
  cerr << "  -m <Num>     - Number of random projections to try (default = 3)" << endl;
  cerr << "  -M           - exhaustive random projections" << endl;
  cerr << "  -d <Dist>    - Number of wildcard positions in seed (default = 2)" << endl;
  cerr << "  -t <thresh>  - Threshold for hard assignment of regulation (default = 0.5)" << endl;
  cerr << "  -r           - Use reverse strand as well" << endl;
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

  
  // init:
  SeedL = 9;
  dist = 3;
  UseRev = false;
  projNum = 3;
  bool allProjections = false;
  PSSML = 20;
  NumPSSM = 3;
  thresh = 0.5;
  char c;
  
  // parse commandLine:
  while( (c = getopt(argc,argv, "a:n:L:l:d:m:M:t:p:r")) != EOF )
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
    case 't':
      thresh = atof(optarg);
      break;      
    case 'r':
      UseRev = true;
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
   // TODO: also use GoodFeatures to allow only features above a threshold
   KBestFeatures kbestFeatures (NumPSSM);

   //
   // create the hyper-geometric scoring scheme
   // TODO: create more scoring schemes
   HyperGeoScore score (positiveSequences, *db);

   //
   // now run over all projections, searching for seeds.
   // the seeds are stored inside kbestFeatures.
   int numOfProjections = projections->numOfProjections ();
   for (int i=0 ; i<numOfProjections ; i++) {
      SeedSearcher::prefixTreeSearch (
         tree, 
         projections->getAssignment (i),
         positiveSequences, 
         score, 
         kbestFeatures);
   }

   //
   // TODO:now output all the seeds
   Persistance::TextWriter writer (new StdOutputStream (std::cout));
   kbestFeatures.write (writer, acgt);
   writer.flush ();


   long finish = time(NULL);
   cerr<<"SeedSearcher finished after "<<finish - start<<" seconds"<<endl;
   return 0;
}


