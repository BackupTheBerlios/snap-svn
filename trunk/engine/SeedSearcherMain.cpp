#include "SeedSearcherMain.h"
#include "DebugLog.h"
#include "StdOptions.h"

#include "LeafPreprocessor.h"
#include "HyperGeoScore.h"

#include <time.h>

USING_TYPE (SeedSearcherMain, CmdLineParameters);

void SeedSearcherMain::beforeSearch (int /* search handle */,
                              int totalNumOfSeedsFound,
                              const Assignment& assg
                              )
{
   DLOG << "Searching for " << Format (assg) << ": ";
   DLOG.flush ();

   _lastTotalNumOfSeedsFound = totalNumOfSeedsFound;
   time (&searchStart);
}

void SeedSearcherMain::afterSearch (int /* search handle */,
                  int totalNumOfSeedsFound,
                  const Assignment&
                              )
{
   time (&searchFinish);
   DLOG << (searchFinish - searchStart) << " seconds, Found "
         << totalNumOfSeedsFound - _lastTotalNumOfSeedsFound 
         << " seeds." << DLOG.EOL ();
}




AutoPtr <SeedSearcherMain::Results> SeedSearcherMain::search () {
   int totalNumOfSeedsFound = 0;
   int numOfProjections = _params.projections ().numOfProjections ();
   for (int i=0 ; i<numOfProjections ; i++) {
      //
      // create 
      const Assignment& assg = 
         _params.projections ().getAssignment (  i, 
                                    _params.langauge ().wildcard (Assignment::together),
                                    _params.langauge ().wildcard (Assignment::discrete));

      //
      //
      beforeSearch (i, totalNumOfSeedsFound, assg);

      //
      //
      if (_params.prepType () == _prep_tree_) {
         totalNumOfSeedsFound +=
            SeedSearcher::prefixTreeSearch (
               _params,
               assg
            );
      }
      else {
         totalNumOfSeedsFound +=
            SeedSearcher::tableSearch (
               _params,
               assg
            );
      }

      afterSearch (i, totalNumOfSeedsFound, assg);
   }

   //
   // now output all the seeds
   _params.bestFeatures().sort ();

   return new Results (_params, totalNumOfSeedsFound);
}



void SeedSearcherMain::CmdLineParameters::setup ()
{
   //
   //
   setupParameters ();

   //
   //
   setupLangauge ();

   //
   // setup the db
   setupDB ();

   //
   // create the weight function
   setupWeightFunction ();

   //
   // create the preprocessor
   setupPreprocessor ();

   //
   // create random projections
   setupProjections ();

   //
   // create the hyper-geometric scoring scheme
   setupScoreFunc ();

   //
   // keep only the best features
   // TODO: what should we do when _parser.__seed_r 
   // is too large for the length of seed?
   setupFeatureContainer ();
}

void SeedSearcherMain::CmdLineParameters::setupParameters ()
{
   _searchType = _parser.__searchType;
   _prepType = _parser.__prep;
   _count = _parser.__count;
   _useSpecialization = _parser.__proj_spec;
   _useReverse = _parser.__count_reverse;
}


void SeedSearcherMain::CmdLineParameters::setupProjections ()
{
   //
   // initialize the random seed
   RandomProjections::srand (_parser.__proj_i);
   if (_parser.__proj_e) {
      _projections = new RandomProjections (
         RandomProjections::all,
         _parser.__seed_l,
         _parser.__proj_d);
   }
   else {
      _projections = new RandomProjections (
         _parser.__proj_n,
         _parser.__seed_l,
         _parser.__proj_d);
   }
}

void SeedSearcherMain::CmdLineParameters::setupDB ()
{
   DLOG << '#' << DLOG.EOL ()
        << "# SequenceDB: " << DLOG.EOL ();

   DLOG  << "Reading Sequence File: " 
         << _parser.__argv[_parser.__firstFileArg] 
         << DLOG.EOL ();

   DLOG  << "Reading Weights File: " 
         << _parser.__argv[_parser.__firstFileArg+1] 
         << DLOG.EOL ();

   DLOG.flush ();

   //
   // load the sequence files
   time_t start, finish;
   time (&start);
   _db = SequenceDB::TextFileStorage::loadFastaAndWeights (_langauge->code (),
      _parser.__argv[_parser.__firstFileArg],
      _parser.__argv[_parser.__firstFileArg+1]);

   time (&finish);

   DLOG << "Loaded " << _db->size () <<  " Sequences. ("
        << (finish - start) << " seconds )." << DLOG.EOL ();
}

void SeedSearcherMain::CmdLineParameters::setupWeightFunction ()
{
   switch (_parser.__weightType) {
   case _weight_simple_:
      _wf = new SimpleWeightFunction (_parser.__weight_t);
      break;
   
   case _weight_border_:
      _wf = new BorderWeightFunction (_parser.__weight_lowt, _parser.__weight_t);
      break;
   case _weight_interval_:
      _wf = new IntervalWeightFunction (_parser.__weight_lowt, _parser.__weight_t);
      break;

   default:
      mustfail ();
      break;
   };

   if (_parser.__weight_invert)
      _wf->invert ();

   _wf->partialCount (_parser.__score_partial);
}

void SeedSearcherMain::CmdLineParameters::setupPreprocessor ()
{
   _preprocessor =
      SeedSearcherMain::PreprocessorFactory::createPreprocessor (
         _parser.__prep,
         *_db,
         *_wf,
         *_langauge,
         _parser.__seed_l,
         useReverse (),
         _parser.__prep_noneg
      );
}

void SeedSearcherMain::CmdLineParameters::setupScoreFunc ()
{
   if (_parser.__count == _count_total_) {
      _score = 
         new HyperGeoScore::FixedTotalCount (_parser.__seed_l, 
                                             _parser.__score_partial, 
                                             *_wf, 
                                             *_db);
   }
   else {
      _score = 
         new HyperGeoScore::Simple (_parser.__score_partial, 
                                    *_wf, 
                                    *_db);
   }
}

void SeedSearcherMain::CmdLineParameters::setupFeatureContainer ()
{
   KBestFeatures* container = NULL;
   if (useReverse ()) {
      container  = 
         new KBestFeaturesComplement ( _parser.__seed_n, 
                                       _parser.__seed_r, 
                                       *_langauge);
   }
   else {
      container = 
         new KBestFeatures (_parser.__seed_n, _parser.__seed_r);
   }

   //
   // use GoodFeatures to allow only features above a threshold
   _bestFeatures = new GoodFeatures (
      container,
      true,
      SeqCluster (*_db),
      *_wf,
      _parser.__score_min,
      _parser.__score_min_seq,
      _parser.__score_min_seq_per);
}

void SeedSearcherMain::CmdLineParameters::setupLangauge ()
{
   _langauge = new ACGTLangauge;
   Langauge* old = SeedSearcherLog::setup (_langauge);
   delete old;
}


SeedSearcherMain::Results::Results (Parameters& params, int n)
: _index (0), _numSearched (n),
  _params (params)
{
   _numFound = _params.bestFeatures ().size ();
}

SeedSearcherMain::Results::~Results ()
{
}

Preprocessor*
   SeedSearcherMain::PreprocessorFactory::createPreprocessor (
               PrepType prepType,
               const SequenceDB& db,
               const SeqWeightFunction& wf,
               const Langauge& langauge,
               int featureLength,
               bool useReverse,
               bool removeNegatives
               )
{
   AutoPtr <Preprocessor> prep;
   if (prepType == _prep_leaf_) {
      LeafPreprocessor::Rep* rep;
      if (removeNegatives) {
         rep = LeafPreprocessor::buildNoNegatives (
            useReverse,
            featureLength, 
            db, 
            langauge,
            wf
         );
      }
      else {
         rep = LeafPreprocessor::build (  
            useReverse,
            featureLength, 
            db, 
            langauge
         );
      }

      prep = new LeafPreprocessor (rep);
   }
   else {
      mustbe (prepType == _prep_tree_);
      PrefixTreePreprocessor::TreeRep* rep = 
         PrefixTreePreprocessor::build (  removeNegatives,
                                          wf,
                                          db,
                                          featureLength);

      prep = new PrefixTreePreprocessor (rep);
   }

   return prep.release ();
}
