//
// File        : $RCSfile: $ 
//               $Workfile: SeedSearcher.cpp $
// Version     : $Revision: 39 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:11 $ 
// Description :
//    Concrete class for seed-searching in a preprocessor
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

#include "SeedSearcher.h"

#include "Assignment.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedHash.h"

#include "DebugLog.h"
#include "core/HashTable.h"
#include "persistance/TextWriter.h"
#include "persistance/StrOutputStream.h"

#include <boost/timer.hpp>

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
   
      if (params.useTotalCount()) 
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
                                   params.useTotalCount ());

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
		boost::shared_ptr <SearchParameters> params,
      const Assignment& projection, // how to climb down the tree
      int desiredDepth              // desired depth / length of features
         )
{
   const PrefixTreePreprocessor& tree = 
		*safe_cast (const PrefixTreePreprocessor*, &(params->preprocessor ()));

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
      rec_prefixTreeSearch (
         *params,
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

         Feature_var seed_feature (new Feature);
			FeatureParameters::createFeature (params,
            *seed_feature,
            // the feature's assignment 
            feature.first,
            // sequences containing the feature  
            feature.second,
            &projection
            );

         //
         // this also cleans up memory, if necessary
         params->bestFeatures ().add (seed_feature);
      }
      //
      // accumolate times
      totalTimeEvaluatingSeeds += t.elapsed ();

      totalSeedsFound += size;
      childFeatures.resize (0);
   }

   DLOG << "[Evaluating seeds: " << static_cast <int> (totalTimeEvaluatingSeeds) << " seconds] ";
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
      virtual void addPositions (const Preprocessor::Node& node)=0;
      virtual void addSequences (const Preprocessor::Node& node)=0;

   };
   class Seed : public AbstractSeed
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

	struct SeedComparator {
		inline bool operator ()(	const TableSearcher::AbstractSeed* a, 
													const TableSearcher::AbstractSeed* b) {
			return (a->assignment().compare (b->assignment()) < 0);
		}
	};

   class SpecializedSeed : public AbstractSeed
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

	struct SeedVector : public Vec <AbstractSeed*> {
		~SeedVector () {
			for (iterator i = begin () ; i!= end () ; ++i) {
				delete *i;
			}
		}
	};
};



static const int DEFAULT_SEED_HASH_TABLE_SIZE = 7 * 1023 * 1024 - 1;

static void
createFeatureTable (	TableSearcher::SeedVector& outVector,
						   TableSearcher::Table& hashTable,
							SeedSearcher::SearchParameters& params,
                     const Assignment& projection)
{
   //
   // collect features assg_together, (with optional total counts)
   Preprocessor::NodeCluster nodes;
   params.preprocessor ().add2Cluster (nodes, projection);
   Preprocessor::NodeIterator it = nodes.iterator ();
   for (; it.hasNext () ; it.next ()) {
      const Preprocessor::AssgNodePair& nodeWithPath = it.get ();
      Preprocessor::Node node (nodeWithPath.node ());
      //
      // 
      debug_mustbe (nodeWithPath.path ().length () == projection.length ());

      hashTable.addSeed (nodeWithPath.path (), node);
   }

	//
	// sort the features into a vector of features
	// this is in order to have consistent results across search algorithms
	// and across preprocessors
	reserveClear(outVector, 
		hashTable.TableSearcher::Table::HashTableBase::getSize ());
	TableSearcher::SeedHashTableBase::Iterator featureIt (hashTable);
	for (; featureIt.hasNext () ; featureIt.next ()) {
		//
		// put the feature in the vector
		outVector.push_back (safe_cast (TableSearcher::AbstractSeed*, featureIt.get ()));
	}
	std::sort (outVector.begin (), outVector.end (), 
					TableSearcher::SeedComparator ());

	//
	// we don't want the table to delete our features
	// so we clear it
	hashTable.clear(/* do not delete elements */ false);
}

static int extendedTableSearch (
										  boost::shared_ptr <SeedSearcher::SearchParameters> params,
                  const Assignment& projection)
{
   //
   // TODO: support specialization

   //
   // constants for later use
   const int prefixLength = params->preprocessor().maxAssignmentSize();
   const int postfixLength = projection.length () - prefixLength;
   const int totalLength = prefixLength + postfixLength;

   const SubAssignment projectionPrefix (projection, 0, prefixLength);
   const SubAssignment projectionPostfix (projection, prefixLength);
   //
   // make sure SubAssignments work well
   debug_mustbe (
      projectionPrefix.length () + projectionPostfix.length () == projection.length ());

	TableSearcher::SeedVector seeds;
	{
		//
		// now we want to create a unified view of preprocessor-nodes 
		// according to the projection's prefix
		TableSearcher::Table shortHashTable ( 
			/* use total count because we need the positions */ true,
			/* don't use specialization */ false,
			DEFAULT_SEED_HASH_TABLE_SIZE,
			params->langauge ());

      //
      // get all the nodes of the preprocessor up to maximum length
      Preprocessor::NodeCluster nodes;
      params->preprocessor ().add2Cluster (nodes, projectionPrefix);
      createFeatureTable (seeds, shortHashTable, *params, projectionPrefix);
   }

   //
   // all the variables below are defined outside the loops
   // for efficiency - less new/delete
   //
   // seqCluster - used by outer loop
   SeqCluster seqCluster;

   //
   // used by inner loop
   Assignment currentAssgPostfix;
   PositionVector currentPositions;
   PositionVector nextPositions;
   AutoPtr <SeqCluster> currentSeqCluster = new SeqCluster;
   int seedsFound = 0;

   //
   // go over all unified nodes
	IteratorWrapper < TableSearcher::SeedVector > featureIt (seeds.begin (), seeds.end ());
   for (; featureIt.hasNext () ; featureIt.next ()) {
      TableSearcher::AbstractSeed* feature = featureIt.get ();

      //
      // get the node's assignment and positions
      const Assignment& currentAssgPrefix = feature->assignment ();
      SeqCluster::SeqPosIterator seqPosIt (feature->getCluster().posIterator ());
      for (; seqPosIt.hasNext() ; seqPosIt.next ()) {
         //
         // discard positions too close to the end
         if (seqPosIt.get ()->maxLookahead () >= totalLength) {
            currentPositions.push_back(seqPosIt.get ());
         }
      }

      //
      // now we look at all the available ways to 'extend' the node
      // we work with just one assignment at a time to be memory-conservative
      while (!currentPositions.empty ()) {
         debug_mustbe (nextPositions.empty ());
         debug_mustbe (seqCluster.empty ());
         PositionIterator posIt (currentPositions.begin (), currentPositions.end ());
         //
         // determine current working assignment:
         // it is the first position's assignment, generalized to fit
         // the wildcards in the projection
         {
            bool shouldTryAgain;
            bool assgFitsProjection;
            const SeqPosition* current;
            do {
               Str actualPostfixSeed = (*posIt)->getSeedString (postfixLength, prefixLength);
               Assignment actualPostfixAssg (actualPostfixSeed, params->langauge ().code ());
               assgFitsProjection = 
                  currentAssgPostfix.specialize(actualPostfixAssg, projectionPostfix);

               current = &(*(*posIt));
               posIt.next ();
               shouldTryAgain = !assgFitsProjection && posIt.hasNext ();
            }
            while (shouldTryAgain);
            if (assgFitsProjection) {
               PosCluster& posCluster = 
                  currentSeqCluster->getCreatePositions (current->sequence ());
               posCluster.addPosition (current);
            }
            else {
               debug_mustbe (!posIt.hasNext ());
            }
         }

         //
         // go over all positions left in this node
         for (; posIt.hasNext() ; posIt.next ()) {
            //
            // the position's assignment
            Assignment posAssignment (
               (*posIt)->getSeedString (postfixLength, prefixLength),
               params->langauge ().code ()
               );
            debug_mustbe (currentAssgPostfix.length () == posAssignment.length ());
            if (currentAssgPostfix.contains (posAssignment)) {
               /*
               DLOG << Format (currentAssgPostfix)
                     << " contains "
                     << Format (posAssignment)
                     << DLOG.EOL ();
               DLOG.flush ();
               */
               //
               // this position fits with the current working assignment
               // add it later (at the end of the loop) for efficiency
               PosCluster& posCluster = 
                  currentSeqCluster->getCreatePositions ((*posIt)->sequence ());
               posCluster.addPosition (*posIt);
            }
            else {
               //
               // this position does not fit with current working assignment
               // we will examine it again later
               nextPositions.push_back(*posIt);
            }
         }

         if (!currentSeqCluster->empty ()) {
            //
            // extend the node's assg-prefix with the current-working-assg
            Assignment* completeAssignment = 
               new Assignment (currentAssgPrefix);
            completeAssignment->addAssignmentAt (prefixLength, currentAssgPostfix);
            debug_mustbe (completeAssignment->length () == projection.length ());

            //
            // 1. the prefixes are unique because they are unified-nodes
            // 2. the postfixes are unique because we are working 
            //       one (generalized) assignment at a time
            //
            // so we actually know all the positions for the complete
            // (generalized) assignment right now! so we score the seed
            // right here. this design is due to memory limitations.
            // remember, if we had more memory, we could just have created
            // a deeper preprocessor, right?
            Feature_var seed_feature (new Feature);
				FeatureParameters::createFeature(params,
               *seed_feature,
               completeAssignment,
               currentSeqCluster.release(),
               &projection);

            params->bestFeatures ().add (seed_feature);
            currentSeqCluster = new SeqCluster;

            seedsFound++;
         }

         //
         // now concentrate on those position that did not match
         // any of the former working-assignments
         currentPositions = nextPositions;
			reserveClear (nextPositions);
      } // finished with one unified-node, next one please
   } // finished all nodes, bye!

   return seedsFound;
}

//
// Total counts
//
int SeedSearcher::tableSearch (  boost::shared_ptr <SearchParameters> params,
                                 const Assignment& projection)
{
   debug_mustbe (projection.length () > 0);
   if (projection.length () <= params->preprocessor ().maxAssignmentSize ()) {

		TableSearcher::SeedVector seeds;
		{
			TableSearcher::Table hashTable ( 
				params->useTotalCount (),
				params->useSpecialization (),
				DEFAULT_SEED_HASH_TABLE_SIZE,
				params->langauge ());

			createFeatureTable(seeds, hashTable, *params, projection);
		}

      time_t start = time (NULL), finish;
      DLOG << "[Evaluating seeds: ";
      DLOG.flush ();

      //
      // now spit out all the features...
		IteratorWrapper < TableSearcher::SeedVector > featureIt (seeds.begin (), seeds.end ());
      for (; featureIt.hasNext () ; featureIt.next ()) {
         TableSearcher::AbstractSeed* feature = featureIt.get ();

         //
         // overlaps are not counted when using total-counts
         // this is implemented in the score-function, no need
         // to do anything here
         Assignment* featureAssg;
         if (params->useSpecialization ()) {
            featureAssg = 
               safe_cast (TableSearcher::SpecializedSeed*, 
               feature)->releaseSpecializtion ();
         }
         else {
            featureAssg = new Assignment (feature->assignment ());
         }

         Feature_var seed_feature (new Feature);
			FeatureParameters::createFeature(
				params,
            *seed_feature,
            featureAssg,
            feature->releaseCluster (),
            &projection);

         params->bestFeatures ().add (seed_feature);
      }

      finish = time (NULL);
      DLOG << static_cast <int>(finish - start) << " seconds.] ";

      return seeds.size ();
   }
   else {
      return extendedTableSearch (params, projection);
   }
}



//
// debug: cross-reference tree-search model with prefix-tree-walk model (safer)
#if SEED_TREE_SEARCH_DEBUG

#  include "DebugLog.h"
#  include "persistance/TextWriter.h"
#  include "persistance/StrOutputStream.h"

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
