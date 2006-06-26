#ifndef _SeedSearcher_Defs_h
#define _SeedSearcher_Defs_h

//
// File        : $RCSfile: $ 
//               $Workfile: Defs.h $
// Version     : $Revision: 21 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:07 $ 
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
#include <boost/shared_ptr.hpp>

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


class FeatureSet;
typedef boost::shared_ptr <FeatureSet> FeatureSet_ptr;

//
//
enum PrepType {
   _prep_leaf_,
   _prep_tree_
};

enum SearchType {
   _search_default_ = - 1,
   _search_table_ = _prep_leaf_,
   _search_tree_ = _prep_tree_ // works only with _prep_tree_ 
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

enum StatFixType {
	_statfix_none_,
	_statfix_bonf_,// use Bonferroni statistical fix
	_statfix_fdr_	// use FDR statistical fix
};


//
// reserve space in vectors while building the tree
#define SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION 1

//
// use Doug Lee's malloc - much better than Microsoft's malloc!
#define SEED_DL_MALLOC_OPTIMIZATION CORE_DL_MALLOC_OPTIMIZATION



#endif // _SeedSearcher_Defs_h











