#include "SeedSearcherMain.h"
#include "DebugLog.h"
#include "StdOptions.h"

#include "LeafPreprocessor.h"
#include "HyperGeoScore.h"

#include "StatusReporter/BaseStatusReporter.hpp"
#include <time.h>

USING_TYPE (SeedSearcherMain, CmdLineParameters);


//
// SeedSearcherMain
//


struct CancelledByUserException : public BaseException {
};

void SeedSearcherMain::beforeProjection (int /* search handle */,
                              int totalNumOfSeedsFound,
                              const Assignment& assg
                              )
{

   //
   // check if we should stop
   if (StatusReportManager::hasUserCancelled ()) {
      StatusReportManager::setJobCancelled ();
      throw CancelledByUserException ();
   }

   //
   // output progress message
   DLOG << "Searching for " << Format (assg) << ": ";
   DLOG.flush ();

   //
   // time the projection
   _lastTotalNumOfSeedsFound = totalNumOfSeedsFound;
   time (&searchStart);
}

void SeedSearcherMain::afterProjection (int /* search handle */,
                  int totalNumOfSeedsFound,
                  const Assignment&
                              )
{
   //
   // time the projection
   time (&searchFinish);

   //
   // produce output message
   DLOG << (searchFinish - searchStart) << " seconds, Found "
         << totalNumOfSeedsFound - _lastTotalNumOfSeedsFound 
         << " seeds." << DLOG.EOL ();

   //
   // indicate progress
   StatusReportManager::setProgress ();
}




AutoPtr <SeedSearcherMain::Results> 
SeedSearcherMain::search (boost::shared_ptr <Parameters> inParams) 
{
   mustbe (inParams);
   _params = inParams;

   int totalNumOfSeedsFound = 0;
   int numOfProjections = _params->projections ().numOfProjections ();
   for (int i=0 ; i<numOfProjections ; i++) {
      //
      // create 
      const Assignment& assg = 
         _params->projections ().getAssignment (  i, 
                                    _params->langauge ().wildcard (assg_together),
                                    _params->langauge ().wildcard (assg_discrete));

      //
      // call virtual 'beforeProjection' handler
      beforeProjection (i, totalNumOfSeedsFound, assg);

      //
      // perform the actual search
      if (_params->prepType () == _prep_tree_) {
         totalNumOfSeedsFound +=
            SeedSearcher::prefixTreeSearch (
               *_params,
               assg
            );
      }
      else {
         totalNumOfSeedsFound +=
            SeedSearcher::tableSearch (
               *_params,
               assg
            );
      }
      //
      // call virtual 'afterProjection' handler
      afterProjection (i, totalNumOfSeedsFound, assg);
   }

   //
   // now output all the seeds
   _params->bestFeatures()->sort ();

   return new Results (_params, totalNumOfSeedsFound);
}

void SeedSearcherMain::search (ParameterIterator& it)
{
   for (; it.hasNext () ; it.next ()) {
      //
      // get current run parameters
      boost::shared_ptr <Parameters> params = it.get ();

      beforeSearch (*params);

      AutoPtr <Results> results = search (params);

      afterSearch (*results);
   }
}









//
// CmdlineParameters
//



void SeedSearcherMain::CmdLineParameters::secondarySetup (int argc, char** argv)
{
   secondarySetup (Parser (argc, argv));
}

void SeedSearcherMain::CmdLineParameters::secondarySetup (const Parser& inParser)
{
   _parser= inParser;

   //
   //
   setupParameters ();

   //
   // create random projections
   setupProjections ();

   //
   // create the weight function
   setupWeightFunction ();

   //
   // create the hyper-geometric scoring scheme
   setupScoreFunc ();
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

   _parser.__proj_n = _projections->numOfProjections ();
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






//
// Results
//




SeedSearcherMain::Results::Results (boost::shared_ptr <Parameters> params, int n)
: _index (0), _numSearched (n),
  _params (params)
{
   _numFound = _params->bestFeatures ()->size ();
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




//
// ConfParameterIterator
//

#include "SeedConf.h"

ConfParameterIterator::ConfParameterIterator (int argc, char* argv [])
: _optList (argc, argv), _useInitParameters (true), _updated(false)
{
   Parser parser (argc, argv);
   if (!parser.__conf.empty ()) {
      SeedConf::read (parser.__conf, _optList);
      _it = _optList.iterator ();
      _useInitParameters = false;
   }
}

ConfParameterIterator::~ConfParameterIterator ()
{
   while (!_list.empty ())
      delete _list.removeFirst ();
}

void ConfParameterIterator::setup (const Str& seqFilename, 
                                   const Str& wgtFilename,
                                   const Str& stubName)
{
   _stub = stubName;

   //
   // setup the first parameters
   AutoPtr <CmdLineParameters> params = 
      new CmdLineParameters (_optList.getInitParser ());

   params->setup (seqFilename, wgtFilename);
   params->setName (stubName);

   //
   // add the new entry to the list
   StatusReportManager::setMaxProgress(params->parser ().__proj_n);
   _list.addLast (new ParamNode (Param_var (params.release ())));

   if (!_optList.empty ()) {
      //
      // the first parameters are used just to setup the system
      // now we setup the first search parameters
      params = new CmdLineParameters (*_list.getLast ()->data);
      params->secondarySetup ( _it.get()->_parser);
      params->setName (_it.get()->_name);

      //
      // add the new entry to the list
      _list.addLast (new ParamNode (Param_var (params.release ())));

      //
      // calculate the number of projections in all searches
      // this counts as the max number of progression points
      int progPoints = 0;
      SeedConfList::OptionIterator it;
      for (it = _optList.iterator (); it.hasNext () ; it.next ()) {
         progPoints += 
            RandomProjections::numOfProjections (
               it.get ()->_parser.__proj_e, it.get ()->_parser.__proj_n,
               it.get ()->_parser.__seed_l, it.get ()->_parser.__proj_d);
      }
      StatusReportManager::setMaxProgress(progPoints);
   }
}

bool ConfParameterIterator::hasNext () {
   return _useInitParameters || _it.hasNext ();
}

boost::shared_ptr <SeedSearcherMain::Parameters> ConfParameterIterator::get () 
{
   if (!_useInitParameters) {
      if (!_updated) {
         //
         // generate the new options only once
         _updated = true;

         //
         // get parameters of last run
         AutoPtr <CmdLineParameters> params = 
            new CmdLineParameters (*_list.getLast ()->data);

         Str name;
         StrBuffer nameBuffer;
         if (!_stub.empty ()) {
            if (!_it.get()->_name.empty ()) {
               nameBuffer.acquire (
                  StrBuffer (_stub, Str ("."), _it.get()->_name).release());

               name = nameBuffer;
            }
            else {
               name = _stub;
            }
         }
         else {
            name = _it.get()->_name;
         }

         params->setName (name);

         //
         // update parameters for current options
         params->secondarySetup ( _it.get()->_parser);

         //
         // if required, get rid of previous seeds
         if (_it.get ()->_resetSeeds) {
            params->setupFeatureContainer ();
         }

         //
         // add the new entry to the list
         _list.addLast (new ParamNode (Param_var (params.release ())));
      }
   }

   return _list.getLast ()->data;
}

void ConfParameterIterator::next ()
{
   mustbe (hasNext ());
   //
   // 
   if (_useInitParameters) {
      _useInitParameters = false;
   }
   else {
      //
      // next options
      _it.next ();
   }

   _updated = false;
}
