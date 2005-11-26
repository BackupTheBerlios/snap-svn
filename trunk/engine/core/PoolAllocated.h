#if 0 

#ifndef _SeedSearcher_Core_PoolAllocated_h
#define _SeedSearcher_Core_PoolAllocated_h

#include "boost/pool/object_pool.hpp"

struct DefaultAllocator : public boost::default_user_allocator_new_delete {
};

template <class T, class UserAllocator = DefaultAllocator >
class TPoolAllocated {
public:
   virtual ~TPoolAllocated () {
   }
   void* operator new (size_t inSize) {
      return _pool.malloc ();
   }
   void operator delete (void* inPtr) {
      if (inPtr) {
         _pool.free (reinterpret_cast <T*> (inPtr));
      }
   }

   void poolDelete () {
      this->~TPoolAllocated ();
      _pool.free (reinterpret_cast <T*> (this));
   }

   typedef boost::object_pool <T, UserAllocator> TObjectPool;
protected:
   static TObjectPool _pool;
};

template <class T, class UserAllocator>
typename TPoolAllocated<T, UserAllocator>::TObjectPool TPoolAllocated<T, UserAllocator>::_pool;

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: PoolAllocated.h $
// Version     : $Revision: 6 $ 
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

#endif 