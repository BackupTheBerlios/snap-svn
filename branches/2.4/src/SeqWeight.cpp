#include "SeqWeight.h"
#include "Sequence.h"
#include "SequenceDB.h"

#include "core/FixedStr.h"
#include "persistance/TextReader.h"
#include "persistance/StdInputStream.h"

#include <string>
#include <fstream>
#include <iostream>
#include <assert.h>

double SeqWeightDB::PositionalWeight::getPositionWeight (int index) const
{
   //
   // we can use find_if because I don't expect more than
   // 10 hot-spots in a sequence, and in this range 
   // find_if performs better than binary_search
   Positions::const_iterator it = _positions.begin ();
   for (; it != _positions.end () ; ++it) {
      if (index < (*it)->_startIndex){
         it = _positions.end ();
         break;
      }
      else if (index <= (*it)->_startIndex + (*it)->_length)
         break;
   }

   if (it == _positions.end ())
      return _weight;
   else {
      return (*it)->_weight;
   }
}


//
//
// Format:
// >SeqName1 Wgt1
// >SeqName2 Wgt2
// ...
//
// example:
//
// >YFL048C	0.991742546801741
// >YOL116W 0.991742546801741

struct WeightsReader {
   virtual ~WeightsReader () {
   }
   void read (const char* fname) {
      
      std::ifstream in (fname);
      if (! in.is_open()) {
         mmustfail (
            FixedStrBuffer<4 * 1024> ("unable to open weight file %s",  fname)
            );
      }
      read (in);
   }
   void read (std::istream& in) {
      std::string name, s;
      while (true) {
         s.resize (0);
         name.resize (0);

         bool ok = true;
         while (ok && s.size()==0) {
            std::istream::sentry _ok(in);
            if (ok = _ok)
               in>>s;// skip empty lines;
         }

         if (!ok)
            break;    

         // here we handle cases in which the ">" is/isn't separated from the name of the gene.
         if (s ==">")
            in>>name;
         else {
            assert(s[0]=='>');    
            name = s.substr(1);
         }

         readValue(in, Str (name));
      }
   }

   virtual void readValue (std::istream& in, const Str&) = 0;
};

/*
AutoPtr <SeqWeightDB::Name2Weight> 
   SeqWeightDB::readWgtFile (const char* wgtFileName)
{
   //
   // we are not expected to deal with more than 
   struct SeqWeightsReader : public WeightsReader, AutoPtr <Name2Weight> {
      SeqWeightsReader () { 
         set (new Name2Weight (_default_db_size)); 
      }
      virtual void readValue (std::ifstream& in, 
                              const Str& name) 
      {
         double val;
         in>>val;
         get ()->add(new SeqWeightDB::Name2Weight::Node(Str (name), val));
      }
   } reader;

   reader.read (wgtFileName);
   return reader.release();
}
*/

AutoPtr <SeqWeightDB::ID2Weight> 
   SeqWeightDB::computeWeightIndex (
      const Name2Weight& weights, const SequenceDB& db)
{
   AutoPtr <ID2Weight> id2weight = new ID2Weight;

   Name2Weight::const_iterator it = weights.begin ();
   for (;it != weights.end () ; ++it) {
      Sequence* seq = db.getSequence(it->first);
      debug_mustbe (seq);
      if (seq) {
         PositionalWeight_var weight = it->second;
         (*id2weight) [seq->id ()] = weight;
      }
   }

   return id2weight;
}

//
// Positional weights:
//
//
// Format:
// >SeqName1 Wgt1 = [index1a, index1b] {Tab} Wgt2 = [index2a, index2b] {Tab}...
// ...
//
// example:
//
// >YFL048C	0.5 = [0, 100] 2.4 = [250, 300]  0.5 = [760, 900]
// >YOL116W 0.5 =[0, 70]  0.67 = [560, 700]
struct PosWeightsReader : public WeightsReader 
{
   PosWeightsReader ()
   {
      _posweights = new SeqWeightDB::Name2Weight;
      _entries.reserve (10);
   }

   virtual void readValue (std::istream& sin, const Str& name)
   {
      double seqWeight;
      sin>>seqWeight;

		std::string buffer;
		std::getline (sin, buffer);
      readValue (buffer, name, seqWeight);
   }

	void readValue (const std::string& lineBuffer, const Str& name, double seqWeight) {
		Str buffer = Str (lineBuffer).trimmedSubstring();

      _entries.clear ();
		while (!buffer.empty ()) {
         double w;
         int i1, i2;
         int count = sscanf (buffer.getChars (), "%lf = [%d, %d]", &w, &i1, &i2);
			Str::Index next = buffer.indexOf(']');
			if ((next == Str::badIndex) || (count != 3) || (!(i1 <= i2) && (w>=0) && (w<=1) && (i1 >= 0))){
				throw BaseException (
					StrBuffer (
						Str ("bad positional-weight format in "), name, 
						Str (":\nUnexpected "), buffer
					)
				);
			}
              
         _entries.push_back(new SeqWeightDB::PositionalWeight::Entry (i1, i2-i1, seqWeight * w));
			buffer = buffer.substring (next + 1);
			buffer = buffer.trimmedSubstring();
      }

      _temp = name;
      SeqWeightDB::PositionalWeight_var posWeight (
         new SeqWeightDB::PositionalWeight (seqWeight, _entries)
      );

      _posweights->insert (
         SeqWeightDB::Name2Weight::value_type (_temp, posWeight)
      );
   }

   virtual void readValue (Persistance::TextReader& reader, const Str& name, double seqWeight)
   {
      _temp.setLength (0);
      reader.readln (_temp);
   }

   StrBuffer _temp;
   AutoPtr <SeqWeightDB::Name2Weight> _posweights;
   SeqWeightDB::PositionalWeight::Positions _entries;
};


AutoPtr <SeqWeightDB::Name2Weight> 
SeqWeightDB::readWgtFile (const char* weightFileName)
{
   PosWeightsReader reader;
   reader.read (weightFileName);
   return reader._posweights;
}

AutoPtr <SeqWeightDB::Name2Weight> 
SeqWeightDB::readWgtFile (std::istream& in)
{
   PosWeightsReader reader;
   reader.read (in);
   return reader._posweights;
}
