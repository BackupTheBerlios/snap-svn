#if 0 

#ifndef _SeedSearcher_Core_AllocPolicy_h
#define _SeedSearcher_Core_AllocPolicy_h 

//
// StdAllocation is in 
struct StdAllocPolicy {

   template <class T> struct Traits {
      //
      // Allocator
      struct Allocator {
         //
         // if the return value is true
         // then the caller has to iterate over all allocated elements
         // and dispose of them
         bool cleanupMemory () {
            return true;
         }
         void cleanupMemory (T* t) {
            delete t;
         }
         static void dispose (T* t) {
            t->cleanupMemory ();
         }
      };

      struct TBase {
         typedef Traits TTraits;
         typedef Allocator TAllocator;

         void* operator new (size_t s, Allocator&) {
            return ::operator new (s);
         }
         void operator delete (void* p, Allocator&) {
            ::operator delete (p);
         }
         void operator delete (void* p) {
            ::operator delete (p);
         }

         virtual ~TBase () {
         }
         void setupMemory (Allocator&) {
         }
         void cleanupMemory () {
            delete this;
         }
      };
   };
};

struct StaticPoolPolicy {
   //
   //
   template <class T> struct Traits {
      struct Allocator {
         //
         // if the return value is true
         // then the caller has to iterate over all allocated elements
         // and dispose of them
         bool cleanupMemory () {
            return true;
         }
         void cleanupMemory (T* t) {
            delete t;
         }
         static void dispose (T* t) {
            t->cleanupMemory ();
         }
      };

      struct TBase {
         typedef Traits TTraits;
         typedef Allocator TAllocator;

         void* operator new (size_t s, Allocator&) {
            return TPoolAllocated <T>::operator new(s);
         }
         void operator delete (void* p, Allocator&) {
            TPoolAllocated <T>::operator delete(p);
         }
         void operator delete (void* p) {
            TPoolAllocated <T>::operator delete(p);
         }

         virtual ~TBase () {
         }
         void setupMemory (Allocator&) {
         }
         void cleanupMemory () {
            delete this;
         }
      };
   };
};



struct PrivatePoolPolicy {
   //
   //
   template <class T> struct Traits {
      struct Allocator {
         Allocator () : _cleaningUp (false) {
         }
         //
         // if the return value is true
         // then the caller has to iterate over all allocated elements
         // and dispose of them
         bool cleanupMemory () {
            _cleaningUp = true;
            return false;
         };
         void cleanupMemory (T* t) {
	   if (!_cleaningUp && t)
	      _pool.destroy (t);
         }
         static void dispose (T* t) {
            t->cleanupMemory ();
         }

         bool _cleaningUp;
         boost::object_pool <T, DefaultAllocator> _pool;
      };

      struct TBase {
         typedef Traits TTraits;
         typedef Allocator TAllocator;

         //
         // allow only placement new, disallow delete
         void* operator new (size_t, Allocator& a) {
            return a._pool.malloc ();
         }
         void operator delete (void* p, Allocator& a) {
            a._pool.free (
               reinterpret_cast <T*> (p));
         }
         void operator delete (void* p) {
            mustfail ();
         }

         virtual ~TBase () {
         }
         void setupMemory (Allocator& a) {
            //
            // debug assert
	   USELESS (safe_cast (T*, this));
            _allocator = &a;
         }
         virtual void cleanupMemory () {
            _allocator->dispose (safe_cast (T*, this));
         }

         Allocator* _allocator;
      };
   };
};

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: AllocPolicy.h $
// Version     : $Revision: 3 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
// Description :
//	The Persistence library contains both high & low level IO classes
//	and is high-performance, highly reusable framework 
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


#endif 0 