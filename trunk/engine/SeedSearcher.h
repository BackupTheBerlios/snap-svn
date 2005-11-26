#ifndef _SeedSearcher_SeedSeacher_h
#define _SeedSearcher_SeedSeacher_h

//
// File        : $RCSfile: $ 
//               $Workfile: SeedSearcher.h $
// Version     : $Revision: 22 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
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

#include "Feature.h"
#include "Assignment.h"
#include "AssignmentFormat.h"
#include "PrefixTreePreprocessor.h"


class SeedSearcher {
public:
   class FeatureFilter;
   class BasicParameters;
   class SearchParameters;
   typedef SeqWeightFunction WeightFunction;

public:

   class FeatureArray {
   public:
      FeatureArray (int k);
      ~FeatureArray ();

      int maxSize () const {
         return _k;
      }
      int size () const {
         return _size;
      }
      void increaseSize () {
         debug_mustbe (_size < _k);
         _size++;
      }
      const Feature& get (int i) const {
         debug_mustbe (i<_size);
         return _features [i];
      }
      Feature& get (int i) {
         debug_mustbe (i<_size);
         return _features [i];
      }
      const Feature& operator [] (int index) const {
         return get (index);
      };
      Feature& operator [] (int index) {
         return get (index);
      };
      void isSorted (bool in) {
         _sorted = in;
      }
      bool isSorted () const {
         return _sorted;
      }
      void sort ();

      //
      // score = 1 - e^score / 1 + e^score
      void normalizeScoresSigmoid ();

      //
      // if highest score is negative multiply all scores by -1
      // t = 1 - lowest_score
      // for each i score(i) += t
      // SIGMA = sum (score(i))
      // for each i score(i) = score(i) / 
      void normalizeScoresLinear ();

   protected:
      int _k;
      int _size;
      Feature* _features;
      bool _sorted;
   };



   class FeatureFilter {
      //
      // this is an interface for a container of features
      // which may implement user-defined strategies as to which
      // features to keep and which to discard
   public:
      virtual ~FeatureFilter () {
      }

      //
      // takes ownership of Assignment & Cluster
      virtual bool add (Feature_var feature) =0;

      FeatureArray* operator -> () { return &(getArray ()); }
      const FeatureArray* operator -> () const { return &(getArray ()); }

      virtual const FeatureArray& getArray () const = 0;
      virtual FeatureArray& getArray () = 0;
   };

   class SearchParameters : public FeatureParameters {
   public:
      SearchParameters () {
      }
      virtual ~SearchParameters () {
      }
      SearchParameters (const SearchParameters& in) {
         set (in);
      }
      SearchParameters& operator = (const SearchParameters& in) {
         set (in);
         return *this;
      }
      void set (const SearchParameters& in) {
         this->FeatureParameters::set (in);

         _bestFeatures = in._bestFeatures;
         _useSpecialization = in._useSpecialization;
         _count = in._count;
      }

      //
      // stores the best features
      const FeatureFilter& bestFeatures () const {
         return *_bestFeatures;
      }
      FeatureFilter& bestFeatures () {
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
      boost::shared_ptr <FeatureFilter> _bestFeatures;
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












