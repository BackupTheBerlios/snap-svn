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
   bool hasNext () const {
      return _current != _end;
   }
   void next () {
      debug_mustbe (_current != _end);
      _current++; 
   }
   const value_type& get () const {
      debug_mustbe (_current != _end);
      return *_current;
   }
   /*
   value_type get () {
      debug_mustbe (_current != _end);
      return *_current;
   }
   */
   value_type* operator -> () const {
      //
      // weird syntax needed in case 'iterator' is a class/struct and 
      // not a pointer
      return &(*_current); 
   }
   const value_type& operator * () const {
      return *_current;
   }
   /*
   value_type operator * () {
      return *_current;
   }
   */
   iterator getImpl () {
      return _current;
   }
   const iterator getImpl () const {
      return _current;
   }

protected:
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
   inline ConstIteratorWrapper () : _current (NULL), _end (NULL) {
   }
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
   const iterator getImpl () const {
      return _current;
   }

protected:
   iterator _current;
   iterator _end;
};


template <class Container>
class Map1stBinder {
public:
   typedef typename Container::iterator iterator_type;
   typedef typename Container::const_iterator const_iterator_type;
   typedef const typename Container::key_type value_type;

   class Iterator {
   public:
      Iterator (iterator_type in) : _it (in) {
      }
      bool operator == (Iterator o) const{
         return _it == o._it;
      }
      bool operator != (Iterator o) const{
         return _it != o._it;
      }
      void operator ++ () {
         _it++;
      }
      Iterator operator ++ (int) {
         return Iterator (_it++);
      }
      value_type& operator * () const{
         return _it->first;
      }
      iterator_type getImpl () {
         return _it;
      }
      const iterator_type getImpl () const {
         return _it;
      }
   protected:
      iterator_type _it;
   };

   class ConstIterator {
   public:
      ConstIterator (const_iterator_type in) : _it (in) {
      }
      bool operator == (ConstIterator o) const{
         return _it == o._it;
      }
      bool operator != (ConstIterator o) const{
         return _it != o._it;
      }
      void operator ++ () {
         _it++;
      }
      ConstIterator operator ++ (int) {
         return ConstIterator (_it++);
      }
      value_type& operator * () const{
         return _it->first;
      }
      const_iterator_type getImpl () {
         return _it;
      }
      const const_iterator_type getImpl () const {
         return _it;
      }
   protected:
      const_iterator_type _it;
   };
   
   typedef Iterator iterator;
   typedef ConstIterator const_iterator;
};

template <class Container>
class Map2ndBinder {
public:
   typedef typename Container::iterator iterator_type;
   typedef typename Container::const_iterator const_iterator_type;
   typedef typename Container::referent_type value_type;
   
   typedef Map2ndBinder <Container> iterator;

   Map2ndBinder (iterator_type in) : _it (in) {
   }
   bool operator == (Map2ndBinder o) const{
      return _it == o._it;
   }
   bool operator != (Map2ndBinder o) const{
      return _it != o._it;
   }
   void operator ++ () {
      _it++;
   }
   Map2ndBinder operator ++ (int) {
      return Map2ndBinder (_it++);
   }
   value_type& operator * () const{
      return _it->second;
   }
   iterator_type getImpl () {
      return _it;
   }

protected:
   iterator_type _it;
};

#endif //_SeedSearcher_STLHelper_h

