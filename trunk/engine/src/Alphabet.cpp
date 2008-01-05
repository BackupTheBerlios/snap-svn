//
// File        : $RCSfile: $ 
//               $Workfile: Alphabet.cpp $
// Version     : $Revision: 10 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
// Description :
//    Concrete class describing an alphabet - 
//       which is considered to be "small". 
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

#include "Alphabet.h"

#include <memory>

using namespace seed;

//
// this is a little leak, but it is constant
// and using auto_ptr is just too much hassle.
static char* _emptyCode;

void AlphabetCode::copy (Code& code, Code_ptr inCode) {
   for (int i=0 ; i<AlphabetCode::SIZE ; i++) {
      code [i]= inCode [i];
   }
}

AlphabetCode::AlphabetCode (Code_ptr inCode, int inCardinality)
: _cardinality (inCardinality)
{
   copy (_code, inCode);
   for (int i=0 ; i<SIZE ; i++) {
      if (_code [i] != notInCode)
         _characters.append (i);
   }
}

AlphabetCode::AlphabetCode (const AlphabetCode& inCode)
: _cardinality (inCode._cardinality)
{
   copy (_code, inCode._code);
   for (int i=0 ; i<SIZE ; i++) {
      if (_code [i] != notInCode)
         _characters.append (i);
   }
}

AlphabetCode& AlphabetCode::operator = (const AlphabetCode& inCode)
{
   _cardinality = inCode._cardinality;
   copy (_code, inCode._code);
   return *this;
}


const AlphabetCode::Code_ptr AlphabetCode::emptyCode ()
{
   if (!_emptyCode) {
      _emptyCode = new Code;
      for (int i=0 ; i<SIZE ; i++)
         _emptyCode [i] = notInCode;
   }

   return _emptyCode;

}














