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

    operator Str () const;
    operator const char* () const;

    Str::Size length () const;
    
    char getCharAt (Str::Index) const;
    void setCharAt (Str::Index, char);

    FixedStr& operator = (const Str&);

    static const char suffix []; // = "...";

private:
    void setEOS ();
    void setTrailingEOS ();

    Str::Size _length;
    Str::Size _capacity;
    bool _overflow;
    char* _buffer;
};

template <int n>
class FixedStrBuffer : public FixedStr  {
public:
    FixedStrBuffer () : FixedStr (nbuffer, n)   {
    }
    
private:
    char nbuffer [n];
};

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: FixedStr.h $
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

