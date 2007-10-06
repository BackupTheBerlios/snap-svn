#include "IArchive.h"
#include "Object.h"
#include "TFactory.h"

#include "Error.h"

#include "core/AutoPtr.h"
#include "core/Str.h"

#include <sstream>

using namespace Persistance;

static void throwTypeNotMatchedException (bool strict, 
					  int expected, 
					  int inArchive)
{
   if (strict) {
      RaisePersistanceError3 (
         "code %d expected, code %d in archive", expected , inArchive);
   }
   else {
      RaisePersistanceError3 (
         "expected %d bytes, %d bytes actually in archive", 
	 expected , inArchive);         
   }
}



//used in case the deserialization is out-of-sync with the archive.
//throws an exception indicating the problem
void IArchive ::throwTypeNotMatchedException(int expected, int inArchive)
{
   ::throwTypeNotMatchedException (_strict, expected, inArchive);
}



///
/// default constructor
///
IArchive::IArchive(InputStream* in, TFactoryList* factories) 
  :  _text (false),  _reader (in), _factories (factories)
{
   //
   // read option flags from stream
   _reader >> _text  >> TextReader::endl
           >> _meta  >> TextReader::endl
           >> _strict>> TextReader::endl;

   //
   // update factory list with factory ids
   _factories->serialize (*this);
}


///
/// destructor
///
IArchive::~IArchive()
{
   // before desrializing is completed, a second pass is made in which
   // object references are linked with their declarations
   // this is in the registrators destructor
}




Prefix IArchive::readPrefix()
{
	Persistance::Flag pre;
   *this >> pre;
	return (Prefix)pre;
}










static TFactoryBase* readClass (IArchive& in)
{
   //
   // we read the object id in the archive
   TFactoryList::FactoryID id;
   in >> id;
   TFactoryBase* factory = in.factories ().getFactory (id);
   if (!factory) {
      std::ostringstream str;
      str << "Unknown factory id " << id;    
      RaisePersistanceError (str.str ().c_str());
   }
   return factory;
}

static TFactoryBase* validateClassName (IArchive& in, const char* expected)
{
   TFactoryBase* factory = readClass (in);
   const char* class_name = factory->name ();
	if ( strcmp( expected , class_name) != 0 ) {
         RaisePersistanceError3 (
            "Incompatible %s with %s", expected, class_name);
   }

   return factory;
}

static Object* createClassObject (IArchive& in, const char* expected)
{
   TFactoryBase* factory = (expected == NULL)?
      readClass (in) : validateClassName (in, expected);
   return factory->create ();
}


IArchive&  IArchive::operator >> (Object& param)
{
   readObject (param);
   return *this;
}

void IArchive::readObject (Object& param)
{
   Prefix preExpected = readPrefix();

   if ( preExpected != preClass )   {
      RaisePersistanceError3 (
         "Expecting prefix no %d. %d found", preExpected , preClass);
   }

	param.serialize(*this);
}





static int readPrimArrayHelper (IArchive& in, size_t elementSize, int *n)
{
	//
	// check that expected prefix
   Prefix preExpected = in.readPrefix();
   if ( preExpected != preArray )   {
      RaisePersistanceError3 (
         "Expecting prefix no %d. %d found", preExpected , preClass);
   }

  //
  // check expected PrimType size
  Persistance::Flag actualSize;
  in >> actualSize;

  if (elementSize != actualSize)
	  throwTypeNotMatchedException(in.strict (), elementSize, actualSize);

   int len;
   in >> len;
   if ( n != NULL)
      *n = len;
 
   if ( len < 0 )  {  // BAD LENGTH Exception
      RaisePersistanceError (
         "Failed to read array, negative array length");
   }

   return len;
}



Object* IArchive::readObjectElem (const char*& class_name)
{
   Object* object = NULL;
   Prefix preExpected = readPrefix();
   switch (preExpected )   {
	   case preNullPointer: {
			break;
      }

      case preValidPointer:   {
         preExpected = readPrefix();
         if ( preExpected != preClass )   {
            RaisePersistanceError3 (
               "Expecting prefix no. %d. %d found", preExpected , preClass );
         }
         else {

            // invoke the function, and upcast it from CSZ_Object to T.               

            object = 
               createClassObject (*this, NULL);
         }
         break;
      }

		default: {
         RaisePersistanceError3 (
            "Expecting prefix no. %d. %d found", preExpected , preValidPointer );
      }
      break;
   }

   return object;
}





template <class PrimType>
static void readPrimitive(IArchive& in, PrimType& param) {
   if (in.text ()) {
      char c;
      in.reader() >> param >> c;
      debug_mustbe (c==' ');
   }
   else {
      char *ptr = reinterpret_cast <char*> (&param);
      in.reader ().read (ptr, sizeof(param));
   }
}

static void readPrimitive(IArchive& in, unsigned char& param) {
   if (in.text ()) {
      char c;
      short x;
      in.reader() >> x >> c;
      param = static_cast <unsigned char> (x);
      debug_mustbe (c == ' ');
   }
   else {
      char *ptr = reinterpret_cast <char*> (&param);
      in.reader ().read (ptr, sizeof(unsigned char));
   }
}

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
static void readPrimitiveArray (IArchive& in, PrimType*& params, int* n) {
  USELESS (static_cast <double> (*params); );
   int len = readPrimArrayHelper (in, sizeof (PrimType), n);
   if (in.text ()) {
      for (int i=0 ; i<len ; i++) 
         readPrimitive (params[i]);
   }
   else {
      size_t nbytes = len * sizeof (PrimType);
      in.reader ().read ((char*)params, nbytes);
   }
}

template <typename PrimType>
static void readPrimitiveBuffer (IArchive& in, 
				 PrimType* params, 
				 int size, int* n) 
{
  USELESS (static_cast <double> (*params); );
   int len = readPrimArrayHelper (in, sizeof (PrimType), n);
   if (size < len) {
      RaisePersistanceError2 ("Buffer size too small %d", size);
   }

   if (in.text ()) {
      for (int i=0 ; i<len ; i++) 
         readPrimitive (in, params[i]);
   }
   else {
      size_t nbytes = len * sizeof (PrimType);
      in.reader ().read ((char*)params, nbytes);
   }
}


template <typename PrimType>
static void readPrimitiveT (IArchive& cia,
                                   PrimType& param, 
                                   unsigned char code)
{
   //match the length of param to the length saved in archive,
   //to help ensure the Serialization/Deserialization matches.
   Persistance::Flag expected, inArchive;

   if (cia.meta ()) {
      expected = cia.strict ()? code : sizeof(param);
      
      int bytesSoFar = cia.reader ().getBytesReadCount ();
      bytesSoFar = cia.reader ().getBytesReadCount ();

      readPrimitive(cia, inArchive);
      if (expected != inArchive )
         throwTypeNotMatchedException(cia.strict (), expected, inArchive);
   }
   
	//restore actual data
   readPrimitive (cia, param);
}






IArchive&  IArchive :: operator >> (bool& param)
{
   readPrimitiveT (*this, param, bool_code);
	return *this;
}

IArchive&  IArchive :: operator >> (char& param)
{
   readPrimitiveT (*this, param, char_code);
	return *this;
}

IArchive&  IArchive :: operator >> (signed char& param)
{
   readPrimitiveT (*this, param, signed_char_code);
	return *this;
}

IArchive&  IArchive :: operator >> (unsigned char& param)
{
   readPrimitiveT (*this, param, unsigned_char_code);
	return *this;
}



IArchive&  IArchive :: operator >> (signed short& param)
{
   readPrimitiveT (*this, param, signed_short_code);
	return *this;
}

IArchive&  IArchive :: operator >> (unsigned short& param)
{
   readPrimitiveT (*this, param, unsigned_short_code);
	return *this;
}



IArchive&  IArchive :: operator >> (signed int& param)
{
   readPrimitiveT (*this, param, signed_int_code);
	return *this;
}

IArchive&  IArchive :: operator >> (unsigned int& param)
{
   readPrimitiveT (*this, param, unsigned_int_code);
	return *this;
}




IArchive&  IArchive :: operator >> (signed long& param)
{
   readPrimitiveT (*this, param, signed_long_code);
	return *this;
}

IArchive&  IArchive :: operator >> (unsigned long& param)
{
   readPrimitiveT (*this, param, unsigned_long_code);
	return *this;
}


IArchive&  IArchive :: operator >> (float& param)
{
   readPrimitiveT (*this, param, float_code);
	return *this;
}


IArchive&  IArchive :: operator >> (double& param)
{
   readPrimitiveT (*this, param, double_code);
	return *this;
}

IArchive&  IArchive :: operator >> (char*& param)
{
   readString (param);
	return *this;
}

IArchive&  IArchive :: operator >> (StrBuffer& param)
{
   readString (param);
	return *this;
}

const char* IArchive::readString (char*& str)
{
   int len;
   return readString (str, len);
}

const char* IArchive::readString (StrBuffer& str)
{
   char* ptr;
   str.acquire ((char*)readString (ptr));
   return ptr;
}

const char* IArchive::readString (char*& str, int& len)
{
   str = NULL;
   *this >> len;
   if (len > 0) {
      str = new char [len + 1];
      _reader.read (str, len);
      str [len] = '\0';
   }
   
   return str;
}

const char* IArchive::readStringBuffer (char buffer[], int size, int* outLen)
{
   buffer[0] = '\0';
   
   int len;
   *this >> len;
   if (outLen != NULL)
      *outLen = len;

   debug_mustbe (len < size);
   if (len > 0) {
      _reader.read (buffer, len);
      buffer [len] = '\0';
   }
   
   return buffer;
}

void IArchive::readBoolBuffer (bool b[], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readCharBuffer (char b[], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readSCharBuffer (signed char b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readUCharBuffer (unsigned char b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readShortBuffer (short b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readSShortBuffer (signed short b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readUShortBuffer (unsigned short b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readIntBuffer (int b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readSIntBuffer (signed int b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readUIntBuffer (unsigned int b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readLongBuffer (long b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readSLongBuffer (signed long b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readULongBuffer (unsigned long b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readFloatBuffer (float b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}
void IArchive::readDoubleBuffer (double b [], int s, int* l)
{
   readPrimitiveBuffer (*this, b, s, l);
}

//
// File        : $RCSfile: $ 
//               $Workfile: IArchive.cpp $
// Version     : $Revision: 12 $ 
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

