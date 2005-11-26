#ifndef _SeedSearcher_Preprocessor_h
#define _SeedSearcher_Preprocessor_h

#include "Core/STLHelper.h"
#include "SequenceDB.h"
#include "Core/AutoPtr.h"


//
// defined in Assignment.h
class Assignment;

class Preprocessor {
public:
   typedef Vec <SequenceDB::Position const*> PositionVector;
	typedef Vec <SequenceDB::Sequence const*> SequenceVector;

   typedef IteratorWrapper <PositionVector> PositionIterator;
	typedef IteratorWrapper <SequenceVector> SequenceIterator;

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

/*
   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual PositionIterator positionIterator (SequenceDB::ID, const Assignment&)=0;

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID, const Assignment&)=0;

	//
	// iterate over all sequences
    virtual SequenceIterator_ptr sequenceIterator ()=0;

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
    virtual SequenceIterator_ptr sequenceIterator (const Assignment&)=0;
*/
};


#endif // _SeedSearcher_Preprocessor_h

