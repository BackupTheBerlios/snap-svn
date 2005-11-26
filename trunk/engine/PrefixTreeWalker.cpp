#include "PrefixTreeWalker.h"
#include "SequenceDB.h"
#include "Sequence.h"

#include <set>

USING_TYPE (PrefixTreePreprocessor, Node);
USING_TYPE (PrefixTreePreprocessor, NodeRep);
USING_TYPE (PrefixTreePreprocessor, PositionVector);
USING_TYPE (PrefixTreePreprocessor, SequenceVector);
USING_TYPE (PrefixTreePreprocessor, PositionIterator);
USING_TYPE (PrefixTreePreprocessor, SequenceIterator);
USING_TYPE (PrefixTreePreprocessor, SeqPositionIterator);



static void rec_addAssignmentNodes (int depth,
                                int desiredDepth,
                                PrefixTreeWalker::NodeVector& nodes,
                                PrefixTreePreprocessor::NodeRep* inNode,
                                const Assignment& assg)

{
   if (inNode == NULL)
      return;

   if (depth == desiredDepth) {
      nodes.push_back (inNode);
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
                              nodes, 
                              node.getChild (nodeIndex), 
                              assg);
   }
}

void PrefixTreeWalker::Nodes::addAssignmentNodes (  const PrefixTreePreprocessor& tree,
                                  const Assignment& assg)
{
   rec_addAssignmentNodes (0,                      // starting depth
                           assg.length (),      // desired depth
                           *this,                  // NodeVector
                           tree.getRoot (),        // starting node
                           assg                    // the assignment
                           );            
}



Preprocessor::SequenceVector* PrefixTreeWalker::Nodes::sequences () 
{
   //
   // multo-importante: the Sequences are repeated in different nodes
   // therefore they are not unique. so store them in a set
   // to keep only those that ARE unique.
   //
   // TODO: check if comparing the pointers is enought to establish 
   //       the sequence's identity
   typedef std::set <SequenceDB::Sequence const *> SequenceSet;
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
	    SequenceDB::Sequence const * newSeq = seqPos.sequence ();
	    seq.insert (newSeq);
      }
   }

   //
   // for debugging
   int size = seq.size ();
   SequenceSet::iterator begin = seq.begin ();
   SequenceSet::iterator end = seq.end ();
   return createNewVector <Preprocessor::SequenceVector> (size, begin, end);
}

//
// returns a vector of all (unique) positions in the nodes
// (there are no duplicates in the vector)
Preprocessor::PositionVector* PrefixTreeWalker::Nodes::positions ()
{
   std::set <SequenceDB::Position const *> pos;
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

   return createNewVector <Preprocessor::PositionVector> (
	  pos.size (), 
	  pos.begin (), 
	  pos.end ()
	  );
}

//
// returns a vector of all (unique) positions in a particular sequence, in the nodes
// (there are no duplicates in the vector)
Preprocessor::PositionVector* 
PrefixTreeWalker::Nodes::positions (SequenceDB::ID id)
{
   std::set <SequenceDB::Position const *> pos;
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

   return createNewVector <Preprocessor::PositionVector> (
	   pos.size (), 
	   pos.begin (), 
	   pos.end ()
	   );
}




