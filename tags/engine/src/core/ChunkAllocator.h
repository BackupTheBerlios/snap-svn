#ifndef _SeedSearcher_Core_ChunkAllocator_h
#define _SeedSearcher_Core_ChunkAllocator_h

#include "Defs.h"
#include <vector>
#include <typeinfo>

#if CORE_DL_MALLOC_OPTIMIZATION
#  include "dlmalloc.h"
#endif



//
// the Ctor for the object is called by the compiler
// after returning the memory to the user, if the user overloaded the new operator
// for the class
template <class T>
struct NoCtor {
   inline static T* construct (void* in) {
      return (T*) in;
   }
};

//
// the Dtor for the object is called by the compiler
// before returning the memory to the allocator, 
// if the user overloaded the delete operator for the class
template <class T>
struct NoDtor {
   inline static void destruct (T*) {
   }
};


//
//
template <class T, class Ctor = NoCtor <T>, class Dtor = NoDtor <T> >
class ChunkAllocator {
public:
   ChunkAllocator (int noOfPages = 1)
   : _currentChunk (-1), _currentChunkSize (0), _currentChunkIndex (0) 
   {
      debug_mustbe (noOfPages > 0);
      // _chunkSize = (SystemInfo::getPageSize () * noOfPages) / sizeof (T) - 128;
      _chunkSize = noOfPages * 1024;
   }
   ~ChunkAllocator () {
      clear ();
   }
   void clear () {
     if (_currentChunk == -1) {
       //
       // not used, nothing to do or print
       return;
     }
      printf ("Clearing %d chunks for %s... ", _currentChunk + 1, typeid (T).name ());
      for (int i=0 ; i<= _currentChunk ; i++) {
         delete _chunks [i];
      }

      _chunks.clear ();
      _currentChunk = _currentChunkSize = _currentChunkIndex = 0;
#if CORE_DL_MALLOC_OPTIMIZATION
      //
      // return memory to the system
      int result = dlmalloc_trim (0);
      printf (result? "[DLMalloc released system memory]\n" : 
	      "[DLMalloc did not release system memory]\n");
#else
      printf ("\n");
#endif
   }

   inline T* newT () {
      if (_currentChunkIndex >= _currentChunkSize) {
         //
         // we need more chunks
         _chunks.push_back (new Chunk (_chunkSize));
         _currentChunk++;
         _currentChunkSize = _chunkSize;
         _currentChunkIndex = 0;
      }

      return Ctor::construct (_chunks [_currentChunk]->get (_currentChunkIndex++));
   }
   inline void deleteT (T* in) {
      //
      // unfortunately, there is no way to free memory of individual objects,
      // so we just call their 'Dtor'
      Dtor::destruct (in);
   }


   class Chunk {
   public:
      Chunk (int inSize) : _size (inSize) {
         //
         // problem: this calls the default ctors...
         //_elements = new T [_size];
         //
         // and this seems to allocate 4 bytes less than new...
         char* ptr = (char*) SEED_MALLOC (4 + sizeof (T) * _size);
         _elements = (T*) (ptr + 4);
      }
      ~Chunk () {
         char* ptr = (char*)_elements;
         SEED_FREE (ptr - 4);
         //
         // this causes elements to be freed twice...
         // delete [] _elements;
      }
      inline void* get (int index) {
         debug_mustbe (index >= 0);
         debug_mustbe (index < _size);
         return _elements + index;
      }

   private:
      Chunk (const Chunk&);
      Chunk& operator = (const Chunk&);

      int _size;
      T* _elements;
   };

   //
   // TODO: increase chunk sizes in time?
private:
   int _chunkSize;
   int _currentChunk;      // which chunk are we using
   int _currentChunkSize;  // size of the chunk we are using
   int _currentChunkIndex; // the index in the chunk of the next object to return
   std::vector <Chunk*> _chunks;
};

#endif // _SeedSearcher_Core_ChunkAllocator_h







