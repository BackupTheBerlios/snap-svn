#ifndef _Persistance_ORegistry_h
#define _Persistance_ORegistry_h

#include "Defs.h"
#include "Object.h"

#include <set>

namespace Persistance {

class  ORegistry   {
public:
   ORegistry ();
   ~ORegistry ();

   //
   // optimization: if it is certain that this is the first-time 
   // registration of an object, this saves looking through the OID table
   void registerObjectInstance (const Object*, OArchive& out);  

   //
   // optimization: if it is certain that this object
   // will be registered as an instance (or using the 'registerObject' method)
   // it saves looking through the OID table
   void registerObjectLink (const Object*, OArchive& out);  

   //
   // looks through the OID table for this object's ID.
   // if it is not there, it is a new object to be serialized.
   // otherwise, it has already been serialized and so is just
   // saved as a link
   void registerObject (const Object*, OArchive& out);  
   void clear();

private:
   typedef std::set <Object::OID> OIDVector;
   OIDVector _idvector;
};

}; // namespace persistance

#endif // _Persistance_ORegistry_h

//
// File        : $RCSfile: $ 
//               $Workfile: ORegistry.h $
// Version     : $Revision: 8 $ 
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

