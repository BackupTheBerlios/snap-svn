#ifndef _SeedSearcher_SequenceDB_h
#define _SeedSearcher_SequenceDB_h

#include "Core/Defs.h"
#include "Core/STLHelper.h"
#include "Alphabet.h"

#include <string>
#include <vector>
#include <map>
#include <set>



class SequenceDB {
public:
   //
   // defined in Sequence.h
   class Sequence;
   class Position;
   class Cluster;

   typedef int ID;
   typedef std::string Name;

   typedef Vec <Sequence*> SequenceVector;
   typedef ConstIteratorWrapper <SequenceVector> SequenceIterator;

public:
   SequenceDB (const AlphabetCode& code) : _code (code) {
   }
   SequenceIterator sequenceIterator ()  const{
      return SequenceIterator (_sequences.begin (), _sequences.end ());
   }
   const SequenceVector& sequences () const{
      return _sequences;
   }
   const AlphabetCode& alphabetCode () const {
      return _code;
   }
   const Sequence& getSequence (int index) const   {
      return *_sequences[index];
   }
   int size () const {
      return _sequences.size ();
   }
   void getSequencesAbove (double weight, Cluster&) const;

   class Cluster {
      //
      // TODO: (1) handle total counts (and also count /w weights e.g. double)
      //       (2) implement more efficiently with Bitset?
   public:
      Cluster () {
      }
      Cluster (const Cluster& o) : _sequences (o._sequences) {
      }
      Cluster& operator = (const Cluster& o) {
         _sequences = o._sequences;
         return *this;
      }

      void add (ID id) {
         //_sequences [id]++;
         _sequences.insert (id);
      }
      //int count (ID) const;
      bool find (ID id) const{
         SeqSet::const_iterator it = _sequences.find (id);
         return (it != _sequences.end ());
      }
      int size () const {
         return _sequences.size ();
      }
      bool empty () const {
         return _sequences.empty ();
      }
      void clear () {
         _sequences.clear ();
      }
      //
      // TODO: maybe cluster should hold Sequence* and thus make sumWeights more efficient
      double sumWeights (const SequenceDB&) const;

      //
      // 
      static void intersect (const Cluster&, const Cluster&, Cluster&);
      void unify (const Cluster&);


      typedef std::set <ID> SeqSet;
   private:
      SeqSet _sequences;
   };
  
   
   struct TextFileStorage {
      static SequenceDB* load (const AlphabetCode&, 
                               const char* seqFileName);
      static SequenceDB* load (const AlphabetCode&,
                               const char* seqFileName,
                               const char* weightFileName);
   };

   friend struct TextFileStorage;

private:
   typedef std::map <Name, ID> Name2ID;
   typedef std::vector <Name> ID2Name;

   AlphabetCode _code;
   SequenceVector _sequences;
   Name2ID _name2ID;
   ID2Name _id2Name;
};

#endif // _SeedSearcher_SequenceDB_h

