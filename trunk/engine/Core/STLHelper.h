#ifndef _SeedSearcher_STLHelper_h
#define _SeedSearcher_STLHelper_h

#include "Core/Defs.h"
#include <vector>


//
// choose between wrapper or standard vector
#define USE_VECTOR_WRAPPER BASE_DEBUG

//
// wrapper for std::vector which checks bounds
template <typename T>
class VectorWrapper : public std::vector <T>   {
public:
   typedef std::vector <T> Super;
   typedef typename Super::const_iterator const_iterator;
   typedef typename Super::iterator iterator;

   VectorWrapper () {}
   VectorWrapper (int size) : Super (size) {}
   VectorWrapper (int size, T t) : Super (size,t) {}
   VectorWrapper (const_iterator b, const_iterator e) : Super (b, e) {}
   VectorWrapper (const Super& o) : Super (o) {
   }

   T& operator [] (unsigned int i) {
      debug_mustbe (i>=0 && i<size ());
      return Super::operator [] (i);
   }

   const T& operator [] (unsigned int i) const{
      debug_mustbe (i>=0 && i<size ());
      return Super::operator [] (i);
   }
};

//
// create a new vector from iterators
template <class Vector, typename const_iterator>
static Vector* createNewVector (int size, const_iterator b, const_iterator e)
{
   Vector* v = new Vector (size);
   std::copy (b, e, v->begin ());
   return v;
}




#if USE_VECTOR_WRAPPER
#  define Vec  VectorWrapper
#else
#  define Vec  std::vector
#endif



template <class Container> 
class IteratorWrapper{
public:
   ;
   // the type of the values we are iterating over
   typedef typename Container::value_type value_type;

   //
   // underlining iterator
    //Container::iterator;
   typedef typename Container::iterator iterator;

   //
   // Copy Ctor & operator =
   inline IteratorWrapper () : _current (NULL), _end (NULL) {
   }
   inline IteratorWrapper (iterator begin, iterator end) : _current (begin), _end (end) {
   }
   inline IteratorWrapper (const IteratorWrapper& i) : _current (i._current), _end (i._end) {
   }
   inline IteratorWrapper& operator = (const IteratorWrapper& i) {
      _current = i._current;
      _end = i._end;
      return *this;
   }

   //
   // iteration methods
   virtual bool hasNext () const {
      return _current != _end;
   }
   virtual void next () {
      debug_mustbe (_current != _end);
      _current++; 
   }
   virtual value_type& get () const {
      debug_mustbe (_current != _end);
      return *_current;
   }
   value_type* operator -> () {
      //
      // weird syntax needed in case 'iterator' is a class/struct and 
      // not a pointer
      return &(*_current); 
   }
   value_type& operator * () {
      return *_current;
   }

private:
   iterator _current;
   iterator _end;
};


template <class Container>
class ConstIteratorWrapper {
public:
   ;
   // the type of the values we are iterating over
   typedef typename Container::value_type value_type;

   //
   // underlining iterator
    //Container::iterator;
   typedef typename Container::const_iterator iterator;

   //
   // Copy Ctor & operator =
   inline ConstIteratorWrapper (iterator begin, iterator end) : _current (begin), _end (end) {
   }
   inline ConstIteratorWrapper (const ConstIteratorWrapper& i) : _current (i._current), _end (i._end) {
   }
   inline ConstIteratorWrapper& operator = (const ConstIteratorWrapper& i) {
      _current = i._current;
      _end = i._end;
   }

   //
   // iteration methods
   inline bool hasNext () {
      return _current != _end;
   }
   inline void next () {
      debug_mustbe (_current != _end);
      _current++; 
   }
   inline const value_type& get () const {
      debug_mustbe (_current != _end);
      return *_current;
   }
   inline value_type const* operator -> () {
      //
      // weird syntax needed in case 'iterator' is a class/struct and 
      // not a pointer
      return &(*_current); 
   }
   inline value_type const& operator * () {
      return *_current;
   }

private:
   iterator _current;
   iterator _end;
};





template <class Container>
class MapIteratorWrapper {
public:
   //
   // underlining iterator
   typedef typename Container::const_iterator iterator;
   //
   // the type of the values we are iterating over
   typedef typename Container::referent_type referent_type;

   // Copy Ctor & operator =
   inline MapIteratorWrapper (iterator begin, iterator end) : _current (begin), _end (end) {
   }
   inline MapIteratorWrapper (const MapIteratorWrapper& i) : _current (i._current), _end (i._end) {
   }
   inline MapIteratorWrapper& operator = (const MapIteratorWrapper& i) {
      _current = i._current;
      _end = i._end;
   }

   //
   // iteration methods
   inline bool hasNext () {
      return _current != _end;
   }
   inline void next () {
      debug_mustbe (_current != _end);
      _current++; 
   }
   inline const referent_type& get () const {
      debug_mustbe (_current != _end);
      return _current->second;
   }

private:
   iterator _current;
   iterator _end;
};






#endif //_SeedSearcher_STLHelper_h

