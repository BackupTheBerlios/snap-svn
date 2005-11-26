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
   IRegistry ();
   ~IRegistry ();
   
   void readObject (Object**, IArchive&);
   void link ();
   void clear ();

private:
   void readObjectLink (Object **, IArchive&);
   void readObjectInstance (Object *& obj , IArchive&);

   struct Rep;
   Rep* _rep;
};

};

#endif // _Persistance_IRegistry_h
