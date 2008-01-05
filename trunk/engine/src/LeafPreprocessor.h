#ifndef _SeedSearcher_LeafPreprocessor_h
#define _SeedSearcher_LeafPreprocessor_h

//
// File        : $RCSfile: $ 
//               $Workfile: LeafPreprocessor.h $
// Version     : $Revision: 15 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
// Description :
//    Concrete preprocessor class - based on a hash table
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
#include "SeedHash.h"

namespace seed {

class LeafPreprocessor : public Preprocessor {
public:
   struct Rep;

   class LeafNode :  
      public Preprocessor::NodeRep, 
      public SeedHash::Cluster <LeafNode>
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
      virtual void add2SeqClusterPositions (SequenceDB::Cluster&) const;
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

      //
      //
      struct LeafNodePositionIt : public NodePositionIt::Rep {
         LeafNodePositionIt (const SeqCluster& c) : _it (c) {
         }
         virtual bool next () {
            return _it.next ();
         }
         virtual bool hasNext () const {
            return _it.hasNext();
         }
         virtual const SeqPosition* get () const {
            return _it.get ();
         }

         SeqCluster::SeqPosIterator _it;   
      };
      virtual NodePositionIt::Rep* positionIterator () const {
         return new LeafNodePositionIt (this->getCluster ());
      }
   };


public:
   LeafPreprocessor (Rep*);
   ~LeafPreprocessor ();

   static LeafPreprocessor::Rep* build (
                     int seedLength       ,
                     const SequenceDB&    , 
                     const Langauge&      );

   //
   // includes negative-node-removal optimization
   static LeafPreprocessor::Rep* buildNoNegatives (
                     int seedLength       ,
                     const SequenceDB&    , 
                     const Langauge&      ,
                     const SeqWeightFunction&);

   //
   // smallest/largest searchable assignments
   virtual int minAssignmentSize () const;
   virtual int maxAssignmentSize () const;

   //
   // iterate over all sequences
   virtual AutoPtr <SequenceVector> getSequences () const;

   //
   //
   virtual void add2Cluster (NodeCluster&, const AssignmentBase&)  const;

protected:
   Rep* _rep;
};

}

#endif



