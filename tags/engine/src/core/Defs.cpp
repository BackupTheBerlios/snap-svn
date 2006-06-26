#include "Defs.h"

#include <typeinfo>
#include <sstream>
#include "Str.h"

#if BASE_DEBUG 

   DebuggerBreak::DebuggerBreak() : _break(true) {
   }

   DebuggerBreak::DebuggerBreak(bool inBreak) : _break(inBreak) {
}

#  if (ENV_COMPILER==ENV_MICROSOFT)
#     include <crtdbg.h>

      void DebuggerBreak::engage() {
         if (_break) {
            try {
               _CrtDbgBreak();
            }
            catch (...) {
               // allow applications to run in debug mode without debugger
               _break = false;
            }
         }
      }

#     else

         void DebuggerBreak::engage() {
         }

#  endif // ENV_COMPILER==ENV_MICROSOFT

#endif // BASE_DEBUG

//	In VC++ 4.2 and above, exceptions are caught 
//	by the debugger, hence the 'breakOnException' is cleared
//	Make sure you have "Microsoft C++ exception" setting
//	set to "Stop always" in the Debug/Exceptions menu

static DebuggerBreak	_breakOnException(false);
static DebuggerBreak	_breakOnThrow(false);

static DebuggerBreak	breakOnAssertion;

#if BASE_DEBUG
	static bool		throwOnAssertion = true;
#endif




BaseException::BaseException()
{
}

BaseException::BaseException (const Str& in)  {
	std::string s;
	in.getCString(s);
	init (s);
}


void BaseException::init (const std::string& inMessage)
{
	_message = inMessage;
}

BaseException::~BaseException() throw (){
}

void BaseException::breakOnThrow (bool inBreak)
{
  _breakOnThrow.set (inBreak);
}

bool BaseException::breakOnThrow ()
{
  return _breakOnThrow;
}

bool BaseException::breakOnException ()
{
  return _breakOnException;
}

const char* BaseException::what () const throw () 
{
  {
    std::ostringstream out;
    explain (out);
    out.flush ();
    const_cast <std::string&> (_buffer) = out.str ();
  }
  return _buffer.c_str ();
}


ProgramException::ProgramException(int inCode, 
				   const char* inFileName, 
				   const char* inError) 
:  _code(inCode), _fileName(inFileName)
{
   if (inError)
      _message = inError;
}

void ProgramException::explain (std::ostream& out) const
{
  out << "program error " 
      << _code;
  if (_fileName) {
    out << "(thrown from " 
	<< _fileName << ")";
  }

  if (!_message.empty ()) {
    out << ' ' 
	<< _message;
  }
  
}

void ProgramException::raise(int lineNo, 
			     const char* fileName, 
			     const char* error)
{
  ProgramException pex(lineNo, fileName, error);
  exception_action(pex, fileName, lineNo);
  throwx (pex);
}


#if BASE_DEBUG

void exception_action(BaseException &/*inException*/, 
		      const char* /*file*/, 
		      int /*line*/)
{
	_breakOnException.engage();
}

void signal_assertion(const char* msg,
		      const char* file, 
		      int lineNo)
{
  breakOnAssertion.engage();
  if (throwOnAssertion) 
    ProgramException::raise (lineNo, file, msg);
}

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: Defs.cpp $
// Version     : $Revision: 11 $ 
//               $Author: Aviad $
//               $Date: 3/03/05 21:34 $ 
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

