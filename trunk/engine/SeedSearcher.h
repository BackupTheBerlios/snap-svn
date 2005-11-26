#ifndef _SeedSearcher_SeedSeacher_h
#define _SeedSearcher_SeedSeacher_h

#include "PrefixTreePreprocessor.h"
#include "Assignment.h"

class AssignmentWriter;

class SeedSearcher {
public:
   //
   // this class is used to test the correctness of SeedSearcher.
   // the score function, by recording the score parameters
   // for a feature, used for later printing.
   struct ScoreParameters {
      virtual ~ScoreParameters () {
      }
      virtual void dispose () {
         delete this;
      }
   };

   typedef SeqWeightFunction WeightFunction;



   class ScoreFunction {
   //
   // this class represents a scoring scheme for features
   // the smaller (more negative) the score, the better.
   public:
     virtual ~ScoreFunction () {
     }

     //
     // if 'parameters' is NULL, do not return ScoreParameters.
     virtual double score (const Assignment& feature,
                           const Assignment& projection,
                           const SequenceDB::Cluster& containingFeature, // k
                           ScoreParameters** parameters
                           ) = 0;

     //
     // print the score parameters 
     virtual void writeAsText (Persistance::TextWriter&, const ScoreParameters*) = 0;
   };

   struct Feature {
      //
      // 
   public:
      Feature () : _assg (NULL), _cluster (NULL), _params (0), _score (0) {
      }
      Feature (Assignment* assg, 
               SequenceDB::Cluster* cluster, 
               ScoreParameters* params,
               double score)
         : _assg(assg), _cluster (cluster), _params (params), _score (score) 
      {
      }

      void dispose () {
         debug_only (
            //
            // guard against repetitive calls to delete
            debug_mustbe (_score != 0xBAADF00D);
            _score = 0xBAADF00D;
            debug_mustbe (_score == 0xBAADF00D);
         );

         delete _assg;     _assg = NULL;
         delete _cluster;  _cluster = NULL;
         if (_params) {
            _params->dispose ();
            _params = NULL;
         }
      }

      struct Owner {
	      inline static void acquire(Feature*) {
	      }
 	      inline static void release(Feature* ptr) {
 		      if (ptr) ptr->dispose ();
 	      }
      };

      Assignment* _assg;
      SequenceDB::Cluster* _cluster;
      ScoreParameters* _params;
      double _score;
   };
   //
   // CORBA notation used here... :-)
   typedef Feature* Feature_ptr;
   typedef AutoPtr <Feature, Feature::Owner> Feature_var;


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
      virtual bool add (Feature_var feature) =0;

      virtual int size () const = 0;
      virtual const Feature& get (int) const = 0;
      const Feature& operator [] (int index) const {
         return get (index);
      };

      virtual bool isSorted () const = 0;
      virtual void sort () = 0;
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
         WeightFunction& weightFunc,         // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures,         // stores the best features
         bool specializeProjections          // should specialize projections?
         )
   {
      return prefixTreeSearch (tree, 
                        projection, 
                        weightFunc, 
                        scoreFunc, 
                        bestFeatures, 
                        projection.length (),
                        specializeProjections
                        );
   }
   
   //
   // search the tree for seeds that correspond to a projection   
   // returns the total number of seeds found
   static int prefixTreeSearch (
         PrefixTreePreprocessor& tree,       // where to search
         const Assignment& projection,       // how to climb down the tree
         WeightFunction& weightFunc,         // which sequences are positively labeled
         ScoreFunction& scoreFunc,           // how to score features
         BestFeatures& bestFeatures,         // stores the best features
         int desiredDepth,                   // desired depth / length of features
         bool specializeProjections          // should specialize projections?
         );

//
//
// Total-Counts
//
//

   //
   // search the tree for seeds that correspond to a projection (total counts)
   // returns the total number of seeds found
   static int tableSearch (
      bool totalCount,
      bool specialization,
      const AlphabetCode& code,
      const Preprocessor& data, // where to search
      const Assignment& projection, // how to climb down the tree
      AssignmentWriter& writer,     // (used for hashing)
      const SeqWeightFunction& positivelyLabeled,   // which sequences are positively labeled
      SeedSearcher::ScoreFunction& scoreFunc,       // how to score features
      SeedSearcher::BestFeatures& bestFeatures      // stores the best features
         );
};

#endif // _SeedSearcher_SeedSeacher_h











