//
// File        : $RCSfile: $ 
//               $Workfile: Feature.cpp $
// Version     : $Revision: 19 $ 
//               $Author: Aviad $
//               $Date: 4/11/04 17:51 $ 
// Description :
//    Concrete cache for Hyper-Geometric distribution values
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


#include "Feature.h"

#include "Preprocessor.h"
#include "AssignmentFormat.h"
#include "Sequence.h"
#include "PSSM.h"

#include "legacy/MathFunctions.h"
#include "ExtraMath.h"

#include "persistance/TextWriter.h"
#include "core/Str.h"

USING_TYPE (Persistance, TextWriter);

FeatureInvestigator::FeatureInvestigator (const FeatureParameters& in, 
                                          int outputLength)
  :   _outputLength (outputLength),
      _allignment (outputLength, '-'),
      _parameters (in)
{
}

FeatureInvestigator::FeatureInvestigator (const FeatureParameters& in, 
                                          int outputLength,
                                          int numSeeds,
                                          int numProjections)
:  _outputLength (outputLength),
   _allignment (outputLength, '-'),
   _parameters (in), 
   _numSeedsSearched (numSeeds),
   _numProjections (numProjections)
{
   if (_numSeedsSearched > 0) {
      //
      // we use the average number of seeds found on a projection
      _log10_seedsSearched = 
         ::log10 (static_cast <double> (_numSeedsSearched / _numProjections));
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
   // use the positions in the cluster if they are available
   if (feature.cluster ().hasPositions ()) {
      //
      // it is assumed that if it has any positions, then
      // it contains all relevant positions
      SeqCluster::AddPositions pos(outPositives);
      SeqCluster::AddPositions neg(outNegatives);
      feature.cluster ().performDivided(_parameters.wf (), pos, neg);
   }
   else {
      Preprocessor::NodeCluster motifNodes;
      _parameters.preprocessor ().add2Cluster ( motifNodes, 
                                                feature.assignment ());
      
      motifNodes.positions (  _parameters.wf (), 
                              outPositives, 
                              outNegatives);
   }
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
   StrBuffer buf(_outputLength);
   int middleSection = 
      position.getSeedString (
                           buf, 
                           motifLength,
                           _outputLength
                           );

   writer << buf.substring (0, middleSection) << ' '
          << buf.substring (middleSection, middleSection + motifLength) << ' '
          << buf.substring (middleSection + motifLength);
 
   //
   // write seq id and name
   writer << '\t' << position.sequence ()->id () 
          << '\t' << position.sequence ()->name ();
   
   //
   // TODO: what does [iYML101C 13 70088 70624 TSL1] [0.0000] mean?
   
   //
   // output sequence weight 
   writer << "\t[" << position.sequence ()->weight () << ']';
   
   //
   // output the position index
   writer << '\t' << position.position ();
   
   //
   // print +/- if it is on normal/reverse strand
   writer << '\t' << (position.strand ()? '+' : '-');
   writer.writeln ();
}


void FeatureInvestigator::printSeedScore (
                                 TextWriter& writer, 
                                 Feature& feature, 
                                 const PositionVector& 
                                 )
{
  static const double LOG2_10 = log2 (static_cast <double> (10));
   double log10_of_score = (feature.log2score ()) / LOG2_10;

   //
   // print bonf correction
   if (_numSeedsSearched > 0) {
      //
      // log10 (score * K) = log10 (score) + log10 (K)
      double bonfScore = log10_of_score + _log10_seedsSearched;
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
      feature.scoreFunction ().writeAsText (writer, feature.scoreParameters ());
      writer << ']';
   }

   //
   // print projection details if available
   if (feature.projection ()) {
      writer << '\t' << _parameters.langauge ().format (*feature.projection ());
   }
}

void FeatureInvestigator::createPSSM (Feature& feature_i, 
                                      const PositionVector& positions, 
                                      PSSM& outPSSM)
{
   const int seed_length = feature_i.assignment ().length ();

   outPSSM = PSSM (  
            _parameters.langauge ().code (), 
		      seed_length,
		      _outputLength,
            positions,
            _parameters.wf ());
}
   

void FeatureInvestigator::printPSSM (  Persistance::TextWriter& writer,
                                       Feature& feature_i, 
                                       const PSSM& pssm)
{
   int size = pssm.length ();          
   int cardinality = _parameters.langauge ().cardinality ();    
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

void FeatureInvestigator::printBayesian (
   Persistance::TextWriter& writer, Feature& feature, 
   const PositionVector& positions)
{
   const int motifLength = feature.assignment ().length ();

   CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next())   {
      const SeqPosition& position = *(*it);

      StrBuffer buf;
      USELESS (int middleSection = )
         position.getSeedString (buf, motifLength, _outputLength, '?');

      writer << '{';

      int length = buf.length();
      for (int i=0 ; i<length ; i++) {
         writer << buf [i] << ' ';
      }

      writer << '}';
      writer.writeln ();
   }
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
         double score,
         boost::shared_ptr <ScoreFunction> sf)
:  _assg(assg), _complement (NULL), _projection (projection),
   _params (params), _cluster (cluster), _score (score),
   _sf (sf)
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

   _sf.reset ();
}
