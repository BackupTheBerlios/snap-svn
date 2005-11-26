#include "Parser.h"
#include "Core/Str.h"


#if ENV_COMPILER==ENV_MICROSOFT
#  include "Legacy/GetOpt.h"
#else
#  include <getopt.h>
#endif

#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;


struct MyOptions {
   char* name;
   char* desc [8];
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

   restoreDefaults ();
}

void Parser::restoreDefaults ()
{
   //
   //
   __proj_e = false;
   __proj_n = 3;
   __proj_d = 4;
   __proj_spec = false;
   USELESS (
    __proj_i; // need to be initialized in main
   );
   __seed_n = 5;
   __seed_l = 9;
   __seed_r = 2;
   __seed_o = 20;
   __prep = _prep_leaf_;
   __prep_noneg = false;

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
   __scoreType = _score_hypegeo_;

   __generatePSSM = true;
   __generateMotif = _motif_all_;

   __perf_m = 5;
   __seed_rr = true;

   __perf_comp_l = _perflencomp_none_;
   __score_norm = _norm_none_;
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
   __SEED_RR,
   __SEED_O,
   __PREP,
   __PREP_NONEG,
   __COUNT,
   __COUNT_REVERSE,
   __SCORE_PARTIAL,
   __SCORE_FDR,
   __SCORE_BONF,
   __SCORE_MIN,
   __SCORE_MIN_SEQ,
   __SCORE_MIN_SEQ_PER,
   __SCORE_NORM,
   __WEIGHT_T,
   __WEIGHT_INTERVAL,
   __WEIGHT_BORDER,
   __WEIGHT_INVERT,
   __SEARCH_TYPE,
   __SCORE_TYPE,
   __PSSM,
   __MOTIF,
   __PERF_M,
   __PERF_COMP_L,
   __CONF
};


static MyOptions my_options [] = { 
   { "Sproj-e", 
     {"[on | off] use exhaustive random projections", 
      NULL
     },
     "off", 
     optional_argument
   },

   {  "Sproj-n",   
      {"<number> of random projections",
       NULL
      },
      "3",
      required_argument
   },

   {  "Sproj-d", 
      {"<number> of wildcards (projection distance)",
       NULL
      },
      "4",
      required_argument
   },

   {  "Sproj-spec",
      {"[on | off] use projection-specialization",
       "(experts use only)",
       NULL
      },
      "off",
      optional_argument
   },

   {  "Sproj-i",
      {"<seed-number> for random projection generator",   
       NULL
      },
      "time",
      required_argument
   },

   {  "Sseed-n",
      {"<number> of seeds to output",
       NULL
      },
      "5",
      required_argument
   },

   {  "Sseed-l",
      {"<length> of seeds to search",
       NULL
      },
      "9",
      required_argument
   },

   {  "Sseed-r",
      {"<offset> to check for redundancy in seeds",
       NULL,
      },
      "2",
      required_argument
   },

   {  "Sseed-rr",
      {"[on | off] should check for reverse-redundancy in seeds",
       NULL,
      },
      "on",
      optional_argument
   },

   {  "Sseed-o",
      {"<length> of seeds to output",
       NULL
      },
      "20",
      required_argument
   },

   {  "Sprep",
      {"<tree | leaf> type of preprocessor",
       NULL
      },
      "leaf",
      required_argument
   },

   {  "Sprep-noneg",
      {"[on | off] removes features with no positive positions",
       "(experts use only)",
       NULL
      },
      "off",
      optional_argument
   },

   {  "Scount",
      {"<gene | total> counting mechanism", 
       NULL
      },
      "gene",
      required_argument
   },

   {  "Scount-reverse",
      {"[on | off] use reverse strand",
       "(enables the reverse-feature-redundancy removal.",
       " but complete the feature is currently", 
       " available only on leaf preprocessor)",
       NULL
      },
      "off",
      optional_argument
   },

   {  "Sscore-partial",
      {"[on | off] use partial counts for scores",
       NULL,
      },
      "off",
      optional_argument
   },

   {  "Sscore-fdr",
      {"[on | off] apply FDR statistical fix",
       NULL,
      },
      "off",
      optional_argument
   },

   {  "Sscore-bonf",
      {"[on | off] apply Bonferroni statistical fix",
       NULL
      },
      "on",
      optional_argument
   },

   {  "Sscore-min",
      {"<min-score or off> for seed",
       NULL
      },
      "0.5",
      required_argument
   },

   {  "Sscore-min-seq",
      {"<min-positive> sequences for seed",
       NULL
      },
      "1",
      required_argument
   },

   {  "Sscore-min-seq-per",
      {"<min-positive> percent of sequences for seed",
       NULL
      },
      "10",
      required_argument
   },

   {  "Sscore-norm",
      {"<none | linear-bg | logit> type of normalization to perform",
       "linear-bg - divides each score by the score-sum of all features found",
       "logit - score = 1 - (e^score / (1 + e^score) )",
       NULL
      },
      "none",
      required_argument
   },

   {  "Sweight-t",
      {"<threshold> for positive sequences",
       NULL
      },
      "0.5",
      required_argument
   },

   {  "Sweight-interval",
      {"<low> defines the interval weight function",
       "all sequences in the interval [low, threshold],"
       "are positives",
       NULL
      },
      "off",
      required_argument
   },

   {  "Sweight-border",
      {"<low> defines the border weight function",
       "all below the threshold are negative", 
       "all above the threshold are positives",
       NULL
      },
      "off",
      required_argument
   },
      
   {  "Sweight-invert",
      {"[on | off] weight function inversion",
       NULL
      },
      "off",
      optional_argument
   },

   {  "Ssearch-t",
      {"<default, table, tree> type of search",
       "(tree-search works only with tree-Preprocessor)",
       NULL
      },
      "default",
      required_argument
   },

   {  "Sscore-t",
      {"<hypegeo, exp> type of score function",
       "choose between hyper-geometric or exponential scoring function",
       NULL
      },
      "hypegeo",
      required_argument
   },

   {  "Spssm",
      {"[on, off] enable/supress generation of .PSSM files",
       NULL
      },
      "on",
      required_argument
   },

   {  "Smotif",
      {"[on, pos, off] enable/supress generation of .Motif files",
      "on => generate all motif files.",
      "pos => gnerate only positive motif files.",
      "off => suppress genration of all motif files.",
       NULL
      },
      "on",
      optional_argument
   },

   {  "Sperf_m",
      {  "<number> determine the number of 'best-positions' to consider",
         "when evaluating a sequence, during seed-performance check",
         NULL
      },
      "5",
      required_argument
   },

   {  "Sperf-comp-l",
      {  "<none | log | linear> type of compensation for sequence length",
         "used in seed performance evaluation",
         NULL
      },
      "none",
      required_argument
   },

   {  "Sconf",
      {  "<filename> name of configuration file",
         NULL
      },
      "empty",
      required_argument
   }
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

   cerr << "Usage: seedSearch [options] <SeqFile> <RegFile> <output stub> " 
	<< endl;
   cerr << "  " << endl;

   for (int i=0 ; i<numberOfOptions ; i++) {
     cout << "--" << my_options [i].name << "\t - "
	  << my_options [i].desc [0] 
	  << " {" 
	  << my_options [i].def 
	  << "}" << endl;
     
     int j=1;
     while (my_options [i].desc [j] != NULL) {
       cout << "\t\t   "
	    << my_options [i].desc [j] << endl; 
       j++;
     }
   }

   cout << endl;
   cout << endl;

   throw ParserError (error);
}



static bool getOptBoolean (char* in, bool* optUnknown = NULL)
{
   if (in == NULL)
      return true;

   Str opt (in);
   if (opt.equalsIgnoreCase ("on") || opt.equalsIgnoreCase ("true"))
      return true;
   else if (opt.equalsIgnoreCase ("off") || opt.equalsIgnoreCase ("false"))
      return false;
   else {
      if (optUnknown == NULL)
         Parser::usage (StrBuffer ("unknown option", in));
      else
         *optUnknown = true;

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

   //
   // very important:
   // we re-initialize getopt's static optind variable back to 0
   // in order to parse the entire argv
   optind = 0;

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

      case __SEED_RR:
         __seed_rr = getOptBoolean (optarg);
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

      case __PREP_NONEG:
         __prep_noneg = getOptBoolean (optarg);
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

      case __SCORE_MIN: {
         bool notBoolean = false;
         bool result = getOptBoolean (optarg, &notBoolean);
         if (notBoolean) {
            __score_min = atof (optarg);
         }
         else {
            if (result == true)
               usage (StrBuffer ("bad minimum score: ", optarg));
            else
               __score_min = -1;
         }
         break;
      }

      case __SCORE_MIN_SEQ:
         __score_min_seq = atoi (optarg);
         break;

      case __SCORE_MIN_SEQ_PER:
         __score_min_seq_per = atoi (optarg);
         break;

      case __SCORE_NORM: {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("none"))
            __score_norm = _norm_none_;
         else if (opt.equalsIgnoreCase ("linear-bg"))
            __score_norm = _norm_linear_background_;
         else if (opt.equalsIgnoreCase ("logit"))
            __score_norm = _norm_logit_;
         else
            usage (StrBuffer ("bad score-norm: ", optarg));
         break;
      };

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
      case __SCORE_TYPE: {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("hypegeo"))
            __scoreType = _score_hypegeo_;
         else if (opt.equalsIgnoreCase ("exp"))
            __scoreType = _score_exp_;
         else
            usage (StrBuffer ("Unknown counting type: ", opt));
         break;
       };

      case __PSSM:
         __generatePSSM = getOptBoolean (optarg);
         break;

      case __MOTIF: {
         bool notBoolean = false;
         bool result = getOptBoolean (optarg, &notBoolean);
         if (notBoolean) {
            Str opt (optarg);
            if (opt.equalsIgnoreCase ("pos"))
               __generateMotif = _motif_pos_;
            else {
               usage (StrBuffer ("bad motif parameter: ", optarg));
            }
         }
         else {
            __generateMotif = result? _motif_all_ : _motif_none_;
         }
         break;
      };

      case __PERF_M:
         __perf_m = atoi (optarg);
         break;

      case __PERF_COMP_L: {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("none"))
            __perf_comp_l = _perflencomp_none_;
         else if (opt.equalsIgnoreCase ("log"))
            __perf_comp_l = _perflencomp_log_;
         else if (opt.equalsIgnoreCase ("linear"))
            __perf_comp_l = _perflencomp_linear_;
         else
            usage (StrBuffer ("bad perf-comp-l: ", optarg));
         break;
      };

      case __CONF:
         __conf = optarg;
         break;

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


void Parser::logParams (Persistance::TextWriter& out) const
{
   out << "Seed length: " << __seed_l << out.EOL ();
   out << "No of Random Positions (dist): " << __proj_d << out.EOL ();

   out << "Preprocessor Type: " << (__prep == _prep_leaf_? "Table" : "Tree") 
       << out.EOL ();
   out << "Count Type: " << (__count == _count_total_? "Total" : "Gene") 
       << out.EOL ();
   out << "Search Type: " 
       << (__searchType == _search_table_? "Table" : "Tree") 
       << out.EOL ();
   out << "Score-Function Type: " 
       << ((__scoreType == _score_hypegeo_)? "HyperGeometric" : "Exponential")
       << out.EOL ();
   out << "Use reverse: " << __count_reverse << out.EOL ();
   out << "Partial count: " << __score_partial << out.EOL ();
   out << "Projection Specialization (expert): " << __proj_spec << out.EOL ();
   out << "Remove negatives (expert): " << __prep_noneg << out.EOL ();

   out << "No of Random Projections: " << __proj_n << out.EOL ();
   out << "Use all possible projections: " << __proj_e << out.EOL ();

   out << "PSSM length: " << __seed_o << out.EOL ();
   out << "No of PSSMs: " << __seed_n << out.EOL ();

   out << "Threshold for pos/neg cluster assignment: " << __weight_t << out.EOL ();
   out << "Weight Function Type: ";
   switch (__weightType) {
      case _weight_simple_:
         out << "Simple" << out.EOL ();
         break;

      case _weight_interval_:
         out << "Interval, low threshold = " << __weight_lowt << out.EOL ();
         break;

      case _weight_border_:
         out << "Border, low threshold = " << __weight_lowt << out.EOL ();
         break;
   };
   out << "Weight Function invert: " << (__weight_invert? "on" : "off") << out.EOL ();
   out << "Maximum offset to check for seed redundancy: " << __seed_r << out.EOL ();
   out << "Check for seed reverse redundancy: " << __seed_rr << out.EOL ();

   out << "Minimum positive sequences a Seed must contain: " << __score_min_seq << out.EOL ();
   out << "Minimum positive sequences a Seed must contain: " << __score_min_seq_per << '%' << out.EOL ();
   out << "Minimum score for seed: ";
   if (__score_min > 0)
      out << "-log10 (" << __score_min << ") = " << -log10 (__score_min) << out.EOL ();
   else
      out << "off" << out.EOL ();


   out << "Use Bonferroni statistical fix: " << __score_bonf << out.EOL ();
   out << "Use FDR statistical fix: " << __score_fdr << out.EOL ();
   out << "Randomization seed: " << __proj_i << out.EOL ();

   out << "Generate PSSM: " << __generatePSSM << out.EOL ();
   out << "Genrate Motif: ";
   switch (__generateMotif) {
      case _motif_all_: out << "all"; break;
      case _motif_pos_: out << "pos"; break;
      case _motif_none_: out << "off"; break;
      default: mustfail ();
   }
   out << out.EOL ();
   out << "#positions considered for sequence during seed-performance check: " 
       << __perf_m << out.EOL ();

   out << "Seq length compensation in performance evaluation: ";
   switch (__perf_comp_l)  {
      case _perflencomp_none_: 
         out << "none"; 
         break;

      case _perflencomp_linear_:
         out << "linear"; 
         break;

      case _perflencomp_log_:
         out << "log"; 
         break;

      default:
         mustfail ();
   }
   out << out.EOL ();


   out << "Score normalization: ";
   switch (__score_norm)  {
      case _norm_none_: 
         out << "none"; 
         break;

      case _norm_linear_background_:
         out << "linear-bg"; 
         break;

      case _norm_logit_:
         out << "logit"; 
         break;

      default:
         mustfail ();
   }
   out << out.EOL ();



   out.flush ();
}


#include<boost/tokenizer.hpp>

//
// only whitespace is delimiter, everything else is kept
class Separator : public boost::char_separator <char> {
  public:
  Separator () : boost::char_separator <char> (" \t") {
  }
};

Argv::Argv (const Str& in) : _argc (0), _argv (NULL)
{
  set (in);
}

Argv::Argv (const Str& prefix, const Str& in) : _argc (0), _argv (NULL)
{
  set (prefix, in);
}


void Argv::set (const Str& prefix, const Str& in)
{
  clear ();

   typedef boost::tokenizer <Separator> Tok;
   Tok tok (in);

   //
   // first we count the number of tokens
   Tok::iterator beg;
   for (beg=tok.begin(); beg!=tok.end();++beg) {
      ++_argc;
   }

   _argv = new char* [++_argc];
   _argv [0] = dup (prefix);

   int index = 1;
   for (beg=tok.begin(); beg!=tok.end();++beg) {
      _argv [index] = dup (*beg);
      index++;
   }
}

void Argv::set (const Str& in)
{
  clear ();

   typedef boost::tokenizer <Separator> Tok;
   Tok tok (in);

   //
   // first we count the number of tokens
   Tok::iterator beg;
   for (beg=tok.begin(); beg!=tok.end();++beg) {
      ++_argc;
   }

   _argv = new char* [_argc];
   int index = 0;
   for (beg=tok.begin(); beg!=tok.end();++beg) {
     int length = (*beg).length () ;
      _argv [index] = new char [length + 1];
      (*beg).copy (_argv [index], length);
      _argv [index][length] = 0;
      index++;
   }
}
