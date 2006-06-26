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

//
// File        : $RCSfile: $ 
//               $Workfile: InputStream.h $
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

