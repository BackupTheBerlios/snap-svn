#include "StreamBuffer.h"
#include <string.h>

using namespace Persistance;

template <class T>
static inline const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}

StreamBuffer::StreamBuffer() : ptr(0), bufEnd(0), bufStart(0), bufferPos(0) {
}

StreamBuffer::~StreamBuffer() {
}

void StreamBuffer::dispose() {
	close();
	delete this;
}

void StreamBuffer::close() {
	flush();
}

void StreamBuffer::flush() {
	debug_mustbe(canWrite());
	if (bytesInBuffer() > 0)
		advanceNextBuffer();
}

void StreamBuffer::skipBytes(Size jumpSize) {
	for(;;) {
		Size blockSize= min((Size)(bufEnd - ptr), jumpSize);
		debug_mustbe(blockSize >= 0);
		if ((jumpSize-=blockSize) > 0) {
			ptr+=blockSize;
			advanceNextBuffer();
		} else {
			ptr+=blockSize;
			break;
		}
	}
}

StreamBuffer::Size StreamBuffer::peekBytes (void* outPtr, Size outSize) 
{
	Size blockSize = min ((Size) (bufEnd - ptr), outSize);
	debug_mustbe (blockSize >= 0);
    if (blockSize > 0) 			// keep the BoundsChecker happy
		memcpy (outPtr, ptr, blockSize);
	return blockSize;
}

void StreamBuffer::readBytes(void* outPtr, Size outSize) {
	for(;;) {
		Size blockSize= min((Size)(bufEnd - ptr), outSize);
		debug_mustbe(blockSize >= 0);
        if (blockSize > 0) {			// keep the BoundsChecker happy
			memcpy(outPtr, ptr, blockSize);
			ptr+=blockSize;
            outSize-=blockSize;
        }
		if (outSize > 0) {
			if (hasMoreBuffers()) {
				advanceNextBuffer();
				outPtr=(void*)(Ptr(outPtr) + blockSize);
			}
			else
				throwx (PrematureEOF());
		} else {
			break;
		}
	}
}

void StreamBuffer::writeBytes(const void* inPtr, Size inSize) {
	if (ptr>=bufEnd)
		advanceNextBuffer();
	for(;;) {
		Size blockSize= min(Size(bufEnd - ptr), inSize);
		if (blockSize > 0)			// keep the BoundsChecker happy
			memcpy(ptr, inPtr, blockSize);
		ptr+=blockSize;
		if ((inSize-=blockSize) > 0) {
			if (hasMoreBuffers ()) {
				advanceNextBuffer();
				inPtr=(void*)(Ptr(inPtr) + blockSize);
			}
			else
				throwx (PrematureEOF ());
		} else
			break;
	}
}

bool StreamBuffer::canRead() {
	return true;
}

bool StreamBuffer::canWrite() {
	return true;
}

//
// File        : $RCSfile: $ 
//               $Workfile: StreamBuffer.cpp $
// Version     : $Revision: 6 $ 
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

