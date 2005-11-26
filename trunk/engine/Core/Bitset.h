#ifndef _SeedSearcher_Core_Bitset
#define _SeedSearcher_Core_Bitset

#include "Defs.h"
#include <math.h>
#include <bitset>

class Bitset {
   //
   // this class is a wrapper for std::bitset
   // which should be used when the number of bits is not known 
   // at compile-time, but rather only during runtime.
public:
   explicit Bitset (int n) : _n(n), _length (ceil ((float) n / CHUNK_SIZE)) {
      _bits = (_n != 0)? new Bits [_length] : NULL;
   }
   Bitset (const Bitset& o) : _n (o._n), _length (o._length)   {
      _bits = new Bits [_length];
      for (int i=0 ; i<_length ; i++)
         _bits [i] = o._bits [i];
   }
   ~Bitset () {
      delete [] _bits;
   }

   Bitset& operator = (const Bitset& o) {
      _n = o._n;
      if (_length != o._length) {
         delete _bits;
         _length = o._length;
         _bits = new Bits [_length];
      }

      for (int i=0 ; i<_length ; i++)
         _bits [i] = o._bits [i];
   }

   bool test(size_t pos) const {
      size_t chunk;
      size_t chunkPos;
      getPos (pos, chunk, chunkPos);
      return _bits [chunk].test (chunkPos);
   }
   bool any() const {
      for (int i=0 ; i<_length ; i++)
         if (_bits [i].any ())
            return true;

      return false;
   }
   bool none() const {
      for (int i=0 ; i<_length ; i++)
         if (_bits [i].any ())
            return false;

      return true;
   }
   size_t count() const {
      size_t c = 0;
      for (int i=0 ; i<_length ; i++)
         c += _bits [i].count ();

      return c;
   }
   size_t size() const {
      return _n;
   }
   void reset (size_t pos) {
      size_t chunk;
      size_t chunkPos;
      getPos (pos, chunk, chunkPos);
      _bits [chunk].reset (chunkPos);
   }
   void reset () {
      for (int i=0 ; i<_length ; i++)
         _bits [i].reset ();
   }
   void set (size_t pos) {
      size_t chunk;
      size_t chunkPos;
      getPos (pos, chunk, chunkPos);
      _bits [chunk].set (chunkPos);
   }
   void set () {
      for (int i=0 ; i<_length ; i++)
         _bits [i].set ();
   }

   //
   // intersect
   Bitset& operator &= (const Bitset& o) {
      debug_mustbe (_n == o._n);
      for (int i=0 ; i<_length ; i++)
         _bits [i] &= o._bits [i];
   }

   //
   // join
   Bitset& operator |= (const Bitset& o) {
      debug_mustbe (_n == o._n);
      for (int i=0 ; i<_length ; i++)
         _bits [i] |= o._bits [i];
   }


   enum {
      // CHAR_BIT = 8,
      CHUNK_SIZE = CHAR_BIT * sizeof (int)
   };
   
   typedef std::bitset <CHUNK_SIZE> Bits;

private:
   static void getPos (size_t pos, size_t& chunk, size_t& chunkPos) {
      debug_mustbe (pos >= 0);
      debug_mustbe (pos < _n);

      div_t t = div (pos, CHUNK_SIZE);
      chunk = t.quot;
      chunkPos = t.rem;
   }

private:
   int _n;
   int _length;
   Bits* _bits;
};
