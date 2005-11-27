#ifndef _SeedSearcher_Core_Argv
#define _SeedSearcher_Core_Argv

#include "Str.h"


class Argv{
   //
   // utlitity class for argv
public:
   Argv () : _argc (0), _argv (NULL) {
   }
   Argv (int argc) : _argc (argc) {
      _argv = new char*[_argc];
      for (int i=0 ; i<_argc ; i++)
         _argv [i] = NULL;
   }
   Argv (int argc, char** argv) : _argc (0), _argv (NULL) {
      set (argc, argv);
   }
   Argv (const Argv& in) : _argc (0), _argv (NULL) {
      set (in);
   }
   Argv (const Str& in);
   Argv (const Str& prefix, const Str& in);
   ~Argv () {
      clear ();
   }

   Argv& operator = (const Argv& argv) {
      set (argv);
      return *this;
   };

   //
   // create argv from a single string
   void set (const Str&);
   //
   // create argv from a prefix, and a string
   void set (const Str& prefix, const Str&);

   void set (const Argv& in) {
      set (in._argc, in._argv);
   }
   void set (int argc, char** argv) {
      mustbe (argc >= 0);
      clear ();
      _argc = argc;
      _argv = new char* [_argc];
      for (int i=0 ; i<_argc ; i++)
         _argv [i] = dup (argv [i]);
   }
   void set (const Str& prefix, int argc, char** argv)  {
      mustbe (argc >= 0);
      clear ();
      _argc = argc + 1;
      _argv = new char* [_argc];
      _argv [0] = dup (prefix);
      for (int i=0 ; i<_argc ; i++)
         _argv [i+1] = dup (argv [i]);
   }

   void clear () {
      if (_argv != NULL) {
         for (int i=0 ; i<_argc ; i++)
            delete [] _argv[i];

         delete [] _argv;
         _argv = NULL;
         _argc = 0;
      }
   }

   int argc () const {
      return _argc;
   }
   char ** argv () const {
      return _argv;
   }
   bool empty () const {
      return _argc == 0;
   }


   template <typename StringT>
      static char* dup (StringT& s)   {
         StrBuffer temp = Str (s);
         return temp.release ();
      }

protected:
   int _argc;
   char** _argv;
};

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: Argv.h $
// Version     : $Revision: 3 $ 
//               $Author: Aviad $
//               $Date: 2/12/04 7:55 $ 
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

