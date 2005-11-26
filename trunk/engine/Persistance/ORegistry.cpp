#include "ORegistry.h"
#include "OArchive.h"

#include <algorithm>

using namespace Persistance;

///
/// default constructor
///
ORegistry::ORegistry()
{
   _idvector.push_back ( 0 ); // 0 is resereved for NULL
}



///
/// destructor
///
ORegistry::~ORegistry()
{
}


///
/// this function is for reinitializing the registrator
///
void ORegistry::clear()
{
   _idvector.clear();
   _idvector.push_back ( 0 ); // 0 is resereved for NULL
}


///
/// this function saves an object to an archive, either as a declaration or a reference.
/// as declaration - the first time the object's UID is encountered
/// as reference   - all following encounters. 
///  
void ORegistry::registerObject( Object * p_Obj , OArchive& cia)
{
   // Declare an iterator for the UID vector
   OIDVector::iterator it;

   //find out the obj's UID is registered in the vector
   Object::OID id= Object::getSafeID ( p_Obj );
   it = std::find( _idvector.begin() , _idvector.end() , id );
  
  //if the UID does not exist in the vector
   if ( it == _idvector.end() )
   {
      // Register it 
      _idvector.push_back ( id);

      // state that following is the object itself
      cia.prependPrefix ( preObjInstance);

	 // Write the object's UID
	   cia << id;

      // serialize the object
      cia << p_Obj;
   }
   else // it was already listed, store it as reference
   {
      // state that this is only a reference
      cia.prependPrefix ( preObjLink);

	// Write the object's UID
	   cia << id;
   }
}

