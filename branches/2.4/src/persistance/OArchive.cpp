#include "OArchive.h"

#include "Error.h"

using namespace Persistance;



/*
//
// specialization
void writePrimitive(unsigned char param) {
   if (_text)
      writePrimitive (static_cast<short> (param));
   else
      _writer.write (param);

}
*/






///
/// default constructor
///
OArchive::OArchive(OutputStream* inStream,
                   TFactoryList* inFactories,
                   bool asText,
                   bool addMeta,
                   bool strict) 
:  _text (asText),
   _meta (addMeta),
   _strict (strict),
   _writer (inStream),
   _factories (inFactories)
{
   _writer << _text  << _writer.EOL ()
           << _meta  << _writer.EOL ()
           << _strict<< _writer.EOL ();

   _factories->serialize (*this);
}

OArchive::~OArchive()
{
}



/*******************************************************************/
/*                                                                 */
/*  function PrependPrefix                                         */
/*                                                                 */
/*  Purpose :  This is used every time new data is inserted,       */
/*             In order to describe it.                            */
/*                                                                 */
/*  Returns : void                                                 */
/*                                                                 */
/*  Argumenents : enum Prefix pre - what is the prefix to prepend. */
/*                                                                 */
/*  Throws : CSZ_ERR_PREPEND_FAILURE when fails                    */
/*                                                                 */
/*******************************************************************/      

void OArchive::prependPrefix(Prefix pre)
{
   *this << (Persistance::Flag)pre ;
}





static void writeClass (OArchive& out, const Object& param)
{
   // 
   //write class id
   const std::type_info& type = typeid (param); 
   const char * classname = type.name();
   TFactoryBase* factory = out.factories ().getFactory (type);
   if (!factory) {
      RaisePersistanceError2 ("Factory missing for %s", classname);
   }
   //
   // the factory's address is its ID
   out << (TFactoryList::FactoryID) factory;

}

    
void OArchive::writeObject (const Object& param)
{
   prependPrefix( preClass );

   //actual serialization
   const_cast <Object&> (param).serialize( *this);
}

OArchive& OArchive::operator << (const Object& param)
{
   writeObject (param);
   return (*this);
}



///
/// 
///
void OArchive::writeObject (const Object* param)
{
	if (param ==NULL)
		prependPrefix ( preNullPointer );
	else	{
		prependPrefix ( preValidPointer );
      prependPrefix( preClass );

      //
      // write class information
      writeClass (*this, *param);

      //actual serialization
      const_cast <Object*> (param)->serialize( *this);
	}
}

OArchive& OArchive::operator << (const Object* param)
{
   writeObject (param);
	return *this;
}





///
/// this function registers an object in CSZ_Registrator either as declaration or reference.
///
OArchive& OArchive::registerObject (const Object* param)
{
   _registry.registerObject (param , *this);
   return *this;
}

OArchive& OArchive::registerObject (const Object* param, bool isInstance)
{
   if (isInstance && param != NULL)
      _registry.registerObjectInstance (param , *this);
   else 
      _registry.registerObjectLink (param , *this);
   return *this;
}



template <class PrimType> 
static void writePrimitive(OArchive& out, PrimType param) {
   //
   // make sure PrimType is indeed primitive
  USELESS (static_cast <double> (param));

   TextWriter& _writer = out.writer ();

   if (out.text ()) {
      _writer << param << ' ';
   }
   else {
      //
      // binary represention
      const char* ptr = reinterpret_cast <const char*> (&param);
      _writer.write (ptr, sizeof(PrimType));
   }
}

static void writePrimitive(OArchive& out, unsigned char param) {
   TextWriter& _writer = out.writer ();

   if (out.text ()) {
      _writer << (short) param << ' ';
   }
   else {
      //
      // binary represention
      const char* ptr = reinterpret_cast <const char*> (&param);
      _writer.write (ptr, sizeof(unsigned char));
   }
}

template <typename PrimType>
static void writePrimitiveArray (OArchive& out, const PrimType* params, int n) 
{
   //
   // make sure PrimType is indeed primitive
  USELESS (static_cast <double> (*params));
   size_t elementSize = sizeof (PrimType);

   // check erroneous states
   if (n < 0)  {
      RaisePersistanceError ("Failed to write array (negative length)");
   }
   else {
      out.prependPrefix (preArray);
      //
      // store the size of each element
      out << (Persistance::Flag) elementSize;

      // Store the number of elements in the array
      out << n;
   }

   TextWriter& _writer = out.writer ();
   if (out.text ())  {
      for (int i=0 ; i<n ; i++) 
         writePrimitive (out, params [i]);
   }
   else {
      char* ptr = (char*) params; 
      size_t nbytes = n * sizeof (PrimType);
      _writer.write (ptr, nbytes);
   }
}


template <typename PrimType>
static inline void writePrimitiveT (OArchive& out,
                                    PrimType param, 
                                    Persistance::Flag code)
{
   //
   // make sure this is indeed a primitive
  USELESS (static_cast <double> (param););

   if (out.meta ()) {
      //
      // Save the length/type of param, to help ensure 
      // the Serialization/Deserialization matches.      
      Persistance::Flag c = 
	(Persistance::Flag) (out.strict ()? code : sizeof(PrimType));
      writePrimitive  (out, c);
   }
   writePrimitive (out, param );
}

//
//  1) overloaded operators << for types char , short , int , long , float ,double.
//
OArchive& OArchive::operator << (bool param)
{
   writePrimitiveT (*this, param, bool_code);
   return *this;
}


OArchive& OArchive::operator << (char param) 
{
   writePrimitiveT (*this, param, char_code);
   return *this;
}

OArchive& OArchive::operator << (signed char param) 
{
   writePrimitiveT (*this, param, signed_char_code);
   return *this;
}

OArchive& OArchive::operator << (unsigned char param)
{
   writePrimitiveT (*this, param, unsigned_char_code);
   return *this;
}



OArchive& OArchive::operator << (signed short param)
{
   writePrimitiveT (*this, param, signed_short_code );
   return *this;
}

OArchive& OArchive::operator << (unsigned short param)
{
   writePrimitiveT (*this, param, unsigned_short_code );
   return *this;
}




OArchive& OArchive::operator << (signed int param)
{
   writePrimitiveT (*this, param, signed_int_code );
   return *this;
}

OArchive& OArchive::operator << (unsigned int param)
{
   writePrimitiveT (*this, param, unsigned_int_code );
   return *this;
}






OArchive& OArchive::operator << (signed long param)
{
   writePrimitiveT (*this, param, signed_long_code );
   return *this;
}

OArchive& OArchive::operator << (unsigned long param)
{
   writePrimitiveT (*this, param, unsigned_long_code );
   return *this;
}


OArchive& OArchive::operator << (float param)
{
   writePrimitiveT (*this, param, float_code);
   return *this;
}


OArchive& OArchive::operator << (double param)
{
   writePrimitiveT (*this, param, double_code);
   return *this;
}

OArchive& OArchive::operator << (const char* str)
{
   writeString (str);
   return *this;
}


void OArchive::writeString (const char* str)
{
   writeString (str, strlen (str));
}

void OArchive::writeString (const char* str, int len)
{
   //
   // do not write the the closing NULL
   debug_mustbe (!str [len - 1] == 0);

   *this << len;
   _writer.write (str, len);
   if (_text)
      _writer << ' ';
}



void OArchive::writeBoolArray (const bool* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeCharArray (const char* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeSCharArray (const signed char* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeUCharArray (const unsigned char* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeShortArray (const short* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeSShortArray (const signed short* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeUShortArray (const unsigned short* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeIntArray (const int* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeSIntArray (const signed int* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeUIntArray (const unsigned int* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeLongArray (const long* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeSLongArray (const signed long* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeULongArray (const unsigned long* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeFloatArray (const float* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

void OArchive::writeDoubleArray (const double* a, int l)
{
   writePrimitiveArray (*this, a, l);
}

//
// File        : $RCSfile: $ 
//               $Workfile: OArchive.cpp $
// Version     : $Revision: 9 $ 
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

