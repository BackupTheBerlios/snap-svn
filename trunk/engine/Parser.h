#ifndef _SeedSearcher_Parser_h
#define _SeedSearcher_Parser_h

#include "Defs.h"
#include "Persistance/TextWriter.h"

class Parser {
public:
   Parser ();
   //
   //
   void parse (int argc, char* argv[]);
   static void usage (const char*);

   void logParams (Persistance::TextWriter&) const;

   //
   //
   int __argc;
   char** __argv;

   //
   // exhaustive projections
   bool __proj_e;
   //
   // number of projections
   int __proj_n;
   //
   // no. of wildcards in projection
   int __proj_d;
   //
   // specialize projection 
   // (expret optimization, may lead to incorrect results)
   bool __proj_spec;
   //
   // seed for random projections 
   int __proj_i;
   //
   // no of seeds to output
   int __seed_n;
   //
   // length of the seed to search for
   int __seed_l;
   //
   // offset for checking seed redundancy
   int __seed_r;
   //
   // length of seed to output (PSSM length)
   int __seed_o;
   //
   // type of preprocessor
   PrepType __prep;
   //
   // remove totaly negative features
   // (expert feature, may lead to incorrect results)
   bool __prep_noneg;
   //
   // type of counting mechanism: gene-count / total count
   CountType __count;
   //
   //
   bool __count_reverse;
   //
   // use FDR statistical fix
   bool __score_fdr;
   //
   // use Bonferroni statistical fix
   bool __score_bonf;
   //
   // worst score to allow
   double __score_min;
   //
   // minimal number to positive sequences for a seed
   int __score_min_seq;
   //
   // minimal percent of positive sequences for a seed
   int __score_min_seq_per;
   //
   // score using partial counts (weights) or discrete counts
   bool __score_partial;
   //
   // theshold for counting a sequence as positive
   double __weight_t;
   bool __weight_invert;
   WeightType __weightType;
   double __weight_lowt;

   //
   // which type of search to perform: tree search or table search
   // note: tree search only works with tree preprocessor
   SearchType __searchType;

   //
   //
   int __firstFileArg;
   int __lastFileArg;
};

#endif

