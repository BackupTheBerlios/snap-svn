#ifndef _SeedSearcher_SeedSearcherMain_h
#define _SeedSearcher_SeedSearcherMain_h

//
// File        : $RCSfile: $ 
//               $Workfile: SeedSearcherMain.h $
// Version     : $Revision: 17 $ 
//               $Author: Aviad $
//               $Date: 10/12/04 21:09 $ 
// Description :
//    Concrete and interface classes for seting-up 
//    a seed-searching environment or program
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

#include "Parser.h"
#include "Sequence.h"
#include "Cluster.h"
#include "SeedSearcher.h"
#include "RandomProjections.h"

#include "boost/shared_ptr.hpp"


class SeedSearcherMain {
public:
   class Results;
   class Parameters;
   class CmdLineParameters;
   struct PreprocessorFactory;

   class ParameterIterator {
   public:
      virtual ~ParameterIterator () {
      }

      virtual bool hasNext () = 0;
      virtual boost::shared_ptr <Parameters> get () = 0;
      virtual void next () = 0;
   };


public:
   SeedSearcherMain ();
   virtual ~SeedSearcherMain () {
   }

   //
   // is called from search before performing new search 
   virtual void beforeSearch (Parameters& nextParameters) {
   }

   //
   // is called from search before performing new search 
   virtual void beforeProjection (int /* search handle */,
                              int /* total seeds found */,                        
                              const Assignment&
                              );

   virtual void afterProjection (int /* search handle */,
                              int /* total seeds found */,                        
                              const Assignment&
                              ); 

   virtual void afterSearch (Results&) {
   }

   //
   // use search parameters to perform actual seed searching!
   // returns the number of seeds found
   AutoPtr <Results> search (boost::shared_ptr <Parameters> in);

   //
   // conduct multiple searches using multiple parameters
   void search (ParameterIterator&);

protected:
//   boost::shared_ptr <Parameters> _params;
   int _lastTotalNumOfSeedsFound;
   time_t searchStart, searchFinish;
};



//
//
class SeedSearcherMain::Parameters : public SeedSearcher::SearchParameters {
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

      _name = in._name;
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
   const ProjectionGenerator& projections () const {
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
   const Str& name () const {
      return _name;
   }

protected:
   //
   // the (optional) name for these settings
   StrBuffer _name;
   //
   // the data to be searched
   boost::shared_ptr <SequenceDB> _db;
   //
   // the projections 
   boost::shared_ptr <ProjectionGenerator> _projections;
   //
   // search type table/tree
   SearchType _searchType;
   //
   // type of preprocessor to generate
   PrepType _prepType;
   //
   //
   bool _useReverse;
};




//
//
class SeedSearcherMain::Results {
   //
   // convienience class.
   // encapsulates results obtained from seed searching.
   // all the functionality implemented here could be easily replicated
   // by going over the features in the 'FeatureFilter' container
   // and querying the preprocessor about those features.
   // please use the 'FeatureInvestigator' class to print or query
   // individual features
public:
   Results (boost::shared_ptr <Parameters>, int);
   ~Results ();

   //
   // returns the number of seeds considered during the search
   int numSeedsSearched () const {
      return _numSearched;
   }
   //
   // returns the number of projections searched
   int numProjectionsSearched () const {
      return _params->projections ().numOfProjections ();
   }

   //
   // get the current feature in the iteration
   const FeatureSet& getFeatures () const {
      return _params->bestFeatures ().getArray ();
   }
   FeatureSet& getFeatures () {
      return _params->bestFeatures ().getArray ();
   }
   //
   // returns the (optional) search name associated with this search
   const Str& getSearchName () const {
      return _params->name ();
   }
   Parameters& getParameters () {
      return *_params;
   }

protected:
   int _numFound;
   int _numSearched;
   boost::shared_ptr <Parameters> _params;
};



//
//
class SeedSearcherMain::CmdLineParameters : public SeedSearcherMain::Parameters {
   //
   // Concrete implementation of SeedSearcherMain::Parameters
   // builds parameters from command-line arguments
public:
   CmdLineParameters () {
   }
   CmdLineParameters (int argc, char** argv) {
      _parser.parse (argc, argv);
   }
   CmdLineParameters (const Parser& inParser) : _parser (inParser) {
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
   void secondarySetup (const Parser&);

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
   void setName (const Str& in) {
      _name = in;
   }
   
protected:
   Parser _parser;
   StrBuffer _seqFilename;
   StrBuffer _wgtFilename;
};


//
// creates a preprocessor according to parameters
struct SeedSearcherMain::PreprocessorFactory {
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

#include "SeedConf.h"
#include "core/ImplList.h"

class ConfParameterIterator : public SeedSearcherMain::ParameterIterator {
public:
   ConfParameterIterator (int argc, char* argv []);
   virtual ~ConfParameterIterator ();

   //
   // get the initiale arguments parser
   const Parser& getInitParser () const {
      return _optList.getInitParser ();
   }

   //
   // call this function to initialize the parameters, 
   // after the appropriate options have been set 
   void setup (const Str& seqFilename, 
               const Str& wgtFilename,
               const Str& stubBasicName);

   virtual bool hasNext ();
   virtual boost::shared_ptr <SeedSearcherMain::Parameters> get ();
   virtual void next ();

   typedef boost::shared_ptr <SeedSearcherMain::CmdLineParameters> Param_var;
   typedef Impl1WayDataNode <Param_var> ParamNode;

private:
   StrBuffer _stub;
   SeedConfList _optList;
   SeedConfList::OptionIterator _it;
   ImplCyclicList <ParamNode> _list;
   bool _useInitParameters;
   bool _updated;
};

#endif
