#include "HashTable.h"

HashValue defaultHashFunction(const char* inStr, size_t inSize) {
	HashValue result= 314159236;
	for(const char* end= inStr+inSize; inStr < end; inStr++)
		result^=(*inStr * 0xF8429A19);
	return result;
}