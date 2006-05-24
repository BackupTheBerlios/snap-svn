
#include "core/Argv.h"
#include "persistance/StrOutputStream.h"
#include "persistance/StdOutputStream.h"

#include "Parser.h"
#include "SeqWeight.h"
#include "StdOptions.h"
#include "SeqWeight.h"
#include "SeedSearcherMain.h"

#define BOOST_AUTO_TEST_MAIN

#include <boost/test/unit_test_suite.hpp>
#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "tests/Test.h"

using namespace boost::unit_test;













/// this test makes sure that after importing an empty string
/// the parser is able to generate a log line of the default values
/// which is again importable into another parser.
BOOST_AUTO_TEST_CASE( parser_basic_input_output)
{
	Str programPrefix ("test");
	Argv argv1 (programPrefix, "");;
	Parser parser1 (argv1);
	StrBuffer buffer1;
	{
		Persistance::TextWriter writer (new Persistance::TStrOutputStream <StrBuffer>(buffer1));
		parser1.logParams (writer);
	}

	Argv argv2 (programPrefix, buffer1);
	Parser parser2 (argv2);
	StrBuffer buffer2;
	{
		Persistance::TextWriter writer (new Persistance::TStrOutputStream <StrBuffer>(buffer2));
		parser2.logParams (writer);
	}

	BOOST_CHECK (buffer1 == buffer2);
	BOOST_CHECK_NO_THROW (parser1.checkCompatibility (parser2));
	BOOST_CHECK_NO_THROW (parser2.checkCompatibility (parser1));
}

//
// SeqWeight test
// 





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

#include <stdio.h>
#include <fstream>










BOOST_AUTO_UNIT_TEST(test_SeedSearcherMain)
{
	/// look for seeds with length=4 distance=0
	Argv argv ("test", "--Sseed-l 4 --Sproj-d 0 --Sscore-min -10");
	Parser parser (argv);
	
	/// 9 sequences, the positive sequences have the motif ACGT
	std::string seqTmpFilename;
	TmpFile::write (
		"seq",
		">Positive1\n"
//		 0         1         2----
//		 0123456789012345678901234
		"AAAAAAAAAAAAAAACCCCCCACGTCCCCCCCCGGGGGGGGGGGGGGTTTTTTTTTTTTT\n"
		">Positive2\n"
//		 ----			
//		 0123456789012345678901234
		"ACGTTTTTTTTTTTTTTTTTTTTTTCCCCCCCCCCCC\n"
		">Positive3\n"
//		           1         2         3         4         5    ---- 
//		 012345678901234567890123456789012345678901234567890123456789
		"AAAAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGCCCCCCCCCCCCCCCTTTTTTTACGT\n"
		">Negative1\n"
		"AAAACCCCGGGGGTTTTTTAAAAAAACCGGGT\n"
		">Negative2\n"
		"TTTTTTTTTTTTTTGGGGGGGGGGAAAAAAAAACCCCCCC\n"
		">Negative3\n"
		"TTTTTTTTTTNNNNNNNTTTTGGGGGCCCCCCCCCGGGGGAAAAAAAAACCCCCCC\n"
		">Negative4\n"
		"NAAAAAAAAGGGGGGCCCCCCCTTTTTTTTTTTTTTTTNNNNNNNTTTTGGGGGCCCCCCCCCGGGGGAAAAAAAAACCCCCCCN\n"
		">Negative5\n"
		"NAAAAAAAAGGGGGGCCACCTCCCCCTTTTTTTTACNGTTTTTTTTTNNNNNNNTTTTGGGGGCCCCCCCCCGGGGGAAAAAAAAACCCCCCCN\n"
		">Unused1\n"
		"ACGTACGTACGTACGT\n",
		seqTmpFilename
		);

	/// use 8 of the 9 sequences (the "Unused1" sequence is not used)
	/// notice the change of order: negative weights come before positive ones
	std::string wgtTmpFilename;
	TmpFile::write (
		"wgt",
		">Negative1	0\n"
		">Negative2	0.1\n"
		">Negative3	0.2\n"
		">Negative4	0.05\n"
		">Negative5	0.0\n"
		">Positive1 1\n"
		">Positive2 0.99\n"
		">Positive3 0.95\n",
		wgtTmpFilename
		);
	
	/// setup everything
	boost::shared_ptr <SeedSearcherMain::CmdLineParameters> params (
		new SeedSearcherMain::CmdLineParameters (parser));

	params->setup(Str (seqTmpFilename), Str (wgtTmpFilename));
	
	/// check that we have the 7 sequences
	BOOST_REQUIRE (params->db ().size () == 8);
	/// check that the sequences have correct IDs and names
	for (int i=0 ; i<params->db ().size () ; ++i) {
		char *names [] = { "Positive1", "Positive2", "Positive3", "Negative1", "Negative2", "Negative3", "Negative4", "Negative5" };
		BOOST_REQUIRE (params->db ().sequences () [i]->name ().equals (names [i]));
		BOOST_REQUIRE (params->db ().sequences () [i]->id () == i);
	}

	SeedSearcherMain appmain;
	AutoPtr<SeedSearcherMain::Results> results = appmain.search (params);
	BOOST_CHECK (results->numProjectionsSearched () == 1);

	/// check that ACGT is the best seed
	Assignment acgtAssg;
	params->langauge ().stringToAssignment (acgtAssg, "acgt");
	
	Feature_var acgt = results->getFeatures ()->bestFeature ();
	Assignment bestFeatureAssg = acgt->assignment ();
	BOOST_CHECK (bestFeatureAssg.equals (acgtAssg));

	/// check ACGT scoring, it should hit 3 positives only
	/// we are assuming gene counts, with integer hits
	Scores::TFPN tpfn (0, 0, 0, 0); 
	acgt->score ()->parameters (tpfn);
	BOOST_CHECK (tpfn._TP == 3);
	BOOST_CHECK (tpfn._FP == 0);
	BOOST_CHECK (tpfn._TN == 5);
	BOOST_CHECK (tpfn._FN == 0);

	/// check that the motif appears in the correct positions
	BOOST_REQUIRE (acgt->cluster ().size () == 3);

	const PosCluster* cluster = NULL;
	/// since we are using gene counts, the positions will not be available "out-of-the-box"
	/// we shall have to ask for them explicitly
	cluster = acgt->cluster (true).getPositions (params->db ().getSequence ("Positive1"));
	BOOST_REQUIRE (cluster);
	BOOST_REQUIRE (cluster->size() == 1);
	BOOST_CHECK (cluster->iterator ().get()->strand () == _strand_pos_);
	BOOST_CHECK (cluster->iterator ().get()->position () == 21);
	BOOST_CHECK (cluster->iterator ().get()->getData (0) == 'A');
	BOOST_CHECK (cluster->iterator ().get()->getSeedString (4, 0).equals ("ACGT"));

	cluster = acgt->cluster (true).getPositions (params->db ().getSequence ("Positive2"));
	BOOST_REQUIRE (cluster);
	BOOST_REQUIRE (cluster->size() == 1);
	BOOST_CHECK (cluster->iterator ().get()->strand () == _strand_pos_);
	BOOST_CHECK (cluster->iterator ().get()->position () == 0);
	BOOST_CHECK (cluster->iterator ().get()->getData (0) == 'A');
	BOOST_CHECK (cluster->iterator ().get()->getSeedString (4, 0).equals ("ACGT"));

	cluster = acgt->cluster (true).getPositions (params->db ().getSequence ("Positive3"));
	BOOST_REQUIRE (cluster);
	BOOST_REQUIRE (cluster->size() == 1);
	BOOST_CHECK (cluster->iterator ().get()->strand () == _strand_pos_);
	BOOST_CHECK (cluster->iterator ().get()->position () == 55);
	BOOST_CHECK (cluster->iterator ().get()->getData (0) == 'A');
	BOOST_CHECK (cluster->iterator ().get()->getSeedString (4, 0).equals ("ACGT"));
	
	/// look for the hypergeometric score
	Scores::HyperGeometricPvalue hypergeo (tpfn);
	Scores::Score_ptr score = acgt->score ();
	
	StrBuffer name1, name2;
	hypergeo.name (name1);
	score->name (name2); /// get current score name
	while (score && !name1.equals (name2)) {
		score = score->next ();
		score->name (name2); /// get current score name
	}

	BOOST_REQUIRE (score);
	BOOST_CHECK_CLOSE (score->log10Score (), double (-1.748), 1);
}


#ifdef _MSC_VER
#	pragma warning(disable : 4244)
#endif


#include <boost/test/included/unit_test_framework.hpp>

#ifdef _MSC_VER
#	pragma warning(default: 4244)
#endif
