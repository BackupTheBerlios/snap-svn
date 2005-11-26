#ifndef _SeedSearcher_SeedSearcherMain_h
#define _SeedSearcher_SeedSearcherMain_h

#include "Defs.h"

#include "Parser.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedSearcher.h"
#include "RandomProjections.h"

#include "boost/shared_ptr.hpp"


class SeedSearcherMain {
public:
   class Parameters;
   class CmdLineParameters;
   
   class Results {
      //
      // convienience class.
      // encapsulates results obtained from seed searching.
      // all the functionality implemented here could be easily replicated
      // by going over the features in the 'FeatureFilter' container
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
         return _index < _numFound;
      }
      void nextFeature () {
         _index++;
      }
      //
      // go to the first feature (used to reset iteration)
      void firstFeature () {
         _index = 0;
      }
      void lastFeature () {
         _index = _numFound - 1;
      }

      //
      // return the index of the current feature
      int featureIndex () const {
         return _index;
      }

      //
      // get the current feature in the iteration
      const Feature& getFeature () const {
         return _params.bestFeatures ()->get (_index);
      }
      Feature& getFeature () {
         return _params.bestFeatures ()->get (_index);
      }

      //
      // used to retrieve preprocessed data about feature
      // void (Preprocessor::NodeCluster&) const

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
      Parameters (const Parameters& in) {
         set (in);
      }
      Parameters& operator = (const Parameters& in) {
         set (in);
         return *this;
      }
      void set (const Parameters& in) {
         this->SearchParameters::set (in);

         _db = in._db;
         _projections = in._projections;
         _searchType = in._searchType;
         _prepType = in._prepType;
         _useReverse = in._useReverse;
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
      boost::shared_ptr <SequenceDB> _db;
      boost::shared_ptr <RandomProjections> _projections;
      SearchType _searchType;
      PrepType _prepType;
      bool _useReverse;
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
      CmdLineParameters (const CmdLineParameters& in) {
         set (in);
      }
      CmdLineParameters& operator = (const CmdLineParameters& in) {
         set (in);
         return *this;
      }
      void set (const CmdLineParameters& in) {
         this->Parameters::set (in);

         _parser = in._parser;
         _seqFilename = in._seqFilename;;
         _wgtFilename = in._wgtFilename;
      }

     
      //
      // call this function to initialize the parameters, 
      // after the appropriate options have been set 
      void setup (const Str& seqFilename, const Str& wgtFilename);
      //
      // call this function if parameters have already been initialized
      // and you want a second seed-searcher run with different parameters.
      //
      // unchanged parameters: 
      //    Preprocessor, Langauge, FeatureContainer, DB, WeightFunction
      //
      // Changable parameters:
      //    ScoreFunctions, Projections, SearchParameters
      void secondarySetup (int argc, char** argv);

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
      Parser& parser () {
         return _parser;
      }
      
   protected:
      Parser _parser;
      StrBuffer _seqFilename;
      StrBuffer _wgtFilename;
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
