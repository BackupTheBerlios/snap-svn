#ifndef _Persistance_TFactory_h
#define _Persistance_TFactory_h

#include "Core/Defs.h"

namespace Persistance {

class Object;

class TFactoryBase {
   //
   // Base class for all object factory classes.
   // the idea is to have an abstract base class
   // to the templated concrete classes 'TFactory <> '
public:
   virtual ~TFactoryBase () {
   }

   //
   // return the name of the class of the objects this factory makes
   virtual const char* name ()=0;
   //
   // create a new object for this class
   virtual Object* create ()=0;
};

template <class T>
class TFactory : public TFactoryBase {
   //
   // Concrete factory for any type.
   // a default Ctor is necessary for this class to work.
   //
   // Optionally, one might want to create his own factory classes.
   // if this is the case, just derive from TFactoryBase and you're ready to go!
public:
   virtual ~TFactory () {
   }

   virtual const char* name () {
      return typeid (T).name ();
   }
   virtual Object* create () {
      return createT ();
   }
   inline T* createT () {
      return new T;
   }
};




class TFactoryList {
   //
   // a list of factories. required by archives, 
   // in order to recognized the classes used.
public:
   TFactoryList ();
   ~TFactoryList ();

   bool add (TFactoryBase*);
   bool remove (const char*);

   Object* createObject (const char*);

private:
   class Rep;
   Rep* rep;
};



}; // Persistance

#endif // _Persistance_TFactory_h

