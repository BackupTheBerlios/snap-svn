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
