#include "HashTable.h"

#if 0 
HashValue defaultHashFunction(const char* inStr, size_t inSize) {
	HashValue result= L_PI;
	for(const char* end= inStr+inSize; inStr < end; inStr++)
		result^=(*inStr * ALEX_CONST);
	return result;
}
#endif 

static const unsigned long ALEX_CONST = 0xF8429A19;
static const unsigned long L_PHI = 6180339;
static const unsigned long L_PI = 31415923;


HashValue defaultHashFunction(const char* inStr, size_t inSize) 
{
	HashValue result= L_PI;
	for(size_t i=0 ; i < inSize ; i++)
		result^=(inStr [i] * ALEX_CONST + i * L_PHI);
	return result;
}



//
// File        : $RCSfile: $ 
//               $Workfile: HashTable.cpp $
// Version     : $Revision: 6 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
// Description :
//	The Core library contains contains basic definitions and classes
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

