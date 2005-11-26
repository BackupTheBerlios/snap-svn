#include "LeafPreprocessor.h"
#include "DebugLog.h"
#include <time.h>


struct LeafPreprocessor::Rep : public SeedHash::Table {
   Rep ( int seedLength                            , 
         int tableSize, const AlphabetCode& code   , 
         AssignmentWriter& assgWriter              )   
      : SeedHash::Table (tableSize, code, assgWriter), 
         _seedLength (seedLength) 
   {
   }

   virtual SeedHash::Cluster* createCluster (const SeedHash::AssgKey& key) {
      return new LeafPreprocessor::LeafNode (key);
   }

   int _seedLength;
};

LeafPreprocessor::LeafPreprocessor (Rep* rep) : _rep (rep) {
}

LeafPreprocessor::~LeafPreprocessor () {
   delete _rep;
}



//
// smallest/largest searchable assignments
int LeafPreprocessor::minAssignmentSize () const
{
   return _rep->_seedLength;
}

int LeafPreprocessor::maxAssignmentSize () const
{
   return _rep->_seedLength;
}

void LeafPreprocessor::add2Cluster (NodeCluster& nodes, 
                                     const Assignment& assg)  const
{
   int assgLength = assg.length ();
   Assignment assgTemplate (assg);
   Rep::Iterator nodeIt (*_rep);
   for (; nodeIt.hasNext () ; nodeIt.next ()) {
      LeafNode* seed = dynamic_cast <LeafNode*> (nodeIt.get ());
      const Assignment& seedAssg = seed->assignment ();

      //
      //
      debug_mustbe (seed);
      debug_mustbe (assg.length () == seedAssg.length ());

      if (assg.contains (seed->assignment ())) {
         //
         // make the template specific to the assignment of the seed
         for (int i=0 ; i<assgLength ; ++i) {
            debug_mustbe (seedAssg.getPosition (i).strategy () == Assignment::discrete);
            if (assgTemplate [i].strategy () == Assignment::discrete)
               assgTemplate.setPosition (i, seedAssg.getPosition (i));
         }

         nodes.addNode (AssgNodePair (seed, assgTemplate));
      }
   }
}

//
// iterate over all positions that correspond to an assignment on a given sequence
AutoPtr <PositionVector> 
LeafPreprocessor::getPositions (SequenceDB::ID id, 
                                const Assignment& assg) const
{
   NodeCluster cluster;
   add2Cluster (cluster, assg);
   return cluster.positions (id);
}

//
// returns true iff the sequence has at least one position which corresponds
// to the given assignment
bool LeafPreprocessor::hasAssignment (SequenceDB::ID id,
                                      const Assignment& assg) const
{
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
AutoPtr <SequenceVector> LeafPreprocessor::getSequences () const
{
   //
   // TODO
   return NULL;
}

//
// iterate over all sequences that have at least one position which corresponds 
// to the given assignment
AutoPtr <SequenceVector> 
LeafPreprocessor::getSequences (const Assignment& assg) const
{
   NodeCluster cluster;
   add2Cluster (cluster, assg);
   return cluster.sequences ();
}



//
//
LeafPreprocessor::Rep* LeafPreprocessor::build (
                   int seedLength                  ,
                   const SequenceDB& db            , 
                   const AlphabetCode& code        , 
                   AssignmentWriter& assgWriter    ) 
{
   time_t start, finish;
   time (&start);

   int numberOfPositions = 0;
   const int TABLE_SIZE = 1024 * 1024 - 1;

   //
   // TODO: guess an estimate to the number of seeds
   Rep* rep = new Rep (seedLength, TABLE_SIZE, code, assgWriter);

   //
   //
   SequenceDB::SequenceIterator it = db.sequenceIterator ();
   for (;it.hasNext () ; it.next ()) {
      //
      // get the sequence we are current working on
      Sequence* seq = it.get ();
      debug_mustbe (seq);

      //
      // stuff every position in this sequence to table
      // except those that dont have enough lookahead
      int length = seq->length () - seedLength + 1;
      numberOfPositions += length ;

      //
      //
      for (int i=0 ; i<=length - seedLength ; i++)   {
         Position* position = 
            new Position (seq, i);

         Str data = position->getDataString (0, seedLength);
         debug_mustbe (data.length () == seedLength);
         rep->addPosition (data, position);
      }

      //
      // increase table size if necessary
      // TODO: is this working properly?
      int tableSize = rep->getTableSize ();
      int numberOfEntries = rep->getSize ();
      if (numberOfEntries > 8 * tableSize)
         rep->resize ((4 * tableSize) - 1);
   }

   time (&finish);
   const int totalBytes =  numberOfPositions * sizeof (Position) + 
                           rep->getSize () * sizeof (LeafNode);

   DLOG << "LeafPreprocessor created: (" << (finish - start) << " seconds)" << DLOG.EOL ()
          << numberOfPositions << " Position objects each of " << sizeof (Position) << " Bytes." << DLOG.EOL ()
          << rep->getSize () << " Node objects each of " << sizeof (LeafNode) << " Bytes." << DLOG.EOL ()
          << (totalBytes / 1024) << " KBytes (loose) lower bound to preprocessor size." << DLOG.EOL ()
          << DLOG.EOL ();
   DLOG.flush ();

   return rep;
}


//
// LeafNode
//


//
// check if node has any positions for a particular sequence
bool LeafPreprocessor::LeafNode::hasPositions (SequenceDB::ID id) const
{
   return _cluster.hasPositions (id);
}
bool LeafPreprocessor::LeafNode::hasPositions (const SeqWeightFunction& wf) const
{
   //
   // TODO
   return false;
}

//
// returns all the sequences in this node
void LeafPreprocessor::LeafNode::add2SeqCluster (SequenceDB::Cluster& outSeqInNode) const
{
   outSeqInNode.unify (_cluster);
}

void LeafPreprocessor::LeafNode::
   add2SeqClusterPositions (SequenceDB::Cluster& outSeqInNode) const
{
   outSeqInNode.unifyPositions (_cluster);
}

void LeafPreprocessor::LeafNode::
   add2PosCluster (PosCluster& out, Sequence::ID id)  const
{
   const PosCluster* pos = _cluster.getPositions (id);
   if (pos) {
      out.unify (*pos);
   }

}