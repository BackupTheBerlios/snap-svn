#include "Sequence.h"

#include "Persistance/OArchive.h"
#include "Persistance/IArchive.h"
#include "Persistance/STLPersist.h"

ChunkAllocator <SeqPosition> SeqPosition::__allocator (16);
ChunkAllocator <Sequence> Sequence::__allocator;



Str SeqPosition::getSeedString (int length, int offset) const {
   //
   // 
   getModifiedOffsets (offset, length);

   //
   // keep str's ctor happy
   if (_position + offset > _sequence->length ()) {
      return 0;
   }

   debug_mustbe (length >= 0);
   debug_mustbe (_position + offset >= 0);
   debug_mustbe (_position + offset + length <= _sequence->length ());


   return Str (_sequence->data (_strand), 
               _position + offset, 
               _position + offset + length);
}
//
// the 1st argument (in/out) provides the offset from this position
// the 2nd argument (in/out) provides the length from the offset
//
// this method makes changes the offset (if necessary) so 
// that it is legal, decreasing the length in accordance.
// also if the length is too large, it is decreased.
void SeqPosition::getModifiedOffsets (int& offset, int& length) const
{
   //
   // do not go past the beginning of the string
   int startIndex = _position + offset;
   if (startIndex < 0) {
      //
      // the string is truncated in the left, so return less bytes
      length += startIndex;   // shorten length
      offset -= startIndex;   // make offset less negative
      startIndex = 0;
   }

   //
   // do not go beyond the end of the string
   int endIndex = startIndex + length;
   if (endIndex > _sequence->length ()) {
      endIndex = _sequence->length ();
   }

   //
   // calculate length
   length = tmax (endIndex - startIndex, 0);
}


//
// 'expands' a motif of length 'inLength' leftwards and rightwards,
// in the desired amount
int SeqPosition::getSeedString (
                     StrBuffer& outBuffer,   // the string is stored here
                     int inLength, // desired length
                     int inDesiredExpansionLeft, 
                     int inDesiredExpansionRight,
                     char alignment  // alignment for missing positions
                     ) const
{
   //
   // left section
   if (inDesiredExpansionLeft > 0) {
      Str leftPad = 
	      getSeedString (   inDesiredExpansionLeft,
                           -inDesiredExpansionLeft);

      outBuffer.append (alignment, 
                        inDesiredExpansionLeft - leftPad.length ());
      outBuffer.append (leftPad);
   }

   //
   // middle section
   Str motif = getSeedString (inLength);
   outBuffer.append (motif);
   if (motif.length () < inLength) {
      outBuffer.append (alignment, inLength - motif.length () + 
                                    inDesiredExpansionRight    );

      return inDesiredExpansionLeft;
   }

   //
   // right section
   const int rightPaddingPosition = inLength;
   if (inDesiredExpansionRight > 0) {
      Str rightPad = 
	      getSeedString (inDesiredExpansionRight, rightPaddingPosition);

      outBuffer.append (rightPad);
      outBuffer.append (alignment,
                     inDesiredExpansionRight - rightPad.length ());
   }

   return inDesiredExpansionLeft;
}

int SeqPosition::getSeedString (  
                     StrBuffer& outBuffer, 
                     int inLength,  // length of seed before expansion
                     int inDesiredLength,  // length after expansion
                     char alignment  // alignment for missing pos
                     ) const
{
   int expansion = inDesiredLength - inLength;
   int rightExpansion = expansion / 2;
   int leftExpansion = expansion - rightExpansion;

   debug_mustbe (expansion >= 0);
   debug_mustbe (rightExpansion >= 0);
   debug_mustbe (leftExpansion >= 0);

   return getSeedString (  outBuffer, 
                           inLength, 
                           leftExpansion, 
                           rightExpansion, 
                           alignment);
}








