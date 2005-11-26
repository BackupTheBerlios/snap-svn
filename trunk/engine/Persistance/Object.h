#ifndef _Persistance_Object_h
#define _Persistance_Object_h

#include "Defs.h"

//
//
#define OBJECT_ID_IS_FIELD 0

namespace Persistance {;

class Object   {
protected:
   Object();
   virtual ~Object();

public:  
   typedef unsigned long OID;

   static OID getSafeID(Object *obj);
   virtual void serialize (IArchive& in);  
   virtual void serialize (OArchive& out); 

private:
#if OBJECT_ID_IS_FIELD
   OID _oid;
   static OID __oidCounter;
#endif
};


}; // Persistance

#endif // _Persistance_Object_h