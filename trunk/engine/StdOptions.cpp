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
 * The IUPAC Code is a set of symbols encoding each subset of the four nucleotides. Here is the complete list of these symbols together with the subsets they encode. 
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
   __acgt ['a'] = __acgt ['A'] = 0;
   __acgt ['c'] = __acgt ['C'] = 1;
   __acgt ['g'] = __acgt ['G'] = 2;
   __acgt ['t'] = __acgt ['T'] = 3;
   __acgt ['n'] = __acgt ['N'] = 4; // AlphabetCode::dunnoCode;
}

const AlphabetCode& ACGTAlphabet::get (bool cardinalityIncludesN)
{
   if (cardinalityIncludesN) {
      if (!__ACGTN.valid ()) {
         initACGTCode ();
         __ACGTN = new AlphabetCode (__acgt, cardinality ());
      }

      return *__ACGTN;
   }
   else {
      if (!__ACGT.valid ()) {
         initACGTCode ();
         __ACGT = new AlphabetCode (__acgt, assgCardinality ());
      }

      return *__ACGT;
   }
}

void ACGTWriter::write(const Assignment::Position& pos,
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
   else if (c == ACGTAlphabet::assgCardinality ()) {
      if (pos.strategy ()== Assignment::together)
         writer << '?';
      else
         writer << '*';
   }
   else {
      char iupac;
      unsigned long code = pos.toULong ();
      switch (code) {
         case 0x1:   // A - Adenine 
            iupac = 'A';
            break;
         case 0x2:   // C - Cytosine 
            iupac = 'C';
            break;
         case 0x4:   // G - Guanine 
            iupac = 'G';
            break;
         case 0x8:   // T - Thymine 
            iupac = 'T';
            break;
         case (0x4 + 0x1): // R [GA] purine 
            iupac = 'R';
            break;
         case (0x8 + 0x2): // Y [TC] Pyrimidine 
            iupac = 'Y';
            break;
         case (0x4 + 0x8): // K [GT] Keto 
            iupac = 'K';
            break;
         case (0x1 + 0x2): // M [AC] Amino 
            iupac = 'M';
            break;
         case (0x4 + 0x2): // S [GC] ? 
            iupac = 'S';
            break;
         case (0x1 + 0x8): // W [AT] ? 
            iupac = 'W';
            break;
         case (0x4 + 0x8 + 0x2): // B [GTC] ? 
            iupac = 'B';
            break;
         case (0x4 + 0x1 + 0x8): // D [GAT] ? 
            iupac = 'D';
            break;
         case (0x1 + 0x2 + 0x8): // H [ACT] ? 
            iupac = 'H';
            break;
         case (0x4 + 0x2 + 0x1): // V [GCA] ? 
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







//
// KBestFeatures
//

KBestFeatures::KBestFeatures (int k, int maxRedundancyOffset)
: _k (k), _size (0), _maxRedundancyOffset (maxRedundancyOffset)
{
   debug_mustbe (_k > 0);
   debug_mustbe (_maxRedundancyOffset>=0);
   _features = new SeedSearcher::Feature [_k];
}

KBestFeatures::~KBestFeatures ()
{
   for (int i=0 ; i<_size ; i++)
      _features [i].dispose ();

   delete [] _features;
}

static bool checkSimilarity (int offset,
                             const Assignment& a, 
                             const Assignment& b)
{
   //
   // TODO: what happens when assignments have different lengths?
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

   debug_only (
      DLOG << "Assignments are redundant (offset " 
           << offset 
           << ") " 
           << Format (a)
           << ' ' 
           << Format (b)
           << DLOG.EOL ();
      )

   //
   // they have a common base assignment, so they are similar
   // TODO: is this actually correct behavior?
   return true;
}

static bool checkRedundancy (int maxOffset, const Assignment& a, const Assignment& b)
{
   debug_only (
      DLOG << "Comparing: "
           << Format (a)
           << ' ' 
           << Format (b)
           << DLOG.EOL ();
   );

   debug_mustbe (maxOffset >= 0);
   debug_mustbe (maxOffset < a.length ());
   debug_mustbe (a.length () == b.length ());   

   //
   // for offset 0 checking similarity between (a,b) or (b,a) is the same
   if (checkSimilarity (0, a, b))
      return true;

   //
   // TODO: is there a better/faster way to do this?
   for (int offset=1 ; offset <= maxOffset ; offset++) {
      if (checkSimilarity (offset, a, b) || checkSimilarity (offset, b, a))
         return true;
   }

   return false;
}

//
// takes ownership of Assignment & Cluster
bool KBestFeatures::add (SeedSearcher::Feature_var daFeature)
{
   _sorted = false;

   //
   // we have to check if the assg is similar enough to some 
   // other in the array 
   int worst = 0;
   double worstScore = _features [0]._score;
   for (int i=0 ; i < _size ; i++) {
      //
      // we dont allow 'duplicates' in our features
      if (checkRedundancy (_maxRedundancyOffset,
                           *_features [i]._assg, 
                           *daFeature->_assg)               ) {
         //
         // the smaller the score, the better.
         if (_features [i]._score > daFeature->_score) {
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
      if (_features [i]._score > worstScore) {
         worstScore = _features [i]._score;
         worst = i;
      }
   }

   if (_size < _k) {
      //
      // there is room in the array, so just stick it somewhere
      _features [_size++] = *(daFeature.release ());
      return true;
   }
   else if (worstScore > daFeature->_score) {
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

struct FeatureComparator{
   //
   // put the best scores first
   bool operator () (const SeedSearcher::Feature& a, const SeedSearcher::Feature& b) {
      return a._score < b._score;
   }
};

void KBestFeatures::sort ()
{
   std::sort (_features, _features + _size, FeatureComparator ());
   _sorted = true;
}




//
// GoodFeatures
//

GoodFeatures::GoodFeatures (
                           SeedSearcher::BestFeatures* next, 
                           bool owner                    ,
                           const SeqCluster& db          ,
                           const SeqWeightFunction& wf   ,
                           double minScore               , 
                           int minPos                    , 
                           int minPosPercent             )
:  BestFeaturesLink (next, owner),
   _wf (wf)
{
   //
   // scores are 'logged' so the minScore should be 'logged' too.
   _minScore = log (minScore);

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
bool GoodFeatures::add (SeedSearcher::Feature_var daFeature)
{
   if (daFeature->_score > _minScore)
      return false;

   if (_minPositiveSeqs > 0) {
      SeqCluster::CountSequences count;
      daFeature->_cluster->performOnPositives (_wf, count);

      if (count.result () < _minPositiveSeqs)
         return false;
   }

   return _next->add (daFeature);
}


int StatFix::FDR (SeedSearcher::BestFeatures& features, int N, double P) 
{
   debug_mustbe (features.isSorted ());
   if (features.size () <= 0)
      return 0;

   //
   // because we use scores after 'log', we have to also 'log' N, P & K
   int K = 1;
   double LOG_P_div_N = ::log (P) - ::log (N);
   //
   // first, check that the best feature is good enough, other-wise
   // there is no point in searching at all
   if (features.get (K-1)._score > LOG_P_div_N + ::log (K)) {
      //
      // no feature is actually good enough
      return 0;
   }

   //
   // now seek backwards the last element (with lowest score)
   // that is still good enough to face the requirements
   for (K = features.size () ; K >= 1 ; K--) {
      double featureScore = features.get (K-1)._score;
      double LOG_P_div_N_MUL_K = LOG_P_div_N + ::log(K);
      if (featureScore <= LOG_P_div_N_MUL_K) {
         return K;
      }
   }

   //
   // 
   debug_mustfail ();
   return 0;
}

int StatFix::bonferroni (SeedSearcher::BestFeatures& features, int N, double P) 
{
   debug_mustbe (features.isSorted ());
   if (features.size () <= 0)
      return 0;

   //
   // because we use scores after 'log', we have to also 'log' N, P & K

   int K= 1;
   double LOG_P_div_N = ::log (P) - ::log (N);
   //
   // first, check that the best feature is good enough, other-wise
   // there is no point in searching at all
   if (features.get (K-1)._score > LOG_P_div_N) {
      //
      // no feature is actually good enough
      return 0;
   }

   //
   // now seek backwards the last element (with lowest score)
   // that is still good enough to face the requirements
   for (K = features.size () ; K >= 1 ; K--) {
      if (features.get (K-1)._score <= LOG_P_div_N) {
         return K;
      }
   }

   //
   // 
   debug_mustfail ();
   return 0;
}











