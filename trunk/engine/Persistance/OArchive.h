#ifndef _Persistance_OArhive_h
#define _Persistance_OArhive_h

#include "Defs.h"
#include "ORegistry.h"
#include "TFactory.h"

#include "Error.h"
#include "TextWriter.h"
#include "Core/AutoPtr.h"

namespace Persistance {

   //
   // defined in OutputStream.h
   class OutputStream;

   class OArchive {
   public:
		OArchive         (OutputStream*,
                        TFactoryList*,
                        bool asText = false);
      ~OArchive        ();

      void prependPrefix    (Prefix);

		OArchive& operator << (bool param);
      OArchive& operator << (char param);
      OArchive& operator << (signed char param);
      OArchive& operator << (unsigned char param);
		OArchive& operator << (signed short param);
		OArchive& operator << (unsigned short param);
      OArchive& operator << (int param);
      OArchive& operator << (unsigned int param);
      OArchive& operator << (long param);
      OArchive& operator << (unsigned long param);
		OArchive& operator << (float param);
		OArchive& operator << (double param);
      //
      // for strings
      OArchive& operator << (const char* param);
		OArchive& operator << (Object& param);
      OArchive& operator << (Object* param);

      OArchive& registerObject (Object*);

      template <typename PrimType>
      void writePrimitiveArray (long n, const PrimType* params) {
         //
         // make sure PrimType is indeed primitive
         static_cast <double> (*params);
         writePrimArrayHelper (n, sizeof (PrimType));
         if (_text)  {
            for (int i=0 ; i<n ; i++) 
               writePrimitive (params[i]);

            _writer << ' ';
         }
         else {
            size_t nbytes = n * sizeof (PrimType);
            _writer.write (params, nbytes);
         }
      }
      //
      // specialization for strings
      void writePrimitiveArray (long n, const char* params) {
         writePrimArrayHelper (sizeof (char), n);
         _writer.write (params, n);
         if (_text) {
            //
            // add whitespace to make file look better
            _writer << ' ';
         }
      }

      template <class PrimType> 
      void writePrimitive(PrimType param) {
         //
         // make sure PrimType is indeed primitive
         static_cast <double> (param);
         if (_text) {
            _writer << param << ' ';
         }
         else {
            //
            // binary represention
            const char* ptr = reinterpret_cast <const char*> (&param);
            _writer.write (ptr, sizeof(PrimType));
         }
      }
      //
      // specialization
      void writePrimitive(unsigned char param) {
         if (_text)
            writePrimitive (static_cast<short> (param));
         else
            _writer.write (param);

      }
      //
      // specialization
      void writePrimitive(char param) {
         _writer << param;
      }
      

	private:
      void writePrimArrayHelper (size_t elementSize, long n);


      bool _text;
      TextWriter _writer;
      ORegistry _registry;
      AutoPtr <TFactoryList> _factories;
   };
};


//
// include template function definitions
//#include "OArchive.ii"


#endif // _Persistance_OArhive_h 
