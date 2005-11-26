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

//
// Table

SeedHash::Table::Table (int tableSize, 
                        const Langauge& langauge)
: TableBase (tableSize), _langauge (langauge)
{
}

SeedHash::Table::~Table ()
{
   //
   // TODO: we own the positions, so delete them
}

void SeedHash::Table::addPosition (const Str& seedData, 
                                   AutoPtr <SeqPosition> position) {
   //
   //
   AssgKey key (seedData, _langauge);
   Cluster* seed = this->find (key);
   if (seed == NULL) {
      //
      // this is a new seed
      seed = createCluster (key);
      this->add (seed);
   }

   //
   // add this new position to the seed
   seed->addPosition (position.release ());
}


