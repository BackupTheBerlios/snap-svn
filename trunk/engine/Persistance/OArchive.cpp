#include "OArchive.h"

#include "Error.h"

using namespace Persistance;

///
/// default constructor
///
OArchive::OArchive(OutputStream* inStream,
                   TFactoryList* inFactories,
                   bool asText) 
:  _text (asText),
   _writer (inStream),
   _factories (inFactories)
{
   _writer << _text << ' ';
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







/*******************************************************************/
/*                                                                 */
/*  function operator << ( CSZ_Object& param)                      */
/*                                                                 */
/*  Purpose :  This is used to serialize a reference to an object. */
/*                                                                 */
/*  Returns : OArchive&                                       */
/*                                                                 */
/*  Argumenents : CSZ_Object& param- since all serialized objects  */
/*                                  must be derived from CSZ_Object*/
/*                                  this polymorphic function is   */
/*                                  possible.                      */
/*                                                                 */
/*  Throws: 1)CSZ_ERR_WRITE_CLASS_MEMBER_FAILURE when serializaton */
/*                    function of the object fails.                */
/*                                                                 */
/*          2)CSZ_ERR_WRITE_CLASS_FAILURE when the serializtion    */
/*                     operation fails. (more general)             */
/*                                                                 */
/*******************************************************************/      
OArchive& OArchive::operator << (Object& param)
{
   prependPrefix( preClass );

   //
   // TODO: put all class names in Archive header
   //write class name
	const char * classname = typeid(param).name();
   *this << classname;

   //actual serialization
    param.serialize( *this);
   return (*this);
}



///
/// 
///
OArchive& OArchive::operator << (Object* param)
{
	if (param ==NULL)
		prependPrefix ( preNullPointer );
	else	{
		prependPrefix ( preValidPointer );
		*this << *param;
	}

	return *this;
}																	                  	





///
/// this function registers an object in CSZ_Registrator either as declaration or reference.
///
OArchive& OArchive::registerObject (Object* param)
{
   _registry.registerObject (param , *this);
   return *this;
}



void OArchive::writePrimArrayHelper (size_t elementSize, long n)
{
   // check erroneous states
   if (n < 0)  {
      RaisePersistanceError ("Failed to write array (negative length)");
   }
   else {
      prependPrefix (preArray);
      //
      // store the size of each element
      *this << (Persistance::Flag) elementSize;

      // Store the number of elements in the array
      writePrimitive ( n );
   }
}

OArchive& OArchive::operator << (const char* param)
{
   writePrimitiveArray (strlen (param), param);
   return *this;
}


static bool strict = true;

template <typename PrimType>
static inline void writePrimitiveT (OArchive& cia,
                                    PrimType param, 
                                    Persistance::Flag code)
{
   //
   // make sure this is indeed a primitive
   static_cast <double> (param);

   //Save the length/type of param, to help ensure the Serialization/Deserialization matches.      
   //
   // TODO: make this safety optional, to save space
   cia.writePrimitive  ((Persistance::Flag) (strict? code : sizeof(PrimType)));
   cia.writePrimitive ( param );
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



