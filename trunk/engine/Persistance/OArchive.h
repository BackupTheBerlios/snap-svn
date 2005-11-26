#ifndef _Persistance_OArhive_h
#define _Persistance_OArhive_h

#include "Defs.h"
#include "ORegistry.h"
#include "TFactory.h"

#include "Error.h"
#include "TextWriter.h"
#include "Core/AutoPtr.h"

//
// defined in Core/Str.h
class Str;

BEGIN_NAMESPACE (Persistance);

//
// defined in OutputStream.h
class OutputStream;

class OArchive {
public:
	OArchive (  OutputStream*,
               TFactoryList*,
               bool asText = false,
               bool addMeta = false,
               bool strict = false);

   ~OArchive ();

   void writeBool (bool);
   void writeChar (char);
   void writeSChar (signed char);
   void writeUChar (unsigned char);
   void writeShort (short);
   void writeSShort (signed short);
   void writeUShort (unsigned short);
   void writeInt (int);
   void writeSInt (signed int);
   void writeUInt (unsigned int);
   void writeLong (long);
   void writeSLong (signed long);
   void writeULong (unsigned long);
   void writeFloat (float);
   void writeDouble (double);
   void writeString (const char*);
   void writeString (const char*, int);
   void writeString (const Str&);

	void writeObject (const Object&);
   void writeObject (const Object*);
   OArchive& registerObject (const Object*);
   OArchive& registerObject (const Object*, bool);

   void writeBoolArray (const bool*, int);
   void writeCharArray (const char*, int);
   void writeSCharArray (const signed char*, int);
   void writeUCharArray (const unsigned char*, int);
   void writeShortArray (const short*, int);
   void writeSShortArray (const signed short*, int);
   void writeUShortArray (const unsigned short*, int);
   void writeIntArray (const int*, int);
   void writeSIntArray (const signed int*, int);
   void writeUIntArray (const unsigned int*, int);
   void writeLongArray (const long*, int);
   void writeSLongArray (const signed long*, int);
   void writeULongArray (const unsigned long*, int);
   void writeFloatArray (const float*, int);
   void writeDoubleArray (const double*, int);

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
   OArchive& operator << (const char* param);
	OArchive& operator << (const Object& param);
   OArchive& operator << (const Object* param);

   //
   // manipulators
   OArchive& operator << (const Manipulator& o) {
      writeObject (o);
      return *this;
   }
   void writeObject (const Manipulator& o) {
      const_cast <Manipulator&> (o).serialize (*this);
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

   //
   // get/set user-defined context
   void* getContext () const {
      return _ctx;
   }
   void* setContext (void* in) {
      void* prev= _ctx;
      _ctx = in;
      return prev;
   }

   //
   // treat as private
   TextWriter& writer () {
      return _writer;
   }
   const TFactoryList& factories () const {
      return *_factories;
   }
   void prependPrefix (Prefix);

private:
   bool _text;    // is the archive textual
   bool _meta;    // should add meta data
   bool _strict;  // is meta data strict

   TextWriter _writer;
   ORegistry _registry;
   AutoPtr <TFactoryList> _factories;
   void* _ctx;
};

};


#endif // _Persistance_OArhive_h 







