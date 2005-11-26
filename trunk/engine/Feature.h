#ifndef _SeedSearcher_Feature_h
#define _SeedSearcher_Feature_h

#include "Defs.h"
#include "Cluster.h"
#include "Sequence.h"
#include "AssignmentFormat.h"
#include "PSSM.h"
#include "DebugLog.h"
#include "Preprocessor.h"

#include "Persistance/Defs.h"
#include "Core/AutoPtr.h"

#include "boost/shared_ptr.hpp"



//
// this class is used to test the correctness of SeedSearcher.
// the score function, by recording the score parameters
// for a feature, used for later printing.
struct ScoreParameters {
   virtual ~ScoreParameters () {
   }
   virtual void dispose () {
      delete this;
   }
};

//
// this class represents a scoring scheme for features
//
// IMPORTANT:
// the smaller (more negative) the score, the better.
// score MUST be in log2 format.
class ScoreFunction {
public:
   virtual ~ScoreFunction () {
   }

   //
   // if 'parameters' is NULL, do not return ScoreParameters.
   virtual double log2score (  const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           ScoreParameters** parameters
                           ) const = 0;

   //
   // print the score parameters 
   virtual void writeAsText ( Persistance::TextWriter&, 
                              const ScoreParameters*  ) const = 0;
};



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
            ScoreParameters* params,
            double score);
   inline ~Feature () {
   }
   void dispose ();

   inline double log2score () const {
	   return _score;
   }
   void log2score (double in) {
      _score = in;
   }
   inline const Assignment& assignment () const {
	   return *_assg;
   }
   inline const SeqCluster& cluster () const {
	   return *_cluster;
   }
   inline const ScoreParameters* scoreParameters () const {
	   return _params;
   }
   inline const Assignment* projection () const {
	   return _projection;
   }
   inline const Assignment* complement () {
      return _complement;
   }

   const Assignment& complement (const Langauge& langauge) {
      if (_complement)
         return *_complement;

      debug_mustbe (_assg);
      _complement = new Assignment ();
      langauge.complement (*_assg, *_complement);

#     if 0
         DLOG << "Reverse of "   << Format (*_assg) 
              << " is "          << Format (*_complement)
              << DLOG.EOL ();
#     endif

      return *_complement;
   }

   struct Owner {
	   inline static void acquire(Feature*) {
	   }
 	   inline static void release(Feature* ptr) {
 		   if (ptr) ptr->dispose ();
 	   }
   };

protected:
   Assignment* _assg;
   Assignment* _complement;
   const Assignment* _projection;
   ScoreParameters* _params;
   SeqCluster* _cluster;
   double _score;
};
//
// CORBA notation used here... :-)
typedef Feature* Feature_ptr;
typedef AutoPtr <Feature, Feature::Owner> Feature_var;

//
//



class FeatureInvestigator {
public:
   //
   //
   class Parameters {
   public:
      Parameters () {
      }
      virtual ~Parameters () {
      }
      Parameters (const Parameters& in) {
         set (in);
      }
      Parameters& operator = (const Parameters& in) {
         set (in);
         return *this;
      }
      void set (const Parameters & in) {
         _preprocessor = in._preprocessor;
         _langauge =in._langauge;
         _score = in._score;
         _wf = in._wf;
      }

      //
      // which sequences are positively labeled
      void wf (SeqWeightFunction* wf) {
         _wf.reset (wf);
      }
      const SeqWeightFunction& wf () const {
         return *_wf;
      }
      //
      // preprocessed data to search over
      void preprocessor (Preprocessor* prep) {
         _preprocessor.reset (prep);
      }
      const Preprocessor& preprocessor () const {
         return *_preprocessor;
      }
      //
      // how to score features
      void score (ScoreFunction* score) {
         _score.reset (score);
      }
      const ScoreFunction& score () const {
         return *_score;
      }
      //
      // returns the langauge to work with
      void langauge (Langauge* lang) {
         _langauge.reset (lang);
      }
      const Langauge& langauge () const {
         return *_langauge;
      }

      Feature* createFeature (Assignment const& assg, 
                              Assignment const& proj) {
         Preprocessor::NodeCluster nodes;
         _preprocessor->add2Cluster (nodes, assg);

         SeqCluster* cluster = new SeqCluster;
         nodes.add2SeqClusterPositions (*cluster);

         ScoreParameters* scoreParams = NULL;
         double featureScore = _score->log2score (  assg, 
                                                proj, 
                                                *cluster, 
                                                &scoreParams);

         return new Feature ( new Assignment (assg), 
                              cluster,
                              new Assignment (proj),
                              scoreParams,
                              featureScore);
      }


   protected:
      boost::shared_ptr <SeqWeightFunction> _wf;
      boost::shared_ptr <Preprocessor> _preprocessor;
      boost::shared_ptr <ScoreFunction> _score;
      boost::shared_ptr <Langauge> _langauge;
   };

   //
   //
public:
   FeatureInvestigator (const Parameters&, 
                        int outputLength);
   //
   // use to enable bonferroni
   FeatureInvestigator (const Parameters&, 
                        int outputLength,
                        int seedsSearched);
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
   virtual void printMotifPosition (   Persistance::TextWriter&      , 
                                       Feature&                      ,
                                       const SeqPosition& position   );
   //
   // prints all positions of a feature
   virtual void printMotif (  Persistance::TextWriter&   ,
                              Feature&                   , 
                              const PositionVector&      );

   //
   // prints a result line for a feature
   virtual void printSeedScore ( Persistance::TextWriter&, 
                                 Feature&                , 
                                 const PositionVector&   );
   virtual void printSeed (   Persistance::TextWriter&, 
                              Feature&                , 
                              const PositionVector&   );
   
   virtual void printSeedHeader (Persistance::TextWriter& out) {
      if (_seedsSearched) {
         out << "Bonf(-log10)\t";
      }
      out << "Score(-log10)\tSeed\t\tParameters\t\t\tProjection" << out.EOL ();
   }

   //
   // creates a PSSM from a feature
   virtual void createPSSM (  Feature&             , 
                              const PositionVector&, 
                              PSSM&                );
   //
   // prints a PSSM
   virtual void printPSSM (Persistance::TextWriter&, 
                           Feature&, 
                           const PSSM&);

   //
   // creates and prints a PSSM for a feature
   virtual void printPSSM (Persistance::TextWriter& writer, 
                           Feature& feature,
                           const PositionVector& pos) {
      PSSM pssm;
      createPSSM (feature, pos, pssm);
      printPSSM (writer, feature, pssm);
   }

protected:
   int _outputLength;
   std::string _allignment;
   const Parameters& _parameters;
   int _seedsSearched;
   double log10_seedsSearched;
};



#endif
