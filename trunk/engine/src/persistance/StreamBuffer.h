#ifndef _Persistance_StreamBuffer_h
#define _Persistance_StreamBuffer_h

#include "IODefs.h"

namespace Persistance {

class	StreamBuffer : public IODefs  {
protected:
	StreamBuffer();
	virtual ~StreamBuffer ();

public:
	virtual void dispose();			// calls close()
	virtual void flush();
	
	Offset getPos() const {
		return bufferPos + bytesInBuffer();
	}
	Size bytesInBuffer() const {
		return ptr - bufStart;
	}

	void skipBytes(Size jumpSize);
	
	Size peekBytes(void* outPtr, Size outSize);
	void readBytes(void* outPtr, Size outSize);
	Byte readByte() {
		if (ptr>=bufEnd)
			advanceNextBuffer();
		Byte result= *ptr++;
		return result;
	}
	void writeBytes(const void* inPtr, Size inSize);
	void writeByte(Byte in) {
		if (ptr>=bufEnd)
			advanceNextBuffer();
		*ptr++= in;
	}

	virtual bool canRead();
	virtual bool canWrite();

	bool atEnd() const {
		return ptr < bufEnd ? false : !hasMoreBuffers();
	}

protected:
	virtual void nextBuffer()= 0;
	virtual bool hasMoreBuffers() const= 0;
	virtual void close();			// calls flush()

	//	Utilities
	void setupBuffer(Ptr inLow, Ptr inHigh) {
		ptr= bufStart= inLow;
		bufEnd= inHigh;
	}
	void setupBuffer(Ptr inPtr, Size inSize) {
		setupBuffer(inPtr, inPtr + inSize);
	}
	void resetBuffer() {
		setupBuffer(0, Size(0));
	}
	Size bytesLeftInBuffer() const {
		return bufEnd - ptr;
	}
	void advanceNextBuffer() {
		bufferPos+=bytesInBuffer();
		nextBuffer();
		debug_mustbe(ptr!=0 && 0!=bufStart && bufStart<=ptr && ptr<=bufEnd);
	}
	Ptr acquire(Size inBytes) {
		Ptr savePtr= ptr;
		if ((ptr+=inBytes) <= bufEnd)
			return savePtr;
		else {
			ptr= savePtr;
			return 0;
		}
	}
protected:
	Ptr ptr, bufEnd, bufStart;
	Size bufferPos;
};


}; // namespace Persistance

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: StreamBuffer.h $
// Version     : $Revision: 7 $ 
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

