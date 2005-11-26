//
// File        : $RCSfile: $ 
//               $Workfile: FixedStr.cpp $
// Version     : $Revision: 1 $ 
//               $Author: Aviad $
//               $Date: 25/08/04 17:56 $ 
// Description :
//	The Core library contains contains basic definitions and classes
// which are useful to any highly-portable applications
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



#include "FixedStr.h"

#include <stdio.h>
#include <string.h>

const char FixedStr::suffix [] = "...";

FixedStr::FixedStr (char* inBuffer, Str::Size inCapacity, bool initialized)
:  _length (0),
   _capacity (inCapacity -1) /* take the terminating NULL into account */,
   _overflow (false),
   _buffer (inBuffer)
{
    debug_mustbe (_buffer);
    debug_mustbe (_capacity > sizeof (suffix));
    if (initialized)    {
        //
        // the string is supposed to be NULL terminated
        _length = strlen (_buffer);
        debug_mustbe (_length <= _capacity);
    }
}

void FixedStr::setEOS() 
{
	debug_mustbe(_length <= _capacity);
	_buffer [_length] = 0;
    _overflow = false;
}

void FixedStr::setTrailingEOS ()
{
    memcpy (_buffer + _capacity - sizeof (suffix), suffix, sizeof (suffix));
    _length = _capacity;
    _overflow = true;
}


void FixedStr::set (const Str& in)
{
    _overflow = false;
    if (_capacity < in.length ()) {
        //
        // not enough place in the _buffer for the entire string
        int toCopy = _capacity - sizeof (suffix);
        memcpy (_buffer, in.getChars (), toCopy);

        setTrailingEOS ();
    }
    else    {
        //
        // the _buffer has enough space for the entire string
        _length = in.length ();
        memcpy (_buffer, in.getChars (), _length);

        setEOS ();
    }
}

void FixedStr::set_va (const char* format, ...)
{
    va_list marker;
    va_start (marker, format);
    set_va (VAList (marker), format);
    va_end (marker);
}

#if (ENV_COMPILER==ENV_MICROSOFT)
#  define VSNPRINT _vsnprintf
#else
#  define VSNPRINT vsnprintf
#endif


void FixedStr::set_va (VAList marker, const char* format)
{
    _overflow = false;
    int written = VSNPRINT (_buffer, _capacity, format, marker.get ());
    if (written == -1)  {
        //
        // not enough place in the _buffer for the entire string
        setTrailingEOS ();
    }
    else    {
        //
        // the _buffer has enough space for the entire string
        _length = written;
        setEOS ();
    }
}

void FixedStr::append (char c)
{
    if (!_overflow)  {
        if (_length < _capacity)  {
            _buffer [_length++] = c;
            setEOS ();
        }
        else    {
            _length = _capacity;
            setTrailingEOS ();
        }
    }
}

void FixedStr::append (const Str& in)
{
    debug_mustbe (_length >= 0);
    debug_mustbe (in.length () >= 0);

    if (!_overflow)  {
        int in_length = in.length ();
        if ((_length + in_length) <= _capacity)    {
            //
            // the _buffer has enough space for the entire string
            memcpy (_buffer + _length, in.getChars (), in_length);
            _length += in_length;
            setEOS ();
        }
        else    {
            //
            // not enough place in the _buffer for the entire string
            int toCopy = _capacity - _length;
            
            debug_mustbe (toCopy > 0);
            memcpy (_buffer + _length, in.getChars (), toCopy);
            setTrailingEOS ();
        }
    }
}

void FixedStr::append_va (const char* format, ...)
{
    va_list marker;
    va_start (marker, format);
    append_va (VAList (marker), format);
    va_end (marker);
}

void FixedStr::append_va (VAList marker, const char* format)
{
    if (!_overflow)  {
        int written = VSNPRINT (_buffer + _length, _capacity - _length, format, marker.get ());
        if (written == -1)  {
            //
            // not enough place in the _buffer for the entire string
            setTrailingEOS ();
        }
        else    {
            //
            // the _buffer has enough space for the entire string
            _length += written;
            setEOS ();
        }
    }
}

Str::Size FixedStr::length () const
{
    return _length;
}

char FixedStr::getCharAt (Str::Index index) const
{
    debug_mustbe (index >=0);
    debug_mustbe (index <= _capacity);

    return _buffer [index];
}

void FixedStr::setCharAt (Str::Index index, char c)
{
    debug_mustbe (index >=0);
    debug_mustbe (index <= _capacity);

    _buffer [index] = c;
}

FixedStr::operator Str () const
{
    return Str (_buffer, 0, _length);
}

FixedStr::operator const char* () const
{
    return _buffer;
}

FixedStr& FixedStr::operator = (const Str& in)
{
    set (in);
    return *this;
}

