#ifndef _SeedSearcher_PrefixTreeWalker_h
#define _SeedSearcher_PrefixTreeWalker_h

#include "Assignment.h"
#include "PrefixTreePreprocessor.h"

class PrefixTreeWalker {
public:
   class Nodes;

   typedef Vec <PrefixTreePreprocessor::NodeRep*> NodeVector;
   typedef IteratorWrapper <NodeVector> NodeIterator;

   class Nodes : public NodeVector {
   public:
      //
      // add all the nodes from the tree that fit the assignment 
      void addAssignmentNodes (  const PrefixTreePreprocessor&,
                                 const Assignment&);

      //
      // returns iterator over all nodes
      NodeIterator iterator () { 
         return NodeIterator (begin (), end ()); 
      }

      //
      // returns a vector of all (unique) sequences with positions in the nodes
      // (there are no duplicates in the vector)
      Preprocessor::SequenceVector* sequences ();

      //
      // returns a vector of all (unique) positions in the nodes
      // (there are no duplicates in the vector)
      Preprocessor::PositionVector* positions ();

      //
      // returns a vector of all (unique) positions in a particular sequence, in the nodes
      // (there are no duplicates in the vector)
      Preprocessor::PositionVector* positions (SequenceDB::ID);
   };
};

#endif // _SeedSearcher_PrefixTreeWalker_h

