#ifndef _Persistance_TextReader_h
#define _Persistance_TextReader_h

#include "core/Defs.h"

#include "StreamBuffer.h"
//#include <string>


class StrBuffer;
class Str;

BEGIN_NAMESPACE (Persistance);


class	InputStream;


class	TextReader {
public:
	TextReader (InputStream*, bool = true);
	virtual ~TextReader ();

	class Overflow: public BaseException {};
	class InvalidFormat: public BaseException {};

	typedef unsigned char Byte;

	enum EndOfLine {
		endl
	};

   TextReader& operator >> (bool& out)				{ read (out); return *this; }
   TextReader& operator >> (char& out)				{ read (out); return *this; }
   TextReader& operator >> (signed char& out)	{ read (out); return *this;}
	TextReader& operator >> (unsigned char& out)	{ read (out); return *this;}
	TextReader& operator >> (short& out)			{ read (out); return *this; }
	TextReader& operator >> (unsigned short& out){ read (out); return *this; }
	TextReader& operator >> (int& out)				{ read (out); return *this; }
   TextReader& operator >> (unsigned int& out)  { read (out); return *this; }
	TextReader& operator >> (long& out)				{ read ((int&)out); return *this; }
	TextReader& operator >> (unsigned long& out)	{ read ((unsigned int&)out); return *this; }
	TextReader& operator >> (float& out)			{ read (out); return *this; }	
	TextReader& operator >> (double& out)			{ read (out); return *this; }
   TextReader& operator >> (StrBuffer& out)		{ read (out); return *this; }
	TextReader& operator >> (char* out)				{ read (out); return *this; }
	TextReader& operator >> (EndOfLine)				{ read (endl); return *this; }

	void read (bool& out);
   void read (char& out);
   void read (signed char& out);
	void read (unsigned char& out);
	void read (short& out);
	void read (unsigned short& out);
	void read (int& n);
	void read (unsigned int& out);
	void read (float& out);
	void read (double& out);
	void read (StrBuffer& out);
	void read (char* out);
   void readln (StrBuffer& out);
	void readln (char* out);
	void read (char* out, size_t inSize);
	virtual void read (EndOfLine);

   void readUntil (StrBuffer& outBuffer, const Str& separator);
   void skipWhitespace ();

	// low-level interface
	bool atEol ();
   Byte readByte ();
	void unreadByte (Byte);
	bool atEnd () const;
	void skip (StreamBuffer::Size);
	StreamBuffer::Offset getPos ();

	InputStream* getStream () const 	{
		return stream;
	}

   int getBytesReadCount () const {
      return readCount;
   }

private:
	static bool iseol (Byte);
	short readShort ();
	int readInt ();
	long readLong ();
	//int64_t readInt64 ();
	double readDouble ();

private:
	InputStream* stream;
	bool owner;
	Byte buf	[1024];
	int bufStart, bufEnd;
	int unreadBufSize;
   int readCount;
};

END_NAMESPACE (Persistance);

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: TextReader.h $
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

