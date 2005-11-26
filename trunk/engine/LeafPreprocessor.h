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
   class LeafNode : public Preprocessor::NodeRep, public SeedHash::Cluster {
   public:
      LeafNode (const SeedHash::AssgKey& key) : Cluster (key) {
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

#if SEED_CHUNK_ALLOCATION_OPTIMIZATION
      void* operator new (size_t size) {
         debug_mustbe (size == sizeof (LeafNode));
         return __allocator.newT ();
      }
      void operator delete(void *p)    {
         __allocator.deleteT (reinterpret_cast <LeafNode*> (p));
      }
#endif

   protected:
      static ChunkAllocator <LeafNode> __allocator;
   };



public:
   LeafPreprocessor (Rep*);
   ~LeafPreprocessor ();

   static LeafPreprocessor::Rep* LeafPreprocessor::build (
                     bool useReverse      ,
                     int seedLength       ,
                     const SequenceDB&    , 
                     Langauge&    );

   //
   // includes negative-node-removal optimization
   static LeafPreprocessor::Rep* LeafPreprocessor::buildNoNegatives (
                     bool useReverse      ,
                     int seedLength       ,
                     const SequenceDB&    , 
                     Langauge&    ,
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


