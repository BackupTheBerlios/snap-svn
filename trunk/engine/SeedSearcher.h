#ifndef _SeedSearcher_SeedSeacher_h
#define _SeedSearcher_SeedSeacher_h

#include "PrefixTreePreprocessor.h"
#include "Assignment.h"

class AssignmentWriter;

class SeedSearcher {
public:
   class ScoreFunction {
   //
   // this class represents a scoring scheme for features
   // TODO: the bigger the score, the better. right?
   public:
     virtual ~ScoreFunction () {
     }

     virtual double score (const Assignment& feature,
                           const Assignment& projection,
                           const SequenceDB::Cluster& containingFeature // k
                           ) = 0;
   };

   struct Feature {
      //
      // 
   public:
      Feature () : _assg (NULL), _cluster (NULL), _score (0) {
      }
      Feature (Assignment* assg, SequenceDB::Cluster* cluster, double score)
         : _assg(assg), _cluster (cluster), _score (score) {
      }

      Assignment* _assg;
      SequenceDB::Cluster* _cluster;
      double _score;
   };
   


   class BestFeatures {
      //
      // this is an interface for a container of features
      // which may implement user-defined strategies as to which
      // features to keep and which to discard
   public:
      virtual ~BestFeatures () {
      }

      //
      // takes ownership of Assignment & Cluster
      virtual bool add (AutoPtr <Assignment>,
                        AutoPtr <SequenceDB::Cluster>,
                        double score) =0;

      virtual int size () const = 0;
      virtual const Feature& get (int) const = 0;
      const Feature& operator [] (int index) const {
         return get (index);
      };

      virtual bool isSorted () const = 0;
   };


//
//
// Gene-Counts
//
//


   //
   // search the tree for seeds that correspond to a projection
   // returns the total number of seeds found
   static int prefixTreeSearch (
         PrefixTreePreprocessor& tree,       // where to search
         const Assignment& projection,       // how to climb down the tree
         const SequenceDB::Cluster& cluster, // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures          // stores the best features
         )
   {
      return prefixTreeSearch (tree, 
                        projection, 
                        cluster, 
                        scoreFunc, 
                        bestFeatures, 
                        projection.length ());
   }
   
   //
   // search the tree for seeds that correspond to a projection   
   // returns the total number of seeds found
   static int prefixTreeSearch (
         PrefixTreePreprocessor& tree,       // where to search
         const Assignment& projection,       // how to climb down the tree
         const SequenceDB::Cluster& cluster, // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures,         // stores the best features
         int desiredDepth                    // desired depth / length of features
         );

//
//
// Total-Counts
//
//

   //
   // search the tree for seeds that correspond to a projection (total counts)
   // returns the total number of seeds found
   static int totalCountSearch (
      PrefixTreePreprocessor& tree, // where to search
      const Assignment& projection, // how to climb down the tree
      AssignmentWriter& writer,     // (used for hashing)
      const SequenceDB::Cluster& positivelyLabeled, // which sequences are positively labeled
      SeedSearcher::ScoreFunction& scoreFunc,       // how to score features
      SeedSearcher::BestFeatures& bestFeatures      // stores the best features
         );
};

#endif // _SeedSearcher_SeedSeacher_h

