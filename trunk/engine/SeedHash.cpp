#include "SeedHash.h"
#include "AssignmentFormat.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StrOutputStream.h"

using namespace Persistance;


//
// AssgKey
SeedHash::AssgKey::AssgKey (const Str& data,  
                            const AlphabetCode& code, 
                            AssignmentWriter& writer)
: _assg (data, code)
{
   std::string hashString;
   {  Persistance::TextWriter textWriter (
         new Persistance::StrOutputStream (hashString));

      textWriter << AssignmentFormat (_assg, writer);
   }

   _hash = defaultHashFunction (hashString.c_str (), hashString.length ());
}

SeedHash::AssgKey::AssgKey (const Assignment& assg, 
                            AssignmentWriter& writer)
: _assg (assg)
{
   std::string hashString;
   {  Persistance::TextWriter textWriter (
         new Persistance::StrOutputStream (hashString));

      textWriter << AssignmentFormat (_assg, writer);
   }

   _hash = defaultHashFunction (hashString.c_str (), hashString.length ());
}

//
// Table

SeedHash::Table::Table (int tableSize, 
                        const AlphabetCode& code, 
                        AssignmentWriter& writer)
: TableBase (tableSize),
   _code (code), _assgWriter (writer)
{
}

SeedHash::Table::~Table ()
{
   //
   // TODO: we own the positions, so delete them
}

void SeedHash::Table::addPosition (const Str& seedData, AutoPtr <Position> position) {
   //
   //
   AssgKey key (seedData, _code, _assgWriter);
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