#include "HashTable.h"

#if 0 
HashValue defaultHashFunction(const char* inStr, size_t inSize) {
	HashValue result= 314159236;
	for(const char* end= inStr+inSize; inStr < end; inStr++)
		result^=(*inStr * 0xF8429A19);
	return result;
}
#endif 

//
// KnuthConst ~ (sqrt(5) - 1) / 2 
static double KnuthConst = 0.61803398874989484820458683436564;

HashValue defaultHashFunction(const char* inStr, size_t inSize) 
{
	HashValue result= 314159236;
	for(int i=0 ; i < inSize ; i++)
		result^=(inStr [i] * 0xF8429A19 + i * 6180339887);
	return result;
}
