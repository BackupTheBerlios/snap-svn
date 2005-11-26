#include "core/Argv.h"

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

//
// File        : $RCSfile: $ 
//               $Workfile: Argv.cpp $
// Version     : $Revision: 3 $ 
//               $Author: Aviad $
//               $Date: 27/08/04 2:09 $ 
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

