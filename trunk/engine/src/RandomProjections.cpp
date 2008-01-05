//
// File        : $RCSfile: $ 
//               $Workfile: RandomProjections.cpp $
// Version     : $Revision: 22 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:10 $ 
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

#include "RandomProjections.h"
#include "ExtraMath.h"

#include "legacy/RandomGenerator.h"

#include "DebugLog.h"

#include <assert.h>
#include <iostream>

using namespace std;
using namespace seed;

//
// adapted from pattFind_general.h
template <class T>
inline
ostream & operator<<(ostream & os, const Vec<T>& v) {
  os<<"{ ";
  for (uint i=0;i<v.size();i++)
    os<<v[i]<<" ";
  os<<"} ";
  return os;
}




typedef unsigned int uint;

static int NChooseK (int n, int k)
{
   double tmp = exp( lgamma(n+1)-
		    (lgamma(k+1)+lgamma(n-k+1)) );

   typedef unsigned int uint;
   uint result = ROUND (tmp);


   //
   // make sure this rounding up is valid
   mustbe ( ((double) result) - tmp < 0.25);
   mustbe ( ((double) result) - tmp > -0.25);

   return (int) result;
}

static int createAllProjections (
               RandomProjections::RandomPositionsVector& projectionVec,
               RandomProjections::RandomPositions& chosenPositions,
               int first, int last, int K)
{
   int alreadyChosen = chosenPositions.size ();
   if (alreadyChosen == K) {
      //
      // we have a new projection
      projectionVec.push_back (chosenPositions);
      return 1;
   }

   int projectionsCreated = 0;
   int leftToChoose = K - alreadyChosen;
   int size = last - first + 1 - leftToChoose;
   for (int i=0; i<size ; i++) {
      chosenPositions.push_back (first+i);
      projectionsCreated +=
         createAllProjections (
                           projectionVec,
                           chosenPositions,
                           first + i + 1,
                           last,
                           K);

      chosenPositions.pop_back ();
   }

   return projectionsCreated;
}

//
// Copied/Adapted from legacy SeedSearcher.cpp
static int verifyProjectionNumber(	int motifLength,
												int& inoutDist,
												bool allowOuterWildcards)
{
	if (!allowOuterWildcards) {
		if (motifLength <= 2)
			return 1;

		//make sure we are not asked to many projections:
		// NIR: last position must always be present...
		motifLength--;

		//
		// Aviad: the first position should also never be random...
		// dont allow random positions at the first or last positions in the assignment
		// because it is the same as having a shorter assignment
		motifLength--;
	}

   if (  motifLength < inoutDist) {
      DLOG << "too many wildcards asked, number of wildcards will be only " 
            << motifLength << DLOG.EOL ();

      inoutDist = motifLength;
   }
   

  int result = NChooseK (motifLength, inoutDist);

  /*
   * Aviad: removed the comparison with projNum, just return the number
   * of possible projections
   */

   return result;
}



RandomProjections::RandomProjections (
   All,              // create all possible projections
   int length,          // length of the assignment to create
   int nPositions,   // number of positions to select in each assignment
	bool allowOuterWildcards,
   boost::shared_ptr <Langauge> lang
   )
:  _length (length),
   _numOfPositions (nPositions),
   _langauge (lang)
{
   //
   // first compute how many projections are possible:
   // I am using a function adapted from legacy SeedSearcher here...
   _maxPossibleProjections = 
      verifyProjectionNumber (length, _numOfPositions, allowOuterWildcards);

   RandomPositions chosenPositions;
   createAllProjections (  _vector, chosenPositions, 
									allowOuterWildcards? 0 : 1, 
									allowOuterWildcards? length : length - 1, 
									_numOfPositions);

   debug_mustbe (_vector.size () == _maxPossibleProjections);

   //
   // make room for all the assignments
   _assignments.resize(_vector.size ());
}









static tRandomGenerator rand1;

void RandomProjections::srand (unsigned int seed)
{
   rand1.Initialize (seed);
}


//
// Copied/Adapted from legacy SeedSearcher.cpp
static void chooseProjections (
               size_t motifLength,
               size_t dist,
               size_t projNum,
					bool allowOuterWildcards,
               RandomProjections::RandomPositionsVector& projectionsSites)
{
   projectionsSites.resize(projNum);

   for( size_t i=0; i<projNum; i++)   {
      // this do - while section is used to make sure
      // we don`t randomly select the same to projections...
      bool found;
      do {
         found = false;
         // NIR: w.l.o.g. we don't need to project the last position...
         // Vec<int> val = rand1.sampleGroup( motifLength - 1, dist );
         // Aviad: don`t allow projection in the first position either
			// unless we really need to - for instance when projecting
			// on a known concensus (known motif)
         RandomProjections::RandomPositions val = 
				rand1.sampleGroup( allowOuterWildcards? motifLength : motifLength - 2, dist );

         debug_mustbe (val.size () == dist);
			if (!allowOuterWildcards) {
				//
				// move all positions one index forward
				// this causes no wildcards in the first position
				for (size_t pos=0 ; pos<dist ; pos++)
	            val [pos]++; 
			}
         projectionsSites[i] =  val;
/*
         debug_only (
            cerr<<"found for place "<<i<<"\tprojection\t"<<val<<endl;
         );
*/

         if (dist ==0)
            continue; // if dist ==0 there are no random projections actually

         for (size_t j=0;j<i;j++) {
            if( projectionsSites[j]==val ) {
               //cerr<<"already had that projection in place "<<j<<endl;
               found = true;
               break;
            }
         }

      } while (found == true);
   }
/*
   debug_only (
      // print the projections chosen:
      cerr<<"projection chosen are"<<endl;
      for (uint ii=0;ii<projectionsSites.size();ii++) {
         cerr<<projectionsSites[ii]<<endl;
      }
   );
*/
}



RandomProjections::RandomProjections (
   int numOfProjections,  // create all possible projections
   int length,          // length of the assignment to create
   int nPositions,   // number of positions to select in each assignment
	bool allowOuterWildcards,
   boost::shared_ptr <Langauge> lang
   )
:  _length (length),
   _numOfPositions (nPositions),
   _langauge (lang)

{

   //
   // first compute how many projections are possible:   ( length          )
   _maxPossibleProjections = 
      verifyProjectionNumber (length, _numOfPositions, allowOuterWildcards);

   if (  _maxPossibleProjections < numOfProjections) {
      DLOG << "too many projections asked, number of projections will be only " 
            << _maxPossibleProjections << DLOG.EOL ();
   }

   if (_maxPossibleProjections <= numOfProjections) {
      //
      // just create all the projections possible
      RandomPositions chosenPositions;
      createAllProjections (  _vector, chosenPositions, 
										allowOuterWildcards? 0 : 1, 
										allowOuterWildcards? length : length -1, 
										_numOfPositions);

      debug_mustbe (_vector.size () == _maxPossibleProjections);
   }
   else {
      //
      // create only the required amount of projections
      //
      // the function allowed random in the first position. 
      // fixed it.
      chooseProjections (length, _numOfPositions, numOfProjections, allowOuterWildcards, _vector);
   }

   //
   // make room for all the assignments
   _assignments.resize(_vector.size ());
}


const Assignment& RandomProjections::getAssignment (int index) const
{
   const RandomPositions& rand = _vector[index];

   Assignment* assg = 
      &(const_cast <AssignmentVector&> (_assignments)) [index];

   getBaseAssignment(*assg);
   for (int i=0 ; i<_numOfPositions; i++){
      int pos = rand [i];
      assg->setPosition (pos, _langauge->wildcard (assg_together));
   }

   return *assg;
/*
   debug_only (
      DLOG  << "RandomProjections returned: "
            << Format (assg)
            << DLOG.EOL ()
   );
*/
}

int RandomProjections::numOfProjections (bool exhaustive, 
                                          int requestedProjections,
                                          int length, 
                                          int numOfPositions,
														bool allowOuterPositions)
{
   //
   // first compute how many projections are possible:   ( length          )
   int maxPossibleProjections = 
      verifyProjectionNumber (length, numOfPositions, allowOuterPositions);

   if (exhaustive)
      return maxPossibleProjections;
   else 
      return tmin (maxPossibleProjections, requestedProjections);
}














