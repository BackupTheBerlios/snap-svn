#ifndef _SeedSearcher_Parser_h
#define _SeedSearcher_Parser_h

#include "Defs.h"
#include "Core/Str.h"
#include "Persistance/TextWriter.h"

class Argv{
   //
   // utlitity class for argv
public:
   Argv () : _argc (0), _argv (NULL) {
   }
   Argv (int argc, char** argv) : _argc (0), _argv (NULL) {
      set (argc, argv);
   }
   Argv (const Argv& in) : _argc (0), _argv (NULL) {
      set (in);
   }
   Argv (const Str& in);
   Argv (const Str& prefix, const Str& in);
   ~Argv () {
      clear ();
   }

   Argv& operator = (const Argv& argv) {
      set (argv);
      return *this;
   };

   //
   // create argv from a single string
   void set (const Str&);
   //
   // create argv from a prefix, and a string
   void set (const Str& prefix, const Str&);

   void set (const Argv& in) {
      set (in._argc, in._argv);
   }
   void set (int argc, char** argv) {
      mustbe (argc >= 0);
      clear ();
      _argc = argc;
      _argv = new char* [_argc];
      for (int i=0 ; i<_argc ; i++)
         _argv [i] = dup (argv [i]);
   }

   void clear () {
      if (_argv != NULL) {
         for (int i=0 ; i<_argc ; i++)
            delete [] _argv[i];

         delete [] _argv;
         _argv = NULL;
         _argc = 0;
      }
   }

   int argc () const {
      return _argc;
   }
   char ** argv () const {
      return _argv;
   }
   bool empty () const {
      return _argc == 0;
   }


   template <typename StringT>
   static char* dup (StringT& s)   {
     StrBuffer temp = Str (s);
     return temp.release ();
   }

protected:
   int _argc;
   char** _argv;
};


class Parser {
public:
   Parser ();
   void restoreDefaults ();

   //
   //
   void parse (const Argv& argv) {
      parse (argv.argc (), argv.argv ());
   }
   void parse (int argc, char* argv[]);
   static void usage (const char*);

   //
   //
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
   // flag for checking reverse redundancy
   bool __seed_rr;
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
   // score using partial counts (weights) or assg_discrete counts
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
   ScoreType __scoreType;

   enum MotifType {
      _motif_all_,
      _motif_pos_,
      _motif_none_,
   };
   //
   // flag that determines if PSSM files should be created
   bool __generatePSSM;
   //
   // flag that determines if .Motif files should be created
   MotifType __generateMotif;
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
   int __lastFileArg;
};

#endif

