//
// File        : $RCSfile: $ 
//               $Workfile: SequenceDB.cpp $
// Version     : $Revision: 25 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $ 
// Description :
//    unit-tests for the SeqWeightDB class
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

#include "tests.h"
#include "SeqWeight.h"

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

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
