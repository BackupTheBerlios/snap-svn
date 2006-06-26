#include "../main.h"

#include "../core/Defs.h"
#include "../SeedSearcherMain.h"
#include "../SeedSearcher.h"
#include "../DebugLog.h"



using namespace std;

const char main_definitions::MOTIF_FILE_STUB[] = "motifs";
const char main_definitions::PSSM_FILE_STUB[] = "pssm";
const char main_definitions::SAMPLE_FILE_STUB[] = "sample";
const char main_definitions::SEEDS_FILE_STUB[] = "seeds";

static void welcomeMessage ()
{
   //
   // (1) write header, and execution time
   DLOG  << "MotifCalc v" 
         << main_definitions::__versionMajor << '.' 
         << main_definitions::__versionMinor;
   debug_only (
      DLOG << " (Debug)";
   );
#ifdef __TIMESTAMP__
   DLOG << " Compiled on " << __TIMESTAMP__;
#endif

   DLOG << DLOG.EOL ();
   DLOG << "By Aviad Rozenhek (aviadr@cs.huji.ac.il) " << DLOG.EOL ();
   DLOG.flush ();
}

//
// [options] <seq_file> <wgt_file> <motif> [stub]
int cpp_main (int argc, char* argv [])
{
   SeedSearcherLog::setupConsoleLogging (false);
   welcomeMessage ();

   //
   // parse paramters
   SeedSearcherMain::CmdLineParameters params (argc, argv);

   //
   // print usage if too little parameters
   if (params.parser ().getNumFileArgs () < 3) {
      printf ("Usage: %s [options] <seqfile> <wgtfile> <motif>\n\n", argv [0]);
      printf ("Motif is a string of [ACGT?] like AC??CAG?A\n");
      printf ("Options are the same as SNAP's:\n");
      params.parser ()._impl.usage (DLOG, params.parser ().getOptions ());
      exit (0);
   }

   Str motif_str (argv [params.parser ().__firstFileArg + 2]);

   //
   // setup parameters
   SeedSearcherLog::setupConsoleLogging (true);
   params.parser ().__seed_l = motif_str.length ();
   params.setup ( argv [params.parser ().__firstFileArg],
                  argv [params.parser ().__firstFileArg +1]
                );

   //
   // create the motif assignment
   Assignment motif;
   params.langauge ().stringToAssignment (motif, motif_str);
   
   //
   // we want to know where is the motif located
   AutoPtr <Feature> feature = params.createFeature (motif, motif);

   //
   // setup the output of the motif
   SeedSearcherLog::setupConsoleLogging (false);
   FeatureInvestigator printer ( params,
                                 params.parser ().__seed_o  ,
                                 false                      ,
                                 0                          );
   //
   // get locations of motif
   PositionVector pos, neg;
   printer.addPositions(*feature, pos, neg);

   //
   // print score
   printer.printSeedHeader(DLOG);
   printer.printSeed(DLOG, *feature, pos);
   DLOG.writeln();
   DLOG.flush ();

   Parser::OutputType gPSSM = params.parser ().__generatePSSM;
   Parser::OutputType gMotif = params.parser ().__generateMotif;
   Parser::OutputType gBayesian = params.parser ().__generateBayesian;

   if (params.parser ().getNumFileArgs () >= 4) {
      //
      // the fourth parameter is a stub for PSSM, motif & sample output 
      main_definitions::printMotif (printer, gPSSM, gMotif, gBayesian,
                                    pos, neg, 
                                    argv [params.parser ().__firstFileArg +3],
                                    *feature, -1
                                    );
   }

   return 0;
}
