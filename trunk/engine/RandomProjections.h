#ifndef _SeedSearcher_RandomProjections_h
#define _SeedSearcher_RandomProjections_h

#include "Assignment.h"

class RandomProjections {
public:
   enum All {
      all
   };
   
   RandomProjections (  All,              // create all possible projections
                        int length,          // length of the assignment to create
                        int numOfPositions   // number of positions to select in each assignment
                        );

   RandomProjections (  int numOfProjections,// num of assignments to generate
                        int length,          // length of the assignment to create
                        int numOfPositions   // number of positions to select in each assignment
                        );

   //
   // returns how many different projections actually created
   int numOfProjections () const {
      return _vector.size ();
   }
   int maxPossibleProjections () const {
      return _maxPossibleProjections;
   }
   //
   // returns the length of each projection
   int length () const {
      return _length;
   }
   //
   // returns the number of random positions inside each projection
   int numOfPositions () const {
      return _numOfPositions;
   }

   const Assignment& getAssignment (
                        int index, 
                        const Assignment::Position& randPos,
                        const Assignment::Position& normalPos) const;

   typedef Vec <int> RandomPositions;
   typedef Vec <RandomPositions> RandomPositionsVector;
   typedef Vec <Assignment> AssignmentVector;

   static void srand (unsigned int seed);

private:
   int _length;
   int _numOfPositions;
   int _maxPossibleProjections;
   RandomPositionsVector _vector;
   AssignmentVector _assignments;
};


#endif // _SeedSearcher_RandomProjections_h











