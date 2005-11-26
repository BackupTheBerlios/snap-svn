#include "SeedHash.h"
#include "AssignmentFormat.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StrOutputStream.h"

using namespace Persistance;


//
// AssgKey
SeedHash::AssgKey::AssgKey (const Str& data,  
                            const Langauge& langauge)
: _assg (data, langauge.code ())
{
   std::string hashString;
   {  Persistance::TextWriter textWriter (
         new Persistance::StrOutputStream (hashString));

      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction (hashString.c_str (), hashString.length ());
}

SeedHash::AssgKey::AssgKey (const Assignment& assg, 
                            const Langauge& langauge)
: _assg (assg)
{
   std::string hashString;
   {  Persistance::TextWriter textWriter (
         new Persistance::StrOutputStream (hashString));

      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction (hashString.c_str (), hashString.length ());
}






