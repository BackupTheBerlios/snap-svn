#ifndef _SeedSearcher_ExtraMath_h
#define _SeedSearcher_ExtraMath_h

#include "Core/Defs.h"

//
// this header is intended to include functions and macros
// which are available on unix but unavailable on windows

#if ENV_COMPILER==ENV_MICROSOFT
#  include "Legacy/MathFunctions.h"
#  include "Legacy/MathPlus.h"
#endif 


#endif
