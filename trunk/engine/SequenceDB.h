#ifndef _SeedSearcher_SequenceDB_h
#define _SeedSearcher_SequenceDB_h

#include "Core/Defs.h"
#include "Core/STLHelper.h"
#include "Alphabet.h"
#include "Sequence.h"
#include "Cluster.h"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>




class SequenceDB  {
public:
   typedef Sequence::ID ID;
   typedef Sequence::Name Name;

   typedef SeqCluster Cluster;
   typedef Vec <Sequence*> SequenceVector;
   typedef ConstIteratorWrapper <SequenceVector> SequenceIterator;

public:
   SequenceDB () {
   }
   ~SequenceDB ();
   SequenceIterator sequenceIterator ()  const{
      return SequenceIterator (_sequences.begin (), _sequences.end ());
   }
   const SequenceVector& sequences () const{
      return _sequences;
   }
   const Sequence& getSequence (ID id) const   {
      return *_sequences[id];
   }
   int size () const {
      return _sequences.size ();
   }
   void getSequencesAbove (double weight, Cluster&) const;

   //
   // interface for adding sequences
   bool insertSequence (SequenceDB::ID id, const Str& name, Sequence*);

   
   struct TextFileStorage {
      //
      // for loading a fasta file and a corresponding weight file
      static SequenceDB* loadFastaAndWeights (const Langauge&,
                                              const char* seqFileName,
                                              const char* weightFileName);
   };

private:
   typedef std::map <Name, ID> Name2ID;
   typedef std::vector <Name> ID2Name;

   SequenceVector _sequences;
   Name2ID _name2ID;
};

#endif // _SeedSearcher_SequenceDB_h













