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









