#ifndef _Persistance_StreamBuffer_h
#define _Persistance_StreamBuffer_h

#include "Core/Defs.h"

namespace Persistance {

class	StreamBuffer   {
protected:
	StreamBuffer();
	virtual ~StreamBuffer ();

public:
   typedef int ptrdiff_t; // also defined in <stddefs.h>
	typedef unsigned char Byte;
	typedef Byte* Ptr;
	typedef ptrdiff_t Distance;
	typedef ptrdiff_t Size;

	typedef Ptr Value;
	typedef Distance Difference;
	typedef Size Offset;

	virtual void dispose();			// calls close()
	virtual void flush();
	
	Offset getPos() const {
		return bufferPos + bytesInBuffer();
	}
	Size bytesInBuffer() const {
		return ptr - bufStart;
	}

	class PrematureEOF: public BaseException {
	};

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
