//
// File        : $RCSfile: $ 
//               $Workfile: SequenceDB.cpp $
// Version     : $Revision: 25 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $ 
// Description :
//    unit-tests for the SequenceDB class
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
#include "SequenceDB.h"
#include "StdOptions.h"


#include <boost/test/auto_unit_test.hpp>

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
