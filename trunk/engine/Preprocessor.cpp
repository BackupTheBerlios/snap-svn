#include "Preprocessor.h"

USING_TYPE (Preprocessor, Node);
USING_TYPE (Preprocessor, NodeCluster);

//
// returns a vector of all (unique) sequences with positions in the nodes
// (there are no duplicates in the vector)
AutoPtr <SequenceVector> NodeCluster::sequences ()
{
   SeqCluster cluster;
   AutoPtr <SequenceVector> out = new SequenceVector;

   add2SeqCluster (cluster);
   cluster.addSeq2Vector (*out);
   return out;
}

//
// returns a vector of all (unique) positions in the nodes
// (there are no duplicates in the vector)
AutoPtr <PositionVector> NodeCluster::positions ()
{
   SeqCluster cluster;
   AutoPtr <PositionVector> out = new PositionVector;

   add2SeqClusterPositions (cluster);
   cluster.addPos2Vector (*out);
   return out;
}

//
// returns a vector of all (unique) positions in a particular sequence, in the nodes
// (there are no duplicates in the vector)
AutoPtr <PositionVector> NodeCluster::positions (SequenceDB::ID id)
{
   PosCluster cluster;
   add2PosCluster (cluster, id);
   
   AutoPtr <PositionVector> positions = new PositionVector;
   cluster.add2Vector (*positions);
   return positions;
}

//
// updates two vectors with (unique) positions, the first contains
// all positions in nodes that are in sequences with weight >= theshold
// the other contains all the other positions (weight < theshold)
void NodeCluster::positions (  const SeqWeightFunction& wf,
                  PositionVector& positivePositions , 
                  PositionVector& negativePositions )
{
   SeqCluster cluster;
   add2SeqClusterPositions (cluster);
   SeqCluster::Iterator it (cluster.iterator ());
   for (; it.hasNext () ; it.next ()) {
      const Sequence* seq = *it;
      bool isPositive;
      if (wf.isRelevant (*seq, isPositive)) {
         PosCluster* positions = cluster.getPositions (it);
         debug_mustbe (positions);
         if (isPositive)
            positions->add2Vector (positivePositions);
         else
            positions->add2Vector (negativePositions);
      }
   }
}

//
//
void NodeCluster::addNode (Preprocessor::AssgNodePair& node)
{
   _nodes.push_back (node);
}

void NodeCluster::add2SeqCluster (SeqCluster& cluster) const
{
   CNodeIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      it->node ()->add2SeqCluster (cluster);
   }
}

void NodeCluster::add2SeqClusterPositions (SeqCluster& cluster) const
{
   CNodeIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      it->node ()->add2SeqClusterPositions (cluster);
   }
}

void NodeCluster::add2PosCluster (PosCluster& cluster, Sequence::ID id) const
{
   CNodeIterator it (iterator ());
   for (; it.hasNext () ; it.next ()) {
      it->node ()->add2PosCluster(cluster, id);
   }
}