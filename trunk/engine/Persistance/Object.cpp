#include "Object.h"

using namespace Persistance;

#if OBJECT_ID_IS_FIELD
   Object::OID Object::counter = 1; 
#endif


/************************************************************************************/
/******						         Object		   			                  *******/

//Default constructor
Object::Object() 
{
#if OBJECT_ID_IS_FIELD
   id = counter++;
#endif
}


Object::~Object()
{
}

/*
Object::OID Persistance::getID(Object *obj)
{

}

Object::OID Persistance::getID(Object& obj)
{
   return getID (&obj);
}
*/

Object::OID Object::getSafeID(const Object *obj)
{
   #if OBJECT_ID_IS_FIELD
      return obj? obj->id : 0;
   #else
	   return reinterpret_cast<Object::OID> (obj);
   #endif
}


//Ancestor of all Serialize functions. stores the UID in the archive.
void Object::serialize( OArchive& cia)
{
}


//Ancestor of all Serialize functions. restores the UID from the archive.
void Object::serialize( IArchive& cia)
{
}










