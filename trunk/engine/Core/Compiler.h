#ifndef _SeedSearcher_Core_Compiler_h
#define _SeedSearcher_Core_Compiler_h

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
#define ENV_BOOL				0x0002	// "bool" keyword
#define ENV_NEWKEYWORDS			0x0004	// "explicit", "typename"
#define ENV_TEMPLATE_ARGS		0x0008	// template<class X=int> 
#define ENV_EXCEPTIONS			0x0010	// C++ native exception handling 
#define ENV_RTTI				0x0020	// C++ native RTTI
#define ENV_NAMESPACES			0x0040	// namespaces support
#define ENV_PRAGMA_ONCE			0x0080	// #pragma once
#define ENV_STD_NAMESPACE		0x0100	// using std:: namespace in c++ library
#define	ENV_INT64				0x0200	// 64 bit integer
#define	ENV_ARRAY_NEW_DELETE	0x0400	// operators new[](size_t), delete[](void*)
#define	ENV_DISTINCT_WCHAR		0x0800	// the wchar_t is a distinct builtin type 
										// (vs. typedef'd to unsigned short)
#define	ENV_PARGMA_ALIGN		0x1000
#define	ENV_PRAGMA_PACKPUSH		0x2000
#define	ENV_PRAGMA_PACK			0x4000

//	ENV_C_VERSION					// Compiler version, depends on compiler type

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
#elif ENV_COMPILER==ENV_GCC
//
// TODO: determine support issues
#else
#pragma warning "Compiling with unknown compiler"
#	define ENV_COMPILER ENV_ANSII_CPP
#	define ENV_C_SUPPORTS (ENV_EXCEPTIONS | ENV_RTTI | ENV_MEMBER_TEMPLATES | ENV_BOOL | ENV_NAMESPACES)
#endif

#define ENV_BUGS ENV_COMPILER


/*
Compiler-dependent definitions

*/


#endif // _SeedSearcher_Compiler_h

