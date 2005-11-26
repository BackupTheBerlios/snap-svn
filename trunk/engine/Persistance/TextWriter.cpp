#include "TextWriter.h"
#include "OutputStream.h"

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
	_itoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(unsigned short in) {
	char buffer[33];
	_ultoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(int in) {
	char buffer[33];
	_itoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(unsigned int in) {
	char buffer[33];
	_ultoa(in, buffer, 10);
	write(buffer);
}

void TextWriter::write(float in) {
	char buffer[33];
	_gcvt(in, 8, buffer);
	write(buffer);
}

void TextWriter::write(double in) {
	char buffer[33];
	_gcvt(in, 12, buffer);
	write(buffer);
}

void TextWriter::write(const char* in)  {
	if (in == NULL) {
		in = "nil";
	}
	stream->write(in, strlen(in));
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
	size_t printSize= ::sprintf(buffer, "0x%08x", inPtr);
	stream->write(buffer, printSize);
}
