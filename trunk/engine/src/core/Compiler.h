#ifndef _SeedSearcher_Core_Compiler_h
#define _SeedSearcher_Core_Compiler_h

#include <boost/config.hpp>

//
// compiler type
#define ENV_MICROSOFT			0x02
#define ENV_GCC 			0x04

#if defined(_MSC_VER)

#	define ENV_COMPILER ENV_MICROSOFT
#	define ENV_C_VERSION _MSC_VER 
#endif

#if defined(__GNUC__)
#       define ENV_COMPILER ENV_GCC
#       define ENV_C_VERSION __GNUC__
#endif



//	ENV_C_SUPPORTS (bit flags)		// Compiler feature flags

#define ENV_MEMBER_TEMPLATES	0x0001	// member templates
#define ENV_BOOL		0x0002	// "bool" keyword
#define ENV_NEWKEYWORDS		0x0004	// "explicit", "typename"
#define ENV_TEMPLATE_ARGS	0x0008	// template<class X=int> 
#define ENV_EXCEPTIONS		0x0010	// C++ native exception handling 
#define ENV_RTTI		0x0020	// C++ native RTTI
#define ENV_NAMESPACES		0x0040	// namespaces support
#define ENV_PRAGMA_ONCE		0x0080	// #pragma once
#define ENV_STD_NAMESPACE	0x0100	// using std:: namespace in c++ library
#define	ENV_INT64		0x0200	// 64 bit integer
// operators new[](size_t), delete[](void*)
#define	ENV_ARRAY_NEW_DELETE	0x0400	
// the wchar_t is a distinct builtin type 
// (vs. typedef'd to unsigned short)
#define	ENV_DISTINCT_WCHAR	0x0800
#define	ENV_PARGMA_ALIGN	0x1000
#define	ENV_PRAGMA_PACKPUSH	0x2000
#define	ENV_PRAGMA_PACK		0x4000
// support (or requirement) of typename keyword in templates
#define	ENV_TYPENAME_KEYWORD 0x8000 

//	ENV_C_VERSION					
// Compiler version, depends on compiler type
#if	ENV_COMPILER & ENV_MICROSOFT
#	ifdef RC_INVOKED
#		define ENV_LANGUAGE ENV_RC
#	else
#		ifdef _CPPUNWIND
#			define ENV_MSC_EXCEPTIONS_ ENV_EXCEPTIONS
#		else
#			define ENV_MSC_EXCEPTIONS_ 0
#		endif 
#		ifdef _CPPRTTI
#			define ENV_MSC_RTTI_ ENV_RTTI
#		else
#			define ENV_MSC_RTTI_ 0
#		endif
#		if ENV_C_VERSION >= 1100
#			define ENV_MSC_BOOL_			ENV_BOOL
#			define ENV_MSC_INT64_			ENV_INT64
#			define ENV_MSC_NAMESPACES_ 		ENV_NAMESPACES
#			define ENV_MSC_STD_NAMESPACE_	ENV_STD_NAMESPACE
#		else
#			define ENV_MSC_BOOL_			0
#			define ENV_MSC_INT64_			0
#			define ENV_MSC_NAMESPACES_		0
#			define ENV_MSC_STD_NAMESPACE_	0
#		endif
#		if ENV_C_VERSION >= 1000
#			define ENV_MSC_PRAGMA_ONCE_	ENV_PRAGMA_ONCE
#		else
#			define ENV_MSC_PRAGMA_ONCE_	0
#		endif
#		define ENV_C_SUPPORTS (ENV_MSC_EXCEPTIONS_|ENV_MSC_RTTI_|ENV_MSC_BOOL_|ENV_MSC_INT64_|ENV_MSC_NAMESPACES_|ENV_MSC_PRAGMA_ONCE_|ENV_MSC_STD_NAMESPACE_|ENV_PRAGMA_PACKPUSH)
#		define ENV_LANGUAGE ENV_C
#	endif
#elif ENV_COMPILER & ENV_GCC
//
// TODO: determine support issues for gcc
#  if ENV_C_VERSION >= 3
#	define ENV_C_SUPPORTS (ENV_TYPENAME_KEYWORD | ENV_MEMBER_TEMPLATES | ENV_BOOL | ENV_NEWKEYWORDS | ENV_TEMPLATE_ARGS | ENV_EXCEPTIONS | ENV_RTTI)
#  else 
#     pragma warning "unsupported gcc version"
#  endif
#else
#pragma warning "Compiling with unknown compiler"
#	define ENV_COMPILER ENV_ANSII_CPP
#	define ENV_C_SUPPORTS (ENV_EXCEPTIONS | ENV_RTTI | ENV_MEMBER_TEMPLATES | ENV_BOOL | ENV_NAMESPACES)
#endif

#define ENV_BUGS ENV_COMPILER


#if ENV_C_SUPPORTS & ENV_INT64
#  if ENV_COMPILER & ENV_MICROSOFT 
      typedef __int64 int64_t;
#  endif
#endif

#if ENV_COMPILER & ENV_MICROSOFT
#   ifdef _M_IA64
#       define ENV_IS_64BIT 1
#   endif
#elif ENV_COMPILER & ENV_GCC
#   ifdef __LP64__
#       define ENV_IS_64BIT 1
#   endif
#endif

#ifdef ENV_IS_64BIT
// #  warning "INFO: compiling with 64bit environment"
#else
// #  warning "INFO: compiling with 32bit environment"
#endif


/*
Compiler-dependent definitions

*/

//
// should throw out variable/delcarations without use?
#if ENV_COMPILER & ENV_GCC
#  define USELESS(commands)
#else
#  define USELESS(commands) commands
#endif


#endif // _SeedSearcher_Compiler_h

//
// File        : $RCSfile: $ 
//               $Workfile: Compiler.h $
// Version     : $Revision: 9 $ 
//               $Author: Aviad $
//               $Date: 7/09/04 9:43 $ 
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

