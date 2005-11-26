#ifndef _SeedSearcher_FeatureSet_h
#define _SeedSearcher_FeatureSet_h

//
// File        : $RCSfile: $ 
//               $Workfile: FeatureSet.h $
// Version     : $Revision: 1 $ 
//               $Author: Aviad $
//               $Date: 10/12/04 21:07 $ 
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

class FeatureSet {
public:
   //
   // comparator for assignments
   struct Comparator : public std::binary_function<Feature&, Feature&, bool> {
      //
      // returns true if a<b
      bool operator () (Feature_var a, Feature_var b) {
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
   typedef IteratorWrapper <Features> Iterator;
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
   void insertFeature (Feature_var f) {
      _features.insert(f);
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
   RIterator getRIterator () {
      return RIterator (begin (), end());
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

      //
      // we will insert this into the set only if it is
      // redundant to a worse seed, or it is not redundant to any seed
      Features::iterator it=
         find_if (
            _features.begin (), 
            _features.end (), 
            std::bind2nd (isRedundant, f)
         );
      //            
      if (it == _features.end ()) {
         //
         // it is not redundant to any seed, drop the worst feature and 
         // replace it with this one
         //debug_mustbe (worstFeature().log2bonfScore() == (it-1)->log2bonfScore());
         removeFeature(--it);
         insertFeature (f);
         return true;
      }
      else {
         //
         // f is better than the feature at it 
         // if it should appear before it the sort order
         if (Comparator::a_better_than_b (*f, **it)) {
            debug_mustbe (f->log2bonfScore() <= (*it)->log2bonfScore ());
            removeFeature(it);
            insertFeature (f);
            return true;
         }
         else {
            //
            // we have a redundant seed which is better than our seed
            return false;
         }
      }
   }

   //
   // insert when there is room 
   // replace if there is chan
   template <class _BinFunc>
   bool insertOrReplace1 (Feature_var f, _BinFunc isRedundant, int maxElements) {
      if (size () < maxElements) {
         insertFeature(f);
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
