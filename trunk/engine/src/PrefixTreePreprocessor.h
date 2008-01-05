#ifndef _SeedSearcher_PrefixTreePreprocessor_h
#define _SeedSearcher_PrefixTreePreprocessor_h

//
// File        : $RCSfile: $ 
//               $Workfile: PrefixTreePreprocessor.h $
// Version     : $Revision: 27 $ 
//               $Author: Aviad $
//               $Date: 4/11/04 17:53 $ 
// Description :
//    Concrete preprocessor class - based on a prefix tree
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

#include "Preprocessor.h"
#include "boost/checked_delete.hpp"

namespace seed {

class PrefixTreePreprocessor : public Preprocessor {
   //
   // interface inherited from Preprocessor
public:
   virtual ~PrefixTreePreprocessor ();

   //
	// smallest/largest searchable assignments
   virtual int maxAssignmentSize () const;
  
   //
   // iterate over all sequences
   virtual AutoPtr <SequenceVector> getSequences ()  const;

   //
   //
   virtual void add2Cluster (NodeCluster&, const AssignmentBase&) const;


    //
    //  inner classes
public:
   class TreeNode;
   class TreeNodeRep;
   class TreeRep;
   class SeqPositions;

   
   //
   // class that represents a vector of positions of a single sequence
   class SeqPositions   {
   public:
     SeqPositions ();
      explicit SeqPositions (PositionVector*);
      ~SeqPositions () {
         //
         // memory for positions is owned by the hosting node
      }

      SeqPositions& operator = (const SeqPositions&);

      PositionIterator iterator ();
      CPositionIterator iterator () const;
      const Sequence* sequence () const;
      const PositionVector* positions () const;
      const SeqPosition* firstPosition () const;
      bool empty () const;
      int size () const;

      void dispose (bool disposePositions) {
         if (disposePositions) {
            PositionIterator it = iterator ();
            for (; it.hasNext () ; it.next ()) {
               const SeqPosition* pos = it.get ();
               delete const_cast <SeqPosition*> (pos);
            }
         }

         if (_positions) {
            boost::checked_delete (_positions);
            _positions = NULL;
         }
      }

   private:
      PositionVector* _positions;
   };


	//
	// contains all positions for a given sequence
   typedef Vec <SeqPositions> SeqPositionVector; 
   typedef IteratorWrapper <SeqPositionVector> SeqPositionIterator;
   typedef CIteratorWrapper <SeqPositionVector> CSeqPositionIterator;
    // consider only non empty genes, search using binary-search

    //
    // every node has at least one position
   class TreeNode : public Preprocessor::Node {
    public:
      TreeNode (TreeNodeRep* in);
      ~TreeNode () { //
         // just a wrapper for TreeNodeRep...
      }
        
      //
      // return the maximum number of children a node can have (in this tree)
      int getCardinality ();

      //
      // get a child of this node of the half-open range [0..cardinality)
      TreeNodeRep* getChild (int);
      //
      // return the depth of this node
      int depth ();

      //
      // iterate over positions for this node
      // ordered by their sequence
      SeqPositionIterator positionsBySequence ();

      //
      // ownership belongs to the caller
      AutoPtr <PositionVector> getPositions (SequenceDB::ID);

      //
      // iterate over all positions of a particular sequence in this node
      PositionIterator positionIterator (SequenceDB::ID);

      //
      // check if node has any positions for a particular sequence
      bool hasPositions (SequenceDB::ID) const; 
      bool hasPositions (const SequenceDB::Cluster&) const;
        
    private:
      TreeNodeRep* _rep;
    };

   class TreeNodePositionIt : public Preprocessor::NodePositionIt::Rep {
   public:
      TreeNodePositionIt (TreeNodeRep* t) : _node(t), _current (NULL) {
         _seqit = _node.positionsBySequence ();
         if (_seqit.hasNext ()) {
            _posit = _seqit->iterator ();
            if (_posit.hasNext ()) {
               _current = &(*_posit.get ());
               _posit.next ();
            }

            _seqit.next ();
         }

      }
      virtual ~TreeNodePositionIt () {
      }
      virtual bool hasNext () const {
         return _current != NULL;
      }
      virtual bool next () {
         while (!_posit.hasNext () && _seqit.hasNext ()) {
            _posit = _seqit->iterator ();
            _seqit.next ();
         }

         if (_posit.hasNext ()) {
            _current = &(*_current);
            _posit.next ();
         }
         else {
            _current = NULL;
         }
         return hasNext ();
      }
      virtual const SeqPosition* get () const {
         return _current;
      }

      TreeNode _node;
      const SeqPosition* _current;
      SeqPositionIterator _seqit;
      PositionIterator _posit;
   };

   //
   // tree functions
public:
   PrefixTreePreprocessor (TreeRep*, bool owner = true);

   TreeNodeRep* getRoot () const;
   const SequenceDB* getSequenceDB () const;
   int getDepth () const;


   //
   // builds a new prefix tree. uses data from SequenceDB. 
   // depth is the maximum prefix size
   static TreeRep* build ( bool removeNodeOptimization,
                           const SeqWeightFunction& wf, 
                           const SequenceDB&,
                           const Langauge&,
                           int depth);

private:
   bool _owner;
   TreeRep* _rep;
};

}

#endif // _SeedSearcher_PrefixTreePreprocessor_h














