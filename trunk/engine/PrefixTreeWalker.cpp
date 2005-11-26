#if 0 

#include "PrefixTreeWalker.h"
#include "SequenceDB.h"
#include "Sequence.h"

#include <set>

USING_TYPE (PrefixTreePreprocessor, Node);
USING_TYPE (PrefixTreePreprocessor, TreeNode);
USING_TYPE (PrefixTreePreprocessor, SeqPositionIterator);



static void rec_addAssignmentNodes (int depth,
                                int desiredDepth,
                                int childIndex,
                                PrefixTreeWalker::NodeVector& nodes,
                                PrefixTreePreprocessor::TreeNode* inNode,
                                const Assignment& assg,
                                Assignment& path)

{
   if (inNode == NULL)
      return;

   const Assignment::Position& thisPosition = assg [depth -1];
   if (thisPosition.strategy () == Assignment::together) {
      //
      // this means that we got here with 'together' strategy
      // so we keep the exact same positions in the feature
      path.setPosition (depth - 1, thisPosition);
   }
   else {
      debug_mustbe (thisPosition.strategy () == Assignment::discrete);
      //
      // this means that the exact code of this depth is important
      path.setPosition (depth -1, 
         Assignment::Position (childIndex, Assignment::discrete)); 
   }

   if (depth == desiredDepth) {
      nodes.push_back (PrefixTreeWalker::NodeWithPath (inNode, path));
      //
      // there is no need to go further down the tree
      // because no new positions can be found further down (this is a prefix tree)
      return;
   }

   PrefixTreePreprocessor::Node node (inNode);
   Assignment::PositionIterator it (assg [depth]);
   for (; it.hasNext () ; it.next ()) {
      int nodeIndex = it.get ();
      rec_addAssignmentNodes (depth+1, 
                              desiredDepth,
                              nodeIndex,
                              nodes, 
                              node.getChild (nodeIndex), 
                              assg,
                              path);
   }
}

void PrefixTreeWalker::Nodes::addAssignmentNodes (  const PrefixTreePreprocessor& tree,
                                  const Assignment& assg)
{
   if (assg.length () <= 0)
      return;

   Assignment path;
   PrefixTreePreprocessor::Node node (tree.getRoot ());
   Assignment::PositionIterator it (assg [0]);
   for (; it.hasNext () ; it.next ()) {
      int nodeIndex = it.get ();
      rec_addAssignmentNodes (1,                         // starting depth
                              assg.length (),            // desired depth
                              nodeIndex,
                              *this,                     // NodeVector
                              node.getChild (nodeIndex), // starting node
                              assg,                      // the assignment
                              path);
   }
}



AutoPtr <SequenceVector> PrefixTreeWalker::Nodes::sequences () 
{
   //
   // multo-importante: the Sequences are repeated in different nodes
   // therefore they are not unique. so store them in a set
   // to keep only those that ARE unique.
   //
   // TODO: check if comparing the pointers is enought to establish 
   //       the sequence's identity
   typedef std::set <Sequence const *> SequenceSet;
   SequenceSet seq;

   //
   // iterate over all nodes
   NodeIterator itNodes (this->begin (), this->end ());
   for (; itNodes.hasNext () ; itNodes.next ()) {
      //
      // in each node iterate over all sequences
      PrefixTreePreprocessor::Node node (itNodes.get ());
      SeqPositionIterator itSeq (node.positionsBySequence ());
      for (; itSeq.hasNext () ; itSeq.next ()) {
         PrefixTreePreprocessor::SeqPositions seqPos = itSeq.get ();
         Sequence const * newSeq = seqPos.sequence ();
         seq.insert (newSeq);
      }
   }

   //
   // for debugging
   int size = seq.size ();
   SequenceSet::iterator begin = seq.begin ();
   SequenceSet::iterator end = seq.end ();
   return createNewVector <SequenceVector> (size, begin, end);
}

//
// returns a vector of all (unique) positions in the nodes
// (there are no duplicates in the vector)
AutoPtr <PositionVector> PrefixTreeWalker::Nodes::positions ()
{
   std::set <Position const *> pos;
   //
   // iterate over all nodes
   NodeIterator itNodes (this->begin (), this->end ());
   for (; itNodes.hasNext () ; itNodes.next ()) {
      
      //
      // in each node iterate over all sequences
      PrefixTreePreprocessor::Node node (itNodes.get ());
      SeqPositionIterator itSeq (node.positionsBySequence ());
      for (; itSeq.hasNext () ; itSeq.next ()) {
         //
         // for each sequence iterate over all positions
         PositionIterator itPos (itSeq->iterator ());
         for (; itPos.hasNext () ; itPos.next ()) {
            pos.insert (itPos.get ());
         }
      }
   }

   return createNewVector <PositionVector> (
	  pos.size (), 
	  pos.begin (), 
	  pos.end ()
	  );
}

//
// returns a vector of all (unique) positions in a particular sequence, in the nodes
// (there are no duplicates in the vector)
AutoPtr <PositionVector> 
PrefixTreeWalker::Nodes::positions (SequenceDB::ID id)
{
   std::set <Position const *> pos;
   //
   // iterate over all nodes
   NodeIterator itNodes (this->begin (), this->end ());
   for (; itNodes.hasNext () ; itNodes.next ()) {
      
      //
      // in each node iterate over all positions of that sequence
      PrefixTreePreprocessor::Node node (itNodes.get ());
      PositionIterator itPos (node.positionIterator (id));
      for (; itPos.hasNext () ; itPos.next ()) {
         pos.insert (itPos.get ());
      }
   }

   return createNewVector <PositionVector> (
	   pos.size (), 
	   pos.begin (), 
	   pos.end ()
	   );
}


void PrefixTreeWalker::Nodes::positions (  
                     double threshold, 
                     PositionVector& positivePositions, 
                     PositionVector& negativePositions)
{
   std::set <Position const *> pos;
   std::set <Position const *> neg;

   //
   // iterate over all nodes
   NodeIterator itNodes (this->begin (), this->end ());
   for (; itNodes.hasNext () ; itNodes.next ()) {
      
      //
      // in each node iterate over all positions of that sequence
      PrefixTreePreprocessor::Node node (itNodes.get ());
      SeqPositionIterator itSeq (node.positionsBySequence ());
      for (; itSeq.hasNext () ; itSeq.next ()) {
         //
         // for each sequence iterate over all positions
         PositionIterator itPos (itSeq->iterator ());      
         for (; itPos.hasNext () ; itPos.next ()) {
            debug_mustbe ((*itPos)->sequence ()->hasWeight ());
         
            if ((*itPos)->sequence ()->weight () >= threshold)
               pos.insert (itPos.get ());
            else
               neg.insert (itPos.get ());
         }
      }
   }

   const int posSize = pos.size ();
   const int negSize = neg.size ();
   positivePositions.resize (posSize);
   negativePositions.resize (negSize);
   std::copy (pos.begin (), pos.end (), positivePositions.begin ());
   std::copy (neg.begin (), neg.end (), negativePositions.begin ());
}










#endif 



