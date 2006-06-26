#if 0 

//
//
static Persistance::OutputStream* openPerfFile (  
   const char* fileStub)
{
   //
   // create the motif file name
   char motifFileName [1024];
   sprintf (motifFileName, "%s.perf", fileStub);
   return openFile (motifFileName);
}

//
// how to score position for which no feature in
// the results matches?
//
// IDEA: the score for each of the features is > 0
// so the unrecognizedPosition score should be 
// somehow compareable with the worst feature score
// but not too close.
// 
// we choose unrecognizedPositionScore = worstFeatureScore / (M+1)
static double unrecognizedPositionScore (
   SeedSearcherMain::Results& results,
   SeedSearcherMain::CmdLineParameters& trainParams)
{
   const int MBestPositions = trainParams.parser ().__perf_m;

   results.lastFeature ();
   const Feature& worstFeature = results.getFeature ();
   double worstFeatureScore = - worstFeature.log2score ();
   if (worstFeatureScore > 0)
      return (worstFeatureScore / (MBestPositions + 1));
   else
      return (worstFeatureScore * (MBestPositions + 1));
}

static void initPositionScoreQueue (
                                    SeedSearcherMain::Results& results,
                                    SeedSearcherMain::CmdLineParameters& trainParams,
                                    std::priority_queue <double>& q)
{
   const int MBestPositions = trainParams.parser ().__perf_m;

   mustbe (q.empty ());

   double dblUnrecognizedPositionScore = 
      unrecognizedPositionScore (results, trainParams);

   std::priority_queue <double> M_unrecognizedPositionScores;
   for (int i=0 ; i<MBestPositions ; i++)
      q.push (dblUnrecognizedPositionScore);
}

//
// 0) print seed scores on test data
// a) normalize scores
// b) score each position in each sequence
// c) the sequence's score is the average of the best M position scores
// D) output all positions with likelihood of having binding site
//   Name best-position-score average-sequence-score
static void testSeedPerformance (
                                 int argc, char* argv[],
                                 SeedSearcherMain::Results& results,
                                 SeedSearcherMain::CmdLineParameters& trainParams)
{
   const int MBestPositions = trainParams.parser ().__perf_m;
   const Parser::PerfLenComp comp_l = trainParams.parser ().__perf_comp_l;

   DLOG << "#" << DLOG.EOL ()
      << "# Performing on test data:" << DLOG.EOL ();

   //
   // the fourth arguemnt is a wgt test file
   SeedSearcherMain::CmdLineParameters testParams (argc, argv);
   testParams.setup ( 
      argv [trainParams.parser ().__firstFileArg + SeqFileIndex],
      argv [trainParams.parser ().__firstFileArg + TestWgtFileIndex]);
   DLOG.flush ();

   FeatureInvestigator printer ( testParams                     , 
      testParams.parser ().__seed_o  );
   printer.printSeedHeader (DLOG);

   for (results.firstFeature ();results.hasMoreFeatures();results.nextFeature ()) {
      //
      // create a feature for the seed in the test data
      const Feature& trainFeature = results.getFeature ();;
      AutoPtr <Feature> feature = 
         testParams.createFeature ( trainFeature.assignment (), 
         *trainFeature.projection ());

      //
      // discover positive/negative 
      PositionVector posPositions;
      PositionVector negPositions;
      printer.addPositions (*feature, posPositions, negPositions);

      //
      // now print the seed score on the test data
      printer.printSeed (DLOG, *feature, posPositions);
      DLOG.flush ();
   }

   //
   // first we normalize the seeds (if necessary)
   switch (trainParams.parser ().__score_norm) {
      case Parser::_norm_none_:
         break;

      case Parser::_norm_logit_:
         trainParams.bestFeatures ()->normalizeScoresSigmoid ();
         break;

      case Parser::_norm_linear_background_: {
         BookkeeperFilter& bookkeeper = 
            dynamic_cast <BookkeeperFilter&> (trainParams.bestFeatures ());
         bookkeeper.normalizeBackgroundScoresLinear ();
                                             }
                                             break;

                                             //case Parser::_norm_linear_:
                                             //trainParams.bestFeatures ()->normalizeScoresLinear ();
                                             //break;
      default:
         mustfail ();
         break;
   }

   //
   // we open file for test-data performance output
   // and begin with header line
   TextWriter perfWriter (openPerfFile (
      argv [trainParams.parser ().__firstFileArg + StubFileIndex]));

   perfWriter << "SeqName\t\tSeqWeight\tBestScoringPosition\t\tSeqScore" 
      << perfWriter.EOL ();

   std::priority_queue <double> MUnrecognizedPositions;
   initPositionScoreQueue (results,
      trainParams,
      MUnrecognizedPositions);

   //
   // for each sequence in the training data,
   // we want to know the score of each position 
   // (e.g. what is the best feature that it matches)
   SequenceDB::SequenceIterator seqit = testParams.db().sequenceIterator ();
   for (; seqit.hasNext (); seqit.next ()) {
      //
      // create a priority queue to hold the scores of
      // each position in this sequence.
      // the priority queue is initialized with M scores
      // for the unrecognized positions
      /*
      std::priority_queue <double> positionScores =
      MUnrecognizedPositions;
      */
      std::priority_queue <double> positionScores;

      //
      // score each position in the sequence
      int seqlen = (*seqit)->length ();
      for (int i=0 ; i<seqlen ; i++) {
         bool foundMatch = false;
         results.firstFeature ();
         //
         // find the first feature that matches
         // the first feature is the 'best' feature
         // (e.g. it has the best (lowest) score
         // we negate the scores to get a positive score on a position
         do {
            const Feature& trainFeature = results.getFeature ();
            int trainFeatureLength = trainFeature.assignment ().length ();
            Str posData = (*seqit)->data (i, trainFeatureLength);
            //
            // if the position's lookahead is small than the feature's length
            // then this is not considered to be a matching
            if (posData.length () < trainFeatureLength) {
               results.nextFeature ();
               continue;
            }

            Assignment posAssignment (posData, testParams.langauge ().code ());
            if (trainFeature.assignment ().contains (posAssignment)) {
               //
               // we score this position with this best feature's score (negated)
               positionScores.push (- trainFeature.log2score ());
               foundMatch = true;
            }

            results.nextFeature ();
         }
         while (!foundMatch && results.hasMoreFeatures ());
      }
      //
      // now I know the best scores of positions in the sequence
      // we need the average of the M best
      // 
      // 
      if (positionScores.empty ()) {
         //
         // no score available
         perfWriter << (*seqit)->name () << "\t\t"
            << (*seqit)->weight () << '\t'
            << "-----" << "\t\t"
            << "-----"
            << perfWriter.EOL ();
      }
      else {
         double score = 0;
         /** 
         changes made by Yoseph on 18.4.04:
         to make the linear combination of the exponential socres and not their logs
         */
         score = -HUGE_VAL; // Yoseph
         double bestScore = positionScores.top (); 
         /*
         for (int i=0 ; i<MBestPositions ; i++) {
         score += positionScores.top ();
         positionScores.pop ();
         }
         score = (score / MBestPositions);
         */
         int j;
         for (j=0 ; !positionScores.empty () && j<MBestPositions ; j++) {
            //score += positionScores.top (); 
            score = AddLog2(score,positionScores.top ()); // Yoseph
            positionScores.pop ();
         }
         //score = (score / j);
         score -= log2(static_cast<double>(j)); // Yoseph

         //
         // we compensate sequence's score by dividing
         switch (comp_l) {
            case Parser::_perflencomp_none_:
               break;

            case Parser::_perflencomp_linear_: 
               score = (score / seqlen);
               break;

            case Parser::_perflencomp_log_:
               score = (score / log2 (static_cast<double>(seqlen)));
               break;

            default:
               mustfail ();
         };

         //
         // now we print the sequence information
         // we transform from log2 internal representation to log10 in the output:
         static const double LOG2_10 = 
            log2 (static_cast<double> (10));

         perfWriter << (*seqit)->name () << "\t\t"
            << (*seqit)->weight () << '\t'
            << bestScore/ LOG2_10 << "\t\t"
            << score / LOG2_10
            << perfWriter.EOL ();
      }
   }
}

#endif