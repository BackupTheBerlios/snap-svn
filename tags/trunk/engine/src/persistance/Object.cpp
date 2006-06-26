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

//
// File        : $RCSfile: $ 
//               $Workfile: Object.cpp $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
// Description :
//	The Persistence library contains both high & low level IO classes
//	and is high-performance, highly reusable framework 
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
//

