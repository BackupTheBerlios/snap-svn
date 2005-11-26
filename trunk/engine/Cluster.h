#ifndef _SeedSearcher_Cluster_h
#define _SeedSearcher_Cluster_h

#include "Sequence.h"
#include "Core/STLHelper.h"

#include <map>
#include <set>

class SequenceDB;

//
//
class PosCluster  {
public:
   struct PositionComparator {
      bool operator () (const Position* x, const Position* y) const {
         debug_mustbe (x->sequence () == y->sequence ());
         return (x->position () < y->position ());
      }
   };

   typedef std::set <const Position*, PositionComparator> PositionSet;
   typedef IteratorWrapper <PositionSet> Iterator;

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

   void addPosition (const Position*);
   void removePosition (const Position*);

   void copy (const PosCluster&);
   void intersection (const PosCluster&);
   void unify (const PosCluster&);
   bool equals (const PosCluster&);
   bool contains (const PosCluster&);

   Iterator iterator () {
      return Iterator (_set.begin (), _set.end ());
   }

   void removeOverlaps (int positionDistance);

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
   typedef ConstIteratorWrapper < Map1stBinder <SequenceSet> > ConstIterator;

public:
   SeqCluster () {
   }
   SeqCluster (const SequenceDB&);
   ~SeqCluster ();

   bool addSequence (const Sequence* in);
   void removeSequence (const Sequence* in);
   void removeSequence (Sequence::ID);
   const Sequence* getSequence (Sequence::ID) const;

   bool hasSequence (const Sequence*) const;
   bool hasSequence (Sequence::ID id) const {
      return getSequence (id) != NULL;
   }


   Iterator iterator () {
      return Iterator (Map1stBinder <SequenceSet>::Iterator (_set.begin ()),
                       Map1stBinder <SequenceSet>::Iterator (_set.end ()));
   }

   ConstIterator iterator () const {
      Map1stBinder <SequenceSet>::ConstIterator a (_set.begin ());
      Map1stBinder <SequenceSet>::ConstIterator b (_set.end ());
      return ConstIterator (a, b);
   }
   
   //
   // 
   PosCluster* getPositions (Sequence::ID id);
   PosCluster* getPositions (Iterator&);
   PosCluster* getPositions (ConstIterator&);
   PosCluster* getPositions (const Sequence*);
   PosCluster& getCreatePositions (const Sequence*);
   PosCluster& getCreatePositions (Sequence::ID);
   PosCluster& getCreatePositions (Iterator&);
   const PosCluster* getPositions (Sequence::ID) const;
   const PosCluster* getPositions (Iterator&) const;
   const PosCluster* getPositions (ConstIterator&) const;
   const PosCluster* getPositions (const Sequence*) const;

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
   //
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

private:
   SequenceSet _set;
};


#endif // _SeedSearcher_Cluster_h
