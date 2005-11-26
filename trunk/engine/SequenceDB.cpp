#include "Core/Defs.h"
#include "Sequence.h"
#include "SequenceDB.h"

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


static void Err(std::string const & s) {
   debug_mustfail ();
   cerr<<s<<endl;
   cerr.flush();
   exit(1);
}

SequenceDB* SequenceDB::TextFileStorage::load (const AlphabetCode& code, const char* seqFileName)
{
   ID id= 0;
   ifstream In(seqFileName);
   if (! In.is_open())
      Err(string("unable to open SeqData file ")+ seqFileName);

   auto_ptr <SequenceDB> db (new SequenceDB (code));
   while (!In.eof()) {
      string name;
      do
      getline(In,name,'\t'); // get name
      while ( (!name.size() && (!In.eof())));
      if ( In.eof())
         break;
      
      string w;
      double weight = 0.0;
      getline(In,w,'\t'); // get weight
      weight = atof(w.c_str());
      assert( (!In.eof()) && weight>=0.0 && weight<=1.0);
      string s;
      getline(In,s); // get sequence
      assert( (!In.eof()) && s.size());

      db->_name2ID [name] = id; 
      db->_id2Name.push_back(name);
      //tGIDVec::push_back( GetCode(s));
      //iWeights.push_back(weight);
      db->_sequences [id] = new Sequence (id, s.c_str (), weight);
      id++;
   }

   if (!db->_sequences.size())
      Err(string("read no data from the seq file")+ seqFileName);

   debug_only (
      cerr<<"read File: "<<endl;
      for (size_t i = 0; i < db->_sequences.size () ;i++) {
         cerr<< db->_id2Name[i] << "\t" << db->getSequence (i).data () << endl;
      }
   )

   return db.release ();
}







static void readWeights(string const & fname, map<string,double> & weights)
{
  ifstream in(fname.c_str());
  if (! in.is_open())
    Err(string("unable to open SeqData file ")+ fname);

  string name,seq,s;

  while (true) {
    string s,name;
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
    weights[name] = val;
  }
   
}




SequenceDB* SequenceDB::TextFileStorage::load (const AlphabetCode& code,
                                   const char* seqFileName,
                                   const char* weightFileName)
{
   map<string,double> weights;
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
         if (weights.find(name) != weights.end()) {	
            //
            //map<string,codeVec>::operator [] (name) = GetCode(seq);
            db->_name2ID [name] = id;
            db->_id2Name.push_back(name);
            db->_sequences.push_back( new Sequence (id, seq.c_str (), (weights.find(name))->second));
            id++;
         }

         seq = "";
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
      if (weights.find(name) != weights.end()) {	
         db->_name2ID [name] = id;
         db->_id2Name.push_back(name);
         db->_sequences.push_back( new Sequence (id, seq.c_str (), (weights.find(name))->second));
         //
         //      map<string,codeVec>::operator [] (name) = GetCode(seq);
      }
   }

   if (!db->_sequences.size())
      Err(string("read no data/ date that match the weights File data from the seq file: ")+ seqFileName);

   debug_only (
      cerr<<"read Fasta File: "<<endl;
      for (size_t i = 0; i < db->_sequences.size () ;i++) {
         cerr<< db->_id2Name[i] << "\t" << db->getSequence (i).data () << endl;
      }
   )

   return db.release ();
}


void SequenceDB::getSequencesAbove (double weight, Cluster& out) const
{
   out.clear ();
   SequenceIterator it (sequenceIterator ());
   for (; it.hasNext () ; it.next ()) {
      if (it.get ()->weight () >= weight)
         out.add (it.get ()->id ());
   }
}

void SequenceDB::Cluster::intersect (const Cluster& a, 
				     const Cluster& b, 
				     Cluster& o)
{
   o.clear ();

   //
   // TODO: must be a better/faster way to do this
   const Cluster* x;
   const Cluster* y;
   if (b.size () < a.size ()) {
       x = &a;
       y = &b;
   }
   else {
      x = &b;
      y = &a;
   }

   SeqSet::const_iterator it = x->_sequences.begin ();
   for (; it != x->_sequences.end () ; it++) {
      if (y->find (*it))
         o.add (*it);
   }
}


void SequenceDB::Cluster::unify (const Cluster& o)
{
   SeqSet::const_iterator it = o._sequences.begin ();
   for (; it != o._sequences.end () ; it++)
      add (*it);
}

double SequenceDB::Cluster::sumWeights (const SequenceDB& db) const
{
   double result = 0;
   SeqSet::const_iterator it =_sequences.begin ();
   SeqSet::const_iterator end =_sequences.end ();

   for (; it != end ; it++) {
      const Sequence& seq = db.getSequence (*it);
      result += seq.weight ();
   }

   return result;
}


