#include "TFactory.h"
#include "Error.h"

#include <map>
#include <string>

using namespace Persistance;

// Defines a map of 'class name' to 'p_alloc_func' that allows
//true dynamic allocation, creating objects according to their names,
//unknown at design time.
typedef std::map < std::string , TFactoryBase*  > FactoryMap;

class TFactoryList::Rep {
public:
   ~Rep () {
      FactoryMap::iterator it = _map.begin ();
      for (; it!=_map.end () ; it++) {
         TFactoryBase* factory = it->second;
         delete factory;
      }
   }
   
   FactoryMap _map;

};

TFactoryList::TFactoryList () {
   rep= new Rep ();
}

TFactoryList::~TFactoryList () {
   delete rep;
   rep = NULL;
}

bool TFactoryList::add (TFactoryBase* factory) 
{
   FactoryMap::value_type  map_value( factory->name (), factory);      
   std::pair < FactoryMap::iterator , bool > return_value;
   
   //Insert the pair, get the return value
   return_value = rep->_map.insert( map_value );

   //
   // return true if no factory for this class was registered
   return return_value.second;
}



Object* TFactoryList::createObject (const char* class_name) 
{
   TFactoryBase* factory = NULL;
   FactoryMap::iterator it;

   // find the function that allocates an object according to class_name
   it = rep->_map.find(class_name);
   if ( it != rep->_map.end() )   {
      // get the pointer to the object allocating factory
      TFactoryBase* factory = it->second;
   }

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

