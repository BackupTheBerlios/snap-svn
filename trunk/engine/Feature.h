#ifndef _SeedSearcher_Feature_h
#define _SeedSearcher_Feature_h

#include "Defs.h"
#include "Cluster.h"
#include "Sequence.h"
#include "AssignmentFormat.h"
#include "PSSM.h"

#include "Persistance/Defs.h"
#include "Core/AutoPtr.h"



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
   virtual double score (  const Assignment& feature,
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

   inline double score () const {
	   return _score;
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

      //
      // which sequences are positively labeled
      void wf (SeqWeightFunction* wf) {
         _wf = wf;
      }
      const SeqWeightFunction& wf () const {
         return *_wf;
      }
      //
      // preprocessed data to search over
      void preprocessor (Preprocessor* prep) {
         _preprocessor = prep;
      }
      const Preprocessor& preprocessor () const {
         return *_preprocessor;
      }
      //
      // how to score features
      void score (ScoreFunction* score) {
         _score = score;
      }
      const ScoreFunction& score () const {
         return *_score;
      }
      //
      // returns the langauge to work with
      void langauge (Langauge* lang) {
         _langauge = lang;
      }
      const Langauge& langauge () const {
         return *_langauge;
      }

   protected:
      AutoPtr <SeqWeightFunction> _wf;
      AutoPtr <Preprocessor> _preprocessor;
      AutoPtr <ScoreFunction> _score;
      AutoPtr <Langauge> _langauge;

   private:
      Parameters (const Parameters&) {
      }
   };

   //
   //
public:
   FeatureInvestigator (const Parameters&, int outputLength);
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
};



#endif