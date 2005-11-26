#ifndef _Persistance_TextWriter_h
#define _Persistance_TextWriter_h

#include <stdlib.h>

class Str;

namespace Persistance {

class	OutputStream;

class	TextWriter {
 public:
	TextWriter(OutputStream* inStream, bool inOwner= true);
	virtual ~TextWriter();

	enum EndOfLine {
		endl
	};

	TextWriter& operator<<(bool in)				{ write(in); return *this; }
   TextWriter& operator<<(char in)				{ write(in); return *this; }
	TextWriter& operator<<(unsigned char in)	{ write(in); return *this;}
	TextWriter& operator<<(short in)			{ write(in); return *this; }
	TextWriter& operator<<(unsigned short in)	{ write(in); return *this; }
	TextWriter& operator<<(int in)				{ write(in); return *this; }
	TextWriter& operator<<(unsigned int in)		{ write(in); return *this; }
	TextWriter& operator<<(long in)				{ write((int)in); return *this; }
	TextWriter& operator<<(unsigned long in)	{ write((unsigned int)in); return *this; }
	TextWriter& operator<<(float in)			{ write(in); return *this; }	
	TextWriter& operator<<(double in)			{ write(in); return *this; }
	TextWriter& operator<<(const char* in)		{ write(in); return *this; }
   TextWriter& operator<<(const Str& in)		{ write(in); return *this; }
	TextWriter& operator<<(const void* in)		{ write(in); return *this; }
	TextWriter& operator<<(EndOfLine)			{ write(endl); return *this; }

	void write(bool in);
   void write(char in);
	void write(unsigned char in);
	void write(short in);
	void write(unsigned short in);
	void write(int n);
	void write(unsigned int in);
	void write(float in);
	void write(double in);
   void write(const char* in);
	void write(const char* in, size_t inSize);
   void write(const void* inPtr);
   void write(const Str&);
	virtual void write(EndOfLine);
   void writeln() {
      write (endl);
   }

	// Keystroke saver. Handy for out << "Hello there!" << out.EOL();
	static EndOfLine EOL() {
		return endl;
	};

	OutputStream* getStream() const {
		return stream;
	}

	void flush();

 private:
	OutputStream* stream;
	bool owner;
};

}; // Persistance

#endif // _Persistance_TextWriter_h

//
// File        : $RCSfile: $ 
//               $Workfile: TextWriter.h $
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

