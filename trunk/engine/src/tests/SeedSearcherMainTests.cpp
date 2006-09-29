//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.cpp $
// Version     : $Revision: 24 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:43 $ 
// Description :
//		Unit tests for the SeedSearcherMain class, check complete functionality of seedsearcher.
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

#include "Main.h"
#include "Parser.h"
#include "SeqWeight.h"
#include "StdOptions.h"
#include "SeqWeight.h"
#include "SeedSearcherMain.h"
#include "SeedConf.h"

#include <boost/filesystem/operations.hpp>
#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>


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
	BOOST_REQUIRE (params->db ()->size () == 8);
	/// check that the sequences have correct IDs and names
	for (int i=0 ; i<params->db ()->size () ; ++i) {
		char *names [] = { "Positive1", "Positive2", "Positive3", "Negative1", "Negative2", "Negative3", "Negative4", "Negative5" };
		BOOST_REQUIRE (params->db ()->sequences () [i]->name ().equals (names [i]));
		BOOST_REQUIRE (params->db ()->sequences () [i]->id () == i);
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
	cluster = acgt->cluster (true).getPositions (params->db ()->getSequence ("Positive1"));
	BOOST_REQUIRE (cluster);
	BOOST_REQUIRE (cluster->size() == 1);
	BOOST_CHECK (cluster->iterator ().get()->strand () == _strand_pos_);
	BOOST_CHECK (cluster->iterator ().get()->position () == 21);
	BOOST_CHECK (cluster->iterator ().get()->getData (0) == 'A');
	BOOST_CHECK (cluster->iterator ().get()->getSeedString (4, 0).equals ("ACGT"));

	cluster = acgt->cluster (true).getPositions (params->db ()->getSequence ("Positive2"));
	BOOST_REQUIRE (cluster);
	BOOST_REQUIRE (cluster->size() == 1);
	BOOST_CHECK (cluster->iterator ().get()->strand () == _strand_pos_);
	BOOST_CHECK (cluster->iterator ().get()->position () == 0);
	BOOST_CHECK (cluster->iterator ().get()->getData (0) == 'A');
	BOOST_CHECK (cluster->iterator ().get()->getSeedString (4, 0).equals ("ACGT"));

	cluster = acgt->cluster (true).getPositions (params->db ()->getSequence ("Positive3"));
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

extern int cpp_main(int argc, char* argv []);

BOOST_AUTO_UNIT_TEST(test_cpp_main)
{
	/// if the --no_long_tests is specified, then this test is skipped
	boost::unit_test::auto_unit_test_suite_t* master_test_suite = boost::unit_test::auto_unit_test_suite();
	for (int i=1 ; i<master_test_suite->argc ; ++i) {
		if (strcmp (master_test_suite->argv [i], "--no_long_tests") == 0) {
			BOOST_WARN_MESSAGE (false, "the test_cpp_main test is ignored");
			return;
		}
	}

	int argc = 6;
	char* argv [] = { "seed.test", "--Sconf", "tests/data/nimble.conf", "tests/data/test.seq", "tests/data/test.wgt", "tests/output/test_cpp_main" };
	cpp_main (argc, argv);
}

BOOST_AUTO_UNIT_TEST(test_exaustive_logging)
{
	/// if the --no_long_tests is specified, then this test is skipped
	boost::unit_test::auto_unit_test_suite_t* master_test_suite = boost::unit_test::auto_unit_test_suite();
	for (int i=1 ; i<master_test_suite->argc ; ++i) {
		if (strcmp (master_test_suite->argv [i], "--no_long_tests") == 0) {
			BOOST_WARN_MESSAGE (false, "the test_cpp_main test is ignored");
			return;
		}
	}

	int argc = 7;
	char* argv [] = { "seed.test", "--Sseedlog=on", "--Sconf", "tests/data/nimble.conf", "tests/data/test.seq", "tests/data/test.wgt", "tests/output/test_exaustive_logging" };
	cpp_main (argc, argv);

	/// check that every section in the conf file has a non-empty .exaustive file
	SeedConfList conf (argc, argv);
	SeedConf::read ("tests/data/nimble.conf", conf);



	StrBuffer base_name = conf.getInitParser ().__argv [conf.getInitParser ().__firstFileArg + main_definitions::StubFileIndex];
	for (SeedConfList::COptionIterator it = conf.const_iterator () ; it.hasNext () ; it.next ())
	{
		StrBuffer name = base_name; 
		name += (*it)->_name;
		name += ".exaustive";
		BOOST_REQUIRE (boost::filesystem::exists (boost::filesystem::path (name)));
		BOOST_REQUIRE (!boost::filesystem::_is_empty (boost::filesystem::path (name)));
	}
}
