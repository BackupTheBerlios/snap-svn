#ifndef _Persistance_ORegistry_h
#define _Persistance_ORegistry_h

#include "Defs.h"
#include "Object.h"

#include <vector>

namespace Persistance {

class  ORegistry   {
public:
   ORegistry ();
   ~ORegistry ();

   void registerObject (Object*, OArchive& out);  
   void clear();

private:
   typedef std::vector <Object::OID> OIDVector;
   OIDVector _idvector;
};

}; // namespace persistance

#endif // _Persistance_ORegistry_h