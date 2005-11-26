#include "TextWriter.h"
#include "OutputStream.h"
#include "core/Str.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace Persistance;

class	Environment {
public:
	static const char* endOfLine();
	static size_t endOfLineLength();
};


#if (ENV_COMPILER==ENV_MICROSOFT)
   static const char EOL[]= { 0x0D, 0x0A, 0 };

#elif (ENV_COMPILER==ENV_GCC)
   static const char EOL[]= { 0x0A, 0 };

#endif

const char* Environment::endOfLine() {
	return EOL;
}

size_t Environment::endOfLineLength() {
	return sizeof (EOL) - 1;
}




TextWriter::TextWriter(OutputStream* inStream, bool inOwner) : 
	stream(inStream), owner(inOwner) {
}

TextWriter::~TextWriter() {
    stream->flush ();
    if (owner)
		stream->dispose();
}

void TextWriter::flush() {
	stream->flush();
}

void TextWriter::write(bool in) {
   stream->write(in? "true " : "false", 5);
}

void TextWriter::write(char in) {
	stream->write(OutputStream::Byte(in));
}

void TextWriter::write(unsigned char in) {
	stream->write(OutputStream::Byte(in));
}


void TextWriter::write(short in) {
	char buffer[33];
	sprintf (buffer, "%d", (int) in);
	//	_itoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(unsigned short in) {
	char buffer[33];
	sprintf (buffer, "%d", (int) in);
	//	_ultoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(int in) {
	char buffer[33];
	sprintf (buffer, "%d", in);
	  //	_itoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(unsigned int in) {
	char buffer[33];
	sprintf (buffer, "%u", in);
	  //	_ultoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(float in) {
	char buffer[128];
	  sprintf (buffer, "%.8f",(double) in);
	  //_gcvt(in, 8, buffer);
	write(buffer);
}

void TextWriter::write(double in) {
	char buffer[128];
	  sprintf (buffer, "%.12g",(double) in);
	  //	_gcvt(in, 12, buffer);
	write(buffer);
}

void TextWriter::write(const char* in)  {
	if (in == NULL) {
		in = "nil";
	}
	stream->write(in, strlen(in));
}

void TextWriter::write(const Str& in)  
{
   stream->write(in.getChars (), in.length ());
}

void TextWriter::write(EndOfLine) {
	stream->write(Environment::endOfLine(), Environment::endOfLineLength());
}

void TextWriter::write(const char* in, size_t inSize) {
	debug_mustbe(in);
	stream->write(in, inSize);
}

void TextWriter::write(const void* inPtr) {
  char buffer[16];
  unsigned int ptr_val = (unsigned int) inPtr;
  size_t printSize= ::sprintf(buffer, "0x%08x", ptr_val);
  stream->write(buffer, printSize);
}

//
// File        : $RCSfile: $ 
//               $Workfile: TextWriter.cpp $
// Version     : $Revision: 10 $ 
//               $Author: Aviad $
//               $Date: 27/08/04 2:09 $ 
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

