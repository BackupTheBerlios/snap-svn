#ifndef _Persistance_StdInputStream_h
#define _Persistance_StdInputStream_h

#include "UnbufferedChannel.h"
#include "InputStream.h"
#include <iostream>

BEGIN_NAMESPACE (Persistance);

class StdUnbufferedInput : public UnbufferedInput {
public:
   StdUnbufferedInput (std::istream& in) : _in (in) {
   }
   virtual ~StdUnbufferedInput () {
   }

   virtual Size readBytes(void* outPtr, Size outSize) {
      std::streamsize bytesRead = 0;
      std::istream::sentry ok(_in, /* noskip */ true);
      if (ok) {
         _in.read ( (char*)outPtr, outSize);
         bytesRead = _in.gcount();
      }
      else {
         throwx (PrematureEOF ());
      }

      return bytesRead;
   }
   virtual bool hasMoreBuffers() const {
      std::istream::sentry ok(_in, /* noskip */ true);
      return ok;
   }

   std::istream& _in;
};
   


class StdInputStream : public SmallChannelInput  {
public:
   StdInputStream (std::istream& in) 
   : SmallChannelInput (&_channel, false), _channel (in) 
   {
   }

   StdUnbufferedInput _channel;
};


//
// Optimization, because most STL streams are unbuffered,
// this is especially bad for file streams...
class BufferedStdInputStream : public DChannelInput {
public:
   enum { 
      HUGE_BUFFER = 1024 * 1024 * 4 /* 4 MBytes */ 
   };

public:
   BufferedStdInputStream (std::istream& in, int inSize = HUGE_BUFFER) 
   : DChannelInput (&_channel ,false, inSize), _channel (in) {
   }

   StdUnbufferedInput _channel;
};
  
   
END_NAMESPACE (Persistance);

#endif // _Persistance_StdInputStream_h

//
// File        : $RCSfile: $ 
//               $Workfile: StdInputStream.h $
// Version     : $Revision: 9 $ 
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

