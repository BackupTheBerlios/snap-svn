#ifndef _SeedSearcher_Persistance_StrOutputStream_h
#define _SeedSearcher_Persistance_StrOutputStream_h

#include "OutputStream.h"
#include <string>

BEGIN_NAMESPACE (Persistance);

class StrOutputStream : public OutputStream {
public:
   StrOutputStream (std::string& out) : _out (out) {
   }

protected:
   virtual void nextBuffer() {
      Size bytes = bytesInBuffer ();
      if (bytes > 0) {
         _out.append (_buffer, bytes);
      }

   	setupBuffer (reinterpret_cast<Ptr> (_buffer), sizeof (_buffer));
   }
   virtual bool hasMoreBuffers() const {
      return true;
   }

private:
   char _buffer [1024];
   std::string& _out; 
};


class FixedBufferOutputStream : public OutputStream {
public:
  FixedBufferOutputStream (char* inBuffer, int inCapacity)
    : _host (inBuffer), _hostCapacity (inCapacity), _size (0) 
    {
    }
  
  ~FixedBufferOutputStream ()    {
    if (bytesInBuffer () > 0)
      flush ();
  }
  
  class BufferOverrun: public BaseException {};

  virtual void nextBuffer () {
    bufferPos += bytesInBuffer ();
    doFlush ();
    if (bufStart == 0 && bufEnd == 0)
      throwx (BufferOverrun ());
  }
  virtual void flush (){
    bufferPos += bytesInBuffer ();
    doFlush ();
    if (bufStart == 0 && bufEnd == 0)
      throwx (BufferOverrun ());
  }
  virtual bool hasMoreBuffers() const {
    return _size < _hostCapacity;
  }
  
  int getSize () const { return _size; }
  
 protected:
  char* _host;
  int _hostCapacity;
  int _size;
  
  void doFlush () {
    _size += bytesInBuffer ();
    if (_hostCapacity < _size)
      setupBuffer (Ptr (NULL), Size (0));
    else
      setupBuffer (Ptr (_host + _size), _hostCapacity - _size);
  }
};

END_NAMESPACE (Persistance);

#endif 

//
// File        : $RCSfile: $ 
//               $Workfile: StrOutputStream.h $
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

