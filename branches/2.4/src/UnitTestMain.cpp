#include "SeqWeight.h"

#define BOOST_AUTO_TEST_MAIN

#include <boost/test/unit_test_suite.hpp>
#include <boost/test/auto_unit_test.hpp>
using namespace boost::unit_test;


//
// Argv Unit test
//
#include "core/Argv.h"

// most frequently you implement test cases as a free functions
BOOST_AUTO_UNIT_TEST(test_Argv)
{
   StrBuffer options ("Option1", " Option2=Value2\t", "Option3\r\n");
   Argv argv[2];
   argv[0].set("MyApp", options);
   argv [1] = argv[0];
   for (int i=0 ; i<2 ; ++i) {
      BOOST_CHECK (argv[i].argc () == 4);
      BOOST_CHECK (Str (argv[i].argv ()[0]).equals ("MyApp"));
      BOOST_CHECK (Str (argv[i].argv ()[1]).equals ("Option1"));
      BOOST_CHECK (Str (argv[i].argv ()[2]).equals ("Option2=Value2"));
      BOOST_CHECK (Str (argv[i].argv ()[3]).equals ("Option3"));
   }
}

//
// SeqWeight test
// 
#include "SeqWeight.h"
BOOST_AUTO_UNIT_TEST(test_readPosWgtFile)
{
   std::istringstream stream (
      ">seq1 0.1 0.5 = [0,4]\t2.4 =[ 6, 7]\t0.2 = [9,11 ]\r\n"
      "> seq2   0.2 0.5   =[1,2]     0.67= [  3,3]\r\n"
   );

   AutoPtr <SeqWeightDB::Name2Weight> pWeights (
      SeqWeightDB::readWgtFile (stream)
   );
   SeqWeightDB::Name2Weight& weights = *pWeights;

   BOOST_CHECK (weights["seq1"] != NULL);
   BOOST_CHECK (weights["seq2"] != NULL);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (0), 0.1 * 0.5, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (4), 0.1 * 0.5, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (5), 0.1, 0.01);

   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (6), 0.1 * 2.4, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (7), 0.1 * 2.4, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (8), 0.1, 0.01);

   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (9), 0.1 * 0.2, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (11), 0.1 * 0.2, 0.01);
   BOOST_CHECK_CLOSE (weights["seq1"]->getPositionWeight (12), 0.1, 0.01);

   BOOST_CHECK_CLOSE (weights["seq2"]->getPositionWeight (0), 0.2, 0.01);
   BOOST_CHECK_CLOSE (weights["seq2"]->getPositionWeight (1), 0.2 * 0.5, 0.01);
   BOOST_CHECK_CLOSE (weights["seq2"]->getPositionWeight (2), 0.2 * 0.5, 0.01);
   BOOST_CHECK_CLOSE (weights["seq2"]->getPositionWeight (3), 0.2 * 0.67, 0.01);
   return;
}

#include "StdOptions.h"
#include "SeedSearcherMain.h"

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

			SeedSearcher::SearchParameters params;
			params.wf (wf);
			params.preprocessor (prep);
			params.score (scoreFunction);
			params.langauge(langauge);
			params.bestFeatures(filter);

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
				params.preprocessor ().add2Cluster ( motifNodes, 
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





