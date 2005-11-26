#ifndef _SeedSearcher_Persistance_StrInputStream_h
#define _SeedSearcher_Persistance_StrInputStream_h

#include "InputStream.h"
#include <string>

BEGIN_NAMESPACE (Persistance);

class FixedBufferInputStream : public InputStream {
public:
   FixedBufferInputStream (const char* inBuffer, int inCapacity) {
      setupBuffer( reinterpret_cast <Persistance::IODefs::Ptr> (
                        const_cast <char*> (inBuffer)), inCapacity);
   }
   ~FixedBufferInputStream () {
   }
   virtual void nextBuffer() {
      mustfail ();
   }
   virtual bool hasMoreBuffers() const {
      return false;
   }
   virtual void flush () {
   }
};

END_NAMESPACE (Persistance);

#endif 

//
// File        : $RCSfile: $ 
//               $Workfile: StrInputStream.h $
// Version     : $Revision: 1 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:41 $ 
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
// and the library authors apply.
//

