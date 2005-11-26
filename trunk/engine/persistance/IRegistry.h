#ifndef _Persistance_IRegistry_h
#define _Persistance_IRegistry_h

namespace Persistance {

class Object;
class IArchive;

class IRegistry   {
   //
   // when an object is pointed to several types,
   // and the user is interested in maintaining the relationship with 
   // the object, but to write/read/create the object only once
   // a registry is needed.
   //
   // an object exists in an archive in one of two modes-
   // as an instance or as a link.
   // an instance is when the objects complete information 
   // is stored in the  current position in the archive.
   // a link is when only the object ID is stored in the 
   // current position in the archive.
   //
   // after reading the entire archive, all links are
   // are connected, e.g. all pointers to objects 
   // are initialized to point to the actual instance
   // create during the archive extraction process
public:
   class AbstractLink {
   public:
      virtual ~AbstractLink () {
      }
      virtual void update (Object*) = 0;
      virtual void dispose () {
         delete this;
      }
   };

   IRegistry ();
   ~IRegistry ();
   
   void readObject (AbstractLink*, IArchive&);
   void readObject (Object**, IArchive&);
   void link ();
   void clear ();

private:
   void readObjectLink (AbstractLink*, IArchive&);
   void readObjectInstance (AbstractLink* obj , IArchive&);

   struct Rep;
   Rep* _rep;
};

};

#endif // _Persistance_IRegistry_h

//
// File        : $RCSfile: $ 
//               $Workfile: IRegistry.h $
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

