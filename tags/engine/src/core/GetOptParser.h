#ifndef _SeedSearcher_Core_Parser_h
#define _SeedSearcher_Core_Parser_h

#include "core/Defs.h"
#include "core/STLHelper.h"
#include "core/Argv.h"
#include "persistance/TextTableReport.h"

class GetOptWrapper {
public:
   GetOptWrapper () : exec_name (NULL), optarg (NULL), optind (0),
      opterr (1), optopt ('?'), nextchar (0) {
   }

   /* Declarations for getopt.
   Copyright (C) 1989, 1990, 1991, 1992, 1993 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

   const char *exec_name;

   /* For communication from `getopt' to the caller.
   When `getopt' finds an option that takes an argument,
   the argument value is returned here.
   Also, when `ordering' is RETURN_IN_ORDER,
   each non-option ARGV-element is returned here.  */

   char *optarg;

   /* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   When `getopt' returns EOF, this is the index of the first of the
   non-option elements that the caller should itself scan.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */

   int optind;

   /* Callers store zero here to inhibit the error message `getopt' prints
   for unrecognized options.  */

   int opterr;

   /* Set to an option character which was unrecognized.  */

   int optopt;

   /* Describe the long-named options requested by the application.
   The LONG_OPTIONS argument to getopt_long or getopt_long_only is a vector
   of `struct option' terminated by an element containing a name which is
   zero.

   The field `has_arg' is:
   no_argument		(or 0) if the option does not take an argument,
   required_argument	(or 1) if the option requires an argument,
   optional_argument 	(or 2) if the option takes an optional argument.

   If the field `flag' is not NULL, it points to a variable that is set
   to the value given in the field `val' when the option is found, but
   left unchanged if the option is not found.

   To have a long-named option do something other than set an `int' to
   a compiled-in constant, such as set a value from `optarg', set the
   option's `flag' field to zero and its `val' field to a nonzero
   value (the equivalent single-letter option character, if there is
   one).  For long options that have a zero `flag' field, `getopt'
   returns the contents of the `val' field.  */

   struct option
   {
#if	__STDC__
      const char *name;
#else
      char *name;
#endif
      /* has_arg can't be an enum because some compilers complain about
      type mismatches in all the code that assumes it is an int.  */
      int has_arg;
      int *flag;
      int val;
   };

   /* Names for the values of the `has_arg' field of `struct option'.  */
   enum {
      _no_argument_ = 0,
      _required_argument_	= 1,
      _optional_argument_	= 2
   };

   int getopt (int argc, char *const *argv, const char *shortopts);
   int getopt_long (int argc, char *const *argv, const char *shortopts,
      const struct option *longopts, int *longind);
   int getopt_long_only (int argc, char *const *argv,
      const char *shortopts,
      const struct option *longopts, int *longind);

   /* Internal only.  Users should not call this directly.  */
   int _getopt_internal (int argc, char *const *argv,
      const char *shortopts,
      const struct option *longopts, int *longind,
      int long_only);

private:
   void exchange (char **argv);
   char *nextchar;
};

class GetOptParser {
   //
   //
public:
   class OptionBase {
   public:
      virtual const char* name ()   const	{ return NULL; }
      virtual const char* desc ()   const	{ return NULL; }
      virtual const char* def ()    const	{ return NULL; }
      virtual int argument ()       const	{ return GetOptWrapper::_no_argument_;   }

      virtual void param (StrBuffer&, void* ctx) = 0;
      virtual void execute (const char* optarg, void* ctx) = 0;
   };

   struct Option : public OptionBase {
      Option ( const char* n, const char* dsc, const char* def, int  arg)
         : _name (n), _desc (dsc), _def (def), _arg (arg) {
      }

      virtual const char* name ()   const	{ return _name;   }
      virtual const char* desc ()   const	{ return _desc;   }
      virtual const char* def ()    const	{ return _def;    }
      virtual int argument ()       const	{ return _arg;    }

      const char * _name, * _desc, * _def;
      int _arg;
   };

   class OptionList {
   public:
      OptionList () : _dirty (true), _internal (NULL) {
      }
      ~OptionList () {
         int l = length();
         for (int i=0 ; i<l ; i++)
            delete _options [i];

         delete _internal;
      }
      int add (OptionBase* inOpt) {
         _dirty = true;
         _options.push_back (inOpt);
         return _options.size () -1;
      }
      OptionBase* operator [] (int index) {
         return _options [index];
      }
      void execute (int index, const char* optarg, void* ctx) {
         USELESS (debug_only (const char* name = _options [index]->name ()));
         _options [index]->execute (optarg, ctx);
      }
      GetOptWrapper::option* getInternal () {
         if (_dirty) {
            delete [] _internal;
            int length = _options.size ();
            _internal = new GetOptWrapper::option [length + 1];
            for (int i=0 ; i<length ; i++) {
               _internal [i].name = 
                  const_cast <char*> (_options [i]->name ());
               _internal [i].has_arg = _options [i]->argument ();
               _internal [i].flag = NULL;
               _internal [i].val = i;
            }
            //
            // create a NULL option to terminate the array
            _internal [length].name = NULL;
            _dirty = false;
         }

         return _internal;
      }
      int length () const {
         return _options.size ();
      }

   private:
      bool _dirty;
      Vec <OptionBase*> _options;
      GetOptWrapper::option* _internal;
   };

   void usage (Persistance::TextWriter& out, OptionList& options) const {
      Persistance::TextTableReport::TextOutput output (out);
      Persistance::TextTableReport::Format format;
      format.addField ("Name", 80, 18);
      format.addField ("Description", 1000, 58);

      Persistance::TextTableReport::Data data (format);      
      int length = options.length ();
      for (int i=0 ; i<length ; i++) {
         //
         // write name and default argument
         FixedStr name_field = data.getField (0);
         name_field = "--";
         name_field.append (options [i]->name ());

         //
         // write description
         FixedStr desc_field = data.getField (1);
         desc_field = options [i]->desc();
         if (options [i]->argument () != GetOptWrapper::_no_argument_) {
            desc_field.append ("\n{default=");
            Str ddef (options [i]->def ());
            if (ddef.empty ())   desc_field.append("not set");
            else                 desc_field.append(ddef);
            desc_field.append ('}');
         }
         output << data;
         output.writeln ();
      }
   }
	void parse (int argc, char const * const * argv , 
               OptionList& opt, void* ctx,
               Option& unknown) 
   {
      GetOptWrapper::option* internal = opt.getInternal();

      //
      // very important:
      // we re-initialize getopt's static optind variable back to 0
      // in order to parse the entire argv
      _getopt.optind = 0;

      char c;
      int opt_ind;
      int numOfOptions = opt.length ();
		char* const * _argv = const_cast <char* const *> (argv);
      while ((c = _getopt.getopt_long (argc, _argv, "", internal, &opt_ind))!=EOF) {
         if ((c != '?') && (opt_ind >= 0) && (opt_ind < numOfOptions)) {
            opt.execute (opt_ind, _getopt.optarg, ctx);
         }
         else {
            unknown.execute (StrBuffer (  argv [_getopt.optind -1], 
                                          " ", 
                                          argv [_getopt.optind]), ctx);
         }
      }
   }

   //
   // completes parameters from the user-defined ctx
   int getCompleteParams (Argv& outOptions, void* ctx, OptionList& opt){
      StrBuffer buffer (32);
      int numOfOptions = opt.length ();
      outOptions = Argv (numOfOptions);
      for (int i=0 ; i<numOfOptions ; i++) {
         opt[i]->param (buffer, ctx);
         outOptions.argv ()[i] = outOptions.dup (buffer);
      }
      return numOfOptions;
   }

   //
   // completes parameters from an argv
   int getCompleteParams (Argv& outOptions,
                           int argc, char* argv [], OptionList& opt) 
   {
      GetOptWrapper::option* internal = opt.getInternal();

      //
      // very important:
      // we re-initialize getopt's static optind variable back to 0
      // in order to parse the entire argv
      _getopt.optind = 0;

      int numOfOptions = opt.length ();
      
      outOptions = Argv (numOfOptions);
      for (int i=0 ; i<numOfOptions ; i++) {
         Str str (opt[i]->def ());
         outOptions.argv () [i] = outOptions.dup (str);
      }

      char c;
      int opt_ind;
      while ((c = _getopt.getopt_long (argc, argv, "", internal, &opt_ind))!=EOF) {
         if ((opt_ind >= 0) && (opt_ind < numOfOptions)) {
            outOptions.argv () [opt_ind] = outOptions.dup (_getopt.optarg);
         }
      }

      return numOfOptions;
   }

   void restoreDefaults (OptionList& options, void* ctx) {
      int length = options.length ();
      for (int i=0 ; i<length ; i++) {
         USELESS (
            const char* option_name = NULL;
            debug_only (
               option_name = options [i]->name ();
            );
         );
         const char* def = options [i]->def ();
         options [i]->execute (def, ctx);
      }
   }

   GetOptWrapper _getopt;
};

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: GetOptParser.h $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 16/12/04 17:18 $ 
// Description :
//	The Core library contains contains basic definitions and classes
// which are useful to any highly-portable applications
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
//

