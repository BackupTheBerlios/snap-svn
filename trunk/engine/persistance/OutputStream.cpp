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
		Size blockSize= tmin(Size(bufEnd - ptr), inSize);
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

//
// File        : $RCSfile: $ 
//               $Workfile: OutputStream.cpp $
// Version     : $Revision: 7 $ 
//               $Author: Aviad $
//               $Date: 7/09/04 9:42 $ 
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

