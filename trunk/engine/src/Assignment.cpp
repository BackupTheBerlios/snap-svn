//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.cpp $
// Version     : $Revision: 24 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:43 $ 
// Description :
//    Concrete class describing an assignment - 
//       which is a sequence of assignment positions.
//    
//    an assignment position is a subset of the set of all possible
//    letters of a given alphabet.
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
#include "Alphabet.h"

#include "persistance/TextWriter.h"
#include "persistance/StdOutputStream.h"

#include "core/Str.h"

using namespace Persistance;

#define DEBUG_ASSIGNMENT 0

Assignment::Assignment (const Str& data, const AlphabetCode& code)
{
   debug_mustbe (data.length () > 0);
   //
   // make room for the positions
   int l = data.length ();
   _positions.reserve (l);
   for (int i=0 ; i<l ; i++) {
      AlphabetCode::Char c = data.getCharAt (i);
      AlphabetCode::CodedChar cc = code.code (c);
      if (cc == AlphabetCode::notInCode) {
         throw AlphabetCode::UnknownCodeError (c);
      }

      //
      // create a position for each char in the string, 
      // using assg_discrete strategy
      _positions.push_back (AssgPosition (cc, assg_discrete));
   }
}


void Assignment::setPosition (int index, const AssgPosition& p)
{
   if (length () <= index)
      _positions.resize (index +1);

   _positions [index] = p;
}


int AssgPosition::count () const
{
  int count = _bits.count ();

  //
  // the last position (which is the strategy) doesnt count
  if (_bits.test (ASSG_MAX_ALPHABET_SIZE))
     count--;

  return count;
}

//
// returns true iff this position contains all the indexes of the paramter
bool AssgPosition::contains (const AssgPosition& p) const
{
   //
   // if bitwise AND results in a bitset which is equal
   // to the given AssgPosition 'p', then 'this' AssgPosition
   // contains all the flags in 'p'
   //
   // NOTE: we should ignore the strategy bit here
   Bits test (this->_bits);
   test [ASSG_MAX_ALPHABET_SIZE] = true;  // ignore strategies
   test &= p._bits;
   return (test == p._bits);

   /*
   if (p.count () <= count ()) {
      AssgPositionIterator it (p);
      for (; it.hasNext () ; it.next ()) {
         if (!index (it.get ()))
            return false;
      }

      return true;
   }

   return false;
   */
}

bool AssgPosition::equals (const AssgPosition& o) const
{
   return _bits == o._bits;
}

int AssgPosition::compare (const AssgPosition& o)  const
{
   return _bits.to_ulong () - o._bits.to_ulong ();
}


AssgPositionIterator::AssgPositionIterator (const AssgPosition& p) 
: _index (0), _position (p) 
{
  _count = _position.count ();

  if (_count > 0) {
    //
    // now move the index to the first set bit
    while (!_position._bits.test (_index))
      _index++;
  }
}


bool AssignmentBase::contains (const AssignmentBase& o, int startIndex, int cmp_length) const
{
   if (cmp_length != assg_end) 
      mustbe ((cmp_length <= length () - startIndex) && (cmp_length <= o.length () - startIndex));
   else
      mustbe (length () == o.length ());


   bool result = true;
   CIterator it = iterator (startIndex, cmp_length);
   CIterator oit = o.iterator (startIndex, cmp_length);
   for (; it.hasNext () ; oit.next (), it.next ()) {
      if (!it->contains(*oit)) {
         result = false;
         break;
      }
   }

#  if DEBUG_ASSIGNMENT
      DLOG << Format (SubAssignment (o, startIndex)) 
           << (result? " <= " : " !<>! ")
           << Format (SubAssignment (*this, startIndex))
           << DLOG.EOL ();
      DLOG.flush ();
#  endif

/*
   for (int i=startIndex ; i<l ; i++) {
      if (!getPosition (i).contains (o [i])) {
         return false;
      }
   }
*/
   return result;
}

int AssignmentBase::compare (const AssignmentBase& o, int startIndex, int cmp_length) const
{
   int length_diff = length () - o.length ();
   if (length_diff != 0)
      return length_diff;

   CIterator it = iterator (startIndex, cmp_length);
   CIterator oit = o.iterator (startIndex, cmp_length);
   for (; it.hasNext () ; oit.next (), it.next ()) {
      int result = it->compare (*oit);
      if (result != 0)
         return result;
   }
   return 0;
}

bool AssignmentBase::equals (const AssignmentBase& o, int startIndex, int cmp_length) const
{
   if (length () != o.length ())
      return false;
   
   CIterator it = iterator (startIndex, cmp_length);
   CIterator oit = o.iterator (startIndex, cmp_length);
   for (; it.hasNext () ; oit.next (), it.next ()) {
      if (!it->equals (*oit))
         return false;
   }

   /*
   int l =length ();
   for (int i=startIndex ; i<l ; i++) {
      if (!_positions [i].equals (o._positions [i]))
         return false;
   }
   */
   
   return true;
}

void Assignment::addAssignmentAt (int index, const Assignment& assg)
{
	/// will not work correctly if assg references this assignment's positions
	debug_mustbe (dynamic_cast <const void*> (this) != dynamic_cast <const void*> (&assg));
	PositionVector::const_iterator b = assg._positions.begin ();
	PositionVector::const_iterator e = assg._positions.end ();

	PositionVector::iterator i = _positions.begin();
	std::advance (i, index);
	_positions.insert (i, b, e);
}