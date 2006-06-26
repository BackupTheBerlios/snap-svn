#ifndef _SeedSearcher_Feature_h
#define _SeedSearcher_Feature_h

//
// File        : $RCSfile: $ 
//               $Workfile: Feature.h $
// Version     : $Revision: 22 $ 
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


#include "Defs.h"
#include "Cluster.h"
#include "Sequence.h"
#include "AssignmentFormat.h"
#include "PSSM.h"
#include "DebugLog.h"
#include "Preprocessor.h"

#include "Score.h"
#include "persistance/Defs.h"
#include "persistance/TextTableReport.h"
#include "core/AutoPtr.h"

#include "boost/shared_ptr.hpp"

class Feature;
class FeatureParameters;
class FeatureInvestigator;

//
//
class Feature {
   //
   // 
public:
   Feature ();
   Feature (Assignment* assg, 
            SeqCluster* cluster,
            const Assignment* projection,
				boost::shared_ptr <Scores::Score> score,
				boost::shared_ptr <FeatureParameters> parameters) {
      set (assg, cluster, projection, score, parameters);
   }
   ~Feature () {
      dispose ();
   }
   void dispose ();
   void set (  Assignment* assg, 
					SeqCluster* cluster,
					const Assignment* projection,
					Scores::Score_ptr score,
					boost::shared_ptr <FeatureParameters> parameters);

	inline double log2score () const {
		return _score->log2Score ();
	}
	inline Scores::Score_ptr score () const {
	   return _score;
   }
	inline void score (Scores::Score_ptr score) {
	   _score = score;
   }
   inline const Assignment& assignment () const {
	   return *_assg;
   }
   inline SeqCluster& cluster () {
      debug_mustbe (_cluster);
      return *_cluster;
   }
	/// returns the SeqCluster which contains the sequences that hold this feature
	/// Remark: This SeqCluster may or may not be populated with PosClusters
   inline const SeqCluster& cluster () const {
      debug_mustbe (_cluster);
	   return *_cluster;
   }
	/// returns the SeqCluster which contains the sequences that hold this feature
	/// if 'fillInPosCluster' is true, the SeqCluster is guranteed to be populated with PosClusters
	const SeqCluster& cluster (bool fillInPosCluster);
   inline const Assignment* projection () const {
	   return _projection;
   }
   inline const Assignment* complement () {
      return _complement;
   }

   const Assignment& complement (const Langauge& langauge) {
      if (!_complement) {
         debug_mustbe (_assg);
         _complement = new Assignment ();
         langauge.complement (*_assg, *_complement);
      }

#     if 0
         DLOG << "Reverse of "   << Format (*_assg) 
              << " is "          << Format (*_complement)
              << DLOG.EOL ();
         DLOG.flush();
#     endif

      return *_complement;
   }

protected:
   Assignment* _assg;
   Assignment* _complement;
   const Assignment* _projection;
   SeqCluster* _cluster;
   boost::shared_ptr <Scores::Score> _score;
	boost::shared_ptr <FeatureParameters> _parameters;
};
//
// CORBA notation used here... :-)
typedef Feature* Feature_ptr;
typedef boost::shared_ptr <Feature> Feature_var;

//
//
class FeatureParameters {
public:
   FeatureParameters () {
   }
   virtual ~FeatureParameters () {
   }
   FeatureParameters (const FeatureParameters& in) {
      set (in);
   }
   FeatureParameters& operator = (const FeatureParameters& in) {
      set (in);
      return *this;
   }
   void set (const FeatureParameters & in) {
      _preprocessor = in._preprocessor;
      _langauge =in._langauge;
      _score = in._score;
      _wf = in._wf;
   }

   //
   // which sequences are positively labeled
   void wf (boost::shared_ptr <SeqWeightFunction>& wf) {
      _wf = wf;
   }
   const SeqWeightFunction& wf () const {
      return *_wf;
   }
   //
   // preprocessed data to search over
   void preprocessor (boost::shared_ptr <Preprocessor>& prep) {
      _preprocessor = prep;
   }
   const Preprocessor& preprocessor () const {
      return *_preprocessor;
   }
   //
   // how to score features
	void score (Scores::Function_ptr score) {
      _score = score;
   }
   const Scores::Function_ptr score () const {
      return _score;
   }
   //
   // returns the langauge to work with
	void langauge (boost::shared_ptr <Langauge>& lang) {
      _langauge = lang;
   }
   const Langauge& langauge () const {
      return *_langauge;
   }
   static Feature& createFeature (
									boost::shared_ptr <FeatureParameters> params,
									Feature& out,
                           Assignment* assg, 
                           SeqCluster* cluster,
                           const Assignment* projection,
                           int numSeedsSearched = 0)
   {
		Scores::Score_ptr score = 
         params->_score->score (
                     *assg,         // the assignment
                     *projection,    // the projection,
                     *cluster      // sequences containing the feature
                  );

      out.set( // the feature's assignment 
               assg,
               // sequences containing the feature  
               cluster,
               projection,
               score,
					params);

      return out;
   }


   static Feature& createFeature (
									boost::shared_ptr <FeatureParameters> params,
									Feature& out,
                           Assignment const& assg, 
                           Assignment const& proj) 
   {
      Preprocessor::NodeCluster nodes;
      params->_preprocessor->add2Cluster (nodes, assg);

      SeqCluster* cluster = new SeqCluster;
      nodes.add2SeqClusterPositions (*cluster);

      return createFeature (params,
               out,
               new Assignment (assg),
               cluster,
               new Assignment (proj));
   }

	static boost::shared_ptr <Feature> createFeature (
									boost::shared_ptr <FeatureParameters> params,
									Assignment const& assg, 
                           Assignment const& proj) {
		boost::shared_ptr <Feature> feature (new Feature);
      createFeature (params, *feature, assg, proj);
      return feature;
   }


protected:
   boost::shared_ptr <SeqWeightFunction> _wf;
   boost::shared_ptr <Preprocessor> _preprocessor;
   Scores::Function_ptr _score;
   boost::shared_ptr <Langauge> _langauge;
};

class FeatureInvestigator {
   //
   //
public:
   FeatureInvestigator (const FeatureParameters&, 
								StatFixType statfixType,
                        int outputLength);
   virtual ~FeatureInvestigator () {
   }

   //
   // this is usually the first method to call,
   // because all other methods require the PositionVectors created
   // by this methods.
   //
   // adds the pos positions of the feature to the positive position vector
   // adds the neg positions of the feature to the negative position vector
   virtual void addPositions (   Feature&, 
                                 PositionVector& outPositives,
                                 PositionVector& outNegatives);

   //
   // prints a single position 
   virtual void printMotifPosition (   Persistance::TextTableReport::Output&      , 
                                       Feature&                      ,
                                       const SeqPosition& position   );
   //
   // prints all positions of a feature
   virtual void printMotif (  Persistance::TextTableReport::Output&   ,
                              Feature&                   , 
                              const PositionVector&      );

   virtual void printSeed (   Persistance::TextTableReport::Output&, 
                              Feature&                , 
                              const PositionVector&   );

   //
   // creates a PSSM from a feature
   virtual void createPSSM (  PositionWeightType   ,
                              Feature&             , 
                              const PositionVector&, 
                              PSSM&                );
   //
   // prints a PSSM
   virtual void printPSSM (Persistance::TextWriter&, 
                           Feature&, 
                           const PSSM&);

   //
   // creates and prints a PSSM for a feature
   virtual void printPSSM (PositionWeightType positionWeightType,
                           Persistance::TextWriter& writer, 
                           Feature& feature,
                           const PositionVector& pos) {
      PSSM pssm;
      createPSSM (positionWeightType, feature, pos, pssm);
      printPSSM (writer, feature, pssm);
   }
   virtual void printBayesian (Persistance::TextWriter& , 
                               Feature&, const PositionVector& );

protected:
   int _outputLength;
   std::string _allignment;
   const FeatureParameters& _parameters;

   Persistance::TextTableReport::Format _motifPositionFormat;
   Persistance::TextTableReport::Format _seedFormat;
};



#endif
