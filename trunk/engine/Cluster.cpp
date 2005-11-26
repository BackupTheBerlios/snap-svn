#include "Cluster.h"
#include "SequenceDB.h"
#include "Legacy/mathplus.h"


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
   SequenceSet::iterator it = _set.begin ();
   SequenceSet::iterator end = _set.end ();
   for (; it != end ; it++) {
      PosCluster* pos = it->second;
      delete pos;
   }

   _set.clear ();
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

PosCluster* SeqCluster::getPositions (ConstIterator& it)
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

const PosCluster* SeqCluster::getPositions (ConstIterator& it) const
{
   return it.getImpl ().getImpl ()->second;
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

   ConstIterator it (x->iterator ());
   for (; it.hasNext () ; it.next ()) {
      if (y->hasSequence ((*it)))
         o.addSequence (*it);
   }
}


void SeqCluster::unify (const SeqCluster& o)
{
   ConstIterator it (o.iterator ());
   for (; it.hasNext () ; it.next ()) {
      addSequence (*it);
   }
}

void SeqCluster::unifyPositions (const SeqCluster& o)
{
   ConstIterator it (o.iterator ());
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
   ConstIterator it (iterator());

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

   ConstIterator it (iterator());
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
   ConstIterator it (iterator());
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
   ConstIterator it (iterator());
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
   ConstIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      const PosCluster* pos = getPositions (it);
      debug_mustbe (pos);
      if (pos)
         count += pos->size ();
   }

   return count;
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

void PosCluster::addPosition (const Position* in)
{
   _set.insert (in);
}

void PosCluster::removePosition (const Position* in)
{
   debug_only (
      int result = _set.erase (in);
      debug_mustbe (result == 1);
   );
}

void PosCluster::removeOverlaps (int positionDistance)
{
   debug_mustbe (positionDistance > 0);
   if (size () <= 0)
      return;

   //
   // we remove all the overlaps by starting at a position
   // and removing all later positions that overlap with it.
   //
   // TODO: this is not the best way to remove overlaps
   // there exists an algorithm that minimizes the number of removed positions
   // to get no overlaps. maybe we should find/implement this algorithm...
   Vec <const Position*> positions;
   PosCluster::Iterator posIt (iterator ());
   for (int lastPosition = -1; posIt.hasNext () ; posIt.next ()) {
      int currentPosition = (*posIt)->position ();
      if (currentPosition <= lastPosition) {
         //
         // this is an overlap, we should remove this position
         positions.push_back ((*posIt));
      }
      else {
         //
         // we are keeping this position, we are not keeping any other positions
         // that start before the feature starting here ends
         lastPosition = currentPosition + positionDistance;
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
   // now we clear the vector for the next iteration
   positions.clear ();

   //
   // that's it, we have removed all overlaps!!!
   debug_mustbe (this->size () >= 1);

}


