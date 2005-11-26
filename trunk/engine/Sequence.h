#ifndef _SeedSearcher_Sequence_h
#define _SeedSearcher_Sequence_h

#include "Defs.h"
#include "Core/STLHelper.h"
#include "Core/ChunkAllocator.h"
#include "Core/Str.h"


class Sequence {
public:
   typedef int ID;
   typedef StrBuffer Name;

   Sequence (ID id, 
            const Str& data, 
            const Str& name, 
            double wgt, 
            Str reverse = NULL)
   : _id (id), _data (data), _reverse (reverse),
     _name (name), _weight (wgt)
   {
   }
   ~Sequence () {
   }
   int length () const {
      return _data.length ();
   }
   inline const Str& data (Strand strand = _strand_pos_) const {
      if (strand == _strand_pos_)
         return _data;
      else return _reverse;
   }
   inline ID id () const {
      return _id;
   }
   const Name& name () const {
      return _name;
   }
   void weight (double inWeight) {
      _weight = inWeight;
   }
   inline double weight () const {
      return _weight;
   }
   Str data (int startPos, int length, Strand strand = _strand_pos_) const {
      return Str (data (strand), startPos, startPos + length);
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
   StrBuffer _reverse;
   Name _name;
   double _weight;
   static ChunkAllocator <Sequence> __allocator;
};



//
// basic interface for deciding if a sequence is positive / negative
class SeqWeightFunction {
public:
   SeqWeightFunction () : _invert (false), _partialCount (false) {
   }
   virtual ~SeqWeightFunction () {
   }

   void invert () {
      _invert = !_invert;
   }

   //
   // get/set the partialCount property.
   // if partialCount is false, weights are discrete.
   // if partialCount is true, weights are real values
   bool partialCount () const {
      return _partialCount;
   }
   void partialCount (bool in)  {
      _partialCount = in;
   }
   //
   // returns the weight of the seq, as determined by this weight function
   virtual double weight (const Sequence& seq) const {
      return _partialCount? seq.weight () : 1;
   }

   //
   // returns true iff the weight belongs to the positive or negative set.
   // if so, 'outIsPositive' is set to true iff the weight belongs to the
   // positive set.
   inline bool isRelevant (const Sequence& seq, bool& outIsPositive) const {
      return isRelevant (seq.weight (), outIsPositive);
   }
   inline bool isRelevant (double weight, bool& outIsPositive) const {
      bool result = 
         isRelevantImpl (weight, outIsPositive);
      if (_invert)
	    outIsPositive = ! outIsPositive;
      return result;
   }

   //
   // returns true iff the weight belongs to the positive set
   bool isPositive (double weight) const {
      bool isPositive = false;
      bool res = isRelevant (weight, isPositive);
      return res && isPositive;
   }
   bool isPositive (const Sequence& sequence) const {
      return isPositive (sequence.weight ());
   }

   //
   // returns true iff the weight belongs to the negative set
   bool isNegative (double weight) const{
      bool isPositive = false;
      bool res = isRelevant (weight, isPositive);
      return res && (!isPositive);
   }
   bool isNegative (const Sequence& sequence) const {
      return isNegative (sequence.weight ());
   }
   //
   // is positive or negative
   bool isRelevant (const Sequence& sequence) const {
      bool unused;
      return isRelevant (sequence.weight (), unused);
   }

protected:
   virtual bool isRelevantImpl (double weight, bool& outIsPositive) const = 0;
   bool _invert;
   bool _partialCount;
};




class SeqPosition {
public:
   //
   // ctor is called in a loop, so must be very effiecient
	inline SeqPosition (Sequence const * seq, int pos) 
   :  _sequence (seq), _position (pos), _strand (_strand_pos_) {
   }
	inline SeqPosition (Sequence const * seq, int pos, Strand strand) 
   :  _sequence (seq), _position (pos), _strand (strand) {
   }
   ~SeqPosition () {
   }
   
   inline char operator [] (int index) const {
      return getData (index);
   }
   inline char getData (int index) const {
      debug_mustbe (index + _position < _sequence->length ());
      return _sequence->data (_strand) [index + _position];
   }
   //
   // how much data available ahead in the stream
   inline int maxLookahead () const {
      return _sequence->length () - _position;
   }
   const Sequence* sequence () const {
      return _sequence;
   }
   //
   // returns the offset in the sequence (unmodified by strand)
   int position () const {
      return _position;
   }
   Strand strand () const {
      return _strand;
   }
   //
   // returns the sequence string starting at this position, 
   // modified by 'offset'with length 'length'. 
   // if offset is too big or too small (negative)
   // it will return a shorter string. in any case, it always returns 
   // a valid string.
   Str getSeedString (int seedLength, int offset = 0) const;

   //
   // 'expands' a motif of length 'inLength' leftwards and rightwards,
   // in the desired amount. it adds alignment bytes if necessary.
   // returns the index of the beginning of the middle section
   int getSeedString (StrBuffer& outBuffer,  // the string is stored here
                      int inLength,          // desired length
                      int inDesiredExpansionLeft, 
                      int inDesiredExpansionRight,
                      char alignment = '-'  // alignment for missing pos
                      ) const; 

   int getSeedString (  StrBuffer& outBuffer, 
                        int inLength,  // length of seed before expansion
                        int inDesiredLength,  // length after expansion
                        char alignment = '-'  // alignment for missing pos
                        ) const;

   //
   //
   static int getSeedString (
	                     Sequence const* sequence,
	                     int position,
                        Strand strand,
                        StrBuffer& outBuffer, 
                        int inLength,         // length of seed before expansion
                        int inDesiredLength,  // length after expansion
                        char alignment = '-'  // alignment for missing pos
                        );

   //
   // the 1st argument (in/out) provides the offset from this position
   // the 2nd argument (in/out) provides the length from the offset
   //
   // this method makes changes the offset (if necessary) so 
   // that it is legal, decreasing the length in accordance.
   // also if the length is too large, it is decreased.
   void getModifiedOffsets (int& offset, int& length) const;      

#if SEED_CHUNK_ALLOCATION_OPTIMIZATION
   void* operator new (size_t size) {
      debug_mustbe (size == sizeof (SeqPosition));
      return __allocator.newT ();
   }
   void operator delete(void *p)    {
      __allocator.deleteT (reinterpret_cast <SeqPosition*> (p));
   }
#endif

private:
	Sequence const * _sequence;
	int _position;
   Strand _strand;
   static ChunkAllocator <SeqPosition> __allocator;
};

//
// a vector of sequences
typedef Vec <Sequence const*> SequenceVector;

//
// a vector of positions
class PositionVector : public Vec <SeqPosition const*> {
public:
   PositionVector () {
   }
   PositionVector (int size) : Vec <SeqPosition const*> (size) {
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













