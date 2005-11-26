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
                                    _params.langauge ().wildcard (assg_together),
                                    _params.langauge ().wildcard (assg_discrete));

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
   _params.bestFeatures()->sort ();

   return new Results (_params, totalNumOfSeedsFound);
}



void SeedSearcherMain::CmdLineParameters::secondarySetup (int argc, char** argv)
{
   _parser.parse (argc, argv);

   //
   //
   setupParameters ();

   //
   // create random projections
   setupProjections ();
}

void SeedSearcherMain::CmdLineParameters::setup (const Str& seq, const Str& wgt)
{
   this->_seqFilename = seq;
   this->_wgtFilename = wgt;

   //
   //
   _prepType = _parser.__prep;
   _useSpecialization = _parser.__proj_spec;
   _useReverse = _parser.__count_reverse;


   //
   //
   setupParameters ();

   //
   //
   setupLangauge ();

   //
   // create random projections
   setupProjections ();

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
   // create the hyper-geometric scoring scheme
   setupScoreFunc ();

   //
   // keep only the best features
   // TODO: what should we do when _parser.__seed_r 
   // is too large for the length of seed?
   setupFeatureContainer ();

   //
   // TODO: this is a HACK!
   // searches should ignore assignments with N's
   // so now we disable the N
   dynamic_cast <ACGTLangauge*> (_langauge.get ())->includeN (false);
}

void SeedSearcherMain::CmdLineParameters::setupParameters ()
{
   _searchType = _parser.__searchType;
   _count = _parser.__count;
}


void SeedSearcherMain::CmdLineParameters::setupProjections ()
{
   //
   // initialize the random seed
   RandomProjections::srand (_parser.__proj_i);
   if (_parser.__proj_e) {
      _projections.reset (
            new RandomProjections (
               RandomProjections::all,
               _parser.__seed_l,
               _parser.__proj_d)
         );
   }
   else {
      _projections.reset (
            new RandomProjections (
               _parser.__proj_n,
               _parser.__seed_l,
               _parser.__proj_d)
            );
   }
}

void SeedSearcherMain::CmdLineParameters::setupDB ()
{
   DLOG << '#' << DLOG.EOL ()
        << "# SequenceDB: " << DLOG.EOL ();

   DLOG  << "Reading Sequence File: " 
         << _seqFilename
         << DLOG.EOL ();

   DLOG  << "Reading Weights File: " 
         << _wgtFilename
         << DLOG.EOL ();

   DLOG.flush ();

   //
   // load the sequence files
   time_t start, finish;
   time (&start);
   _db.reset (SequenceDB::TextFileStorage::loadFastaAndWeights (
      *_langauge,
      _seqFilename, 
      _wgtFilename));

   time (&finish);

   DLOG << "Loaded " << _db->size () <<  " Sequences. ("
        << (finish - start) << " seconds )." << DLOG.EOL ();
   DLOG.flush ();
}

void SeedSearcherMain::CmdLineParameters::setupWeightFunction ()
{
   switch (_parser.__weightType) {
   case _weight_simple_:
      _wf.reset (new SimpleWeightFunction (_parser.__weight_t));
      break;
   
   case _weight_border_:
      _wf.reset (new BorderWeightFunction (_parser.__weight_lowt, _parser.__weight_t));
      break;
   case _weight_interval_:
      _wf.reset (new IntervalWeightFunction (_parser.__weight_lowt, _parser.__weight_t));
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
   _preprocessor.reset (
      SeedSearcherMain::PreprocessorFactory::createPreprocessor (
         _parser.__prep,
         *_db,
         *_wf,
         *_langauge,
         _parser.__seed_l,
         useReverse (),
         _parser.__prep_noneg
      ));
}

void SeedSearcherMain::CmdLineParameters::setupScoreFunc ()
{
   if (_parser.__scoreType == _score_hypegeo_) {
      if (_parser.__count == _count_total_) {
         _score.reset ( 
            new HyperGeoScore::FixedTotalCount (_parser.__seed_l, 
                                                _parser.__score_partial, 
                                                *_wf, 
                                                *_db)
         );
      }
      else {
         _score.reset (
            new HyperGeoScore::Simple (_parser.__score_partial, 
                                       *_wf, 
                                       *_db)
          );
      }
   }
   else {
      mustbe (_parser.__scoreType == _score_exp_);
      _score.reset (new ExpScore (1.2, 1.2, *_wf));
   }
}

void SeedSearcherMain::CmdLineParameters::setupFeatureContainer ()
{
   KBestFilter* container = NULL;
   if (_parser.__seed_rr) {
      container  = 
         new KBestComplementFilter ( _parser.__seed_n, 
                                       _parser.__seed_r, 
                                       *_langauge);
   }
   else {
      container = 
         new KBestFilter (_parser.__seed_n, _parser.__seed_r);
   }

   //
   // use GoodFeaturesFilter to allow only features above a threshold
   _bestFeatures.reset (new BookkeeperFilter (
         new GoodFeaturesFilter (
            container,
            true,
            SeqCluster (*_db),
            *_wf,
            _parser.__score_min,
            _parser.__score_min_seq,
            _parser.__score_min_seq_per
         ), 
         true
      ));
}

void SeedSearcherMain::CmdLineParameters::setupLangauge ()
{
   //
   // at first N is considered to be a part of the langauge
   // this is in order to allow reading of seq files with N's
   _langauge.reset ( 
      new ACGTLangauge (_parser.__count_reverse, // support reverse
                        true // N is considered to be part of the langauge
                        ));

   SeedSearcherLog::setup (_langauge);
}


SeedSearcherMain::Results::Results (Parameters& params, int n)
: _index (0), _numSearched (n),
  _params (params)
{
   _numFound = _params.bestFeatures ()->size ();
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
            featureLength, 
            db, 
            langauge,
            wf
         );
      }
      else {
         rep = LeafPreprocessor::build (  
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
                                          langauge,
                                          featureLength);

      prep = new PrefixTreePreprocessor (rep);
   }

   return prep.release ();
}



