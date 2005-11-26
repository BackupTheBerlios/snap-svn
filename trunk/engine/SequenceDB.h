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
   SequenceDB (const AlphabetCode& code) : _code (code) {
   }
   ~SequenceDB ();
   SequenceIterator sequenceIterator ()  const{
      return SequenceIterator (_sequences.begin (), _sequences.end ());
   }
   const SequenceVector& sequences () const{
      return _sequences;
   }
   const AlphabetCode& alphabetCode () const {
      return _code;
   }
   const Sequence& getSequence (ID id) const   {
      return *_sequences[id];
   }
   int size () const {
      return _sequences.size ();
   }
   void getSequencesAbove (double weight, Cluster&) const;
   
   struct TextFileStorage {
      static SequenceDB* loadFastaNoWeights (const AlphabetCode&, 
                                             const char* seqFileName);

      static SequenceDB* loadFastaInFileWeights (const AlphabetCode&, 
                                                 const char* seqFileName);
      
      static SequenceDB* loadFastaAndWeights (const AlphabetCode&,
                                              const char* seqFileName,
                                              const char* weightFileName);

      static void assignWeights (SequenceDB& db, 
                                 const char* weightFileName,
                                 bool removeWeightsForMissingSequences);

      class Rep;
   };

   friend class TextFileStorage::Rep;

private:
   typedef std::map <Name, ID> Name2ID;
   typedef std::vector <Name> ID2Name;

   AlphabetCode _code;
   SequenceVector _sequences;
   Name2ID _name2ID;
};

#endif // _SeedSearcher_SequenceDB_h













