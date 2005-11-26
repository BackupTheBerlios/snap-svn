#ifndef _SeedSearcher_Defs_h
#define _SeedSearcher_Defs_h

#include "Core/Defs.h"

class AlphabetCode;

class Assignment;
class Langauge;
class AssignmentFormat;
class PositionFormat;

class Preprocessor;
class PrefixTreePreprocessor;

class Sequence;
class SeqPosition;
class SeqCluster;
class PosCluster;
class SequenceDB;
class PositionVector;

class RandomProjections;
class PSSM;

//
//
enum PrepType {
   _prep_leaf_,
   _prep_tree_
};

enum SearchType {
   _search_default_,
   _search_table_,
   _search_tree_, // works only with _prep_tree_ 
};

//
//
enum WeightType {
   _weight_simple_,
   _weight_border_,
   _weight_interval_
};

//
//
enum CountType {
   _count_total_,
   _count_gene_
};

enum ScoreType {
    _score_hypegeo_,
    _score_exp_

};

enum Strand {
   _strand_pos_= true,
   _strand_neg_ = false,
};




//
// reserve space in vectors while building the tree
#define SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION 1

//
// allocate objects in pools (reduces calls to new/delete)
#define SEED_POOL_ALLOCATION_OPTIMIZATION 0

#if SEED_POOL_ALLOCATION_OPTIMIZATION
   //
   // inherit from TPoolAllocated class
#  define POOL_ALLOCATED(T) TPoolAllocated<T>
#else
   //
   // dummy class
   class TStdAllocated {
   };
   
   //
   // inherit from dummy class instead
#  define POOL_ALLOCATED(T) TStdAllocated
#endif

//
// use Doug Lee's malloc - much better than Microsoft's malloc!
#define SEED_DL_MALLOC_OPTIMIZATION CORE_DL_MALLOC_OPTIMIZATION



#endif // _SeedSearcher_Defs_h











