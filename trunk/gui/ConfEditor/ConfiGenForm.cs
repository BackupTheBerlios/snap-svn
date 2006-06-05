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
                foreach (SNAP.Engine.Conf.Section section in _conf.Sections.Values)
                {
                    AddSection(section);
                }

                if (_conf.Sections.Count > 0)
                {
                    /// load the first section
                    IEnumerator<KeyValuePair <string, SNAP.Engine.Conf.Section>> i = _conf.Sections.GetEnumerator();
                    i.MoveNext ();
                    string name = i.Current.Value.Name;
                    sectionButton_Click(_items[name], new EventArgs());
                }
            }
        }

        
        public ConfiGenForm() {
            InitializeComponent();
            Conf = new SNAP.Engine.Conf();
        }

        public ConfiGenForm(SNAP.Engine.Conf conf) 
        {
            InitializeComponent();
            Conf = conf;
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
            LoadParameters(_conf.Sections[sectionButton.Text].Settings);
            ActiveButton = sectionButton;
        }

        public void LoadParameters (SNAP.Engine.Parser parser)
        {
            /// length of seed
            numericProjectionsLength.Value = parser.__seed_l;

            /// num of wildcards
            numericProjectionsWildcards.Value = parser.__proj_d;

            /// num of wildcards in middle section
            numericProjectionsMidWildcards.Value = parser.__proj_mid;

            /// allow wildcards in outer positions
            radioProjectionsOuterWildcards.Checked = 
                parser.__proj_outer;

            /// use random projections
            radioSamplingRandom.Checked = !parser.__proj_e;
            
            /// how many random projections (if not exaustive)
            numericSamplingRandom.Value = parser.__proj_n;

            /// use a constant seed for random projections
            radioRandomSamplingPredetermined.Checked = parser.__proj_i != 0;
            numericRandomSamplingPredetermined.Value = parser.__proj_i;

            /// use a specialized projection base
            radioProjectionBaseDefault.Checked = parser.__proj_base.Length > 0;
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
            numericOutputMinimumScore.Value = (decimal) parser.__minusLog10score_min;

            /// the minimal positive hits for a reported seed
            numericOutputMinPositiveHits.Value = parser.__score_min_seq;

            /// the minimal (in percent) positive hits for a reported seed
            numericOutputMinPositiveHitsPercent.Value = parser.__score_min_seq_per;

            /// when to generate .PSSM files
            switch (parser.__generatePSSM) {
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
            switch (parser.__generateMotif) {
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
            switch (parser.__generateBayesian) {
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
            switch (parser.__generateSeedlog) {
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
            radioHitsGeneCounts.Checked = parser.__count == SNAP.Engine.CountType._count_gene_;
            
            /// from which weight is a sequence considered positive
            numericHitsCutoff.Value = (decimal) parser.__weight_t;

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
            radioScoringHypergeo.Checked = parser.__scoreType == SNAP.Engine.ScoreType._score_hypegeo_;
            
            /// exponent values for exploss function
            numericScoreingExplossAlpha.Value = (decimal) parser.__expLossPos;
            numericScoreingExplossBeta.Value = (decimal) parser.__expLossNeg;

            /// statistical fix
            switch (parser.__statfix_t) {
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
            radioPreprocessingTypeTree.Checked = parser.__prep == SNAP.Engine.PrepType._prep_tree_;

            /// preprocessor depth
            numericPreprocessingDepth.Value = parser.__prep_l;

            /// search type
            switch (parser.__searchType)
            {
                case SNAP.Engine.SearchType._search_default_:
                    radioPreprocessingSearchTypeTree.Checked = parser.__prep == SNAP.Engine.PrepType._prep_tree_;
                    break;

                case SNAP.Engine.SearchType._search_tree_:
                case SNAP.Engine.SearchType._search_table_:
                    radioPreprocessingSearchTypeTree.Checked = parser.__searchType == SNAP.Engine.SearchType._search_tree_;
                    break;
            }

            /// should use reverse?
            radioPreprocessingNoReverse.Checked = parser.__count_reverse == false;
        }

        /// <summary>
        /// Handles the ValueChanged event of the numericProjectionsLength control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void numericProjectionsLength_ValueChanged(object sender, EventArgs e) {
            int oldvalue = (int)numericProjectionsLength.Tag;
            int newvalue = Decimal.ToInt32((numericProjectionsLength.Value));
            int diff = newvalue - oldvalue;
            if ((numericProjectionsWildcards.Value <= numericProjectionsWildcards.Maximum + diff) &&
                (numericProjectionsMidWildcards.Value <= numericProjectionsMidWildcards.Maximum + diff)) {
                numericProjectionsLength.Tag = newvalue;
                numericProjectionsWildcards.Maximum += diff;
                numericProjectionsMidWildcards.Maximum += diff;
                UpdateRangeDisplay();
            }
            else {
                numericProjectionsLength.Value = oldvalue;
            }
        }

        /// <summary>
        /// Handles the ValueChanged event of the numericProjectionsWildcards control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void numericProjectionsWildcards_ValueChanged(object sender, EventArgs e) {
            int oldvalue = (int)numericProjectionsWildcards.Tag;
            int newvalue = Decimal.ToInt32((numericProjectionsWildcards.Value));
            int diff = newvalue - oldvalue;

            if ((numericProjectionsLength.Minimum + diff <= numericProjectionsLength.Value) &&
                (numericProjectionsMidWildcards.Value <= numericProjectionsMidWildcards.Maximum - diff)) {
                numericProjectionsWildcards.Tag = newvalue;
                numericProjectionsLength.Minimum += diff;
                numericProjectionsMidWildcards.Maximum -= diff;
                UpdateRangeDisplay();
            }
            else {
                numericProjectionsWildcards.Value = oldvalue;
            }
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
            int oldvalue = (int)numericProjectionsMidWildcards.Tag;
            int newvalue = Decimal.ToInt32((numericProjectionsMidWildcards.Value));
            int diff = newvalue - oldvalue;

            if ((numericProjectionsLength.Minimum + diff <= numericProjectionsLength.Value) &&
                (numericProjectionsWildcards.Value <= numericProjectionsWildcards.Maximum - diff)) {
                numericProjectionsMidWildcards.Tag = newvalue;
                numericProjectionsLength.Minimum += diff;
                numericProjectionsWildcards.Maximum -= diff;
                UpdateRangeDisplay();
            }
            else {
                numericProjectionsMidWildcards.Value = oldvalue;
            }
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioScoringTypeExponential control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioScoringTypeExponential_CheckedChanged(object sender, EventArgs e) {
            panelScoringTypeExponential.Visible = radioScoringTypeExponential.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioPreprocessingTypeTree control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioPreprocessingTypeTree_CheckedChanged(object sender, EventArgs e) {
            panelSearchType.Visible = radioPreprocessingTypeTree.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioProjectionBaseManual control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioProjectionBaseManual_CheckedChanged(object sender, EventArgs e) {
            txtProjectionBaseManual.Visible = radioProjectionBaseManual.Checked;
        }

        /// <summary>
        /// Handles the CheckedChanged event of the radioRandomSamplingPredetermined control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void radioRandomSamplingPredetermined_CheckedChanged(object sender, EventArgs e) {
            numericRandomSamplingPredetermined.Visible = radioRandomSamplingPredetermined.Checked;
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
            panelRandomSampling.Visible =
                numericSamplingRandom.Visible = radioSamplingRandom.Checked;
        }

        private void numericUpDown11_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown13_ValueChanged(object sender, EventArgs e)
        {

        }

        private void ConfiGenForm_Load(object sender, EventArgs e)
        {

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
                SNAP.Engine.Conf conf = SNAP.Engine.Conf.LoadFile(dialog.FileName);
                this.Conf = conf;
            }
        }
    }
}