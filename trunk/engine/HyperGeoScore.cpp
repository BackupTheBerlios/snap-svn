#include "HyperGeoScore.h"

HyperGeoScore::HyperGeoScore (const SequenceDB::Cluster& positivelyLabeled,// m
                              const SequenceDB& allSequences // n
               )
:  _allSequences (allSequences),
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

   return _cache->logTail (positiveContaining.size (), containingFeature.size ());
}


