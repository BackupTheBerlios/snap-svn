#ifndef _SeedSearcher_STLHelper_h
#define _SeedSearcher_STLHelper_h

#include "core/Defs.h"
#include <vector>


//
// choose between wrapper or standard vector
#define USE_VECTOR_WRAPPER BASE_DEBUG


//
// remove elements from vector, while preserving its capacity
template <class _Seq>
static inline void reserveResize (_Seq& sequence, size_t n, size_t res)
{
	sequence.reserve (res);
	sequence.resize (n);
	debug_mustbe (sequence.capacity () >= res);
}

template <class _Seq>
static inline void reserveResize (_Seq& sequence, size_t n)
{
	reserveResize (sequence, n, sequence.size ());
}

//
// remove all elements from vector, 
// while preserving its capacity
template <class _Seq>
static inline void reserveClear (_Seq& sequence, size_t res)
{
	reserveResize (sequence, 0, res);
}

template <class _Seq>
static inline void reserveClear (_Seq& sequence)
{
	reserveClear (sequence, sequence.size ());
}

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


template <class Container, class TIterator>
class IteratorWrapperBase {
public:
   // the type of the values we are iterating over
   typedef typename Container::value_type value_type;

   //
   // underlining iterator
    //Container::iterator;
   typedef TIterator iterator;

   //
   // Copy Ctor & operator =
   inline IteratorWrapperBase () : _init (false), _current (), _end () {
	   _current = _end;
   }
   inline IteratorWrapperBase (iterator begin, iterator end) : _init (true), _current (begin), _end (end) {
   }
   inline IteratorWrapperBase (const IteratorWrapperBase& i) : _init (true), _current (i._current), _end (i._end) {
   }
   inline IteratorWrapperBase& operator = (const IteratorWrapperBase& i) {
		_init = i._init;
      _current = i._current;
      _end = i._end;
      return *this;
   }

   //
   // step forward a few more steps
   void next (int index) {
      //
      // advance the begin iterator
      std::advance(_current, tmin (index, _end - _current));
      //for (; (_current!= _end) && (index > 0) ; --index, ++_current);
   }
   //
   // how many iteration steps maximally allowed
   void allowNext (int length) {
      iterator temp = _current;
      std::advance (temp, tmin (length, _end - _current));
      // for (; (temp != _end) && (length > 0) ; --length, ++temp);
      _end = temp;
   };

   //
   // iteration methods
   inline bool hasNext () const {
      return _init && (_current != _end);
   }
   inline void next () {
      debug_mustbe (hasNext ());
      ++_current; 
   }
   inline const value_type& get () const {
      debug_mustbe (hasNext ());
      return *_current;
   }
   inline value_type const& operator * () const {
      return *_current;
   }
   inline iterator getImpl () {
      return _current;
   }
   inline const iterator getImpl () const {
      return _current;
   }

protected:
	bool _init;
   iterator _current;
   iterator _end;
};

template <  class Container, 
            class Iterator = BOOST_DEDUCED_TYPENAME Container::iterator> 
class IteratorWrapper : 
   public IteratorWrapperBase <Container, typename Container::iterator> 
{
public:
   typedef IteratorWrapperBase <Container, typename Container::iterator> Base;
   //
   // needed again because gcc is complaining about typenames...
   typedef typename Container::iterator iterator;
   typedef typename Container::value_type value_type;

   inline IteratorWrapper () {
   }
   inline IteratorWrapper (iterator begin, iterator end) 
      : Base (begin, end) {
   }
   inline IteratorWrapper (const IteratorWrapper& i)
      : Base (i) {
   }

   inline value_type* operator -> () const {
      //
      // weird syntax needed in case 'iterator' is a class/struct and 
      // not a pointer
      return &(*this->_current); 
   }
};

template <class Container> 
class CIteratorWrapper : 
   public IteratorWrapperBase <Container, typename Container::const_iterator> 
{
public:
   typedef IteratorWrapperBase <Container, typename Container::const_iterator> Base;
   //
   // needed again because gcc is complaining about typenames...
   typedef typename Container::const_iterator iterator;
   typedef typename Container::value_type value_type;

   inline CIteratorWrapper () {
   }
   inline CIteratorWrapper (iterator begin, iterator end) 
      : Base (begin, end) {
   }
   inline CIteratorWrapper (const CIteratorWrapper& i)
      : Base (i) {
   }

   inline value_type const* operator -> () const {
      //
      // weird syntax needed in case 'iterator' is a class/struct and 
      // not a pointer
      return &(*this->_current); 
   }
};

template <typename T>
class AbstractIterator {
public:
   class Rep {
   public:
      virtual ~Rep () {
      }
      virtual bool next () = 0;
      virtual bool hasNext () const = 0;
      virtual T* get () const = 0;
      inline T& operator * () const { return *get (); }
      inline T* operator -> () const {return get (); }
   };

public:
   inline AbstractIterator () : _rep (NULL) {
   }
   inline AbstractIterator (Rep* in) : _hasNext (in->hasNext ()), _rep (in) {
   }
   ~AbstractIterator () {
      delete _rep;
   }
   inline void next () {
      mustbe (_rep);
      //
      // optimization: it is assumed that 
      _hasNext = _rep->next ();
   }
   inline bool hasNext () const {
      mustbe (_rep);
      return _hasNext;
   }
   inline T* get () const {
      mustbe (_rep);
      return _rep->get ();
   }
   inline T& operator * () const { return *get (); }
   inline T* operator -> () const {return get (); }

private:
   AbstractIterator& operator = (const AbstractIterator&);
   AbstractIterator (const AbstractIterator&);

   bool _hasNext;
   Rep* _rep;
};

template <typename T>
class CAbstractIterator {
public:
   class Rep {
   public:
      virtual ~Rep () {
      }
      virtual bool next () = 0;
      virtual bool hasNext () const = 0;
      virtual const T* get () const = 0;
      inline const T& operator * () const { return *get (); }
      inline const T* operator -> () const {return get (); }
   };

public:
   inline CAbstractIterator () : _rep (NULL) {
   }
   inline CAbstractIterator (Rep* in) : _hasNext (in->hasNext ()), _rep (in) {
   }
   ~CAbstractIterator () {
      delete _rep;
   }
   inline void next () {
      mustbe (_rep);
      //
      // optimization: it is assumed that 
      _hasNext = _rep->next ();
   }
   inline bool hasNext () const {
      mustbe (_rep);
      return _hasNext;
   }
   inline const T* get () const {
      mustbe (_rep);
      return _rep->get ();
   }
   inline const T& operator * () const { return *get (); }
   inline const T* operator -> () const {return get (); }

private:
   CAbstractIterator& operator = (const CAbstractIterator&);
   CAbstractIterator (const CAbstractIterator&);

   bool _hasNext;
   Rep* _rep;
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

   class CIterator {
   public:
      CIterator (const_iterator_type in) : _it (in) {
      }
      bool operator == (CIterator o) const{
         return _it == o._it;
      }
      bool operator != (CIterator o) const{
         return _it != o._it;
      }
      void operator ++ () {
         _it++;
      }
      CIterator operator ++ (int) {
         return CIterator (_it++);
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
   typedef CIterator const_iterator;
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

//
// File        : $RCSfile: $ 
//               $Workfile: STLHelper.h $
// Version     : $Revision: 26 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
// Description :
//	The Core library contains contains basic definitions and classes
// which are useful to any highly-portable applications
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
//

