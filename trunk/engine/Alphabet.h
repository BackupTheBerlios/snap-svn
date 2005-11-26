#ifndef _SeedSearcher_Alphabet_h
#define _SeedSearcher_Alphabet_h

#include "Core/Defs.h"

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
      int result = _code [c];
      debug_mustbe ( (result == notInCode)  || 
                     (result == dunnoCode)  ||
                     ((result>=0) && (result <= _cardinality)));
      return result;
   }

   class UnknownCodeError : public BaseException {
   public:
      UnknownCodeError (Char c) : _c (c) {
      }
      ~UnknownCodeError () {
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
};

#endif


