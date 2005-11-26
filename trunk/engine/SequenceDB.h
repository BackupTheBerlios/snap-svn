#ifndef _SeedSearcher_SequenceDB_h
#define _SeedSearcher_SequenceDB_h

//
// File        : $RCSfile: $ 
//               $Workfile: SequenceDB.h $
// Version     : $Revision: 22 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:52 $ 
// Description :
//    Concrete repository for sequences
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
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "core/Defs.h"
#include "core/STLHelper.h"
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
   typedef CIteratorWrapper <SequenceVector> SequenceIterator;

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
   //
   // interface for adding sequences
   bool insertSequence (SequenceDB::ID id, const Str& name, Sequence*);
   
   Sequence* getSequence (const Sequence::Name& name) const{
      Name2ID::const_iterator it = _name2ID.find (name);
      return (it != _name2ID.end ())? _sequences [it->second] : NULL;
   }
   
   struct TextFileStorage {
      //
      // for loading a fasta file and a corresponding weight file
      static SequenceDB* loadFastaAndWeights (const Langauge&,
                                              const char* seqFileName,
                                              SeqWeightDB::Name2Weight&);
   };

private:
   typedef std::map <Name, ID> Name2ID;
   typedef std::vector <Name> ID2Name;

   SequenceVector _sequences;
   Name2ID _name2ID;
};

#endif // _SeedSearcher_SequenceDB_h













