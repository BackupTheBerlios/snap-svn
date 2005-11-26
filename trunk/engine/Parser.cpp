//
// File        : $RCSfile: $ 
//               $Workfile: Parser.cpp $
// Version     : $Revision: 42 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
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


#include "Parser.h"
#include "core/Str.h"

#include <time.h>
#include <iostream>
#include <math.h>

#include "core/GetOptParser.h"
#include "DebugLog.h"
using namespace std;






struct ParserError : public BaseException {
   ParserError (std::string const & s) 
		: BaseException (std::string ("Error in arguments: ") + s) {
   }
};






bool Parser::getOptBoolean (const char* in, bool* optUnknown)
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

Parser::OutputType Parser::getOptOutputType(const char* optarg)
{
   bool notBoolean = false;
   bool result = getOptBoolean (optarg, &notBoolean);
   if (notBoolean) {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("pos"))
         return Parser::_out_pos_;
      else {
         usage (StrBuffer ("bad motif parameter: ", optarg));
         return Parser::_out_none_;
      }
   }
   else {
      return result? Parser::_out_all_ : Parser::_out_none_;
   }
}

int Parser::getInt (const char* in, const char* option_name)
{
   if (!in)
      usage (StrBuffer ("missing arguments for: ", option_name));

   int out;
   int result = sscanf (in, "%d", &out);
   if (result != 1)
      usage (StrBuffer ("not an integer: ", in));

   return out;
}

#define GET_SEED_PARSER_OPTION_CLASS(name) Option_##name
#define REGISTER_SEED_PARSER_OPTION_CLASS(name, list) \
   list.add (new GET_SEED_PARSER_OPTION_CLASS(name));

#define DEFINE_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, EXEC_CODE, P_CODE) \
struct Option_##name : public GetOptParser::Option {                 \
   Option_##name () : GetOptParser::Option (NAME, DESC, DEF, ARG) {  \
   }                                                                 \
                                                                     \
   virtual void execute (const char* optarg, void* ctx) {            \
      execute (optarg, reinterpret_cast <Parser*> (ctx));            \
   }                                                                 \
   void execute (const char* optarg, Parser* parser) {               \
      EXEC_CODE;                                                     \
   }                                                                 \
   virtual void param (StrBuffer& out, void* ctx) {                  \
      param (out, reinterpret_cast <Parser*> (ctx));                 \
   }                                                                 \
   void param (StrBuffer& out, Parser* parser) {                     \
      P_CODE;                                                        \
   }                                                                 \
};

static inline void bool_set_option (Parser* parser, const char* name, const char* optarg, bool& value)
{  value = parser->getOptBoolean (optarg);   }

static inline void bool_get_option (const char* name, bool value, StrBuffer& out)
{  out = (value? "on" : "off");  }

#define DEFINE_BOOL_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, OPT) \
   DEFINE_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, { bool_set_option (parser, _name, optarg, parser-> OPT);}, { bool_get_option (_name, parser-> OPT, out); } )

#define DEFINE_INT_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, OPT) \
   DEFINE_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, { parser-> OPT = parser->getInt (optarg, _name); }, { out = FixedStrBuffer <128>("%d", (int) parser-> OPT).getStr (); } )

#define DEFINE_STRING_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, OPT) \
   DEFINE_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, { parser-> OPT = optarg; }, { out = parser-> OPT; } )

#define DEFINE_OUTPUT_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG, OPT) \
   DEFINE_SEED_PARSER_OPTION(name, NAME, DESC, DEF, ARG,    \
   { parser-> OPT = parser->getOptOutputType (optarg); },  \
   {  switch (parser-> OPT) {                              \
         case Parser::_out_all_: out = "on";  break;                \
         case Parser::_out_pos_: out = "pos"; break;                \
         case Parser::_out_none_: out = "off"; break;                \
         default: mustfail ();                              \
      }                                                     \
   })



DEFINE_STRING_SEED_PARSER_OPTION(
   conf,
   "Sconf",
   "<filename> name of configuration file",
   "",
   GetOptWrapper::_required_argument_,
   __conf
);      


DEFINE_BOOL_SEED_PARSER_OPTION (
   proj_e,
   "Sproj-e", 
   "[=on | =off] use exhaustive random projections",
   "off", 
   GetOptWrapper::_optional_argument_,
   __proj_e
);


DEFINE_INT_SEED_PARSER_OPTION(
   proj_n,
   "Sproj-n", 
   "<number> of random projections",
   "3", 
   GetOptWrapper::_required_argument_,
   __proj_n
);

DEFINE_INT_SEED_PARSER_OPTION(proj_d,
   "Sproj-d", 
   "<number> of wildcards (projection distance)",
   "4", 
   GetOptWrapper::_required_argument_,
   __proj_d
);

DEFINE_INT_SEED_PARSER_OPTION(proj_mid,
   "Sproj-mid", 
   "<number> of wildcards enforced in middle section",
   "0", 
   GetOptWrapper::_required_argument_,
   __proj_mid
);

DEFINE_BOOL_SEED_PARSER_OPTION(proj_spec,
   "Sproj-spec", 
   "[=on | =off] use projection-specialization (experts use only)",
   "off", 
   GetOptWrapper::_optional_argument_,
   __proj_spec
);

DEFINE_INT_SEED_PARSER_OPTION(proj_i,
   "Sproj-i", 
   "<seed-number> for random projection generator (expert use only)\n"
      "if set to non-zero value it forces Random-Projections to behave predictably",
   "0",
   GetOptWrapper::_required_argument_,
   __proj_i
);

DEFINE_STRING_SEED_PARSER_OPTION(proj_base,
      "Sproj-base", 
      "<assignment> the basic assignment on which to project.\n"
         "not specifying this option is exactly the same as "
         "specifying this option with an assignment of '*' of the "
         "same length as specified in the --Sseed-l option."
         "examples:\n"
         "(1) --Sproj-base ACG*?GG --Sproj-e"
         "this will generate all possible projections on ACG*?GG"
         "which means that the '?' will always remain while the '*'"
         "is substituted for A, C, G, T in turn.\n"
         "examples:\n"
         "(2) \"--Sproj-base *****\" is equivalent to \"--Sseed-l 5\"",
      "",
      GetOptWrapper::_required_argument_,
      __proj_base 
);

DEFINE_INT_SEED_PARSER_OPTION(seed_n,
   "Sseed-n",
   "<number> of seeds to output",
   "5",
   GetOptWrapper::_required_argument_,
   __seed_n
);


DEFINE_INT_SEED_PARSER_OPTION(seed_l,
   "Sseed-l",
   "<length> of seeds to search",
   "9",
   GetOptWrapper::_required_argument_,
   __seed_l
);

DEFINE_INT_SEED_PARSER_OPTION(seed_r,
   "Sseed-r",
   "<offset> to check for redundancy in seeds",
   "2",
   GetOptWrapper::_required_argument_,
   __seed_r
);


DEFINE_BOOL_SEED_PARSER_OPTION(seed_rr,
   "Sseed-rr",
   "[=on | =off] should check for reverse-redundancy in seeds",
   "on",
   GetOptWrapper::_optional_argument_,
   __seed_rr
);

DEFINE_INT_SEED_PARSER_OPTION(seed_o,
   "Sseed-o",
   "<length> of seeds to output",
   "20",
   GetOptWrapper::_required_argument_,
   __seed_o
);


DEFINE_SEED_PARSER_OPTION(prep,
   "Sprep",
   "<tree | leaf> type of preprocessor",
   "leaf",
   GetOptWrapper::_required_argument_,
   {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("leaf"))
         parser->__prep = _prep_leaf_;
      else if (opt.equalsIgnoreCase ("tree"))
         parser->__prep = _prep_tree_;
      else
         parser->usage (StrBuffer ("unknown preprocessor type ", optarg));
   },
   {
      switch (parser->__prep) {
         case _prep_leaf_: out = "leaf"; break;
         case _prep_tree_: out = "tree"; break;
         default: mustfail ();
      }
   }
);

DEFINE_INT_SEED_PARSER_OPTION(
   prep_l,
   "Sprep-l",
   "<maximum-length> of preprocessed seeds.\n"
      "if this option is set to -1, it defaults to "
      "the length set in --Sseed-l. "
      "this feature is useful to limiting memory consumption.",
   "-1",
   GetOptWrapper::_required_argument_,
   __prep_l
);

DEFINE_BOOL_SEED_PARSER_OPTION(
   prep_noneg,
   "Sprep-noneg",
   "[=on | =off] removes features with no positive positions (experts use only)",
   "off",
   GetOptWrapper::_optional_argument_,
   __prep_noneg
);

DEFINE_SEED_PARSER_OPTION(
   count,
   "Scount",
   "<gene | total> counting mechanism", 
   "gene",
   GetOptWrapper::_required_argument_,
   {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("gene"))
         parser->__count = _count_gene_;
      else if (opt.equalsIgnoreCase ("total"))
         parser->__count = _count_total_;
      else
         parser->usage (StrBuffer ("Unknown counting type: ", opt));
   },
   {
      switch (parser->__count) {
         case _count_gene_: out = "gene"; break;
         case _count_total_: out = "total"; break;
         default: mustfail ();
      }
   }
);


DEFINE_BOOL_SEED_PARSER_OPTION(
   count_reverse,
   "Scount-reverse",
   "[=on | =off] use reverse strand",
   "off",
   GetOptWrapper::_optional_argument_,
   __count_reverse
);

DEFINE_SEED_PARSER_OPTION(
   score_partial,
   "Sscore-partial",
   "[=on | =off | =hotspots] use partial counts for scores",
   "off",
   GetOptWrapper::_optional_argument_,
   {
      bool notBoolean = false;
      bool result = parser->getOptBoolean (optarg, &notBoolean);
      if (notBoolean) {
         Str opt (optarg);
         if (opt.equalsIgnoreCase ("hotspots"))
            parser->__score_partial = _position_weight_hotspots_;
         else {
            parser->usage (StrBuffer ("bad partial score parameter: ", optarg));
         }
      }
      else {
         parser->__score_partial = 
            result? _position_weight_real_ : _position_weight_discrete_;
      }
   },
   {
      switch (parser->__score_partial) {
         case _position_weight_hotspots_: out = "hotspots"; break;
         case _position_weight_real_:     out = "on"; break;
         case _position_weight_discrete_: out = "off"; break;
         default: mustfail ();
      };
   }
);

DEFINE_SEED_PARSER_OPTION(
   score_t,
   "Sscore-t",
   "< hypegeo | exp:<pos_loss>:<neg_loss> > type of score function."
      " choose between hyper-geometric or exponential scoring function",
   "hypegeo",
   GetOptWrapper::_required_argument_,
   {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("hypegeo"))
         parser->__scoreType = _score_hypegeo_;
      else if (opt.startsWith ("exp:", true)) {
         parser->__scoreType = _score_exp_;
         int result = sscanf (optarg + 4, "%f:%f", 
                  &parser->__expLossPos, &parser->__expLossNeg);
         if (result != 2) 
            parser->usage (StrBuffer ("Bad exp score format: ", opt));
      }
      else
         parser->usage (StrBuffer ("Unknown counting type: ", opt));
   },
   {
      switch (parser->__scoreType) {
         case _score_hypegeo_:   out = "hypegeo"; break;
         case _score_exp_:       
            out = FixedStrBuffer <128> ("exp:%f:%f", 
                                        (double) parser->__expLossPos, 
                                        (double) parser->__expLossNeg).getStr ();
            break;
         default: mustfail ();
      }
   }
);

DEFINE_BOOL_SEED_PARSER_OPTION(
   score_fdr,
   "Sscore-fdr",
   "[=on | =off] apply FDR statistical fix",
   "off",
   GetOptWrapper::_optional_argument_,
   __score_fdr
);

DEFINE_BOOL_SEED_PARSER_OPTION(
   score_bonf,
   "Sscore-bonf",
   "[=on | =off] apply Bonferroni statistical fix",
   "on",
   GetOptWrapper::_optional_argument_,
   __score_bonf
);


DEFINE_SEED_PARSER_OPTION(
   score_min,
   "Sscore-min",
   "<min-score> for seed",
   "0.5",
   GetOptWrapper::_required_argument_,
   {  parser->__score_min = atof (optarg); },
   {  out = FixedStrBuffer <128> ("%f", (double) parser->__score_min).getStr (); }
);

DEFINE_INT_SEED_PARSER_OPTION(
   score_min_seq,
   "Sscore-min-seq",
   "<min-positive> sequences for seed",
   "1",
   GetOptWrapper::_required_argument_,
   __score_min_seq
);

DEFINE_INT_SEED_PARSER_OPTION(
   score_min_seq_per,
   "Sscore-min-seq-per",
   "<min-positive> percent of sequences for seed",
   "10",
   GetOptWrapper::_required_argument_,
   __score_min_seq_per
);

DEFINE_SEED_PARSER_OPTION(
   weight_t,
   "Sweight-t",
   "< <threshold-value>       | \n"
   "  interval:<low>:<high>   | \n"
   "  border:<low>:<high>     > type of weight function.\n"
      " => 'threshold': neg=[0, thrshd], pos=[thrshd, 1]\n"
      " => 'interval':  neg=[0,low] U [hi, 1], pos=[low, hi]\n"
      " => 'border':    neg=[0,low], irrelevant=[low, hi], pos=[hi, 1]",
   "0.5",
   GetOptWrapper::_required_argument_,
   {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("interval")) {
         parser->__weightType = _weight_interval_;
         int result = sscanf (optarg, "interval:%f:%f", 
            &parser->__weight_lowt, &parser->__weight_t);
         
         if (result != 2) 
            parser->usage (StrBuffer ("Bad interval weight format: ", opt));
      }
      else if (opt.startsWith ("border", true)) {
         parser->__weightType = _weight_border_;
         int result = sscanf (optarg, "border:%f:%f", 
            &parser->__weight_lowt, &parser->__weight_t);

         if (result != 2) 
            parser->usage (StrBuffer ("Bad border weight format: ", opt));
      }
      else if (sscanf (optarg, "%f", &parser->__weight_t) == 1) {
         parser->__weightType = _weight_simple_;
      }
      else {
         parser->usage (StrBuffer ("Unknown weight function type: ", opt));
      }
   },
   {
      switch (parser->__weightType){
         case _weight_simple_: 
            out = FixedStrBuffer <128> ("%f", (double) parser->__weight_t).getStr ();
            break;
         case _weight_interval_:
            out = FixedStrBuffer<128> ("interval:%f:%f", 
                                       (double) parser->__weight_lowt, 
                                       (double) parser->__weight_t).getStr ();
            break;
         case _weight_border_:
            out = FixedStrBuffer<128> ("border:%f:%f", 
                                       (double) parser->__weight_lowt, 
                                       (double) parser->__weight_t).getStr ();
            break;
         default: mustfail ();
      }
   }
);


DEFINE_BOOL_SEED_PARSER_OPTION(
   weight_invert,
   "Sweight-invert",
   "[=on | =off] weight function inversion",
   "off",
   GetOptWrapper::_optional_argument_,
   __weight_invert
);      


DEFINE_SEED_PARSER_OPTION(
   search_t,
   "Ssearch-t",
   "<default, table, tree> type of search"
      " (tree-search works only with tree-Preprocessor)",
   "default",
   GetOptWrapper::_required_argument_,
   {
      Str opt (optarg);
      if (opt.equalsIgnoreCase ("default"))
         parser->__searchType = _search_default_;
      else if (opt.equalsIgnoreCase ("table"))
         parser->__searchType = _search_table_;
      else if (opt.equalsIgnoreCase ("tree"))
         parser->__searchType = _search_tree_;
      else
         parser->usage (StrBuffer ("Unknown counting type: ", opt));
   },
   {
      switch (parser->__searchType) {
         case _search_default_:  out = "default"; break;
         case _search_table_:    out = "table"; break;
         case _search_tree_:     out = "tree"; break;
         default: mustfail ();
      }
   }
);      


DEFINE_OUTPUT_SEED_PARSER_OPTION(
   pssm,
   "Spssm",
   "<on | pos | off> enable/supress generation of .PSSM files:"
      "\non => generate all PSSM files."
      "\npos => gnerate only positive PSSM files."
      "\noff => suppress genration of all PSSM files.",
   "pos",
   GetOptWrapper::_required_argument_,
   __generatePSSM
);      

DEFINE_OUTPUT_SEED_PARSER_OPTION(
   motif,
   "Smotif",
   "<on | pos | off> enable/supress generation of .motif files"
      "\non => generate all motif files."
      "\npos => gnerate only positive motif files."
      "\noff => suppress genration of all motif files.",
   "on",
   GetOptWrapper::_required_argument_,
   __generateMotif 
);      

DEFINE_OUTPUT_SEED_PARSER_OPTION(
   sample,
   "Ssample",
   "<on | pos | off> enable/supress generation of .sample files"
      "\non => generate all sample files."
      "\npos => gnerate only positive sample files."
      "\noff => suppress genration of all sample files.",
   "off",
   GetOptWrapper::_required_argument_,
   __generateBayesian
);

DEFINE_OUTPUT_SEED_PARSER_OPTION(
   seedlog,
   "Sseedlog",
   "<exhaustive | on | off> enable/supress logging of the seed featureset"
		"\non => output **each and every seen seed** to a .exhaustive file, and also log the featureset after every search"
      "\npos => log the featureset after every search"
      "\noff => no gratuitous logging",
   "off",
   GetOptWrapper::_required_argument_,
   __generateSeedlog
);

DEFINE_SEED_PARSER_OPTION(
   help,
   "Shelp",
   "displays usage information",
   "",
   GetOptWrapper::_no_argument_,
   {  parser->usage(StrBuffer ("unknown argument: ", optarg));   },
   {                                                             }
);




      



/* seed performance checking flags,

{  "Sscore-norm",
{"<none | linear-bg | logit> type of normalization to perform",
"linear-bg - divides each score by the score-sum of all features found",
"logit - score = 1 - (e^score / (1 + e^score) )",
NULL
},
"none",
GetOptWrapper::_required_argument_
},


{  "Sperf_m",
{  "<number> determine the number of 'best-positions' to consider",
"when evaluating a sequence, during seed-performance check",
NULL
},
"5",
GetOptWrapper::_required_argument_
},

{  "Sperf-comp-l",
{  "<none | log | linear> type of compensation for sequence length",
"used in seed performance evaluation",
NULL
},
"none",
GetOptWrapper::_required_argument_
},
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


case __PERF_M:
__perf_m = parser->getInt (optarg, this->_name);
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

*/

struct MyOptions {
   MyOptions () {
      REGISTER_SEED_PARSER_OPTION_CLASS (conf, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_e, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_n, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_d, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_mid, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_spec, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_i, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (proj_base, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (seed_n, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (seed_l, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (seed_r, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (seed_rr, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (seed_o, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (prep, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (prep_l, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (prep_noneg, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (count, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (count_reverse, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_partial, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_t, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_fdr, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_bonf, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_min, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_min_seq, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (score_min_seq_per, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (weight_t, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (weight_invert, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (search_t, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (pssm, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (motif, _list);
      REGISTER_SEED_PARSER_OPTION_CLASS (sample, _list);
		REGISTER_SEED_PARSER_OPTION_CLASS (seedlog, _list);
   }
   GetOptParser::OptionList _list;   
} __options;



GetOptParser::OptionList& Parser::getOptions () 
{
   return __options._list;
}

Parser::Parser ()
{
   __argv.clear ();

   //
   //
   __firstFileArg = 0;

   restoreDefaults ();
}

void Parser::usage (const char* error) const
{
   DLOG.writeln();
   DLOG.writeln();
   DLOG  << "Usage: " << __argv.argv () [0] << " [options] <seqfile> <wgtfile> <stub>"
         << DLOG.EOL ()
         << DLOG.EOL ()
         << "Following is the list of supported options:"
         << DLOG.EOL ()
         << DLOG.EOL ();

   _impl.usage (DLOG, __options._list);
   throw ParserError (error);
}



void Parser::internalParse ()
{
   __firstFileArg =  __argv.argc ();

   GET_SEED_PARSER_OPTION_CLASS (help) help_option;
   _impl.parse (__argv.argc (), __argv.argv (), __options._list, this, help_option);

   __firstFileArg = _impl._getopt.optind;

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
   if (!__proj_base.empty()) {
      if (__proj_mid > 0) {
         usage ("Cannot use --Sproj-mid option --Sproj-base option");
      }

      if (__seed_l != __proj_base.length()) {
         usage ("The seed length --Sseed-l parameter must match the length of the assignment specified by --Sproj-base");
      }
   }

   if (__prep_l < 0)
      __prep_l = __seed_l;

   if (__seed_l > __prep_l) {
      if (__searchType != _search_table_)
         usage ("Only table-search is supported for projections longer then the preprocessor.");

      if (__proj_spec)
         usage ("Seed specialization is not supported for projections longer then the preprocessor.");
   }


}

void Parser::restoreDefaults ()
{
   _impl.restoreDefaults (__options._list, this);

   USELESS (
      __proj_i; // need to be initialized in main
   );
}

static const char* outputTypeName (Parser::OutputType t) {
   switch (t) {
      case Parser::_out_all_: return "all"; break;
      case Parser::_out_pos_: return "pos"; break;
      case Parser::_out_none_: return "off"; break;
      default: mustfail ();
      return NULL;
   }
}


void Parser::logParams (Persistance::TextWriter& out) const
{
   Argv params;
   int l = _impl.getCompleteParams (   
                  params, 
                  reinterpret_cast <void*> (const_cast <Parser*>(this)), 
                  __options._list);
   out << __argv.argv () [0] << ' ';
   for (int i=0 ; i<l ; i++) {
      Str name_i (__options._list [i]->name ());
      Str param_i (params.argv () [i]);
      int arg_type = __options._list [i]->argument ();
      if (arg_type == GetOptWrapper::_no_argument_) {
         out << "  --" << name_i;
      }
      else if (arg_type == GetOptWrapper::_optional_argument_) {
         out << "  --" << name_i;
         if (param_i.empty ()) continue;
         out << '=' << param_i;
      }
      else if (!param_i.empty ())   {
         out   << "  --" << name_i
               << ' '    << param_i;
      }
   }
   out.writeln();
   out.flush ();
}

void Parser::checkCompatibility (const Parser& in)
{
   //
   // mustbe the same preprocessor
   mustbe (in.__prep == __prep);
   if (__prep == _prep_leaf_) {
      //
      // leaf preprocessor only supports seeds of constant length
      if (in.__seed_l < __prep_l)
			throw BaseException (Str ("leaf preprocessor only supports seeds that are equal or longer in length to its depth."));
   }
   else {
      mustbe (__prep == _prep_tree_);
      //
      // in tree prep we can only search seeds that are 
      // not longer than the depth of the tree
      //mustbe (__seed_l >= in.__seed_l);
   }
}
