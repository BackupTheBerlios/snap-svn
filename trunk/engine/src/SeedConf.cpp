//
// File        : $RCSfile: $ 
//               $Workfile: SeedConf.cpp $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 9/12/04 3:05 $ 
// Description :
//    implementation classes for reading SeedSearcher's conf files.
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
// and the library authors apply.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "SeedConf.h"
#include "DebugLog.h"
#include "persistance/TextWriter.h"
#include "persistance/StrOutputStream.h"

using namespace seed;

//
//
void SeedConf::read (const Str& inConfFileName, SeedConf& in)
{
   ConfReader conf (inConfFileName);
   in.init (conf);

   //
   // now we validate the arguments in the conf
   StrBuffer args;
   ConfReader::Package seed (conf.getPackage ("Seed"));
   ConfReader::Package init (seed.createSubPackage ("Init"));
   init.mustGet ("Args", args);
   in.initArgs (args);

   //
   // now we read and validate run parameters from the conf
   ConfReader::Package runs (seed.createSubPackage ("Runs"));
   ConfReader::Iterator it (runs);
   for (; !it.atEnd () ; it.next ()) {
      bool resetSeedsBeforeRun;
      bool resetArgs;
      runs.mustGet (it + "ResetArgs", resetArgs);
      runs.mustGet (it + "ResetSeeds", resetSeedsBeforeRun);
      runs.mustGet (it + "Args", args);
      in.runArgs (resetArgs, resetSeedsBeforeRun, it.getName (), args);
   }

   in.done ();
}


static void disallowFileArgs (Parser& parser)
{
   if (parser.getNumFileArgs ()> 0) {
      std::string buffer; buffer.reserve(512);

      {  Persistance::TextWriter writer (new Persistance::StrOutputStream (buffer));
         writer << "File arguments are not allowed in conf. Offending arguments are:";
         for (int i=0 ; i<parser.getNumFileArgs () ; i++)  {
            const char* arg = parser.__argv.argv () [parser.__firstFileArg + i];
            writer   << writer.EOL () 
                     << '(' 
                     << (i+1) 
                     << ") " 
                     << arg;
         }
      }
      mmustfail (buffer.c_str());
   }
}

SeedConfList::SeedConfList (int argc, char const * const* argv)
{
	Argv args (argc, argv);
	Parser parser;
   parser.parse (argc, argv);

	StrBuffer buffer;
	_init.reset (new Options ("Init", args.get (buffer), false, parser));
}


void SeedConfList::init (ConfReader& conf) {
   DLOG << "Checking correctness of " << conf.source () << ':' << DLOG.EOL ();
   DLOG.flush ();
   if (!conf.valid ()) {
      mmustfail ("The file could not be found");
   }
}

void SeedConfList::initArgs (const Str& args) {
   DLOG  << "Validating initial arguments... \t("
         << args
         << ')'
         << DLOG.EOL ();
   DLOG.flush ();

   //
   // parse the conf arguments
   Parser temp;
   temp.parse(Argv (_init->_parser.__argv.argv () [0], args));

   //
   // we dont allow unrecognized switches in conf
   disallowFileArgs (temp);

	//
   // reapply cmdline arguments
   temp.parse (_init->_parser.__argv);
   
	StrBuffer params;
	params += _init->_parameters;
	params += " ";
	params += args;
				
	_init.reset (new Options (
		_init->_name, 
		params,
		_init->_resetSeeds,
		temp)
		);
}

void SeedConfList::runArgs (bool resetArgs, bool resetSeeds,
                        const Str& runName, const Str& args)
{
   DLOG << "Validating " << runName 
        << " \t( " << args << ')'
        << DLOG.EOL ();

   AutoPtr <Options> options;
   if (resetArgs) {
      //
      // revert to the initial arguments
      options = new Options ( runName, args, resetSeeds, _init->_parser);
   }
   else if (_optionList.size () > 0) {
      //
      // arguments are carried over from the last run
      options = new Options (  runName, args, resetSeeds, 
                                    _optionList.back ()->_parser);
   }
   else {
      options = new Options (  runName, args, resetSeeds, _init->_parser);
   }

   //
   // update with the specific run args
   options->_parser.parse (Argv (_init->_parser.__argv.argv () [0], args));

   //
   // make sure we can continue to the next configuration
   _init->_parser.checkCompatibility (options->_parser);

   //
   // make sure there are no undefined parameters
   disallowFileArgs (options->_parser);

   //
   // everything is cool, we advance to next step
   _optionList.push_back (options.release ());
}

void SeedConfList::done ()
{
   DLOG  << "Configuration file is valid."
         << DLOG.EOL ()
         << DLOG.EOL ();
   DLOG.flush ();
}

