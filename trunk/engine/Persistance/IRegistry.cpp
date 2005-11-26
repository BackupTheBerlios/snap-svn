#include "Defs.h"
#include "IArchive.h"
#include "IRegistry.h"
#include "Object.h"

#include "Error.h"

#include <map>
#include <vector>

using namespace Persistance;

class PointerLink : public IRegistry::AbstractLink {
public:
   PointerLink (Object** ppObj) : _ppObject (ppObj) {
   }
   virtual void update (Object* instance) {
      *_ppObject = instance;
   }

private:
   Object** _ppObject;
};


// Defines a map of 'Object::OID' to 'Object *' that allows
//to keep track of objects known to be 'alive' in one place.
typedef std::map <Object::OID, Object *> InstanceMap;


// Defines a pair of 'Object::OID' to 'Object *' 
typedef std::pair <Object::OID, IRegistry::AbstractLink*> Link;


// Defines a vector of 'Obj_Ref' that allows
//to keep track of pointers referencing other objects,
typedef std::vector <Link> LinkVector;

struct IRegistry::Rep {
   InstanceMap _instances;
   LinkVector _links;
};


///
/// default constructor
///
IRegistry::IRegistry()
{
   _rep = new Rep;

   //Initialize map with the declaration of a NULL object
   _rep->_instances[ 0 ] = NULL;
}



///
/// destructor
///
IRegistry::~IRegistry()
{
   // the second pass, in which object references are linked with their declarations
   link ();

   delete _rep;
}

///
/// this function is for reinitializing the registrator
///
void IRegistry::clear ()
{
//   m_Ref_Vec.clear();   //frees elements. does not affect objects pointed to
   _rep->_instances.clear();  //frees elements. does not affect objects pointed to

   _rep->_links.clear ();

   //Initialize map with the declaration of a NULL object
   _rep->_instances [0] = NULL;   


}



///
/// RegRead_Obj
///
void IRegistry::readObject (Object**  p_Obj, 
                            IArchive& cia)
{
   readObject (new PointerLink (p_Obj), cia);
}

void IRegistry::readObject (AbstractLink*  p_Obj, 
                            IArchive& cia)
{
   //Read prefix
   Prefix preExpected = cia.readPrefix();

   switch ( preExpected )  {
      case preObjLink:  {
         //Object was saved as link
         readObjectLink ( p_Obj , cia );
         break;
      }

      case preObjInstance: {
         //Object was saved as instance
         readObjectInstance ( p_Obj, cia );
         break;
      }

      default:      {
         p_Obj->dispose ();
         //
         //throw exception
         RaisePersistanceError3 (
            "Expecting prefix no. %d, %d found", preObjLink, preExpected);
      }
   }
}




void IRegistry::readObjectLink (AbstractLink* pp_Obj ,IArchive& cia)
{
   Object::OID id;

   //
   //Read UID from Archive
   cia >> id;

   //Define Iterator for the Obj Declarations map.
   InstanceMap::iterator instIt;

  //Try to find it's declaration in the Decl_Map
  instIt = _rep->_instances.find(id);

  //If it does not exist
  if (instIt == _rep->_instances.end() )     {
      //Store it in 'm_Ref_Vec'
      _rep->_links.push_back (Link (id, pp_Obj));
  }
  else     {
     //initialize it to point at the declaration
     pp_Obj->update (instIt -> second);
     pp_Obj->dispose ();
  }
}





///
///
///
void IRegistry::readObjectInstance (AbstractLink* link, 
                                    IArchive& cia)
{
	Object::OID id;
	
	//
	// read the id of the object
	cia >> id;

   //Deserialize Object
   Object* obj;
   cia.readObject ( obj );
   link->update (obj);
   link->dispose ();

   //Create a pair of UID to Object pointer.
   InstanceMap::value_type  map_value( id, obj );      

   //Create a pair that matches map::insert return type
   std::pair <InstanceMap::iterator, bool> return_value;

   //Insert the pair, get the return value
   return_value = _rep->_instances.insert( map_value );

   //check if UID already existed in the map
   if ( return_value.second == false)  {
      //a declaration for this UID already is registered, throw exception
      RaisePersistanceError2 (
         "Error. UID no. %ld already has a registered instance", id);     
   }

   //
   //Object successfully registered in Decl_Map
}





///
///
///
void IRegistry::link ()
{
   //Define Iterator for the Obj References vector, and initialize.
   LinkVector::iterator linkIt = _rep->_links.begin() ;

   //Define Iterator for the Obj Declarations map.
   InstanceMap::iterator instIt;

   //For each obj reference in the map 
   for ( ; linkIt != _rep->_links.end() ; linkIt++)
   {
      
      //Try to find it's declaration in the Decl_Map
      instIt = _rep->_instances.find( linkIt ->first );
   
      //If it does not exist
      if ( instIt == _rep->_instances.end() )   {
         //throw excpetion
         RaisePersistanceError2 (
            "Cannot find an object declaration with UID %ld", linkIt->first);
      }
      else  {
         //Get the pointer to the refernce
         AbstractLink* link = linkIt->second;

         //initialize it to point at the declaration
         link->update (instIt -> second);
         link->dispose ();
      }
   }
   
   // All references successfuly linked, Clear lists
   clear();
}








