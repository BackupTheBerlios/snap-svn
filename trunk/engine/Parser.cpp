#include "Parser.h"

#include "Core/Str.h"

#if ENV_COMPILER==ENV_MICROSOFT
#  include "Legacy/GetOpt.h"
#else
#  include <getopt.h>
#endif

#include <time.h>
#include <iostream>

using namespace std;


struct MyOptions {
   char* name;
   char* desc;
   char* def;
   int has_arg;
};

//
//
int Parser::__argc = 0;
char** Parser::__argv = NULL;

//
//
int Parser::__firstFileArg = 0;
int Parser::__lastFileArg = 0;

//
//
bool Parser::__proj_e = false;
int Parser::__proj_n = 3;
int Parser::__proj_d = 4;
bool Parser::__proj_spec = true;
int Parser::__proj_i; // need to be initialized in main
int Parser::__seed_n = 5;
int Parser::__seed_l = 9;
int Parser::__seed_r = 2;
int Parser::__seed_o = 20;
Parser::PrepType Parser::__prep = Parser::leaf;
bool Parser::__prep_save = false;
bool Parser::__prep_load = false;
Parser::CountType Parser::__count = Parser::gene;
bool Parser::__score_partial = false;
bool Parser::__count_reverse = false;
bool Parser::__score_fdr = false;
bool Parser::__score_bonf = true;
double Parser::__score_min = 0.5;
int Parser::__score_min_seq = 1;
int Parser::__score_min_seq_per = 10;
double Parser::__weight_t = 0.5;
double Parser::__weight_interval = 0;
double Parser::__weight_border = 0;
bool Parser::__weight_invert = false;
double Parser::__weight_lowt = 0.5;
Parser::WeightType Parser::__weightType = Parser::simple;




enum {
   __PROJ_E,
   __PROJ_N,
   __PROJ_D,
   __PROJ_SPEC,
   __PROJ_I,
   __SEED_N,
   __SEED_L,
   __SEED_R,
   __SEED_O,
   __PREP,
   __PREP_SAVE,
   __PREP_LOAD,
   __COUNT,
   __COUNT_REVERSE,
   __SCORE_PARTIAL,
   __SCORE_FDR,
   __SCORE_BONF,
   __SCORE_MIN,
   __SCORE_MIN_SEQ,
   __SCORE_MIN_SEQ_PER,
   __WEIGHT_T,
   __WEIGHT_INTERVAL,
   __WEIGHT_BORDER,
   __WEIGHT_INVERT,
};

static MyOptions my_options [] = { 
   { "proj-e", 
     "[on | off] use exhaustive random projections", 
     "off", 
     optional_argument
   },

   {  "proj-n",   
      "<number> of random projections",
      "3",
      required_argument
   },

   {  "proj-d", 
      "<number> of wildcards (projection distance)",
      "4",
      required_argument
   },

   {  "proj-spec",
      "[on | off] use projection-specialization optimization",
      "on",
      optional_argument
   },

   {  "proj-i",
      "<seed-number> for random projection generator",   
      "time",
      required_argument
   },

   {  "seed-n",
      "<number> of seeds to output",
      "5",
      required_argument
   },

   {  "seed-l",
      "<length> of seeds to search",
      "9",
      required_argument
   },

   {  "seed-r",
      "<offset> to check for redundancy in seeds",
      "2",
      required_argument
   },

   {  "seed-o",
      "<length> of seeds to output",
      "20",
      required_argument
   },

   {  "prep",
      "<tree | leaf> type of preprocessor",
      "leaf",
      required_argument
   },

   {  "prep-save",
      "save preprocessed data to disk",
      "off",
      no_argument
   },

   {  "prep-load",
      "load preprocessed data from disk",
      "off",
      no_argument
   },

   {  "count",
      "<gene | total> counting mechanism", 
      "gene",
      required_argument
   },

   {  "count-reverse",
      "[on | off] use reverse strand",
      "off",
      optional_argument
   },

   {  "score-partial",
      "[on | off] use partial counts for scores",
      "off",
      optional_argument
   },

   {  "score-fdr",
      "[on | off] apply FDR statistical fix",
      "off",
      optional_argument
   },

   {  "score-bonf",
      "[on | off] apply Bonferroni statistical fix",
      "on",
      optional_argument
   },

   {  "score-min",
      "<min-score> for seed",
      "0.5",
      required_argument
   },

   {  "score-min-seq",
      "<min-positive> sequences for seed",
      "1",
      required_argument
   },

   {  "score-min-seq-per",
      "<min-positive> percent of sequences for seed",
      "10",
      required_argument
   },

   {  "weight-t",
      "<threshold> for positive sequences",
      "0.5",
      required_argument
   },

   {  "weight-interval",
      "<low> all sequences in the interval [low, threshold] are positives",
      "off",
      required_argument
   },

   {  "weight-border",
      "<low> all below are negative, all above threshold are positives",
      "off",
      required_argument
   },
      
   {  "weight-invert",
      "[on | off] weight function inversion",
      "off",
      optional_argument
   },
};

static const int numberOfOptions = sizeof (my_options) / (sizeof (MyOptions));
  


void Parser::usage (const char* error)
{
   cout << endl;
   cout << endl;

   cerr << "Usage: seedSearch [options] <SeqFile> <RegFile> <output stub> " << endl;
   cerr << "  " << endl;

   for (int i=0 ; i<numberOfOptions ; i++) {
      cout << my_options [i].name << "\t - "
                << my_options [i].desc 
                << " {" << my_options [i].def << "}" << endl;
   }

   cout << endl;
   cout << endl;

   if( error != NULL)
      cerr << "Error: " << error << endl;

   debug_mustfail ();
   exit(-1);
}



static bool getOptBoolean (char* in)
{
   if (in == NULL)
      return true;

   Str opt (in);
   if (opt.equalsIgnoreCase ("on") || opt.equalsIgnoreCase ("true"))
      return true;
   else if (opt.equalsIgnoreCase ("off") || opt.equalsIgnoreCase ("false"))
      return false;
   else {
      Parser::usage (StrBuffer ("unknown option", in));
      return false;
   }
}



void Parser::parse (int argc, char* argv[])
{
   __argc = argc;
   __argv = argv;

   //
   // initialize getopt options
   option parserOptions [numberOfOptions + 1];
   for (int i=0 ; i<numberOfOptions ; i++) {
      parserOptions [i].name = my_options [i].name;
      parserOptions [i].has_arg = my_options [i].has_arg;
      parserOptions [i].flag = NULL;
      parserOptions [i].val = i;
   }

   //
   // create a NULL option to terminate the array
   parserOptions [numberOfOptions ].name = NULL;

   //
   // initialize projection seed here
   __proj_i = time (NULL);

   char c;
   int opt_ind;
   while ((c = getopt_long (argc, argv, "", parserOptions, &opt_ind))!=EOF) {
      switch (opt_ind) {
      case __PROJ_E:
         __proj_e = getOptBoolean (optarg);
         break;

      case __PROJ_N:
         __proj_n = atoi (optarg);
         break;

      case __PROJ_D:
         __proj_d = atoi (optarg);
         break;

      case __PROJ_SPEC:
         __proj_spec = getOptBoolean (optarg);
         break;

      case __PROJ_I:
         __proj_i = atoi (optarg);
         break;

      case __SEED_N:
         __seed_n = atoi (optarg);
         break;

      case __SEED_L:
         __seed_l = atoi (optarg);
         break;

      case __SEED_R:
         __seed_r = atoi (optarg);
         break;

      case __SEED_O:
         __seed_o = atoi (optarg);
         break;

      case __PREP:   {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("leaf"))
            __prep = leaf;
         else if (opt.equalsIgnoreCase ("tree"))
            __prep = tree;
         else
            usage (StrBuffer ("unknown preprocessor type ", optarg));
         break;
      }

      case __PREP_SAVE:
         __prep_save = getOptBoolean (optarg);
         break;

      case __PREP_LOAD:
         __prep_load = getOptBoolean (optarg);
         break;

      case __COUNT: {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("gene"))
            __count = Parser::gene;
         else if (opt.equalsIgnoreCase ("total"))
            __count = Parser::total;
         else
            usage (StrBuffer ("Unknown counting type: ", opt));
         break;
      }

      case __SCORE_PARTIAL:
         __score_partial = getOptBoolean (optarg);
         break;

      case __COUNT_REVERSE:
         __count_reverse = getOptBoolean (optarg);
         break;

      case __SCORE_FDR:
         __score_fdr = getOptBoolean (optarg);
         break;

      case __SCORE_BONF:
         __score_bonf = getOptBoolean (optarg);
         break;

      case __SCORE_MIN:
         __score_min = atof (optarg);
         break;

      case __SCORE_MIN_SEQ:
         __score_min_seq = atoi (optarg);
         break;

      case __SCORE_MIN_SEQ_PER:
         __score_min_seq_per = getOptBoolean (optarg);
         break;

      case __WEIGHT_T:
         __weight_t = atof (optarg);
         break;

      case __WEIGHT_INTERVAL:
         __weightType = Parser::interval;
         __weight_lowt = atof (optarg);
         break;

      case __WEIGHT_BORDER:
         __weightType = Parser::border;
         __weight_lowt = atof (optarg);
         break;

      case __WEIGHT_INVERT:
         __weight_invert = getOptBoolean (optarg);
         break;

      default:
         usage (StrBuffer ("unknown argument: ", __argv [optind]));
         break;
      };
   }

   if (__prep_load) { // needs RegFile and output-stub
      __firstFileArg = optind;
      __lastFileArg = optind+1;
   }
   else {   // needs SeqFile RegFile and output-stub
      __firstFileArg = optind;
      __lastFileArg = optind + 2;
   }

   if( __lastFileArg >= argc )
      usage("Missing arguments");
}


