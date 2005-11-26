#ifndef _SeedSearcher_Parser_h
#define _SeedSearcher_Parser_h

struct Parser {
   //
   //
   static void parse (int argc, char* argv[]);
   static void usage (const char*);

   //
   //
   enum PrepType {
      leaf,
      tree
   };

   //
   //
   enum WeightType {
      simple,
      border,
      interval
   };

   //
   //
   enum CountType {
      total,
      gene
   };

   //
   //
   static int __argc;
   static char** __argv;

   //
   //
   static bool __proj_e;
   static int __proj_n;
   static int __proj_d;
   static bool __proj_spec;
   static int __proj_i;
   static int __seed_n;
   static int __seed_l;
   static int __seed_r;
   static int __seed_o;
   static PrepType __prep;
   static bool __prep_save;
   static bool __prep_load;
   static CountType __count;
   static bool __count_reverse;
   static bool __score_fdr;
   static bool __score_bonf;
   static double __score_min;
   static int __score_min_seq;
   static int __score_min_seq_per;
   static bool __score_partial;
   static double __weight_t;
   static double __weight_interval;
   static double __weight_border;
   static bool __weight_invert;
   static WeightType __weightType;
   static double __weight_lowt;

   //
   //
   static int __firstFileArg;
   static int __lastFileArg;
};

#endif
