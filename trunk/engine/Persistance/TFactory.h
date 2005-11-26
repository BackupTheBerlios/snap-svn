#ifndef _Persistance_TFactory_h
#define _Persistance_TFactory_h

#include "Defs.h"

BEGIN_NAMESPACE (Persistance);

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
   virtual const char* name ()const = 0;
   //
   // create a new object for this class
   virtual Object* create () const = 0;

   //
   // return the std c++ type-info class for the objects this factory makes
   virtual const std::type_info& type () const = 0;
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
   TFactory () {
   }
   TFactory (TFactoryList* list) {
      list->add (this);
   }
   virtual ~TFactory () {
   }

   virtual const char* name () const{
      return typeid (T).name ();
   }
   virtual const std::type_info& type () const {
      return typeid (T);
   }
   virtual Object* create () const{
      return createT ();
   }
   inline T* createT () const {
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

   typedef int FactoryID;

   bool add (TFactoryBase*);
   bool remove (const char*);

   TFactoryBase* getFactory (const std::type_info&) const;
   TFactoryBase* getFactory (FactoryID) const;
   Object* createObject (FactoryID) const;

   TFactoryBase* getFactory (const char*) const;
   Object* createObject (const char*) const;

   void serialize (IArchive&);
   void serialize (OArchive&);

private:
   class Rep;
   Rep* _rep;
};



END_NAMESPACE (Persistance);

#endif // _Persistance_TFactory_h









