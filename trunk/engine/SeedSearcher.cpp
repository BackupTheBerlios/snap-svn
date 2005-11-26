#include "SeedSearcher.h"

#include "Assignment.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedHash.h"

#include "DebugLog.h"
#include "Core/HashTable.h"
#include "Persistance/TextWriter.h"
#include "Persistance/StrOutputStream.h"

#include <iostream>

using namespace std;


//
// debug: cross-reference tree-search model with prefix-tree-walk model (safer)
#define SEED_TREE_SEARCH_DEBUG 0

#if SEED_TREE_SEARCH_DEBUG
static void compareSeedResult (const PrefixTreePreprocessor& tree,
                               const Assignment& feature,
                               const SequenceDB::Cluster& containingFeature);
#endif



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
   FeatureComparator (int startIndex) : _startIndex (startIndex) {
   }

   //
   // features by their assignment
   bool operator() (const FeaturePair& x, const FeaturePair& y) const {
      int result = x.first->compare (*y.first, _startIndex);
      return result < 0;
   }

   int _startIndex;
};

static int together (FeatureVector& myFeatures, // stores the features of the node
                     int fromIndex,     // from where to start the merge
                     int myDepth
                     )
{
   int size = myFeatures.size ();
   int numFeatures = size - fromIndex;
   if (numFeatures == 0)
      return 0;
   else if (numFeatures == 1) {
      //
      // add the position that got us here to the feature
      return 1;
   }
   else {
      //
      // all the features that have similar endings are grouped together.
      typedef std::set <FeaturePair, FeatureComparator> FeatureSet;
      FeatureComparator comparator (myDepth + 1);
      FeatureSet features (comparator);
      for (int i=fromIndex ; i<size ; i++) {
         //
         // we should be unifying on the '?' wildcard character
         debug_only (
            Assignment::Strategy strategy = 
               myFeatures [i].first->getPosition (myDepth).strategy ();

            debug_mustbe (strategy == Assignment::together);
         );

         //
         //
         std::pair<FeatureSet::iterator, bool> result =
            features.insert (myFeatures [i]);
         
         if (result.second == false) {

            Assignment& resultProjection = 
               *result.first->first;
            
            //
            // it is already in the set...
#           if SEED_TREE_SEARCH_DEBUG
            DLOG << "rec_prefixTreeSearch (): grouping together "
               << Format (resultProjection)
               << " with " 
               << Format (*myFeatures [i].first)
               << DLOG.EOL ();
#           endif
            
            const FeatureSet::iterator& it = result.first;
            SeqCluster* seqCluster = it->second;
            seqCluster->unify (*myFeatures [i].second);

            //
            // now we generalize the projection
            resultProjection [myDepth].unify (
               myFeatures [i].first->getPosition (myDepth));
            
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
// combine child seeds if we have '?' wildcard
static int combineChildSeeds (const Assignment& projection,
                              FeatureVector& myFeatures,
                              int newEntries,
                              int myDepth)
{
   if (projection [myDepth].strategy () == Assignment::together) {
      //
      // this means that we got here with 'together' strategy
      // so we keep the exact same positions in the feature.
      //
      // also, the features added are grouped together.
      int size = myFeatures.size ();
      int firstFeatureIndex = size - newEntries;
      return together (myFeatures, firstFeatureIndex , myDepth);
   }
   
   return newEntries;
}



static void addAssignmentPosition (
              bool specializeProjection,
              const Assignment& projection,
              FeatureVector& myFeatures,
              int childIndex,
              int newEntries,
              int myDepth)
{

   const Assignment::Position& thisPosition = projection [myDepth-1];
   Assignment::Strategy strategy = thisPosition.strategy ();

   int size = myFeatures.size ();  
   if (specializeProjection || (strategy == Assignment::discrete)) {
      //
      // this means that the exact code of this depth is important
      for (int i= size - newEntries ; i< size ; i++) {
         myFeatures [i].first->setPosition (myDepth-1, 
            Assignment::Position (childIndex, strategy)); 
      }
   }
   else {
      debug_mustbe (strategy == Assignment::together);
      //
      // this means that we got here with 'together' strategy
      // without projection specialization option.
      // so we keep the exact same positions in the feature.
      for (int i= size - newEntries ; i< size ; i++) {
         myFeatures [i].first->setPosition (myDepth-1, thisPosition);
      }
   }
}


//
// returns the amount of new entries in myFeatures vector
static int rec_prefixTreeSearch (
      PrefixTreePreprocessor::TreeNodeRep* inNode,  // where to search
      const Assignment& projection,             // how to climb down the tree
      SeedSearcher::WeightFunction& weightFunc, // which seq are positive
      SeedSearcher::ScoreFunction& scoreFunc,   // how to score features
      FeatureVector& myFeatures,    // stores the features of the node
      int myDepth,                  // current depth in the tree
      int desiredDepth, // desired depth / length of features                           
      int childIndex,   // what is my index as child of my parent
      bool specializeProj

      )
{
   if (inNode == NULL)
      return 0;

   PrefixTreePreprocessor::TreeNode node (inNode);

   if (myDepth == desiredDepth) {
      AutoPtr <SequenceDB::Cluster> seqInNode =
         new SequenceDB::Cluster;
   
      node.add2SeqCluster (*seqInNode);

      //
      // we are at the desired length
      myFeatures.push_back(
         FeaturePair (new Assignment, seqInNode.release ()));

      addAssignmentPosition ( specializeProj,
                              projection, 
                              myFeatures, 
                              childIndex, 
                              1, 
                              myDepth);
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
      //
      const int nextChildIndex = posIt.get ();
      const int newChildEntries = 
         rec_prefixTreeSearch (
            node.getChild (nextChildIndex),  // where to search
            projection,             // how to climb down the tree
            weightFunc,             // which sequences are positively labeled
            scoreFunc,              // how to score features
            myFeatures,             // stores the features of the node
            myDepth + 1,            // current depth in the tree
            desiredDepth,           // desired depth / length of features
            nextChildIndex,         // index of the child
            specializeProj
         );

      //
      // 
      newEntries += newChildEntries;
   }
   
   if (newEntries == 0)
      return 0;

   //
   // combine position for chlid if they have together strategy
   newEntries = combineChildSeeds (projection, 
                                   myFeatures, 
                                   newEntries, 
                                   myDepth);

   //
   // add our position to all the features
   addAssignmentPosition ( specializeProj,
                        projection, 
                        myFeatures, 
                        childIndex, 
                        newEntries, 
                        myDepth);
 
   //
   // now for each new position in the vector, add the position
   // that got us here

   return newEntries;
}


int SeedSearcher::prefixTreeSearch (
    PrefixTreePreprocessor& tree,       // where to search
    const Assignment& projection,       // how to climb down the tree
    WeightFunction& weightFunc, // which sequences are pos labeled
    ScoreFunction& scoreFunc,           // how to score features
    BestFeatures& bestFeatures,         // stores the best features
    int desiredDepth,                   // desired depth / length of features
    bool specializeProjection
         )
{
   debug_mustbe (projection.length () > 0);
   debug_mustbe (projection.length () <= tree.getDepth ());
   debug_mustbe (desiredDepth <= projection.length ());
   debug_mustbe (desiredDepth > 0);

   PrefixTreePreprocessor::TreeNode node (tree.getRoot ());
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
		    weightFunc,    // which sequences are positively labeled
		    scoreFunc,     // how to score features
		    childFeatures, // storage for all the child's features
		    1,             // current depth in the tree
		    desiredDepth,  // desired depth / length of features
		    childIndex,    // index of the chlid
          specializeProjection
		    );

      //
      // now we have all the relevant features from our child
      // insert them all to the BestFeatures container
      int size = childFeatures.size ();
      for (int i=0 ; i < size ; i++) {
         const FeaturePair feature = childFeatures [i];

         //
         // only for debbuging
#        if SEED_TREE_SEARCH_DEBUG
            compareSeedResult (tree,
                               *feature.first,  // the assignment
                               *feature.second // sequences containing the feature
                              );
#        endif

         ScoreParameters* scoreParams = NULL;
         double score = 
            scoreFunc.score (
               *feature.first,         // the assignment
               projection,             // the projection,
               *feature.second,        // sequences containing the feature
               &scoreParams
               );

         SeedSearcher::Feature seed_feature (
				      // the feature's assignment 
				      feature.first,
				      // sequences containing the feature  
                  feature.second,
                  &projection,
                  scoreParams,
				      score);
         //
         // this also cleans up memory, if necessary
         bestFeatures.add (&seed_feature);
      }

      totalSeedsFound += size;
      childFeatures.resize (0);
   }

   return totalSeedsFound;
}






struct TableSearcher {
   //
   //
   class Seed : public SeedHash::Cluster {
   public:
      inline Seed (const Key& key) : Cluster (key) {
      }
      virtual ~Seed () {
      }

      int removeOverlaps () {
         //
         // get the length of the feature, needed to compute
         // the space required between positions, so that no overlaps occur
         int featureLength = 
            _key.assignment ().length ();

         int removed = 0;
         SeqCluster::Iterator it (_cluster->iterator ());
         for (; it.hasNext () ; it.next ()) {
            PosCluster* pos_set = _cluster->getPositions (it);
            if (pos_set != NULL) {
               removed += pos_set->removeOverlaps (featureLength);
            }
         }
         //
         // that's it, we have removed all overlaps!!!
         return removed;
      }

      //
      //
      virtual void addPositions (const Preprocessor::Node& node) {
         node.add2SeqClusterPositions (*_cluster);
      }
      //
      //
      virtual void addSequences (const Preprocessor::Node& node) {
         node.add2SeqCluster (*_cluster);
      }
   };

   class SpecializedSeed : public Seed {
   public:
      SpecializedSeed (const Key& key) : Seed (key)   {
         //
         //
         const Assignment& assg  = key.assignment ();
         _specialization = new Assignment (assg);

         //
         // an empty together position
         Assignment::Position together_p (Assignment::together);

         //
         //
         int length = assg.length ();
         for (int i=0 ; i<length ; i++) {
            if (assg [i].strategy () == Assignment::together)
               //
               // make all together positions blank
               _specialization->setPosition (i, together_p);
         }
      }
      virtual ~SpecializedSeed () {
      }

      //
      //
      virtual void addPositions (const Preprocessor::Node& node) {
         node.add2SeqClusterPositions (*_cluster);
         node.add2Assignment (*_specialization);
      }
      //
      //
      virtual void addSequences (const Preprocessor::Node& node) {
         node.add2SeqCluster (*_cluster);
         node.add2Assignment (*_specialization);
      }

      Assignment* releaseSpecializtion () {
         return _specialization.release ();
      }

   protected:
      AutoPtr <Assignment> _specialization;
   };

   //
   //
   class Table : public SeedHash::Table {
   public:
      Table (  bool totalCount,
               bool specialize,
               int tableSize, 
               const AlphabetCode& code, 
               AssignmentWriter& writer)
      :  SeedHash::Table (tableSize, code, writer), 
         _totalCount (totalCount), _specialize (specialize) {
      }
      //
      //
      void addSeed ( const Assignment& projection, 
                     const Preprocessor::Node& node)   {
         SeedHash::AssgKey key (projection, _assgWriter);
   
         //
         // search for it in the table
         Seed* cachedSeed = dynamic_cast <Seed*> (this->find (key));
         if (cachedSeed == NULL) {
            //
            // it is a totally new feature
            cachedSeed = dynamic_cast <Seed*> (createCluster (key));
            this->add (cachedSeed);
         }

         //
         // it converges to a feature we already have
         if (_totalCount) {
            // so we sum their total counts
            cachedSeed->addPositions (node);
         }
         else {
            // so we some their gene counts
            cachedSeed->addSequences (node);
         }
      }

      virtual SeedHash::Cluster* createCluster (const SeedHash::AssgKey& key){
         return _specialize? new SpecializedSeed (key) : new Seed (key);
      }

   protected:
      bool _totalCount;
      bool _specialize;
   };
};

//
// Total counts
//
int SeedSearcher::tableSearch (
   bool totalCount,
   bool specialize,
   const AlphabetCode& code,
   const Preprocessor& data, 
   const Assignment& projection, 
   AssignmentWriter& writer,
   // which sequences are positively labeled
   const SeqWeightFunction& wf,
   SeedSearcher::ScoreFunction& scoreFunc,       // how to score features
   SeedSearcher::BestFeatures& bestFeatures      // stores the best features
   )
{
   debug_mustbe (projection.length () > 0);

   Preprocessor::NodeCluster nodes;
   TableSearcher::Table hashTable ( totalCount,
                                    specialize,
                                    7 * 1023 * 1024 - 1, 
                                    code, 
                                    writer);
   //
   // collect features together, (with optional total counts)
   data.add2Cluster (nodes, projection);
   Preprocessor::NodeIterator it = nodes.iterator ();
   for (; it.hasNext () ; it.next ()) {
      const Preprocessor::AssgNodePair& nodeWithPath = it.get ();
      Preprocessor::Node node (nodeWithPath.node ());
      //
      // 
      debug_mustbe (nodeWithPath.path ().length () == projection.length ());

      hashTable.addSeed (  nodeWithPath.path (), 
                           node);
   }

   //
   // now spit out all the features...
   TableSearcher::Table::Iterator featureIt (hashTable);
   for (; featureIt.hasNext () ; featureIt.next ()) {
      TableSearcher::Seed* feature = 
         dynamic_cast <TableSearcher::Seed*> (featureIt.get ());

      if (totalCount) {
         //
         // now we have to remove position overlaps, e.g. we do not count
         // 'AAAAAA' (6 A's)  as having the feature 'AA' 5 times, but only 3 times 
         //
         // gcc doesnt like unused variable
         // (Even if they are very useful for debugging!)
         USELESS (const int overlappingPositions = )
	          feature->removeOverlaps ();
      }

      ScoreParameters* scoreParams = NULL;
      //
      // ok. now we have to score each feature 
      // and insert it to a BestFeatures container
      double score = 
         scoreFunc.score (feature->assignment (),
                          projection,
                          feature->getCluster (),// k
                          &scoreParams
                          );

      
      
      Assignment* featureAssg;
      if (specialize) {
         featureAssg = 
            dynamic_cast <TableSearcher::SpecializedSeed*> (
               feature)->releaseSpecializtion ();
      }
      else {
         featureAssg = new Assignment (feature->assignment ());
      }

      Feature seed_feature (  featureAssg,
                              feature->releaseCluster (),
                              &projection,
                              scoreParams,
                              score);
      
      bestFeatures.add (&seed_feature);
   }

   return hashTable.getSize ();
}









//
// debug: cross-reference tree-search model with prefix-tree-walk model (safer)
#if SEED_TREE_SEARCH_DEBUG

#  include "DebugLog.h"
#  include "Persistance/TextWriter.h"
#  include "Persistance/StrOutputStream.h"

static void compareSeedResult (const PrefixTreePreprocessor& tree,
                               const Assignment& feature,
                               const SequenceDB::Cluster& containingFeature)
{

   Preprocessor::NodeCluster nodes;
   tree.add2Cluster (nodes, feature);
   AutoPtr <SequenceVector> s = nodes.sequences ();
   int a = s->size ();
   int b = containingFeature.size ();
   if (a != b) {
      try   {
         //
         // intended for use with debugger
         DLOG << "Seed " << Format (feature) << " tree= " << b << " walk= " << a<< DLOG.EOL ();
         DLOG.flush ();
         mustfail ();
      }
      catch (...) {
      }
   }
}

#endif



