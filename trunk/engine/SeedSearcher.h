#ifndef _SeedSearcher_SeedSeacher_h
#define _SeedSearcher_SeedSeacher_h

#include "Feature.h"
#include "Assignment.h"
#include "AssignmentFormat.h"
#include "PrefixTreePreprocessor.h"


class SeedSearcher {
public:
   class BestFeatures;
   class BasicParameters;
   class SearchParameters;
   typedef SeqWeightFunction WeightFunction;

public:



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
      virtual Feature& get (int) = 0;
      const Feature& operator [] (int index) const {
         return get (index);
      };
      Feature& operator [] (int index) {
         return get (index);
      };

      virtual bool isSorted () const = 0;
      virtual void sort () = 0;
   };

   class SearchParameters : public FeatureInvestigator::Parameters {
   public:
      SearchParameters () {
      }
      virtual ~SearchParameters () {
      }

      //
      // stores the best features
      const BestFeatures& bestFeatures () const {
         return *_bestFeatures;
      }
      BestFeatures& bestFeatures () {
         return *_bestFeatures;
      }
      //
		// should keep track of all positions
      CountType countType () const {
         return _count;
      }
      //
      // should specialize projections?
      // warning: expert-level feature.
      bool useSpecialization () const {
         return _useSpecialization;
      }

   protected:
      AutoPtr <BestFeatures> _bestFeatures;
      bool _useSpecialization;
      CountType _count;
   };

   //
   // search the tree for seeds that correspond to a projection
   // returns the total number of seeds found
   static int prefixTreeSearch (
         SearchParameters& params,
         const Assignment& projection // how to climb down the tree
         )
   {
      return prefixTreeSearch (params, projection, projection.length ());
   }
   
   //
   // search the tree for seeds that correspond to a projection   
   // returns the total number of seeds found
   static int prefixTreeSearch (
         SearchParameters& params,
         const Assignment& projection, // how to climb down the tree
         int length
         );

   //
   // search the tree for seeds that correspond to a projection (total counts)
   // returns the total number of seeds found
   static int tableSearch (
      SearchParameters& params,
      const Assignment& projection // how to climb down the tree
         );
};

#endif // _SeedSearcher_SeedSeacher_h












