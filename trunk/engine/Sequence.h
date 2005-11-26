#ifndef _SeedSearcher_Sequence_h
#define _SeedSearcher_Sequence_h

#include "Defs.h"
#include "Persistance/Object.h"

#include "Core/STLHelper.h"
#include "Core/ChunkAllocator.h"
#include "Core/Str.h"


class Sequence : public Persistance::Object {
public:
   typedef int ID;
   typedef StrBuffer Name;

   Sequence (ID id, const Str& data, const Str& name, double wgt)
   : _id (id), _data (data), _name (name), _weight (wgt), _hasWeight (true) 
   {
   }
   Sequence (ID id, const Str& data, const Str& name) 
   : _id (id), _data (data), _name (name), _weight (0xBAADF00D), _hasWeight (false) 
   {
   }
   ~Sequence () {
   }
   int length () const {
      return _data.length ();
   }
   inline const Str& data () const {
      return _data;
   }
   inline ID id () const {
      return _id;
   }
   const Name& name () const {
      return _name;
   }
   bool hasWeight () const {
      return _hasWeight;
   }
   void weight (double inWeight) {
      _hasWeight = true;
      _weight = inWeight;
   }
   inline double weight () const {
      return _weight;
   }
   void noWeight () {
      _weight = 0xBAADF00D;
      _hasWeight = false;
   }
   Str data (int startPos, int length) const {
      return Str (_data, startPos, length);
   }

   void serialize (Persistance::IArchive& in);
   void serialize (Persistance::OArchive& out);
   Sequence () {
   }

#if SEED_CHUNK_ALLOCATION_OPTIMIZATION
   void* operator new (size_t size) {
      debug_mustbe (size == sizeof (Sequence));
      return __allocator.newT ();
   }
   void operator delete(void *p)    {
      __allocator.deleteT (reinterpret_cast <Sequence*> (p));
   }
#endif

private:
	ID _id;
   StrBuffer _data;
   Name _name;
   double _weight;
   bool _hasWeight;
   static ChunkAllocator <Sequence> __allocator;
};



class Position : public Persistance::Object {
public:
   //
   // ctor is called in a loop, so must be very effiecient
	inline Position (Sequence const * seq, int pos) :  _sequence (seq),
                                                      _position (pos) {
   }
   ~Position () {
   }
   
   inline char operator [] (int index) const {
      return getData (index);
   }
   inline char getData (int index) const {
      debug_mustbe (index + _position < _sequence->length ());
      return _sequence->data () [index + _position];
   }
   //
   // how much data available ahead in the stream
   inline int maxLookahead () const {
      return _sequence->length () - _position;
   }
   const Sequence* sequence () const {
      return _sequence;
   }
   int position () const {
      return _position;
   }
   //
   // return the sequence string starting at this position, with length 'length'
   Str getSeedString (int seedLength) const {
      return Str (_sequence->data (), _position, _position + seedLength);
   }
   //
   // returns the sequence string starting at this position, modified by 'offset'
   // with length 'length'. if offset is too big or too small (negative)
   // it will return a shorter string. in any case, it always returns 
   // a valid string.
   Str getDataString (int offset, int length) const {
      //
      // 
      getModifiedOffsets (offset, length);

      //
      // keep str's ctor happy
      if (_position + offset > _sequence->length ()) {
         return 0;
      }

      debug_mustbe (length > 0);
      debug_mustbe (_position + offset >= 0);
      debug_mustbe (_position + offset + length <= _sequence->length ());


      return Str (_sequence->data (), 
                  _position + offset, 
                  _position + offset + length);
   }
   //
   //
   void getModifiedOffsets (int& offset, int& length) const
   {
      //
      // do not go past the beginning of the string
      int startIndex = _position + offset;
      if (startIndex < 0) {
         //
         // the string is truncated in the left, so return less bytes
         length += startIndex;   // shorten length
         offset -= startIndex;   // make offset less negative
         startIndex = 0;
      }

      //
      // do not go beyond the end of the string
      int endIndex = startIndex + length;
      if (endIndex > _sequence->length ()) {
         endIndex = _sequence->length ();
      }

      //
      // calculate length
      length = tmax (endIndex - startIndex, 0);
   }
      

   void serialize (Persistance::IArchive& in);
   void serialize (Persistance::OArchive& out);
   Position () {
   }

#if SEED_CHUNK_ALLOCATION_OPTIMIZATION
   void* operator new (size_t size) {
      debug_mustbe (size == sizeof (Position));
      return __allocator.newT ();
   }
   void operator delete(void *p)    {
      __allocator.deleteT (reinterpret_cast <Position*> (p));
   }
#endif

private:
	Sequence const * _sequence;
	int _position;
   static ChunkAllocator <Position> __allocator;
};

//
// a vector of sequences
typedef Vec <Sequence const*> SequenceVector;

//
// a vector of positions
class PositionVector : public Vec <Position const*> {
public:
   PositionVector () {
   }
   PositionVector (int size) : Vec <Position const*> (size) {
   }
   ~PositionVector () {
   }

#     if SEED_CHUNK_ALLOCATION_OPTIMIZATION
      void* operator new (size_t size) {
         debug_mustbe (size == sizeof (PositionVector));
         return __allocator.newT ();
      }
      void operator delete(void *p)    {
         __allocator.deleteT (reinterpret_cast <PositionVector*> (p));
      }
#     endif

private:
   static ChunkAllocator <PositionVector> __allocator;
};

//
// iterators
typedef IteratorWrapper <PositionVector> PositionIterator;
typedef IteratorWrapper <SequenceVector> SequenceIterator;
typedef ConstIteratorWrapper <PositionVector> CPositionIterator;
typedef ConstIteratorWrapper <SequenceVector> CSequenceIterator;




#endif // _SeedSearcher_Sequence_h









