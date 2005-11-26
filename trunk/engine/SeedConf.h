#ifndef _SeedSearcher_SeedConf_h
#define _SeedSearcher_SeedConf_h

//
// File        : $RCSfile: $ $Workfile: SeedConf.h $
// Version     : $Revision: 7 $ $Author: Aviad $
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
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//


#include "core/ConfReader.h"
#include "Parser.h"

#include "core/STLHelper.h"
#include <list>


struct SeedConf {
   //
   //
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

