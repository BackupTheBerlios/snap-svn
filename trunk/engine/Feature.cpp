#include "Feature.h"

#include "Preprocessor.h"
#include "AssignmentFormat.h"
#include "Sequence.h"
#include "PSSM.h"

#include "Legacy/MathFunctions.h"
#include "ExtraMath.h"

#include "Persistance/TextWriter.h"

USING_TYPE (Persistance, TextWriter);

FeatureInvestigator::FeatureInvestigator (const Parameters& in, 
                                          int outputLength)
:  _outputLength (outputLength), _parameters (in), 
   _allignment (outputLength, '-')
{
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
   //
   // write the motif: LeftPadding Seed RightPadding
   
   //
   // left padding
   const int leftPaddingLength = 
      getMotifLeftOffset (_outputLength, feature.assignment ().length ());

   if (leftPaddingLength > 0) {
      Str leftPad = 
	   position.getDataString (-leftPaddingLength, leftPaddingLength);
      writer.write ( _allignment.c_str (), 
                     leftPaddingLength - leftPad.length ());

      writer.write (leftPad);
   }
   
   //
   // separate left padding from seed
   writer << ' ';
   
   //
   // write the actual seed
   const int seedLength = 
     tmin (_outputLength - 2 * leftPaddingLength, feature.assignment ().length ());

   Str motif = position.getSeedString (seedLength);
   writer << motif;

   //
   // separate right padding from seed
   writer << ' ';

   //
   // right padding
   const int rightPaddingPosition =
     _outputLength - seedLength - leftPaddingLength;
   const int rightPaddingLength =  rightPaddingPosition;
   if (rightPaddingLength > 0) {
      Str rightPad = 
	      position.getDataString (rightPaddingPosition, rightPaddingLength);

      writer.write (rightPad);
      writer.write ( _allignment.c_str (), 
		               rightPaddingLength - rightPad.length ());
   }
  
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
   static const double Log_2_10 = ::log2 (10);
   double log_10_of_score = (feature.score ()) / Log_2_10;
   
   writer << (- log_10_of_score);
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