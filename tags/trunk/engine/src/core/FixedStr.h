#ifndef RTimage_Data_FixedStr_h
#define RTimage_Data_FixedStr_h

#include "core/Str.h"

//
// required for va_list
#include <stdarg.h>


class FixedStr  {
    //
    // the last 4 characters are resereved
public:
    class VAList   {
    public:
        explicit VAList (va_list inMarker) : marker (inMarker)  {
        }

        va_list get () const {
            return marker;
        }

    private:
        va_list marker;
    };


    FixedStr (char*, Str::Size, bool initialized = false);

	void set (const Str&);
    void set_va (const char*, ...);
    void set_va (VAList, const char*);

    void append (char);
	void append (const Str&);

    void append_va (const char*, ...);
    void append_va (VAList, const char*);

    operator Str () const {
       return getStr ();
    }
    Str getStr () const;
    operator const char* () const {
       return getChars ();
    }
    const char* getChars () const {
       return _buffer;
    }

    inline bool empty () const {
       return length () == 0;
    }
    Str::Size length () const;
    Str::Size capacity () const {
       return _capacity;
    }
    void setLength (Str::Size in) {
       _length = in;
    }

    char getCharAt (Str::Index) const;
    char& getCharAt (Str::Index);
    void setCharAt (Str::Index, char);
    char operator [] (Str::Index i) const {
       return getCharAt (i);
    }
    char& operator [] (Str::Index i) {
       return getCharAt (i);
    }

    FixedStr& operator = (const Str&);

    static const char suffix []; // = "...";
    static void onOverflow (FixedStr&);

private:
    void setEOS ();
    

    Str::Size _length;
    Str::Size _capacity;
    char* _buffer;
    void (* _onOverflow) (FixedStr&);
};

template <int n>
class FixedStrBuffer : public FixedStr  {
public:
    FixedStrBuffer () : FixedStr (nbuffer, n)   {
    }
    FixedStrBuffer (const Str& in) : FixedStr (nbuffer, n) {
       set (in);
    }
    FixedStrBuffer (const char* format, ...) : FixedStr (nbuffer, n) {
       va_list marker;
       va_start (marker, format);
       set_va (VAList (marker), format);
       va_end (marker);
    }
    FixedStrBuffer (VAList marker, const char* format) : FixedStr (nbuffer, n) {
       set_va (VAList (marker), format);
    }
    
private:
    char nbuffer [n];
};

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: FixedStr.h $
// Version     : $Revision: 4 $ 
//               $Author: Aviad $
//               $Date: 16/12/04 6:06 $ 
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

