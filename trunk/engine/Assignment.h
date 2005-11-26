#ifndef _SeedSearcher_Assignment_h
#define _SeedSearcher_Assignment_h

//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.h $
// Version     : $Revision: 22 $ 
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

#include "core/Defs.h"
#include "core/STLHelper.h"
#include "persistance/Defs.h"

#include <bitset>


class Str;
class AlphabetCode;
class AssgPosition;
class AssgPositionIterator;


//
//
enum AssgStrategy {
   assg_discrete, // consider all characters discretly (N) 
   assg_together, // consider all characters assg_together (? / random-projection)
};

enum {
   ASSG_MAX_ALPHABET_SIZE = 7,
   ASSG_BITSET_SIZE = ASSG_MAX_ALPHABET_SIZE + 1 // + 1 is for the strategy
};


//
//
class AssgPosition {
   //
   // NOTE: take care to set/reset only indexes which are meaningfull
   // in the context of a certain Alphabet
public:
   enum All{
      all
   };  
   typedef std::bitset <ASSG_BITSET_SIZE> Bits;

public:
   AssgPosition (AssgStrategy s = assg_discrete) {
      strategy (s);
   }
   AssgPosition (All, int cardinality, AssgStrategy s = assg_discrete)  {
      //
      // set all bits
      for (int i=0 ; i < cardinality ; i++)
         index (i, true);
      
      strategy (s);
   }
   //
   // sets index i to true
   AssgPosition (int i, AssgStrategy s = assg_discrete)   {
      index (i, true);
      strategy (s);
   }
   void strategy (AssgStrategy s) {
      _bits.set (ASSG_MAX_ALPHABET_SIZE, (s == assg_discrete)? true : false);
   }
   void index (int i, bool b) {
      debug_mustbe (i>=0 && i<=ASSG_MAX_ALPHABET_SIZE);
      _bits.set (i, b);
   }
   inline AssgStrategy strategy () const {
      return _bits.test (ASSG_MAX_ALPHABET_SIZE) ? assg_discrete : assg_together;
   }
   inline bool index (int i) const {
      debug_mustbe (i>=0 && i<=ASSG_MAX_ALPHABET_SIZE);
      return _bits.test (i);
   }
   inline bool empty () const {
      return _bits.count () > 0;
   }
   //
   // returns the number of set indexes
   int count () const;

   //
   // does not affect strategy
   void unify (const AssgPosition& o) {
      AssgStrategy s = strategy ();
      _bits |= o._bits;
      strategy (s);
   }

   //
   //
   unsigned long toULong () const {
      unsigned long l = _bits.to_ulong ();
      //
      // remove the strategy bit
      return (l & (~(0x1 << ASSG_MAX_ALPHABET_SIZE)));
   }

   //
   // returns true iff this position contains all the indexes of the paramter
   bool contains (const AssgPosition&) const;
   bool equals (const AssgPosition&) const;
   int compare (const AssgPosition&) const;
   
   bool operator == (const AssgPosition& o) {
      return this->equals (o);
   }
   AssgPosition& operator = (const AssgPosition& o) {
      _bits = o._bits;
      return *this;
   }
   void set(const AssgPosition& o) {
      _bits = o._bits;
   }
   
   friend class AssgPositionIterator;
   
private:
   Bits _bits;
};
   




//
//
class AssgPositionIterator {
public:
   AssgPositionIterator (const AssgPosition& p);
   bool hasNext () {
      return _count > 0;
   }
   void next () {
      debug_mustbe (_count > 0);
      debug_mustbe (_index < ASSG_MAX_ALPHABET_SIZE);
      
      if (--_count > 0)
         while (!_position._bits.test (++_index));
   }
   //
   // returns the index of the next set bit
   int get () {
      return _index;
   }
   
private:
   int _count;
   int _index;
   const AssgPosition& _position;
};



class AssignmentBase {
public:
   typedef Vec <AssgPosition> PositionVector;
   typedef IteratorWrapper <PositionVector> Iterator;
   typedef CIteratorWrapper <PositionVector> CIterator;

   enum {
      assg_end = -1
   };

public:
   virtual ~AssignmentBase () {
   }
   inline AssgPosition& operator [] (int index) {
      return getPosition (index);
   }
   inline const AssgPosition& operator [] (int index) const {
      return getPosition (index);
   }
   virtual AssgPosition& getPosition (int index) = 0;
   virtual const AssgPosition& getPosition (int index) const = 0;

   virtual int length () const = 0;
   
   virtual bool contains (const AssignmentBase&, int startIndex = 0, int length = assg_end) const;
   virtual int compare (const AssignmentBase&, int startIndex = 0, int length = assg_end) const;
   virtual bool equals (const AssignmentBase&, int startIndex = 0, int length = assg_end) const;
   bool operator == (const AssignmentBase& o) const {
      return this->equals (o);
   }

   //
   // beginning to the end, respectively
   virtual Iterator iterator (  int begin = 0, int length = assg_end) = 0;
   virtual CIterator iterator ( int begin = 0, int length = assg_end) const = 0;

   //
   //
   void unify (const AssignmentBase& o, int startIndex = 0, int inLength = assg_end) {
      int oLength = (inLength == assg_end)? o.length () : inLength;
      if (length () < oLength) {
         resize (oLength);
      }
      
      Iterator it = iterator(startIndex, oLength);
      CIterator oit = o.iterator(startIndex, oLength);
      for (; it.hasNext () ; it.next (), oit.next ()) {
         debug_mustbe (oit.hasNext ());
         it->unify (*oit);
      }
   }
   //
   // inserts or erases AssgPositions at the end of the assignment
   virtual void resize (int length)=0;

   //
   // erases AssgPositions
   virtual void erase (int length, int position = assg_end) =0;
   //
   //
   virtual void insert (int length, int position = assg_end, 
                        const AssgPosition& p = AssgPosition ()) = 0;

   virtual void set (const AssignmentBase& o) {
      int l = o.length ();
      if (l != length ())
         resize (l);

      Iterator it (iterator ());
      CIterator oit (o.iterator ());
      for (; it.hasNext () ; it.next (), oit.next ()) {
         debug_mustbe (oit.hasNext ());
         it->set (*oit);
      }
   }
};


// aA - A
// gG - G
// cC - C
// tT - T
// ? - random projection - try all possible combinations, differently
// N  - don't care, anything will do   
//
// an assignment is a string of 
class Assignment : public AssignmentBase {
public:
   //
   //
   typedef AssgPosition Position;
   typedef AssgPositionIterator PositionIterator;
   typedef AssgStrategy Strategy;
   
public:
   Assignment () {
      //
      // this is a good upper bound on most assignments
      // this pre-allocation boosts performance
      _positions.reserve(20);
   }
   Assignment (const Assignment& assg) : _positions (assg._positions) {
   }
   Assignment (const AssignmentBase& assg) {
      _positions.reserve(assg.length());
      for (CIterator it = assg.iterator (); it.hasNext () ; it.next ()) {
         _positions.push_back (*it);
      }
   }
   Assignment (const Position& pos, int length) {
      _positions.reserve (length);
      for (int i=0 ; i<length ; i++) {
         addPosition (pos); 
      }
   }
   //
   // create assignment from a string and the alphabet that codes the string
   Assignment::Assignment (const Str&, const AlphabetCode&);

   Assignment& operator = (const Assignment& o) {
      _positions = o._positions;
      return *this;
   }
   bool specialize (const AssignmentBase& assg, const AssignmentBase& projection) {
      //
      //
      debug_mustbe (assg.length() == projection.length());
      _positions.clear ();
      _positions.reserve(projection.length());

      CIterator assgIt (assg.iterator());
      CIterator projIt (projection.iterator());
      for (; projIt.hasNext () ; projIt.next (), assgIt.next()) {
         if (projIt->contains (*assgIt)) {
            debug_mustbe (assgIt.hasNext());
            if (projIt->strategy () == assg_together)
               addPosition(*projIt);
            else
               addPosition(*assgIt);
         }
         else {
            return false;
         }
      }
      return true;
   }
   inline Position& operator [] (int index) {
      return _positions [index];
   }
   inline const Position& operator [] (int index) const {
      return _positions [index];
   }
   virtual Position& getPosition (int index) {
      return _positions [index];
   }
   virtual const AssgPosition& getPosition (int index) const {
      return _positions [index];
   }
   virtual int length () const {
      return _positions.size ();
   }
   void addPosition (const Position& p) {
      _positions.push_back (p);
   }
   void addPositionAt (int index, const Position& p, int count = 1) {
      _positions.insert (_positions.begin() + index, count, p);
   }
   void addAssignmentAt (int index, const Assignment& assg) {
      _positions.insert (  _positions.begin() + index, 
                           assg._positions.begin (), 
                           assg._positions.end ());
   }

   void setPosition (int, const Position& p);

   //
   // beginning to the end, respectively
   virtual Iterator iterator (int begin = 0, int length = assg_end) {
      if (begin >= 0) {
         Iterator it (_positions.begin () + begin, _positions.end ());
         if (length != assg_end) it.allowNext (length);
         return it;
      }
      else {
         return Iterator (_positions.end (), _positions.end ()); 
      }
   }
   virtual CIterator iterator (int begin = 0, int length = assg_end) const {
      if (begin >= 0) {
         CIterator it (_positions.begin () + begin, _positions.end ());
         if (length != assg_end) it.allowNext (length);
         return it;
      }
      else {
         return CIterator (_positions.end (), _positions.end ()); 
      }
   }
   //
   //
   virtual void resize (int length) {
      _positions.resize (length);
   }
   //
   //
   virtual void erase (int length, int position = assg_end) {
      if (position == assg_end) {
         _positions.resize (_positions.size () - length);
      }
      else {
         _positions.erase(_positions.begin () + position, _positions.begin() + length);
      }
   }
   //
   //
   virtual void insert (int length, int position = assg_end, 
      const AssgPosition& p = AssgPosition ()){
         PositionVector::iterator loc = (position = assg_end)?
            _positions.end () : _positions.begin () + position;

      _positions.insert (loc, length, p);
   }
      
private:
   PositionVector _positions;
};


//
// this class is used to view a continous-subpart of an assignment
class SubAssignment : public AssignmentBase {
public:
   //
   // non-const ctors
   SubAssignment (AssignmentBase& in, int begin, int length) 
      : _assg (in), _begin (begin), _length (length), _const (false) {
   }
   SubAssignment (AssignmentBase& in, int begin) 
      : _assg (in), _begin (begin), _length (in.length () - begin), _const (false) {
   }

   //
   // const ctors
   SubAssignment (const AssignmentBase& in, int begin, int length) 
      :  _assg (const_cast <AssignmentBase&> (in)), 
         _begin (begin), 
         _length (length), 
         _const (true) {
   }
   SubAssignment (const AssignmentBase& in, int begin) 
      :  _assg (const_cast <AssignmentBase&> (in)), 
         _begin (begin), 
         _length (in.length () - begin), 
         _const (true) {
   }

   virtual AssgPosition& getPosition (int index) {
      mustbe (index < _length);
      mustbe (!_const);
      return _assg.getPosition (_begin + index);
   }
   virtual const AssgPosition& getPosition (int index) const {
      mustbe (index < _length);
      return _assg.getPosition (_begin + index);
   }
   virtual int length () const {
      return _length;
   }
   virtual bool contains (const AssignmentBase& in, int startIndex = 0, int cmp_length = assg_end) const {
      debug_mustbe (length () == in.length ());
      return _assg.contains (in, startIndex, (cmp_length == assg_end)? _length : cmp_length);
   }
   virtual int compare (const AssignmentBase& in, int startIndex = 0, int cmp_length = assg_end) const {
      debug_mustbe (length () == in.length ());
      return _assg.compare(in, startIndex, (cmp_length == assg_end)? _length : cmp_length);
   }
   virtual bool equals (const AssignmentBase& in, int startIndex = 0, int cmp_length = assg_end) const {
      debug_mustbe (length () == in.length ());
      return _assg.equals (in, startIndex, (cmp_length == assg_end)? _length : cmp_length);
   }

   //
   // beginning to the end, respectively
   virtual Iterator iterator (  int begin = 0, int length = assg_end) {
      mustbe (!_const);
      return _assg.iterator (_begin + begin, (length == assg_end)? _length : length);
   }
   virtual CIterator iterator ( int begin = 0, int length = assg_end) const {
      return static_cast <const Assignment&> (_assg).iterator (
         _begin + begin, 
         (length == assg_end)? _length : length)
      ;
   }
   //
   //
   virtual void resize (int inLength) {
      if (_length < inLength) {
         _assg.insert (inLength - _length, _begin);
         _length = inLength;
      }
      else if (_length > inLength){
         _assg.erase (inLength - _length);
      }
   }
   //
   // erases AssgPositions
   virtual void erase (int inLength, int inPosition = assg_end) {
      debug_mustbe (inPosition < _length);

      int pos = (inPosition == assg_end)? 
         _begin + _length - inLength : _begin + inPosition;

      _assg.erase (inLength, pos);
      _length -= inLength;
   }
   //
   //
   virtual void insert (int inLength, int inPosition = assg_end, 
                        const AssgPosition& p = AssgPosition ()) {
      debug_mustbe (inPosition < _length);

      int pos = (inPosition == assg_end)? 
         _begin + _length: _begin + inPosition;

      _assg.insert (inLength, pos, p);
      _length += inLength;
   }

private:
   AssignmentBase& _assg;
   int _begin;
   int _length;
   bool _const;
};

#endif // _SeedSearcher_Assignment_h


