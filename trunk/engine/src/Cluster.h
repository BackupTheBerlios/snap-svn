#ifndef _SeedSearcher_Cluster_h
#define _SeedSearcher_Cluster_h

//
// File        : $RCSfile: $ 
//               $Workfile: Cluster.h $
// Version     : $Revision: 23 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:57 $ 
// Description :
//    Concrete class for sets of sequences, sets of sequence positions
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

#include "Sequence.h"
#include "SeqWeight.h"
#include "legacy/mathplus.h"

#include "core/AutoPtr.h"
#include "core/STLHelper.h"

#include <map>
#include <set>

namespace seed {

class SequenceDB;

//
//
class PosCluster  {
public:
   struct PositionComparator {
      //
      // returns true if x comes before y
      inline bool operator () (const SeqPosition* x, const SeqPosition* y) const {
         debug_mustbe (x->sequence () == y->sequence ());
         return x_before_y (x, y);
      }
      static inline bool x_before_y (const SeqPosition* x, const SeqPosition* y) {
         return (strandPos (x) < strandPos (y));
      }
      static inline int strandPos (const SeqPosition* x, int offset = 0) {
         int pos = x->position (); 
         // reverse strand positions should appear after positive strand ones.
         int modifier = (x->strand ()== _strand_pos_)? 0 : (10000 + x->sequence()->length());
         return pos + offset + modifier;
      }
   };

   typedef std::set <const SeqPosition*, PositionComparator> PositionSet;
   typedef IteratorWrapper <PositionSet> Iterator;
   typedef CIteratorWrapper <PositionSet> CIterator;

public:
   PosCluster () {
   }
   ~PosCluster () {
   }

   const Sequence* sequence () const;
   bool empty () const {
      return _set.empty ();
   }
   void clear () {
      _set.clear ();
   }
   int size () const {
      return _set.size ();
   }

   bool addPosition (const SeqPosition*);
   void removePosition (const SeqPosition*);

   void copy (const PosCluster&);
   void intersection (const PosCluster&);
   void unify (const PosCluster&);
   bool equals (const PosCluster&);
   bool contains (const PosCluster&);

   Iterator iterator () {
      return Iterator (_set.begin (), _set.end ());
   }
   CIterator iterator () const {
      return CIterator (_set.begin (), _set.end ());
   }

   class NoOverlapsIterator {
   public:
      NoOverlapsIterator (PosCluster::PositionSet& set, int positionDistance); 

      bool hasNext () const {
         return _current != _end;
      }
      void next ();
      const SeqPosition& get () const {
         return **_current;
      }
   private:
      PosCluster::PositionSet::reverse_iterator _current;
      PosCluster::PositionSet::reverse_iterator _end;
      const int _positionDistance;
   };

   NoOverlapsIterator iteratorNoOverlaps (int positionDistance) {
      return NoOverlapsIterator (_set, positionDistance);
   }

   int removeOverlaps (int positionDistance);
   int sizeNoOverlaps (int positionDistance) const;

   void add2Vector (PositionVector&) const;

private:
   PosCluster (const PosCluster&);
   PosCluster& operator = (const PosCluster&);

private:
   PositionSet _set;
};


//
//
class SeqCluster {
public:
   struct SequenceComparator {
      bool operator()(const Sequence*, const Sequence*) const;
      bool operator()(const Sequence*, Sequence::ID) const;
      bool operator()(Sequence::ID, const Sequence*) const;
      bool operator()(Sequence::ID, Sequence::ID) const;
   };

   typedef std::map <const Sequence*, PosCluster*, SequenceComparator> SequenceSet;
   typedef IteratorWrapper < Map1stBinder <SequenceSet> > Iterator;
   typedef CIteratorWrapper < Map1stBinder <SequenceSet> > CIterator;

public:
   SeqCluster () {
   }
   explicit SeqCluster (const SequenceDB&);
   //SeqCluster (const SeqCluster&);
   //
   // copies only the positive elements from the cluster, does not import positions
   SeqCluster (const SeqCluster& seq, const SeqWeightFunction& wf) {
      CIterator it (seq.iterator ());
      for (; it.hasNext () ; it.next ()) {
         if (wf.isPositive ((*it)->id ()))
            addSequence (*it);
      }
   }
   ~SeqCluster ();

   SeqCluster& set (const SeqCluster&);

   bool addSequence (const Sequence* in);
   void removeSequence (const Sequence* in);
   void removeSequence (Sequence::ID);
   const Sequence* getSequence (Sequence::ID) const;

   bool hasSequence (const SeqWeightFunction&) const;
   bool hasSequence (const Sequence*) const;
   bool hasSequence (Sequence::ID id) const {
      return getSequence (id) != NULL;
   }


   Iterator iterator () {
      return Iterator (Map1stBinder <SequenceSet>::Iterator (_set.begin ()),
                       Map1stBinder <SequenceSet>::Iterator (_set.end ()));
   }

   CIterator iterator () const {
      Map1stBinder <SequenceSet>::CIterator a (_set.begin ());
      Map1stBinder <SequenceSet>::CIterator b (_set.end ());
      return CIterator (a, b);
   }

   struct SeqPosIterator {
      //
      // invariants:
      // (1) the current element is stored at _current
      // (2) _posit will point at the next element
      SeqPosIterator (const SeqCluster& c) : _cluster (c), _seqit (c.iterator ()), _current (NULL) {
         while (_seqit.hasNext () && (_cluster.getPositions (_seqit.get ()) == NULL))
            _seqit.next ();

         if (_seqit.hasNext()){
            _posit = _cluster.getPositions (_seqit.get ())->iterator ();
            if (_posit.hasNext ()) {
               _current = &(*_posit.get ());
               _posit.next ();
            }

            _seqit.next ();
         }

      }
      virtual ~SeqPosIterator () {
      }
      bool hasNext () const {
         return _current != NULL;
      }
      bool next () {
         while (!_posit.hasNext () && _seqit.hasNext ()) {
            if (_cluster.getPositions (_seqit.get ()) != NULL) {
               _posit = _cluster.getPositions (_seqit.get ())->iterator ();
            }
            _seqit.next ();
         }

         if (_posit.hasNext ()) {
            _current = *_posit;
            _posit.next ();
         }
         else {
            _current = NULL;
         }
         return hasNext ();
      }
      const SeqPosition* get () const {
         return _current;
      }

      const SeqCluster& _cluster;
      PosCluster::CIterator _posit;
      SeqCluster::CIterator _seqit;
      const SeqPosition* _current;
   };

   SeqPosIterator posIterator () const {
      return SeqPosIterator (*this);
   }
   
   //
   // 
   PosCluster* getPositions (Sequence::ID id);
   PosCluster* getPositions (Iterator&);
   PosCluster* getPositions (CIterator&);
   PosCluster* getPositions (const Sequence*);
   PosCluster& getCreatePositions (const Sequence*);
   PosCluster& getCreatePositions (Sequence::ID);
   PosCluster& getCreatePositions (Iterator&);
   const PosCluster* getPositions (Sequence::ID) const;
   const PosCluster* getPositions (Iterator&) const;
   const PosCluster* getPositions (CIterator&) const;
   const PosCluster* getPositions (const Sequence*) const;
   //
   //
   bool hasPositions (Sequence::ID) const;
   bool hasPositions (Iterator&) const;
   bool hasPositions (CIterator&) const;
   bool hasPositions (const Sequence*) const;
   bool hasPositions () const {
      SeqPosIterator it (*this);
      return it.hasNext (); // returns true if it has any positions at all
   }

   bool empty () const {
      return _set.empty ();
   }
   void clear ();

   //
   // return the size of the cluster (number of sequences)
   inline int size () const {
      return _set.size ();
   }

   //
   // populates the 3rd parameters with the sequences that appear 
   // in both of the first-two paramters
   static void intersect (const SeqCluster&, const SeqCluster&, SeqCluster&);
   
   //
   // adds all sequences from parameter into this cluster (does not import positions)
   void unify (const SeqCluster&);

   //
   // adds all sequences and all positions from parameter, into this cluster.
   void unifyPositions (const SeqCluster&);

   //
   // adds all positions from parameter for sequences in this cluster
   void importPositions (const SeqCluster&);

   void addPos2Vector (PositionVector&) const;
   void addPos2Vector (PositionVector&, Sequence::ID) const;
   void addSeq2Vector (SequenceVector&) const;

   struct FindPositive {
      FindPositive (const SeqWeightFunction& wf) : _wf (wf) {
      }
      bool perform (const Sequence& seq, PosCluster*) {
         //
         // we continue until we find a positive
         bool shouldContinue = !_wf.isPositive (seq.id ());
         return shouldContinue;
      }

   protected:
      const SeqWeightFunction& _wf;
   };

   struct AddPositions {
      typedef PositionVector& Result;
      AddPositions (PositionVector& in) : _positions (in) {
      }
      inline void perform (const Sequence&, PosCluster* cluster) {
         cluster->add2Vector (_positions);
      }
      Result result () {
         return _positions;
      }

   protected:
      PositionVector& _positions;
   };

   struct AddSequences {
      typedef SequenceVector& Result;
      AddSequences (SequenceVector& in) : _sequences (in) {
      }
      inline void perform (const Sequence& seq, PosCluster*) {
         _sequences.push_back (&seq);
      }
      Result result () {
         return _sequences;
      }

   protected:
      SequenceVector& _sequences;
   };

   //
   //
   template <typename CounterT, typename ResultT = CounterT>
   struct SimpleCounter {
      typedef ResultT Result;
      SimpleCounter () : _result (0) {
      }
      inline Result result () {
         return _result;
      }
   protected:
      CounterT _result;
   };

   //
   //
   struct MaxPosNoOverlaps : public SimpleCounter <double> {
      MaxPosNoOverlaps (int seedLength) : _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster*) {
         double L_by_K = double (seq.length ()) / _seedLength;
         _result += L_by_K;
      }

      int _seedLength;
   };

   //
   //
   struct SumMaxPositionalWeight : public SimpleCounter <double> {
      SumMaxPositionalWeight (const SeqWeightFunction& wf,
                              int seedLength) 
      : _wf (wf), _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster* pos) {
         debug_mustbe (pos);
         PosCluster::Iterator posit (pos->iterator ());
         double bestSeqWeight = 0;
         for (; posit.hasNext() ; posit.next()) {
            bestSeqWeight = tmax (_wf.weight (*posit.get (), _seedLength), 
                                 bestSeqWeight);
         }
         _result += bestSeqWeight;
      }

      const SeqWeightFunction& _wf;
      int _seedLength;
   };

   struct SumPositionalWeightNoOverlaps : public SimpleCounter <double> {
      SumPositionalWeightNoOverlaps (const SeqWeightFunction& wf,
                           int seedLength) 
      : _wf (wf), _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster* pos) {
         debug_mustbe (pos);
         PosCluster::NoOverlapsIterator posit (
            pos->iteratorNoOverlaps(_seedLength));

         double bestSeqWeight = 0;
         for (; posit.hasNext() ; posit.next()) {
            bestSeqWeight += _wf.weight (posit.get (), _seedLength);
         }
         _result += bestSeqWeight;
      }

      const SeqWeightFunction& _wf;
      int _seedLength;
   };

   //
   //
   struct WeightedMaxPosNoOverlaps : public SimpleCounter <double> {
      WeightedMaxPosNoOverlaps (const SeqWeightFunction& wf, int seedLength) 
      : _wf (wf), _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster*) {
         double L_by_K = double (seq.length ()) / _seedLength;
         _result += _wf.weight (seq.id ()) * L_by_K;
      }

      const SeqWeightFunction& _wf;
      int _seedLength;
   };


   //
   //
   struct SumPosWeights : public SimpleCounter <double> {
      SumPosWeights (const SeqWeightFunction& wf, int seedLength) 
      : _wf (wf), _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster* p) {
         _result += _wf.weight (seq.id ()) * p->sizeNoOverlaps (_seedLength);
      }
      const SeqWeightFunction& _wf;
      int _seedLength;
   };

   //
   //
   struct SumSeqWeights : public SimpleCounter <double> {
      SumSeqWeights (const SeqWeightFunction& wf) 
      : _wf (wf) {
      }
      inline void perform (const Sequence& seq, PosCluster*) {
         _result += _wf.weight (seq.id ());
      }
      const SeqWeightFunction& _wf;
   };



   //
   //
   template <class SeqOp1, class SeqOp2>
   struct Compose {
      SeqOp1& _op1;
      SeqOp2& _op2;

      Compose (SeqOp1& op1, SeqOp2& op2) : _op1(op1), _op2(op2) {
      }
      inline void perform (const Sequence& seq, PosCluster* p) {
         _op1.perform(seq, p);
         _op2.perform(seq, p);
      }
   };

   template <class SeqOp1, class SeqOp2>
   static Compose<SeqOp1, SeqOp2> compose (SeqOp1& op1, SeqOp2& op2) {
      return Compose <SeqOp1, SeqOp2> (op1, op2);
   };

   //
   // useful for counting sequences in a cluster
   struct CountSequences : public SimpleCounter <int> {
      inline void perform (const Sequence&, PosCluster*) {
         _result++;
      }
   };

   //
   // useful for counting all positions in a cluster
   struct CountPositionsNoOverlaps : public SimpleCounter <int> {
      int _seedLength;
      CountPositionsNoOverlaps (int seedLength) 
      : _seedLength (seedLength) {
      }
      inline void perform (const Sequence&, PosCluster* pos) {
          debug_mustbe (pos);
		  _result += pos->sizeNoOverlaps(_seedLength);
      }
   };

   //
   //
   template <class SeqOp>
   class ForPositives {
   public:
      typedef typename SeqOp::Result Result;
      ForPositives (const SeqWeightFunction& wf, SeqOp& op)
      : _op (op), _wf (wf) {
      }
      inline void perform (const Sequence& seq, PosCluster* pos) {
         if (_wf.isPositive (seq.id ()))
            _op.perform (seq, pos);
      }
      Result result () {
         return _op.result ();
      }
   private:
      SeqOp& _op;
      const SeqWeightFunction& _wf;
   };


   //
   //
   template <class SeqOp1, class SeqOp2 = SeqOp1>
   class DivideByWeight {
   public:
      typedef std::pair <SeqOp1*, SeqOp2*> Result;
      DivideByWeight (const SeqWeightFunction&  wf, SeqOp1& op1, SeqOp2& op2)
      : _op1 (op1), _op2 (op2), _wf (wf) {
      }
      inline void perform (const Sequence& seq, PosCluster* pos) {
         bool isPositive;
         if (_wf.isRelevant (seq.id(), isPositive)) {
            isPositive? 
               _op1.perform (seq, pos) : _op2.perform (seq, pos);
         }
      }
      Result result () {
         return Result (&_op1, &_op2);
      }

   private:
      SeqOp1& _op1;
      SeqOp2& _op2;
      const SeqWeightFunction& _wf;
   };



   //
   //
   template <class SeqOp>
   void perform (SeqOp& op) const {
      SequenceSet::const_iterator current = _set.begin ();
      SequenceSet::const_iterator end = _set.end();
      for (; current != end ; ++current) {
         op.perform (*(current->first), current->second);
      }
   }


   //
   //
   template <class SeqOp>
   void performOnPositives (const SeqWeightFunction& wf, SeqOp& op) const {
      ForPositives <SeqOp> action (wf, op);
      perform (action);
   }


   //
   //
   template <class SeqOp1, class SeqOp2>
   void performDivided (const SeqWeightFunction& wf, 
                        SeqOp1& op1                , 
                        SeqOp2& op2                ) const {
      DivideByWeight <SeqOp1, SeqOp2> action (wf, op1, op2);
      perform (action);
   }

   template <class SeqBoolOp>
   CIterator performUntil (SeqBoolOp& op) const {
      SequenceSet::const_iterator current = _set.begin ();
      SequenceSet::const_iterator end = _set.end();
      for (; current != end ; ++current) {
         bool result = op.perform (*(current->first), current->second);
         if (!result)
            break;
      }

      return CIterator (current, end);
   }



private:
   SequenceSet _set;
};

}


#endif // _SeedSearcher_Cluster_h
