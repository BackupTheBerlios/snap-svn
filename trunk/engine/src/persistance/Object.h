#ifndef _Persistance_Object_h
#define _Persistance_Object_h

#include "Defs.h"

//
//
#define OBJECT_ID_IS_FIELD 0

namespace Persistance {;

//
// base class of all objects with persistance.
// just derive from this, implement the 'serialize' functions,
// and you're ready to go!
class Object   {
protected:
   Object();
   virtual ~Object();

public:  
   typedef unsigned long OID;

   static OID getSafeID(const Object *obj);
   virtual void serialize (IArchive& in);  
   virtual void serialize (OArchive& out); 


private:
#if OBJECT_ID_IS_FIELD
   OID _oid;
   static OID __oidCounter;
#endif
};

//
// see usage under 'STLPersist.h'
// base class of classes that persist other objects, rather than themselves - 
// for instance a framework for handling special types, like 'int64',
// 'long double', arrays of objects or STL.
struct Manipulator {
   virtual ~Manipulator () {
   }
   virtual void serialize (OArchive& out) {
      //
      // the default serialize function is meaningless
      debug_mustfail ();
   }
   virtual void serialize (IArchive& in) {
      //
      // the default serialize function is meaningless
      debug_mustfail ();
   }
};


}; // Persistance

#endif // _Persistance_Object_h

//
// File        : $RCSfile: $ 
//               $Workfile: Object.h $
// Version     : $Revision: 9 $ 
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

