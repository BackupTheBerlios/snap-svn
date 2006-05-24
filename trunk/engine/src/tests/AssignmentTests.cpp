//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.cpp $
// Version     : $Revision: 24 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:43 $ 
// Description :
//		Unit tests for the assignment classes.
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
	BOOST_CHECK (assg [9].count () == 5);	// when the strategy is assg_together, it is also allowed to look at positions where the sequence has 'N'
	BOOST_CHECK (assg [10].count () == 5);	// when the strategy is assg_together, it is also allowed to look at positions where the sequence has 'N'
	BOOST_CHECK (assg [11].count () == 5); // when the strategy is assg_together, it is also allowed to look at positions where the sequence has 'N'

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
	BOOST_CHECK (assg1.contains (assg2, 1, 3));
	BOOST_CHECK (!assg1.contains (SubAssignment (assg2, 1, 3), 0, 3));
	BOOST_CHECK (assg1.contains (SubAssignment (assg2, 0, 3), 0, 3));
	BOOST_CHECK (SubAssignment (assg1, 0, 3).contains (SubAssignment (assg2, 0, 3)));
	BOOST_CHECK (!SubAssignment (assg1, 1, 3).contains (SubAssignment (assg2, 0, 3)));
		
	assg1.addAssignmentAt (0, Assignment (assg1));	/// now assg1 == ACGTACGT same as assg2
	BOOST_REQUIRE (assg1.length () == 8);
	BOOST_CHECK (assg1.equals (assg2));
	BOOST_CHECK (assg1.contains (assg2));

	assg1.erase (4); /// remove last 4 characters, now assg1 = ACGT
	BOOST_REQUIRE (assg1.length () == 4);

	assg1.addAssignmentAt (0, Assignment (assg1));	/// now assg1 == ACGTACGT same as assg2
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