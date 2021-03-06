#ifndef _SeedSearcher_Preprocessor_h
#define _SeedSearcher_Preprocessor_h

//
// File        : $RCSfile: $ 
//               $Workfile: Preprocessor.h $
// Version     : $Revision: 22 $ 
//               $Author: Aviad $
//               $Date: 4/11/04 17:56 $ 
// Description :
//    interface classes for preprocessors
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "Defs.h"
#include "SequenceDB.h"
#include "Assignment.h"

#include "core/AutoPtr.h"
#include "core/STLHelper.h"

#include <list>

namespace seed {

class Preprocessor {
public:
   //
   //
public:
   typedef CAbstractIterator <SeqPosition> NodePositionIt;

   //
   //
   class NodeRep {
   protected:
      virtual ~NodeRep () {
      }

   public:
      //
      // check if node has any positions for a particular sequence
      virtual bool hasPositions (SequenceDB::ID) const = 0; 
      virtual bool hasPositions (const SeqWeightFunction&) const = 0;

      //
      // returns all the sequences in this node
      virtual void add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const = 0;
      virtual void add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const = 0;
      virtual void add2PosCluster (PosCluster&, Sequence::ID) const = 0;

      //
      //
      virtual void add2Assignment (Assignment&) const = 0;

      //
      //
      virtual NodePositionIt::Rep* positionIterator () const = 0;

      //
      //
      virtual void acquire () {
      }
      virtual void unacquire () {
      }
   };

   //
   //
   class Node {
   public:
      Node (NodeRep* in) : _node (in) {
         if (_node) _node->acquire();
      }
      ~Node () {
         if (_node) _node->unacquire();
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

      //
      //
      void add2Assignment (Assignment& outAssg) const {
         _node->add2Assignment (outAssg);
      }

      //
      //
      NodePositionIt::Rep* positionIterator () {
         return _node->positionIterator();
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
      AssgNodePair (NodeRep* node, const AssignmentBase& assg) 
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
   // optimization: nodes are never used in random access
   // so a list is a better choice 
   // typedef Vec <AssgNodePair> NodeVector;
   typedef std::list <AssgNodePair> NodeVector;
   typedef IteratorWrapper <NodeVector> NodeIterator;
   typedef CIteratorWrapper <NodeVector> CNodeIterator;

   //
   //
   class NodeCluster {
   public:
      NodeCluster () {
      }
      ~NodeCluster () {
         for (NodeIterator it =iterator() ; it.hasNext() ;it.next()) 
            it->node ()->unacquire ();
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
   virtual int minAssignmentSize ()const {
      return 0;
   }
   virtual int maxAssignmentSize ()const=0;

   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual AutoPtr <PositionVector> 
      getPositions (SequenceDB::ID id, const AssignmentBase& assg) const {
         NodeCluster cluster;
         add2Cluster (cluster, assg);
         return cluster.positions (id);
      }

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID id, const AssignmentBase& assg) const {
      NodeCluster cluster;
      add2Cluster (cluster, assg);

      NodeIterator it (cluster.iterator ());
      for (; it.hasNext (); it.next ()) {
         Node node (it.get ());
         if (node.hasPositions (id))
            return true;
      }

      return false;
   }

	//
	// iterate over all sequences
   virtual AutoPtr <SequenceVector> getSequences ()const=0;

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
   virtual AutoPtr <SequenceVector> getSequences (const AssignmentBase& assg) const {
      NodeCluster cluster;
      add2Cluster (cluster, assg);
      return cluster.sequences ();
   }

   //
   // add nodes that match the given assignment to a given NodeCluster
   virtual void add2Cluster (NodeCluster&, const AssignmentBase&) const= 0;
};

}


#endif // _SeedSearcher_Preprocessor_h



