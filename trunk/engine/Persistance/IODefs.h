#ifndef SeedSearcher_Persistance_IODefs_h
#define SeedSearcher_Persistance_IODefs_h

#include "Core/Defs.h"

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






