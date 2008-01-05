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
#include "core/STLHelper.h"
#include <boost/shared_ptr.hpp>

#include <map>

namespace seed {

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
         
			///
			/// the weight of the sequence is already factored in to the weight of the position
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
            return (p->_startIndex < index);
         }
         bool operator () (int index, const Entry* p) const {
            return (index < p->_startIndex);
         }
			bool operator () (const Entry* p1, const Entry* p2) const {
				return (p1->_startIndex < p2->_startIndex);
			}
      };

      //
      //
      typedef Vec <Entry*> Positions;

		class Iterator
		{
		public:
			Iterator (const PositionalWeight& parent, int position = 0)
				: _position (0), _parent (parent)
			{
				_it = _parent._positions.begin ();
				if (position > 0)
					advance (position);
			}
			int position () const {
				return _position;
			}
			double weight () const {
				if (weightedPosition ()) {
					/// the position's weight already factors in the weight of the sequence
					double weight = ((*_it)->_weight);
					return weight;
				}
				else {
					return _parent.getWeight ();
				}
			}
				 
			void advance (int offset) {
				debug_mustbe (_position + offset >= 0);
				_position += offset;
				if (!weightedPosition ()) {
					// we have to update the entry iterator
					_it = _parent.find (_position);
				}
			}

			bool weightedPosition () const
			{
				if (_it != _parent._positions.end ())
					return fitsEntry (**_it, _position);

				return false;
			}

		private:
			int _position;
			const PositionalWeight& _parent;
			Positions::const_iterator _it;
		};


      //
      //
   public:
		/// constructor for weights without any positional information
		PositionalWeight (double weight)
			: _weight (weight)
		{
		}

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
		double getAveragePositionWeight (int index, int length) const;
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
		Positions::const_iterator find (int position) const;

   private:
      double _weight;
      Positions _positions;
   };

   typedef boost::shared_ptr <PositionalWeight> PositionalWeight_var;
   
	/// the Sequence ID's are consequetive, and we dont assign an ID to an unused sequence.
	/// this suggests that we can use a vector instead of a map to hold and index
	/// sequences on their ID
	//typedef std::map <Sequence::ID, PositionalWeight_var> ID2Weight;
	typedef std::vector <PositionalWeight_var> ID2Weight;
   typedef std::map <Sequence::Name, PositionalWeight_var> Name2Weight;

   static AutoPtr <Name2Weight> readWgtFromFile (const char* weightFileName);
   static AutoPtr <Name2Weight> readWgtFromStream (std::istream&);
	static AutoPtr <Name2Weight> readWgtFromString (const std::string&);

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
	struct CIterator : public CIteratorWrapper <DB> 
	{
		CIterator (iterator begin, iterator end) 
			: CIteratorWrapper <DB> (begin, end), _begin (begin)
		{
		}
		Sequence::ID id () const {
			return _current - _begin;
		}

	private:
		iterator _begin;
	};

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

   inline double internalWeight (const Sequence::ID& seqID) const {
		debug_mustbe (seqID >= 0);
		debug_mustbe (seqID < static_cast <Sequence::ID> (_weights->size ()));
		return (*_weights) [seqID]->getWeight ();
   }
   double internalWeight (const SeqPosition& pos, int seedLength) const {
		Sequence::ID seqID = pos.sequence ()->id ();
		debug_mustbe (seqID >= 0);
		debug_mustbe (seqID < static_cast <Sequence::ID> (_weights->size ()));

		int posStrandOffsetFromBeginningOfSeq = 
				pos.tssPosition (seedLength, SeqPosition::_offset_from_beginning_);

		return (*_weights) [seqID]->getAveragePositionWeight (posStrandOffsetFromBeginningOfSeq, seedLength);
   }

   bool _invert;
   boost::shared_ptr <SeqWeightDB::ID2Weight> _weights;
};

}

#endif
