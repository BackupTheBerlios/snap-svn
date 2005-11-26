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

Parser::Parser ()
{
   //
   //
   __argc = 0;
   __argv = NULL;

   //
   //
   __firstFileArg = 0;
   __lastFileArg = 0;

   //
   //
   __proj_e = false;
   __proj_n = 3;
   __proj_d = 4;
   __proj_spec = true;
   __proj_i; // need to be initialized in main
   __seed_n = 5;
   __seed_l = 9;
   __seed_r = 2;
   __seed_o = 20;
   __prep = _prep_leaf_;
   __prep_save = false;
   __prep_load = false;
   __count = _count_gene_;
   __score_partial = false;
   __count_reverse = false;
   __score_fdr = false;
   __score_bonf = true;
   __score_min = 0.5;
   __score_min_seq = 1;
   __score_min_seq_per = 10;
   __weight_t = 0.5;
   __weight_invert = false;
   __weight_lowt = 0.5;
   __weightType = _weight_simple_;
   __searchType = _search_default_;
}

   
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
   __SEARCH_TYPE
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

   {  "search-t",
      "<default, table, tree> type of search (tree-search works only with tree-prep",
      "default",
      required_argument
   },
};

static const int numberOfOptions = sizeof (my_options) / (sizeof (MyOptions));
  

struct ParserError : public BaseException {
    ParserError (std::string const & s) : _error (s) {
    }

    virtual void explain (std::ostream& out) {
        out << "Error in arguments: " << _error;
    }

    std::string _error;
};

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

   throw ParserError (error);
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
            __prep = _prep_leaf_;
         else if (opt.equalsIgnoreCase ("tree"))
            __prep = _prep_tree_;
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
            __count = _count_gene_;
         else if (opt.equalsIgnoreCase ("total"))
            __count = _count_total_;
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
         __weightType = _weight_interval_;
         __weight_lowt = atof (optarg);
         break;

      case __WEIGHT_BORDER:
         __weightType = _weight_border_;
         __weight_lowt = atof (optarg);
         break;

      case __WEIGHT_INVERT:
         __weight_invert = getOptBoolean (optarg);
         break;

      case __SEARCH_TYPE: {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("default"))
            __searchType = _search_default_;
         else if (opt.equalsIgnoreCase ("table"))
            __searchType = _search_table_;
         else if (opt.equalsIgnoreCase ("tree"))
            __searchType = _search_tree_;
         else
            usage (StrBuffer ("Unknown counting type: ", opt));
         break;
      }

      default:
         usage (StrBuffer ("unknown argument: ", __argv [optind]));
         break;
      };
   }

   __firstFileArg = optind;
   __lastFileArg = argc - 1;

   //
   // validate arguments
   if (__prep != _prep_tree_) {
      if (__searchType == _search_tree_) {
         usage ("Can only use tree-search option with tree-preprocessor");
      }
   }

   if (__searchType == _search_default_)   {
      switch (__prep) {
         case _prep_tree_:
            __searchType = _search_tree_;
            break;

         case _prep_leaf_:
            __searchType = _search_table_;
            break;

         default:
            mustfail ();
            break;
      }
   }
}


