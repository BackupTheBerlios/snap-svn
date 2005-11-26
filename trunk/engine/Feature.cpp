#include "Feature.h"

#include "Preprocessor.h"
#include "AssignmentFormat.h"
#include "Sequence.h"
#include "PSSM.h"

#include "Legacy/MathFunctions.h"
#include "ExtraMath.h"

#include "Persistance/TextWriter.h"
#include "Core/Str.h"

USING_TYPE (Persistance, TextWriter);

FeatureInvestigator::FeatureInvestigator (const Parameters& in, 
                                          int outputLength)
  :   _outputLength (outputLength),
      _allignment (outputLength, '-'),
      _parameters (in)
{
}

FeatureInvestigator::FeatureInvestigator (const Parameters& in, 
                                          int outputLength,
                                          int numSeeds)
:  _outputLength (outputLength),
   _allignment (outputLength, '-'),
   _parameters (in), 
   _seedsSearched (numSeeds)
{
   if (_seedsSearched > 0) {
      log10_seedsSearched = ::log10 (_seedsSearched);
   }
}

inline static int getMotifLeftOffset (int motifLen, int seedLen)
{
   const int leftPaddingLength = 
      tmax ((motifLen - seedLen) / 2, 0);

   return leftPaddingLength;
}

//
// adds the positive positions of the feature to the position vector
void FeatureInvestigator::addPositions (
                           Feature& feature, 
                           PositionVector& outPositives,
                           PositionVector& outNegatives)
{
   //
   // TODO: use the positions in the cluster if they are available
   Preprocessor::NodeCluster motifNodes;
   _parameters.preprocessor ().add2Cluster ( motifNodes, 
                                             feature.assignment ());

   PositionVector posPositions;
   PositionVector negPositions;
   motifNodes.positions (  _parameters.wf (), 
                           outPositives, 
                           outNegatives);
}


void FeatureInvestigator::printMotif (  
                           TextWriter& writer,
                           Feature& feature, 
                           const PositionVector& positions)
{
   CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next ()) {
      printMotifPosition (writer, feature, *(*it));
   }
}

void FeatureInvestigator::printMotifPosition (    
                     Persistance::TextWriter& writer,
                     Feature& feature, 
                     const SeqPosition& position)
{
   int motifLength = feature.assignment ().length ();
   StrBuffer buf;
   int middleSection = 
      position.getSeedString (
                           buf, 
                           motifLength,
                           _outputLength
                           );

   writer << buf.substring (0, middleSection) << ' '
          << buf.substring (middleSection, motifLength) << ' '
          << buf.substring (middleSection + motifLength);
 
   //
   // write seq id and name
   writer << '\t' << position.sequence ()->id () 
          << '\t' << position.sequence ()->name ();
   
   //
   // TODO: what does [iYML101C 13 70088 70624 TSL1] [0.0000] mean?
   
   //
   // output sequence weight 
   debug_mustbe (position.sequence ()->hasWeight ());
   writer << " [" << position.sequence ()->weight () << ']';
   
   //
   // output the position index
   writer << '\t' << position.position ();
   
   //
   // TODO: print +/- if it is on normal/reverse strand
   writer.writeln ();
}


void FeatureInvestigator::printSeedScore (
                                 TextWriter& writer, 
                                 Feature& feature, 
                                 const PositionVector& 
                                 )
{
   static const double LOG2_10 = ::log2 (10);
   double log10_of_score = (feature.score ()) / LOG2_10;

   //
   // print bonf correction
   if (_seedsSearched > 0) {
      //
      // log10 (score * K) = log10 (score) + log10 (K)
      double bonfScore = log10_of_score + log10_seedsSearched;
      writer   << (- bonfScore)
               << '\t';
   }
  
   writer << (- log10_of_score);
}

void FeatureInvestigator::printSeed (Persistance::TextWriter& writer, 
                                     Feature& feature, 
                                     const PositionVector& positions)
{
   printSeedScore (writer, feature, positions);

   //
   // print the assignment
   writer   << '\t'
            << _parameters.langauge ().format (feature.assignment ());

   //
   // print score params if available
   if (feature.scoreParameters ()) {
      writer << "\t[";
      _parameters.score ().writeAsText (writer, feature.scoreParameters ());
      writer << ']';
   }

   //
   // print projection details if available
   if (feature.projection ()) {
      writer << '\t' << _parameters.langauge ().format (*feature.projection ());
   }

   writer << writer.EOL ();
}

void FeatureInvestigator::createPSSM (Feature& feature_i, 
                                      const PositionVector& positions, 
                                      PSSM& outPSSM)
{
   const int seed_length = feature_i.assignment ().length ();
   const int offset = getMotifLeftOffset (_outputLength, seed_length);

   outPSSM = PSSM (  _parameters.langauge ().code (), 
                     offset, 
                     _outputLength, 
                     positions,
                     _parameters.wf ());
}
   

void FeatureInvestigator::printPSSM (  Persistance::TextWriter& writer,
                                       Feature& feature_i, 
                                       const PSSM& pssm)
{
   int size = pssm.length ();          
   int cardinality = _parameters.langauge ().code ().cardinality ();    
   debug_mustbe (cardinality > 0);
   for (int j=0 ; j<cardinality ; j++) {
      //
      // write the first position
      writer << pssm [0][j];

      //
      // write all other positions with a prepending '\t'
      for (int i=1 ; i<size ; i++) {
         writer << "\t\t\t" << pssm [i][j];
      }

      //
      //
      writer.writeln ();
   }

   writer.flush ();
}




//
// Feature
Feature::Feature () 
  :  _assg (NULL), _projection (0), 
   _params (0), _cluster (NULL), _score (0) 
{
}

Feature::Feature (Assignment* assg, 
         SequenceDB::Cluster* cluster,
         const Assignment* projection,
         ScoreParameters* params,
         double score)
:  _assg(assg), _complement (NULL), _projection (projection),
   _params (params), _cluster (cluster), _score (score) 
{
}

void Feature::dispose () {
   debug_only (
      //
      // guard against repetitive calls to delete
      debug_mustbe (_score != 0xBAADF00D);
      _score = 0xBAADF00D;
      debug_mustbe (_score == 0xBAADF00D);
   );

   delete _assg;     _assg = NULL;
   delete _cluster;  _cluster = NULL;
   delete _complement;  _complement = NULL;
   if (_params) {
      _params->dispose ();
      _params = NULL;
   }
}
