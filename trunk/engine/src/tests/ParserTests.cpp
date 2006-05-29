//
// File        : $RCSfile: $ 
//               $Workfile: SequenceDB.cpp $
// Version     : $Revision: 25 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $ 
// Description :
//    unit-tests for the Parser class
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
#include "Parser.h"

#include "persistance/StrOutputStream.h"

#include <boost/test/auto_unit_test.hpp>


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