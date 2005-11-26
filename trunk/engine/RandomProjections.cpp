/*
 * Author: Aviad Rozenhek
 */

#include "RandomProjections.h"
#include "ExtraMath.h"

#include "Legacy/RandomGenerator.h"

#include "DebugLog.h"

#include <assert.h>
#include <iostream>

using namespace std;

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
static int verifyProjectionNumber( int motifLength,
					 int dist
                )
{
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

  assert(dist<=motifLength);
  int result = NChooseK (motifLength, dist);

  /*
   * Aviad: removed the comparison with projNum, just return the number
   * of possible projections
   */

   return result;
}



RandomProjections::RandomProjections (
   All,              // create all possible projections
   int length,          // length of the assignment to create
   int numOfPositions   // number of positions to select in each assignment
   )
:_length (length),
 _numOfPositions (numOfPositions)
{
   //
   // first compute how many projections are possible:
   // I am using a function adapted from legacy SeedSearcher here...
   _maxPossibleProjections = 
      verifyProjectionNumber (length, numOfPositions);

   RandomPositions chosenPositions;
   createAllProjections (  _vector, chosenPositions, 
                           1, length -1, numOfPositions);

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
               size_t projNum ,
               RandomProjections::RandomPositionsVector& projectionsSites)
{
   projectionsSites.resize(projNum);

   for( size_t i=0; i<projNum; i++)   {
      // this do - while section is used to make sure
      // we dont randomly select the same to projections...
      bool found;
      do {
         found = false;
         // NIR: wlog we don't need to project the last position...
         // Vec<int> val = rand1.sampleGroup( motifLength - 1, dist );
         // Aviad: dont allow projection in the first position either
         RandomProjections::RandomPositions val = 
            rand1.sampleGroup( motifLength - 2, dist );

         debug_mustbe (val.size () == dist);
         for (size_t pos=0 ; pos<dist ; pos++)
            val [pos]++; 


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
   int numOfPositions   // number of positions to select in each assignment
   )
:_length (length),
 _numOfPositions (numOfPositions)

{
   //
   // first compute how many projections are possible:   ( length          )
   _maxPossibleProjections = 
      verifyProjectionNumber (length, numOfPositions);

   debug_only (
      if (  _maxPossibleProjections < numOfProjections) 
         DLOG << "too many projections asked, number of projections will be only " 
              << _maxPossibleProjections << DLOG.EOL ();
   );

   if (_maxPossibleProjections <= numOfProjections) {
      //
      // just create all the projections possible
      RandomPositions chosenPositions;
      createAllProjections (  _vector, chosenPositions, 
                              1, length -1, numOfPositions);

      debug_mustbe (_vector.size () == _maxPossibleProjections);
   }
   else {
      //
      // create only the required amount of projections
      //
      // the function allowed random in the first position. 
      // fixed it.
      chooseProjections (length, numOfPositions, numOfProjections, _vector);
   }

   //
   // make room for all the assignments
   _assignments.resize(_vector.size ());
}

const Assignment& RandomProjections::getAssignment (int index, 
                                 const Assignment::Position& randPos,
                                 const Assignment::Position& normalPos) const
{
   const RandomPositions& rand = _vector[index];

   Assignment* assg = 
      &(const_cast <AssignmentVector&> (_assignments)) [index];

   *assg = Assignment (normalPos, _length);
   for (int i=0 ; i<_numOfPositions; i++){
      int pos = rand [i];
      assg->setPosition (pos, randPos);
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













