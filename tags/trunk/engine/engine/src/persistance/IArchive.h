#ifndef _Persistance_IArchive_h
#define _Persistance_IArchive_h

#include "Defs.h"
#include "IRegistry.h"
#include "TextReader.h"
#include "TFactory.h"
#include "Object.h"

#include "Error.h"
#include "core/AutoPtr.h"

class StrBuffer;

namespace Persistance {

class IArchive {
public:
   IArchive(InputStream*, TFactoryList*);
   ~IArchive();

   void readBool (bool&);
   void readChar (char&);
   void readSChar (signed char&);
   void readUChar (unsigned char&);
   void readShort (short&);
   void readSShort (signed short&);
   void readUShort (unsigned short&);
   void readInt (int&);
   void readSInt (signed int&);
   void readUInt (unsigned int&);
   void readLong (long&);
   void readSLong (signed long&);
   void readULong (unsigned long&);
   void readFloat (float&);
   void readDouble (double&);
   
   //
   // allocates a new string 
   const char* readString (char*&);
   const char* readString (char*&, int&);
   const char* readString (StrBuffer&);
   //
   // reads into buffer without allocating memory
   const char* readStringBuffer (char [], int, int* = NULL);

   void readBoolArray (bool*, int&);
   void readCharArray (char*, int&);
   void readSCharArray (signed char*, int&);
   void readUCharArray (unsigned char*, int&);
   void readShortArray (short*, int&);
   void readSShortArray (signed short*, int&);
   void readUShortArray (unsigned short*, int&);
   void readIntArray (int*, int&);
   void readSIntArray (signed int*, int&);
   void readUIntArray (unsigned int*, int&);
   void readLongArray (long*, int&);
   void readSLongArray (signed long*, int&);
   void readULongArray (unsigned long*, int&);
   void readFloatArray (float*, int&);
   void readDoubleArray (double*, int&);

   void readBoolBuffer (bool[], int, int* = NULL);
   void readCharBuffer (char[], int, int* = NULL);
   void readSCharBuffer (signed char[], int, int* = NULL);
   void readUCharBuffer (unsigned char[], int, int* = NULL);
   void readShortBuffer (short[], int, int* = NULL);
   void readSShortBuffer (signed short[], int, int* = NULL);
   void readUShortBuffer (unsigned short[], int, int* = NULL);
   void readIntBuffer (int[], int, int* = NULL);
   void readSIntBuffer (signed int[], int, int* = NULL);
   void readUIntBuffer (unsigned int[], int, int* = NULL);
   void readLongBuffer (long[], int, int* = NULL);
   void readSLongBuffer (signed long[], int, int* = NULL);
   void readULongBuffer (unsigned long[], int, int* = NULL);
   void readFloatBuffer (float[], int, int* = NULL);
   void readDoubleBuffer (double[], int, int* = NULL);
   
	// Deserializing operators
   IArchive& operator >> (bool&);
   IArchive& operator >> (char&);
   IArchive& operator >> (signed char&);
   IArchive& operator >> (unsigned char&);
   IArchive& operator >> (short&);
  	IArchive& operator >> (unsigned short&);
   IArchive& operator >> (int&);
   IArchive& operator >> (unsigned int&);
   IArchive& operator >> (long&);
   IArchive& operator >> (unsigned long&);
	IArchive& operator >> (float&);
	IArchive& operator >> (double&);
   IArchive& operator >> (char*&);
   IArchive& operator >> (StrBuffer&);
	IArchive& operator >> (Object&);

   void readObject (Object&);

   //
   // we would like to have this function, but we cant (see VC error C244).
   // a template wont work either, because of ambiguities:
   //    IArchive& operator >> (Object*& param) {


   //
   // manipulators are often temporary objects (which gcc takes as r-values)
   // therefore it is useful that the parameter here is 'const'
   IArchive& operator >> (const Manipulator& o) {
      readObject (o);
      return *this;
   }
   void readObject (const Manipulator& o) {
      const_cast <Manipulator&> (o).serialize (*this);
   }


   //
   // here we use the template solution, which works because 
   // the function's name is unique
   template <class T> void registerObject (T*& param) {
      Object** pObj = 
         reinterpret_cast <Object **> (
            const_cast<T**> ((&param)));

      _registry.readObject(pObj, *this );
   }

   //
   // here we use the template solution, which works because 
   // the function's name is unique
   template <class T> void readObject (T*& param) {
      const char* class_name = NULL;
      Object* object = readObjectElem (class_name);

      // invoke the function, and upcast it from CSZ_Object to T.               
      param = dynamic_cast <T*> (object);
      if (param == NULL)   {
         RaisePersistanceError2 ("Incompatible %s", class_name);
      }
      else
         param->serialize(*this);  // deserialize
   }


   bool text () const {
      return _text;
   }
   bool meta () const {
      return _meta;
   }
   bool strict () const {
      return _strict;
   }

   TextReader& reader() {
      return _reader;
   }
   const TFactoryList& factories () const {
      return *_factories;
   }
   IRegistry& registry () {
      return _registry;
   }
   Prefix readPrefix ();

private:
   Object* readObjectElem (const char*&);
   void throwTypeNotMatchedException(int expected, int inArchive);

   bool _text;    // is the archive textual
   bool _meta;    // should add meta data
   bool _strict;  // is meta data strict

   TextReader _reader;
   IRegistry _registry;
   AutoPtr <TFactoryList> _factories;
};


}; // Persistance


#endif // _Persistance_IArchive_h

//
// File        : $RCSfile: $ 
//               $Workfile: IArchive.h $
// Version     : $Revision: 11 $ 
//               $Author: Aviad $
//               $Date: 27/08/04 2:08 $ 
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

