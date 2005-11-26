#ifndef _SeedSearcher_RandomProjections_h
#define _SeedSearcher_RandomProjections_h

//
// File        : $RCSfile: $ 
//               $Workfile: RandomProjections.h $
// Version     : $Revision: 14 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
// Description :
//    Concrete classes for creating and retrieving random projections
//    from given <l,d> parameters
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
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

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

   virtual ~RandomProjections () {
   }

   //
   // returns how many different projections actually created
   int numOfProjections () const {
      return _vector.size ();
   }
   int maxPossibleProjections () const {
      return _maxPossibleProjections;
   }
   static int numOfProjections (bool exhaustive, int requestedProjections,
                                 int length, int numOfPositions);
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

   virtual const Assignment& getAssignment (
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

//
// random projections with a midsection of wildcards
class MidsectionRandomProjections : public RandomProjections {
public:
   MidsectionRandomProjections (  
      All,              // create all possible projections
      int length,          // length of the assignment to create
      int numOfPositions,  // number of positions to select in each assignment
      int midsection       
      )
      : RandomProjections (all, length - midsection, numOfPositions), 
         _midsection (midsection)
   {
   }

   MidsectionRandomProjections (  
      int numOfProjections,// num of assignments to generate
      int length,          // length of the assignment to create
      int numOfPositions,  // number of positions to select in each assignment
      int midsection       
      )
      : RandomProjections (numOfProjections, length - midsection, numOfPositions),
         _midsection (midsection)
   {
   }

   virtual const Assignment& getAssignment (
      int index, 
      const Assignment::Position& randPos,
      const Assignment::Position& normalPos) const 
   {
      Assignment& out = const_cast <Assignment&> (
         RandomProjections::getAssignment (index, randPos, normalPos));

      if (_midsection > 0) {
         //
         // now add the midsection
         out.addPositionAt (out.length () / 2, randPos, _midsection);
      }

      return out;
   }

private:
   int _midsection;
};


#endif // _SeedSearcher_RandomProjections_h












