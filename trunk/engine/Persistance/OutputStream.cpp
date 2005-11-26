#include "OutputStream.h"
#include <string.h>

template <class T>
static inline const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}



using namespace Persistance;

OutputStream::~OutputStream() {
}

void OutputStream::dispose() {
	StreamBuffer::dispose();
}

void OutputStream::cancel() {
	StreamBuffer::dispose();
}

void OutputStream::write(const void* inPtr, Size inSize) {
	if (ptr>=bufEnd)
		advanceNextBuffer();
	for(;;) {
		Size blockSize= min(Size(bufEnd - ptr), inSize);
		memcpy(ptr, inPtr, blockSize);
		ptr+=blockSize;
		if ((inSize-=blockSize) > 0) {
			advanceNextBuffer();
			inPtr=(void*)(Ptr(inPtr) + blockSize);
		} else
			break;
	}
}

bool OutputStream::hasMoreBuffers() const {
	return true;
}









