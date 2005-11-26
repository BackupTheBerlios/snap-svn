#ifndef _SeedSearcher_Persistance_AbstractFormat_h
#define _SeedSearcher_Persistance_AbstractFormat_h

#include "Persistance/Defs.h"
#include "Core/AutoPtr.h"

BEGIN_NAMESPACE (Persistance);

//
//
class AbstractFormat {
   //
   // this class should be used to allow a class to have several externalization
   // methods. use like this:
   //
   // class MyClass {
   //    ...
   // };
   //
   // class Format1 : public AbstractFormat {
   // public:
   //    Format1 (const MyClass&) {
   //         ...
   //    }
   //
   //    virtual void write (TextWriter&) {
   //       ...
   //    }
   // }
   //
   // class Format2 : public AbstractFormat {
   //    ... (defined like Format1 class)
   // }
   //
   // void main () {
   //    MyClass object (...);
   //    TextWriter writer (...);
   //    writer << Format1 (object) << Format2 (object) << writer.endl;
   //

public:
   typedef AutoPtr <AbstractFormat> Owner;

   virtual ~AbstractFormat () {
   };

   friend TextWriter& operator << (TextWriter& out, const AbstractFormat& format) {
      format.write (out);
      return out;
   }
   friend TextWriter& operator << (TextWriter& out, const AbstractFormat::Owner& format) {
      format->write (out);
      return out;
   }

   virtual void write (TextWriter&) const= 0;

   
};

END_NAMESPACE (Persistance);

#endif // _SeedSearcher_Persistance_AbstractFormat_h

//
// File        : $RCSfile: $ 
//               $Workfile: AbstractFormat.h $
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

