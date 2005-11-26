#ifndef _Persistance_StdOutputStream_h
#define _Persistance_StdOutputStream_h

#include "OutputStream.h"
#include <ostream>

namespace Persistance {

class StdOutputStream : public OutputStream {
public:
   StdOutputStream (std::ostream& out) : _out (out) {
   }
   virtual ~StdOutputStream () {
   }

protected:
   virtual void nextBuffer() {
      Size bytes = bytesInBuffer ();
      if (bytes > 0) {
         _out.write (_buffer, bytes);
      }

   	setupBuffer (reinterpret_cast<Ptr> (_buffer), sizeof (_buffer));
   }
   virtual bool hasMoreBuffers() const {
      return _out.good ();
   }
   virtual void flush () {
      _out.flush ();
      OutputStream::flush ();
   }

   std::ostream& _out;
   char _buffer [8 * 1024];
};


}; // namespace Persistance

#endif // _Persistance_StdOutputStream_h
