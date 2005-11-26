#ifndef _Persistance_OutputStream_h
#define _Persistance_OutputStream_h

#include "StreamBuffer.h"

namespace Persistance {

class	OutputStream : public StreamBuffer {
public:	
	virtual void dispose();
   //
	// Cancel the write operation and dispose the stream. 
	// If can't cancel then just do dispose.	
   virtual void cancel();

	void write(const void* inPtr, Size inSize);
	void write(Byte in) {
		if (ptr>=bufEnd)
			advanceNextBuffer();
		*ptr++= in;
	}

	//	Number of bytes immediately available for writing
	Size available() const {
		return bytesLeftInBuffer();
	}

protected:
	~OutputStream();		// use dispose() instead of delete
	virtual bool hasMoreBuffers() const;
};

class NullOutputStream : public OutputStream {
public:
   virtual ~NullOutputStream () {
   }

protected:
   virtual bool hasMoreBuffers() const {
      return true;
   }
   virtual void nextBuffer() {
      setupBuffer (reinterpret_cast<Ptr> (_buffer), sizeof (_buffer));
   }

   char _buffer [1024];
};

}; // namesspace Persistance

#endif








