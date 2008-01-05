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
#include "Score.h"
#include "ScoreFunction.h"
#include "ExtraMath.h"


#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

using namespace seed;

BOOST_AUTO_TEST_CASE(test_FDR_score)
{
	/// create an exploss score
	Scores::TFPN tfpn (4, 3, 2, 1);
	boost::shared_ptr <Scores::ExplossWeights> weights (new Scores::ExplossWeights (log2 (2), log2 (2)));
	Scores::Score_ptr explossScore (new Scores::ExplossScore (weights, tfpn));

	/// check for correctness of exploss score
	double expectedExplossScore = 
		pow (2.0f, tfpn._FP) / pow (2.0f, tfpn._TP);

	BOOST_CHECK_CLOSE (log2(expectedExplossScore),  -2.0, 1);
	BOOST_CHECK_CLOSE (explossScore->log2Score (), log2 (expectedExplossScore), 1);
	

	/// 1) generate FDR corrected score for the exploss score
	/// 2) generate Bonferroni corrected score for the exploss score
	/// both should be the same, since FDR corrects for the first score the same as bonferroni
	Scores::FDRCorrectedPValue fdrScore1 (explossScore, 100, 1, NULL);
	BOOST_CHECK_CLOSE (fdrScore1.log2Score (), log2 (expectedExplossScore * 100), 1); 

	Scores::BonfCorrectedPvalue bonfScore1 (explossScore, 100);
	BOOST_CHECK_CLOSE (fdrScore1.log2Score (), bonfScore1.log2Score (), 1);
	
	/// again we make an FDR score, we give let it be the 2nd-best seed
	/// but we dont supply the 1st-best seed. so we expect scores to be calculated in the normal fasion
	Scores::FDRCorrectedPValue fdrScore2 (explossScore, 100, 2, NULL);
	BOOST_CHECK_CLOSE (fdrScore2.log2Score (), log2 (expectedExplossScore * 100 / 2), 1); 

	/// lastly, we make an FDR score, but this time we supply the 1st-best seed.
	/// since the 1st-best seed cant be any worse than the 2nd-best seed, even after
	/// the statistical fix, we should see that the 2nd-best score is in fact equal to
	/// the 1st-best seed instead of being better.
	Scores::FDRCorrectedPValue fdrScore3 (explossScore, 100, 2, &fdrScore1);
	BOOST_CHECK_CLOSE (fdrScore3.log2Score (), log2 (expectedExplossScore * 100), 1); 
}

#include "SeedSearcherMain.h"
#include "StdOptions.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/fstream.hpp>
#include <sstream>

class DNAParameterBuilder : public SeedSearcherMain::Parameters
{
public:
	DNAParameterBuilder ()
	{
		_langauge.reset (new ACGTLangauge);
	}

	/// first stage: setup the weights
	void setupWeights (const char* wgtString)
	{
		std::istringstream stream (wgtString);
		setupWeights (stream);
	}
	void setupWeights (const boost::filesystem::path& filename)
	{
		boost::filesystem::ifstream stream (filename);
		setupWeights (stream);
	}
	void setupWeights (std::istream& stream)
	{
		AutoPtr <SeqWeightDB::Name2Weight> weights = SeqWeightDB::readWgtFromStream (stream);
		_seqNameWeights.reset (weights.release ());
	}

	/// second stage: setup the sequence DB
	/// also sets up the SeqWeightFunction
	void setupSequences(const char* fastaString)
	{
		std::istringstream stream (fastaString);
		setupSequences (stream);
	}
	void setupSequences (const boost::filesystem::path& filename)
	{
		boost::filesystem::ifstream stream (filename);
		setupWeights (stream);
	}
	void setupSequences (std::istream& stream)
	{
		debug_mustbe (_langauge);
		debug_mustbe (_seqNameWeights);

		/// setup the database
		_db.reset (SequenceDB::TextFileStorage::loadFastaAndWeightsFromStream (
			*_langauge,
			stream,
			*_seqNameWeights));

		/// setup the mapping between sequence ID and weights
		_seqWeights.reset (SeqWeightDB::computeWeightIndex (*_seqNameWeights, *_db).release ());

		/// setup the sequence weight function
		_wf.reset (new SimpleWeightFunction (_seqWeights, 0.5));
	}
};

BOOST_AUTO_TEST_CASE(test_discrete_counts)
{
	DNAParameterBuilder parameters;
	
	parameters.setupWeights (
		">Pos1\t 1		\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos2\t 0.901 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos3\t 0.802 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos4\t 0.703 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos5\t 0.604 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos6\t 0.505 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg1\t 0.406 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg2\t 0.307 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg3\t 0.208 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg4\t 0.109 \t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg5\t 0.010 \t 0.7=[0, 2] 0.7=[4,7]\n"
		);

	parameters.setupSequences (
		">Pos1\n"
		"ACGTACGTA\n"
		">Pos2\n"
		"AGCGCGCGTTTTGTGTGT\n"
		">Pos3\n"
		"TTTCGCGCGAAAGCCT\n"
		">Pos4\n"
		"TACTACTACA\n"
		">Pos5\n"
		"TACTACTACA\n"
		">Pos6\n"
		"TACTACTACA\n"
		">Neg1\n"
		"AGCGCGCGTTTTGTGTGT\n"
		">Neg2\n"
		"TTTCGCGCGAAAGCCT\n"
		">Neg3\n"
		"TACTACTACA\n"
		">Neg4\n"
		"TACTACTACA\n"
		">Neg5\n"
		"TACGGGGTTTTTTTTTTTTTTTTTTTTTTTTTGGG\n"
		">Neg6\n"
		"TACGGACGCGCGCGCGCGCGCGCGCGCGGGTTTTTTTTTTTTTTTTTTTTTTTTTGGG\n"
		);

	boost::shared_ptr <const SequenceDB> db = parameters.db ();	
	BOOST_REQUIRE (db);
	BOOST_REQUIRE (db->size () == 11);

	boost::shared_ptr <const SeqWeightFunction> weightFunc = parameters.wf();
	BOOST_REQUIRE (weightFunc);

	{	/// test the discrete_weighter
		typedef Scores::detail::PositionWeighter <_position_weight_discrete_> discrete_weighter;
		for (int i=0 ; i<6 ; ++i) {
			double expectedWeight = 1;
			const Sequence& sequence = db->getSequence (i);
			double actualWeight = discrete_weighter::weigh (sequence, *weightFunc);
			BOOST_REQUIRE (actualWeight == expectedWeight);
		}

		for (int i=6 ; i<db->size () ; ++i) {
			double expectedWeight = 0;
			const Sequence& sequence = db->getSequence (i);
			double actualWeight = discrete_weighter::weigh (sequence, *weightFunc);
			BOOST_REQUIRE (actualWeight == expectedWeight);
		}
	}

	{	/// test the partial weighter
		typedef Scores::detail::PositionWeighter <_position_weight_real_> real_weighter;
		for (int i=0 ; i <db->size () ; ++i) {
			double expectedWeight = double(1) - (double (0.099) * i);
			const Sequence& sequence = db->getSequence (i);
			double actualWeight = real_weighter::weigh (sequence, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight, 1);
		}
	}

	{	/// test the hotspots weighter
		typedef Scores::detail::PositionWeighter <_position_weight_hotspots_> hotspot_weighter;
		for (int i=0 ; i <db->size () ; ++i) {
			const Sequence& sequence = db->getSequence (i);
			SeqPosition position3 (&sequence, 3);

			/// check with motif length=1
			double expectedWeight1 = double(1) - (double (0.099) * i);
			double actualWeight = hotspot_weighter:: weigh (position3, 1, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight1, 1);

			/// with motif length = 2 should be same result
			double expectedWeight2 = (expectedWeight1 + 0.7*expectedWeight1) /2;
			actualWeight = hotspot_weighter:: weigh (position3, 2, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight2, 1);

			/// with motif length = 3
			double expectedWeight3 = (expectedWeight1  + 2 * 0.7 * expectedWeight1)/3;
			actualWeight = hotspot_weighter:: weigh (position3, 3, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight3, 1);

			/// with motif length = 4
			double expectedWeight4 = (expectedWeight1  + 3 * 0.7 * expectedWeight1)/4;
			actualWeight = hotspot_weighter:: weigh (position3, 4, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight4, 1);

			/// with motif length = 5
			double expectedWeight5 = (expectedWeight1  + 4 * 0.7 * expectedWeight1)/5;
			actualWeight = hotspot_weighter:: weigh (position3, 5, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight5, 1);

			/// with motif length = 6
			double expectedWeight6 = (2 * expectedWeight1  + 4 * 0.7 * expectedWeight1)/6;
			actualWeight = hotspot_weighter:: weigh (position3, 6, *weightFunc);
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight6, 1);
		}
	}

	{	/// test the sigmoid weighter
		typedef Scores::detail::InverseSigmoidPositionWeighter sigmoid_weighter;
		for (int i=0 ; i <db->size () ; ++i) {
			double expectedWeight = double(1) - (double (0.099) * i);
			const Sequence& sequence = db->getSequence (i);
			double inverseSigmoidWeight = sigmoid_weighter::weigh (sequence, *weightFunc);
			double actualWeight = sigmoid_weighter::sigmoid (inverseSigmoidWeight);

			BOOST_REQUIRE_CLOSE (expectedWeight, actualWeight, 1);
		}
	}



}
