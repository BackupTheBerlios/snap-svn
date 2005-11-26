#ifndef _SeedSearcher_Core_Defs_h
#define _SeedSearcher_Core_Defs_h

#include "Compiler.h"

//
// disable warnings
#if ENV_COMPILER==ENV_MICROSOFT
   //
   // class name too long
#  pragma warning(disable: 4786)
#endif


#include <string>
#include <iostream>

#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE(name) };

//
// definitions for 'typename' keyword. 
// some compilers (VC 6.0) dont support it properly
// while others (gcc) enforce it rather strictly.
#if ENV_C_SUPPORTS & ENV_TYPENAME_KEYWORD
#  define TYPENAME typename
#else
#  define TYPENAME
#endif



//	}{ BASE_DEBUG -- debugging

#ifndef BASE_DEBUG
#	if ENV_COMPILER==ENV_MICROSOFT
#		ifdef _DEBUG
#			define BASE_DEBUG 1
#		else
#			define BASE_DEBUG 0
#		endif
#	elif ENV_COMPILER==ENV_GCC
#               ifndef NDEBUG
#                       define BASE_DEBUG 1
#		else
#        		define BASE_DEBUG 0
#               endif
#       else
#		define BASE_DEBUG 0
#	endif
#endif



#if BASE_DEBUG
#       define debug_only(expr) expr
#else
#       define debug_only(expr)
#endif





#if BASE_DEBUG
	class	DebuggerBreak {
	 public:
	 	DebuggerBreak();
		DebuggerBreak(bool inBreak);

		void engage();

		void set (bool inBreak)	{
			_break = inBreak;
		}
		operator bool () const {
			return _break;
		}
	 private:
		bool _break;
	};
#else
	class	DebuggerBreak {
	 public:
		DebuggerBreak(bool /*inBreak*/= true) {
		}
		void engage() {
		}
		operator bool () const {
			return false;
		}
		void set (bool)	{
		}
	};
#endif


class BaseException  {
public:
  BaseException();
  virtual ~BaseException();

  virtual bool bypassStackTrace () const;
  //  Write short explanation message to the 'out'. The message should be
  //  applicable in the context "The operation failed because of <message>"
  //  Example: "system error 25"
  virtual void explain (std::ostream&);

  //	Gets called right before throw usually
  //	to gather exception information
  void willThrow() const;
  
  class	Support {
  public:
    virtual ~Support();
    virtual void willThrow(const BaseException& inExcp, void* inContext)= 0;
  };
	
  static void setSupport(Support* in);
  static Support* getSupport();
  
  //
  // break when BaseException constructor is called
  static void breakOnException (bool);
  static bool breakOnException ();
  
  //
  // break when throwx is called
  static void breakOnThrow (bool);
  static bool breakOnThrow ();
};



template<class Exception>
inline void throwx(const Exception& in) {
	in.willThrow();
	throw in;
}



//	}{ Program exception stuff (equivalent to various AsSerTs())
//
//	It is recommended to use mustbe(expr) unless it's called too often (100,000 times or more)
//	Then, use debug_mustbe(expr)

class ProgramException : public BaseException {
public:
  ProgramException(int inCode, 
		   const char* inFileName=0, const char* inError=0);
   virtual void explain (std::ostream&);
   static void raise(int lineNo, 
		     const char* fileName=0, const char* inError=0);

   int getCode() const { return code; }
	
protected:
   int code;
   const char* fileName;
   std::string error;
};


#if	BASE_DEBUG
   void exception_action(BaseException &inException, 
			 const char* file, int line);

   void signal_assertion(const char* msg, const char* file, int line);	

   inline void signal_assert(bool cond, 
			     const char* msg, 
			     const char* file, 
			     int line) 
{
  if (!cond) signal_assertion(msg, file, line);
}

#else
#   define exception_action(exc, file, line)	
#   define signal_assertion(msg, file, line)
#   define signal_assert(cond, msg, file, line)
#endif

//
// mustbe / debug_mustbe
#ifndef mustbe
	inline void pexifnot_(bool cond, int lineNo, const char* err=NULL) {
		if (!cond) ProgramException::raise(lineNo, err);
	}
	inline void pexifnot_(const void* ptr, int lineNo, const char* err=NULL) {
		if (ptr==0) ProgramException::raise(lineNo, err);		
	}
	inline void pexifnot_(int cond, int lineNo, const char* err=NULL) {
		if (!cond) ProgramException::raise(lineNo, err);
	}
	
	#define mustbe(cond)		pexifnot_((cond), __LINE__)
	#define mustnot(cond)		pexifnot_(!(cond), __LINE__)
	#define mustfail()		pexifnot_(bool(false), __LINE__)

   //
   // with message 
	#define mmustbe(cond, err)		pexifnot_((cond), __LINE__, err)
	#define mmustnot(cond, err)		pexifnot_(!(cond), __LINE__, err)
	#define mmustfail(err)		pexifnot_(bool(false), __LINE__, err)

	#define	debug_assert(cond)	\
debug_only(signal_assert((cond), #cond, __FILE__, __LINE__))
	#define debug_mustbe(cond)	debug_assert((cond)!=0)
	#define debug_mustnot(cond)	debug_assert((cond)==0)

	#define debug_mustfail()	\
debug_only(signal_assertion("Failure", __FILE__, __LINE__))

	#define	debug_signal(msg)	\
debug_only(signal_assertion(msg, __FILE__, __LINE__))		

#endif


#if ENV_C_SUPPORTS & ENV_NAMESPACES
#    define USING_TYPE(type_path, type) using type_path::type;
#else 
     //
     // using is not properly handled by compiler
#    define USING_TYPE(type_path, type) typedef type_path::type type;
#endif


//
// min/max templates, more efficient than MACRO versions 
template <class T>
inline const T& tmin(const T& a, const T& b) {
	return a < b ? a : b;
}
template <class T>
inline const T& tmax(const T& a, const T& b) {
	return  a < b ? b : a;
}

   
//
// optimizations: should use Doug Lee's malloc? 
#define CORE_DL_MALLOC_OPTIMIZATION (ENV_COMPILER == ENV_MICROSOFT)

#if CORE_DL_MALLOC_OPTIMIZATION
#define SEED_MALLOC dlmalloc
#define SEED_FREE dlfree
#else
#define SEED_MALLOC malloc
#define SEED_FREE free
#endif

#endif // _SeedSearcher_Core_Defs_h






