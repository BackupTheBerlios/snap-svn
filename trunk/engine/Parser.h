#ifndef _SeedSearcher_Parser_h
#define _SeedSearcher_Parser_h

//
// File        : $RCSfile: $ 
//               $Workfile: Parser.h $
// Version     : $Revision: 28 $ 
//               $Author: Aviad $
//               $Date: 22/11/04 9:36 $ 
// Description :
//    Concrete Parser for seed-searcher options
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


#include "Defs.h"
#include "core/Str.h"
#include "core/Argv.h"
#include "core/GetOptParser.h"
#include "persistance/TextWriter.h"


class Parser {
public:
   Parser ();
   Parser (int argc, char* argv []) {
      *this = Parser ();
      parse (argc, argv);
   }
   Parser (const Argv& inArgv) {
      *this = Parser ();
      parse (inArgv);
   }
   void restoreDefaults ();

   //
   //
   void parse (const Argv& argv) {
      __argv = argv;
      internalParse ();
   }
   void parse (int argc, char* argv[]){
      __argv.set(argc, argv);
      internalParse();
   }
   
   void usage (const char*) const;

   //
   //
   void logParams (Persistance::TextWriter&) const;

   //
   //
   void checkCompatibility (const Parser& in);
   int getNumFileArgs () const {
      return __argv.argc () - __firstFileArg;
   }

   //
   //
   Argv __argv;

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
   // how long is midsection (which is only wildcards)
   int __proj_mid;
   //
   // specialize projection 
   // (expret optimization, may lead to incorrect results)
   bool __proj_spec;
   //
   // seed for random projections 
   int __proj_i;
   //
   // ask for a specific projection (not random)
   StrBuffer __proj_base;
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
   // flag for checking reverse redundancy
   bool __seed_rr;
   //
   // length of seed to output (PSSM length)
   int __seed_o;
   //
   // type of preprocessor
   PrepType __prep;
   //
   // remove totally negative features
   // (expert feature, may lead to incorrect results)
   bool __prep_noneg;
   //
   // how deep/long should preprocessed k-mers be
   int __prep_l;
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
   // score using partial counts (weights) or assg_discrete counts
   bool __score_partial;
   //
   // threshold for counting a sequence as positive
   float __weight_t;
   bool __weight_invert;
   WeightType __weightType;
   float __weight_lowt;

   //
   // which type of search to perform: tree search or table search
   // note: tree search only works with tree preprocessor
   SearchType __searchType;
   ScoreType __scoreType;

   //
   // values for exponential loss score
   float __expLossPos;
   float __expLossNeg;

   enum OutputType {
      _out_all_,
      _out_pos_,
      _out_none_,
   };
   //
   // flag that determines if PSSM files should be created
   OutputType __generatePSSM;
   //
   // flag that determines if .Motif files should be created
   OutputType __generateMotif;
   //
   // flag that determines if .sample file should be created
   OutputType __generateBayesian;
   //
   // (in seed performance test)
   // the number of BestPositions used for each sequence evaluation
   // during seed performance testing
   int __perf_m;
   //
   // performance length compensation
   enum PerfLenComp{
      _perflencomp_none_,
      _perflencomp_linear_,
      _perflencomp_log_
   };
   //
   // (in seed performance test)
   // how to compensate for sequence length 
   PerfLenComp __perf_comp_l;
   //
   // (in seed performance test)
   // 
   enum NormType {
      _norm_none_,
//    _norm_linear_,
      _norm_linear_background_,
//      _norm_log_linear_,
//      _norm_exp_linear_,
      _norm_logit_,
   };
   NormType __score_norm;

   //
   //
   StrBuffer __conf;

   //
   //
   int __firstFileArg;

   bool Parser::getOptBoolean (const char* in, bool* optUnknown = NULL);
   OutputType getOptOutputType(const char*);
   int getInt (const char* in, const char* ctx);
   static GetOptParser::OptionList& getOptions ();

   mutable GetOptParser _impl;

private:
   void internalParse ();
};

#endif

