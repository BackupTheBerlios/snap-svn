#ifndef _SeedSearcher_RandomProjections_h
#define _SeedSearcher_RandomProjections_h

//
// File        : $RCSfile: $ 
//               $Workfile: RandomProjections.h $
// Version     : $Revision: 16 $ 
//               $Author: Aviad $
//               $Date: 13/10/04 3:33 $ 
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
#include "AssignmentFormat.h"
#include <boost/shared_ptr.hpp>

class ProjectionGenerator {
public:
   virtual ~ProjectionGenerator () {
   }

   virtual const Assignment& getAssignment (int index) const = 0;

   virtual int numOfProjections () const = 0;
};

class RandomProjections : public ProjectionGenerator {
public:
   enum All {
      all
   };
   
   RandomProjections (  All,              // create all possible projections
                        int length,          // length of the assignment to create
                        int numOfPositions,  // number of positions to select in each assignment
                        boost::shared_ptr <Langauge>
                        );

   RandomProjections (  int numOfProjections,// num of assignments to generate
                        int length,          // length of the assignment to create
                        int numOfPositions,  // number of positions to select in each assignment
                        boost::shared_ptr <Langauge>
                        );

   RandomProjections (  int numOfProjections,   // num of assignments to generate
                        const Assignment& base, // background assignment on which to project
                        int numOfPositions,     // number of positions to select in each assignment
                        boost::shared_ptr <Langauge>
                     );

   virtual ~RandomProjections () {
   }

   //
   // returns how many different projections actually created
   virtual int numOfProjections () const {
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

   virtual const Assignment& getAssignment (int index) const;

   typedef Vec <int> RandomPositions;
   typedef Vec <RandomPositions> RandomPositionsVector;
   typedef Vec <Assignment> AssignmentVector;

   static void srand (unsigned int seed);

protected:
   virtual const Assignment& getBaseAssignment (Assignment& outBase) const {
      outBase = Assignment (_langauge->wildcard (assg_discrete), _length);
      return outBase;
   }

protected:
   Assignment _base;
   int _length;
   int _numOfPositions;
   int _maxPossibleProjections;
   RandomPositionsVector _vector;
   AssignmentVector _assignments;
   boost::shared_ptr <Langauge> _langauge;
};

//
// random projections with a midsection of wildcards
class MidsectionRandomProjections : public RandomProjections {
public:
   MidsectionRandomProjections (  
      All,              // create all possible projections
      int length,          // length of the assignment to create
      int numOfPositions,  // number of positions to select in each assignment
      int midsection,
      boost::shared_ptr <Langauge> lang
      )
      : RandomProjections (all, length - midsection, numOfPositions, lang), 
         _midsection (midsection)
   {
   }

   MidsectionRandomProjections (  
      int numOfProjections,// num of assignments to generate
      int length,          // length of the assignment to create
      int numOfPositions,  // number of positions to select in each assignment
      int midsection,
      boost::shared_ptr <Langauge> lang
      )
      : RandomProjections (numOfProjections, 
                           length - midsection, 
                           numOfPositions, 
                           lang),
         _midsection (midsection)
   {
   }

   virtual const Assignment& getAssignment (int index) const {
      Assignment& out = const_cast <Assignment&> (
         RandomProjections::getAssignment (index));

      if (_midsection > 0) {
         //
         // now add the midsection
         out.addPositionAt (  out.length () / 2, 
                              _langauge->wildcard (assg_together), 
                              _midsection);
      }

      return out;
   }

private:
   int _midsection;
};

class SpecificProjectionGenerator : public RandomProjections {
public:
   SpecificProjectionGenerator (  
      All,              // create all possible projections
      const Str& base,     // base assignment on which to project
      int numOfPositions,  // number of positions to select in each assignment
      boost::shared_ptr <Langauge> lang
      )
      : RandomProjections (   all, 
                              base.length (), 
                              numOfPositions, 
                              lang) 
   {
      _langauge->stringToAssignment (_base, base);
   }

   SpecificProjectionGenerator (  
      int numOfProjections,// num of assignments to generate
      const Str& base,     // base assignment on which to project
      int numOfPositions,  // number of positions to select in each assignment
      boost::shared_ptr <Langauge> lang
      )
      : RandomProjections (   numOfProjections, 
                              base.length (), 
                              numOfPositions, 
                              lang)
   {
      _langauge->stringToAssignment (_base, base);
   }
   virtual ~SpecificProjectionGenerator () {
   }

protected:
   virtual const Assignment& getBaseAssignment (Assignment& outBase) const {
      outBase = _base;
      return outBase;
   }

protected:
   Assignment _base;
};


#endif // _SeedSearcher_RandomProjections_h





