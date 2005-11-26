#ifndef _SeedSearcher_SeedSearcherMain_h
#define _SeedSearcher_SeedSearcherMain_h

#include "Defs.h"

#include "Parser.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedSearcher.h"
#include "RandomProjections.h"


class SeedSearcherMain {
public:
   class Parameters;
   class CmdLineParameters;
   
   class Results {
      //
      // convienience class.
      // encapsulates results obtained from seed searching.
      // all the functionality implemented here could be easily replicated
      // by going over the features in the 'BestFeatures' container
      // and querying the preprocessor about those features.
      // please use the 'FeatureInvestigator' class to print or query
      // individual features
   public:
      Results (Parameters&, int);
      ~Results ();

      //
      // returns the number of seeds considered during the search
      int numSeedsSearched () const {
         return _numSearched;
      }

      //
      // returns the number of features discovered
      int numFeatures () const {
         return _numFound;
      }

      //
      // feature iteration interface
      bool hasMoreFeatures () const {
         return _index < _params.bestFeatures ().size ();
      }
      void nextFeature () {
         _index++;
      }
      //
      // go to the first feature (used to reset iteration)
      void firstFeature () {
         _index = 0;
      }

      //
      // return the index of the current feature
      int featureIndex () const {
         return _index;
      }

      //
      // get the current feature in the iteration
      const Feature& getFeature () const {
         return _params.bestFeatures ().get (_index);
      }
      Feature& getFeature () {
         return _params.bestFeatures ().get (_index);
      }

      //
      // used to retrieve preprocessed data about feature
//      void (Preprocessor::NodeCluster&) const

   protected:
      int _index;
      int _numFound;
      int _numSearched;
      Parameters& _params;
   };

public:
   SeedSearcherMain (Parameters& in) : _params (in) {
   }
   virtual ~SeedSearcherMain () {
   }

   virtual void beforeSearch (int /* search handle */,
                              int /* total seeds found */,                        
                              const Assignment&
                              );

   virtual void afterSearch (int /* search handle */,
                              int /* total seeds found */,                        
                              const Assignment&
                              ); 

   //
   //
   void setupLogging (bool supressConsole);
   void setupFileLogging (const Str& filename, bool supressConsole);

   //
   // use search parameters to perform actual seed searching!
   // returns the number of seeds found
   AutoPtr <Results> search ();

public:
   //
   //
   class Parameters : public SeedSearcher::SearchParameters {
   public:
      Parameters () {
      }
      virtual ~Parameters () {
      }
      //
      // returns the Sequence DB
      const SequenceDB& db () const {
         return *_db;
      }
      //
      // returns the randome projections for the search
      const RandomProjections& projections () const {
         return *_projections;
      }
      //
      // return the search type
      SearchType searchType () const {
         return _searchType;
      }
      PrepType prepType () const {
         return _prepType;
      }
      bool useReverse () const {
         return _useReverse;
      }

   protected:
      AutoPtr <SequenceDB> _db;
      AutoPtr <RandomProjections> _projections;
      SearchType _searchType;
      PrepType _prepType;
      bool _useReverse;

   private:
      Parameters (const Parameters&);
   };

   class CmdLineParameters : public Parameters {
   public:
      CmdLineParameters () {
      }
      CmdLineParameters (int argc, char** argv) {
         _parser.parse (argc, argv);
      }
      ~CmdLineParameters () {
      }

      //
      //
      void interpret (int argc, char** argv) {
         _parser.parse (argc, argv);
      }

      //
      // call these functions to explicitly set 
      void setupLogFilename (const Str&);
      void setupSeqFilename (const Str&);
      void setupWgtFilename (const Str&);
      
      //
      // call this function to initialize the parameters, 
      // after the appropriate options have been set 
      void setup ();

      virtual void setupParameters ();
      virtual void setupLangauge ();
      virtual void setupProjections ();
      virtual void setupDB ();
      virtual void setupFeatureContainer ();
      virtual void setupScoreFunc ();
      virtual void setupPreprocessor ();
      virtual void setupWeightFunction ();

      const Parser& parser () const {
         return _parser;
      }
      
   protected:
      Parser _parser;
      StrBuffer _logFilename;
      StrBuffer _seqFilename;
      StrBuffer _wgtFilename;

   private:
      CmdLineParameters (const CmdLineParameters&);
   };

   //
   //
   struct PreprocessorFactory {
      //
      //
      static Preprocessor* createPreprocessor (
               PrepType,
               const SequenceDB&,
               const SeqWeightFunction&,
               const Langauge&,
               int featureLength,
               bool useReverse,
               bool removeNegatives = false
            );
   };

protected:
   Parameters& _params;
   int _lastTotalNumOfSeedsFound;
   time_t searchStart, searchFinish;
};

#endif
