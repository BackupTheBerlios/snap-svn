#ifndef _SeedSearcher_Preprocessor_h
#define _SeedSearcher_Preprocessor_h

#include "Defs.h"
#include "SequenceDB.h"
#include "Assignment.h"

#include "Core/AutoPtr.h"
#include "Core/ChunkAllocator.h"
#include "Core/STLHelper.h"

class Preprocessor {
public:
   //
   //
public:
   //
   //
   struct NodeRep {
      virtual ~NodeRep () {
      }

      //
      // check if node has any positions for a particular sequence
      virtual bool hasPositions (SequenceDB::ID) const = 0; 
      virtual bool hasPositions (const SeqWeightFunction&) const = 0;

      //
      // returns all the sequences in this node
      virtual void add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const = 0;
      virtual void add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const = 0;
      virtual void add2PosCluster (PosCluster&, Sequence::ID) const = 0;
   };

   //
   //
   class Node {
   public:
      Node (NodeRep* in) : _node (in) {
      }
      ~Node () {
      }

      //
      // check if node has any positions for a particular sequence
      bool hasPositions (SequenceDB::ID id) const { 
         return _node->hasPositions (id);
      }
      bool hasPositions (const SeqWeightFunction& wf) const {
         return _node->hasPositions (wf);
      }

      //
      // returns all the sequences in this node
      void add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const {
         _node->add2SeqCluster (outSeqInNode);
      }
      void add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const {
         _node->add2SeqClusterPositions (outSeqInNode);
      }
      void add2PosCluster (PosCluster& p, Sequence::ID id) const {
         _node->add2PosCluster (p, id);
      }

   protected:
      NodeRep* _node;
   };

   //
   //
   class AssgNodePair {
   public:
      //
      //
      AssgNodePair (NodeRep* node, const Assignment& assg) 
         : _node (node), _path (assg) {
      }
      ~AssgNodePair () {
      }

      //
      //
      NodeRep* node () const     { return _node; }
      operator NodeRep* () const { return _node; }
      const Assignment& path () const { return _path; }

   private:
      NodeRep* _node;
      Assignment _path;
   };

   //
   //
   typedef Vec <AssgNodePair> NodeVector;
   typedef IteratorWrapper <NodeVector> NodeIterator;
   typedef ConstIteratorWrapper <NodeVector> CNodeIterator;

   //
   //
   class NodeCluster {
   public:
      NodeCluster () {
      }
      ~NodeCluster () {
      }

      //
      // returns iterator over all nodes
      NodeIterator iterator () { 
         return NodeIterator (_nodes.begin (), _nodes.end ()); 
      }
      CNodeIterator iterator () const { 
         return CNodeIterator (_nodes.begin (), _nodes.end ()); 
      }

      //
      // returns a vector of all (unique) sequences with positions in the nodes
      // (there are no duplicates in the vector)
      AutoPtr <SequenceVector> sequences ();

      //
      // returns a vector of all (unique) positions in the nodes
      // (there are no duplicates in the vector)
      AutoPtr <PositionVector> positions ();

      //
      // returns a vector of all (unique) positions in a particular sequence, in the nodes
      // (there are no duplicates in the vector)
      AutoPtr <PositionVector> positions (SequenceDB::ID);

      //
      // updates two vectors with (unique) positions, the first contains
      // all positions in nodes that are in sequences with weight >= theshold
      // the other contains all the other positions (weight < theshold)
      void positions (  const SeqWeightFunction&                        ,
                        PositionVector& positivePositions , 
                        PositionVector& negativePositions );

      //
      //
      void addNode (AssgNodePair&);

      //
      //
      void add2SeqCluster (SeqCluster&) const;
      void add2SeqClusterPositions (SeqCluster&) const;
      void add2PosCluster (PosCluster&, Sequence::ID) const;

   protected:
      NodeVector _nodes;
   };


   //
   //
public:
   virtual ~Preprocessor () {
   }

	//
	// smallest/largest searchable assignments
   virtual int minAssignmentSize ()const=0;
   virtual int maxAssignmentSize ()const=0;

   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual AutoPtr <PositionVector> getPositions (SequenceDB::ID, const Assignment&)const=0;

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID, const Assignment&)const=0;

	//
	// iterate over all sequences
   virtual AutoPtr <SequenceVector> getSequences ()const=0;

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
   virtual AutoPtr <SequenceVector> getSequences (const Assignment&) const=0;

   virtual void add2Cluster (NodeCluster&, const Assignment&) const= 0;
};


#endif // _SeedSearcher_Preprocessor_h










