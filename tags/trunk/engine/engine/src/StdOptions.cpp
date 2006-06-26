//
// File        : $RCSfile: $ 
//               $Workfile: StdOptions.cpp $
// Version     : $Revision: 37 $ 
//               $Author: Aviad $
//               $Date: 12/04/05 0:54 $ 
// Description :
//    Concrete implmentations for Langauge, Scores::Function, WeightFunction etc
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

#include "StdOptions.h"

#include "persistance/TextWriter.h"
#include "DebugLog.h"

#ifndef ROUND
#define ROUND(x) ((x) >= 0 ? (int) ((x) + .5) : -((int) (.5 - (x))))
#endif


#define DEBUG_FILTERS 0 

/**
 * from http://www.loria.fr/~kucherov/SOFTWARE/grappe-3.0/iupac.html
 * IUPAC codes
 *
 * The IUPAC Code is a set of symbols encoding each subset of the four nucleotides. Here is the complete list of these symbols assg_together with the subsets they encode. 
 * Code Corresponding class Name 
 * A - Adenine 
 * C - Cytosine 
 * G - Guanine 
 * T - Thymine 
 * U - Uracil 
 * R [GA] purine 
 * Y [TC] Pyrimidine 
 * K [GT] Keto 
 * M [AC] Amino 
 * S [GC] ? 
 * W [AT] ? 
 * B [GTC] ? 
 * D [GAT] ? 
 * H [ACT] ? 
 * V [GCA] ? 
 * N [ACGT] Any 
**/




using namespace std;

static AlphabetCode::Code __acgt;
static AutoPtr <AlphabetCode> __ACGTN;
static AutoPtr <AlphabetCode> __ACGT;


static void initACGTCode () 
{
   AlphabetCode::copy (__acgt, AlphabetCode::emptyCode ());
   //
   // cast to int to make gcc happy
   __acgt [(int)'a'] = __acgt [(int)'A'] = 0;
   __acgt [(int)'c'] = __acgt [(int)'C'] = 1;
   __acgt [(int)'g'] = __acgt [(int)'G'] = 2;
   __acgt [(int)'t'] = __acgt [(int)'T'] = 3;
   __acgt [(int)'n'] = __acgt [(int)'N'] = 4; // AlphabetCode::dunnoCode;
}

const AlphabetCode& ACGTLangauge::getCode (bool cardinalityIncludesN)
{
   if (cardinalityIncludesN) {
      if (!__ACGTN.valid ()) {
         initACGTCode ();
         __ACGTN = new AlphabetCode (__acgt, 5);
      }

      return *__ACGTN;
   }
   else {
      if (!__ACGT.valid ()) {
         initACGTCode ();
         __ACGT = new AlphabetCode (__acgt, 4);
      }

      return *__ACGT;
   }
}

static void writeACGTLangaugeCode (unsigned long code, 
                                   Assignment::Strategy strategy,
                                   Persistance::TextWriter& writer)
{
   char iupac;
   switch (code) {
      case ACGTLangauge::ACode:   // A - Adenine 
         iupac = 'A';
         break;
      case ACGTLangauge::CCode:   // C - Cytosine 
         iupac = 'C';
         break;
      case ACGTLangauge::GCode:   // G - Guanine 
         iupac = 'G';
         break;
      case ACGTLangauge::TCode:   // T - Thymine 
         iupac = 'T';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::ACode): // R [GA] purine 
         iupac = 'R';
         break;
      case (ACGTLangauge::TCode | ACGTLangauge::CCode): // Y [TC] Pyrimidine 
         iupac = 'Y';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::TCode): // K [GT] Keto 
         iupac = 'K';
         break;
      case (ACGTLangauge::ACode | ACGTLangauge::CCode): // M [AC] Amino 
         iupac = 'M';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::CCode): // S [GC] ? 
         iupac = 'S';
         break;
      case (ACGTLangauge::ACode | ACGTLangauge::TCode): // W [AT] ? 
         iupac = 'W';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::TCode | ACGTLangauge::CCode): // B [GTC] ? 
         iupac = 'B';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::ACode | ACGTLangauge::TCode): // D [GAT] ? 
         iupac = 'D';
         break;
      case (ACGTLangauge::ACode | ACGTLangauge::CCode | ACGTLangauge::TCode): // H [ACT] ? 
         iupac = 'H';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::CCode | ACGTLangauge::ACode): // V [GCA] ? 
         iupac = 'V';
         break;
      case (ACGTLangauge::GCode | ACGTLangauge::CCode | ACGTLangauge::ACode | ACGTLangauge::TCode): // N [GCTA]  
			if (strategy == assg_together) {
            writer << "[ACGT]";
				return;
			}
         else
            iupac = '*';
         break;
      case (ACGTLangauge::NCode):  {
            writer << "[N]";
            return;
         }
         break;

      case (ACGTLangauge::NCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::CCode):
      case (ACGTLangauge::NCode | ACGTLangauge::GCode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::CCode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::GCode):
      case (ACGTLangauge::NCode | ACGTLangauge::GCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::GCode | ACGTLangauge::CCode):
      case (ACGTLangauge::NCode | ACGTLangauge::CCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::GCode | ACGTLangauge::CCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::CCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::GCode | ACGTLangauge::ACode):
      case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::GCode | ACGTLangauge::CCode): {
            writer << "[N";
            writeACGTLangaugeCode (code  - ACGTLangauge::NCode, strategy, writer);
            writer << ']';
            return;
         }
         break;
		
		case (ACGTLangauge::NCode | ACGTLangauge::TCode | ACGTLangauge::GCode | ACGTLangauge::CCode | ACGTLangauge::ACode):   
			if (strategy == assg_together)
            iupac = '?';
			else {
            writer << "[*ACGTN]";
				return;
			}
         break;


      default:
         debug_mustfail ();
         iupac = '!';
         break;
   };

   writer << iupac;
}

void ACGTLangauge::write(const Assignment::Position& pos,
                       Persistance::TextWriter& writer) const
{
   int c = pos.count ();
   if (c == 0) {
      writer << "-";
      return;
   }
   unsigned long code = pos.toULong ();
   writeACGTLangaugeCode (code, pos.strategy (), writer);


}

void ACGTLangauge::complement (const Assignment& in , Assignment& out) const
{
   out = Assignment ();
   for (int i=in.length () - 1; i>=0 ; i--) {
      const Assignment::Position& p = in.getPosition (i);
		if (p.equals (wildcard (p.strategy ()))) 
			out.addPosition (p);
		else {
			Assignment::Position r (p.strategy ());
			Assignment::PositionIterator it (p);
			for (; it.hasNext () ; it.next ()) {
				//
				// A <--> T, C <--> G
				// 0      3  1      2
				r.index (3 - (it.get ()), true);
			}

			out.addPosition (r);
		}
   }
}

void ACGTLangauge::complement (const Str& in, StrBuffer& out) const
{
   out.ensureCapacity (in.length ());
   for (int i=in.length () - 1 ; i>=0 ; i--) {
      char code = in [i];
      char reverse;
      switch (code) {
         case 'a':
         case 'A':   // A - Adenine 
            reverse = 'T';
            break;
         case 'c':
         case 'C':   // C - Cytosine 
            reverse = 'G';
            break;
         case 'g':
         case 'G':   // G - Guanine 
            reverse = 'C';
            break;
         case 't':
         case 'T':   // T - Thymine 
            reverse = 'A';
            break;
         case 'r':
         case 'R': // R [GA] purine 
            reverse = 'Y';  // [TC]
            break;
         case 'y':
         case 'Y': // Y [TC] Pyrimidine 
            reverse = 'R'; // [GA]
            break;
         case 'k':
         case 'K': // K [GT] Keto 
            reverse = 'M'; // [AC]
            break;
         case 'm':
         case ('M'): // M [AC] Amino 
            reverse = 'K'; // [GT]
            break;
         case 's':
         case ('S'): // S [GC] ? 
            reverse = 'S'; // [GC]
            break;
         case 'w':
         case ('W'): // W [AT] ? 
            reverse = 'W'; // [AT]
            break;
         case 'b':
         case ('B'): // B [GTC] ? 
            reverse = 'V'; // [GAC]
            break;
         case 'd':
         case ('D'): // D [GAT] ? 
            reverse = 'H'; // [ACT]
            break;
         case 'h':
         case ('H'): // H [ACT] ? 
            reverse = 'D';  // [AGT]
            break;
         case ('V'): // V [GCA] ? 
            reverse = 'B'; // [GTC]
            break;
         
         case 'n':
         case 'N':
         case '?':
         case '*':
            reverse = code;
				break;

         default:
            debug_mustfail ();
            reverse = '!';
            break;
      };
      out.append (reverse);
   }
}

//
// KBestFilter
//


KBestFilter::KBestFilter (int k, int maxRedundancyOffset, FeatureSet_ptr container)
: _maxElements (k), _maxRedundancyOffset (maxRedundancyOffset), _features (container)
{
   debug_mustbe (_maxRedundancyOffset>=0);
   debug_mustbe (_maxElements>0);

	if (!_features) {
		_features.reset (new FeatureSet);
	}
}

KBestFilter::~KBestFilter ()
{
}

//
// FertileFeaturesFilter
//

FertileFeaturesFilter::FertileFeaturesFilter (
								 boost::shared_ptr <SeedSearcher::FeatureFilter>& next, 
                           const SeqCluster& db          ,
                           const SeqWeightFunction& wf   ,
                           int minPos                    , 
                           int minPosPercent             )
:  FeatureFilterLink (next),
   _wf (wf)
{
   debug_mustbe (minPos >= 0);
   debug_mustbe (minPosPercent >= 0);
   debug_mustbe (minPosPercent <= 100);

   //
   // count positive sequences
   SeqCluster::CountSequences count;
   db.performOnPositives (_wf, count);

   int threshold = 
      tmax (minPos, count.result () * minPosPercent / 100);

   _minPositiveSeqs = threshold;
}

//
// takes ownership of Assignment & Cluster
bool FertileFeaturesFilter::add (Feature_var daFeature)
{
   if (_minPositiveSeqs > 0) {
      SeqCluster::CountSequences count;
      daFeature->cluster().performOnPositives (_wf, count);

      if (count.result () < _minPositiveSeqs)
         return false;
   }

   return _next->add (daFeature);
}

#include <fstream>
#include "persistance/StdOutputStream.h"
#include "core/Str.h"

FeaturePrintFilter::FeaturePrintFilter (	
	boost::shared_ptr <SeedSearcher::FeatureFilter>& next,
	const Str& name)
: FeatureFilterLink (next), _writer (NULL)
{
	std::string filename;
	name.getCString (filename);	filename += ".exhaustive";
   AutoPtr <std::ofstream> file = new std::ofstream (filename.c_str (),
      std::ios::out | std::ios::trunc | std::ios::binary);

	if( ! file->is_open() ) {
		std::string err ("Cannot open file for ");
		err += filename;
      mmustfail (filename.c_str ());
	}

	_writer.setStream (new Persistance::StdOutputStream (file.release(), true));

	//
	// add a header
	_writer << "Score (-log10)\tMotif" << _writer.EOL();
}

//
// takes ownership of Assignment & Cluster
bool FeaturePrintFilter::add (Feature_var feature)
{
	static const double LOG10_2 = log10 (static_cast <double> (2));
	//
	// the purpose here is to get a summary of all scores 
	// for generating statistics 
	// but we print in -log10 format
	_writer << (0 - feature->log2score ()) * LOG10_2;

#if 1 
	//
	// just for debugging, we also print the seed
	_writer << '\t' << Format (feature->assignment ());
#endif

	_writer.writeln ();

	//
	// now actually add the seed to the feature container
	return _next->add (feature);
}

void FDRCorrectionFilter::finalizeSetting (int numSeedsSearched, int numProjections)
{
	Scores::FDRCorrectedPValue* fdr = NULL;
   FeatureSet::RIterator it = getArray ()->getRIterator ();
   for (int k = getArray ()->size () ; it.hasNext () ; ++k, it.next()) {
      Feature_var feature = (*it);
		fdr = new Scores::FDRCorrectedPValue (feature->score (), numSeedsSearched, k, fdr);
		feature->score (Scores::Score_ptr (fdr));
   }

	FeatureFilterLink::finalizeSetting (numSeedsSearched, numProjections);
}

void BonfCorrectionFilter::finalizeSetting (int numSeedsSearched, int numProjections)
{
	Scores::BonfCorrectedPvalue* bonf = NULL;
   FeatureSet::RIterator it = getArray ()->getRIterator ();
   for (int k = getArray ()->size () ; it.hasNext () ; ++k, it.next()) {
      Feature_var feature = (*it);
		bonf = new Scores::BonfCorrectedPvalue (feature->score (), numSeedsSearched);
		feature->score (Scores::Score_ptr (bonf));
   }

	FeatureFilterLink::finalizeSetting (numSeedsSearched, numProjections);
}









