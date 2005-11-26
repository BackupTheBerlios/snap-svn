#ifndef _SeedSearcher_Persistance_TextTableReport_h
#define _SeedSearcher_Persistance_TextTableReport_h

#include "core/Str.h"
#include "core/FixedStr.h"
#include "core/AutoPtr.h"
#include "core/ImplList.h"
#include "persistance/TextWriter.h"


BEGIN_NAMESPACE (Persistance);

class TextTableReport {
    //
    // The purpose of this file is to provide an flexible, reuseable mechanism
    // for generating reports (logs, user messages etc).
public:
    class Field;
    class Output;
    class Writer;
    class TextOutput;

    enum    {
        maxFields = 128,
        maxRecordLength = 16 * 1024,
        maxHeaderLength = maxRecordLength + 2,
        maxFieldSepator = 64,
        firstFieldIndex = 0
    };


    class Output    {
        //
        // This class abstracts an output mechanism for logging
    public:
        virtual ~Output ()  {
        }

        //
        // write a formatted record, adding the header if necessary
        virtual void writeRecord (const Str& /* header */, const Str& /* body */)=0;
    };



    class Format    {
        //
        //
    public:
        Format (const char* separator = "\t");
        ~Format ();

        //
        // 
        void addField (const Str& name, int length, int width);
        void addField (const Str& name, int length) {
           addField (name, length, length);
        }
        void addField (const Str& name) {
           addField (name, name.length() + 1);
        }

        //
        //
        int fields () const;
        int length () const;
        int width () const;
        //
        //
        Field* field (int);

        //
        // sets the separator to be a string of spaces
        void spacesBetweenFields (int);
        Str fieldSeparator () const {
           return _fieldSeparator;
        }
        
        //
        //
        Str header () const;

    private:
        int _width;
        int _length;
        int _nfields;
        char _header [maxHeaderLength];
        Field* _fields [maxFields];
        FixedStrBuffer <maxFieldSepator> _fieldSeparator ;
    };


    class Data  {
        //
        //
    public:
        Data (Format&);
        ~Data ();

        void reset ();
        void writeInto (Output&);
        void writeInto (StrBuffer&);

         void nextField () {
           _current++;
        }
        int currentFieldIndex () {
           return _current;
        }
        FixedStr getField (int index);

        void writeField (const Str& /* inFieldData */);
        void writeField (const Str& /* inFieldData */, int /* inFieldIndex */);
        OutputStream* getOutputStream (int /* inFieldIndex */);
        OutputStream* getOutputStream ();

        class Spaces;
        class Iterator;
        class FieldOutput;

    private:
        int _current;
        Format& _format;
        char _buffer [maxRecordLength];
    };
};



class TextTableReport::TextOutput : 
   public TextTableReport::Output, public TextWriter   {
    //
    //
public:
    TextOutput (OutputStream*, bool /* owner */= true);
    TextOutput (TextWriter& writer) 
       : TextWriter (writer.getStream (), false), _first (true) {
          writer.flush ();
      }
    ~TextOutput ();

    //
    // writes the contents of the field into the buffer.
    virtual void writeRecord (const Str&, const Str&);
    void skipHeader () {
       _first = false;
    }
    void noNewlineAfterRecord () {
       _newline = false;
    }

private:
    bool _first;
    bool _newline;
};


END_NAMESPACE (Persistance);

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: TextTableReport.h $
// Version     : $Revision: 5 $ 
//               $Author: Aviad $
//               $Date: 10/12/04 21:17 $ 
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

