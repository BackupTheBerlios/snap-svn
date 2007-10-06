//
// File        : $RCSfile: $ 
//               $Workfile: FixedStr.cpp $
// Version     : $Revision: 3 $ 
//               $Author: Aviad $
//               $Date: 2/12/04 7:54 $ 
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
   _capacity (inCapacity - 1), // we always end with a null
   _buffer (inBuffer),
   _onOverflow (FixedStr::onOverflow)
{
    debug_mustbe (_buffer);
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
}

void FixedStr::onOverflow(FixedStr& inStr)
{
   int capacity = inStr.capacity();
   debug_mustbe (inStr.length() == capacity);
   if (capacity > 0) {
      char* buffer = const_cast <char*>(inStr.getChars());
      int suffixToCopy = tmin <int> (capacity, sizeof (suffix) - 1);
      memcpy (buffer + capacity - suffixToCopy, suffix, suffixToCopy);
      buffer [capacity] = 0;
   }
}


void FixedStr::set (const Str& in)
{
    if (in.length () <= _capacity) {
        //
        // the _buffer has enough space for the entire string
        _length = in.length ();
        memcpy (_buffer, in.getChars (), _length);
        setEOS ();
    }
    else {
       //
       // not enough place in the _buffer for the entire string
       memcpy (_buffer, in.getChars (), _capacity);
       _length = _capacity;
       _onOverflow(*this);
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
    va_list vamarker;
    marker.get (vamarker);
    int written = VSNPRINT (_buffer, _capacity, format, vamarker);
    if (written == -1)  {
        //
        // not enough place in the _buffer for the entire string
      _length = _capacity;
      _onOverflow(*this);
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
   if (_length < _capacity)  {
      _buffer [_length++] = c;
      setEOS ();
   }
   else    {
      debug_mustbe (_length == _capacity);
      _onOverflow(*this);
   }
}

void FixedStr::append (const Str& in)
{
   debug_mustbe (_length >= 0);
   debug_mustbe (in.length () >= 0);

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
      int toCopy = tmax (_capacity - _length, 0);
      memcpy (_buffer + _length, in.getChars (), toCopy);
      _length += toCopy;
      _onOverflow (*this);
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
   va_list vamarker;
   marker.get (vamarker);
   int written = VSNPRINT(_buffer + _length, _capacity - _length, format, vamarker);
   if (written == -1)  {
      //
      // not enough place in the _buffer for the entire string
      _length = _capacity;
      _onOverflow(*this);
   }
   else    {
      //
      // the _buffer has enough space for the entire string
      _length += written;
      setEOS ();
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

char& FixedStr::getCharAt (Str::Index index) 
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

Str FixedStr::getStr () const
{
    return Str (_buffer, 0, _length);
}


FixedStr& FixedStr::operator = (const Str& in)
{
    set (in);
    return *this;
}

