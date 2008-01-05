#ifndef _SeedSearcher_Alphabet_h
#define _SeedSearcher_Alphabet_h

//
// File        : $RCSfile: $ 
//               $Workfile: Alphabet.h $
// Version     : $Revision: 16 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
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

#include "core/Defs.h"
#include "core/Str.h"

namespace seed {

//
// Codes each letter in an alphabet with a non-negative integer
class AlphabetCode   {
public:
   enum { SIZE = 256 };
   typedef char Char;
   typedef char CodedChar;
   typedef CodedChar Code [SIZE];
   typedef CodedChar const * const Code_ptr ;

   AlphabetCode (Code_ptr, int);
   AlphabetCode (const AlphabetCode&);
   AlphabetCode& operator = (const AlphabetCode&);

   static const Code_ptr emptyCode ();
   static void copy (Code&, Code_ptr inCode);

   enum {
      // code for characters that are not in the code
      notInCode = -1,
      //
      // code for the character that means, 'gee i dunno what's there, really...'
      dunnoCode = -2,
   };

   inline int cardinality () const {
      return _cardinality;
   }

   inline CodedChar code (Char c) const {
     //
     // keep gcc happy
     int index = static_cast <int> (c);
      int result = _code [index];
      debug_mustbe ( (result == notInCode)  || 
                     (result == dunnoCode)  ||
                     ((result>=0) && (result <= _cardinality)));
      return result;
   }

   Code_ptr getCode () const {
      return _code;
   }

   //
   // returns a buffer of the characters used in this alphabet
   const StrBuffer& characters () const {
      return _characters;
   }

   class UnknownCodeError : public BaseException {
   public:
      UnknownCodeError (Char c) : _c (c) {
      }
      virtual void explain (std::ostream& o) {
         o << "Unknown code: '"<< _c << "'";
      }
   private:
      Char _c;
   };

private:
   Code _code;
   int _cardinality;
   StrBuffer _characters;
};

}

#endif














