#include "Cluster.h"
#include "SequenceDB.h"
#include "Legacy/mathplus.h"

#include <limits.h>


//
// SequenceComparator
//



bool SeqCluster::SequenceComparator::
   operator()(const Sequence* x, const Sequence* y) const
{
   return x->id () < y->id ();
}

bool SeqCluster::SequenceComparator::
operator()(const Sequence* x, Sequence::ID y) const
{
   return x->id () < y;
}

bool SeqCluster::SequenceComparator::
   operator()(Sequence::ID x, const Sequence* y) const
{
   return x < y->id ();
}

bool SeqCluster::SequenceComparator::
   operator()(Sequence::ID x, Sequence::ID y) const
{
   return x < y;
}


static char __emptyString [] ="";

//
// SeqCluster
//

SeqCluster::SeqCluster (const SequenceDB& db)
{
   SequenceDB::SequenceIterator it (db.sequenceIterator ());
   for (; it.hasNext () ; it.next ())
      addSequence (*it);
}

SeqCluster::~SeqCluster () 
{
   clear ();
}

void SeqCluster::clear ()
{
   if (!_set.empty ()) {
      SequenceSet::iterator it = _set.begin ();
      SequenceSet::iterator end = _set.end ();
      for (; it != end ; it++) {
         PosCluster* pos = it->second;
         delete pos;
      }

      _set.clear ();
   }
}

bool SeqCluster::addSequence (const Sequence* in)
{
   std::pair <SequenceSet::iterator, bool> result = 
      _set.insert (SequenceSet::value_type (in, NULL));

   return result.second;
}

bool SeqCluster::hasSequence (const Sequence* in) const
{
   return _set.find (in) != _set.end ();

}

const Sequence* SeqCluster::getSequence (Sequence::ID id) const
{
   Sequence dummy (id, __emptyString, __emptyString);
   SequenceSet::const_iterator it = _set.find (&dummy);
   return (it != _set.end ())? it->first: NULL;
}

PosCluster* SeqCluster::getPositions (Sequence::ID id)
{
   Sequence dummy (id, __emptyString, __emptyString);
   SequenceSet::iterator it = _set.find (&dummy);
   return (it != _set.end ())? it->second: NULL;
}

PosCluster* SeqCluster::getPositions (Iterator& it)
{
   return it.getImpl ().getImpl ()->second;
}

PosCluster* SeqCluster::getPositions (CIterator& it)
{
   return it.getImpl ().getImpl ()->second;
}

PosCluster& SeqCluster::getCreatePositions (const Sequence* seq)
{
   std::pair <SequenceSet::iterator, bool> result =
      _set.insert (SequenceSet::value_type (seq, NULL));

   if (result.first->second == NULL) {
      result.first->second = new PosCluster;
      debug_mustbe (_set [result.first->first] != NULL);
   }

   return *(result.first->second);
}

PosCluster& SeqCluster::getCreatePositions (Sequence::ID id)
{
   Sequence dummy (id, __emptyString, __emptyString);
   SequenceSet::iterator it = _set.find (&dummy);
   debug_mustbe (it != _set.end ());

   if (it->second == NULL) {
      it->second = new PosCluster;
      debug_mustbe (_set [it->first] != NULL);
   }

   return *(it->second);
}

PosCluster& SeqCluster::getCreatePositions (Iterator& in)
{
   SequenceSet::iterator it = in.getImpl ().getImpl ();
   debug_mustbe (it != _set.end ());

   if (it->second == NULL) {
      it->second = new PosCluster;
      debug_mustbe (_set [it->first] != NULL);
   }

   return *(it->second);
}

const PosCluster* SeqCluster::getPositions (const Sequence* seq) const
{
   SequenceSet::const_iterator it = _set.find (seq);
   return (it != _set.end ())? it->second: NULL;
}


const PosCluster* SeqCluster::getPositions (Sequence::ID id) const
{
   Sequence dummy (id, __emptyString, __emptyString);
   SequenceSet::const_iterator it = _set.find (&dummy);
   return (it != _set.end ())? it->second: NULL;
}

const PosCluster* SeqCluster::getPositions (Iterator& it) const
{
   return it.getImpl ().getImpl ()->second;
}

const PosCluster* SeqCluster::getPositions (CIterator& it) const
{
   return it.getImpl ().getImpl ()->second;
}

bool SeqCluster::hasPositions (Sequence::ID id) const
{
   const PosCluster* pos = getPositions (id);
   return (pos)? !pos->empty () : false;
}
bool SeqCluster::hasPositions (Iterator& it) const
{
   const PosCluster* pos = getPositions (it);
   return (pos)? !pos->empty () : false;
}

bool SeqCluster::hasPositions (CIterator& it) const
{
   const PosCluster* pos = getPositions (it);
   return (pos)? !pos->empty () : false;
}

bool SeqCluster::hasPositions (const Sequence* seq) const
{
   const PosCluster* pos = getPositions (seq);
   return (pos)? !pos->empty () : false;
}


void SeqCluster::intersect (
                     const SeqCluster& a, 
                     const SeqCluster& b, 
                     SeqCluster& o)
{
   o.clear ();

   //
   // TODO: must be a better/faster way to do this
   const SeqCluster* x;
   const SeqCluster* y;
   if (b.size () < a.size ()) {
       x = &a;
       y = &b;
   }
   else {
      x = &b;
      y = &a;
   }

   CIterator it (x->iterator ());
   for (; it.hasNext () ; it.next ()) {
      if (y->hasSequence ((*it)))
         o.addSequence (*it);
   }
}


void SeqCluster::unify (const SeqCluster& o)
{
   CIterator it (o.iterator ());
   for (; it.hasNext () ; it.next ()) {
      addSequence (*it);
   }
}

void SeqCluster::unifyPositions (const SeqCluster& o)
{
   CIterator it (o.iterator ());
   for (; it.hasNext () ; it.next ()) {
      addSequence (*it);
      const PosCluster* pos = o.getPositions (it);
      if (pos != NULL)
         getCreatePositions ((*it)->id ()).unify (*pos);
   }
}

void SeqCluster::importPositions (const SeqCluster& o)
{
   Iterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      const Sequence* seq = *it;
      const PosCluster* pos = o.getPositions (seq);
      if (pos)
         getCreatePositions (it).unify (*pos);
   }
}

double SeqCluster::sumAbsWeights () const
{
   double result = 0;
   CIterator it (iterator());

   //
   // Wi = (Weight - 0.5) * 2
   for (; it.hasNext (); it.next ()) {
      const Sequence& seq = *(*it);
      if (seq.hasWeight ()) {
         double Wi = ABS (seq.weight () - 0.5) * 2;
         result += Wi;
      }
   }

   return result;
}

double SeqCluster::sumPositionAbsWeights () const
{
   double result = 0;

   CIterator it (iterator());
   for (; it.hasNext (); it.next ()) {
      const Sequence& seq = *(*it);
      debug_mustbe (seq.hasWeight ());
      if (seq.hasWeight ()) {
         double Wi = ABS (seq.weight () - 0.5) * 2;
         const PosCluster* pos = getPositions (it);
         debug_mustbe (pos);
         if (pos)
            result += Wi * pos->size ();
      }
   }

   return result;
}

double SeqCluster::maxPositionsAbsWeightsNoOverlaps (int seedLength) const
{
   double result = 0;
   CIterator it (iterator());
   for (; it.hasNext (); it.next ()) {
      const Sequence& seq = *(*it);
      debug_mustbe (seq.hasWeight ());
      if (seq.hasWeight ()) {
         double Wi = ABS (seq.weight () - 0.5) * 2;
         double L_by_K = double (seq.length ()) / seedLength;
         result += Wi * L_by_K;
      }
   }

   return result;
}

int SeqCluster::maxPositionsNoOverlaps (int seedLength) const
{
   double result = 0;
   CIterator it (iterator());
   for (; it.hasNext (); it.next ()) {
      const Sequence& seq = *(*it);
      double L_by_K = double (seq.length ()) / seedLength;
      result += L_by_K;
   }

   return ROUND (result);
}

int SeqCluster::countPositions () const
{
   int count = 0;
   CIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      const PosCluster* pos = getPositions (it);
      debug_mustbe (pos);
      if (pos)
         count += pos->size ();
   }

   return count;
}

void SeqCluster::addPos2Vector (PositionVector& out) const
{
   AddPositions action (out);
   perform (action);
}
void SeqCluster::addPos2Vector (PositionVector& out, Sequence::ID id) const
{
   getPositions (id)->add2Vector (out);
}

void SeqCluster::addSeq2Vector (SequenceVector& out) const
{
   AddSequences action(out);
   perform (action);
}

bool SeqCluster::hasSequence (const SeqWeightFunction& wf) const
{
   FindPositive findPositive (wf);
   CIterator& it = performUntil (findPositive);
   return it.hasNext ();
}







//
// PosCluster
//

void PosCluster::unify (const PosCluster& in)
{
   PositionSet::const_iterator it = in._set.begin ();
   PositionSet::const_iterator end = in._set.end ();
   for (; it != end ; it++)
      _set.insert (*it);
}

bool PosCluster::addPosition (const Position* in)
{
   bool success = 
      _set.insert (in).second;

   return success;
}

void PosCluster::removePosition (const Position* in)
{
   USELESS (int result =)
     _set.erase (in);

   USELESS (debug_mustbe (result == 1));
}

int PosCluster::removeOverlaps (int positionDistance)
{
   debug_mustbe (positionDistance > 0);
   if (size () <= 1)
      return 0;

   int lastStartPosition = INT_MAX;

   //
   // greedy algorithm - 
   // (1) the positions are ordered by starting positions
   // (2) go from the end of the list to the beginning,
   //       adding a position iff it does not overlap
   //
   // same as the known activity-selection problem.
   // this algorithm yields an optimal solution
   // 
   Vec <const Position*> positions;
   PositionSet::reverse_iterator revIt = _set.rbegin();
   for (; revIt != _set.rend () ; revIt++) {
      //
      //
      const int currentPosition = (*revIt)->position ();
      const int currentFinishPosition = currentPosition + positionDistance;
      //
      //
      if (currentFinishPosition > lastStartPosition) {
         //
         // this is an overlap, we should remove this position
         positions.push_back ((*revIt));
      }
      else {
         //
         // we are keeping this position, we are not keeping any other positions
         // that start before the feature starting here ends
         lastStartPosition = currentPosition;
      }
   }

   //
   // now after we have decided which positions to remove, we actually
   // do the removing
   int size = positions.size ();
   for (int i=0 ; i<size ; i++) {
      removePosition (positions [i]);
   }

   //
   // that's it, we have removed all overlaps!!!
   debug_mustbe (this->size () >= 1);
   return size;
}

void PosCluster::add2Vector (PositionVector& out) const
{
   CIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      out.push_back (*it);
   }
}












