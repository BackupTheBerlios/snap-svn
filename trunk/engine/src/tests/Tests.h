#ifndef _SeedSearcher_Tests_Tests_h
#define _SeedSearcher_Tests_Tests_h

//
// File        : $RCSfile: $ 
//               $Workfile: Alphabet.h $
// Version     : $Revision: 16 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
// Description :
//		Contains useful functions and classes for seedsearcher's unit tests
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


#include "core/defs.h"
#include <stdio.h>
#include <fstream>
#include <string>

class TmpFile
{
public:
	static void write (const char* tmpFilePrefix, const char* data, std::string& outFilename)
	{
#if	ENV_COMPILER & ENV_MICROSOFT
#	define TEMPNAM _tempnam
#else
#	define TEMPNAM tempnam
#endif
		outFilename = TEMPNAM (NULL, tmpFilePrefix);
		{
			std::ofstream writer (outFilename.c_str ());
			writer << data;
		}
	}
	///
	/// writes data to temporary file and opens the file
	static std::auto_ptr<std::ifstream> writeAndOpen (const char* tmpFilePrefix, const char* data)
	{
		std::string filename;
		write (tmpFilePrefix, data, filename);
		return new std::ifstream (filename.c_str ());
	}
};

#endif