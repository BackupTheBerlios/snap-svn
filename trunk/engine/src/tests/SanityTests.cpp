//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.cpp $
// Version     : $Revision: 24 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:43 $ 
// Description :
//		check inter-module sanity functionality of seedsearcher.
//
//		The Assignment classs is:
//    Concrete class describing an assignment - 
//       which is a sequence of assignment positions.
//    
//    an assignment position is a subset of the set of all possible
//    letters of a given alphabet.
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

#include "Tests.h"

#include "StdOptions.h"
#include "DebugLog.h"
#include "SeqWeight.h"
#include "SeedSearcherMain.h"


#include <boost/test/auto_unit_test.hpp>

BOOST_AUTO_UNIT_TEST(test_motifInSeqOuterPositions)
{
	std::istringstream wgt_stream (
		">seq1	0.9\r\n"
		">seq2	0.8\r\n"
	);

	std::istringstream seq_stream (
		">seq1	\r\n"
		"AAACGT\r\n"
		">seq2	\r\n"
		"TCGAAA\r\n"
	);

	//
	// create langauge
	boost::shared_ptr <Langauge> langauge (new ACGTLangauge);

	//
	// setup log
	SeedSearcherLog::setupConsoleLogging ( /* supress */ true);
	SeedSearcherLog::setup (langauge);

	//
	// create weights
	AutoPtr <SeqWeightDB::Name2Weight> pWeights (
		SeqWeightDB::readWgtFile (wgt_stream)
	);

	//
	// create DB
	boost::shared_ptr <SequenceDB> pDB (SequenceDB::TextFileStorage::loadFastaAndWeights(
		*langauge, seq_stream, *pWeights)
	);

	//
	// create SeqWeightFunction
	boost::shared_ptr <SeqWeightDB::ID2Weight> pID2Weights (
		SeqWeightDB::computeWeightIndex (*pWeights, *pDB).release()
	);
	
	boost::shared_ptr <SeqWeightFunction> wf ( 
		new SimpleWeightFunction(pID2Weights, 0.5)
	);

	// create hyper-geometric score factory
	boost::shared_ptr <Scores::Factory> factory (
		new Scores::HyperGeometricPvalueFactory
	); 

	// create score function
	boost::shared_ptr <Scores::Function> scoreFunction = Scores::makeFunction (
		_count_gene_, _position_weight_discrete_, pDB, wf, factory, 3
	);

	//
	// create the projection
	Assignment projection (langauge->wildcard(assg_discrete), 3);

	//
	// this assignment is the one we are looking for
	Assignment expectedResult ("AAA", langauge->code());

	PrepType prep_types [] = { _prep_leaf_, _prep_tree_ };
	for (int i=0 ; i< 2 ; ++i) {
		//
		// the PrefixTree doesn`t have an extended search
		// in which we search for motifs longer than the depth of the tree
		for (int depth = 2 + i; depth <=5 ; ++depth) {
			//
			// create preprocessor
			boost::shared_ptr <Preprocessor> prep (
				SeedSearcherMain::PreprocessorFactory::createPreprocessor (
					prep_types [i], *pDB, *wf, *langauge, depth, false
				)
			);

			//
			// build a feature set
			boost::shared_ptr <FeatureSet> features (new FeatureSet);
			SeedSearcher::FeatureFilter_ptr filter (
				new KBestFilter (1, 0, features)
			);

			boost::shared_ptr <SeedSearcher::SearchParameters> params (new SeedSearcher::SearchParameters);
			params->wf (wf);
			params->preprocessor (prep);
			params->score (scoreFunction);
			params->langauge(langauge);
			params->bestFeatures(filter);

			SeedSearcher::search ((SearchType) prep_types [i], params, projection);

			//
			// there should be only 1 seed with 2 appearances, and it is "AAA"
			DLOG << "Best assignment = "
					<< Format (features->bestFeature ()->assignment()) << DLOG.EOL ()
					<< "Expected assignment = "
					<< Format (expectedResult) << DLOG.EOL();
			DLOG.flush();
			
			Feature_var feature = features->bestFeature ();
			if (!feature->cluster ().hasPositions ()) {
				// add the motif positions if they are missing
				Preprocessor::NodeCluster motifNodes;
				params->preprocessor ().add2Cluster ( motifNodes, 
					feature->assignment ());

				motifNodes.add2SeqClusterPositions (feature->cluster ());
			}

			BOOST_CHECK (features->bestFeature ()->assignment().equals (expectedResult));
		
			PositionVector vec;
			feature->cluster().addPos2Vector (vec);
			BOOST_CHECK (vec.size () == 2);
		}
	}
}
