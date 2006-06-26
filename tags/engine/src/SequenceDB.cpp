//
// File        : $RCSfile: $ 
//               $Workfile: SequenceDB.cpp $
// Version     : $Revision: 25 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $ 
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
#include "Sequence.h"
#include "SequenceDB.h"
#include "AssignmentFormat.h"

#include <fstream>
#include <iostream>
#include <assert.h>


using namespace std;

/*****************
*
* Most of this file's content has been 
* copied from legacy SeedSearcher
*
*****************/

struct DBError : public BaseException {
   DBError (std::string const & s)
		: BaseException (std::string ("Error in sequence file: ") + s) {
   }
};


static void Err(const char* s) {
   throw DBError (s);
}
static void Err(const std::string& s) {
   throw DBError (s);
}


static inline Str toStr (const string& in) {
   return Str (in.c_str (), 0, in.length ());
}

static void insertSequence (  SequenceDB& db          , 
                              const std::string& name ,
                              const std::string& seq  , 
                              SequenceDB::ID id       ,
                              const Langauge& langauge)  
{
   StrBuffer reverse;
   if (langauge.supportComplement ()) {
      langauge.complement (toStr (seq), reverse);
   }

   Sequence* newSeq = 
      new Sequence (id, toStr (seq),  toStr (name), reverse);

   db.insertSequence (  id, 
                        toStr (name), 
                        newSeq );
}

static void checkup (SequenceDB& db, const char* seqFileName) 
{
   if (!db.size ())
      Err(StrBuffer ("read no data from the seq file", seqFileName));
   
      /*
      debug_only (
      cerr<<"read File: "<<endl;
      for (size_t i = 0; i < db._sequences.size () ;i++) {
      cerr<< db.getSequence (i).name () << "\t" << db.getSequence (i).data () << endl;
      }
      )
   */
}


static void readName (istream& in, string& name, const string& s)
{
   //
   // here we handle cases in which the ">" is/is'nt seperated from the name of the gene.
   if (s ==">")
      in>>name;
   else {
      assert(s[0]=='>');
      //
      // skip the first '>' and also all whitespace afterwards
      const char WHITESPACE [] =" \t";
      int index = s.find_first_not_of (WHITESPACE, 1 , sizeof (WHITESPACE));
      name = s.substr (index);
   }

   //
   // now we ignore the rest of the description line
   char c;
   in.get(c);
   while (c != '\n' && c != EOF)
      in.get(c);
}


SequenceDB* 
   SequenceDB::TextFileStorage::loadFastaAndWeights (
      const Langauge& langauge   ,
      const char* seqFileName    ,
      SeqWeightDB::Name2Weight& weights)
{
   ifstream in(seqFileName);
   if (! in.is_open())
      Err(string("unable to open SeqData file ")+ seqFileName);

	AutoPtr <SequenceDB> db = loadFastaAndWeights(langauge, in, weights);
	checkup (*db, seqFileName);
	return db.release();
}

SequenceDB* 
	SequenceDB::TextFileStorage::loadFastaAndWeights (
	const Langauge& langauge   ,
	std::istream& in,
	SeqWeightDB::Name2Weight& weights)
{
   auto_ptr <SequenceDB> db (new SequenceDB);
   
   string name,seq,s;
   ID id =0;
   in>>s;

   readName (in, name, s);

   const StrBuffer& characters =
      langauge.code ().characters ();
   
   while (in>>s) {
      if ((s[0]=='>') && seq.size()){
         SeqWeightDB::Name2Weight::iterator node = weights.find(Str (name));
			if (node != weights.end ()) {	
            //
            //
            ::insertSequence (   *db, 
                                 name, 
                                 seq, 
                                 id++,
                                 langauge);
         }
         
         debug_only ( size_t capacity = seq.capacity (); );
         seq.resize (0);
         debug_mustbe ( capacity == seq.capacity () );
         
         readName (in, name, s);
      }
      else {
         //
         // make sure all the characters are in the alphabet
         std::string::size_type index = 
            s.find_first_not_of (characters, 0, characters.length ());

         if (index != std::string::npos) {
            //
            // found a character that is not in the alphabet
            Err ( string ("The sequence ") + 
                  name + 
                  " contained non-langauge characters:\n" + s);
         }

         seq += s;
      }
   }
   
   if (seq.size()) {
      //
      // BUG FIX: (Aviad). the last sequence (exactly like those before it)
      // should be used only if it has an associated weight
      SeqWeightDB::Name2Weight::iterator node = weights.find(Str (name));
      if (node != weights.end ()) {
         ::insertSequence (*db, 
                           name, 
                           seq, 
                           id,
                           langauge);
      }
   }

   return db.release ();
}



SequenceDB::~SequenceDB ()
{
   int size = _sequences.size ();
   for (int i=0 ; i<size ; i++)
      delete _sequences [i];
   
   _sequences.clear ();
}


#include "core/FixedStr.h"

bool SequenceDB::insertSequence (Sequence::ID id, const Str& name, Sequence* seq)
{
   //
	/// make sure that sequence names are unique
	if (_name2ID.find (name) != _name2ID.end ()) {
		/// name already exists
		Err (FixedStrBuffer <1024> ("A sequence named %s appears more than once in the sequence file.", StrBuffer (name).getCString ()));
	}

   _name2ID [name] = id;
   _sequences.push_back(seq);
   return true;
}
















