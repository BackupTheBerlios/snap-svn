//
// File        : $RCSfile: $ 
//               $Workfile: Feature.cpp $
// Version     : $Revision: 32 $ 
//               $Author: Aviad $
//               $Date: 13/05/05 11:08 $ 
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
														StatFixType statfixType,
                                          int outputLength)
:  _outputLength (outputLength),
   _allignment (outputLength, '-'),
   _parameters (in)
{
   //
   // motif position format
   _motifPositionFormat.addField("Actual-Data", outputLength + 4);
   _motifPositionFormat.addField("Seq-ID");
   _motifPositionFormat.addField("Seq-Name", 200, 40, /* dont put newlines */ false);
   _motifPositionFormat.addField("Seq-Weight", 40, 12, /* dont put newlines */ false);
   _motifPositionFormat.addField("TSS-Start-Offset");
   _motifPositionFormat.addField("TSS-End-Offset");
   _motifPositionFormat.addField("Strand");
	_motifPositionFormat.addField("Seq-Len");

   //
   // seed format
	switch (statfixType) {
		default: mustfail ();
		case _statfix_bonf_: _seedFormat.addField ("Bonf(-log10)", 14); break;
		case _statfix_fdr_: _seedFormat.addField ("FDR(-log10)", 14); break;
		case _statfix_none_: 
			;
	}

   _seedFormat.addField ("Score(-log10)", 14);
   _seedFormat.addField ("Seed", outputLength);
   _seedFormat.addField ("Parameters", 100, 60, false);
   _seedFormat.addField ("Projection", outputLength);
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
   feature.cluster ().performDivided(*_parameters.wf (), pos, neg);
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
   writer << '[' << _parameters.wf ()->weight (position.sequence ()->id ()) << ']';
   
   //
   // output the position information:
   // we write the position from the TSS, that is:
	// the upstream offset from the gene
	// the promoter is assumed to be on the same strand as the gene
	// and read in the same direction as the gene.
	// this means that the 'reverse' strand is the strand that DOES not
	// have the gene.
   //
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
	writer << tssPosition + (position.strand ()? motifLength : - motifLength);
   
   //
   // print +/- if it is on normal/reverse strand
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << (position.strand ()? '+' : '-');

	//
	// print the sequence length
   writer.setStream(data.getOutputStream(fieldIndex++));
   writer << position.sequence ()->length ();

   writer.setStream(NULL);
   out << data;
}


void FeatureInvestigator::printSeed (Persistance::TextTableReport::Output& out, 
                                     Feature& feature, 
                                     const PositionVector& positions)
{
   int currentField = Persistance::TextTableReport::firstFieldIndex;
   Persistance::TextTableReport::Data data (_seedFormat);

   TextWriter writer (NULL);

	//
	// print all scores
	Scores::Score_ptr score = feature.score ();
	while (score) {
      writer.setStream (data.getOutputStream(currentField++));
      writer << (- score->log10Score ());
		score = score->next ();
	}

   //
   // print the assignment
   writer.setStream (data.getOutputStream(currentField++));
   writer << _parameters.langauge ().format (feature.assignment ());

   //
   // print score params if available
   writer.setStream (data.getOutputStream(currentField++));
	feature.score ()->writeAsText (writer);

	/*
   if (feature.scoreParameters ()) {
      writer << '[';
      feature.scoreFunction ().writeAsText (writer, feature.scoreParameters ());
      writer << ']';
   }*/

   //
   // print projection details if available
   writer.setStream (data.getOutputStream(currentField++));
   if (feature.projection ()) {
      writer << _parameters.langauge ().format (*feature.projection ());
   }
/*
   //
   // print how many seeds counted for bonf correction, if available
   writer.setStream (data.getOutputStream(currentField++));
   if (feature.numSeedsSearched () > 0) {
      writer << feature.numSeedsSearched();
   }
*/

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
            *_parameters.wf ());
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

      writer << '(';

      int length = buf.length();
      for (int i=0 ; i<length ; i++) {
         writer << buf [i] << ' ';
      }

      writer << ')';
      writer.writeln ();
   }
}





//
// Feature
Feature::Feature () 
  :  _assg (NULL), _complement (NULL), _projection (0), _cluster (NULL)
{
}

void Feature::set (Assignment* assg, 
         SequenceDB::Cluster* cluster,
         const Assignment* projection,
			Scores::Score_ptr score,
			boost::shared_ptr <FeatureParameters> parameters)
{
   _assg = assg;
   _complement = NULL;
   _projection = projection;
   _cluster = cluster;
   _score = score;
	_parameters = parameters;
}


void Feature::dispose () {
   delete _assg;     _assg = NULL;
   delete _cluster;  _cluster = NULL;
   
	delete _complement;  _complement = NULL;
}

const SeqCluster& Feature::cluster(bool fillInPosCluster) 
{
	debug_mustbe (_cluster);
	if (fillInPosCluster) {
	//
		// use the positions in the cluster if they are available
		if (!_cluster->hasPositions ()) {
			//
			// it is assumed that if it has any positions, then
			// it contains all relevant positions
			Preprocessor::NodeCluster motifNodes;
			_parameters->preprocessor ().add2Cluster ( motifNodes, 
																	assignment ());

			motifNodes.add2SeqClusterPositions (*_cluster);
		}
		debug_mustbe (_cluster->hasPositions ());
	}
   return *_cluster;
}
