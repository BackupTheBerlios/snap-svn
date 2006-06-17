using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ConfEditor {
    public partial class ConfiGenForm : Form {

        private SNAP.Engine.Conf _conf = null;
        private SortedDictionary<string, ToolStripItem> _items = new SortedDictionary<string, ToolStripItem>();
        private ToolStripSplitButton _activeButton;
        private bool _suppressChecks = true;

        public ToolStripSplitButton ActiveButton
        {
            get
            {
                return _activeButton;
            }
            set
            {
                if (_activeButton == value)
                    return;

                if (_activeButton != null)
                {
                    _activeButton.ForeColor = _activeButton.Owner.ForeColor;
                }

                _activeButton = value;
                _activeButton.ForeColor = Color.Goldenrod;
            }
        }

        public SNAP.Engine.Conf Conf {
            set {
                if (value == _conf) 
                    return;

                _conf = value;
                
                /// remove all buttons from panel
                foreach (System.Windows.Forms.ToolStripItem item in _items.Values)
                {
                    toolStrip1.Items.Remove (item);
                }
                _items.Clear ();

                /// add the new sections
                foreach (KeyValuePair <string, SNAP.Engine.Conf.Section> sectionItem in _conf.Sections)
                {
                    AddSection(sectionItem.Value);
                }

                if (_conf.Sections.Count > 0)
                {
                    /// load the first section
                    IEnumerator<KeyValuePair <string, SNAP.Engine.Conf.Section>> i = _conf.Sections.GetEnumerator();
                    i.MoveNext ();
                    string name = i.Current.Value.Name;
                    
                }
            }
        }
        public SNAP.Engine.Conf.Section Section;

        
        public ConfiGenForm() {
            InitializeComponent();
            Conf = new SNAP.Engine.Conf(
                //new ConfEditor.Util.IndexedSortedList <string, SNAP.Engine.Conf.Section> ()
                );
            _suppressChecks = false;

            panelProjectionWildcards.ContentOverrideChanged += new EventHandler(panelProjectionWildcards_ContentOverrideChanged);
        }

        void panelProjectionWildcards_ContentOverrideChanged(object sender, EventArgs e)
        {
            if (!panelProjectionWildcards.ContentOverride)
                LoadProjectionWildcards();
        }

        public ConfiGenForm(SNAP.Engine.Conf conf) 
        {
            InitializeComponent();
            Conf = conf;
            _suppressChecks = false;
        }

        public void AddSection(SNAP.Engine.Conf.Section section)
        {
            ToolStripSplitButton sectionButton = new ToolStripSplitButton (section.Name);
            sectionButton.Click += new EventHandler(sectionButton_Click);
            toolStrip1.Items.Add (sectionButton);
            _items.Add(section.Name, sectionButton);
        }

        void sectionButton_Click(object sender, EventArgs e)
        {
            ToolStripSplitButton sectionButton = (ToolStripSplitButton)sender;
            LoadSection (_conf.Sections[sectionButton.Text]);
            ActiveButton = sectionButton;
        }

        public void UpdateConstraints()
        {
            int modifier = (this.radioProjectionsOuterWildcardsAllow.Checked) ?
                0 : 2;

            numericProjectionsLength.Minimum = 
                numericProjectionsMidWildcards.Value + 
                numericProjectionsWildcards.Value + 
                modifier;

            numericProjectionsMidWildcards.Maximum = 
                numericProjectionsLength.Value - 
                numericProjectionsWildcards.Value - 
                modifier;

            numericProjectionsWildcards.Maximum = 
                numericProjectionsLength.Value - 
                numericProjectionsMidWildcards.Value 
                - modifier;
        }

        private void LoadProjectionLength()
        {
            SNAP.Engine.Settings parser = Section.Settings;

            /// length of seed
            numericProjectionsLength.Minimum = 0;
            numericProjectionsLength.Maximum = 20;
            numericProjectionsLength.Value = parser.__seed_l;
        }

        private void LoadProjectionWildcards()
        {
            SNAP.Engine.Settings parser = Section.Settings;

            numericProjectionsWildcards.Minimum = 0;
            numericProjectionsWildcards.Maximum = 20;
            numericProjectionsWildcards.Value = parser.__proj_d;
        }

        public void LoadSection (SNAP.Engine.Conf.Section section)
        {
            try
            {
                bool firstSection = _conf.Sections.IndexOf (section.Name) == 0;

                panelPreprocessingType.Enabled = firstSection;
                panelPreprocessingDepth.Enabled = firstSection;
                panelPreprocessingReverse.Enabled = firstSection;

                _suppressChecks = true;
                SNAP.Engine.Settings parser = section.Settings;

                /// general information
                txtInfoSectionName.Text = section.Name;
                txtInfoParameters.Text = section.Parameters;

                /// length of seed
                LoadProjectionLength();

                /// num of wildcards
                LoadProjectionWildcards();

                /// num of wildcards in middle section
                numericProjectionsMidWildcards.Minimum = 0;
                numericProjectionsMidWildcards.Value = parser.__proj_mid;
                numericProjectionsMidWildcards.Maximum = 20;

                /// allow wildcards in outer positions
                if (parser.__proj_outer)
                    radioProjectionsOuterWildcardsAllow.Checked = true;
                else
                    radioProjectionsOuterWildcards.Checked = true;

                /// use random projections
                if (parser.__proj_e)
                    radioSamplingExaustive.Checked = true;
                else
                    radioSamplingRandom.Checked = true;

                /// how many random projections (if not exaustive)
                numericSamplingRandom.Value = parser.__proj_n;

                /// use a constant seed for random projections
                if (parser.__proj_i != 0)
                    radioRandomSamplingRandomize.Checked = true;
                else
                    radioRandomSamplingPredetermined.Checked = true;
                numericRandomSamplingPredetermined.Value = parser.__proj_i;

                /// use a specialized projection base
                if (parser.__proj_base.Length > 0)
                    radioProjectionBaseManual.Checked = true;
                else
                    radioProjectionBaseDefault.Checked = true;
                txtProjectionBaseManual.Text = parser.__proj_base;

                /// number of seeds to output
                numericOutputSeedN.Value = parser.__seed_n;

                /// length of the seeds to output
                numericOutputSeedL.Value = parser.__seed_l;

                /// redundancy checking offset
                numericOutputRedundancyOffset.Value = parser.__seed_r;

                /// check reverse redundancy
                radioOutputIgnoreReverseRedundancy.Checked = parser.__seed_rr;

                /// the minimal score for a reported seed
                numericOutputMinimumScore.Value = (decimal)parser.__minusLog10score_min;

                /// the minimal positive hits for a reported seed
                numericOutputMinPositiveHits.Value = parser.__score_min_seq;

                /// the minimal (in percent) positive hits for a reported seed
                numericOutputMinPositiveHitsPercent.Value = parser.__score_min_seq_per;

                /// when to generate .PSSM files
                switch (parser.__generatePSSM)
                {
                    case SNAP.Engine.OutputType._out_all_:
                        radioOutputGeneratePSSMAll.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_pos_:
                        radioOutputGeneratePSSMPos.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_none_:
                        radioOutputGeneratePSSMNone.Checked = true;
                        break;
                }

                /// when to generate .motif files
                switch (parser.__generateMotif)
                {
                    case SNAP.Engine.OutputType._out_all_:
                        radioOutputGenerateMotifAll.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_pos_:
                        radioOutputGenerateMotifPos.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_none_:
                        radioOutputGenerateMotifNone.Checked = true;
                        break;
                }

                /// when to generate .sample files
                switch (parser.__generateBayesian)
                {
                    case SNAP.Engine.OutputType._out_all_:
                        radioOutputGenerateSampleAll.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_pos_:
                        radioOutputGenerateSamplePos.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_none_:
                        radioOutputGenerateSampleNone.Checked = true;
                        break;
                }

                /// when to log the seeds in the console output
                switch (parser.__generateSeedlog)
                {
                    case SNAP.Engine.OutputType._out_all_:
                        radioOutputGenerateFeatureseAll.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_pos_:
                        radioOutputGenerateFeaturesetPos.Checked = true;
                        break;

                    case SNAP.Engine.OutputType._out_none_:
                        radioOutputGenerateFeaturesetNone.Checked = true;
                        break;
                }

                /// which hit mechanism gene/total counts
                if (parser.__count == SNAP.Engine.CountType._count_gene_)
                    radioHitsGeneCounts.Checked = true;
                else
                    radioHitsTotalCounts.Checked = true;

                /// from which weight is a sequence considered positive
                numericHitsCutoff.Value = (decimal)parser.__weight_t;

                /// how hits are incremented
                switch (parser.__score_partial)
                {
                    case SNAP.Engine.PositionWeightType._position_weight_discrete_:
                        radioHitsIncrementsInteger.Checked = true;
                        break;

                    case SNAP.Engine.PositionWeightType._position_weight_real_:
                        radioHitsIncrementsWeighted.Checked = true;
                        break;

                    case SNAP.Engine.PositionWeightType._position_weight_hotspots_:
                        radioHitsIncrementsHotspots.Checked = true;
                        break;
                }

                /// which score function: hypergeometric or exploss
                if (parser.__scoreType == SNAP.Engine.ScoreType._score_hypegeo_)
                    radioScoringHypergeo.Checked = true;
                else
                    radioScoringTypeExponential.Checked = true;

                /// exponent values for exploss function
                numericScoreingExplossAlpha.Value = (decimal)parser.__expLossPos;
                numericScoreingExplossBeta.Value = (decimal)parser.__expLossNeg;

                /// statistical fix
                switch (parser.__statfix_t)
                {
                    case SNAP.Engine.StatFixType._statfix_bonf_:
                        radioScoringCorrectionBonf.Checked = true;
                        break;

                    case SNAP.Engine.StatFixType._statfix_fdr_:
                        radioScoringCorrectionFDR.Checked = true;
                        break;

                    case SNAP.Engine.StatFixType._statfix_none_:
                        radioScoringCorrectionNone.Checked = true;
                        break;
                }

                /// preprocessor type
                if (parser.__prep == SNAP.Engine.PrepType._prep_tree_)
                    radioPreprocessingTypeTree.Checked = true;
                else
                    radioPreprocessingTypeTable.Checked = true;

                /// preprocessor depth
                numericPreprocessingDepth.Value = parser.__prep_l;

                /// search type
                if (parser.__searchType == SNAP.Engine.SearchType._search_tree_)
                    radioPreprocessingSearchTypeTree.Checked = true;
                else
                    radioPreprocessingSearchTypeTree.Checked = true;

                /// should use reverse?
                if (parser.__count_reverse == false)
                    radioPreprocessingNoReverse.Checked = true;
                else
                    radioPreprocessingReverse.Checked = true;
            }
            finally
            {
                _suppressChecks = false;
                UpdateConstraints();
                UpdateRangeDisplay();
            }
        }

        public void SaveSection(SNAP.Engine.Conf.Section section)
        {
            SNAP.Engine.Settings parser = new SNAP.Engine.Settings();

            /// length of seed
            parser.__seed_l = decimal.ToInt32 (numericProjectionsLength.Value);

            /// num of wildcards
            parser.__proj_d = decimal.ToInt32 (numericProjectionsWildcards.Value);

            /// num of wildcards in middle section
            parser.__proj_mid = decimal.ToInt32 (numericProjectionsMidWildcards.Value);

            /// allow wildcards in outer positions
            parser.__proj_outer = radioProjectionsOuterWildcardsAllow.Checked;

            /// use random projections
            parser.__proj_e = radioSamplingExaustive.Checked;

            /// how many random projections (if not exaustive)
            parser.__proj_n = decimal.ToInt32 (numericSamplingRandom.Value);

            /// use a constant seed for random projections
            if (radioRandomSamplingRandomize.Checked)
                parser.__proj_i = 0;
            else {
                parser.__proj_i = decimal.ToInt32 (numericRandomSamplingPredetermined.Value);
            }

            /// use a specialized projection base
            if (radioProjectionBaseManual.Checked) {
                parser.__proj_base = txtProjectionBaseManual.Text;
            }
            else {
                parser.__proj_base = "";
            }

            /// number of seeds to output
            parser.__seed_n = decimal.ToInt32 (numericOutputSeedN.Value);

            /// length of the seeds to output
            parser.__seed_l = decimal.ToInt32 (numericOutputSeedL.Value);

            /// redundancy checking offset
            parser.__seed_r = decimal.ToInt32 (numericOutputRedundancyOffset.Value);

            /// check reverse redundancy
            parser.__seed_rr = radioOutputIgnoreReverseRedundancy.Checked;

            /// the minimal score for a reported seed
            parser.__minusLog10score_min = decimal.ToDouble(numericOutputMinimumScore.Value);

            /// the minimal positive hits for a reported seed
            parser.__score_min_seq = decimal.ToInt32(numericOutputMinPositiveHits.Value);

            /// the minimal (in percent) positive hits for a reported seed
            parser.__score_min_seq_per = decimal.ToInt32(numericOutputMinPositiveHitsPercent.Value);

            /// when to generate .PSSM files
            if (radioOutputGeneratePSSMAll.Checked)
                parser.__generatePSSM = SNAP.Engine.OutputType._out_all_;
            else if (radioOutputGeneratePSSMPos.Checked)
                parser.__generatePSSM = SNAP.Engine.OutputType._out_pos_;
            else
                parser.__generatePSSM = SNAP.Engine.OutputType._out_none_;

            /// when to generate .motif files
            if (radioOutputGenerateMotifAll.Checked)
                parser.__generateMotif = SNAP.Engine.OutputType._out_all_;
            else if (radioOutputGenerateMotifPos.Checked)
                parser.__generateMotif = SNAP.Engine.OutputType._out_pos_;
            else
                parser.__generateMotif = SNAP.Engine.OutputType._out_none_;

            /// when to generate .sample files
            if (radioOutputGenerateSampleAll.Checked)
                parser.__generateBayesian = SNAP.Engine.OutputType._out_all_;
            else if (radioOutputGenerateSamplePos.Checked)
                parser.__generateBayesian = SNAP.Engine.OutputType._out_pos_;
            else
                parser.__generateBayesian = SNAP.Engine.OutputType._out_none_;

            /// when to log the seeds in the console output
            if (radioOutputGenerateFeatureseAll.Checked)
                parser.__generateSeedlog = SNAP.Engine.OutputType._out_all_;
            else if (radioOutputGenerateFeaturesetPos.Checked)
                parser.__generateSeedlog = SNAP.Engine.OutputType._out_pos_;
            else
                parser.__generateSeedlog = SNAP.Engine.OutputType._out_none_;

            /// which hit mechanism gene/total counts
            if (radioHitsGeneCounts.Checked)
                parser.__count = SNAP.Engine.CountType._count_gene_;
            else
                parser.__count = SNAP.Engine.CountType._count_total_;

            /// from which weight is a sequence considered positive
            parser.__weight_t = decimal.ToSingle (numericHitsCutoff.Value);

            /// how hits are incremented
            if (radioHitsIncrementsInteger.Checked)
                parser.__score_partial = SNAP.Engine.PositionWeightType._position_weight_discrete_;
            else if (radioHitsIncrementsWeighted.Checked)
                parser.__score_partial = SNAP.Engine.PositionWeightType._position_weight_real_;
            else 
                parser.__score_partial = SNAP.Engine.PositionWeightType._position_weight_hotspots_;

            /// which score function: hypergeometric or exploss
            if (radioScoringHypergeo.Checked)
                parser.__scoreType = SNAP.Engine.ScoreType._score_hypegeo_;
            else
                parser.__scoreType = SNAP.Engine.ScoreType._score_exp_;

            /// exponent values for exploss function
            parser.__expLossPos = (float)numericScoreingExplossAlpha.Value;
            parser.__expLossNeg = (float)numericScoreingExplossBeta.Value;

            /// statistical fix
            if (radioScoringCorrectionBonf.Checked)
                parser.__statfix_t = SNAP.Engine.StatFixType._statfix_bonf_;
            else if (radioScoringCorrectionFDR.Checked)
                parser.__statfix_t = SNAP.Engine.StatFixType._statfix_fdr_;
            else
                parser.__statfix_t = SNAP.Engine.StatFixType._statfix_none_;

            /// preprocessor type
            if (radioPreprocessingTypeTree.Checked)
                parser.__prep = SNAP.Engine.PrepType._prep_tree_;
            else
                parser.__prep = SNAP.Engine.PrepType._prep_leaf_;

            /// preprocessor depth
            parser.__prep_l = decimal.ToInt32 (numericPreprocessingDepth.Value);

            /// search type
            if (radioPreprocessingSearchTypeTree.Checked)
                parser.__searchType = SNAP.Engine.SearchType._search_tree_;
            else
                parser.__searchType = SNAP.Engine.SearchType._search_table_; 

            /// should use reverse?
            parser.__count_reverse = radioPreprocessingReverse.Checked;
        }

        /// <summary>
        /// Handles the ValueChanged event of the numericProjectionsLength control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void numericProjectionsLength_ValueChanged(object sender, EventArgs e) {
            if (_suppressChecks)
                return;

            UpdateConstraints();
            UpdateRangeDisplay();
        }

        /// <summary>
        /// Handles the ValueChanged event of the numericProjectionsWildcards control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void numericProjectionsWildcards_ValueChanged(object sender, EventArgs e) {
            if (_suppressChecks)
                return;

            UpdateConstraints();
            UpdateRangeDisplay();
        }

        private void UpdateRangeDisplay() {
            lblProjectionLengthRange.Text  = "(" + numericProjectionsLength.Minimum + " - " + numericProjectionsLength.Maximum + ")";
            lblProjectionWildcardsRange.Text = "(" + numericProjectionsWildcards.Minimum + " - " + numericProjectionsWildcards.Maximum + ")";
            lblProjectionMidWildcardsRange.Text = "(" + numericProjectionsMidWildcards.Minimum + " - " + numericProjectionsMidWildcards.Maximum + ")";

        }

        /// <summary>
        /// Handles the ValueChanged event of the numericProjectionsMidWildcards control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void numericProjectionsMidWildcards_ValueChanged(object sender, EventArgs e) {
            if (_suppressChecks)
                return;

            UpdateConstraints();
            UpdateRangeDisplay();
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioScoringTypeExponential control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioScoringTypeExponential_CheckedChanged(object sender, EventArgs e) {
            panelScoringTypeExponential.Enabled = radioScoringTypeExponential.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioPreprocessingTypeTree control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioPreprocessingTypeTree_CheckedChanged(object sender, EventArgs e) {
            panelSearchType.Enabled = radioPreprocessingTypeTree.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioProjectionBaseManual control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioProjectionBaseManual_CheckedChanged(object sender, EventArgs e) {
            txtProjectionBaseManual.Enabled = radioProjectionBaseManual.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioRandomSamplingPredetermined control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioRandomSamplingPredetermined_CheckedChanged(object sender, EventArgs e) {
            numericRandomSamplingPredetermined.Enabled = radioRandomSamplingPredetermined.Checked;
        }

        private void radioProjectionsOuterWildcardsAllow_CheckedChanged(object sender, EventArgs e) {
            if (radioProjectionsOuterWildcardsAllow.Checked) {
                numericProjectionsLength.Minimum -= 2;
                numericProjectionsWildcards.Maximum += 2;
                numericProjectionsMidWildcards.Maximum += 2;
                UpdateRangeDisplay();
            }
            else {
                numericProjectionsLength.Minimum += 2;
                numericProjectionsWildcards.Maximum -= 2;
                numericProjectionsMidWildcards.Maximum -= 2;
                UpdateRangeDisplay();
            }
        }

        private void radioSamplingRandom_CheckedChanged_1(object sender, EventArgs e) {
            panelRandomSampling.Enabled =
                numericSamplingRandom.Enabled = radioSamplingRandom.Checked;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.CheckFileExists = true;
            dialog.CheckPathExists = true;
            //dialog.InitialDirectory = 
            dialog.Multiselect = false;
            dialog.Filter = "conf files (*.conf)|*.conf|All files (*.*)|*.*";
            if (dialog.ShowDialog(this) == DialogResult.OK)
            {
                SNAP.Engine.Conf conf = SNAP.Engine.Conf.LoadFile(
//                    new Util.IndexedSortedList <string, SNAP.Engine.Conf.Section> (),
                    dialog.FileName);
                this.Conf = conf;
            }
        }

        private void optionPanel12_Load(object sender, EventArgs e)
        {

        }
    }
}