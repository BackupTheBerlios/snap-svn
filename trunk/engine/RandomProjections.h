#ifndef _SeedSearcher_RandomProjections_h
#define _SeedSearcher_RandomProjections_h

#include "Assignment.h"

class RandomProjections {
public:
   enum All {
      all
   };
   
   RandomProjections (  All,              // create all possible projections
                        int cardinality,  // length of the Assignment to create;
                        int length,          // length of the assignment to create
                        int numOfPositions   // number of positions to select in each assignment
                        );

   RandomProjections (  int numOfProjections,// num of assignments to generate
                        int cardinality,     // size of the alphabet
                        int length,          // length of the assignment to create
                        int numOfPositions   // number of positions to select in each assignment
                        );

   //
   // returns how many different projections actually created
   int numOfProjections () const {
      return _vector.size ();
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

   void getAssignment (int index, Assignment&) const;
   Assignment getAssignment (int index) const;

   typedef Vec <int> RandomPositions;
   typedef Vec <RandomPositions> RandomPositionsVector;

private:
   int _length;
   int _cardinality;
   int _numOfPositions;
   RandomPositionsVector _vector;
};


#endif // _SeedSearcher_RandomProjections_h