#ifndef SeedSearcher_Persistance_IODefs_h
#define SeedSearcher_Persistance_IODefs_h

#include "core/Defs.h"

BEGIN_NAMESPACE (Persistance);

struct IODefs {
   typedef int ptrdiff_t; // also defined in <stddefs.h>
	typedef unsigned char Byte;
	typedef Byte* Ptr;
	typedef ptrdiff_t Distance;
	typedef ptrdiff_t Size;

	typedef Ptr Value;
	typedef Distance Difference;
	typedef Size Offset;

	class PrematureEOF: public BaseException {
	};
};

END_NAMESPACE (Persistance);

#endif // SeedSearcher_Persistance_IODefs_h

//
// File        : $RCSfile: $ 
//               $Workfile: IODefs.h $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 27/08/04 2:08 $ 
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

