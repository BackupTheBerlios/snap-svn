#include "Alphabet.h"

#include <memory>

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
}

AlphabetCode::AlphabetCode (const AlphabetCode& inCode)
: _cardinality (inCode._cardinality)
{
   copy (_code, inCode._code);
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













