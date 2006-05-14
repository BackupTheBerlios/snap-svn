
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



using namespace boost::unit_test;


//
// Argv Unit test
//


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



/// this test also has the desired side-effect that DLOG is initialized
BOOST_AUTO_TEST_CASE ( test_DLOG )
{
	boost::shared_ptr<Langauge> lang (new ACGTLangauge ());
	SeedSearcherLog::setup (lang);
	SeedSearcherLog::setupConsoleLogging (false);
	BOOST_CHECK_NO_THROW (DLOG);
}

BOOST_AUTO_TEST_CASE ( test_Assignment_basic )
{
	Assignment assg;
	BOOST_REQUIRE (assg.length () == 0);

	ACGTLangauge lang;
	lang.stringToAssignment (assg, "ACGTacgt*nN?");
	BOOST_REQUIRE (assg.length () == 12);
	
	std::string buffer;
	{	
		Persistance::TextWriter writer (new Persistance::StrOutputStream (buffer));
		writer << Format (assg);
	}
	/// the 'N' is always written as '?' by the langauge
	BOOST_REQUIRE (buffer == "ACGTACGT*???");

	/// check strategies
	BOOST_CHECK (assg [0].strategy () == assg_discrete);
	BOOST_CHECK (assg [1].strategy () == assg_discrete);
	BOOST_CHECK (assg [2].strategy () == assg_discrete);
	BOOST_CHECK (assg [4].strategy () == assg_discrete);
	BOOST_CHECK (assg [5].strategy () == assg_discrete);
	BOOST_CHECK (assg [6].strategy () == assg_discrete);
	BOOST_CHECK (assg [7].strategy () == assg_discrete);
	BOOST_CHECK (assg [8].strategy () == assg_discrete);
	
	BOOST_CHECK (assg [9].strategy () == assg_together);	/// 'N' = '?' has together strategy
	BOOST_CHECK (assg [10].strategy () == assg_together);	/// 'N' = '?' has together strategy
	BOOST_CHECK (assg [11].strategy () == assg_together);	/// 'N' = '?' has together strategy

	BOOST_CHECK (assg [8].count () == 4);
	BOOST_CHECK (assg [9].count () == 4);
	BOOST_CHECK (assg [10].count () == 4);
	BOOST_CHECK (assg [11].count () == 4);

	/// check connection between alphabet and assignment
	buffer = "acgtACGT";
	for (std::string::size_type i= 0 ; i<buffer.length () ; ++i) {
		AlphabetCode::CodedChar c = lang.code ().code (buffer[i]);
		/// make sure each position has the appropriate character 
		/// and only that character
		BOOST_CHECK (assg [i].index (c));
		BOOST_CHECK (assg [i].count () == 1);
	}

	BOOST_CHECK (assg.equals (assg));
	BOOST_CHECK (assg.contains (assg));
	BOOST_CHECK (assg.compare (assg) == 0);
}

BOOST_AUTO_TEST_CASE ( test_Assignment_advanced )
{
	Assignment assg1;
	Assignment assg2;

	ACGTLangauge lang;
	lang.stringToAssignment (assg1, "ACGT");
	lang.stringToAssignment (assg2, "ACGTacgt");
	BOOST_CHECK (!assg1.equals (assg2));
	BOOST_CHECK_THROW (assg1.contains (assg2), BaseException);	/// cannot compare assignments of different length
	BOOST_CHECK (!assg2.equals (assg1));
	BOOST_CHECK_THROW (assg2.contains (assg1), BaseException); /// cannot compare assignments of different length
	
	BOOST_CHECK (assg1.contains (assg2, 0, 4));
	BOOST_CHECK (!assg1.contains (assg2, 1, 4));
	BOOST_CHECK (assg1.contains (assg2, 4, 4));


	
	assg1.addAssignmentAt (0, assg1);	/// now assg1 == ACGTACGT same as assg2
	BOOST_REQUIRE (assg1.length () == 8);
	BOOST_CHECK (assg1.equals (assg2));
	BOOST_CHECK (assg1.contains (assg2));

	assg1.erase (4); /// remove last 4 characters, now assg1 = ACGT
	BOOST_REQUIRE (assg1.length () == 4);

	assg1.addAssignmentAt (0, assg1);	/// now assg1 == ACGTACGT same as assg2
	BOOST_CHECK (assg1.equals (assg2));

	assg1.erase (3, 2); 	///       01234556
								/// erase ACGTACGT ==> ACCGT
								///         ---
	std::string buffer;
	{
		Persistance::TextWriter writer (new Persistance::StrOutputStream (buffer));
		writer << Format (assg1);
	}
	BOOST_CHECK (buffer == "ACCGT");
}





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

#include <stdio.h>
#include <fstream>



class TmpFile
{
public:
	static void write (const char* tmpFilePrefix, const char* data, std::string& outFilename)
	{
		outFilename = tempnam (NULL, tmpFilePrefix);
		{
			std::ofstream writer (outFilename.c_str ());
			writer << data;
		}
	}
	///
	/// writes data to temporary file and opens the file
	static std::auto_ptr<std::ifstream> writeAndOpen (const char* tmpFilePrefix, const char* data)
	{
		std::string filename;
		write (tmpFilePrefix, data, filename);
		return new std::ifstream (filename.c_str ());
	}
};

BOOST_AUTO_UNIT_TEST(test_WeightDB_repetitive_sequence_name)
{
	/// write a simple weight file
	std::string wgtTmpFilename;
	TmpFile::write (
		"wgt",
		">Positive1	1\n"
		">Positive2	1\n"
		">Positive1	1\n",
		wgtTmpFilename
		);

	/// read the weight file
	AutoPtr <SeqWeightDB::Name2Weight> weights;
	BOOST_CHECK_THROW (weights = SeqWeightDB::readWgtFile (wgtTmpFilename.c_str ()), BaseException);
}

BOOST_AUTO_UNIT_TEST(test_SequenceDB_repetitive_sequence_name)
{
	/// write a simple weight file
	std::string wgtTmpFilename;
	TmpFile::write (
		"wgt",
		">Positive1	1\n"
		">Positive2	1\n",
		wgtTmpFilename
		);

	/// read the weight file
	AutoPtr <SeqWeightDB::Name2Weight> weights = SeqWeightDB::readWgtFile (wgtTmpFilename.c_str ());

	/// write a simple seq file with a repetitive sequence
	std::string seqTmpFilename;
	TmpFile::write (
		"seq",
		">Positive1\n"
		"CCC\n"
		">Positive2\n"
		"TTTT\n"
		">Positive1\n"
		"AAA\n",
		seqTmpFilename
		);

	/// load the sequences, this must throw an exception since
	/// the sequence file is invalid
	ACGTLangauge langauge;
	AutoPtr <SequenceDB> db;
	BOOST_REQUIRE_THROW (
		db = SequenceDB::TextFileStorage::loadFastaAndWeights (
			langauge, 
			seqTmpFilename.c_str (), 
			*weights),
		BaseException
		);
}



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
		"AAAAAAAAAAAAAAACCCCCCACGTCCCCCCCCGGGGGGGGGGGGGGTTTTTTTTTTTTT\n"
		">Positive2\n"
		"ACGTTTTTTTTTTTTTTTTTTTTTTCCCCCCCCCCCC\n"
		">Positive3\n"
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
	BOOST_CHECK_CLOSE (acgt->score ()->log10Score (), double (-1.7), 1);
}



#include <boost/test/included/unit_test_framework.hpp>