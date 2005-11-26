#include "Core/Defs.h"
#include "Sequence.h"
#include "SequenceDB.h"

#include "Persistance/OArchive.h"
#include "Persistance/IArchive.h"
#include "Persistance/TextReader.h"
#include "Persistance/StdInputStream.h"

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


static void Err(const char* s) {
   debug_mustfail ();
   cerr<<s<<endl;
   cerr.flush();
   exit(1);
}
static void Err(const std::string& s) {
   Err (s.c_str ());
}



class SequenceDB::TextFileStorage::Rep {
public:
   static void insertSequence (  SequenceDB& db          , 
                                 double* weight          ,
                                 const std::string& name ,
                                 const std::string& seq  , 
                                 SequenceDB::ID id       )  {
      db._name2ID [Str (name)] = id;
      Sequence* sequence = (weight != NULL)?
         new Sequence (id, Str (seq),  Str (name),  *weight) :
         new Sequence (id, Str (seq), Str (name));
      
      db._sequences.push_back(sequence);
   }
   
   static void checkup (SequenceDB& db, const char* seqFileName) {
      if (!db._sequences.size())
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
};



SequenceDB* SequenceDB::TextFileStorage::loadFastaInFileWeights (
                                                                 const AlphabetCode& code,
                                                                 const char* seqFileName)
{
   ID id= 0;
   ifstream In (seqFileName);
   if (! In.is_open())
      Err(StrBuffer ("unable to open SeqData file ", seqFileName));
   
   std::string w;
   std::string s;
   std::string name;
   auto_ptr <SequenceDB> db (new SequenceDB (code));
   while (!In.eof()) {
      name.resize (0);
      w.resize (0);
      s.resize (0);
      
      do {
         getline(In,name,'\t'); // get name
      } while ( (!name.size() && (!In.eof())));
      if ( In.eof())
         break;
      
      
      double weight = 0.0;
      getline(In,w,'\t'); // get weight
      weight = atof(w.c_str());
      assert( (!In.eof()) && weight>=0.0 && weight<=1.0);
      getline(In,s); // get sequence
      assert( (!In.eof()) && s.size());
      
      Rep::insertSequence (*db, &weight, name, s, id);
      id++;
   }
   
   return db.release ();
}



static void readWeights(string const & fname, map<StrBuffer,double> & weights)
{
   ifstream in(fname.c_str());
   if (! in.is_open())
      Err(string("unable to open SeqData file ")+ fname);
   
   string name, s;
   while (true) {
      s.resize (0);
      name.resize (0);
      
      double val;
      while ( (! in.eof()) && (s.size()==0) )
         in>>s;// skip empty lines;
      if ( in.eof())
         break;    
      // here we handle cases in which the ">" is/is'nt seperated from the name of the gene.
      if (s ==">")
         in>>name;
      else {
         assert(s[0]=='>');    
         name = s.substr(1);
      }
      
      in>>val;
      weights[Str (name)] = val;
   }
}





SequenceDB* SequenceDB::TextFileStorage::loadFastaNoWeights (
                                                             const AlphabetCode& code, 
                                                             const char* seqFileName)
{
   ifstream in(seqFileName);
   if (! in.is_open())
      Err(string("unable to open SeqData file ")+ seqFileName);
   
   auto_ptr <SequenceDB> db (new SequenceDB (code));
   
   string name,seq,s;
   ID id =0;
   in>>s;
   //
   // here we handle cases in which the ">" is/is'nt seperated from the name of the gene.
   if (s ==">")
      in>>name;
   else {
      assert(s[0]=='>');    
      name = s.substr(1);
   }
   
   char c;
   in.get(c);
   while (c != '\n' && c != EOF)
      in.get(c);
   
   while (in>>s) {
      if ((s[0]=='>') && seq.size()){
         Rep::insertSequence (*db, NULL, name, seq, id);
         id++;
         
         seq.resize (0);
         if (s ==">")
            in>>name;
         else
            name = s.substr(1);	
         
         in.get(c);
         while (c != '\n' && c != EOF)
            in.get(c);
      }
      else
         seq += s;
   }
   
   if (seq.size()) {
      //
      // BUG FIX: (Aviad). the last sequence (exactly like those before it)
      // should be used only if it has an associated weight
      Rep::insertSequence (*db, NULL, name, seq, id);
   }
   
   TextFileStorage::Rep::checkup (*db, seqFileName);
   return db.release ();
}


SequenceDB* SequenceDB::TextFileStorage::loadFastaAndWeights (
                                                              const AlphabetCode& code,
                                                              const char* seqFileName,
                                                              const char* weightFileName)
{
   map<StrBuffer,double> weights;
   readWeights(weightFileName, weights);
   
   ifstream in(seqFileName);
   if (! in.is_open())
      Err(string("unable to open SeqData file ")+ seqFileName);
   
   auto_ptr <SequenceDB> db (new SequenceDB (code));
   
   string name,seq,s;
   ID id =0;
   in>>s;
   //
   // here we handle cases in which the ">" is/is'nt seperated from the name of the gene.
   if (s ==">")
      in>>name;
   else {
      assert(s[0]=='>');    
      name = s.substr(1);
   }
   
   char c;
   in.get(c);
   while (c != '\n' && c != EOF)
      in.get(c);
   
   while (in>>s) {
      if ((s[0]=='>') && seq.size()){
         if (weights.find(Str (name)) != weights.end()) {	
            //
            //
            Rep::insertSequence (*db, 
                                 &((weights.find(Str (name)))->second),
                                 name, 
                                 seq, 
                                 id++);
         }
         
         debug_only ( size_t capacity = seq.capacity (); );
         seq.resize (0);
         debug_mustbe ( capacity == seq.capacity () );
         
         if (s ==">")
            in>>name;
         else
            name = s.substr(1);	
         
         in.get(c);
         while (c != '\n' && c != EOF)
            in.get(c);
      }
      else
         seq += s;
   }
   
   if (seq.size()) {
      //
      // BUG FIX: (Aviad). the last sequence (exactly like those before it)
      // should be used only if it has an associated weight
      if (weights.find(Str (name)) != weights.end()) {	
         Rep::insertSequence (*db, &((weights.find(Str (name)))->second), name, seq, id);
      }
   }
   
   Rep::checkup (*db, seqFileName);
   return db.release ();
}

void SequenceDB::TextFileStorage::assignWeights (
                                                 SequenceDB& db, 
                                                 const char* weightFileName,
                                                 bool removeWeightsForMissingSequences)
{
   map<StrBuffer,double> weights;
   readWeights (weightFileName, weights);
   
   SequenceIterator it = db.sequenceIterator ();
   for (; it.hasNext () ; it.next ()) {
      map<StrBuffer,double>::const_iterator weights_it = 
         weights.find ((*it)->name ());
      
      if (weights_it == weights.end ()) {
         if (removeWeightsForMissingSequences)
            (*it)->noWeight ();
      }
      else {
         (*it)->weight (weights_it->second);
      }
   }
}




SequenceDB::~SequenceDB ()
{
   int size = _sequences.size ();
   for (int i=0 ; i<size ; i++)
      delete _sequences [i];
   
   _sequences.clear ();
}

void SequenceDB::getSequencesAbove (double weight, Cluster& out) const
{
   out.clear ();
   SequenceIterator it (sequenceIterator ());
   for (; it.hasNext () ; it.next ()) {
      Sequence* seq = it.get ();
      if (seq->hasWeight ())
         if (seq->weight () >= weight)
            out.addSequence (it.get ());
   }
}



#include "Persistance/STLPersist.h"

using namespace Persistance;

void SequenceDB::serialize (Persistance::IArchive& in)
{
   int cardinality;
   AlphabetCode::Code code;
   
   in >> cardinality;
   in.readCharBuffer (code, sizeof (code));
   _code = AlphabetCode (code, cardinality);
   
   in >> Persistance::ISTLReg <SequenceVector> (_sequences);
   in >> IMap <Name2ID> (_name2ID);
}

void SequenceDB::serialize (Persistance::OArchive& out)
{
   out << (int) _code.cardinality ();
   out.writeCharArray (_code.getCode (), sizeof (AlphabetCode::Code));
   
   out << OSTLReg <SequenceVector> (_sequences);
   out << OMap <Name2ID> (_name2ID);
}










