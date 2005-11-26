#include "Error.h"
#include "Core/Defs.h"

using namespace Persistance;

void Error::raise (const char* filename, int line, const char* error)
{
   ProgramException::raise (line, filename, error);
}

void Error::raise (int line, const char* error)
{
   ProgramException::raise (line, NULL, error);
}


//
// File        : $RCSfile: $ 
//               $Workfile: Error.cpp $
// Version     : $Revision: 6 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
// Description :
//	The Persistence library contains both high & low level IO classes
//	and is high-performance, highly reusable framework 
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

