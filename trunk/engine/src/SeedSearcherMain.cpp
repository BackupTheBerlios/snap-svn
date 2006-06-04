//
// File        : $RCSfile: $
//               $Workfile: SeedSearcherMain.cpp $
// Version     : $Revision: 35 $
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $
// Description :
//    Concrete and interface classes for seting-up
//    a seed-searching environment or program
//
// Author:
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program.
// for details see www.huji.ac.il/~hoan
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "SeedSearcherMain.h"
#include "DebugLog.h"
#include "StdOptions.h"

#include "LeafPreprocessor.h"
//#include "HyperGeoScore.h"
#include "ExtraMath.h"
#include "Score.h"

#include "status_reporter/BaseStatusReporter.hpp"
#include <time.h>
#include <boost/cast.hpp>


USING_TYPE (SeedSearcherMain, CmdLineParameters);


//
// SeedSearcherMain
//


struct CancelledByUserException : public BaseException {
};

SeedSearcherMain::SeedSearcherMain ()
{
   //
   // initialize the random seed
   RandomProjections::srand (static_cast <unsigned int> (time (NULL)));
}

void SeedSearcherMain::beforeProjection (int /* search handle */,
                              int totalNumOfSeedsFound,
                              const Assignment& assg
                              )
{

   //
   // check if we should stop
   if (StatusReportManager::hasUserCancelled ()) {
      throw BaseStatusReporter::StatusException ("Job was cancelled by user");
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
   DLOG << static_cast <int>(searchFinish - searchStart) << " seconds, Found "
         << totalNumOfSeedsFound - _lastTotalNumOfSeedsFound
         << " seeds." << DLOG.EOL ();

   //
   // indicate progress
   StatusReportManager::setProgress ();
}




AutoPtr <SeedSearcherMain::Results>
SeedSearcherMain::search (boost::shared_ptr <CmdLineParameters> inParams)
{
   //
   // copy the params
	boost::shared_ptr <Parameters> currentPameters (new Parameters (*inParams));

	// create a fresh feature set, with all extended filters
	currentPameters->bestFeatures (
		FeatureSetManager::createFilters(*inParams, true)
	);

   debug_mustbe (currentPameters->bestFeatures ().getArray()->size () == 0);

   int totalNumOfSeedsFound = 0;
   int numOfProjections = currentPameters->projections ().numOfProjections ();
   for (int i=0 ; i<numOfProjections ; i++) {
      //
      // create
      const Assignment& assg =
         currentPameters->projections ().getAssignment (i);


      //
      // call virtual 'beforeProjection' handler
      beforeProjection (i, totalNumOfSeedsFound, assg);

      //
      // perform the actual search
		int currentSeedsFound;
      if (currentPameters->searchType () == _search_tree_) {
         currentSeedsFound = 
            SeedSearcher::prefixTreeSearch (
               currentPameters,
               assg
            );
      }
      else {
         currentSeedsFound = 
            SeedSearcher::tableSearch (
               currentPameters,
               assg
            );
      }
		totalNumOfSeedsFound += currentSeedsFound; 
      //
      // call virtual 'afterProjection' handler
      afterProjection (i, totalNumOfSeedsFound, assg);
		currentPameters->bestFeatures ().finalizeProjection (currentSeedsFound); 
   }
/*
   //
   // now we bonferroni-correct all the scores of the seeds found
   // and insert the new seeds to the original feature array
   // TODO: correctly bonf correct
   FeatureSet::Iterator it = currentPameters.bestFeatures()->getIterator();
   for (; it.hasNext () ; it.next()) {
      (*it)->numSeedsSearched(totalNumOfSeedsFound);
      inParams->bestFeatures ().add (*it);
   }
	inParams->bestFeatures ().finalize ();
*/

	//
	// run finalizing scripts, like statistical corrections.
	currentPameters->bestFeatures ().finalizeSetting (totalNumOfSeedsFound, numOfProjections);

   FeatureSet::Iterator it = currentPameters->bestFeatures()->getIterator();
   for (; it.hasNext () ; it.next()) {
		inParams->bestFeatures ().add (*it);
	}

   //
   // now output all the seeds
   return new Results (inParams, totalNumOfSeedsFound);
}

void SeedSearcherMain::search (ParameterIterator& it)
{
   for (; it.hasNext () ; it.next ()) {
      //
      // get current run parameters
      boost::shared_ptr <Parameters> pparams = it.get ();
		boost::shared_ptr <CmdLineParameters> params = 
			boost::shared_dynamic_cast < 
				CmdLineParameters > (pparams);

      beforeSearch (*params);
		
      AutoPtr <Results>	 results = search (params);

      afterSearch (*results);
   }
}









//
// CmdlineParameters
//



void SeedSearcherMain::CmdLineParameters::secondarySetup (int argc, char* const* argv)
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
   // TODO: HACK HERE!!!
   (boost::polymorphic_downcast<ACGTLangauge*> (_langauge.get ()))->includeN (false);

	///
	/// anticipate n searches
	StatusReportManager::setMaxProgress(_parser.__proj_n);
}

void SeedSearcherMain::CmdLineParameters::setupParameters ()
{
   _searchType = _parser.__searchType;
   _useTotalCount = 
            _parser.__count == _count_total_ || 
            _parser.__score_partial == _position_weight_hotspots_;
}


void SeedSearcherMain::CmdLineParameters::setupProjections ()
{
   if (_parser.__proj_i)   {
      //
      // initialize the random seed with a specific seed
      RandomProjections::srand (_parser.__proj_i);
   }

   //
   // check if a specific projection was asked for
   if (!_parser.__proj_base.empty()) {
      if (_parser.__proj_e) {
         _projections.reset(
            new SpecificProjectionGenerator (
               RandomProjections::all,
               _parser.__proj_base,
               _parser.__proj_d,
					_parser.__proj_outer,
               _langauge
               ));
      }
      else {
         _projections.reset (
            new SpecificProjectionGenerator (
            _parser.__proj_n,
            _parser.__proj_base,
            _parser.__proj_d,
				_parser.__proj_outer,
            _langauge)
            );
      }
   }
   else {
      if (_parser.__proj_e) {
         _projections.reset (
               new MidsectionRandomProjections (
                  RandomProjections::all,
                  _parser.__seed_l,
                  _parser.__proj_d,
                  _parser.__proj_mid,
						_parser.__proj_outer,
                  _langauge)
            );
      }
      else {
         _projections.reset (
               new MidsectionRandomProjections (
                  _parser.__proj_n,
                  _parser.__seed_l,
                  _parser.__proj_d,
                  _parser.__proj_mid,
						_parser.__proj_outer,
                  _langauge)
               );
      }
   }

   _parser.__proj_n = _projections->numOfProjections ();
}

void SeedSearcherMain::CmdLineParameters::setupDB ()
{

   DLOG << '#' << DLOG.EOL ()
        << "# SequenceDB: " << DLOG.EOL ();

	if (!_seqNameWeights) {
		DLOG  << "Reading Weights File: "
				<< _wgtFilename
				<< DLOG.EOL ();

		DLOG.flush ();

		_seqNameWeights.reset ((SeqWeightDB::readWgtFile (_wgtFilename)).release ());
	}

	if (!_db) {

		DLOG  << "Reading Sequence File: "
				<< _seqFilename
				<< DLOG.EOL ();

		//
		// load the sequence files
		time_t start, finish;
		time (&start);
		_db.reset (SequenceDB::TextFileStorage::loadFastaAndWeights (
			*_langauge,
			_seqFilename,
			*_seqNameWeights));

		_seqWeights.reset (SeqWeightDB::computeWeightIndex (*_seqNameWeights, *_db).release ());

		time (&finish);

		DLOG << "Loaded " << _db->size () <<  " Sequences. ("
			  << static_cast <int>(finish - start) << " seconds )." << DLOG.EOL ();
		DLOG.flush ();
	}
}

void SeedSearcherMain::CmdLineParameters::setupWeightFunction ()
{
   _wf.reset (new SimpleWeightFunction (_seqWeights, _parser.__weight_t));
}

void SeedSearcherMain::CmdLineParameters::setupPreprocessor ()
{
   _preprocessor.reset (
      SeedSearcherMain::PreprocessorFactory::createPreprocessor (
         _parser.__prep,
         *_db,
         *_wf,
         *_langauge,
         _parser.__prep_l,
         useReverse (),
         _parser.__prep_noneg
      )
   );
}

void SeedSearcherMain::CmdLineParameters::setupScoreFunc ()
{
	//
	// create the score factory
	boost::shared_ptr <Scores::Factory> factory;
	switch (_parser.__scoreType) {
		case _score_hypegeo_:
			factory.reset (new Scores::HyperGeometricPvalueFactory);
			break;

		case _score_exp_: {
				boost::shared_ptr <Scores::ExplossWeights> weights (
					new Scores::ExplossWeights (_parser.__expLossPos, _parser.__expLossNeg)
				);

				factory.reset (new Scores::ExplossScoreFactory (weights));
			}
			break;
	}

	//
	//
	_score = Scores::makeFunction (
		_parser.__count, 
		_parser.__score_partial, 
		_db, _wf, 
		factory, 
		_parser.__seed_l);
}

void SeedSearcherMain::CmdLineParameters::setupFeatureContainer ()
{
	boost::shared_ptr <FeatureSet> newFeatureContainer (new FeatureSet);
	if (_bestFeatures) {
		//
		// import all features from the previous container
		newFeatureContainer->insertFeatures (_bestFeatures->getArray ()->begin (), _bestFeatures->getArray ()->end ());
	}

	_bestFeatures = FeatureSetManager::createFilters (*this, false, newFeatureContainer);
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
: _numSearched (n),
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

ConfParameterIterator::ConfParameterIterator (int argc, char* const * argv)
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
               it.get ()->_parser.__seed_l, it.get ()->_parser.__proj_d,
					it.get ()->_parser.__proj_outer);
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




SeedSearcher::FeatureFilter_ptr 
	SeedSearcherMain::FeatureSetManager::createFilters (	
		const CmdLineParameters& params,
		bool temporary,
		FeatureSet_ptr container)
{
	const Parser& parser = params.parser ();
	if (!container) {
		container.reset(new FeatureSet);
	}

	//
	// the temporary FeatureSet may include additional filters, like
	// the logging filter and the good-features filter
	// as well as the statistical correction filters
	//
	// also, the FeatureSet is built twice, so that after removing redundancies
	// enough features will remain
	static const int EXPAND_FACTOR = 2;

	//
	// build the basic redundancy removing filters
	SeedSearcher::FeatureFilter_ptr filter;
	if (parser.__seed_rr) {
		filter.reset (
			new KBestComplementFilter ( parser.__seed_n * EXPAND_FACTOR,
				parser.__seed_r,
				params.langauge(),
				container
			)
		);
	}
	else {
		filter.reset(
			new KBestFilter (parser.__seed_n * EXPAND_FACTOR, parser.__seed_r, container)
		);
	}
	
	if (temporary) {
		//
		// install statistical correction filters
		switch (parser.__statfix_t) {
			default:
				mustfail ();
				break;

			case _statfix_bonf_:
				filter.reset(new BonfCorrectionFilter (filter));
				break;

			case _statfix_fdr_:
				filter.reset(new FDRCorrectionFilter (filter));
				break;
				
			case _statfix_none_:
				;
		}
		
		//
		// use FertileFeaturesFilter to allow only features that contain
		// enough positive promoters
		filter.reset (
			new FertileFeaturesFilter (
				filter,			
				SeqCluster (params.db ()),
				params.wf (),
				parser.__score_min_seq,
				parser.__score_min_seq_per 
			)
		);
	}

	//
	// quickly discard irrelevant features - by looking at their score
	filter.reset(
		new ScoreFeaturesFilter (
			filter, 
			// convert to log2 format
			(0 - parser.__minusLog10score_min) * log2 (10)
		)
	);

	if (temporary) {
		if (parser.__generateSeedlog == Parser::_out_all_) {
			//
			// we insert a filter which prints to file all given seeds
			filter.reset (new FeaturePrintFilter (filter, params.name ()));
		}
	}

	return filter;
};

FeatureSet_ptr SeedSearcherMain::FeatureSetManager::removeRedundancies (
	const FeatureSet& features, const CmdLineParameters& params)
{
	//
	// creates a new empty container with only the redundancy removing filters
	SeedSearcher::FeatureFilter_ptr bestFeatures = 
		createFilters (params, false);

	int maxElements = params.parser ().__seed_n;
	FeatureSet::CIterator feature_it = features.getIterator();
	for (; ((*bestFeatures)->size () < maxElements) && (feature_it.hasNext()) ; feature_it.next())
		bestFeatures->add(*feature_it );

	return bestFeatures->getArray();
}
