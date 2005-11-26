#include "Assignment.h"

#include "Persistance/TextWriter.h"

#include "Alphabet.h"
#include "Persistance/StdOutputStream.h"
using namespace Persistance;


void Assignment::setPosition (int index, const Position& p)
{
   if (_positions.size () <= index)
      _positions.resize (index +1);

   _positions [index] = p;
}

bool Assignment::equals (const Assignment& o) 
{
   if (length () != o.length ())
      return false;

   int l =length ();
   for (int i=0 ; i<l ; i++) {
      if (!_positions [i].equals (o._positions [i]))
         return false;
   }

   return true;
}

Persistance::TextWriter& 
Assignment::write (Persistance::TextWriter& writer, 
                   const AlphabetCode& code) const
{
   for (int i=0 ; i < length () ; i++)
      this->operator [] (i).write (writer, code);

   return writer;
}
std::ostream& operator << (std::ostream& out, const Assignment& a)
{
   AlphabetCode code (AlphabetCode::emptyCode (), 0);
   TextWriter writer (new StdOutputStream (out));
   a.write (writer, code);
   return out;
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
bool Assignment::Position::contains (const Position& p)
{
   if (p.count () < count ()) {
      PositionIterator it (p);
      for (; it.hasNext () ; it.next ()) {
         if (!index (it.get ()))
            return false;
      }

      return true;
   }

   return false;
}

bool Assignment::Position::equals (const Position& o) 
{
   return _bits == o._bits;
}

Persistance::TextWriter& 
Assignment::Position::write (Persistance::TextWriter& writer, 
                   const AlphabetCode& code) const
{
   //
   // TODO: make this general
   char ACGT [] = "ACGT";
   
   int c = count ();
   if (c == 0)
      writer << "-";
   else if (c == 1) {
      PositionIterator it (*this);
      writer << ACGT [it.get ()];
   }
   else if (strategy ()== together)
      writer << '?';
   else
      writer << 'N';

   return writer;
}


std::ostream& operator << (const Assignment::Position& p, 
                                                 std::ostream& out) 
{
   AlphabetCode code (AlphabetCode::emptyCode (), 0);
   TextWriter writer (new StdOutputStream (out));
   p.write (writer, code);
   return out;
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

 
