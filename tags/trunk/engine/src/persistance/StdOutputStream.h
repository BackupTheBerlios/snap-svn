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

//
// File        : $RCSfile: $ 
//               $Workfile: StdOutputStream.h $
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

