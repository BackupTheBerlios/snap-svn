#ifndef _SeedSearcher_Defs_h
#define _SeedSearcher_Defs_h

//
// File        : $RCSfile: $ 
//               $Workfile: Defs.h $
// Version     : $Revision: 15 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:44 $ 
// Description :
//    Forward definitions and global definitions for the 
//    seed-searcher application
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

#include "core/Defs.h"

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

enum PositionWeightType {
   // {0, 1} counts per sequence
   _position_weight_discrete_,   
   // [0, 1] counts per sequence
   _position_weight_real_,       
   // [0, 1] counts, with possible different weights 
   // for different positions in the same sequence
   _position_weight_hotspots_,   
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











