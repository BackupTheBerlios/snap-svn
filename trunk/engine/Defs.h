#ifndef _SeedSearcher_Defs_h
#define _SeedSearcher_Defs_h

#include "Core/Defs.h"

class AlphabetCode;

class Assignment;
class AssignmentWriter;
class AssignmentFormat;
class PositionFormat;

class Preprocessor;
class PrefixTreePreprocessor;

class Sequence;
class Position;
class SeqCluster;
class PosCluster;
class SequenceDB;


//
// reserve space in vectors while building the tree
#define SEED_RESERVE_VECTOR_SPACE_OPTIMIZATION 1

//
// allocate objects in chunks (reduces calls to new/delete)
#define SEED_CHUNK_ALLOCATION_OPTIMIZATION 1

//
// use Doug Lee's malloc - much better than Microsoft's malloc!
#define SEED_DL_MALLOC_OPTIMIZATION CORE_DL_MALLOC_OPTIMIZATION


#endif // _SeedSearcher_Defs_h










