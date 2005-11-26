#ifndef _SeedSearcher_SeqWeight_h
#define _SeedSearcher_SeqWeight_h

//
// File        : $RCSfile: $
//               $Workfile: SeqWeight.h $
// Version     : $Revision: 3 $
//               $Author: Aviad $
//               $Date: 10/05/05 12:12 $
// Description :
//    Concrete classes for sequences, sequence positions
//
// Author:
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program.
// for details see http://www.cs.huji.ac.il/~hoan
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors apply.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE

#include "Sequence.h"
#include "core/HashTable.h"
#include "core/AutoPtr.h"
#include <core/STLHelper.h>
#include "boost/shared_ptr.hpp"

#include <map>

class SequenceDB;

struct SeqWeightDB {
/*
   enum {
      _default_db_size = (2 * 3 * 5 * 7 * 11 * 13) + 1 // 30031 prime
   };

   //
   //
   //typedef HashTable<HashTableEntry <Sequence::ID, double> > ID2Weight;
   //typedef HashTable<HashTableEntry <Sequence::Name, double, Str> > Name2Weight;
*/
   class PositionalWeight {
   public:
      //
      //
      struct Entry {
         Entry (short startIndex, short length, double weight) 
         : _startIndex (startIndex), _length (length), _weight (weight)
         {
         }

         short _startIndex;
         short  _length;
         double _weight;
      };

      //
      //
      static bool fitsEntry (const Entry& p, int index) {
         return (index>=p._startIndex) && (index < p._startIndex + p._length);
      }
      //
      // returns true when 
      // an index is equivalent to the Entry if it is in the entry's range
      // if it is not equivalent 
      struct IndexEntryOrder  : public std::binary_function <Entry*, int, bool> {
         bool operator () (const Entry* p, int index) const {
            return (p->_startIndex <= index);
         }
      };

      //
      //
      typedef Vec <Entry*> Positions;
      //
      //
   public:
      PositionalWeight (double weight, const Positions& p)
      : _weight (weight), _positions (p) {
         debug_mustbe (_positions.size () == _positions.capacity ());
      }
      ~PositionalWeight () {
         Positions::iterator it;
         for (it=_positions.begin () ; it!=_positions.end () ; ++it)
            delete *it;
      }
      double getPositionWeight (int index) const;
      inline double getWeight () const {
         return _weight;
      }
/*
      //
      // 
      void initExpectedWeight (int seqLength) {
         int hotspots = 0;
         double expectedWeight = 0;
         Positions::iterator it = _positions.begin ();
         for (; it!=_positions.end (); ++it) {
            Entry& entry = *(*it);
            hotspots += entry._length;
            expectedWeight +=  entry._length * entry._weight;
         }
         expectedWeight += _weight * (seqLength - hotspots);
         expectedWeight = expectedWeight / seqLength;
         _weight = expectedWeight;
      }
*/
   private:
      double _weight;
      Positions _positions;
   };

   typedef boost::shared_ptr <PositionalWeight> PositionalWeight_var;
   typedef std::map <Sequence::ID, PositionalWeight_var> ID2Weight;
   typedef std::map <Sequence::Name, PositionalWeight_var> Name2Weight;

   static AutoPtr <Name2Weight> readWgtFile (const char* weightFileName);
   static AutoPtr <Name2Weight> readWgtFile (std::istream&);
   static AutoPtr <ID2Weight> computeWeightIndex ( const Name2Weight&,
                                                   const SequenceDB&);
};



//
// basic interface for deciding if a sequence is positive / negative
class SeqWeightFunction {
public:
   SeqWeightFunction (boost::shared_ptr <SeqWeightDB::ID2Weight> weight) 
   : _invert (false), _weights (weight)  {
   }
   virtual ~SeqWeightFunction () {
   }

   void invert () {
      _invert = !_invert;
   }
   //
   // for now this is just a call to internalWeight function
   // perhaps it will become a virtual function later
   inline double weight (const SeqPosition& pos, int seedLength) const {
      return internalWeight(pos, seedLength);
   }
   inline double weight (const Sequence::ID& seq) const {
      return internalWeight(seq);
   }
   //
   // returns true iff the weight belongs to the positive or negative set.
   // if so, 'outIsPositive' is set to true iff the weight belongs to the
   // positive set.
   inline bool isRelevant (const Sequence::ID& seq, bool& outIsPositive) const {
      return isRelevant (internalWeight(seq), outIsPositive);
   }
   inline bool isRelevant (double weight, bool& outIsPositive) const {
      bool result =
         isRelevantImpl (weight, outIsPositive);
      if (_invert)
         outIsPositive = ! outIsPositive;
      return result;
   }

   //
   // returns true iff the weight belongs to the positive set
   bool isPositive (double weight) const {
      bool isPositive = false;
      bool res = isRelevant (weight, isPositive);
      return res && isPositive;
   }
   bool isPositive (const Sequence::ID& sequence) const {
      return isPositive (internalWeight(sequence));
   }

   //
   // returns true iff the weight belongs to the negative set
   bool isNegative (double weight) const{
      bool isPositive = false;
      bool res = isRelevant (weight, isPositive);
      return res && (!isPositive);
   }
   bool isNegative (const Sequence::ID& sequence) const {
      return isNegative (internalWeight(sequence));
   }

   //
   // is positive or negative
   bool isRelevant (const Sequence::ID& sequence) const {
      bool unused;
      return isRelevant (internalWeight(sequence), unused);
   }

   typedef SeqWeightDB::ID2Weight DB;
   typedef CIteratorWrapper <DB> CIterator;
   typedef IteratorWrapper <DB> Iterator;
   const DB& getWeightDB () const {
      return *_weights;
   }
   DB& getWeightDB () {
      return *_weights;
   }
   CIterator iterator () const {
      return CIterator (_weights->begin (), _weights->end ());
   }

protected:
   virtual bool isRelevantImpl (double weight, bool& outIsPositive) const = 0;

   double internalWeight (const Sequence::ID& seq) const {
      SeqWeightDB::ID2Weight::iterator it =
         _weights->find(seq);

      if (it != _weights->end ())
         return it->second->getWeight ();
      else {
         mustfail ();
         return 0;
      }
   }
   double internalWeight (const SeqPosition& pos, int seedLength) const {
      SeqWeightDB::ID2Weight::iterator it =
         _weights->find(pos.sequence()->id ());

      if (it != _weights->end ())
         return it->second->getPositionWeight (pos.tssPosition (seedLength));
      else {
         mustfail ();
         return 0;
      }
   }

   bool _invert;
   boost::shared_ptr <SeqWeightDB::ID2Weight> _weights;
};

#endif
