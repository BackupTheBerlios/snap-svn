//
// File        : $RCSfile: $ 
//               $Workfile: FeatureSet.cpp $
// Version     : $Revision: 3 $ 
//               $Author: Aviad $
//               $Date: 12/04/05 0:40 $ 
// Description :
//    Concrete class describing a set of features.
//    contains algorithms for replacing redundant features
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
// and the library authors apply.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "FeatureSet.h"

using namespace seed;

bool FeatureSet::ASymmetricOffsetRedundancyCheck::
   check (  int offset,
            const AssignmentBase& a, const AssignmentBase& b)
{
   debug_mustbe (a.length () == b.length ());
   int length = a.length () - offset;
   SubAssignment suba (a, 0, length);
   SubAssignment subb (a, offset, length);
   return SymmetricRedundancyCheck::check (a, b);
}



bool FeatureSet::SymmetricMaxOffsetRedundancyCheck::
   check (  int maxoffset,
            const AssignmentBase& a, const AssignmentBase& b)
{
   if (a.length() == b.length()) {
      debug_mustbe (maxoffset >= 0);
      debug_mustbe (maxoffset < a.length ());

      //
      // for offset 0 checking similarity between (a,b) or (b,a) is the same
      if (SymmetricRedundancyCheck::check (a, b))
         return true;

      //
      // TODO: is there a better/faster way to do this?
      for (int offset=1 ; offset <= maxoffset ; ++offset) {
         if (  ASymmetricOffsetRedundancyCheck::check (offset, a, b) || 
               ASymmetricOffsetRedundancyCheck::check (offset, b, a)    )
         {
            return true;
         }
      }

      return false;
   }
   else {
      //
      // find out who is longer and who is shorter
      const AssignmentBase* longer, *shorter;
      if (a.length () > b.length ()) { longer = &a; shorter = &b; }
      else { longer = &b; shorter = &a; }
      int llength = longer->length ();
      int slength = shorter->length ();
      int diff =  llength - slength;

      //
      // check similarity one under the other
      for (int i=0 ; i <= diff ; i++) {
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), i, slength);
         if (SymmetricRedundancyCheck::check (assg, *shorter))
            return true;
      }

      {  //
         // check similarity between the short one and the beginning of the long one
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), 0, slength);
         for (int offset=1 ; offset <= maxoffset ; offset++) {
            if (ASymmetricOffsetRedundancyCheck::check (offset, assg, *shorter))
               return true;
         }
      }

      {  //
         // check similarity between the short one and the end of the long one
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), diff, slength);
         for (int offset=1 ; offset <= maxoffset ; offset++) {
            if (ASymmetricOffsetRedundancyCheck::check (offset, *shorter, assg))
               return true;
         }
      }

      return false;
   }
}

//
// returns true if a is better than b
bool FeatureSet::Comparator::a_better_than_b(const Feature& a, const Feature& b) {
	int compare = a.score ()->compare (*b.score ().get ());
	if (compare != 0) return (compare < 0);	// lower scores are better
	else return (a.assignment ().compare (b.assignment()) < 0); // lexicogrphically lower 
}
