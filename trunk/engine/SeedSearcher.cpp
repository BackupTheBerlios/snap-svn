#include "SeedSearcher.h"

#include "Assignment.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedHash.h"

#include "DebugLog.h"
#include "Core/HashTable.h"
#include "Persistance/TextWriter.h"
#include "Persistance/StrOutputStream.h"

#include "boost/timer.hpp"

#include <iostream>
#include <time.h>

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
typedef std::pair <Assignment*, SequenceDB::Cluster*> FeaturePairBase;
struct FeaturePair : 
   public FeaturePairBase
{
   FeaturePair () {
   }
   FeaturePair (Assignment* assg, SequenceDB::Cluster* cluster) 
   : FeaturePairBase (assg, cluster) {
   }
};

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
                     int myDepth,
                     bool totalCount
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
      // all the features that have similar endings are grouped assg_together.
      typedef std::set <FeaturePair, FeatureComparator> FeatureSet;
      FeatureComparator comparator (myDepth + 1);
      FeatureSet features (comparator);
      for (int i=fromIndex ; i<size ; i++) {
         //
         // we should be unifying on the '?' wildcard character
         debug_only (
            Assignment::Strategy strategy = 
               myFeatures [i].first->getPosition (myDepth).strategy ();

            debug_mustbe (strategy == assg_together);
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
            DLOG << "rec_prefixTreeSearch (): grouping assg_together "
               << Format (resultProjection)
               << " with " 
               << Format (*myFeatures [i].first)
               << DLOG.EOL ();
#           endif
            
            const FeatureSet::iterator& it = result.first;
            SeqCluster* seqCluster = it->second;
            if (totalCount) {
               seqCluster->unifyPositions (*myFeatures [i].second);
            }
            else {
               seqCluster->unify (*myFeatures [i].second);
            }

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
                              int myDepth,
                              bool totalCount)
{
   if (projection [myDepth].strategy () == assg_together) {
      //
      // this means that we got here with 'assg_together' strategy
      // so we keep the exact same positions in the feature.
      //
      // also, the features added are grouped assg_together.
      int size = myFeatures.size ();
      int firstFeatureIndex = size - newEntries;
      return together (myFeatures, firstFeatureIndex , myDepth, totalCount);
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
   if (specializeProjection || (strategy == assg_discrete)) {
      //
      // this means that the exact code of this depth is important
      for (int i= size - newEntries ; i< size ; i++) {
         myFeatures [i].first->setPosition (myDepth-1, 
            Assignment::Position (childIndex, strategy)); 
      }
   }
   else {
      debug_mustbe (strategy == assg_together);
      //
      // this means that we got here with 'assg_together' strategy
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
      SeedSearcher::SearchParameters& params,
      PrefixTreePreprocessor::TreeNodeRep* inNode,  // where to search
      const Assignment& projection,             // how to climb down the tree
      FeatureVector& myFeatures,    // stores the features of the node
      int myDepth,                  // current depth in the tree
      int desiredDepth, // desired depth / length of features                           
      int childIndex   // what is my index as child of my parent
      )
{
   if (inNode == NULL)
      return 0;

   PrefixTreePreprocessor::TreeNode node (inNode);

   if (myDepth == desiredDepth) {
      AutoPtr <SequenceDB::Cluster> seqInNode =
         new SequenceDB::Cluster;
   
      if (params.countType () == _count_total_) 
		   node.add2SeqClusterPositions (*seqInNode);
      else
         node.add2SeqCluster (*seqInNode);

      //
      // we are at the desired length
      myFeatures.push_back(
         FeaturePair (new Assignment, seqInNode.release ()));

      addAssignmentPosition ( params.useSpecialization (),
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
            params,
            node.getChild (nextChildIndex),  // where to search
            projection,             // how to climb down the tree
            myFeatures,             // stores the features of the node
            myDepth + 1,            // current depth in the tree
            desiredDepth,           // desired depth / length of features
            nextChildIndex          // index of the child
         );

      //
      // 
      newEntries += newChildEntries;
   }
   
   if (newEntries == 0)
      return 0;

   //
   // combine position for chlid if they have assg_together strategy
   newEntries = combineChildSeeds (projection, 
                                   myFeatures, 
                                   newEntries, 
                                   myDepth,
                                   params.countType () == _count_total_);

   //
   // add our position to all the features
   addAssignmentPosition ( 
                        params.useSpecialization (),
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
      SearchParameters& params,
      const Assignment& projection, // how to climb down the tree
      int desiredDepth              // desired depth / length of features
         )
{
   const PrefixTreePreprocessor& tree = 
      dynamic_cast <const PrefixTreePreprocessor&> (params.preprocessor ());

   debug_mustbe (projection.length () > 0);
   debug_mustbe (projection.length () <= tree.getDepth ());
   debug_mustbe (desiredDepth <= projection.length ());
   debug_mustbe (desiredDepth > 0);

   PrefixTreePreprocessor::TreeNode node (tree.getRoot ());
   const Assignment::Position& firstPosition = projection[0];
   
   //
   // a projection in the first position is both meaningless
   // and is a lot of hassle to program.
   debug_mustbe (firstPosition.strategy () == assg_discrete);

   int totalSeedsFound = 0;
   double totalTimeEvaluatingSeeds = 0;

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
         params,
         node.getChild (childIndex), //where to search
         projection,    // how to climb down the tree
         childFeatures, // storage for all the child's features
         1,             // current depth in the tree
         desiredDepth,  // desired depth / length of features
         childIndex    // index of the chlid
      );

      boost::timer t;

      //
      // now we have all the relevant features from our child
      // insert them all to the FeatureFilter container
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
            params.score ().log2score (
               *feature.first,         // the assignment
               projection,             // the projection,
               *feature.second,        // sequences containing the feature
               &scoreParams
               );

         Feature seed_feature (
				      // the feature's assignment 
				      feature.first,
				      // sequences containing the feature  
                  feature.second,
                  &projection,
                  scoreParams,
				      score);
         //
         // this also cleans up memory, if necessary
         params.bestFeatures ().add (&seed_feature);
      }
      //
      // accumolate times
      totalTimeEvaluatingSeeds += t.elapsed ();

      totalSeedsFound += size;
      childFeatures.resize (0);
   }

   DLOG << "[Evaluating seeds: " << (time_t) totalTimeEvaluatingSeeds << " seconds] ";
   return totalSeedsFound;
}






struct TableSearcher {
   //
   //
   class AbstractSeed : public SeedHash::Cluster <AbstractSeed> {
   public:
      inline AbstractSeed (const Key& key) 
      : SeedHash::Cluster <AbstractSeed> (key) 
      {
      }

      virtual ~AbstractSeed () {
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
      virtual void addPositions (const Preprocessor::Node& node)=0;
      virtual void addSequences (const Preprocessor::Node& node)=0;

   };
   class Seed : 
      public AbstractSeed,
      public POOL_ALLOCATED(Seed)
   {
   public:
      inline Seed (const Key& key) : AbstractSeed (key) {
      }
      virtual ~Seed () {
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

   class SpecializedSeed : 
      public AbstractSeed,
      public POOL_ALLOCATED(SpecializedSeed)
   {
   public:
      SpecializedSeed (const Key& key) : AbstractSeed (key)   {
         //
         //
         const Assignment& assg  = key.assignment ();
         _specialization = new Assignment (assg);

         //
         // an empty assg_together position
         Assignment::Position together_p (assg_together);

         //
         //
         int length = assg.length ();
         for (int i=0 ; i<length ; i++) {
            if (assg [i].strategy () == assg_together)
               //
               // make all assg_together positions blank
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
   typedef SeedHash::Table <AbstractSeed> SeedHashTableBase;
   class Table : public SeedHashTableBase{
   public:
      Table (  bool totalCount,
               bool specialize,
               int tableSize, 
               const Langauge& langauge)
      :  SeedHashTableBase (tableSize, langauge), 
         _totalCount (totalCount), _specialize (specialize) {
      }
      //
      //
      void addSeed ( const Assignment& projection, 
                     const Preprocessor::Node& node)   {
         SeedHash::AssgKey key (projection, _langauge);
   
         //
         // search for it in the table
         AbstractSeed* cachedSeed = this->find (key);
         if (cachedSeed == NULL) {
            //
            // it is a totally new feature
            cachedSeed = createCluster (key);
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

      virtual AbstractSeed* createCluster (const SeedHash::AssgKey& key){
         if (_specialize)
            return new SpecializedSeed (key);
         else
            return new Seed (key);
      }

   protected:
      bool _totalCount;
      bool _specialize;
   };
};

//
// Total counts
//
int SeedSearcher::tableSearch (  SearchParameters& params,
                                 const Assignment& projection)
{
   debug_mustbe (projection.length () > 0);

   Preprocessor::NodeCluster nodes;
   TableSearcher::Table hashTable ( params.countType () == _count_total_,
                                    params.useSpecialization (),
                                    7 * 1023 * 1024 - 1,
                                    params.langauge ());
   //
   // collect features assg_together, (with optional total counts)
   params.preprocessor ().add2Cluster (nodes, projection);
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

   time_t start = time (NULL), finish;
   DLOG << "[Evaluating seeds: ";
   DLOG.flush ();

   //
   // now spit out all the features...
   TableSearcher::SeedHashTableBase::Iterator featureIt (hashTable);
   for (; featureIt.hasNext () ; featureIt.next ()) {
      TableSearcher::Seed* feature = 
         dynamic_cast <TableSearcher::Seed*> (featureIt.get ());

      if (params.countType () == _count_total_) {
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
      // and insert it to a FeatureFilter container
      double score = 
         params.score ().log2score (
                  feature->assignment (),
                  projection,
                  feature->getCluster (),// k
                  &scoreParams
         );
      
      Assignment* featureAssg;
      if (params.useSpecialization ()) {
         featureAssg = 
            safe_cast (TableSearcher::SpecializedSeed*, 
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
      
      params.bestFeatures ().add (&seed_feature);
   }

   finish = time (NULL);
   DLOG << (finish - start) << " seconds.] ";

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




void SeedSearcher::FeatureArray::normalizeScoresSigmoid ()
{
   for (int i=0 ; i<_size;i++) {
      Feature& feature = get (i);
      double score = feature.log2score ();
      double P = pow (M_E, score);
      feature.log2score (1 - (P / (1+P)));
   }
}

struct SortComparator{
   //
   // put the best scores first
   bool operator () (const Feature& a, const Feature& b) {
      return a.log2score () < b.log2score ();
   }
};

void SeedSearcher::FeatureArray::sort ()
{
   std::sort (_features, _features + _size, SortComparator ());
   _sorted = true;
}

SeedSearcher::FeatureArray::FeatureArray (int k)
: _k (k), _size (0)
{
   debug_mustbe (_k > 0);
   _features = new Feature [_k];
}

SeedSearcher::FeatureArray::~FeatureArray ()
{
   for (int i=0 ; i<_size ; i++)
      _features [i].dispose ();

   delete [] _features;
}

