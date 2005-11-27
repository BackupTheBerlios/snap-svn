#ifndef _SeedSearcher_Persistance_TextTableReport_h
#define _SeedSearcher_Persistance_TextTableReport_h

#include "core/Str.h"
#include "core/FixedStr.h"
#include "core/AutoPtr.h"
#include "core/ImplList.h"
#include "core/STLHelper.h"
#include "persistance/TextWriter.h"


BEGIN_NAMESPACE (Persistance);

class TextTableReport {
    //
    // The purpose of this file is to provide an flexible, reusable mechanism
    // for generating reports (logs, user messages etc).
public:
    class Format;
    class Data;
    class Field;

    enum    {
        maxRecordLength = 16 * 1024,
        maxFieldSeparator = 64,
        firstFieldIndex = 0
    };

    class Data  {
       //
       //
    public:
       Data (Format&);
       ~Data ();

       void reset ();
       void writeInto (StrBuffer& out) const;
       void writeInto (OutputStream&) const;

       //
       // also returns the index of current field
       int nextField () {
          return _current++;
       }
       int currentFieldIndex () {
          return _current;
       }
       FixedStr getField (int index);
       const Format& format () const {
          return _format;
       }

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

    class Format    {
        //
        //
    public:
        Format (const char* separator = "\t");
        ~Format ();

        //
        // 
        void addField (const Str& name, int length, int width, bool useNewline = true);
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

        Str fieldSeparator () const {
           return _fieldSeparator;
        }
        
        //
        //
        Str header () const;

        typedef Vec <Field*> Fields;

    private:
        int _width;
        int _length;
        AutoPtr <Data> _header;
        Fields _fields;
        FixedStrBuffer <maxFieldSeparator> _fieldSeparator;
        mutable FixedStrBuffer <maxRecordLength> _headerData;
    };


    class TextOutput : public TextWriter   {
          //
          //
    public:
       TextOutput (OutputStream*, bool /* owner */= true);
       TextOutput (TextWriter& writer) 
          : TextWriter (writer.getStream (), false), _first (true) {
             writer.flush ();
          }
          ~TextOutput ();

          void writeRecord (const Data&);
          friend TextOutput& operator << (TextOutput& out, const Data& data) {
             out.writeRecord (data);
             return out;
          }
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
   typedef TextOutput Output;
};

END_NAMESPACE (Persistance);

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: TextTableReport.h $
// Version     : $Revision: 8 $ 
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
// and the library authors appliy.
//

