#ifndef _SeedSearcher_Assignment_h
#define _SeedSearcher_Assignment_h

#include "Core/Defs.h"
#include "Core/STLHelper.h"
#include "Persistance/Defs.h"
#include <bitset>

class AlphabetCode;

// aA - A
// gG - G
// cC - C
// tT - T
// ?  - random projection - try all posibble combinations, differently
// N  - don't care, anything will do   
//
// an assignment is a string of 
class Assignment {
public:
   
public:
   class Position;
   class PositionIterator;
   
   enum Strategy {
      discrete, // consider all characters discretly (N) 
         together, // consider all characters together (? / random-projection)
   };
   
   enum {
      MAX_ALPHABET_SIZE = 7,
         BITSET_SIZE = MAX_ALPHABET_SIZE + 1 // + 1 is for the strategy
   };
   enum All{
      all
   };
   
   typedef std::bitset <BITSET_SIZE> Bits;


public:
   //
   //
   class Position {
      //
      // NOTE: take care to set/reset only indexes which are meaningfull
      // in the context of a certain Alphabet
   public:
      Position (Strategy s = discrete) {
         strategy (s);
      }
      Position (All, int cardinality, Strategy s = discrete)  {
         //
         // set all bits
         for (int i=0 ; i < cardinality ; i++)
            index (i, true);
         
         strategy (s);
      }
      //
      // sets index i to true
      Position (int i, Strategy s = discrete)   {
         index (i, true);
         strategy (s);
      }
      void strategy (Strategy s) {
         _bits.set (MAX_ALPHABET_SIZE, (s == discrete)? true : false);
      }
      void index (int i, bool b) {
         debug_mustbe (i>=0 && i<=MAX_ALPHABET_SIZE);
         _bits.set (i, b);
      }
      inline Strategy strategy () const {
         return _bits.test (MAX_ALPHABET_SIZE) ? discrete : together;
      }
      inline bool index (int i) const {
         debug_mustbe (i>=0 && i<=MAX_ALPHABET_SIZE);
         return _bits.test (i);
      }
      inline bool empty () const {
         return _bits.count () > 0;
      }
      //
      // returns the number of set indexes
      int count () const;
      //
      // returns true iff this position contains all the indexes of the paramter
      bool contains (const Position&) const;
      bool equals (const Position&) const;
      int compare (const Position&) const;
      
      bool operator == (const Position& o) {
         return this->equals (o);
      }
     
      friend class PositionIterator;
      
   private:
      Bits _bits;
   };
   



   //
   //
   class PositionIterator {
   public:
      PositionIterator (const Position& p);
      bool hasNext () {
         return _count > 0;
      }
      void next () {
         debug_mustbe (_count > 0);
         debug_mustbe (_index < MAX_ALPHABET_SIZE);
         
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
      const Position& _position;
   };

   
public:
   Assignment () {
   }
   Assignment (const Assignment& assg) : _positions (assg._positions) {
   }
   Assignment (const Position& pos, int length) {
      for (int i=0 ; i<length ; i++) {
         addPosition (pos); 
      }
   }
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
   int length () const {
      return _positions.size ();
   }
   void addPosition (const Position& p) {
      _positions.push_back (p);
   }
   void setPosition (int, const Position& p);
   
   int compare (const Assignment&) const;
   bool equals (const Assignment&) const;
   bool operator == (const Assignment& o) const {
      return this->equals (o);
   }
   
   typedef Vec <Position> PositionVector;
      
private:
   PositionVector _positions;
};

#endif // _SeedSearcher_Assignment_h




