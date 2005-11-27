#ifndef _SeedSearcher_SeedSeacher_h
#define _SeedSearcher_SeedSeacher_h

//
// File        : $RCSfile: $ 
//               $Workfile: SeedSearcher.h $
// Version     : $Revision: 30 $ 
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
   typedef FeatureSet FeatureArray;
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

      FeatureSet_ptr operator -> () { return getArray (); }
      const FeatureSet_ptr operator -> () const { return getArray (); }

      virtual const FeatureSet_ptr getArray () const = 0;
      virtual FeatureSet_ptr getArray () = 0;

		virtual void finalizeProjection (int /* numSeedsSearched */) { }
		virtual void finalizeSetting (int /* numSeedsSearched */, int /* numProjections */) { }

      virtual FeatureFilter* clone () = 0;
   };
	typedef boost::shared_ptr <FeatureFilter> FeatureFilter_ptr;

   class SearchParameters : public FeatureParameters {
   public:
		SearchParameters () : _useSpecialization (false), _useTotalCount (false) {
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
         _useTotalCount = in._useTotalCount;
      }

      //
      // stores the best features
      const FeatureFilter& bestFeatures () const {
         return *_bestFeatures;
      }
      FeatureFilter& bestFeatures () {
         return *_bestFeatures;
      }
      void bestFeatures (boost::shared_ptr <FeatureFilter> in) {
         _bestFeatures = in;
      }
      //
		// should keep track of all positions
      bool useTotalCount() const {
         return _useTotalCount;
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
      bool _useTotalCount;
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

	static int search (
		SearchType type,
		SearchParameters& params,
		const Assignment& projection // how to climb down the tree
		)
	{
		int currentSeedsFound;
		if (type == _search_tree_) {
			currentSeedsFound = 
				prefixTreeSearch (
					params,
					projection
				);
		}
		else {
			currentSeedsFound = 
				tableSearch (
					params,
					projection
				);
		}
		return currentSeedsFound;
	}
};

#endif // _SeedSearcher_SeedSeacher_h












