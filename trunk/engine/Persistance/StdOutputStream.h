#ifndef _Persistance_StdOutputStream_h
#define _Persistance_StdOutputStream_h

#include "OutputStream.h"
#include "UnbufferedChannel.h"
#include <iostream>

BEGIN_NAMESPACE (Persistance)

class StdUnbufferedOutput : public UnbufferedOutput {
public:
   StdUnbufferedOutput (std::ostream& out) : _out (&out) {
      _owner = false;
   }
   StdUnbufferedOutput (std::ostream* out, bool owner) 
   : _out (out), _owner (owner) {
   }
   virtual ~StdUnbufferedOutput () {
      if (_owner)
         delete _out;
   }
   virtual void writeBytes(const void* inPtr, Size inSize) {
      _out->write ( (const char*)inPtr, inSize);
   }
   virtual bool hasMoreBuffers() const {
      return _out->good ();
   }
   virtual void flush () {
      _out->flush ();
   }

protected:   
   std::ostream* _out;
   bool _owner;
};


class StdOutputStream : public SmallChannelOutput  {
public:
   StdOutputStream (std::ostream& out) 
   : SmallChannelOutput (&_channel, false), _channel (out) 
   {
   }
   StdOutputStream (std::ostream* out, bool owner) 
   : SmallChannelOutput (&_channel, false), _channel (out, owner) 
   {
   }

   StdUnbufferedOutput _channel;
};

//
// Optimization, because most STL streams are unbuffered,
// this is especially bad for file streams...
class BufferedStdOutputStream : public DChannelOutput {
public:
   enum { 
      HUGE_BUFFER = 1024 * 1024 * 4 /* 4 MBytes */ 
   };

public:
   BufferedStdOutputStream (std::ostream& out, int inSize = HUGE_BUFFER) 
   : DChannelOutput (&_channel ,false, inSize), _channel (out) {
   }

   StdUnbufferedOutput _channel;
};


END_NAMESPACE (Persistance);

#endif // _Persistance_StdOutputStream_h








