#ifndef SeedSearcher_Core_Str_h
#define SeedSearcher_Core_Str_h

#include "Defs.h"
#include <string>

class	StringDefs {
public:
   typedef int Size;
   typedef int Index;
   
   enum {
      badIndex= (Index)-1
   };
   static bool valid(Index index) {
      return index!=badIndex;
   }
   
   class IndexOutOfBounds : public BaseException {};
};


//
// wrapper for const-char-ptr, does not allocate/deallocate memory
class	Str : public StringDefs {
public:
   typedef char Char;
   
   //
   // its not really safe to build an str from a std::string 
   // because it is likely
   // to destroy its sequence, this is why this ctor is explicit
   explicit Str (const std::string& in) 
     : mData ((char*) in.c_str ()), mLength (in.size ()) 
   {
   }
   Str(const char* in= 0);
   Str(const Str&);
   Str(const Str&, Index inStart, Index inEnd= badIndex);
   Str(const char* in, Index inStart, Index inEnd/*= badIndex*/);
   
   Str& operator= (const Str& in);
   Str& operator= (const char* in);	// could be 0
   
   //	void writeExternal(DataOutput& output) const;
   //NOTE// Strictly speaking, this method belongs to DataOutput class. But
   // since Str is not primitive type of C++ we've preferred to do it here
   
   char& getCharRefAt(Index in)   {
      debug_mustbe(in<mLength);
      return mData[in];
   }
   
   char getCharAt(Index in) const {
      debug_mustbe(in<mLength);
      return mData[in];
   }
   char operator[](Index in) const {
      return getCharAt(in);
   }
   Size length() const {
      return mLength;
   }
   bool empty() const {
      return mLength==0;
   }
   void getChars(char* inDest, Size inDestSize) const;
   // Copy my data to 'inDest' up to 'inDestSize' bytes
   // without the trailing '\0'
   
   const char* getChars() const {
      // Return pointer to my data.
      // = NOTE
      // This function neither guarantee to return valid c-style string 
      // (with trailing '\0') nor even that the pointer is not null
      // Use getCString() when you need to convert to c-style string.
      return mData;
   }

   // Copy my data and trailing '\0' to 'inDest' up to 'inDestSize' bytes.
   void getCString(char* inDest, Size inDestSize) const;
   // Copy my data to a std string
   std::string& getCString (std::string& in) const {
     in.replace (in.begin (), in.end (), getChars (), length ());
     debug_mustbe (Str (in).equals (*this));
     return in;
   }
   
   Str substring(Index inStart, Index inEnd) const;
   // Return part of me between the indices 'inStart' and 'inEnd'
   // Both 'inStart' and 'inEnd' have to be valid
   Str substring(Index inStart) const {
      return substring(inStart, mLength);
   }
   
   int compare(const Str& in) const;
   int compareIgnoreCase(const Str& in) const;
   bool equals(const Str& in) const;
   bool equalsIgnoreCase(const Str& in) const;
   friend bool operator==(const Str& a, const Str& b) {
      return a.equals(b);
   }
   friend bool operator!=(const Str& a, const Str& b) {
      return !a.equals(b);
   }
   
   bool startsWith(const Str& in, const bool inIgnoreCase= false) const;
   bool endsWith(const Str& in, const bool inIgnoreCase= false) const;
   Index indexOf(char in, Index inStart= 0) const;
   Index indexOf(const Str& inString, Index inStart= 0) const;
   Index lastIndexOf(char in, Index inStart= 0) const;
   Index lastIndexOf(const Str& inString, Index inStart= 0) const;
   
   Index findOneOf(const Str in, Index inStart= 0) const;
   /*
   friend TextWriter& operator<<(TextWriter& output, const Str& in) {
   in.writeAsText(output);
   return output;
   }
   */
   typedef const char* const_iterator;
   const char* begin () const {
      return mData;
   }
   const char* end () const {
      return mData + mLength;
   }

	Str trimmedSubstring () const;

	Size copy (char* in, Size count, Size _off = 0) const {
		debug_mustbe (_off >= 0);
		if (_off > 0)
			return substring (_off).copy (in, count);
		else {
			this->getCString (in, count);
			return tmin (this->length (), count);
		}
	}
   
protected:
   char* mData;
   Size mLength;
   
   void copyFrom(const Str& in, Index inStart, Size inLength);
   void checkIndex(Index in) const {
      if ((in > mLength) || (in < 0))
         throwx (IndexOutOfBounds());
   }
   
   //	void writeAsText(TextWriter& output) const;
   
   friend class StrBuffer;
};



//
// careful, Str is not polymorphic...
class	StrBuffer : public Str {
public:
   StrBuffer(Size inSize= 0);
   ~StrBuffer();
   StrBuffer(const StrBuffer& in);
   StrBuffer(const Str& in, Index inStart= 0, Index inEnd= badIndex);
   StrBuffer(const char* in);
   StrBuffer(const char* in1, const char* in2, const char* in3= 0, const char* in4= 0);
   StrBuffer(const Str& in1, const Str& in2);
   StrBuffer(const Str& in1, const Str& in2, const Str& in3);
   StrBuffer(const Str& in1, const Str& in2, const Str& in3, const Str& in4);
   
   void set(const Str& in);
   
   StrBuffer& operator=(const Str& in) {
      set(in);
      return *this;
   }
   StrBuffer& operator=(const StrBuffer& in) {
      set(in);
      return *this;
   }
   StrBuffer& operator=(const char* in) {
      set(Str(in));
      return *this;
   }
   
//   void readExternal(DataInput& input);
   
   StrBuffer& append(char in);
   StrBuffer& append(char in, int repetitions);
   StrBuffer& append(char* in, int length) {
      return append (Str (in, length));
   }
   StrBuffer& append(const Str& in);
   StrBuffer& operator+=(const Str& in) {
      return append(in);
   }
   StrBuffer& operator+=(const char* in) {
      return append(Str(in));
   }
   StrBuffer& operator+=(char in) {
      return append(in);
   }
   
   void remove(Index inStart, Index inEnd=badIndex);
   
   void setLength(Size in);
   Size capacity();
   void ensureCapacity(Size in);
   const char* getCString(Index inStart= 0) const;
   operator const char*() const {
      return getCString();
   }

   void getCString(char* inDest, Size inDestSize) const {
      Str::getCString(inDest, inDestSize);
   }
      
   void setCharAt(Index ix, char inChar) {
      ensureCapacity(ix);
      mData[ix] = inChar;
   }
   
   void toLowerCase();
   
   void trimLeft();
   void trimRight();
   void trim();	
   // Remove white space from both ends of 'this'.
   // Like in Java, all chars <= 0x20 are considered whitespace.
   
   char* willWrite(Size inSize);
   // Prepare for writing exactly 'inSize' bytes into mySelf
   // YTD: see if we can do it the safer way
   
   char* release ();
   // gives ownership of the controlled string to the caller, resets to an empty string.
   // if 'shrink' is true, then string buffer is reallocated to the string's length
   
   void acquire (char*);
   void acquire (char*, int inSize);
   void acquire (StrBuffer& in) {
      mLength= in.mLength;
      mCapacity = in.mCapacity;
      mData = in.release ();
   }
   // takes ownership of pointer
   
protected:
   Size mCapacity;
   
   bool reallocate(Size inLength);
   void setEOS();
   
private:
   void doAppend(const char* inString, Size inLength);
   void init4(const Str& s1, const Str& s2, const Str& s3, const Str& s4);
};


inline bool operator < (const Str& a, const Str& b) {
	return (a.compare(b) < 0);
}
inline bool operator > (const Str& a, const Str& b) {
	return (a.compare(b) > 0);
}
inline bool operator <= (const Str& a, const Str& b) {
	return (a.compare(b) <= 0);
}
inline bool operator >= (const Str& a, const Str& b) {
	return (a.compare(b) >= 0);
}

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: Str.h $
// Version     : $Revision: 14 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:14 $ 
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

