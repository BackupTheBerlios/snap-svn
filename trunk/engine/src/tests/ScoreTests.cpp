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
#include "ExtraMath.h"


#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

BOOST_AUTO_UNIT_TEST(test_FDR_score)
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