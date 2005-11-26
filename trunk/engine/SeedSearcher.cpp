#include "SeedSearcher.h"
#include "Assignment.h"

#include "DebugLog.h"

#include <iostream>

using namespace std;

//
// assignment that lead to a node <--> cluster of sequences in the node
typedef std::pair <Assignment*, SequenceDB::Cluster*> FeaturePair;
class FeatureVector : public Vec <FeaturePair> {
public:
   void reverse ();
};


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
         std::pair<FeatureSet::iterator, bool> result =
            features.insert (myFeatures [i]);

         if (result.second == false) {
            //
            // it is already in the set...
            debug_only (
               DLOG << "rec_prefixTreeSearch (): grouping together "
                    << Format (*result.first->first)
                    << " with " 
                    << Format (*myFeatures [i].first)
                    << DLOG.EOL ();
            );

            result.first->second->unify (*myFeatures [i].second);
         }
         else {
            //
            // add the position that got us here to the feature
            result.first->first->setPosition (myDepth-1, thisPosition);
         }
      }

      //
      // resize myFeatures and copy the relevant features back from the set
      size = fromIndex + features.size ();
      myFeatures.resize (size);
      IteratorWrapper <FeatureSet> it (features.begin (), features.end ());
      for (i=fromIndex ; i<size ; it.next (), i++) {
         myFeatures [i] = *it;
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
/*
      FeaturePair& firstFeature = myFeatures [firstFeatureIndex];
      
      debug_mustbe (firstFeature.first);
      debug_mustbe (firstFeature.second);

      for (int i=firstFeatureIndex + 1; i<size ; i++) {
         debug_only (
            std::cerr << "rec_prefixTreeSearch (): trying to group together "
                      << *firstFeature.first 
                      << " with " 
                      << *myFeatures [i].first
                      << std::endl;
         );
         
         debug_mustbe (*firstFeature.first  == *myFeatures [i].first);
         firstFeature.second->unify (*myFeatures [i].second);
      }
      if (newEntries > 1 ) {
         //
         // get rid of all features except the first one
         myFeatures.resize (firstFeatureIndex + 1);
         newEntries = 1;
      }

      firstFeature.first->setPosition (myDepth-1, thisPosition);
      */
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


void SeedSearcher::prefixTreeSearch (
         PrefixTreePreprocessor& tree,       // where to search
         const Assignment& projection,       // how to climb down the tree
         const SequenceDB::Cluster& cluster, // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures,         // stores the best features
         int desiredDepth                    // desired depth / length of features
         )
{
   debug_mustbe (projection.length () > 0);
   debug_mustbe (projection.length () < tree.getDepth ());
   debug_mustbe (desiredDepth <= projection.length ());
   debug_mustbe (desiredDepth > 0);
   debug_mustbe (cluster.size () > 0);


   PrefixTreePreprocessor::Node node (tree.getRoot ());
   const Assignment::Position& firstPosition = projection[0];
   
   //
   // a projection in the first position is both meaningless
   // and is a lot of hassle to program.
   debug_mustbe (firstPosition.strategy () == Assignment::discrete);

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

      childFeatures.resize (0);
   }
}



/*
void prefixTreeSearch (PrefixTreePreprocessor::NodeRep* inNode,
                     ScoreFunction* scoreFunc,
                     const Assignment& assg,
                     Assignment& feature,
                     int desiredLength,
                     int depth,
                     int childIndex,
                     const SequenceDB::Cluster& cluster,
                     FeatureVector& features) { 
if (inNode == NULL)
   return;

PrefixTreePreprocessor::Node node (inNode);

AutoPtr <SequenceDB::Cluster> positiveSeqInNode =
   new SequenceDB::Cluster;

node.getCluster (cluster, *positiveSeqInNode);

//
// optimization. we are saving a lot of time and space
// by not going over nodes that dont contain any position
// from the positively labeled cluster
if (positiveSeqInNode.empty ()) {
   return;
}

if (depth == desiredLength) {
   //
   // we are at a leaf
   Assignment::Position& thisPosition = assg [depth -1];
   if (thisPosition.strategy () == Assignment::together) {
      //
      // this means that we got here with 'together' strategy
      // so we keep the exact same positions in the feature
      features.add (new FeaturePair (new Assignment::Position (thisPosition), 
                                       positiveSeqInNode.release ());
   }
   else {
      debug_mustbe (thisPosition.strategy () == Assignment::discrete);
      //
      // this means that the exact code of this depth is important
      feature.addPosition (childIndex); 
   }
   



}

bool worthWhile = false;
double score = scoreFunc->score (inNode, &assg, worthWhile);
if (!worthWhile) 
   return;

//
// features of length 0 are meaningless
debug_mustbe (desiredLength > 0);
const Assignment::Position& thisPosition = assg [depth -1];
if (thisPosition.strategy () == Assignment::together) {
   //
   // this means that we got here with 'together' strategy
   // so we keep the exact same positions in the feature
   feature.addPosition (thisPosition);
}
else {
   debug_mustbe (thisPosition.strategy () == Assignment::discrete);
   //
   // this means that the exact code of this depth is important
   feature.addPosition (childIndex); 
}

if (depth == desiredLength) {
   //
   // we have created a worthwhile feature of the desired length.
   // TODO: addd it to the feature container
   return;
}
 
PrefixTreePreprocessor::Node node (inNode);
//
// (1) make a projection then search the tree
//       
// (2) search the tree with all random projections at once

Assignment::PositionIterator posIt (assg [depth]);
//
// it is meaningless to have an assignment with
// with no positions at an index
debug_mustbe (posIt.hasNext ());
for (; posIt.hasNext () ; posIt.next () {
   prefixTreeSearch (node.getChild (posIt.get (),
                     scoreFunc, 
                     assg,
                     desiredLength,
                     depth
                     );
}
}
*/







