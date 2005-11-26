#include "Str.h"
/*
#include "IO/DataInput.h"
#include "IO/DataOutput.h"
#include "IO/TextWriter.h"
#include "Util/MinMax.h"
#include "Util/c_extras.h"
#include "Util/MinMax.h"
*/
#include <string.h>
#include <ctype.h>
#include <limits.h>

#if ENV_COMPILER & ENV_MICROSOFT
#   define ENV_STRNCMP ::_strnicmp
#elif ENV_COMPILER & ENV_GCC
#   define ENV_STRNCMP ::strncasecmp
#endif

static inline Str::Size strLength(const char* in) {
	return in ? ::strlen(in) : 0;
}

static inline char* unconst(const char* in) {
	return const_cast<char*>(in);
}

Str::Str(const char* in) : mData(unconst(in)), mLength(strLength(in)) {
}

Str::Str(const Str& in) : mData(in.mData), mLength(in.mLength) {
}

Str::Str(const Str& in, Index inStart, Index inEnd)
{ 
	mData = in.mData+inStart;
   int length = tmin(Index(in.length()), inEnd) - inStart;
   mLength = (length>0)? length : 0;
   
	debug_mustbe(mData + mLength <= in.mData + in.mLength);
}

Str::Str(const char* in, Index inStart, Index inEnd) : mData(unconst(in) + inStart) {
	if (inEnd==badIndex)
		inEnd= ::strlen(in);
	debug_mustbe(inStart<=inEnd);
	mLength= inEnd - inStart;
}

Str& Str::operator= (const Str& in) {
	mData= in.mData;
	mLength= in.mLength;
	return *this;
}

Str& Str::operator=(const char* in) {
	mData= unconst(in);
	mLength= strLength(in);
	return *this;
}
/*
void Str::writeExternal(DataOutput& output) const {
	mustbe(length() < SHRT_MAX);
	output<<short(length());
	output.write(mData, length());
}
*/

void Str::getChars(char* inDest, Size inDestSize) const {
	size_t lengthToWrite= tmin(inDestSize, mLength);
	if (lengthToWrite > 0)
		memcpy(inDest, mData, lengthToWrite);
}

void Str::getCString(char* inDest, Size inDestSize) const {
	debug_mustbe(inDest && inDestSize > 0);
	size_t lengthToWrite= tmin(inDestSize-1, mLength);
	if (lengthToWrite > 0)
		memcpy(inDest, mData, lengthToWrite);
	inDest[lengthToWrite]= 0;
}

Str Str::substring(Index inStart, Index inEnd) const {
	checkIndex(inStart);
	checkIndex(inEnd);
	if (inStart==inEnd)
		return Str(0);
	else {
		debug_mustbe(inStart < inEnd);
		return Str(*this, inStart, inEnd);
	}
}

int Str::compare(const Str& in) const
{
	int res = 0;
	int len = tmin(mLength, in.mLength);
	if (len > 0) {
		res = memcmp(mData, in.mData, len);
	}
	if (res == 0) {
		res = (int)mLength - (int)in.mLength;
	}
	return res;
}

int Str::compareIgnoreCase(const Str& in) const
{
	int res = 0;
	int len = tmin(mLength, in.mLength);
	if (len > 0) {
		res = ENV_STRNCMP(mData, in.mData, len);
	}
	if (res == 0) {
		res = (int)mLength - (int)in.mLength;
	}
	return res;
}

bool Str::equals(const Str& in) const {
	if (mLength!=in.mLength)
		return false;
	else if (mLength==0)
		return true;
	else
		return memcmp(mData, in.mData, mLength)==0;
}

bool Str::equalsIgnoreCase(const Str& in) const {
	if (mLength!=in.mLength)
		return false;
	else if (mLength==0)
		return true;
	else
		return ENV_STRNCMP(mData, in.mData, mLength)==0;
}

Str::Index Str::indexOf(char inChar, Index inStart) const {
	checkIndex(inStart);
	if (mLength > 0) {
		char* found= (char*)memchr(mData + inStart, inChar, mLength - inStart);
		if (found)
			return found - mData;
	}
	return badIndex;
}

Str::Index Str::indexOf(const Str& inString, Index inStart) const {
	checkIndex(inStart);

	int stringLen = inString.length();
	int checkSize = mLength-inStart-stringLen+1;
	if (stringLen > 0 && checkSize > 0) {
		char*  checkData = mData+inStart;
		while (checkSize > 0) {
			char* found = (char*)memchr(checkData, inString[0], checkSize);
			if (found) {
				if (memcmp(found, inString.mData, stringLen)==0) {
					return found - mData;
				}

				found++;

				checkSize -= found-checkData;
				checkData = found;
			} else {
				break;
			}
		}
	}
	return badIndex;
}

Str::Index Str::lastIndexOf(char in, Index inStart) const {
	checkIndex(inStart);
	for(Index i= mLength - 1; i>=inStart; i--) {
		if (mData[i]==in)
			return i;
	}
	return badIndex;
}

Str::Index Str::lastIndexOf(const Str& in, Index inStart) const {
	checkIndex(inStart);
	if (in.length() > (length() - inStart))
		return badIndex;		// No way to match
	Char firstLook= in[in.length() - 1];
	for(Index i= mLength - 1; i>=inStart; i--) {
		if (mData[i]==firstLook) {
			Index startAt= i - in.length() + 1;
			if (startAt >= 0 && substring(startAt, i + 1).equals(in))
				return startAt;
			else if (startAt < 0)
				break;
		}
	}
	return badIndex;
}

Str::Index Str::findOneOf(const Str in, Index inStart) const {
	checkIndex(inStart);
	for (Index i= inStart; i < mLength; i++) {
		if (in.indexOf(mData[i]) != badIndex)
			return i;
	}
	return badIndex;
}

bool Str::startsWith(const Str& in, const bool inIgnoreCase) const {
	if (mLength < in.length())
		return false;
	if (inIgnoreCase)
		return ENV_STRNCMP(in.getChars(), mData, in.length())==0;
	else
		return memcmp(in.getChars(), mData, in.length())==0;
}

bool Str::endsWith(const Str& in, const bool inIgnoreCase) const {
	if (in.length() > mLength)
		return false;
	if (inIgnoreCase)
		return ENV_STRNCMP(&mData[mLength - in.length()], in.getChars(), in.length())==0;
	else
		return memcmp(&mData[mLength - in.length()], in.getChars(), in.length())==0;
}

//Shame// Intended for use by its subclass, StrBuffer. See the note 2) at the end.

void Str::copyFrom(const Str& in, Index inStart, Size inLength) {
	memcpy(mData, in.mData + inStart, inLength);
}
/*
void Str::writeAsText(TextWriter& output) const {
	output.write('"');
	if (mLength > 0)
		output.write(mData, mLength);
	output.write('"');
}
*/

StrBuffer::StrBuffer(Size inSize) : Str(), mCapacity(0) {
	if (inSize)
		reallocate(inSize);
}

StrBuffer::~StrBuffer() {
	delete [] mData;
}

StrBuffer::StrBuffer(const StrBuffer& in) : Str(), mCapacity(0) {
	mLength= in.length();
	if (mLength > 0) {
		reallocate(mLength);
		memcpy(mData, in.mData, mLength);
		setEOS();
	}
}

StrBuffer::StrBuffer(const Str& in, Index inStart, Index inEnd) : Str(), mCapacity(0) {
	if (inStart > in.length())
		throwx (IndexOutOfBounds());
	if (inEnd==badIndex)
		inEnd= in.length();
	else {
		if (inEnd > in.length())
			throwx (IndexOutOfBounds());
	}
	mLength= inEnd - inStart;
	if (mLength > 0) {
		reallocate(mLength);
		copyFrom(in, inStart, mLength);
		setEOS();
	}
}

StrBuffer::StrBuffer(const char* in) : Str(), mCapacity(0) {
	mLength= strLength(in);
	if (mLength > 0) {
		reallocate(mLength);
		memcpy(mData, in, mLength);
		setEOS();
	}
}

StrBuffer::StrBuffer(const char* in1, const char* in2, const char* in3, const char* in4) :
	Str(), mCapacity(0) {
	init4(Str(in1), Str(in2), Str(in3), Str(in4));
}

StrBuffer::StrBuffer(const Str& in1, const Str& in2) :
	Str(), mCapacity(0) {
	init4(Str(in1), Str(in2), Str(0), Str(0));
}

StrBuffer::StrBuffer(const Str& in1, const Str& in2, const Str& in3) :
	Str(), mCapacity(0) {
	init4(Str(in1), Str(in2), Str(in3), Str(0));
}

StrBuffer::StrBuffer(const Str& in1, const Str& in2, const Str& in3, const Str& in4) :
	Str(), mCapacity(0) {
	init4(Str(in1), Str(in2), Str(in3), Str(in4));
}

void StrBuffer::init4(const Str& s1, const Str& s2, const Str& s3, const Str& s4) {
	mLength= s1.length() + s2.length() + s3.length() + s4.length();
	if (mLength > 0) {
		reallocate(mLength);
		char* p= mData;
		if (s1.length()) {
			memcpy(p, s1.getChars(), s1.length());
			p+=s1.length();
		}
		if (s2.length()) {
			memcpy(p, s2.getChars(), s2.length());
			p+=s2.length();
		}
		if (s3.length()) {
			memcpy(p, s3.getChars(), s3.length());
			p+=s3.length();
		}
		if (s4.length()) {
			memcpy(p, s4.getChars(), s4.length());
			p+=s4.length();
		}
		setEOS();
	}
}

void StrBuffer::set(const Str& in) {
	if (in.length() > 0) {
		char* save= mData;
		if (reallocate(in.length()))
			delete [] save;
		mLength= in.length();
		copyFrom(in, 0, mLength);
		setEOS();
	} else
		mLength= 0;
}
/*
void StrBuffer::readExternal(DataInput& input) {
	short readLength= input.readShort();
	ensureCapacity(readLength);
	mLength= readLength;
	input.read(mData, mLength);
	setEOS();
}
*/

inline void StrBuffer::doAppend(const char* inString, Size inLength) {
		char* save= mData;
		if (reallocate(mLength + inLength)) {
			if (mLength > 0)
				memcpy(mData, save, mLength);
			delete [] save;
		}
		memcpy(mData + mLength, inString, inLength);
		mLength+=inLength;
		setEOS();
}

StrBuffer& StrBuffer::append(const Str& in) {
	if (in.length() > 0) {
		doAppend(in.mData, in.length());
	}
	return *this;
}

StrBuffer& StrBuffer::append(char in, int repetitions) {
   if (repetitions > 0) {
	   char buffer [1024];
      memset (buffer, in, tmin <size_t> (sizeof (buffer), repetitions));
      for (; repetitions > 0 ; repetitions -= sizeof(buffer)) {
         //
         //
         int current = tmin <size_t> (sizeof (buffer), repetitions);
         doAppend (buffer, current);
      }
   }

   return *this;
}

StrBuffer& StrBuffer::append(char in) {
   doAppend(&in, 1);
	return *this;
}

void StrBuffer::remove(Index inStart, Index inEnd)
{
	if (inEnd==badIndex || inEnd > mLength)
		inEnd = mLength;

	if (inStart >= inEnd)
		return;


	if (inEnd < mLength) {
		memmove(mData+inStart, mData+inEnd, mLength-inEnd);			
	}
	mLength -= inEnd-inStart;
}

void StrBuffer::setLength(Size in) {
	checkIndex(in);
	mLength= in;
	if (mLength > 0)
		setEOS();
}

void StrBuffer::ensureCapacity(Size inLength) {
	char* save= mData;
	if (reallocate(inLength)) {
		if (mLength > 0) {
			debug_mustbe(save);
			memcpy(mData, save, mLength);
		}
		setEOS();
		delete [] save;
	}
}

bool StrBuffer::reallocate(Size inLength) {
	inLength++;
	if (mCapacity < inLength) {				
		mCapacity= tmax((mCapacity + 1)*2, inLength);
		mData= new char[mCapacity];
		return true;
	} else
		return false;
}

void StrBuffer::setEOS() {
	debug_mustbe(mLength < mCapacity);
	mData[mLength]= 0;
}

static char emptyCString[]="";

const char* StrBuffer::getCString(Index inStart) const {
	checkIndex(inStart);
	return inStart < mLength ? mData + inStart : emptyCString;
}

void StrBuffer::toLowerCase() {
//	if (mLength>0)
//		_strlwr(mData);
	if (mLength > 0) {
		for (char* ptr = mData, *end = mData+mLength; ptr < end; ptr++) {
			*ptr = tolower(*ptr);
		}
	}
}

void StrBuffer::trimLeft() {
	int newBeg;
	for(newBeg= 0; newBeg < mLength; newBeg++) {
		if (mData[newBeg] > 0x20)
			break;
	}
	if (newBeg > 0) {
		int newLength= mLength - newBeg;
		memmove(mData, mData+newBeg, newLength);
		setLength(newLength);
	}
}

void StrBuffer::trimRight() {
	int newEnd;
	for(newEnd= mLength-1; newEnd >= 0; newEnd--) {
		if (mData[newEnd] > 0x20)
			break;
	}
	setLength(newEnd + 1);
}

void StrBuffer::trim() {
	int newBeg, newEnd;
	for(newBeg= 0; newBeg < mLength; newBeg++) {
		if (mData[newBeg] > 0x20)
			break;
	}
	for(newEnd= mLength-1; newEnd >= newBeg; newEnd--) {
		if (mData[newEnd] > 0x20)
			break;
	}
	int newLength= newEnd + 1 - newBeg;
	if (newBeg > 0)
		memmove(mData, mData+newBeg, newLength);
	setLength(newLength);
}

char* StrBuffer::willWrite(Size inSize) {
	ensureCapacity(inSize);
	mLength= inSize;
	setEOS();
	return mData;
}

char* StrBuffer::release ()
{
    char* ptr = mData;
    mCapacity =0;
    mLength = 0;
    mData = 0;
    return ptr;
}

void StrBuffer::acquire (char* ptr)
// takes ownership of pointer
{
    set (NULL);

    Size length = strLength (ptr);
    mCapacity = length;
    mLength = length;
    mData = ptr;
}

#if BASE_DEBUG

static char charFor(int i) {
	return 'a' + i % 26;
}

void testStr();
void testStr() {
	StrBuffer a("123"), b;
	a+="456";
	mustbe(!(a!=Str("123456")));
	b= a;
	mustbe(a.equals(b));
	a+=b;
	mustbe(a.compare(b) > 0);
	mustbe((b.length() * 2)==a.length());
	mustbe(a.lastIndexOf(b)==b.length());
	a= 0;
	mustbe(a.empty());
	int i;
	for(i= 0; i < 1025; i++)
		a.append(charFor(i));
	for(i= 0; i < 1025; i++)
		mustbe(a[i]==charFor(i));
	Str test1(a.getCString(), 1025 - 25, 1025);
	for(i= 0; i < test1.length(); i++)
		mustbe(test1[i]==charFor(i + 1025 - 25));
	Str c1("11"), c2("2222222222222222222"), c3("3"), c4("44");
	StrBuffer atOnce(c1, c2, c3, c4);
	StrBuffer oneByOne;
	(oneByOne+=c1)+=c2;
	oneByOne.append(StrBuffer(c3, c4));
	mustbe(oneByOne==atOnce);
	mustbe(oneByOne.indexOf(atOnce)==0);
}

#endif

/*
NOTES:

1) A Difference between Str and StrBuffer

Str is lightweight. It does not allocate memory, it relies on memory supplied in
the constructor, so care should be taken that the underlying buffer is not deallocated. 
The following will most likely return garbage:

	Str wrongGetStringFromStdIn() {
		char readBuff[256];
		gets(readBuff);
		return Str(readBuff);	// readBuff will turn into garbage upon function exit
	}

In contrast, StrBuffer takes care of its storage so its data is always valid and this will 
work:

	StrBuffer rightGetStringFromStdIn() {
		char readBuff[256];
		gets(readBuff);
		return StrBuffer(readBuff);	// readBuff's data is copied to StrBuffer
	}

2) 

The inheritance "StrBuffer : public Str" is coincidental and should be treated as "bad C++". 
I will try to get rid of it in the future.

*/




