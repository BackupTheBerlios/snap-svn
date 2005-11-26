#ifndef _SeedSearcher_SeedConf_h
#define _SeedSearcher_SeedConf_h

#include "Util/ConfReader.h"
#include "Parser.h"

#include "Core/STLHelper.h"
#include <list>


struct SeedConf {
   virtual ~SeedConf () {
   }
   virtual void init (ConfReader& conf) = 0;
   virtual void initArgs (const Str&) = 0;
   virtual void runArgs (bool resetArgs, bool resetSeeds,
                         const Str& runName, const Str& args) = 0;
   virtual void done () = 0;

   static void read (const Str& inConfFileName, SeedConf& in);
};

class SeedConfList : public SeedConf {
   //
   // makes sure a conf file is valid
public:
   SeedConfList (int argc, char* argv []);
   ~SeedConfList () {
      while (!_optionList.empty ()) {
         Options* o = _optionList.back (); _optionList.pop_back ();
         delete o;
      }
   }
   virtual void init (ConfReader& conf);
   virtual void initArgs (const Str& args);
   virtual void runArgs (bool resetArgs, bool resetSeeds,
                         const Str& runName, const Str& args);
   virtual void done ();

   struct Options {
      Options (const Str& inName, bool inReset, const Parser& inParser)
         : _name (inName), _resetSeeds (inReset), _parser (inParser) {
      }

      StrBuffer _name;
      bool _resetSeeds;
      Parser _parser;
   };
   typedef std::list <Options*> OptionList;
   typedef CIteratorWrapper <SeedConfList::OptionList> COptionIterator;
   typedef IteratorWrapper <SeedConfList::OptionList> OptionIterator;

   //
   // returns the list of options
   OptionList& getOptionList () {
      return _optionList;
   }
   COptionIterator const_iterator () const {
      return COptionIterator (_optionList.begin (), _optionList.end ());
   }
   OptionIterator iterator () {
      return OptionIterator (_optionList.begin (), _optionList.end ());
   }
   const Parser& getInitParser () const {
      return _init;
   }
   bool empty () const {
      return _optionList.empty ();
   }

private:
   Parser _init;
   OptionList _optionList;
};


#endif

