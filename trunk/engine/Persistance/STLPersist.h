#include "Core/Defs.h"
#include <map>

//
// the classes in this file are intended to facilitate the persistance
// of STL containers - their data.


BEGIN_NAMESPACE (Persistance);

//
// persistance for STL string
inline static OArchive& operator << (OArchive& out, const std::string& str)
{
   out.writeString (str.c_str (), str.length ());
   return out;
}

//
// persistance for STL string
inline static IArchive& operator >> (IArchive& in, std::string& str)
{
   int len;
   {
      char buffer [1024 * 16];
      in.readStringBuffer (buffer, sizeof (buffer), &len);
      debug_mustbe (buffer [len] == 0);
      str.assign (buffer, len);
   }

   return in;
}




//
//
// classes for OUTPUTING STL containers and types
//
//




//
// simply outputs the value received in the ctor
template <class T>
struct OT : public Manipulator {
   //
   //
   typedef T TType;

   //
   //
   inline OT (const T& in) : _in (in) {
   }
   inline void serialize (Persistance::OArchive& out) {
      out << _in;
   }

   const TType& _in;
};

struct OInstance : public Manipulator {
   //
   //
   typedef Object* TType;

   //
   //
   inline OInstance (const Object* in) : _in (in) {
   }
   inline void serialize (Persistance::OArchive& out) {
      out.registerObject (_in, true);
   }

   const Object* _in;
};



struct OLink : public Manipulator {
   //
   //
   typedef Object* TType;

   //
   //
   inline OLink (const Object* in) : _in (in) {
   }
   inline void serialize (Persistance::OArchive& out) {
      out.registerObject (_in, false);
   }

   const Object* _in;
};



//
// persistance for STL pairs, the default action is to 
// output the first value, then the second
// may be augmented using other template parameters instead of the default ones
template <  class Pair,
            class Action1 = OT <TYPENAME Pair::first_type>,
            class Action2 = OT <TYPENAME Pair::second_type>
         >
struct OPair : public Manipulator {
   //
   //
   typedef Pair TType;
   typedef Action1 Action1Type;
   typedef Action2 Action2Type;

   //
   //
   inline OPair (const TType& in) : _in (in) {
   }
   inline void serialize (Persistance::OArchive& out) {
      out << Action1Type (_in.first) << Action2Type (_in.second);
   }

   const TType& _in;
};





//
// used for maps, keystroke saver. does the same thing as OPair,
// but saves typing because it uses the types of a map.
template <  class Map,             
            class Action1 = OPair <TYPENAME Map::value_type>::Action1Type,
            class Action2 = OPair <TYPENAME Map::value_type>::Action2Type
         >
struct OMapPair : public OPair <TYPENAME Map::value_type, Action1, Action2> {
   //
   //
   typedef Action1 Action1Type;
   typedef Action2 Action2Type;
   typedef typename Map::value_type TType;
   typedef OPair <TType, Action1Type, Action2Type> SuperType;

   //
   //
   inline OMapPair (const TType& in) : SuperType (in) {
   }
};



//
// used to persist (write) an STL template (but probably not a map)
// by going over ALL elements, performing 'Action' on them 
// (default = just write the elements using '<<')
template <  class Container, 
            class Action = OT <TYPENAME Container::value_type>
         >
class OSTL : public Manipulator {
public:
   //
   //
   typedef Container ContainerType;
   typedef typename Container::value_type TType;
   typedef typename Container::const_iterator IteratorType;

   //
   //
   OSTL (const ContainerType& in) : _container (in) {
   }
   void serialize (Persistance::OArchive& out) {
      out << (int) _container.size ();
      IteratorType it = _container.begin ();
      IteratorType end = _container.end ();
      for (; it != end ; it++) {
         out << Action (*it);
      }
   }

private:
   const ContainerType& _container;
};


//
// used to persist (write) an STL map, keystroke saver.
// by going over ALL elements, performing 'Action' on them 
// (default = just write the elements using '<<')
template <  class Container,
            class Action1 = OMapPair <Container>::Action1Type,
            class Action2 = OMapPair <Container>::Action2Type
         >
class OMap : public OSTL < Container, OMapPair <Container> > {
public:
   typedef Container ContainerType;
   typedef OSTL <Container, OMapPair <Container> > SuperType;
   typedef Action1 Action1Type;
   typedef Action2 Action2Type;

   OMap (const ContainerType& in) : SuperType (in) {
   }
};

//
// registers all the objects in a container
template <class Container>
struct OSTLReg : public Manipulator {
   //
   //
   typedef Container ContainerType;
   typedef typename Container::const_iterator IteratorType;
   typedef typename Container::value_type TType; 

   //
   //
   OSTLReg (Container& cont) : _container (cont), _knownType (false) {
   }
   OSTLReg (Container& cont, bool isInstance) 
   : _container (cont), _knownType (true), _type (isInstance) {
   }
   void serialize (OArchive& out) {
      out << (int) _container.size ();
      IteratorType it = _container.begin ();
      IteratorType end = _container.end ();
      if (!_knownType) {
         for (; it != end ; it++) {
            out.registerObject (*it);
         }
      }
      else {
         for (; it != end ; it++) {
            out.registerObject (*it, _type);
         }
      }
   }

   bool _knownType;
   bool _type;
   Container& _container;
};







//
//
// classes for INPUTING STL containers and types
//
//


//
// just uses '>>' to read from the archive
template <class T>
struct IT : public Manipulator {
   //
   //
   typedef T TType;

   //
   //
   inline IT (TType& t) : _t (t) {
   }
   inline void serialize (Persistance::IArchive& in) {
      in >> _t;
   }

   TType& _t;
};


//
// persistance for STL pairs
// reads it using 'Action1' 'Action2' which default to '>>'
template <  class Pair,
            class Action1 = IT <TYPENAME Pair::first_type>,
            class Action2 = IT <TYPENAME Pair::second_type>
         >
struct IPair : public Manipulator {
   //
   //
   typedef Pair TType;
   typedef typename Pair::first_type TType1;
   typedef typename Pair::second_type TType2;
   typedef Action1 Action1Type;
   typedef Action2 Action2Type;

   //
   //
   inline IPair (TType& p) : _p (p) {
   }
   inline void serialize (Persistance::IArchive& in) {
      in >> Action1 (_p.first) >> Action2 (_p.second);
   }

   TType& _p;
};



//
// persistance for STL map pairs.
// this is needed because we cannot use the map's 'value_type' type
// 'Map::value_type::first_type' always has const...
template <  class Map,             
            class Action1 = IT <TYPENAME Map::key_type>,
            class Action2 = IT <TYPENAME Map::value_type::second_type>
         >
struct IMapPair : public Manipulator {
   //
   // 
   typedef typename Map::value_type TType;
   typedef typename Map::key_type TType1;
   typedef typename Map::value_type::second_type TType2;
   typedef Action1 Action1Type;
   typedef Action2 Action2Type;

   //
   //
   inline IMapPair (TType& p) : _p (p) {
   }
   inline void serialize (Persistance::IArchive& in) {
     //
     // must separate action from deserialization because of stupid gcc 
     // compilation errors...
     Action1 t1 (const_cast <TType1&> (_p.first));
     Action2 t2 (_p.second);
     
     in >> t1 >> t2; 
   }

   TType& _p;
};


//
// used to persist (read) an STL template (but probably not a map)
// by going over ALL elements, performing 'Action' on them 
// (default = just write the elements using '<<')
template <  class Container, 
            class Action = IT <TYPENAME Container::value_type>
         >
class ISTL : public Manipulator {
   //
   // NOTE: this doesnt work with object registration!
public:
   //
   //
   typedef typename Container ContainerType;
   typedef typename Container::value_type ValueType;
   typedef typename Container::iterator IteratorType;
   typedef Action ActionType;

   //
   //
   ISTL (Container& in) : _container (in) {
      debug_mustbe (_container.empty ());
   }
   void serialize (Persistance::IArchive& in) {
      int size;
      in >> size;
      IteratorType it = _container.begin ();
      for (int i=0 ; i<size ; i++) {
         ValueType value;
         Action t1 (value);
         in >> t1;
         it = _container.insert (it, value);
      }
   }

private:
   Container& _container;
};



//
// this class is used to register (read) objects to an STL container
// note: this is somewhat complicated, because registration is two-phased:
// the actual linking of a pointer to real-live object may occur
// long after the scope of the 'ISTLReg' object is over.
// therefore, it creates an 'Array' object which stays alive in heap memory
// until all the links to it have been created.
template <class Container, class T = TYPENAME Container::value_type>
class ISTLReg : public Manipulator {
public:
   //
   //
   typedef Container ContainerType;
   typedef T TType;

   //
   //
   ISTLReg (Container& cont) : _container (cont), _array (NULL) {
   }
   void serialize (IArchive& in) {
      int size;
      in >> size;
      if (size > 0) {
         //
         // TODO: make this exception safe
         _array = new Array (_container, size);
         _array->registerObjects (in);
         _array->finished ();
      }
   }

private:
   class Array {
   public:
      Array (Container& cont, int size) : _size (size), _cont (cont) {
         _links = new T [size];
         _remaining = size + 1; // one more for the ptr in ISTLReg
      }
      ~Array () {
         delete [] _links;
      }

      void registerObjects (IArchive& in) {
         for (int i=0 ; i<_size ; i++)
            in.registry ().readObject (new Link (this, i), in);
      }

      void update (int index, Object* o) {
         _links [index] = dynamic_cast <T> (o);
         finished ();
      }

      void finished () {
         _remaining--;
         if (_remaining == 0) {
            for (int i=0 ; i<_size ; i++) {
               _cont.insert (_cont.end (), _links [i]);
            }

            delete this;
         }
      }

   private:
      T* _links;
      int _size;
      int _remaining;
      Container& _cont;
   };



   class Link : public IRegistry::AbstractLink {
   public:
      Link (Array* reg, int index) : _reg (reg), _index (index) {
      }
      virtual void update (Object* o) {
         _reg->update (_index, o);
      }

   private:
      Array* _reg;
      int _index;
   };

private:
   Container& _container;
   Array* _array; // self owned
};



//
// reads a map from archive
template <class Container>
class IMap : public ISTL < Container, IMapPair <Container> > {
public:
   //
   //
   typedef ISTL <Container, IMapPair <Container> > SuperType;

   //
   //
   IMap (Container& in) : SuperType (in) {
   }
};


END_NAMESPACE (Persistance);
