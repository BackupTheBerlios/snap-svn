#ifndef _Persistance_InputStream_h
#define _Persistance_InputStream_h

#include "StreamBuffer.h"

namespace Persistance {

class	OutputStream;

class	InputStream : public StreamBuffer {
public:
	void skip(Size skipSize);
	bool atEnd() const {
		return ptr < bufEnd ? false : !hasMoreBuffers();
	}
	void read(void* inDest, Size inDestSize);
	Byte read() {
		if (ptr>=bufEnd)
			advanceNextBuffer();
		Byte result= *ptr++;
		return result;
	}
	Size available() const {
		//	Number of bytes immediately available for reading
	   //	return bytesInBuffer();
		return bytesLeftInBuffer();
	}

	virtual void dispose();

	void copyTo(OutputStream* output);
	void copyTo(OutputStream* output, Size inBytes);

 protected:
   //
   // use dispose() instead of delete
	~InputStream();		
};

}; // namespace persistance

#endif
