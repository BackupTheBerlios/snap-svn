#include "StdOptions.h"

#include "Persistance/TextWriter.h"
#include "DebugLog.h"


using namespace std;

static AlphabetCode::Code __acgt;
static AutoPtr <AlphabetCode> __ACGT;



HyperGeoScore::HyperGeoScore (bool countWeights,
                              const SequenceDB::Cluster& positivelyLabeled,// n
                              const SequenceDB& allSequences // m
               )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (positivelyLabeled)
{
   _cache = new HyperGeoCache (positivelyLabeled.size (), allSequences.size ());
}


double HyperGeoScore::score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature// k
                     )
{
   //
   // TODO: mustbe some easier way...
   SequenceDB::Cluster positiveContaining;
   SequenceDB::Cluster::intersect ( _positivelyLabeled,
                                    containingFeature,
                                    positiveContaining);
   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      double posWeightCount = positiveContaining.sumWeights (_allSequences);
      posCount = ROUND (posWeightCount);

      double containingWeightCount = containingFeature.sumWeights (_allSequences);
      containingCount = ROUND (containingWeightCount);
   }
   else {
      posCount = positiveContaining.size();
      containingCount = containingFeature.size();
   }

   double score = 
        _cache->logTail (posCount, containingCount);
                            
    //
    // because with p-values the *smaller* the better
    // we return the negation of the score (which for good features is probably negative)
    return -score;
}






const AlphabetCode& ACGTAlphabet::get ()
{
   if (!__ACGT.valid ()) {
      AlphabetCode::copy (__acgt, AlphabetCode::emptyCode ());
      __acgt ['a'] = __acgt ['A'] = 0;
      __acgt ['c'] = __acgt ['C'] = 1;
      __acgt ['g'] = __acgt ['G'] = 2;
      __acgt ['t'] = __acgt ['T'] = 3;
      __acgt ['n'] = __acgt ['N'] = 4; // AlphabetCode::dunnoCode;

      __ACGT = new AlphabetCode (__acgt, 5);
   }

   return *__ACGT;
}

void ACGTWriter::write(const Assignment::Position& pos,
                                      Persistance::TextWriter& writer) 
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
      Assignment::PositionIterator it (pos);
      writer << '{';
      for (; it.hasNext () ; it.next ())
         writer << ACGT [it.get ()];

      writer << '}';
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
bool KBestFeatures::add (
                  AutoPtr <Assignment> assg,
                  AutoPtr <SequenceDB::Cluster> cluster,
                  double score)
{
   //
   // we have to check if the assg is similar enough to some 
   // other in the array 
   int worst = 0;
   double worstScore = _features [0]._score;
   for (int i=0 ; i < _size ; i++) {
      if (checkRedundancy (_maxRedundancyOffset,
                           *_features [i]._assg, 
                           *assg)               ) {
         //
         // TODO: the bigger the score, the better. right?
         if (_features [i]._score <  score) {
            //
            // replace this similar feature with a better one
            _features [i] = SeedSearcher::Feature (assg.release (), 
                                   cluster.release (),
                                   score);
            return true;
         }

         //
         // search for the worst feature in the array
         if (_features [i]._score < worstScore) {
            worstScore = _features [i]._score;
            worst = i;
         }
      }
   }

   if (_size < _k) {
      //
      // there is room in the array, so just stick it somewhere
      _features [_size++] = SeedSearcher::Feature (assg.release (), 
                                   cluster.release (),
                                   score);
      return true;
   }
   else if (worstScore < score) {
      debug_mustbe (_size == _k);
      //
      // we have no room in the array, so we have to replace
      // the worst feature
      _features [worst] = SeedSearcher::Feature (assg.release (), 
                                   cluster.release (),
                                   score);
      return true;
   }

   //
   // didnt add the feature, delete the memory (we are owners)
   return false;
}




//
// GoodFeatures
//

GoodFeatures::GoodFeatures (SeedSearcher::BestFeatures* next, 
                                          const SequenceDB::Cluster& posSeqs,
                                          double minScore, 
                                          int minPos, 
                                          bool isPercent)
:  BestFeaturesLink (next),
   _minScore (minScore),
   _posSeqs (posSeqs)
{
   if (isPercent) {
      debug_mustbe (minPos >= 0);
      debug_mustbe (minPos <= 100);
      _minPositiveSeqs = (_posSeqs.size () * minPos) / 100;
   }
   else {
      _minPositiveSeqs = minPos;
   }
}

GoodFeatures::GoodFeatures (SeedSearcher::BestFeatures* next, 
                                          const SequenceDB::Cluster& posSeqs,
                                          double minScore, 
                                          int minPos, 
                                          int minPosPercent)
:  BestFeaturesLink (next),
   _minScore (minScore),
   _posSeqs (posSeqs)
{
   debug_mustbe (minPos >= 0);
   debug_mustbe (minPosPercent >= 0);
   debug_mustbe (minPosPercent <= 100);

   int threshold = 
      max (minPos, _posSeqs.size () * minPosPercent / 100);

   _minPositiveSeqs = threshold;
}

//
// takes ownership of Assignment & Cluster
bool GoodFeatures::add (
                  AutoPtr <Assignment> assg,
                  AutoPtr <SequenceDB::Cluster> cluster,
                  double score)
{
   if (score < _minScore)
      return false;

   if (_minPositiveSeqs > 0) {
      //
      // TODO: is this taking a lot of time???
      SequenceDB::Cluster posContainingCluster;
      SequenceDB::Cluster::intersect (*cluster, _posSeqs, posContainingCluster);

      if (posContainingCluster.size () < _minPositiveSeqs)
         return false;
   }

   return _next->add (assg, cluster, score);
}


