#ifndef __SeedSearcher_main_h
#define __SeedSearcher_main_h

#include "Feature.h"
#include "Parser.h"

#include "persistance/TextWriter.h"
#include "persistance/StdOutputStream.h"

#include <fstream>

struct main_definitions {
   enum {
      _alpha_version_,
      _beta_version_,
      _stable_version_,

      __versionMajor = 2,
      __versionMinor = 3321,
      __stability = _alpha_version_
   };

   //
   //
   struct MainError : public BaseException {
      MainError (std::string const & s) : BaseException (s) {
      }
      ~MainError () throw () {
      }
   };

   //
   // Copied/Adapted from legacy SeedSearcher
   static void Err(std::string const & s) {
      throw MainError (s);
   }

   static Persistance::OutputStream* openFile (const char* filename)
   {
      std::ofstream* file = new std::ofstream (filename,
         std::ios::out | std::ios::trunc | std::ios::binary);

      if( ! file->is_open() )
         Err(std::string("Cannot open file for ") + filename);

      return new Persistance::StdOutputStream (file, true);
   }



   static const char* getOutputFileName (char* motifFileName,
      bool isPositives,
      int index,
      const char* fileStub,
      const char* typeStub)
   {
      if (index >= 0) {
         if (isPositives)
            sprintf (motifFileName, "%s.%d.%s",
            fileStub, (index+1), typeStub);
         else
            sprintf (motifFileName, "%s.%d.neg.%s",
            fileStub, (index+1), typeStub);
      }
      else {
         if (isPositives)
            sprintf (motifFileName, "%s.%s",
            fileStub, typeStub);
         else
            sprintf (motifFileName, "%s.neg.%s",
            fileStub, typeStub);
      }

      return motifFileName;
   }

   //
   //
   static Persistance::OutputStream* openFile (
      bool isPositives,
      int index,
      const char* fileStub,
      const char* typeStub)
   {
      //
      // create the motif file name
      char motifFileName [1024];
      return openFile (
         getOutputFileName (motifFileName, isPositives, index, fileStub, typeStub)
         );
   }

   static const char MOTIF_FILE_STUB[];   // = "motifs";
   static const char PSSM_FILE_STUB[];    // = "pssm";
   static const char SAMPLE_FILE_STUB[];  // = "sample";
   static const char SEEDS_FILE_STUB[];   // = "seeds";
   static const char MATRIX_FILE_STUB[];  // = "matrix";
   

   //
   //
   static void printMotif (PositionWeightType positionWeightType,
      Persistance::TextTableReport::Output& out,
      FeatureInvestigator& printer,
      Parser::OutputType gPSSM,
      Parser::OutputType gMotif,
      Parser::OutputType gSample,
      PositionVector pos,
      PositionVector neg,
      const char* fileStub,
      Feature& feature, int featureIndex
      )
   {

      //
      // now we print the seed result line,
      // which includes the seed, score projection etc.
      printer.printSeed (out, feature, pos);

      //
      // now we print pos & neg motif files
      bool isPos = true;
      for (int i = 0 ; i <= 1; i++) {
         //
         // print neg only if Parser::_motif_all_ is specified
         if (  (gMotif!= Parser::_out_none_) &&
               ((gMotif == Parser::_out_all_) || isPos)) {
            //
            // we open a file for the motif
            Persistance::TextTableReport::TextOutput motifFile (
               openFile (isPos, featureIndex, fileStub, MOTIF_FILE_STUB)
               );

            printer.printMotif ( motifFile,
               feature,
               isPos? pos : neg);
         }

         //
         // now we print the PSSM files
         if (  (gPSSM!= Parser::_out_none_) &&
               ((gPSSM == Parser::_out_all_) || isPos)) {
            Persistance::TextWriter pssmFile (
               openFile (isPos, featureIndex, fileStub, PSSM_FILE_STUB)
               );

            printer.printPSSM (positionWeightType, pssmFile, feature, pos);
         }

         //
         // now we print the bayesian sample files
         if (  (gSample!= Parser::_out_none_) &&
               ((gSample == Parser::_out_all_) || isPos)) {
            Persistance::TextTableReport::TextOutput sampleFile (
               openFile (isPos, featureIndex , fileStub, SAMPLE_FILE_STUB)
               );

            printer.printBayesian (sampleFile, feature, pos);
         }

         isPos = !isPos;
      }
   }

};

#endif
