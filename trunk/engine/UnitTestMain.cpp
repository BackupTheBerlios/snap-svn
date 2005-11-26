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
   StrBuffer options ("Option1", "Option2=Value2\t", "Option3\r\n");
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
