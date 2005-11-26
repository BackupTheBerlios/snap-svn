#include "StdOptions.h"

#include "Persistance/TextWriter.h"
#include "DebugLog.h"

#ifndef ROUND
#define ROUND(x) ((x) >= 0 ? (int) ((x) + .5) : -((int) (.5 - (x))))
#endif

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

void ACGTLangauge::write(const Assignment::Position& pos,
                       Persistance::TextWriter& writer) const
{
   char ACGT [] = "ACGTN";
   
   int c = pos.count ();
   if (c == 0)
      writer << "-";
   else if (c == 1) {
      Assignment::PositionIterator it (pos);
      writer << ACGT [it.get ()];
   }
   else if (c == cardinality ()) {
      if (pos.strategy ()== assg_together)
         writer << '?';
      else
         writer << '*';
   }
   else {
      char iupac;
      unsigned long code = pos.toULong ();
      switch (code) {
         case ACode:   // A - Adenine 
            iupac = 'A';
            break;
         case CCode:   // C - Cytosine 
            iupac = 'C';
            break;
         case GCode:   // G - Guanine 
            iupac = 'G';
            break;
         case TCode:   // T - Thymine 
            iupac = 'T';
            break;
         case (GCode | ACode): // R [GA] purine 
            iupac = 'R';
            break;
         case (TCode | CCode): // Y [TC] Pyrimidine 
            iupac = 'Y';
            break;
         case (GCode | TCode): // K [GT] Keto 
            iupac = 'K';
            break;
         case (ACode | CCode): // M [AC] Amino 
            iupac = 'M';
            break;
         case (GCode | CCode): // S [GC] ? 
            iupac = 'S';
            break;
         case (ACode | TCode): // W [AT] ? 
            iupac = 'W';
            break;
         case (GCode | TCode | CCode): // B [GTC] ? 
            iupac = 'B';
            break;
         case (GCode | ACode | TCode): // D [GAT] ? 
            iupac = 'D';
            break;
         case (ACode | CCode | TCode): // H [ACT] ? 
            iupac = 'H';
            break;
         case (GCode | CCode | ACode): // V [GCA] ? 
            iupac = 'V';
            break;
         default:
            debug_mustfail ();
            iupac = '!';
            break;
      };

      writer << iupac;
   }
}

void ACGTLangauge::complement (const Assignment& in , Assignment& out) const
{
   out = Assignment ();
   for (int i=in.length () - 1; i>=0 ; i--) {
      const Assignment::Position& p = in.getPosition (i);
      Assignment::Position r (p.strategy ());

      Assignment::PositionIterator it (p);
      for (; it.hasNext () ; it.next ()) {
         //
         // A <--> T, C <--> G
         r.index (3 - (it.get ()), true);
      }

      out.addPosition (r);
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

KBestFilter::KBestFilter (int k, int maxRedundancyOffset)
: _maxRedundancyOffset (maxRedundancyOffset), _features (k)
{
   debug_mustbe (_maxRedundancyOffset>=0);
}

KBestFilter::~KBestFilter ()
{
}

bool KBestFilter::checkSimilarity (int offset,
                             const AssignmentBase& a, 
                             const AssignmentBase& b)
{
   debug_mustbe (a.length () == b.length ());
   //
   // check that they share a common valid assignemnt
   int length = a.length () - offset;
   for (int i=0 ; i < length ; i++) {
      Assignment::Position apos = a[i];
      Assignment::Position bpos = b[i+offset];
      if (!apos.contains (bpos) && !bpos.contains (apos)) {
         //
         // they are not similar
         return false;
      }
   }

#if 0
   debug_only (
      DLOG << "Assignments are redundant (offset " 
           << offset 
           << ") " 
           << Format (a)
           << ' ' 
           << Format (b)
           << DLOG.EOL ();
      )
#endif

   //
   // they have a common base assignment, so they are similar
   // TODO: is this actually correct behavior?
   return true;
}

bool KBestFilter::checkRedundancy (int index, const Assignment& b)
{
   const Assignment& a = _features [index].assignment ();
   return checkSimilarity (a, b);
}

bool KBestFilter::checkSimilarity (const AssignmentBase& a, const AssignmentBase& b)
{
#if 0 
   debug_only (
      DLOG << "Comparing: "
           << Format (a)
           << ' ' 
           << Format (b)
           << DLOG.EOL ();
   );
#endif

   debug_mustbe (_maxRedundancyOffset >= 0);
   if (a.length () == b.length ()) {
      debug_mustbe (_maxRedundancyOffset < a.length ());

      //
      // for offset 0 checking similarity between (a,b) or (b,a) is the same
      if (checkSimilarity (0, a, b))
         return true;

      //
      // TODO: is there a better/faster way to do this?
      for (int offset=1 ; offset <= _maxRedundancyOffset ; offset++) {
         if (checkSimilarity (offset, a, b) || checkSimilarity (offset, b, a))
            return true;
      }
   }
   else {
      //
      // find out who is longer and who is shorter
      const AssignmentBase* longer, *shorter;
      if (a.length () > b.length ()) { longer = &a; shorter = &b; }
      else { longer = &b; shorter = &a; }
      int llength = longer->length ();
      int slength = shorter->length ();
      int diff =  llength - slength;

      //
      // check similarity one under the other
      for (int i=0 ; i <= diff ; i++) {
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), i, slength);
         if (checkSimilarity (0, assg, *shorter))
            return true;
      }

      {  //
         // check similarity between the short one and the beginning of the long one
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), 0, slength);
         for (int offset=1 ; offset <= _maxRedundancyOffset ; offset++) {
            if (checkSimilarity (offset, assg, *shorter))
               return true;
         }
      }

      {  //
         // check similarity between the short one and the end of the long one
         SubAssignment assg (const_cast <AssignmentBase&> (*longer), diff, slength);
         for (int offset=1 ; offset <= _maxRedundancyOffset ; offset++) {
            if (checkSimilarity (offset, *shorter, assg))
               return true;
         }
      }
   }

   return false;
}

//
// takes ownership of Assignment & Cluster
bool KBestFilter::add (Feature_var daFeature)
{
   _features.isSorted (false);
   const int _size = _features.size ();
   const int _k = _features.maxSize ();

   if (_size == 0) {
      _features.increaseSize ();
      _features [0] = *(daFeature.release ());
      return true;
   }

   //
   // we have to check if the assg is similar enough to some 
   // other in the array 
   int worst = 0;
   double worstScore = _features [0].log2score ();
   for (int i=0 ; i < _size ; i++) {
      //
      // we dont allow 'duplicates' in our features
      if (checkRedundancy (i, daFeature->assignment ())               ) {
         //
         // the smaller the score, the better.
         if (_features [i].log2score ()> daFeature->log2score ()) {
            //
            // replace this similar feature with a better one
            _features [i] = *(daFeature.release ());
            return true;
         }
         else {
            //
            // this is a redundant seed, and we already have a better one
            return false;
         }
      }

      //
      // search for the worst feature in the array
      if (_features [i].log2score () > worstScore) {
         worstScore = _features [i].log2score ();
         worst = i;
      }
   }

   if (_size < _k) {
      //
      // there is room in the array, so just stick it somewhere
      _features.increaseSize ();
      _features [_size] = *(daFeature.release ());
      return true;
   }
   else if (worstScore > daFeature->log2score ()) {
      debug_mustbe (_size == _k);
      //
      // we have no room in the array, so we have to replace
      // the worst feature
      _features [worst] = *(daFeature.release ());
      return true;
   }

   //
   // didnt add the feature, delete the memory (we are owners)
   return false;
}


//
// GoodFeaturesFilter
//

GoodFeaturesFilter::GoodFeaturesFilter (
                           SeedSearcher::FeatureFilter* next, 
                           bool owner                    ,
                           const SeqCluster& db          ,
                           const SeqWeightFunction& wf   ,
                           double minScore               , 
                           int minPos                    , 
                           int minPosPercent             )
:  FeatureFilterLink (next, owner),
   _wf (wf)
{
   //
   // scores are 'logged' so the minScore should be 'logged' too.
   _minScore = (minScore > 0)? log10 (minScore) : minScore;

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
bool GoodFeaturesFilter::add (Feature_var daFeature)
{
   if (_minScore > 0)
      if (daFeature->log2score () > _minScore)
         return false;

   if (_minPositiveSeqs > 0) {
      SeqCluster::CountSequences count;
      daFeature->cluster().performOnPositives (_wf, count);

      if (count.result () < _minPositiveSeqs)
         return false;
   }

   return _next->add (daFeature);
}


int StatFix::FDR (SeedSearcher::FeatureFilter& features, int N, double P) 
{
   debug_mustbe (features->isSorted ());
   if (features->size () <= 0)
      return 0;

   //
   // because we use scores after 'log2', we have to also 'log' N, P & K
   int K = 1;
   double LOG_P_div_N = log2 (P) - log2 ((double)N);
   //
   // first, check that the best feature is good enough, other-wise
   // there is no point in searching at all
   if (features->get (K-1).log2score ()> LOG_P_div_N + ::log ((double)K)) {
      //
      // no feature is actually good enough
      return 0;
   }

   //
   // now seek backwards the last element (with lowest score)
   // that is still good enough to face the requirements
   for (K = features->size () ; K >= 1 ; K--) {
      double featureScore = features->get (K-1).log2score ();
      double LOG_P_div_N_MUL_K = LOG_P_div_N + log2((double)K);
      if (featureScore <= LOG_P_div_N_MUL_K) {
         return K;
      }
   }

   //
   // 
   debug_mustfail ();
   return 0;
}

int StatFix::bonferroni (SeedSearcher::FeatureFilter& features, int N, double P) 
{
   debug_mustbe (features->isSorted ());
   if (features->size () <= 0)
      return 0;

   //
   // because we use scores after 'log', we have to also 'log' N, P & K

   int K= 1;
   double LOG_P_div_N = log2 (P) - log2 ((double)N);
   //
   // first, check that the best feature is good enough, other-wise
   // there is no point in searching at all
   if (features->get (K-1).log2score ()> LOG_P_div_N) {
      //
      // no feature is actually good enough
      return 0;
   }

   //
   // now seek backwards the last element (with lowest score)
   // that is still good enough to face the requirements
   for (K = features->size () ; K >= 1 ; K--) {
      if (features->get (K-1).log2score () <= LOG_P_div_N) {
         return K;
      }
   }

   //
   // 
   debug_mustfail ();
   return 0;
}












