//
// File        : $RCSfile: $ 
//               $Workfile: TextTableReport.cpp $
// Version     : $Revision: 6 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:33 $ 
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
// and the library authors apply.
//



#include "TextTableReport.h"
#include "persistance/StrOutputStream.h"
#include "persistance/OutputStream.h"
#include <memory.h>

using namespace Persistance;

//
//
class	StrTokenizer {
public:
   StrTokenizer(const Str& inString, const Str& inDelimeters, bool inReturnTokens= false);
   StrTokenizer(const Str& inString, bool inReturnTokens= false);
   // Construct, using 'inString' and the default delimeter set
   // (newline, tab, space)
   StrTokenizer();

   void setString(const Str& inString);
   // Set the string to parse. Helps to reuse StrSokenizer for a set of strings
   void setDelimeters(const Str& inDelimeters);
   void setReturnTokens(bool in);

   bool atEnd() const {
      return ptr >= end;
   }
   void next();
   Str get() const;
   Str getRest() const;
   bool isDelimeter() const {
      return atEnd() ? true : isDelimeter(*ptr);
   }

   static char defaultDelimeters []; // = " \n\t\r";

private:
   typedef const char* Ptr;
   Ptr ptr, end, tokenEnd;
   StrBuffer delimeters;
   bool returnTokens;

   void setup();
   void findTokenEnd();
   void doSetString(const Str& inString);

   bool isDelimeter(char in) const {
      return delimeters.indexOf(in)!=Str::badIndex;
   }
};

struct StrUtils {
   static Str trim (const Str&);
   static Str trimLeft (const Str&);
   static Str trimRight (const Str&);
   char* trimendl (char* s);
};




//
// TextTableReport::Field interface
//

class TextTableReport::Field   {
    //
    //
public:
    Field (const Str& name, int length, int width, int offset, bool useNewline);
    ~Field ();

    //
    // returns the maximum width in chars of this field
    int width () const;

    //
    // returns the maximum length in chars of this field
    int length () const;

    //
    // returns the offset in chars from the beginning of the format data
    int offset () const;

    //
    // returns the name of the field
    const Str& name () const;

	 //
	 // if returns true, than the user wants to use newlines
	 // to maintain alignment of fields (default)
	 // if returns false, than fields should lose alignment
	 // when the data is too long
	 bool useNewlineToMaintainAlignment () const {
		 return _useNewline;
	 }

private:
	bool _useNewline;
    int _width;
    int _length;
    int _offset;
    StrBuffer _name;
};





//
// TextTableReport::Data::Iterator interface
//

class TextTableReport::Data::Iterator   {
public:
    Iterator ();
    ~Iterator ();

    void set (const Str& data, int width);

    int width () const ;
    int unusedWidth () const;

    Str get () const;
    bool atEnd () const; 
    void next ();

private:
    Str _line;
    Str::Index _offset;
    StrTokenizer _tokenizer;
    int _width;
};


//
// TextTableReport::Data::Spaces interface
//

class TextTableReport::Data::Spaces    {
public:
    Spaces ()    {
        memset (_buffer, ' ', sizeof (_buffer));
    }

    operator const char * () const {
        return _buffer;
    }

private:
    char _buffer [TextTableReport::maxRecordLength];
};



static const Str newline = "\r\n";
static const TextTableReport::Data::Spaces spaces;


//
// TextTableReport::Data::Iterator implementation
//

static Str::Index findLastOneOf (const Str& inString, const Str& inChars)    
{
    Str::Size length = inChars.length ();
    const char* data = inChars.getChars ();

    Str::Index index;
    Str::Index last = Str::badIndex;
    for (Str::Index i=0 ; i<length ; i++)    {
        index = inString.lastIndexOf (data [i]);
        last = (index > last)? index : last;
    }

    return last;
}

static Str::Index computeOffset (const Str& inLine, int inWidth)
{
    Str::Index offset = inLine.length ();
    if (offset > inWidth) {
        offset = inWidth;

        //
        // look for the last space or tab, so we can cut the string there
        Str::Index index = findLastOneOf (inLine.substring (0, offset), " \t");
        if (index != Str::badIndex) {
            //
            // found a place to cut the line, without breaking any words
            offset = index;
        }
    }

    return offset;
}



TextTableReport::Data::Iterator::Iterator ()
:   _offset (0),
    _width (0)
{
    _tokenizer.setDelimeters (newline);
}

TextTableReport::Data::Iterator::~Iterator ()
{
}

void TextTableReport::Data::Iterator::set (const Str& inValue, 
                                               int inWidth)
{
    _tokenizer.setString (inValue);
    _width = inWidth;

    if (!inValue.empty ())  {
        _line = _tokenizer.get ();
                _tokenizer.next ();

        _offset = computeOffset (_line, _width);
    }
}

int TextTableReport::Data::Iterator::width () const
{
    return _width;
}

int TextTableReport::Data::Iterator::unusedWidth () const
{
    return _width - _offset;
}


Str TextTableReport::Data::Iterator::get () const
{
    debug_mustbe (!atEnd ());
    debug_mustbe (!_line.empty ());
    debug_mustbe (_offset > 0);

    return _line.substring (0, _offset);
}







void TextTableReport::Data::Iterator::next ()
{
    debug_mustbe (!atEnd ());
    if (_line.length () > _offset)  {
        //
        // there is still input in this line
        _line = StrUtils::trim (_line.substring (_offset));
        _offset = computeOffset (_line, _width);
    }
    else    {
        //
        // have to get a new line from the tokenizer
        if (!_tokenizer.atEnd ())   {
            _line = _tokenizer.get ();
                    _tokenizer.next ();
            _offset = computeOffset (_line, _width);
        }
        else    {
            //
            // no more input
            _line = 0;
        }
    }
}



bool TextTableReport::Data::Iterator::atEnd () const
{
    return _line.empty ();
}








//
// TextTableReport::Field
//

TextTableReport::Field::Field (const Str& inName, 
                            int inLength, 
                            int inWidth,
                            int inOffset,
									 bool useNewline)
:  _useNewline (useNewline),
	_width (inWidth),
   _length (inLength),
    _offset (inOffset),
   _name (inName)

{
    debug_mustbe (_length > 0);
    debug_mustbe (_length >= _width);
    debug_mustbe (_length < maxRecordLength);
    debug_mustbe (_offset >=0);
}

TextTableReport::Field::~Field ()
{
}

const Str& TextTableReport::Field::name () const
{
    return _name;
}

//
// returns the maximum width in chars of this field
int TextTableReport::Field::width () const
{
    return _width;
}

//
// returns the maximum length in chars of this field
int TextTableReport::Field::length () const
{
    return _length;
}

int TextTableReport::Field::offset () const
{
    return _offset;
}


//
// TextTableReport::Format
//


TextTableReport::Format::Format (const char* separator) 
:  _width (0),
   _length (0)
{
    _fieldSeparator.set (separator);
   _header = new Data (*this);
}

TextTableReport::Format::~Format ()
{
   int s = _fields.size ();
   for (int i=0 ; i<s ; ++i)
      delete _fields [i];
}


void TextTableReport::Format::addField (const Str& fieldName, 
													 int fieldLength, 
													 int fieldWidth, 
													 bool useNewline)
{
    debug_mustbe (fieldLength > 0);
    debug_mustbe (fieldLength >= fieldWidth);
    mustbe (_length + fieldLength < maxRecordLength);

    //
    // all fields except the first one also incur an additional
    // width and length caused by the separator
    if (_fields.size () > 0) {
       _width += _fieldSeparator.length();
    }
    _width += fieldWidth;

    //
    // create a field instance
    _fields.push_back (
       new Field (fieldName, 
                  fieldLength,
                  fieldWidth,
                  _length,
						useNewline)
    );

    //
    // update length
    _length += fieldLength;

    //
    // update the header
    _header->writeField (fieldName, _header->nextField());
    _headerData.setLength(0);
}


Str TextTableReport::Format::header () const   
{
   if (_headerData.empty ()) {
      Persistance::FixedBufferOutputStream outputStream (
         const_cast<char*> (_headerData.getChars()), 
         _headerData.capacity ()
      );

      _header->writeInto(outputStream);
      outputStream.flush ();
      _headerData.setLength(outputStream.bytesWritten ());
   }

    return _headerData;
}



int TextTableReport::Format::fields () const
{
    return _fields.size ();
}

int TextTableReport::Format::length () const
{
    return _length;
}

int TextTableReport::Format::width () const
{
    return _width;
}

TextTableReport::Field* TextTableReport::Format::field (int index)
{
    debug_mustbe (index >= 0);
    return _fields [index];
}




//
// TextTableReport::Data
//

TextTableReport::Data::Data (Format& inFormat)
:   _current (0), _format (inFormat)
{
    int length = _format.length ();

    //
    // initialize buffer
    memset (_buffer, ' ', length);
    _buffer [length] = '\0';
}



TextTableReport::Data::~Data ()
{
}


void TextTableReport::Data::reset ()
{
    _current = 0;
}

class TextTableReport::Data::FieldOutput : public OutputStream  {
public:
    FieldOutput (char* inBuffer, int inCapacity): host (inBuffer, inCapacity)    {
	}
    ~FieldOutput ()  {
    }

protected:
	FixedStr host;
	char buffer [1024];

	virtual void nextBuffer()	{
      host.append (Str (buffer, 0, bytesInBuffer ()));
      setupBuffer (IODefs::Ptr (buffer), sizeof (buffer));
	}
	virtual bool hasMoreBuffers () const	{
		return true;
	}
};

static void getFieldBuffer (TextTableReport::Format& inFormat, 
                            char* inBuffer, int inFieldIndex    , 
                            char*& outBuffer, int& outLength    )
{
    int offset;
    int length;
    TextTableReport::Field* field;

    //
    // get the field's format    
    field = inFormat.field (inFieldIndex);
    offset = field->offset ();
    length = field->length ();

    outBuffer = inBuffer + offset;
    outLength = length;
}

OutputStream* TextTableReport::Data::getOutputStream (int inFieldIndex)
{
    int length;
    char* fieldBuffer;
    getFieldBuffer (_format, _buffer, inFieldIndex, fieldBuffer, length);
    return new FieldOutput (fieldBuffer, length);
}

OutputStream* TextTableReport::Data::getOutputStream ()
{
    return getOutputStream (_current++);
}

void TextTableReport::Data::writeField (const Str& data)
{
    writeField (data, _current++);
}

void TextTableReport::Data::writeField (const Str& data, int index)
{
    //
    // write the field body
    getField (index) = data;
}

FixedStr TextTableReport::Data::getField (int index) 
{
   int length;
   char* fieldBuffer;
   getFieldBuffer (_format, _buffer, index, fieldBuffer, length);

   //
   // create buffers for the field's length
   return FixedStr (fieldBuffer, length);
}

void TextTableReport::Data::writeInto (StrBuffer& out) const{
   TStrOutputStream <StrBuffer> outputStream (out);
   writeInto (outputStream);
}

static void append (Persistance::OutputStream& stream, const Str& inStr)
{
   stream.write(inStr.getChars(), inStr.length ());
}

//
// returns true if more input is available
static bool writeLineInto (OutputStream& outputBuffer,
                           TextTableReport::Data::Iterator iterators [],
                           int iteratorCount,
                           const Str& fieldSeparator)
{
    bool hasMore = false;
    for (int i=0 ; i<iteratorCount ; i++)    {
        TextTableReport::Data::Iterator& iterator = iterators [i];
        if (!iterator.atEnd ())    {
            //
            // write the value to the outputBuffer
            Str value = iterator.get ();
            append (outputBuffer, value);

            //
            // if this is not the last field
            if (i + 1 < iteratorCount)  {
                //
                // append spaces
                int unusedWidth = iterator.unusedWidth ();
                append (outputBuffer, Str (spaces, 0, unusedWidth));
            }

            //
            // advance iterator, 
            // if theres more input in this iterator, we're not done
            iterator.next ();
            if (!iterator.atEnd ())
                hasMore = true;
        }
        else    {
            //
            // there's no more input in this field, just append spaces
           append (outputBuffer, Str (spaces, 0, iterator.width ()));
        }

        //
        // insert the separator between fields
        append (outputBuffer, fieldSeparator);
    }

    return hasMore;
}

void TextTableReport::Data::writeInto (OutputStream& outputBuffer) const
{
    int width;
    int offset;
	 int length;
    Field* field = NULL;
    ArrayAutoPtr <Iterator> pIterators = new Iterator [_format.fields()];
    Iterator* iterators = pIterators.get ();

    //
    // set all the iterators
    int fields = _format.fields ();
    for (int i=0 ; i<fields ; i++)  {
        //
        // get the field's format
        field = _format.field (i);
        offset = field->offset ();
        width = field->width ();
		length = field->length ();

		//
		// copy the field, do not copy more chars than is defined by field-length
		Str temp_str (_buffer + offset);
		Str field_str (temp_str, 0, tmin <int> (temp_str.length (), length));
		iterators [i].set (field_str, width);
    }

    //
    // format the buffer, line-by-line to another buffer
    bool hasMore = writeLineInto (outputBuffer, iterators, fields, _format.fieldSeparator ());
    while (hasMore) {
		 if (field->useNewlineToMaintainAlignment ()) {
			//
			// add a newline to terminate the line
			append (outputBuffer, newline);
		}

		//
		// write the line into the buffer
		hasMore = writeLineInto (outputBuffer, iterators, fields, _format.fieldSeparator ());
    }
}




//
// TextTableReport::TextOutput
//

TextTableReport::TextOutput::TextOutput (OutputStream* inStream, bool inOwner)
:   Persistance::TextWriter (inStream, inOwner),
    _first (true), _newline (true)
{
}

TextTableReport::TextOutput::~TextOutput ()
{
}

//
// writes the contents of the field into the buffer.
void TextTableReport::TextOutput::writeRecord (const Data& data)
{
    if (_first) {
        _first = false;
        this->write (data.format ().header());
        writeln ();
    }

    data.writeInto(*getStream());
    if (this->_newline) {
       writeln ();
    }
}




//
// StrTokenizer
//

char StrTokenizer::defaultDelimeters[]= " \n\t\r";

StrTokenizer::StrTokenizer(const Str& inString, const Str& inDelimeters, bool inReturnTokens) :
returnTokens(inReturnTokens) {
   doSetString(inString);
   delimeters= inDelimeters;
   setup();
}

StrTokenizer::StrTokenizer(const Str& inString, bool inReturnTokens) : 
returnTokens(inReturnTokens) {
   doSetString(inString);
   delimeters= defaultDelimeters;
   setup();
}

StrTokenizer::StrTokenizer() : ptr(0), end(0), returnTokens(false) {
   delimeters= defaultDelimeters;
   setup();
}

void StrTokenizer::setString(const Str& inString) {
   doSetString(inString);
   setup();
}

void StrTokenizer::setDelimeters(const Str& inDelimeters) {
   delimeters= inDelimeters;
   setup();
}

void StrTokenizer::setReturnTokens(bool in) {
   returnTokens= in;
}

void StrTokenizer::next() {
   if (returnTokens && isDelimeter(*ptr))
      ptr= tmin(ptr + 1, end);
   else
      ptr= tokenEnd;
   setup();
}

Str StrTokenizer::get() const {
   debug_mustbe(!atEnd());
   return Str(ptr, 0, tokenEnd - ptr);
}

Str StrTokenizer::getRest() const {
   debug_mustbe(tokenEnd<=end);
   return Str(tokenEnd, 0, end - tokenEnd);
}

void StrTokenizer::setup() {
   if (!atEnd()) {
      if (returnTokens) {
         if (isDelimeter(*ptr))
            tokenEnd= tmin(ptr + 1, end);
         else
            findTokenEnd();
      } else {
         for(; ptr < end && isDelimeter(*ptr); ptr++)
            ;
         findTokenEnd();
      }
   }
}

void StrTokenizer::findTokenEnd() {
   for(tokenEnd= ptr; tokenEnd < end && !isDelimeter(*tokenEnd); tokenEnd++)
      ;
}

void StrTokenizer::doSetString(const Str& inString) {
   ptr= inString.getChars();
   end= ptr + inString.length();
}



//
// StrUtils
//

Str StrUtils::trim (const Str& in)
{
   return trimRight (trimLeft (in));
}

Str StrUtils::trimLeft (const Str& in)
{
   int i, length = in.length ();
   const char* p = in.getChars ();

   for(i = 0; i < length ; p++, i++) {
      if (*p > 0x20)
         break;
   }

   return Str (in, i, length);
}

Str StrUtils::trimRight (const Str& in)
{
   int i, length = in.length ();
   const char* p = in.getChars () + length - 1;

   for(i = length; i > 0 ; p--, i--) {
      if (*p > 0x20)
         break;
   }

   return Str (in, 0, i);
}

char* StrUtils::trimendl (char* s)
{
   if (s) {
      int n = strlen (s);

      if (n > 0 && s [n-1] == '\n')
         s [n-1] = '\0';
   }

   return s;
}

