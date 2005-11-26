#include "ORegistry.h"
#include "OArchive.h"

#include <algorithm>

using namespace Persistance;

///
/// default constructor
///
ORegistry::ORegistry()
{
   _idvector.insert ( 0 ); // 0 is resereved for NULL
}



///
/// destructor
///
ORegistry::~ORegistry()
{
   _idvector.clear ();
}


///
/// this function is for reinitializing the registrator
///
void ORegistry::clear()
{
   _idvector.clear();
   _idvector.insert ( 0 ); // 0 is resereved for NULL
}


static void _registerObjectInstance (Object::OID id, 
                                     const Object* p_Obj, 
                                     OArchive& cia)
{
   // state that following is the object itself
   cia.prependPrefix ( preObjInstance);

   // Write the object's UID
	cia << id;

   // serialize the object
   cia << p_Obj;
}

//
// optimization: if it is certain that this is the first-time 
// registration of an object, this saves looking through the OID table
void ORegistry::registerObjectInstance (const Object* p_Obj, OArchive& cia)
{
   Object::OID id= Object::getSafeID ( p_Obj );

   // Register it 
   bool isNew = 
     _idvector.insert (id).second;

   debug_mustbe (isNew);
   _registerObjectInstance (id, p_Obj, cia);


}

//
// optimization: if it is certain that this object
// will be registered as an instance (or using the 'registerObject' method)
// it saves looking through the OID table
void ORegistry::registerObjectLink (const Object* p_Obj, OArchive& cia)
{
   Object::OID id= Object::getSafeID ( p_Obj );

   // state that this is only a reference
   cia.prependPrefix ( preObjLink);

	// Write the object's UID
	cia << id;
}


///
/// this function saves an object to an archive, either as a declaration or a reference.
/// as declaration - the first time the object's UID is encountered
/// as reference   - all following encounters. 
///  
void ORegistry::registerObject(const Object * p_Obj , OArchive& cia)
{
   //find out the obj's UID is registered in the vector
   Object::OID id = Object::getSafeID ( p_Obj );
   bool isNew = _idvector.insert (id).second;
   if (isNew) {
       //if the UID does not exist in the vector
      _registerObjectInstance (id, p_Obj, cia);
   }
   else { // it was already listed, store it as reference
      registerObjectLink (p_Obj, cia);
   }
}








