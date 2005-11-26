#include "SeedConf.h"

#include "DebugLog.h"

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
      char buffer [1024];
      sprintf (buffer, "File arguments are not allowed in conf %s",
                        parser.__argv [parser.__firstFileArg]);
      mmustfail (buffer);
   }
}

SeedConfList::SeedConfList (int argc, char* argv [])
{
   _init.parse (argc, argv);
}

void SeedConfList::init (ConfReader& conf) {
   DLOG << "Checking correctness of " << conf.source () << ':' << DLOG.EOL ();
   if (!conf.valid ()) {
      mmustfail ("The file could not be found");
   }
   DLOG.flush ();
}

void SeedConfList::initArgs (const Str& args) {
   DLOG  << "Validating initial arguments..."
         << args
         << DLOG.EOL ();
   DLOG.flush ();

   //
   // parse the conf arguments
   Parser temp;
   temp.parse(Argv (_init.__argv [0], args));

   //
   // we dont allow unrecognized switches in conf
   disallowFileArgs (temp);

   //
   // reapply cmdline arguments
   temp.parse (_init.__argc, _init.__argv);
   _init = temp;
}

void SeedConfList::runArgs (bool resetArgs, bool resetSeeds,
                        const Str& runName, const Str& args)
{
   DLOG << "Validating  " << runName << DLOG.EOL ();

   AutoPtr <Options> options;
   if (resetArgs) {
      //
      // revert to the initial arguments
      options = new Options ( runName, resetSeeds, _init);
   }
   else if (_optionList.size () > 0) {
      //
      // arguments are carried over from the last run
      options = new Options (  runName, resetSeeds, 
                                    _optionList.back ()->_parser);
   }
   else {
      options = new Options (  runName, resetSeeds, _init);
   }

   //
   // update with the specific run args
   options->_parser.parse (Argv (_init.__argv [0], args));

   //
   // make sure we can continue to the next configuration
   _init.checkCompatibility (options->_parser);

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

