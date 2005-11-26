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









