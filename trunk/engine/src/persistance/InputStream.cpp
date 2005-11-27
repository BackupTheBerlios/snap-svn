#include "InputStream.h"
#include "OutputStream.h"

#include <string.h>

template <class T>
static inline const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}

using namespace Persistance;

InputStream::~InputStream() {
}

void InputStream::dispose() {
	StreamBuffer::dispose();
}

void InputStream::skip (Size skipSize)
{
	skipBytes (skipSize);
}

void InputStream::copyTo(OutputStream* output) {
	for(;;) {
		Size bytes= bytesLeftInBuffer();
		if (bytes > 0) {
			output->write(bufStart, bytes);
			ptr+=bytes;
		}
		if (!hasMoreBuffers())
			break;
		advanceNextBuffer();
	}
}


void InputStream::copyTo(OutputStream* output, Size inBytes) 
{
    Size toCopy;
    Size bytes;

    while (inBytes > 0) {
        //
        // check for available bytes in buffer
        bytes = bytesLeftInBuffer ();
        if (bytes > 0)  {
            //
            // copy every byte left in buffer to output, but no more than inBytes
            toCopy = tmin (bytes, inBytes);
            inBytes -= toCopy;

			output->write(ptr, toCopy);
			ptr+=toCopy;
        }
        else    {
            //
            // buffer is empty
            if (hasMoreBuffers ())  {
                //
                // more buffers available
                advanceNextBuffer ();
            }
            else    {
                //
                // cannot proceed
                debug_mustfail ();
                break;
            }
        }
    }
}



void InputStream::read(void* inDest, Size inDestSize) {
	Ptr dest= Ptr(inDest);
	debug_only(Ptr endDest= dest + inDestSize);
	for(;;) {
		Size blockSize= tmin((Size)(bufEnd - ptr), inDestSize);
		debug_mustbe(blockSize >= 0);
		if (blockSize > 0) {			// keep the BoundsChecker happy
			memcpy(dest, ptr, blockSize);
			ptr+=blockSize;
			debug_mustbe(dest + blockSize <= endDest);
		}
		if ((inDestSize-=blockSize) > 0) {
			advanceNextBuffer();
			dest+=blockSize;
		} else {
			break;
		}
	}
}

//
// File        : $RCSfile: $ 
//               $Workfile: InputStream.cpp $
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

