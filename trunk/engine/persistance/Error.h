#ifndef _Persistance_Error_h
#define _Persistance_Error_h

//
// it is important that source file names will not appear in release 
// version of a program for reasons of (1) security (2) executable size
#if BASE_DEBUG
#  define RaisePersistanceError(arg1)  \
      Persistance::Error::raise (__FILE__, __LINE__, arg1);
#else
#  define RaisePersistanceError(arg1)  \
      Persistance::Error::raise (__LINE__, arg1);
#endif


#  define RaisePersistanceError1(arg1)   \
      RaisePersistanceError(arg1);

#  define RaisePersistanceError2(arg1, arg2) {                    \
         char buffer [128 * 16];                                  \
         sprintf(buffer, arg1, arg2);                             \
         Persistance::Error::raise (__FILE__, __LINE__, buffer);  \
      }

#  define RaisePersistanceError3(arg1, arg2, arg3) {              \
         char buffer [128 * 16];                                  \
         sprintf(buffer, arg1, arg2, arg3);                       \
         Persistance::Error::raise (__FILE__, __LINE__, buffer);  \
      }
      

#  define RaisePersistanceError4(arg1, arg2, arg3, arg4) {        \
         char buffer [128 * 16];                                  \
         sprintf(buffer, arg1, arg2, arg3, arg4);                 \
         Persistance::Error::raise (__FILE__, __LINE__, buffer);  \
      }

#  define RaisePersistanceError5(arg1, arg2, arg3, arg4, arg5) {  \
         char buffer [128 * 16];                                  \
         sprintf(buffer, arg1, arg2, arg3, arg4, arg5);           \
         Persistance::Error::raise (__FILE__, __LINE__, buffer);  \
      }

namespace Persistance {

struct Error {
   static void raise (const char*, int, const char*);
   static void raise (int, const char*);
};


}; // namespace Persistance

#endif // _Persistance_Error_h

//
// File        : $RCSfile: $ 
//               $Workfile: Error.h $
// Version     : $Revision: 8 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
// Description :
//	The Persistence library contains both high & low level IO classes
//	and is high-performance, highly reusable framework 
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

