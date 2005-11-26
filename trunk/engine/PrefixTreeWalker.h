#ifndef _SeedSearcher_PrefixTreeWalker_h
#define _SeedSearcher_PrefixTreeWalker_h

#include "Assignment.h"
#include "PrefixTreePreprocessor.h"

class PrefixTreeWalker {
public:
   class NodeWithPath {
   public:
      NodeWithPath (PrefixTreePreprocessor::NodeRep* inNode, 
                    const Assignment& inPath) 
      : _node (inNode), _path (inPath) 
      {
      }

      operator PrefixTreePreprocessor::NodeRep* () const {
         return _node;
      }
      PrefixTreePreprocessor::NodeRep* node () const {
         return _node;
      }
      const Assignment& path () const {
         return _path;
      }

   private:
      PrefixTreePreprocessor::NodeRep* _node;
      Assignment _path;
   };

   typedef Vec <NodeWithPath> NodeVector;
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
      AutoPtr <Preprocessor::SequenceVector> sequences ();

      //
      // returns a vector of all (unique) positions in the nodes
      // (there are no duplicates in the vector)
      AutoPtr <Preprocessor::PositionVector> positions ();

      //
      // returns a vector of all (unique) positions in a particular sequence, in the nodes
      // (there are no duplicates in the vector)
      AutoPtr <Preprocessor::PositionVector> positions (SequenceDB::ID);

      //
      // updates two vectors with (unique) positions, the first contains
      // all positions in nodes that are in sequences with weight >= theshold
      // the other contains all the other positions (weight < theshold)
      void positions (  double threshold, 
                        Preprocessor::PositionVector& positivePositions, 
                        Preprocessor::PositionVector& negativePositions);
   };
};

#endif // _SeedSearcher_PrefixTreeWalker_h



