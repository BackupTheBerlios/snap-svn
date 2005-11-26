#ifndef _SeedSearcher_Preprocessor_h
#define _SeedSearcher_Preprocessor_h

#include "Defs.h"
#include "Core/STLHelper.h"
#include "SequenceDB.h"
#include "Core/AutoPtr.h"
#include "Core/ChunkAllocator.h"

class Preprocessor {
public:
	typedef Vec <Sequence const*> SequenceVector;


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

   typedef IteratorWrapper <PositionVector> PositionIterator;
	typedef IteratorWrapper <SequenceVector> SequenceIterator;
   typedef ConstIteratorWrapper <PositionVector> CPositionIterator;
	typedef ConstIteratorWrapper <SequenceVector> CSequenceIterator;

   virtual ~Preprocessor () {
   }

	//
	// smallest/largest searchable assignments
    virtual int minAssignmentSize ()=0;
    virtual int maxAssignmentSize ()=0;

   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual PositionVector* getPositions (SequenceDB::ID, const Assignment&)=0;

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID, const Assignment&)=0;

	//
	// iterate over all sequences
    virtual SequenceVector* getSequences ()=0;

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
    virtual SequenceVector* getSequences (const Assignment&)=0;
};


#endif // _SeedSearcher_Preprocessor_h



