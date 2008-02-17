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

BOOST_AUTO_TEST_CASE(test_weighters)
{
	DNAParameterBuilder parameters;
	
	parameters.setupWeights (
		">Pos1\t 1	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos2\t 0.901	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos3\t 0.802	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos4\t 0.703	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos5\t 0.604	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Pos6\t 0.505	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg1\t 0.406	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg2\t 0.307	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg3\t 0.208	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg4\t 0.109	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">Neg5\t 0.010	\t 0.7=[0, 2] 0.7=[4,7]\n"
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
			double actualWeight = discrete_weighter::weigh (sequence, *weightFunc).first;
			BOOST_REQUIRE (actualWeight == expectedWeight);
		}

		for (int i=6 ; i<db->size () ; ++i) {
			double expectedWeight = 0;
			const Sequence& sequence = db->getSequence (i);
			double actualWeight = discrete_weighter::weigh (sequence, *weightFunc).first;
			BOOST_REQUIRE (actualWeight == expectedWeight);
		}
	}

	{	/// test the partial weighter
		typedef Scores::detail::PositionWeighter <_position_weight_real_> real_weighter;
		for (int i=0 ; i <db->size () ; ++i) {
			double expectedWeight = double(1) - (double (0.099) * i);
			const Sequence& sequence = db->getSequence (i);
			double actualWeight = real_weighter::weigh (sequence, *weightFunc).first;
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
			double actualWeight = hotspot_weighter:: weigh (position3, 1, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight1, 1);

			/// with motif length = 2 should be same result
			double expectedWeight2 = (expectedWeight1 + 0.7*expectedWeight1) /2;
			actualWeight = hotspot_weighter:: weigh (position3, 2, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight2, 1);

			/// with motif length = 3
			double expectedWeight3 = (expectedWeight1  + 2 * 0.7 * expectedWeight1)/3;
			actualWeight = hotspot_weighter:: weigh (position3, 3, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight3, 1);

			/// with motif length = 4
			double expectedWeight4 = (expectedWeight1  + 3 * 0.7 * expectedWeight1)/4;
			actualWeight = hotspot_weighter:: weigh (position3, 4, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight4, 1);

			/// with motif length = 5
			double expectedWeight5 = (expectedWeight1  + 4 * 0.7 * expectedWeight1)/5;
			actualWeight = hotspot_weighter:: weigh (position3, 5, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight5, 1);

			/// with motif length = 6
			double expectedWeight6 = (2 * expectedWeight1  + 4 * 0.7 * expectedWeight1)/6;
			actualWeight = hotspot_weighter:: weigh (position3, 6, *weightFunc).first;
			BOOST_REQUIRE_CLOSE (actualWeight, expectedWeight6, 1);
		}
	}

	{	/// test the sigmoid weighter
		typedef Scores::detail::InverseSigmoidPositionWeighter sigmoid_weighter;
		for (int i=0 ; i <db->size () ; ++i) {
			double expectedWeight = double(1) - (double (0.099) * i);
			const Sequence& sequence = db->getSequence (i);
			double inverseSigmoidWeight = sigmoid_weighter::weigh (sequence, *weightFunc).first;
			double actualWeight = sigmoid_weighter::sigmoid (inverseSigmoidWeight);

			BOOST_REQUIRE_CLOSE (expectedWeight, actualWeight, 1);
		}
	}
}



BOOST_AUTO_TEST_CASE(test_counts)
{
	DNAParameterBuilder parameters;
	
	parameters.setupWeights (
		">PosACGG0\t 1		\t 0.7=[0, 2] 0.7=[4,7]\n"
		">PosACGG1\t 0.901	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">PosACGG2\t 0.802	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">PosACGG3\t 0.703	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">NegACGG4\t 0.406	\t 0.7=[0, 2] 0.7=[4,7]\n"
		">NegACGG5\t 0.307	\t 0.7=[0, 2] 0.7=[4,7]\n"
		);

	// number of occurances of acgt grows from sequence to sequence
	parameters.setupSequences (
		">PosACGG0\n"
			"aacgaattcgtatatatcgt\n"
		">PosACGG1\n"
			"aaACGGaa\n"
		">PosACGG2\n"
			"ACGGACGG\n"
		">PosACGG3\n"
			"tttACGGtACGGaaACGG\n"
	
		">NegACGG4\n"
			"aACGGcACGGgACGGtACGG\n"
		">NegACGG5\n"
			"aACGGccACGGgggACGGttttACGGaaaaaACGG\n"
		);

	boost::shared_ptr <const SequenceDB> db = parameters.db ();	
	BOOST_REQUIRE (db);
	BOOST_REQUIRE_EQUAL (6, db->size ());

	boost::shared_ptr <const SeqWeightFunction> weightFunc = parameters.wf();
	BOOST_REQUIRE (weightFunc);
	
	typedef Scores::detail::PositionCounter <_count_total_> total_counter_t;
	typedef Scores::detail::PositionCounter <_count_gene_> gene_counter_t;
	
	total_counter_t total_counter;
	gene_counter_t gene_counter;
		
	// create a preprocessor for the data
	boost::shared_ptr <seed::Preprocessor> prep;
	prep.reset ( 
		seed::SeedSearcherMain::PreprocessorFactory::createPreprocessor(
		_prep_leaf_,
		*db,
		*weightFunc,
		parameters.langauge(),
		/* feature length = */ 10,
		/* use reverse = */ false
		));
		
	// now search for ACGT
	seed::Preprocessor::NodeCluster node;
	seed::Assignment acgg("acgg", parameters.langauge().code());
	prep->add2Cluster(node, acgg);
	
	{	/// sanity check positions
		SequenceDB::Cluster allPositions;
		node.add2SeqClusterPositions(allPositions);
		
		/// all sequences, except the first which has no ACGG
		BOOST_CHECK_EQUAL(5, allPositions.size());
		BOOST_CHECK(NULL == allPositions.getPositions(0));
		for(int i=1 ; i<6 ; ++i) {
			PosCluster* posCluster = allPositions.getPositions(i);
			BOOST_REQUIRE(posCluster != NULL);
			for(PosCluster::Iterator it=posCluster->iterator() ; it.hasNext() ; it.next()) {
				std::string buffer;
				BOOST_CHECK_EQUAL("ACGG", (*it)->getSeedString(acgg.length()).getCString(buffer));
				
				/// the number of appearances of the AGCC motif equals the sequence id
				BOOST_CHECK_EQUAL(i, posCluster->size());
				
				/// there should be no overlaps
				BOOST_CHECK_EQUAL(posCluster->size(), posCluster->sizeNoOverlaps(acgg.length()));
			}
		}
	}
				
	boost::shared_ptr<const SeqWeightFunction> wf = parameters.wf ();
	
	{	/// test counts with the discrete_weighter
		typedef Scores::detail::PositionWeighter <_position_weight_discrete_> discrete_weighter_t;
		discrete_weighter_t discrete_weighter;
		
		for (int i=0 ; i<6 ; ++i) {
			// get the positions of acgt in this sequence
			PosCluster positions;
			node.add2PosCluster(positions, i);
			const Sequence& seq = db->getSequence(i);
			
			BOOST_REQUIRE_EQUAL(i, positions.size());
			
			{ /// check gene counts
				discrete_weighter_t::counter_pair discrete_gene_count = gene_counter.count(
					acgg.length(), 
					seq,
					&positions,
					*wf,
					discrete_weighter);
					
				/// with discrete gene counts counting positions in a sequence
				/// is either 1 or 0: depending on the weight of the sequence.
				/// positions are ignored
				BOOST_CHECK_EQUAL(
					1 * wf->isPositive(wf->weight(i)), 
					discrete_gene_count.first
					);
			}
			
			{ /// check total counts
				discrete_weighter_t::counter_pair discrete_total_count = total_counter.count(
					acgg.length(), 
					seq,
					&positions,
					*wf,
					discrete_weighter);
					
				/// with total counts, we count the number of appearances
				BOOST_CHECK_EQUAL(
					i * wf->isPositive(wf->weight(i)), 
					discrete_total_count.first
					);
			}
		}	
	}

}



BOOST_AUTO_TEST_CASE(test_scores)
{
	seed::Scores::TFPN tpfn_10_8_6_4 (
		/* TP = */ 10,
		/* TN = */ 8,
		/* FP = */ 6,
		/* FN = */ 4
	);
	
	seed::Scores::TFPN tpfn_3_11_7_19 (
		/* TP = */ 3,
		/* TN = */ 11,
		/* FP = */ 7,
		/* FN = */ 19
	);
	
	seed::Scores::TFPN tpfn_0_0_0_0 (
		/* TP = */ 0,
		/* TN = */ 0,
		/* FP = */ 0,
		/* FN = */ 0
	);
	
	seed::Scores::TFPN tpfn_1_1_1_1 (
		/* TP = */ 1,
		/* TN = */ 1,
		/* FP = */ 1,
		/* FN = */ 1
	);
	
	

	/// test exponential scores
	{
	
		boost::shared_ptr<seed::Scores::ExplossWeights> weights_4_2;
		weights_4_2.reset(
			new seed::Scores::ExplossWeights(
			/* positive weight = */ log2(4),
			/* negative weight = */ log2(2)
			)
		);
		
		BOOST_REQUIRE_EQUAL(log2(2), weights_4_2->log2HitNegativeWeight ());
		BOOST_REQUIRE_EQUAL(log2(4), weights_4_2->log2HitPositiveWeight ());	
			
		/// the smaller the score, the "better" it is, so the formula is: 
		/// 	exploss = pow (FP, beta) / pow(TP, alpha)
		{
			seed::Scores::ExplossScore score_10_8_6_4 (weights_4_2, tpfn_10_8_6_4);
			BOOST_CHECK_CLOSE(
				log2(pow (2,6) / pow (4, 10)),
				score_10_8_6_4.log2Score(),
				/* % difference = */ 0.01
			);
		}
			
		{
			seed::Scores::ExplossScore score_3_11_7_19 (weights_4_2, tpfn_3_11_7_19);
			BOOST_CHECK_CLOSE(
				log2(pow (2,7) / pow (4, 3)),
				score_3_11_7_19.log2Score(),
				/* % difference = */ 0.01
			);
		}
			
		{
			seed::Scores::ExplossScore score_0_0_0_0 (weights_4_2, tpfn_0_0_0_0);
			BOOST_CHECK_CLOSE(
				log2(pow (4, 0) / pow (2,0)),
				score_0_0_0_0.log2Score(),
				/* % difference = */ 0.01
				);
		}
			
		{
			seed::Scores::ExplossScore score_1_1_1_1 (weights_4_2, tpfn_1_1_1_1);
			BOOST_CHECK_CLOSE(
				log2(pow (2,1) / pow (4, 1)),
				score_1_1_1_1.log2Score(),
				/* % difference = */ 0.01
				);
		}
	}
		
}
	
	
