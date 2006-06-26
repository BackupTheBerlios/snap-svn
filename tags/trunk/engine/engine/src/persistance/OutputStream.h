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

//
// File        : $RCSfile: $ 
//               $Workfile: OutputStream.h $
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

