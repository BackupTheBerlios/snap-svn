#ifndef _SeedSearcher_PrefixTreePreprocessor_h
#define _SeedSearcher_PrefixTreePreprocessor_h

#include "Preprocessor.h"

class PrefixTreePreprocessor : public Preprocessor {
   //
   // interface inherited from Preprocessor
public:
   virtual ~PrefixTreePreprocessor ();

   //
	// smallest/largest searchable assignments
   virtual int minAssignmentSize ();
   virtual int maxAssignmentSize ();

   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual PositionVector* getPositions (SequenceDB::ID, const Assignment&);

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID, const Assignment&);

	//
	// iterate over all sequences
    virtual SequenceVector* getSequences ();

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
    virtual SequenceVector* getSequences (const Assignment&);


    //
    //  inner classes
public:
   class Node;
   class NodeRep;
   class TreeRep;
   class SeqPositions;

   //
   // class that represents a vector of positions of a single sequence
   class SeqPositions {
   public:
     SeqPositions ();
      SeqPositions (PositionVector*, bool owner = false);
      ~SeqPositions ();

      SeqPositions& operator = (const SeqPositions&);

      PositionIterator iterator ();
      const SequenceDB::Sequence* sequence () const;
      const PositionVector* positions () const;
      bool empty () const;
      int size () const;

   private:
      bool _owner;
      PositionVector* _positions;
   };

	//
	// contains all positions for a given sequence
   typedef Vec <SeqPositions> SeqPositionVector; 
   typedef IteratorWrapper <SeqPositionVector> SeqPositionIterator;
    // consider only non empty genes, search using binary-search

    //
    // every node has at least one position
    class Node {
    public:
      Node (NodeRep* in) : _rep (in) {
      }
      ~Node () { //
         // just a wrapper for NodeRep...
      }
        
      //
      // return the maximum number of children a node can have (in this tree)
      int getCardinality ();

      //
      // get a child of this node of the half-open range [0..cardinality)
      NodeRep* getChild (int);
      //
      // get parent of this node
      NodeRep* getParent ();
      //
      // return the depth of this node
      int depth ();

      //
      // iterate over positions for this node
      // ordered by their sequence
      SeqPositionIterator positionsBySequence ();

      //
      // ownership belongs to the caller
      PositionVector* getPositions (SequenceDB::ID);

      //
      // iterate over all positions of a particular sequence in this node
      PositionIterator positionIterator (SequenceDB::ID);

      //
      // check if node has any positions for a particular sequence
      bool hasPositions (SequenceDB::ID);
      bool hasPositions (SequenceDB::Cluster&);

      //
      // returns all the sequences in this node
      void getCluster (SequenceDB::Cluster& outSeqInNode) const;
        
    private:
      NodeRep* _rep;
    };

   //
   // tree functions
public:
   PrefixTreePreprocessor (TreeRep*, bool owner = true);
   
   NodeRep* getRoot () const;
   const SequenceDB* getSequenceDB () const;
   int getDepth () const;


    //
    // builds a new prefix tree. uses data from SequenceDB. 
    // depth is the maximum prefix size
    static TreeRep* build (SequenceDB*, int depth);


private:
   bool _owner;
   TreeRep* _rep;
};

#endif // _SeedSearcher_PrefixTreePreprocessor_h

