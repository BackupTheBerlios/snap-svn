#include "TFactory.h"
#include "Error.h"

#include "OArchive.h"
#include "IArchive.h"

#include "STLPersist.h"


#include <map>
#include <string>

using namespace Persistance;

// Defines a map of 'class name' to 'p_alloc_func' that allows
//true dynamic allocation, creating objects according to their names,
//unknown at design time.
struct TypeComparator {
   inline bool operator()(const std::type_info* x, const std::type_info* y) const {
      int result = x->before (*y);
      return result > 0;
   }
};

typedef std::map < const std::type_info*, TFactoryBase*, TypeComparator > Type2FactoryMap;
typedef std::map < std::string , TFactoryBase*  > Name2FactoryMap;
typedef std::map < TFactoryList::FactoryID , TFactoryBase*  > ID2FactoryMap;

class TFactoryList::Rep {
public:
   ~Rep () {
      Name2FactoryMap::iterator it = _names.begin ();
      for (; it!=_names.end () ; it++) {
         TFactoryBase* factory = it->second;
         delete factory;
      }
   }

   Type2FactoryMap _types;
   Name2FactoryMap _names;
   ID2FactoryMap _ids;
};

TFactoryList::TFactoryList () {
   _rep= new Rep ();
}

TFactoryList::~TFactoryList () {
   delete _rep;
   _rep = NULL;
}

bool TFactoryList::add (TFactoryBase* factory) 
{
   Name2FactoryMap::value_type  map_value( factory->name (), factory);      
   std::pair < Name2FactoryMap::iterator , bool > return_value;
   
   //Insert the pair, get the return value
   return_value = _rep->_names.insert( map_value );
   if (return_value.second) {
      const std::type_info& type = factory->type ();
      USELESS (bool ok = )
	_rep->_types.insert( 
         Type2FactoryMap::value_type ( &type, factory)).second;

      USELESS (debug_mustbe (ok));
   }

   //
   // return true if no factory for this class was registered
   return return_value.second;
}

TFactoryBase* TFactoryList::getFactory (const std::type_info& type) const
{
   Type2FactoryMap::iterator it;

   // find the function that allocates an object according to class_name
   it = _rep->_types.find(&type);
   if ( it != _rep->_types.end() )   {
      // get the pointer to the object allocating factory
      TFactoryBase* factory = it->second;
      return factory;
   }

   return NULL;
}

TFactoryBase* TFactoryList::getFactory (FactoryID id) const
{
   ID2FactoryMap::iterator it;

   // find the function that allocates an object according to class_name
   it = _rep->_ids.find(id);
   if ( it != _rep->_ids.end() )   {
      // get the pointer to the object allocating factory
      TFactoryBase* factory = it->second;
      return factory;
   }

   return NULL;
}

TFactoryBase* TFactoryList::getFactory (const char* class_name) const
{
   Name2FactoryMap::iterator it;

   // find the function that allocates an object according to class_name
   it = _rep->_names.find(class_name);
   if ( it != _rep->_names.end() )   {
      // get the pointer to the object allocating factory
      TFactoryBase* factory = it->second;
      return factory;
   }

   return NULL;
}


Object* TFactoryList::createObject (const char* class_name) const
{
   TFactoryBase* factory = getFactory (class_name);
   if (factory != NULL) {
      return factory->create ();
   }
   else {
      //the class name wasn't registered
      RaisePersistanceError2 (
         "The following class was not registered in the archive: %s", class_name);
      return NULL;
   }
}

Object* TFactoryList::createObject (FactoryID id) const
{
   TFactoryBase* factory = getFactory (id);
   if (factory != NULL) {
      return factory->create ();
   }
   else {
      //the class name wasn't registered
      RaisePersistanceError2 (
         "The following class id was not registered in the archive: %d", id);
      return NULL;
   }
}

void TFactoryList::serialize (OArchive& out)
{
   int size = _rep->_names.size ();
   out << size;
   Name2FactoryMap::iterator it = _rep->_names.begin ();
   Name2FactoryMap::iterator end = _rep->_names.end ();
   for (; it != end ; it++) {
      out << (FactoryID) it->second;
      out << it->first;
   }
}


void TFactoryList::serialize (IArchive& in)
{
   //
   // clear all previous id-->factory associations
   _rep->_ids.clear ();

   FactoryID id;
   int size;
   std::string class_name;
   
   in >> size;
   for (int i=0 ; i<size ; i++) {
      in >> id;
      in >> class_name;

      Name2FactoryMap::iterator it;
      //
      // find the function that allocates an object according to class_name
      it = _rep->_names.find(class_name.c_str ());
      if (it == _rep->_names.end()) {
         RaisePersistanceError2 (
            "The following class was not registered in the archive: %s", class_name.c_str ());
      }
      else {
         ID2FactoryMap::value_type  map_value( id, it->second);      
         std::pair < ID2FactoryMap::iterator , bool > return_value;
   
         //Insert the pair, get the return value
         return_value = _rep->_ids.insert( map_value );

         if (return_value.second == false) {
            RaisePersistanceError2 (
               "The following id was already registered in the archive: %d", id);
         }
      }
   }
}








