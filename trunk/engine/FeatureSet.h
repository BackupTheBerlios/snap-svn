#ifndef _SeedSearcher_FeatureSet_h
#define _SeedSearcher_FeatureSet_h

//
// File        : $RCSfile: $ 
//               $Workfile: FeatureSet.h $
// Version     : $Revision: 5 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
// Description :
//    Concrete class describing a set of features.
//    contains algorithms for replacing redundant features
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
// and the library authors apply.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "Feature.h"
#include <set>
#include <boost/functional.hpp>

//
// does looks at the value at it1
// does not look at the value at it2
// returns it1 if not found
template <typename _It, typename _Pred>
_It reverse_find_if (_It it1, _It it2, _Pred p)
{
   _It current = it2;
   for (--current; true ; --current) {
      if (p (*current)) {
         return current;
      }
      if (current == it1) {
         //
         // this is the last seed to compare to
         // so if we got here, it means we failed the search
         return it1;
      }
   }
}

class FeatureSet {
public:
   //
   // comparator for assignments
   struct Comparator : public std::binary_function<Feature&, Feature&, bool> {
      //
      // returns true if a<b
      bool operator () (Feature_var a, Feature_var b) const {
         return a_better_than_b (*a,*b);
      }

      //
      // compares based on: 
      // (1) bonfScore 
      // (2) score 
      // (3) assignment lexicographical-compare
      //
      // returns true if a<b
      static bool a_better_than_b (const Feature& a, const Feature& b);
   };
   typedef std::set <Feature_var, Comparator> Features;
   typedef Features::iterator iterator;
   typedef Features::reverse_iterator reverse_iterator;
	typedef Features::const_iterator const_iterator;
   typedef IteratorWrapper <Features> Iterator;
   typedef CIteratorWrapper <Features> CIterator;
   typedef IteratorWrapper <Features, reverse_iterator> RIterator;

public:
   ~FeatureSet () {
      _features.clear ();
   }
   Feature_var bestFeature() const {
      return *_features.begin ();
   }
   Feature_var worstFeature() const{
      return *_features.rbegin ();
   }
   void removeFeature (iterator it) {
      _features.erase(it);
   }
   bool insertFeature (Feature_var f) {
      std::pair <Features::iterator, bool> result = _features.insert(f);
      return result.second;
   }
	void insertFeatures (iterator begin, iterator end)	{
		_features.insert (begin, end);
	}
   //
   // removes the feature pointed by the iterator from the set
   // and insert the feature f instead
   void replaceFeature (Features::iterator it, Feature_var f) {
      if (it!=_features.end ()) {
         removeFeature(it);
      }
      USELESS (bool result =) insertFeature (f);
      USELESS (debug_mustbe (result));
   }
   int size () {
      return _features.size ();
   }
   iterator begin () {
      return _features.begin();
   }
   iterator end () {
      return _features.end ();
   }
   reverse_iterator rbegin () {
      return _features.rbegin();
   }
   reverse_iterator rend () {
      return _features.rend ();
   }
   Iterator getIterator () {
      return Iterator (begin (), end());
   }
	CIterator getIterator() const {
		return CIterator (_features.begin (), _features.end());
	}
   RIterator getRIterator () {
      return RIterator (begin (), end());
   }
   template <class _BinFunc >
   std::pair <Features::iterator, bool>
      shouldReplace (Feature_var f, _BinFunc isRedundant) 
   {
      //
      // find the BEST-SCORING seed which is redundant with f
      Features::iterator best_scoring_redundant =
         find_if (
            _features.begin (), 
            _features.end (), 
            std::bind2nd (isRedundant, f)
         );

      //            
      if (best_scoring_redundant == _features.end ()) {
         //
         // it is not redundant to any seed, 
         return std::make_pair (_features.end (), true);
      }
      else {
         //
         if (Comparator::a_better_than_b (*f, **best_scoring_redundant)) {
            //
            // f is better than its redundant
            debug_mustbe ( f->log2bonfScore() <= 
               (*best_scoring_redundant)->log2bonfScore ());
            //
            // f is better than the best-scoring seeds which it is redundant with.
            // so we should insert f into the set.
            // but remove the WORST-SCORING seed that f is redundant with
            Features::iterator worst_scoring_redundant =
               reverse_find_if (
               best_scoring_redundant, 
               _features.end (), 
               std::bind2nd (isRedundant, f)
               );

            if (worst_scoring_redundant == _features.end ()) {
               //
               // the best-scoring-redundant is also the worst-scoring-redundant
               worst_scoring_redundant = best_scoring_redundant;
            }

#           if 0
            DLOG << Str ("-------------------") << DLOG.EOL ();
            DLOG << Format (f->assignment()) << DLOG.EOL ();
            DLOG << Format ((*best_scoring_redundant)->assignment()) << DLOG.EOL ();
            DLOG << Format ((*worst_scoring_redundant)->assignment()) << DLOG.EOL ();
            DLOG.flush();
#           endif

            return std::make_pair (worst_scoring_redundant, true);
         }
         else {
            //
            // we have a redundant seed which is better than our seed
            // we cannot 
            return std::make_pair (_features.end (), false);
         }
      }
   }

   //
   // this function replaces a single feature in the set
   // with the given feature, if it is helpful.
   //
   // _BinfFunc should be of the form:
   //    (1) bool func (const Feature&, const Feature&)
   // otherwise if it is a function it should derive from
   //    (2) std::binary_function <Feature&, Feature&, bool>
   template <class _BinFunc >
   bool replace1 (Feature_var f, _BinFunc isRedundant) {
      Feature& wfeature = *worstFeature();
      if (Comparator::a_better_than_b(wfeature, *f)) {
         //
         // this seed is worse than the worst seed in the set
         debug_mustbe (f->log2bonfScore() >= wfeature.log2bonfScore());
         return false;
      }

      std::pair <Features::iterator, bool> result =
         shouldReplace(f, isRedundant);

      if (result.second == false) {
         //
         // it should not be inserted into the set at all
         // because a better-scoring, redundant, seed exists
         return false;
      }
      else {
         if (result.first == _features.end ()) {
            //
            // it is not redundant to any seed, 
            // so drop the worst feature and  replace it with this one
            replaceFeature (--result.first, f);
            return true;
         }
         else {
            //
            // we replace the redundant seed with our seed
            replaceFeature (result.first, f);
            return true;
         }
      }
   }


   //
   // insert when there is room 
   // replace if there is chan
   template <class _BinFunc>
   bool insertOrReplace1 (Feature_var f, _BinFunc isRedundant, int maxElements) {
      if (size () < maxElements) {
         //
         // we insert, unless the seed is redundant to something in the set
         std::pair <Features::iterator, bool> result =
            shouldReplace(f, isRedundant);

         if (result.second) {
            replaceFeature(result.first, f);
         }
         return true;
      }
      else {
         return replace1 (f, isRedundant);
      }
   }

   //
   // returns true if (a contains b) or (b contains a)
   // length of assignments must be the same
   struct SymmetricRedundancyCheck :
      public std::binary_function <AssignmentBase, AssignmentBase, bool>
   {
      bool operator () (const AssignmentBase& a, const AssignmentBase& b) const {
         return check (a,b);
      }

      static bool check (const AssignmentBase& a, const AssignmentBase& b) {
         debug_mustbe (a.length () == b.length ());
         return a.contains (b) || b.contains (a);
      }
   };

   //
   // a = substr (a, 0, length - offset)
   // b = substr (b, offset, length - offset)
   //
   // returns true if (a contains b) or (b contains a)
   // length of assignments must be the same
   struct ASymmetricOffsetRedundancyCheck :
      public std::binary_function <AssignmentBase, AssignmentBase, bool>
   {
      int _offset;
      ASymmetricOffsetRedundancyCheck (int offset) : _offset (offset) {
         debug_mustbe (_offset >= 0);
      }
      bool operator () (const AssignmentBase& a, const AssignmentBase& b) const{
         return check (_offset, a,b);
      }
      static bool check (int offset, const AssignmentBase& a, const AssignmentBase& b);
   };

   //
   // symmetrically looks for ASymmetricOffsetRedundancy
   // for all 0<= offset <= max-offset
   //
   // length of assignments need not be the same
   struct SymmetricMaxOffsetRedundancyCheck :
      public std::binary_function <AssignmentBase, AssignmentBase, bool>
   {
      int _maxoffset;
      SymmetricMaxOffsetRedundancyCheck (int maxoffset) 
      : _maxoffset (maxoffset) {
         debug_mustbe (_maxoffset >= 0);
      }
      bool operator () (const AssignmentBase& a, const AssignmentBase& b) const{
         return check (_maxoffset, a,b);
      }
      static bool check (int offset, const AssignmentBase& a, const AssignmentBase& b);
   };

   template <class _BinFunc>
   struct FeatureRedundancyCheck : 
      public std::binary_function <Feature_var, Feature_var, bool>
   {
      _BinFunc _f;
      FeatureRedundancyCheck (_BinFunc f) :_f (f) {
      }
      
      bool operator () (Feature_var a, Feature_var b) const{
         return _f(a->assignment(), b->assignment());
      }
   };
   template <class _BinFunc>
   static FeatureRedundancyCheck<_BinFunc> 
      featureRedundancyCheck (_BinFunc f) {
         return FeatureRedundancyCheck<_BinFunc> (f);
   }

   template <class _BinFunc>
   struct FeatureReverseRedundancyCheck : 
      public std::binary_function <Feature_var, Feature_var, bool>
   {
      _BinFunc _f;
      const Langauge& _langauge;
      FeatureReverseRedundancyCheck (_BinFunc f, const Langauge& l) 
      :_f (f), _langauge (l) {
      }
      
      bool operator () (Feature_var a, Feature_var b) const {
         return   _f(a->assignment(), b->assignment()) ||
                  _f(a->complement(_langauge), b->assignment());
      }
   };
   template <class _BinFunc>
   static FeatureReverseRedundancyCheck<_BinFunc> 
      featureReverseRedundancyCheck (_BinFunc f, const Langauge& l) {
         return FeatureReverseRedundancyCheck<_BinFunc> (f, l);
   }

private:
   Features _features;
};

#endif
