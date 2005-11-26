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
   char buffer [8096];
   Persistance::FixedBufferOutputStream output (buffer, sizeof (buffer));
   {  Persistance::TextWriter textWriter (&output, false);
      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction ( buffer, output.getSize ());
}

SeedHash::AssgKey::AssgKey (const Assignment& assg, 
                            const Langauge& langauge)
: _assg (assg)
{
   char buffer [8096];
   Persistance::FixedBufferOutputStream output (buffer, sizeof (buffer));
   {  Persistance::TextWriter textWriter (&output, false);

      textWriter << AssignmentFormat (_assg, langauge);
   }

   _hash = defaultHashFunction ( buffer, output.getSize ());
                               
}






