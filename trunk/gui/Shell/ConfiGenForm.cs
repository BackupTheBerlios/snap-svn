using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class ConfiGenForm : Form {
        public ConfiGenForm() {
            InitializeComponent();
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
    }
}