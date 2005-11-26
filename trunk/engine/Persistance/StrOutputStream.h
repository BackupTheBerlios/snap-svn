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

END_NAMESPACE (Persistance);

#endif 