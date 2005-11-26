#include "IArchive.h"
#include "Object.h"
#include "TFactory.h"

#include "Error.h"

#include "Core/AutoPtr.h"

using namespace Persistance;

///
/// default constructor
///
IArchive::IArchive(InputStream* in, TFactoryList* factories) 
:  _text (false), _factories (factories), _reader (in)
{
   //
   // read text flag from stream
   char c;
   _reader>> _text >> c;
   debug_mustbe (c == ' ');
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









/*******************************************************************/
/*                                                                 */
/*  function operator << ( Object& param)                      */
/*                                                                 */
/*  Purpose :  This is used to deserialize a reference to an object*/
/*                                                                 */
/*  Returns : CSZ_ArchiveIn&                                       */
/*                                                                 */
/*  Argumenents : Object& param- since all serialized objects  */
/*                                  must be derived from Object*/
/*                                  this polymorphic function is   */
/*                                  possible.                      */
/*                                                                 */
/*  Throws: 1)CSZ_ERR_VALIDATE_PREFIX_FAILURE when the prefix read */
/*                     is not preClass                             */
/*                                                                 */
/*          2)CSZ_ERR_DIFFRENT_CLASS_MEMBER_FAILURE when the class */
/*                 found in arciove doesn't match the one expected.*/
/*                                                                 */
/*          3)CSZ_ERR_READ_CLASS_FAILURE when the serializtion     */
/*                     operation fails. (more general)             */
/*                                                                 */
/*******************************************************************/      
IArchive&  IArchive::operator >> (Object& param)
{
   Prefix preExpected = readPrefix();

   if ( preExpected != preClass )   {
      RaisePersistanceError3 (
         "Expecting prefix no %d. %d found", preExpected , preClass);
   }

   const char * expected = typeid( param ).name();

   char* tmp;
   readPrimitiveArray (NULL, tmp);
   ArrayAutoPtr <char> classname = tmp;

	if ( strcmp( expected , classname.get ()) != 0 ) {
      RaisePersistanceError2 (
         "Incompatible %s", typeid(param).name());
	}
	else {
		param.serialize(*this);
	}

	return *this;	
}





long IArchive::readPrimArrayHelper (size_t elementSize, long *n)
{
	//
	// check that expected prefix
   Prefix preExpected = readPrefix();
   if ( preExpected != preArray )   {
      RaisePersistanceError3 (
         "Expecting prefix no %d. %d found", preExpected , preClass);
   }

  //
  // check expected PrimType size
  Persistance::Flag actualSize;
  *this >> actualSize;

  if (elementSize != actualSize)
	  throwTypeNotMatchedException(elementSize, actualSize);

   long len;
   readPrimitive(len);
   if ( n != NULL)
      *n = len;
 
   if ( len < 0 )  {  // BAD LENGTH Exception
      RaisePersistanceError (
         "Failed to read array, negative array length");
   }

   return len;
}


Object* IArchive::readObjectElem (ArrayAutoPtr <char>& class_name)
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
            char* tmp;
            readPrimitiveArray (NULL, tmp);
            class_name = tmp;

            // invoke the function, and upcast it from CSZ_Object to T.               
            object = _factories->createObject (class_name);
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



static bool strict = true;

static void throwTypeNotMatchedException (int expected, int inArchive)
{
   if (strict) {
      RaisePersistanceError3 (
         "code %d expected, code %d in archive", expected , inArchive);         
   }
   else {
      RaisePersistanceError3 (
         "expected %d bytes, %d bytes actually in archive", expected , inArchive);         
   }
}



//used in case the deserialization is out-of-sync with the archive.
//throws an exception indicating the problem
void IArchive ::throwTypeNotMatchedException(int expected, int inArchive)
{
   ::throwTypeNotMatchedException (expected, inArchive);
}


template <typename PrimType>
static void readPrimitiveT (IArchive& cia,
                                   PrimType& param, 
                                   unsigned char code)
{
   //match the length of param to the length saved in archive,
   //to help ensure the Serialization/Deserialization matches.
   Persistance::Flag expected, inArchive;
   
   expected = strict? code : sizeof(param);
   cia.readPrimitive(inArchive);
   if (expected != inArchive )
      throwTypeNotMatchedException(expected, inArchive);
   
	//restore actual data
   cia.readPrimitive (param);
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

