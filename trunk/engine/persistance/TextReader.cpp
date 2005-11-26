#include "TextReader.h"
#include "InputStream.h"

#include "Core/Str.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace Persistance;

TextReader::TextReader(InputStream* inStream, bool inOwner) : 
	stream(inStream), owner(inOwner), bufStart (0), bufEnd (0),
	unreadBufSize (0), readCount (0)
{	
}

TextReader::~TextReader() 
{
	if (owner)
		stream->dispose();
}

void TextReader::unreadByte (Byte in) 
{
	buf [bufEnd++] = in;
	bufEnd %= sizeof (buf);
	++unreadBufSize;
	if (bufEnd == bufStart)
		throwx (Overflow ());

   readCount--;
}

TextReader::Byte TextReader::readByte () 
{
   readCount++;
	if (bufStart != bufEnd) {
		Byte c = buf [bufStart++];
		bufStart %= sizeof (buf);
		--unreadBufSize;
		return c;
	}
	else
		return stream->readByte ();
}

bool TextReader::atEnd () const
{
	if (bufStart != bufEnd)
		return false;
	else
		return stream->atEnd ();
}

void TextReader::read(bool& out) 
{
   skipWhitespace ();
   //
   // TODO: maybe accept other strings as true/false values
   char buffer [8];
   read (buffer, 5);
   buffer [5] = 0;

   if (strcmp (buffer, "true ") == 0)
      out = true;
   else if (strcmp (buffer, "false") == 0)
      out = false;
   else
      throwx (InvalidFormat ());
}

void TextReader::read(char& out) 
{
   out = readByte();
}

void TextReader::read(signed char& out) 
{
   out = readByte();
}

void TextReader::read(unsigned char& out) 
{
	out = readByte();
}

int TextReader::readInt ()
{
    return (int)readLong ();
}

short TextReader::readShort ()
{
    int c;              /* current char */
    short total;         /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
	c = readByte ();
    while ( isspace(c) )
        c = readByte ();

    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
        c = readByte ();    /* skip sign */

    total = 0;

    bool eof = false;
    while (isdigit(c)) {
        total = 10 * total + (c - '0');     /* accumulate digit */
        if (atEnd ())   {
            eof = true;
			break;
        }
        c = readByte ();    /* get next char */
    }
    if (!eof)
        unreadByte (c);

    if (sign == '-')
        return -total;
    else
        return total;   /* return result, negated if necessary */
}

long TextReader::readLong ()
{
    int c;              /* current char */
    long total;         /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
	c = readByte ();
    while ( isspace(c) )
        c = readByte ();

    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
        c = readByte ();    /* skip sign */

    total = 0;

    bool eof = false;
    while (isdigit(c)) {
        total = 10 * total + (c - '0');     /* accumulate digit */
        if (atEnd ())   {
            eof = true;
			break;
        }
        c = readByte ();    /* get next char */
    }
    if (!eof)
        unreadByte (c);

    if (sign == '-')
        return -total;
    else
        return total;   /* return result, negated if necessary */
}

#if 0 // int64 not supported right now

int64_t TextReader::readInt64 ()
{
    int c;              /* current char */
    int64_t total;      /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
	c = readByte ();
    while ( isspace(c) )
        c = readByte ();

    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
        c = readByte ();    /* skip sign */

    total = 0;

    bool eof = false;
    while (isdigit(c)) {
        total = 10 * total + (c - '0');     /* accumulate digit */
        if (atEnd ())   {
            eof = true;
			break;
        }
        c = readByte ();    /* get next char */
    }

    if (!eof)
        unreadByte (c);

    if (sign == '-')
        return -total;
    else
        return total;   /* return result, negated if necessary */
}
#endif // #if 0 

double TextReader::readDouble ()
{
    int c;              /* current char */

	char buf [128];
	char* bufPtr = buf;

    /* skip whitespace */
	c = readByte ();
    while ( isspace(c) )
        c = readByte ();

	if (c == '-' || c == '+') {
		*bufPtr++ = c;
		c = readByte ();
	}

    bool eof = false;
	while (isdigit (c)) {
		*bufPtr++ = c;
        if (atEnd ())   {
            eof = true;
			break;
        }
		c = readByte ();
	}

	if (c == '.') {
		*bufPtr++ = c;
		if (atEnd ())
			goto finish;
		c = readByte ();

		while (isdigit (c)) {
			*bufPtr++ = c;
            if (atEnd ())   {
                eof = true;
				break;
            }
			c = readByte ();
		}
	}

	if (c == 'e' || c == 'E') {
		*bufPtr++ = c;
		c = readByte ();
		if (c == '-' || c == '+') {
			*bufPtr++ = c;
			c = readByte ();
		}
		while (isdigit (c)) {
			*bufPtr++ = c;
            if (atEnd ())   {
                eof = true;
				break;
            }
			c = readByte ();
		}
	}

    if (!eof)
        unreadByte (c);

finish:
	*bufPtr = '\0';
	return atof (buf);
}

void TextReader::read (short& out) 
{
	out = readShort ();
}

void TextReader::read (unsigned short& out) 
{
	out = readShort ();
}

void TextReader::read (int& out) 
{
	out = readInt ();
}

void TextReader::read (unsigned int& out) 
{
	out = readInt ();
}

void TextReader::read (float& out) 
{
	out = (float) readDouble ();
}

void TextReader::read (double& out) 
{
	out = readDouble ();
}

bool TextReader::iseol (Byte c)
{
	return (c == '\r' || c == '\n');
}

void TextReader::read (char* out)  
{
    skipWhitespace ();
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			unreadByte (c);
			break;
		}
		else if (isspace (c))
			break;
		else
			*out++ = c;
	}
	*out = '\0';
}

void TextReader::read (StrBuffer& out)  
{
	out = "";
    skipWhitespace ();
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			unreadByte (c);
			break;
		}
		else if (isspace (c))
			break;
		else
			out += c;
	}
}

void TextReader::read (EndOfLine) 
{
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			if (!atEnd ()) {
				Byte c2 = readByte ();
				if (!iseol (c2) || c == c2)
					unreadByte (c2);
			}
			return;
		}
	}
}

void TextReader::readUntil (StrBuffer& outBuffer, const Str& separator)
{
   outBuffer.set (0);
   while (!atEnd ()) {
      Byte c = readByte ();
      outBuffer.append (c);
      if (outBuffer.endsWith (separator)) {
         //
         // remove the separator from the buffer
         outBuffer.setLength (outBuffer.length () - separator.length ());
         break;
      }
   }
}

void TextReader::readln (char* out)  
{
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			if (!atEnd ()) {
				Byte c2 = readByte ();
				if (!iseol (c2) || c == c2)
					unreadByte (c2);
			}
			break;
		}
		else
			*out++ = c;
	}
	*out = '\0';
}

void TextReader::readln (StrBuffer& out)  
{
	out = "";
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			if (!atEnd ()) {
				Byte c2 = readByte ();
				if (!iseol (c2) || c == c2)
					unreadByte (c2);
			}
			break;
		}
		else
			out += c;
	}
}

void TextReader::read (char* out, size_t inSize) 
{
	debug_mustbe (out);

	while (inSize > 0)
		if (bufStart != bufEnd) {
			Byte c = buf [bufStart++];
			bufStart %= sizeof (buf);
			--unreadBufSize;
			*out++ = c;
			--inSize;
		}
		else {
			stream->read (out, inSize);
         readCount += inSize;
			inSize = 0;
		}
}

bool TextReader::atEol ()
{
    //
    // if no more input is available, it is also considered as eol
    bool result = true;
    if (!atEnd ())  {
        Byte c;
        c = readByte ();
    	result = iseol (c);
        unreadByte (c);
    }

    return result;
}

void TextReader::skipWhitespace ()
{
	while (!atEnd ()) {
		Byte c = readByte ();
		if (iseol (c)) {
			unreadByte (c);
			return;
		}
		else if (!isspace (c)) {
			unreadByte (c);
			return;
		}
	}
}

void TextReader::skip (InputStream::Size in)
{
	while (in > 0)
		if (bufStart != bufEnd) {
			bufStart++;
			bufStart %= sizeof (buf);
			--unreadBufSize;
			--in;
		}
		else {
			stream->skip (in);
         readCount += in;
			in = 0;
		}
}

InputStream::Offset TextReader::getPos ()
{
	return stream->getPos () - unreadBufSize;
}

//
// File        : $RCSfile: $ 
//               $Workfile: TextReader.cpp $
// Version     : $Revision: 10 $ 
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

