//
// File        : $RCSfile: $ 
//               $Workfile: Feature.cpp $
// Version     : $Revision: 26 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:45 $ 
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

   //
   // motif position format
   _motifPositionFormat.addField("Actual-Data", outputLength + 4);
   _motifPositionFormat.addField("Seq-ID", 7);
   _motifPositionFormat.addField("Seq-Name", 13);
   _motifPositionFormat.addField("Seq-Weight", 15);
   _motifPositionFormat.addField("TSS-Start-Offset");
   _motifPositionFormat.addField("TSS-End-Offset");
   _motifPositionFormat.addField("Strand");

   //
   // seed format
   if (_numSeedsSearched > 0) {
      _seedFormat.addField ("Bonf(-log10)", 14);
   }
   _seedFormat.addField ("Score(-log10)", 14);
   _seedFormat.addField ("Seed", outputLength);
   _seedFormat.addField ("Parameters", 30);
   _seedFormat.addField ("Projection", outputLength);
   _seedFormat.addField ("Bonf-corrected for");
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
   if (!feature.cluster ().hasPositions ()) {
      //
      // it is assumed that if it has any positions, then
      // it contains all relevant positions
      Preprocessor::NodeCluster motifNodes;
      _parameters.preprocessor ().add2Cluster ( motifNodes, 
                                                feature.assignment ());

      motifNodes.add2SeqClusterPositions (feature.cluster ());
   }

   SeqCluster::AddPositions pos(outPositives);
   SeqCluster::AddPositions neg(outNegatives);
   feature.cluster ().performDivided(_parameters.wf (), pos, neg);
}

void FeatureInvestigator::printMotif (  
                           Persistance::TextTableReport::Output& writer,
                           Feature& feature, 
                           const PositionVector& positions)
{
   CPositionIterator it (positions.begin (), positions.end ());
   for (; it.hasNext () ; it.next ()) {
      printMotifPosition (writer, feature, *(*it));
   }
}

void FeatureInvestigator::printMotifPosition (    
                     Persistance::TextTableReport::Output& out,
                     Feature& feature, 
                     const SeqPosition& position)
{
   Persistance::TextTableReport::Data data (_motifPositionFormat);

   const int motifLength = feature.assignment ().length ();
   StrBuffer buf(_outputLength);
   int middleSection = 
      position.getSeedString (
                           buf, 
                           motifLength,
                           _outputLength
                           );

   int fieldIndex = Persistance::TextTableReport::firstFieldIndex;
   Persistance::TextWriter writer (data.getOutputStream (fieldIndex++));
   writer << buf.substring (0, middleSection) << ' '
          << buf.substring (middleSection, middleSection + motifLength) << ' '
          << buf.substring (middleSection + motifLength);
 
   //
   // write seq id 
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << position.sequence ()->id (); 

   //
   // write seq name
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << position.sequence ()->name ();
   
   //
   // output sequence weight 
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << '[' << _parameters.wf ().weight (position.sequence ()->id ()) << ']';
   
   //
   // output the position information:
   // we write the position from the TSS, that is:
   // the offset from the POSITIVE strand,
   // regardless to what strand the motif resides on
   //
   // for positions on the pos strand, it is equuiv to the position ().
   // for positions on negative strand it is:
   //          
   //       98765|432|10
   //       TTTTT|TGC|TT   <--
   // -->   AAAAA|ACG|AA
   //       01234|567|89
   // 
   // CGT-positions:       2-->5
   // CGT-tssPositions (): 5-->8 = (10 - 2 - 3) --> (10 - 2)
   writer.setStream(data.getOutputStream(fieldIndex++));
   int tssPosition = position.tssPosition (motifLength);
   writer << tssPosition;
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << tssPosition + motifLength;
   
   //
   // print +/- if it is on normal/reverse strand
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << (position.strand ()? '+' : '-');
   writer.setStream(NULL);

   out << data;
}


void FeatureInvestigator::printSeed (Persistance::TextTableReport::Output& out, 
                                     Feature& feature, 
                                     const PositionVector& positions)
{
   int currentField = Persistance::TextTableReport::firstFieldIndex;
   Persistance::TextTableReport::Data data (_seedFormat);


   static const double LOG2_10 = log2 (static_cast <double> (10));

   //
   // print bonfferoni correction
   TextWriter writer (NULL);
   if (_numSeedsSearched > 0) {
      writer.setStream (data.getOutputStream(currentField++));
      //
      // 
      double log10_of_bonfScore = feature.log2bonfScore () / LOG2_10;
      writer << (- log10_of_bonfScore);
   }
   double log10_of_score = (feature.log2score ()) / LOG2_10;
   writer.setStream (data.getOutputStream(currentField++));
   writer << (- log10_of_score);

   //
   // print the assignment
   writer.setStream (data.getOutputStream(currentField++));
   writer << _parameters.langauge ().format (feature.assignment ());

   //
   // print score params if available
   writer.setStream (data.getOutputStream(currentField++));
   if (feature.scoreParameters ()) {
      writer << '[';
      feature.scoreFunction ().writeAsText (writer, feature.scoreParameters ());
      writer << ']';
   }

   //
   // print projection details if available
   writer.setStream (data.getOutputStream(currentField++));
   if (feature.projection ()) {
      writer << _parameters.langauge ().format (*feature.projection ());
   }

   //
   // print how many seeds counted for bonf correction, if available
   writer.setStream (data.getOutputStream(currentField++));
   if (feature.numSeedsSearched () > 0) {
      writer << feature.numSeedsSearched();
   }

   writer.setStream (NULL);
   out << data;
}

void FeatureInvestigator::createPSSM (PositionWeightType positionWeightType,
                                      Feature& feature_i, 
                                      const PositionVector& positions, 
                                      PSSM& outPSSM)
{
   const int seed_length = feature_i.assignment ().length ();

   outPSSM = PSSM (
            positionWeightType,
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
   int prevWidth = writer.width ();
   writer.width(writer.precision() + 3);
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
         writer << "\t" << pssm [i][j];
      }

      //
      //
      writer.writeln ();
   }

   writer.flush ();
   writer.width(prevWidth);
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
  :  _assg (NULL), _complement (NULL), _projection (0), 
   _params (0), _cluster (NULL), _score (0), _bonfScore (0), _numSeedSearched (0) 
{
}

void Feature::set (Assignment* assg, 
         SequenceDB::Cluster* cluster,
         const Assignment* projection,
         ScoreParameters* params,
         double score,
         int seedsSearched,
         boost::shared_ptr <ScoreFunction> sf)
{
   _assg = assg;
   _complement = NULL;
   _projection = projection;
   _params = params;
   _cluster = cluster;
   _score = score;
   _sf = sf;

   numSeedsSearched (seedsSearched);
}

//
// also sets the bonf score
void Feature::numSeedsSearched (int in)
{
   _numSeedSearched = in;

   //
   // compute bonferroni corrected scores:
   if (_numSeedSearched > 0)  {
      //
      // log2 (score * K) = log2 (score) + log2 (K)
      _bonfScore = _score + log2 (_numSeedSearched);
   }
   else {
      _bonfScore = _score;
   }

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
