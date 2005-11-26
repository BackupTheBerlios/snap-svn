#include "Assignment.h"
#include "Alphabet.h"

#include "Persistance/TextWriter.h"
#include "Persistance/StdOutputStream.h"

#include "Core/Str.h"

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
      //
      // create a position for each char in the string, 
      // using discrete strategy
      _positions.push_back (Position (cc, discrete));
   }
}


void Assignment::setPosition (int index, const Position& p)
{
   if (length () <= index)
      _positions.resize (index +1);

   _positions [index] = p;
}

#include "DebugLog.h"

void Assignment::unify (const Assignment& o, int startIndex)  
{
#if DEBUG_ASSIGNMENT
   DLOG  << "unifying " << Format (*this) 
         << " with " << Format (o) << DLOG.EOL ();
#endif

   size_t length = o.length ();
   if (_positions.size () < length) {
      _positions.resize (length);
   }

   for (size_t i=startIndex ; i<length ; i++) {
      Position& my_pos = getPosition (i);
      const Position& o_pos = o.getPosition (i);

#if DEBUG_ASSIGNMENT
         if ((!my_pos.empty ()) && my_pos.strategy () == discrete) {
            if (!my_pos.contains (o_pos)) {
               DLOG  << "unifying " << Format (*this) 
                     << " with " << Format (o) << DLOG.EOL ();
               DLOG.flush ();
               debug_mustfail ();
            }
         }
#endif

      my_pos.unify (o_pos);
   }
}

bool Assignment::contains (const Assignment& o, int startIndex) const
{
   int l = length ();
   debug_mustbe (length () == o.length ());
   for (int i=startIndex ; i<l ; i++) {
      if (!getPosition (i).contains (o [i])) {
         return false;
      }
   }

   return true;
}

bool Assignment::equals (const Assignment& o, int startIndex)  const
{
   if (length () != o.length ())
      return false;

   int l =length ();
   for (int i=startIndex ; i<l ; i++) {
      if (!_positions [i].equals (o._positions [i]))
         return false;
   }

   return true;
}

int Assignment::compare (const Assignment& o, int startIndex)  const
{
   int length_diff = length () < o.length ();
   if (length_diff != 0)
      return length_diff;

   int l = length ();
   for (int i= startIndex ; i<l ; i++) {
      int result = _positions [i].compare (o._positions [i]);
      if (result != 0)
         return result;
   }

   return 0;
}

int Assignment::Position::count () const
{
  int count = _bits.count ();

  //
  // the last position (which is the strategy) doesnt count
  if (_bits.test (MAX_ALPHABET_SIZE))
     count--;

  return count;
}

//
// returns true iff this position contains all the indexes of the paramter
bool Assignment::Position::contains (const Position& p) const
{
   if (p.count () <= count ()) {
      PositionIterator it (p);
      for (; it.hasNext () ; it.next ()) {
         if (!index (it.get ()))
            return false;
      }

      return true;
   }

   return false;
}

bool Assignment::Position::equals (const Position& o) const
{
   return _bits == o._bits;
}

int Assignment::Position::compare (const Assignment::Position& o)  const
{
   return _bits.to_ulong () - o._bits.to_ulong ();
}


Assignment::PositionIterator::PositionIterator (const Position& p) 
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

 













