#ifndef _Persistance_Defs_h
#define _Persistance_Defs_h

#include "Core/Defs.h"

namespace Persistance {

   class Object;
   struct Manipulator;
   class Archive;
   class IArchive;
   class OArchive;
   class IRegistry;
   class ORegistry;
   class TFactoryBase;
   class TFactoryList;

   class InputStream;
   class OutputStream;
   class TextWriter;
   class TextReader;

   enum Prefix   {
      preClass = 0x10,  
      preArray = 0x20,  
      preNullPointer = 0x30,  
      preValidPointer = 0x40 , 
      preObjLink  = 0x50,  
      preObjInstance = 0x60 
   };

   enum PrimitiveCode {
      bool_code            = 10,
      char_code            = 20,
      signed_char_code     = 30,
      unsigned_char_code   = 40,
      signed_short_code    = 50,
      unsigned_short_code  = 60,
      signed_int_code      = 70,
      unsigned_int_code    = 80,
      signed_long_code     = 90,
      unsigned_long_code   = 100,
      float_code           = 110,
      double_code          = 120,
   };

   typedef unsigned char Flag;

/*
	CSZ_ID getID(CSZ_Object *obj);
	CSZ_ID getID(CSZ_Object& obj);*/
};

#endif
