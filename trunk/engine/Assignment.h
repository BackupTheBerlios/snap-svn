#ifndef _SeedSearcher_Assignment_h
#define _SeedSearcher_Assignment_h

//
// File        : $RCSfile: $ 
//               $Workfile: Assignment.h $
// Version     : $Revision: 18 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
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
   
   virtual bool contains (const AssignmentBase&, int startIndex = 0) const;
   virtual int compare (const AssignmentBase&, int startIndex = 0) const;
   virtual bool equals (const AssignmentBase&, int startIndex = 0) const;
   bool operator == (const AssignmentBase& o) const {
      return this->equals (o);
   }

   //
   // beginning to the end, respectively
   virtual Iterator iterator (  int begin = 0, int length = assg_end) = 0;
   virtual CIterator iterator ( int begin = 0, int length = assg_end) const = 0;
};


// aA - A
// gG - G
// cC - C
// tT - T
// ? - random projection - try all posibble combinations, differently
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
   }
   Assignment (const Assignment& assg) : _positions (assg._positions) {
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

   void unify (const Assignment& o, int startIndex = 0) ;

   //
   // beginning to the end, respectively
   virtual Iterator iterator (int begin = 0, int length = assg_end) {
      Iterator it (_positions.begin (), _positions.end ());
      if (begin > 0) it.next (begin);
      if (length != assg_end) it.allowNext (length);
      return it;
   }
   virtual CIterator iterator (int begin = 0, int length = assg_end) const {
      CIterator it (_positions.begin (), _positions.end ());
      if (begin > 0) it.next (begin);
      if (length != assg_end) it.allowNext (length);
      return it;
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
   virtual bool contains (const AssignmentBase& in, int startIndex = 0) const {
      return _assg.contains (in, _begin + startIndex);
   }
   virtual int compare (const AssignmentBase& in, int startIndex = 0) const {
      return _assg.compare(in, _begin + startIndex);
   }
   virtual bool equals (const AssignmentBase& in, int startIndex = 0) const {
      return _assg.equals (in, _begin + startIndex);
   }

   //
   // beginning to the end, respectively
   virtual Iterator iterator (  int begin = 0, int length = assg_end) {
      mustbe (!_const);
      return _assg.iterator (begin + _begin, length);
   }
   virtual CIterator iterator ( int begin = 0, int length = assg_end) const {
      return static_cast <const Assignment&> (_assg).iterator (begin + _begin, length);
   }

private:
   AssignmentBase& _assg;
   int _begin;
   int _length;
   bool _const;
};

#endif // _SeedSearcher_Assignment_h















