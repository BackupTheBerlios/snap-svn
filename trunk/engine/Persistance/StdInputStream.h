#ifndef _Persistance_StdInputStream_h
#define _Persistance_StdInputStream_h

#include "InputStream.h"
#include <istream>

namespace Persistance {

class StdInputStream : public InputStream {
public:
   StdInputStream (std::istream& in) : _in (in) {
   }
   virtual ~StdInputStream () {
   }

protected:
   virtual void nextBuffer() {
      std::streamsize bytesRead = 0;
      const std::istream::sentry ok(_in);
      if (ok) {
          _in.read (_buffer, sizeof (_buffer));
          bytesRead = _in.gcount();
      }
      else {
			throwx (PrematureEOF ());
      }

   	setupBuffer (reinterpret_cast<Ptr> (_buffer), bytesRead);
   }
   virtual bool hasMoreBuffers() const {
      const std::istream::sentry ok(_in);
      return ok;

      //return _in.good ();
   }
   virtual void flush () {
	   //nothing to flush on read
   }

   std::istream& _in;
   char _buffer [8 * 1024];
};


}; // namespace Persistance

#endif // _Persistance_StdInputStream_h