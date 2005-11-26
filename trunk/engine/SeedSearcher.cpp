#include "SeedSearcher.h"
#include "Assignment.h"
#include "Sequence.h"
#include "PrefixTreeWalker.h"
#include "Cluster.h"

#include "DebugLog.h"
#include "Core/HashTable.h"
#include "Persistance/TextWriter.h"
#include "Persistance/StrOutputStream.h"

#include <iostream>

using namespace std;

//
// Gene counts
//


//
// assignment that lead to a node <--> cluster of sequences in the node
typedef std::pair <Assignment*, SequenceDB::Cluster*> FeaturePair;
class FeatureVector : public Vec <FeaturePair> {
};

static void clean (FeaturePair& p)
{
   delete p.first;
   delete p.second;
   p.first = NULL;
   p.second = NULL;
}


struct FeatureComparator : public std::binary_function<FeaturePair, FeaturePair, bool> {
   //
   // features by their assignment
   bool operator() (const FeaturePair& x, const FeaturePair& y) const {
      int result = x.first->compare (*y.first);
      return result < 0;
   }
};

static int together (
   FeatureVector& myFeatures, // stores the features of the node
   int fromIndex,     // from where to start the merge
   int myDepth,   // current depth in the tree
   const Assignment::Position& thisPosition)
{
   debug_mustbe (thisPosition.count () > 0);
   debug_mustbe (thisPosition.strategy () == Assignment::together);

   int size = myFeatures.size ();
   int numFeatures = size - fromIndex;
   if (numFeatures == 0)
      return 0;
   else if (numFeatures == 1) {
      //
      // add the position that got us here to the feature
      myFeatures [fromIndex].first->setPosition (myDepth-1, thisPosition);
      return 1;
   }
   else {
      //
      // all the features that have similar endings are grouped together.
      typedef std::set <FeaturePair, FeatureComparator> FeatureSet;
      FeatureSet features;
      for (int i=fromIndex ; i<size ; i++) {
         myFeatures [i].first->setPosition (myDepth-1, thisPosition);
         std::pair<FeatureSet::iterator, bool> result =
            features.insert (myFeatures [i]);

         if (result.second == false) {
            //
            // it is already in the set...
            /*
            debug_only (
               DLOG << "rec_prefixTreeSearch (): grouping together "
                    << Format (*result.first->first)
                    << " with " 
                    << Format (*myFeatures [i].first)
                    << DLOG.EOL ();
            );
            */

            result.first->second->unify (*myFeatures [i].second);

            //
            // clean memory of this feature
            clean (myFeatures [i]);
         }
      }

      //
      // resize myFeatures and copy the relevant features back from the set
      int newSize = fromIndex + features.size ();
      if (size != newSize) {
         myFeatures.resize (newSize);
         IteratorWrapper <FeatureSet> it (features.begin (), features.end ());
         for (int index=fromIndex ; index<newSize ; it.next (), index++) {
            //
            // add the position that got us here to the feature
            myFeatures [index] = *it;
         }
      }

      return features.size ();
   }
}


//
// returns the amount of new entries in myFeatures vector
static int rec_prefixTreeSearch (
   PrefixTreePreprocessor::NodeRep* inNode,  // where to search
   const Assignment& projection,             // how to climb down the tree
   const SequenceDB::Cluster& positiveCluster,// which sequences are positively labeled
   SeedSearcher::ScoreFunction& scoreFunc,   // how to score features
   FeatureVector& myFeatures,                // stores the features of the node
   int myDepth,                              // current depth in the tree
   int desiredDepth,                         // desired depth / length of features
   int childIndex                            // what is my index as child of my parent
      )
{
   if (inNode == NULL)
      return 0;

   PrefixTreePreprocessor::Node node (inNode);

   //
   // get the cluster of sequences in this node
   AutoPtr <SequenceDB::Cluster> seqInNode =
      new SequenceDB::Cluster;

   node.getCluster (*seqInNode);

   //
   // compute the cluster of positively labeled sequences in this node
   SequenceDB::Cluster posSeqInNode;
   SequenceDB::Cluster::intersect (positiveCluster, *seqInNode, posSeqInNode);

   //
   // optimization. we are saving a lot of time and space
   // by not going over nodes that dont contain any position
   // from the positively labeled cluster
   if (posSeqInNode.empty ()) {
      return 0;
   }

   if (myDepth == desiredDepth) {
      //
      // we are at the desired length
      const Assignment::Position& thisPosition = projection [myDepth -1];
      AutoPtr <Assignment> feature = new Assignment;
      if (thisPosition.strategy () == Assignment::together) {
         //
         // this means that we got here with 'together' strategy
         // so we keep the exact same positions in the feature
         feature->setPosition (myDepth - 1, thisPosition);
         myFeatures.push_back(FeaturePair (feature.release (), 
                                          seqInNode.release ()));
      }
      else {
         debug_mustbe (thisPosition.strategy () == Assignment::discrete);
         //
         // this means that the exact code of this depth is important
         feature->setPosition (myDepth -1, 
            Assignment::Position (childIndex, Assignment::discrete)); 

         myFeatures.push_back (FeaturePair (feature.release (), 
                                          seqInNode.release ()));
      }

      return 1;
   }

   //
   // we have not yet reached the needed length
   // so call the recursive function, for each child that corresponds
   // to a code in the assignment's position
   int newEntries = 0;
   Assignment::PositionIterator posIt (projection [myDepth]);
   for (; posIt.hasNext () ; posIt.next ()) {
      //
      // optimization: since there is no possibility that the child of this node
      // will have more positively labeled sequnces then this node
      // it saves time to search only for positively labeled sequences 
      // that are present in THIS node
      int nextChildIndex = posIt.get ();
      newEntries += 
         rec_prefixTreeSearch (
            node.getChild (nextChildIndex),  // where to search
            projection,             // how to climb down the tree
            posSeqInNode,           // which sequences are positively labeled
            scoreFunc,              // how to score features
            myFeatures,             // stores the features of the node
            myDepth + 1,            // current depth in the tree
            desiredDepth,           // desired depth / length of features
            nextChildIndex          // index of the child
            );
   }

   if (newEntries == 0)
      return 0;

   //
   // now for each new position in the vector, add the position
   // that got us here
   // note: the feature assignment generated this way are backwards
   // we have to reverse them when they are complete
   int size = myFeatures.size ();
   const Assignment::Position& thisPosition = projection [myDepth -1];
   debug_mustbe (thisPosition.count () > 0);

   if (thisPosition.strategy () == Assignment::together) {
      //
      // this means that we got here with 'together' strategy
      // so we keep the exact same positions in the feature.
      //
      // also, the features added are grouped together.
      int firstFeatureIndex = size - newEntries;
      return together (myFeatures, firstFeatureIndex , myDepth, thisPosition);
   }
   else {
      debug_mustbe (thisPosition.strategy () == Assignment::discrete);
      //
      // this means that the exact code of this depth is important
      for (int i= size - newEntries ; i< size ; i++) {
         myFeatures [i].first->setPosition (myDepth-1, 
            Assignment::Position (childIndex, Assignment::discrete)); 
      }
   }

   return newEntries;
}


int SeedSearcher::prefixTreeSearch (
         PrefixTreePreprocessor& tree,       // where to search
         const Assignment& projection,       // how to climb down the tree
         const SequenceDB::Cluster& cluster, // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures,         // stores the best features
         int desiredDepth                    // desired depth / length of features
         )
{
   debug_mustbe (projection.length () > 0);
   debug_mustbe (projection.length () <= tree.getDepth ());
   debug_mustbe (desiredDepth <= projection.length ());
   debug_mustbe (desiredDepth > 0);
   debug_mustbe (cluster.size () > 0);


   PrefixTreePreprocessor::Node node (tree.getRoot ());
   const Assignment::Position& firstPosition = projection[0];
   
   //
   // a projection in the first position is both meaningless
   // and is a lot of hassle to program.
   debug_mustbe (firstPosition.strategy () == Assignment::discrete);

   int totalSeedsFound = 0;

   //
   // optimization: we keep the vector here in order to avoid
   // increasing capacity and then deleting its contents.
   // resize () function does not deallocate space.
   FeatureVector childFeatures;
   Assignment::PositionIterator posIt (firstPosition);
   for (; posIt.hasNext () ; posIt.next ()) {
      int childIndex = posIt.get ();
      FeatureVector childFeatures;
      rec_prefixTreeSearch (
                        node.getChild (childIndex), //where to search
                        projection,    // how to climb down the tree
                        cluster,       // which sequences are positively labeled
                        scoreFunc,     // how to score features
                        childFeatures, // storage for all the child's features
                        1,             // current depth in the tree
                        desiredDepth,  // desired depth / length of features
                        childIndex     // index of the chlid
                        );

      //
      // now we have all the relevant features from our child
      // insert them all to the BestFeatures container
      int size = childFeatures.size ();
      for (int i=0 ; i < size ; i++) {
         const FeaturePair feature = childFeatures [i];

         double score = 
            scoreFunc.score (
               *feature.first,         // the assignment
               projection,             // the projection,
               *feature.second         // sequences containing the feature
               );

         //
         // this also cleans up memory, if necessary
         bestFeatures.add (feature.first,   // the feature's assignment
                           feature.second,  // sequences containing the feature
                           score);


      }
      totalSeedsFound += size;
      childFeatures.resize (0);
   }

   return totalSeedsFound;
}



class TotalCountKey {
public:
   TotalCountKey (const Assignment& inAssg, AssignmentWriter& writer) : _assg (inAssg) {
      std::string hashString;
      {  Persistance::TextWriter textWriter (
            new Persistance::StrOutputStream (hashString));

         textWriter << AssignmentFormat (inAssg, writer);
      }

      _hash = defaultHashFunction (hashString.c_str (), hashString.length ());
   }
   TotalCountKey (const TotalCountKey& o) : _assg (o._assg), _hash (o._hash) {
   }

   HashValue hash () const {
      return _hash;
   }
   const Assignment& assignment () const {
      return _assg;
   }

private:
   Assignment _assg;
   HashValue _hash;
};

class TotalCountFeature : public HashLinkEntry <TotalCountFeature> {
public:
   typedef TotalCountKey Key;
   
   inline TotalCountFeature (const Key& key) : _key (key) {
      _positions = new SeqCluster;
      debug_mustbe (_key.assignment ().length () > 0);
   }
   inline bool fitsKey (const Key& key) {
      return _key.assignment () == key.assignment ();
   }
	inline const Key& getKey() const {
		return _key;
	}
   inline static HashValue hash (const Key& inKey) {
      return inKey.hash ();
   }
   const Assignment& assignment () const {
      return _key.assignment ();
   }

   void removeOverlaps () {
      //
      // get the length of the feature, needed to compute
      // the space required between positions, so that no overlaps occur
      int featureLength = 
         _key.assignment ().length ();

      SeqCluster::Iterator it (_positions->iterator ());
      for (; it.hasNext () ; it.next ()) {
         PosCluster* pos_set = _positions->getPositions (it);
         if (pos_set != NULL) {
            pos_set->removeOverlaps (featureLength);
         }
      }
      //
      // that's it, we have removed all overlaps!!!
   }

   const SeqCluster& positions () const {
      return *_positions;
   }
   SeqCluster* releasePositions () {
      return _positions.release ();
   }

   void addCounts (PrefixTreePreprocessor::Node& node) {
     PrefixTreePreprocessor::SeqPositionIterator posIt =
            node.positionsBySequence ();
         
      for (; posIt.hasNext () ; posIt.next ()) {
         addCounts (posIt->sequence (), *posIt->positions ());
      }
   }

private:
   void addCounts (const Sequence* seq, const Preprocessor::PositionVector& newPositions) {
      debug_mustbe (seq!= NULL);
      PosCluster& pos_set = _positions->getCreatePositions (seq);
      ConstIteratorWrapper <Preprocessor::PositionVector> it (newPositions.begin (), 
                                                              newPositions.end ());
      for (; it.hasNext () ; it.next ()) {
         pos_set.addPosition (*it);
      }
   }



private:
   Key _key;
   AutoPtr <SeqCluster> _positions;
};

typedef HashTable <TotalCountFeature> TotalCountTable;

//
// Total counts
//
int SeedSearcher::totalCountSearch (
   PrefixTreePreprocessor& tree, 
   const Assignment& projection, 
   AssignmentWriter& writer,
   const SequenceDB::Cluster& positivelyLabeled, // which sequences are positively labeled
   SeedSearcher::ScoreFunction& scoreFunc,           // how to score features
   SeedSearcher::BestFeatures& bestFeatures          // stores the best features
   )
{
   debug_mustbe (projection.length () > 0);

   TotalCountTable hashTable (8 * 1024);
   PrefixTreeWalker::Nodes nodes;

   //
   // collect features together, with total counts
   nodes.addAssignmentNodes (tree, projection);
   PrefixTreeWalker::NodeIterator it = nodes.iterator ();
   for (; it.hasNext () ; it.next ()) {
      const PrefixTreeWalker::NodeWithPath& nodeWithPath = it.get ();
      PrefixTreePreprocessor::Node node (nodeWithPath.node ());

      //
      // optimization: get rid of nods with no positions in the positive sequences
      SeqCluster posContaining;
      SeqCluster containing;
      node.getCluster (containing);
      SeqCluster::intersect (containing, positivelyLabeled, posContaining);
      if (posContaining.size () <= 0)
         continue;

      //
      // create the key for this feature
      debug_mustbe (nodeWithPath.path ().length () == projection.length ());
      TotalCountKey key (nodeWithPath.path (), writer);
      
      //
      // search for it in the table
      TotalCountFeature* cachedSeed = hashTable.find (key);
      if (cachedSeed == NULL) {
         //
         // it is a totally new feature
         cachedSeed = new TotalCountFeature (key);
         hashTable.add (cachedSeed);
      }

      //
      // it converges to a feature we already have, so we sum their
      // total counts
      cachedSeed->addCounts (node);
   }

   //
   // now we have to remove position overlaps, e.g. we do not count
   // 'AAAAAA' (6 A's)  as having the feature 'AA' 5 times, but only 3 times 
   // TODO: is this correct?
   TotalCountTable::Iterator featureIt (hashTable);
   for (; featureIt.hasNext () ; featureIt.next ()) {
      TotalCountFeature* feature = featureIt.get ();
      feature->removeOverlaps ();

      //
      // ok. now we have to score each feature and insert it to a BestFeatures container
      double score = 
         scoreFunc.score (feature->assignment (),
                          projection,
                          feature->positions ()// k
                          );
      
      bestFeatures.add (new Assignment (feature->assignment ()),
                        feature->releasePositions (),
                        score);
   }

   return hashTable.getSize ();
}

