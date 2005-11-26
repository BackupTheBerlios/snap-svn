#ifndef _SeedSearcher_LeafPreprocessor_h
#define _SeedSearcher_LeafPreprocessor_h

#include "Preprocessor.h"
#include "SeedHash.h"

class LeafPreprocessor : public Preprocessor {
public:
   struct Rep;
   class Table;

   //
   //
   class LeafNode :  
      public Preprocessor::NodeRep, 
      public SeedHash::Cluster <LeafNode>,
      public POOL_ALLOCATED(LeafNode) 
   {
   public:
      LeafNode (const SeedHash::AssgKey& key) 
      : SeedHash::Cluster <LeafNode> (key) 
      {
      }
      virtual ~LeafNode () {
      }

      //
      // check if node has any positions for a particular sequence
      virtual bool hasPositions (SequenceDB::ID) const; 
      virtual bool hasPositions (const SeqWeightFunction&) const;

      //
      // returns all the sequences in this node
      virtual void add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const;
      virtual void add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const;
      virtual void add2PosCluster (PosCluster&, Sequence::ID) const;

      virtual void add2Assignment (Assignment&) const;

      //
      //
      void addPosition (AutoPtr <SeqPosition> pos) {
         PosCluster& posCluster = 
            _cluster->getCreatePositions (pos->sequence ());

         USELESS (bool result = )
            posCluster.addPosition (pos.release ());

	      USELESS (debug_mustbe (result));
      }
   };



public:
   LeafPreprocessor (Rep*);
   ~LeafPreprocessor ();

   static LeafPreprocessor::Rep* LeafPreprocessor::build (
                     int seedLength       ,
                     const SequenceDB&    , 
                     const Langauge&      );

   //
   // includes negative-node-removal optimization
   static LeafPreprocessor::Rep* LeafPreprocessor::buildNoNegatives (
                     int seedLength       ,
                     const SequenceDB&    , 
                     const Langauge&      ,
                     const SeqWeightFunction&);

	//
	// smallest/largest searchable assignments
   virtual int minAssignmentSize () const;
   virtual int maxAssignmentSize () const;

   //
	// iterate over all positions that correspond to an assignment on a given sequence
	virtual AutoPtr <PositionVector> getPositions ( SequenceDB::ID, 
                                                   const Assignment&)  const;

	//
	// returns true iff the sequence has at least one position which corresponds
	// to the given assignment
	virtual bool hasAssignment (SequenceDB::ID, const Assignment&) const;

	//
	// iterate over all sequences
   virtual AutoPtr <SequenceVector> getSequences () const;

	//
	// iterate over all sequences that have at least one position which corresponds 
	// to the given assignment
   virtual AutoPtr <SequenceVector> getSequences (const Assignment&) const;

   //
   //
   virtual void add2Cluster (NodeCluster&, const Assignment&)  const;

protected:
   Rep* _rep;
};

#endif



