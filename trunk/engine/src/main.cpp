//
// File        : $RCSfile: $
//               $Workfile: main.cpp $
// Version     : $Revision: 71 $
//               $Author$
//               $Date$
// Description :
//    main routine for the seed-searcher program
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
#include "main.h"
#include "Parser.h"

#include "SequenceDB.h"
#include "Assignment.h"
#include "Sequence.h"
#include "RandomProjections.h"
#include "SeedSearcher.h"
#include "pssm.h"
#include "SeedSearcherMain.h"

#include "StdOptions.h"
#include "DebugLog.h"

#include "core/AutoPtr.h"
#include "persistance/StdInputStream.h"
#include "persistance/StrOutputStream.h"
#include "persistance/xmlwriter.h"

#include "status_reporter/BaseStatusReporter.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>

using namespace std;
using namespace Persistance;
using namespace seed;


static const char buildComment [] =
	"Release notes: \n"
	"Built with gcc 4.1.2\n"
	"\n";


class OutputSummary 
{
public:
	OutputSummary (const char* outputFile)
		: _stream (outputFile), _xml (_stream)
	{
		/// write headers
		_xml << prolog ();
		_xml << tag ("resources");
	}
	void seedsOutput (const char* filename) 
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
					<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()
					<< attr ("type") << "SNAP Seeds file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	void matrixOutput (const char* filename)
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
				<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()		
				<< attr ("type") << "SNAP Matrix file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	void logOutput (const char* filename)
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
					<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()
					<< attr ("type") << "SNAP Log file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	void samplesOutput (const char* filename)
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
					<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()
					<< attr ("type") << "SNAP Samples file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	void pssmOutput (const char* filename)
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
					<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()
					<< attr ("type") << "SNAP PSSM file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	void motifsOutput (const char* filename)
	{
		if (!shouldReport (filename))
			return;

		_xml	<< tag ("resource")
					<< attr ("name") << boost::filesystem::path(filename, boost::filesystem::native).leaf ()
					<< attr ("type") << "SNAP Motifs file"
					<< tag ("field") 
						<< attr ("name") << "File"
						<< attr ("value") << filename
					<< endtag ()
				<< endtag ();
	}

	bool shouldReport (const char* filename) 
	{
		if (_files.find (filename) != _files.end ()) {
			/// we aleady reported about this file
			return false;
		}
		else {
			_files.insert (filename);
			return true;
		}
	}

private:
	std::ofstream _stream;
	Persistance::XmlStream _xml;
	
	typedef std::set <std::string> FileNameSet;
	FileNameSet _files;
};





static void printGoodbye (time_t start, time_t finish)
{
   std::string timeStr = ctime (&finish);
   //
   // remove the NEWLINE at the end of the string
   timeStr [timeStr.length () - 1] = '\0';

   DLOG << '#' << DLOG.EOL ()
      << "# summary" << DLOG.EOL ()
      << "Execution ended on " <<  timeStr.c_str ()
      << " after running " << int(finish - start) << " seconds."
      << DLOG.EOL ();
   DLOG.flush ();
}



static void welcomeMessage ()
{
   //
   // (1) write header, and execution time
   DLOG  << "SeedSearcher v"
         << main_definitions::__versionMajor << '.'
         << main_definitions:: __versionMinor;

   switch (main_definitions::__stability) {
      case main_definitions::_alpha_version_:   DLOG << " alpha build"; break;
      case main_definitions::_beta_version_:    DLOG << " beta build";  break;
      case main_definitions::_stable_version_:  DLOG << " release build"; break;
   }

   debug_only (
      DLOG << " (Debug) ";
   );

#ifdef __TIMESTAMP__
   DLOG << " Compiled on " << __TIMESTAMP__;
#endif

   DLOG << DLOG.EOL ()
        << "by Yoseph Barash (hoan@cs.huji.ac.il)" << DLOG.EOL ()
        << "and Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ()
        << DLOG.EOL ();
	DLOG << buildComment << DLOG.EOL ();
   DLOG.flush ();

}


static void welcomeMessage (const Parser& parser)
{
   time_t ltime;
   time( &ltime );
   DLOG << DLOG.EOL ()
        << "Execution started on " << ctime( &ltime ) << DLOG.EOL ();
   //
   // (2) write execution line
   DLOG  << '#' << DLOG.EOL ()
         << "# command line" << DLOG.EOL ();

   for (int i=0 ;i<parser.__argv.argc (); i++)
      DLOG << parser.__argv.argv ()[i] << ' ';
   DLOG << DLOG.EOL ();

   DLOG  << DLOG.EOL ();
   DLOG  << '#' << DLOG.EOL ()
         << "# execution parameters " << DLOG.EOL ();
   parser.logParams (DLOG);
}




static time_t cleanupStart = 0, cleanupFinish;
static time_t start = time (NULL), finish;

static void mainRoutine (int argc,
                        char* argv []);

//
// Copied/Adapted from legacy SeedSearcher
int cpp_main(int argc, char* argv [])
{
int exit_value = 0;
   try {
	   Argv anArgv;
      StatusReportManager::Sentry report( argc, argv, anArgv );

      //
      // setup basic logging
      SeedSearcherLog::setupConsoleLogging ( /* dont supress */ false);
      mainRoutine ( anArgv.argc(), anArgv.argv() );

      if (cleanupStart) {
         cleanupFinish = time(NULL);
         DLOG << int (cleanupFinish - cleanupStart) << " seconds." << DLOG.EOL ();
         DLOG.flush ();
      }

      StatusReportManager::setJobDone ();
   }
   catch (const BaseStatusReporter::CancelledException&) {
		try {
			//
			// aborted by user,
			StatusReportManager::setJobCancelled ();
		}
		catch (...) {
			cerr << endl << "StatusReportManager Error" << endl;
		}
		throw;
   }
   catch (const std::exception& x) {
      try {
			StatusReportManager::setJobError(x.what ());
      }
      catch (...) {
			cerr << endl << "StatusReportManager Error" << endl;
      }
      throw;
   }
   catch (...) {
      try {
         StatusReportManager::setJobError("Unknown Error");
      }
      catch (...) {
         cerr << endl << "StatusReportManager Error" << endl;
      }
      throw;
   }

   return exit_value;
}


class ApplicationMain : public SeedSearcherMain {
public:
	ApplicationMain (const boost::filesystem::path& outputDirectory) :
		_outputSummary ( (outputDirectory / "summary.xml").string ().c_str ())
	{
	}

protected:
   virtual void beforeSearch (Parameters& nextParameters) {
      DLOG << DLOG.EOL () << DLOG.EOL ();
      DLOG << "Performing search";
      if (!nextParameters.name ().empty ()) {
         boost::filesystem::path leaf (nextParameters.name ().getChars (), boost::filesystem::native);
         DLOG << ' ' << Str(leaf.leaf ());
      }

      DLOG << ':' << DLOG.EOL();
      DLOG.flush ();
   }
   //
   // prints results after a search 
   virtual void afterSearch (Results& results) {
      SeedSearcherMain::afterSearch (results);

      SeedSearcherMain::CmdLineParameters& params =
         *safe_cast (CmdLineParameters*, &results.getParameters ());

      Parser::OutputType gPSSM = params.parser ().__generatePSSM;
      Parser::OutputType gMotif = params.parser ().__generateMotif;
      Parser::OutputType gBayesian = params.parser ().__generateBayesian;
		Parser::OutputType gSeedlog = params.parser ().__generateSeedlog;

      //
      // should we generate a file that contains only the seeds?
      bool gSeeds =  (gMotif  != Parser::_out_none_)  ||
         (gPSSM   != Parser::_out_none_)  ||
         (gBayesian != Parser::_out_none_) ||
			(gSeedlog != Parser::_out_none_);

      if (!gSeeds)
         return;

		//
		// get features without any redundancies
      FeatureSet_ptr bestFeatures =
			SeedSearcherMain::FeatureSetManager::removeRedundancies (
				*params.bestFeatures ().getArray(), params);

      FeatureInvestigator printer ( params                     ,
                                    params.parser ().__statfix_t,
												params.parser ().__seed_o
                                    );

		/// beign or continue reporting the seeds file
      FixedStrBuffer <4096> seedsFileName;
		StrBuffer fileStub (params.name ());
      TextTableReport::TextOutput seedsFile (
         main_definitions::openFile (true, -1, fileStub, main_definitions::SEEDS_FILE_STUB, seedsFileName)
      );
      seedsFile.skipHeader ();
      seedsFile.noNewlineAfterRecord ();

		/// report the generation of this seeds files
		_outputSummary.seedsOutput (seedsFileName);


      //
      // we print the results to the log
      PositionVector pos;	pos.reserve(1024);
      PositionVector neg;	neg.reserve(1024);
      Persistance::TextTableReport::TextOutput dlog (DLOG);
		FeatureSet::Iterator feature_it = bestFeatures->getIterator();
      for (int i=0; feature_it.hasNext() ; feature_it.next(), ++i) {

         Feature& feature = *(feature_it.get ());

         //
         // first we find the positive and negative positions
         // of this feature
			reserveClear(pos);
			reserveClear(neg);
         printer.addPositions (feature, pos, neg);
         debug_mustbe (feature.cluster ().hasPositions ());

         main_definitions::printMotif (
                  params.parser ().__score_partial,
                  dlog, printer,
                  gPSSM, gMotif, gBayesian,
                  pos, neg,
                  fileStub, feature, i
         );
         dlog.writeln ();
         printSeedFile (seedsFile, printer,
			   gPSSM, gMotif, gBayesian,
			   pos, neg,
			   fileStub, feature, i
			);
      }

      printSeqMatrix (*bestFeatures, results.getParameters ());
   }

	void printSeqMatrix (FeatureSet& bestFeatures,
                            SeedSearcherMain::Parameters& parameters);

	void printSeedFile (TextTableReport::TextOutput& seedsFile,
                           FeatureInvestigator& printer,
                           Parser::OutputType gPSSM,
                           Parser::OutputType gMotif,
                           Parser::OutputType gSample,
                           PositionVector pos,
                           PositionVector neg,
                           const char* fileStub,
                           Feature& feature,
                           int index);

protected:
	OutputSummary _outputSummary;
};




const char main_definitions::MOTIF_FILE_STUB[] = "motifs";
const char main_definitions::PSSM_FILE_STUB[] = "pssm";
const char main_definitions::SAMPLE_FILE_STUB[] = "sample";
const char main_definitions::SEEDS_FILE_STUB[] = "seeds";
const char main_definitions::MATRIX_FILE_STUB[] = "matrix";

/// print the .seeds file, which lists in a user-fiendly tabular form the files
/// generated from the run of the program.
///
/// additionally, it outputs an xml-format file which lists the same information
void ApplicationMain::printSeedFile (TextTableReport::TextOutput& seedsFile,
                           FeatureInvestigator& printer,
                           Parser::OutputType gPSSM,
                           Parser::OutputType gMotif,
                           Parser::OutputType gSample,
                           PositionVector pos,
                           PositionVector neg,
                           const char* fileStub,
                           Feature& feature,
                           int index)
{
   printer.printSeed (seedsFile, feature, pos);
   Parser::OutputType outputs [3] = { gMotif, gPSSM, gSample };
   const char* names [] = { main_definitions::MOTIF_FILE_STUB,
                            main_definitions::PSSM_FILE_STUB,
                            main_definitions::SAMPLE_FILE_STUB };

   for (int i=0 ; i<3; i++) {
      if (outputs[i] != Parser::_out_none_)  {
         /// get the file name
			FixedStrBuffer <4096> filenameBuffer;
         main_definitions::getOutputFileName(filenameBuffer, true,
					     index, fileStub, names [i]);

			/// report about the file generation in the seeds file
         boost::filesystem::path leaf (filenameBuffer, boost::filesystem::native);
         seedsFile << Str (leaf.leaf ()) << '\t';

			/// report about the file generation in the summary file
			switch (i) {
				case 0:
					_outputSummary.motifsOutput (filenameBuffer);
					break;

				case 1:
					_outputSummary.pssmOutput (filenameBuffer);
					break;

				case 2:
					_outputSummary.samplesOutput (filenameBuffer);
					break;

			}
			
      }
      else {
         seedsFile << "-----" << '\t';
      }
   }

   seedsFile.writeln();
   seedsFile.flush();
}

void ApplicationMain::printSeqMatrix (FeatureSet& bestFeatures,
                            SeedSearcherMain::Parameters& parameters)
{
	/// create or continue the matrix file
	FixedStrBuffer <4096> matrixFileName;
   TextTableReport::TextOutput matrixFile (
      main_definitions::openFile (true, -1,
                                 StrBuffer (parameters.name ()),
                                 main_definitions::MATRIX_FILE_STUB,
											matrixFileName));

	/// report the generation of the matrix file
	_outputSummary.matrixOutput (matrixFileName);

   //
   // create the format of the table
   // the first column is the name of the sequence
   // the next columns are names of the motifs
   Persistance::TextTableReport::Format format;
   format.addField("Seq-Name", 13);
   FeatureSet::Iterator feature_it = bestFeatures.getIterator();
   for (; feature_it.hasNext() ; feature_it.next()) {
      std::string feature_name;
      {  Persistance::TextWriter writer (new Persistance::StrOutputStream (feature_name));
         writer << Format ((*feature_it)->assignment ());
      }
      format.addField (Str (feature_name), feature_name.length () + 1);
   }

   //
   // get the seq iterator and the weight function
   SequenceDB::SequenceIterator it = parameters.db ()->sequenceIterator ();
	boost::shared_ptr<const SeqWeightFunction> wf = parameters.wf ();

   //
   // go over all sequences
   for (; it.hasNext () ; it.next ()){
      //
      // skip non positive sequences
      const Sequence* seq = it.get ();
      if (!wf->isPositive (seq->id ()))
         continue;

      Persistance::TextTableReport::Data data (format);
      data.writeField((*it)->name ());

      //
      // go over all results
      FeatureSet::Iterator feature_it = bestFeatures.getIterator ();
      for (; feature_it.hasNext() ; feature_it.next ()) {
         Feature& feature = *(feature_it.get ());
         debug_mustbe (feature.cluster ().hasPositions ());
         PosCluster* posCluster = feature.cluster ().getPositions(*it);
         //
         //
         if (posCluster != NULL) {
            int numPositions = posCluster->size ();
            data.writeField (FixedStrBuffer <128> ("%d", numPositions));
         }
         else
            data.writeField ("0");
      }

      matrixFile << data;
   }
}








static void mainRoutine (int argc,
                        char* argv [])
{
   welcomeMessage ();

   //
   // parse the arguments
   ConfParameterIterator confParamaters (argc, argv);
   const Parser& parser = confParamaters.getInitParser ();

   //
   // write welcome message with all parameters
   welcomeMessage(parser);

   //
   // check that we have enough arguments
   // needs SeqFile RegFile and output-stub
   int numOfFileArgs = parser.getNumFileArgs ();
	if(numOfFileArgs < main_definitions::RequiredParams)
      parser.usage ("Missing arguments");

	//
	// create the parent directory of the stub
	boost::filesystem::path jobFolder (
		argv [parser.__firstFileArg + main_definitions::StubFileIndex], boost::filesystem::native);
	
	if (!jobFolder.branch_path ().empty ()) {
		if (!boost::filesystem::exists (jobFolder.branch_path ())) {
			boost::filesystem::create_directory (jobFolder.branch_path ());
		}
		else {
			mmustbe (boost::filesystem::is_directory (jobFolder.branch_path ()), "The specified stub path is not a directory");
		}
	}

   //
   // create the preprocessor and other initial data
	confParamaters.setup (  argv [parser.__firstFileArg + main_definitions::SeqFileIndex],
                           argv [parser.__firstFileArg + main_definitions::WgtFileIndex],
                           argv [parser.__firstFileArg + main_definitions::StubFileIndex]);

   //
   // this takes care of all searching and printing of seeds
	
	ApplicationMain application (jobFolder.branch_path ());
   application.search (confParamaters);

   finish = time(NULL);
   printGoodbye (start, finish);
   DLOG << DLOG.EOL () << "Cleaning up...";
   time (&cleanupStart);
}






#if 0
#if SEED_DL_MALLOC_OPTIMIZATION

#include "core/dlmalloc.h"

void* operator new (size_t inSize)
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void* operator new (size_t inSize, const std::nothrow_t&)
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void operator delete (void* inPtr)
{
   if (inPtr)
	   dlfree (inPtr);
}

void* operator new[] (size_t inSize)
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void* operator new[] (size_t inSize, const std::nothrow_t& nothrow)
{
	void* ptr = dlmalloc (inSize);
	debug_mustbe (ptr);
	return ptr;
}

void operator delete[] (void* inPtr)
{
   if (inPtr)
	   dlfree (inPtr);
}

#endif
#endif
