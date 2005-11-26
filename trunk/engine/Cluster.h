#ifndef _SeedSearcher_Cluster_h
#define _SeedSearcher_Cluster_h

#include "Sequence.h"
#include "Legacy/MathPlus.h"

#include "Core/AutoPtr.h"
#include "Core/STLHelper.h"


#include <map>
#include <set>

class SequenceDB;

//
//
class PosCluster  {
public:
   struct PositionComparator {
      bool operator () (const SeqPosition* x, const SeqPosition* y) const {
         debug_mustbe (x->sequence () == y->sequence ());
         return (x->position () < y->position ());
      }
   };

   typedef std::set <const SeqPosition*, PositionComparator> PositionSet;
   typedef IteratorWrapper <PositionSet> Iterator;
   typedef ConstIteratorWrapper <PositionSet> CIterator;

public:
   PosCluster () {
   }
   ~PosCluster () {
   }

   const Sequence* sequence () const;
   bool empty () const {
      return _set.empty ();
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

   int removeOverlaps (int positionDistance);

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
   typedef ConstIteratorWrapper < Map1stBinder <SequenceSet> > CIterator;

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
         if (wf.isPositive (*(*it)))
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

   bool empty () const {
      return _set.empty ();
   }
   void clear ();
   
   //
   // returns the sum of weights for all weighted sequences
   // outCount returns the number of all weighted sequences
   double sumAbsWeights () const;
   //
   // returns the sum of (seq-weight * seq-position-count)
   double sumPositionAbsWeights () const;

   //
   // returns the maximum number of 
   double maxPositionsAbsWeightsNoOverlaps (int seedLength) const;

   //
   //
   int maxPositionsNoOverlaps (int seedLength) const;

   //
   //
   int countPositions () const;

   //
   // return the size of the cluster (number of sequences)
   int size () const {
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
         bool shouldContinue = !_wf.isPositive (seq);
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
   struct MaxPosWeightsNoOverlaps : public SimpleCounter <double> {
      MaxPosWeightsNoOverlaps (int seedLength) : _seedLength (seedLength) {
      }
      inline void perform (const Sequence& seq, PosCluster*) {
         double Wi = ABS (seq.weight () - 0.5) * 2;
         double L_by_K = double (seq.length ()) / _seedLength;
         _result += Wi * L_by_K;
      }

      int _seedLength;
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
   struct SumPosWeights : public SimpleCounter <double> {
      inline void perform (const Sequence& seq, PosCluster* pos) {
         debug_mustbe (pos);
         double Wi = ABS (seq.weight () - 0.5) * 2;
         _result += Wi * pos->size ();
      }
   };


   //
   //
   struct SumSeqWeights : public SimpleCounter <double> {
      inline void perform (const Sequence& seq, PosCluster*) {
         double Wi = ABS (seq.weight () - 0.5) * 2;
         _result += Wi;
      }
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
   struct CountPositions : public SimpleCounter <int> {
      inline void perform (const Sequence&, PosCluster* pos) {
          debug_mustbe (pos);
		  _result += pos->size ();
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
         if (_wf.isPositive (seq))
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
         if (_wf.isRelevant (seq, isPositive)) {
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


#endif // _SeedSearcher_Cluster_h











