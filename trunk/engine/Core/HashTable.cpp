#include "HashTable.h"

#if 0 
HashValue defaultHashFunction(const char* inStr, size_t inSize) {
	HashValue result= L_PI;
	for(const char* end= inStr+inSize; inStr < end; inStr++)
		result^=(*inStr * ALEX_CONST);
	return result;
}
#endif 

static const unsigned long ALEX_CONST = 0xF8429A19;
static const unsigned long L_PHI = 6180339;
static const unsigned long L_PI = 31415923;


HashValue defaultHashFunction(const char* inStr, size_t inSize) 
{
	HashValue result= L_PI;
	for(size_t i=0 ; i < inSize ; i++)
		result^=(inStr [i] * ALEX_CONST + i * L_PHI);
	return result;
}


