#ifndef _Persistance_IArchive_h
#define _Persistance_IArchive_h

#include "Defs.h"
#include "IRegistry.h"
#include "TextReader.h"
#include "TFactory.h"

#include "Error.h"
#include "Core/AutoPtr.h"

namespace Persistance {

class IArchive {
public:
	IArchive(InputStream*, TFactoryList*);
   ~IArchive();
   
	// Deserializing operators
   IArchive& operator >> (bool& param);
   IArchive& operator >> (char& param);
   IArchive& operator >> (signed char& param);
   IArchive& operator >> (unsigned char& param);
   IArchive& operator >> (short& param);
  	IArchive& operator >> (unsigned short& param);
   IArchive& operator >> (int& param);
   IArchive& operator >> (unsigned int& param);
   IArchive& operator >> (long& param);
   IArchive& operator >> (unsigned long& param);
	IArchive& operator >> (float& param);
	IArchive& operator >> (double& param);
	IArchive& operator >> (Object& param);
   
   template <class T>
   IArchive& operator >> (T*& param) {
      //
      // make sure it is a Object
      static_cast <Object*> (param);
      readObject (param);
      return *this;
   }

   Prefix readPrefix ();


   //
   // Reads an array of primitive - typed data or
   // a class/union/struct from the archive,
   // into a referenced pointer.
   // of course, memory is allocated for that pointer
   // automatically
   // the function also reads back the number of items 
   // in the array into the 1st parameter (n).
   // optionally, n could be NULL
   template <typename PrimType>
   void readPrimitiveArray (long* n, PrimType*& params) {
      static_cast <double> (*params);
      long len = readPrimArrayHelper (sizeof (PrimType), n);
      params = (len > 0)? new PrimType [len] : NULL;
      if (_text) {
         for (int i=0 ; i<len ; i++) 
            readPrimitive (params[i]);
      }
      else {
         size_t nbytes = len * sizeof (PrimType);
         _reader.read (params, nbytes);
      }
   }
   //
   // specialization for strings
   void readPrimitiveArray (long*n, char*& params) {
      long len = readPrimArrayHelper (sizeof (char), n);
      params = (len > 0)? new char [len+1] : NULL;
      if (_text) {
         //
         // now eat one whitespace
         mustbe (_reader.readByte () == ' ');
      }
      
      _reader.read (params, len);
      params [len] = 0;
   }

   template <class PrimType>
   void readPrimitive(PrimType& param) {
      if (_text) {
         _reader >> param;
      }
      else {
         char *ptr = reinterpret_cast <char*> (&param);
         _reader.read (ptr, sizeof(param));
      }
   }
   //
   // specialization
   void readPrimitive(unsigned char& param) {
      if (_text)  {
         //
         // read unsigned chars as numbers in text mode
         short s;
         readPrimitive (s);
         param = s;
      }
      else {
         _reader.read (param);
      }
   }
   //
   // specialization
   void readPrimitive(char& param) {
      _reader >> param;
   }


   template <class T>
   IArchive& readObject (T*& param) {
      ArrayAutoPtr <char> class_name = NULL;
      Object* object = readObjectElem (class_name);

      // invoke the function, and upcast it from CSZ_Object to T.               
      param = dynamic_cast <T*> (object);
      if (param == NULL)   {
         RaisePersistanceError2 ("Incompatible %s", class_name);
      }
      else
         param->serialize(*this);  // deserialize

      return *this;
   }

   template <class T>
   IArchive& registerObject (T* const&  param) {
      _registry.readObject( reinterpret_cast <CSZ_Object **> (const_cast<T**>((&param))) , *this );
      return *this;
   }

private:
   Object* readObjectElem (ArrayAutoPtr <char>&);
   long readPrimArrayHelper (size_t elementSize, long *n);
   void throwTypeNotMatchedException(int expected, int inArchive);

   bool _text;
   TextReader _reader;
   IRegistry _registry;
   AutoPtr <TFactoryList> _factories;
};


}; // Persistance

//#include "IArchive.ii"

#endif // _Persistance_IArchive_h
