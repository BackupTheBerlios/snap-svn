#include <boost/test/auto_unit_test.hpp>
#include "core/Str.h"
#include "core/Argv.h"

static char charFor(int i) {
	return 'a' + i % 26;
}

BOOST_AUTO_UNIT_TEST (testStr)
{
	StrBuffer a("123"), b;
	a+="456";
	mustbe(!(a!=Str("123456")));
	b= a;
	mustbe(a.equals(b));
	a+=b;
	mustbe(a.compare(b) > 0);
	mustbe((b.length() * 2)==a.length());
	mustbe(a.lastIndexOf(b)==b.length());
	a= 0;
	mustbe(a.empty());
	int i;
	for(i= 0; i < 1025; i++)
		a.append(charFor(i));
	for(i= 0; i < 1025; i++)
		mustbe(a[i]==charFor(i));
	Str test1(a.getCString(), 1025 - 25, 1025);
	for(i= 0; i < test1.length(); i++)
		mustbe(test1[i]==charFor(i + 1025 - 25));
	Str c1("11"), c2("2222222222222222222"), c3("3"), c4("44");
	StrBuffer atOnce(c1, c2, c3, c4);
	StrBuffer oneByOne;
	(oneByOne+=c1)+=c2;
	oneByOne.append(StrBuffer(c3, c4));
	mustbe(oneByOne==atOnce);
	mustbe(oneByOne.indexOf(atOnce)==0);
}

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

//
// File        : $RCSfile: $ 
//               $Workfile: Str.cpp $
// Version     : $Revision: 8 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:14 $ 
// Description :
// Contains unit tests for the core library
//	The Core library contains basic definitions and classes
// which are useful to any highly-portable applications
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
//