/*
 * Author: Aviad Rozenhek
 */

#include "RandomProjections.h"
#include "ExtraMath.h"

#include "Legacy/RandomGenerator.h"

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



inline static void createAllProjections (
                  RandomProjections::RandomPositionsVector& positions,
                  int& index,
                  int startingPos, 
                  int endPos, 
                  int numOfPositions
                  )
{
   if (numOfPositions == 0)
      return;

   for (int i = startingPos ; i < endPos ; i++) {
      positions [index].push_back (i);
      createAllProjections (positions,
                           index,
                           i+1,
                           endPos,
                           numOfPositions-1);
      index++;
   }
}


//
// Copied/Adapted from legacy SeedSearcher.cpp
static int verifyProjectionNumber( int motifLength,
					 int dist /*,
					 int projNum */
                )
{
   //make sure we are not asked to many projections:
   // NIR: last position must always be present...
   motifLength--;

   //
   // Aviad: TODO: the first position should also never be random...
   // dont allow random positions at the first or last positions in the assignment
   // because it is the same as having a shorter assignment
   motifLength--;

  assert(dist<motifLength);
  double tmp = exp( lgamma(motifLength+1)-
		    (lgamma(dist+1)+lgamma(motifLength-dist+1)) );
  
  //  uint possibleProjections = ( (tmp - ((int)tmp)) > 0) ? (int) (tmp+1) : (int)tmp; 

  typedef unsigned int uint;
  uint possibleProjections = (int)tmp;   
  /*
   * Aviad: removed the comparison with projNum, just return the number
   * of possible projections

  debug_only (
    if (  possibleProjections < static_cast<uint>(projNum)) 
      cerr<<string("too many projections asked, number of porjections will be only ") + (int)possibleProjections<<endl;
  );

   if( ((int)projNum) < ((int)possibleProjections) )
      return projNum;
   else
   *
   */
      return (int)possibleProjections;
}



RandomProjections::RandomProjections (
   All,              // create all possible projections
   int cardinality,  // length of the Assignment to create;
   int length,          // length of the assignment to create
   int numOfPositions   // number of positions to select in each assignment
   )
:  _cardinality (cardinality),
   _length (length),
   _numOfPositions (numOfPositions)
{
   //
   // first compute how many projections are possible:
   // I am using a function adapted from legacy SeedSearcher here...
   int numOfProjections = 
      verifyProjectionNumber (length, numOfPositions);

   //
   // expand the vector to the required size
   _vector.resize (numOfProjections);

   int index = 0;
   createAllProjections (_vector, index, 1, length -1, numOfProjections);
}









static tRandomGenerator rand1;

//
// Copied/Adapted from legacy SeedSearcher.cpp
static void chooseProjections (int motifLength,
				      int dist,
				      int projNum ,
				      Vec<Vec<int> >  & projectionsSites)
{
   projectionsSites.resize(projNum);

   for( int i=0; i<projNum; i++)   {
      // this do - while section is used to make sure
      // we dont randomly select the same to projections...
      bool found;
      do {
         found = false;
         // NIR: wlog we don't need to project the last position...
         // Vec<int> val = rand1.sampleGroup( motifLength - 1, dist );
         // Aviad: dont allow projection in the first position either
         Vec<int> val = rand1.sampleGroup( motifLength - 2, dist );
         debug_mustbe (val.size () == dist);
         for (int pos=0 ; pos<dist ; pos++)
            val [pos]++; 


         projectionsSites[i] =  val;

         debug_only (
            cerr<<"found for place "<<i<<"\tprojection\t"<<val<<endl;
         );

         if (dist ==0)
            continue; // if dist ==0 there are no random projections actually

         for (int j=0;j<i;j++) {
            if( projectionsSites[j]==val ) {
               //cerr<<"already had that projection in place "<<j<<endl;
               found = true;
               break;
            }
         }

      } while (found == true);
   }

   debug_only (
      // print the projections chosen:
      cerr<<"projection chosen are"<<endl;
      for (uint ii=0;ii<projectionsSites.size();ii++) {
         cerr<<projectionsSites[ii]<<endl;
      }
   );
}



RandomProjections::RandomProjections (
   int numOfProjections,  // create all possible projections
   int cardinality,        // length of the Assignment to create;
   int length,          // length of the assignment to create
   int numOfPositions   // number of positions to select in each assignment
   )
:  _cardinality (cardinality),
   _length (length),
   _numOfPositions (numOfPositions)

{
   //
   // first compute how many projections are possible:   ( length          )
   int possibleProjections = 
      verifyProjectionNumber (length, numOfPositions);

   debug_only (
      if (  possibleProjections < numOfProjections) 
         cerr<< "too many projections asked, number of porjections will be only " << possibleProjections << endl;
   );

   if (possibleProjections < numOfProjections) {
      //
      // just create all the projections possible
      _vector.resize (possibleProjections);

      int index = 0;
      createAllProjections (_vector, index, 1, length -1, possibleProjections);
   }
   else {
      //
      // create only the required amount of projections
      //
      // the function allowed random in the first position. 
      // fixed it.
      chooseProjections (length, numOfPositions, numOfProjections, _vector);
   }
}

void RandomProjections::getAssignment (int index, Assignment& assg) const
{
   const RandomPositions& rand = _vector[index];

   assg = Assignment (Assignment::all, _length, _cardinality, Assignment::discrete);
   for (int i=0 ; i<_numOfPositions; i++){
      assg [i].strategy (Assignment::together);
   }

   debug_only (
      std::cerr << "RandomProjections returned: " << assg << endl;
      )
}

Assignment RandomProjections::getAssignment (int index) const
{
   const RandomPositions& rand = _vector[index];

   Assignment assg (Assignment::all, _length, _cardinality, Assignment::discrete);
   for (int i=0 ; i<_numOfPositions; i++){
      assg [rand[i]].strategy (Assignment::together);
   }
   
   debug_only (
      std::cerr << "RandomProjections returned: " << assg << endl;
      )

   return assg;
}
