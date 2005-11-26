#include "Defs.h"
#include <typeinfo>

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
   static bool		throwOnAssertion= false;
#endif

static BaseException::Support* support;	//=0 implicitly

BaseException::BaseException()
{
	_breakOnException.engage();
}

BaseException::~BaseException() {
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

bool BaseException::bypassStackTrace () const
{
	return false;
}

void BaseException::explain(std::ostream& out) 
{
   std::string name;
	out << "exception " << typeid (*this).name ();
}

void BaseException::willThrow() const {
    _breakOnThrow.engage ();
	if (support)
		support->willThrow(*this, NULL);
}

void BaseException::setSupport(Support* in) {
	support= in;
}

BaseException::Support* BaseException::getSupport() {
	return support;
}

BaseException::Support::~Support() {
}

ProgramException::ProgramException(int inCode, const char* inFileName, const char* inError) 
:  code(inCode), fileName(inFileName)
{
   if (inError)
      error = inError;
}

void ProgramException::explain (std::ostream& out) {
	out << "program error " << code;
	if (fileName) 
		out << "(file " << fileName << ")";
   if (!error.empty ())
      out << ' ' << error;

}

void ProgramException::raise(int lineNo, const char* fileName, const char* error)
{
	ProgramException pex(lineNo, fileName, error);
	exception_action(pex, fileName, lineNo);
	throwx (pex);
}


#if BASE_DEBUG

void exception_action(BaseException &/*inException*/, const char* /*file*/, int /*line*/)
{
	_breakOnException.engage();
}

void signal_assertion(const char* /*msg*/, const char* file, int lineNo)
{
	breakOnAssertion.engage();
	if (throwOnAssertion) 
		throwx (ProgramException(lineNo, file));
}

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: Defs.cpp $
// Version     : $Revision: 9 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
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
