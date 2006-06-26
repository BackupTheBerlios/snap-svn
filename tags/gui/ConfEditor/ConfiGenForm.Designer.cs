using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;


namespace SNAP.ConfEditor {
    partial class ConfiGenForm {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.helpProvider1 = new System.Windows.Forms.HelpProvider();
            this.button1 = new System.Windows.Forms.Button();
            this.toolStripContainer1 = new System.Windows.Forms.ToolStripContainer();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.panel27 = new System.Windows.Forms.Panel();
            this.txtInfoParameters = new System.Windows.Forms.TextBox();
            this.linkLabel31 = new System.Windows.Forms.LinkLabel();
            this.panel26 = new System.Windows.Forms.Panel();
            this.txtInfoSectionName = new System.Windows.Forms.TextBox();
            this.linkLabel30 = new System.Windows.Forms.LinkLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel28 = new System.Windows.Forms.Panel();
            this.txtInfoFilename = new System.Windows.Forms.TextBox();
            this.linkLabel32 = new System.Windows.Forms.LinkLabel();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.optionPanel18 = new SNAP.ConfEditor.OptionPanel();
            this.txtProjectionBaseManual = new System.Windows.Forms.TextBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.radioProjectionBaseDefault = new System.Windows.Forms.RadioButton();
            this.radioProjectionBaseManual = new System.Windows.Forms.RadioButton();
            this.panelRandomSampling = new SNAP.ConfEditor.OptionPanel();
            this.numericRandomSamplingPredetermined = new System.Windows.Forms.NumericUpDown();
            this.panel2 = new System.Windows.Forms.Panel();
            this.radioRandomSamplingRandomize = new System.Windows.Forms.RadioButton();
            this.radioRandomSamplingPredetermined = new System.Windows.Forms.RadioButton();
            this.optionPanel16 = new SNAP.ConfEditor.OptionPanel();
            this.numericSamplingRandom = new System.Windows.Forms.NumericUpDown();
            this.panel1 = new System.Windows.Forms.Panel();
            this.radioSamplingExaustive = new System.Windows.Forms.RadioButton();
            this.radioSamplingRandom = new System.Windows.Forms.RadioButton();
            this.optionPanel15 = new SNAP.ConfEditor.OptionPanel();
            this.radioProjectionsOuterWildcardsAllow = new System.Windows.Forms.RadioButton();
            this.radioProjectionsOuterWildcards = new System.Windows.Forms.RadioButton();
            this.optionPanel14 = new SNAP.ConfEditor.OptionPanel();
            this.lblProjectionMidWildcardsRange = new System.Windows.Forms.Label();
            this.numericProjectionsMidWildcards = new System.Windows.Forms.NumericUpDown();
            this.panelProjectionWildcards = new SNAP.ConfEditor.OptionPanel();
            this.lblProjectionWildcardsRange = new System.Windows.Forms.Label();
            this.numericProjectionsWildcards = new System.Windows.Forms.NumericUpDown();
            this.panelProjectionLength = new SNAP.ConfEditor.OptionPanel();
            this.lblProjectionLengthRange = new System.Windows.Forms.Label();
            this.numericProjectionsLength = new System.Windows.Forms.NumericUpDown();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.optionPanel11 = new SNAP.ConfEditor.OptionPanel();
            this.radioOutputGenerateFeaturesetNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateFeaturesetPos = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateFeatureseAll = new System.Windows.Forms.RadioButton();
            this.optionPanel10 = new SNAP.ConfEditor.OptionPanel();
            this.radioOutputGenerateSampleNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateSampleAll = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateSamplePos = new System.Windows.Forms.RadioButton();
            this.optionPanel9 = new SNAP.ConfEditor.OptionPanel();
            this.radioOutputGenerateMotifNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateMotifAll = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateMotifPos = new System.Windows.Forms.RadioButton();
            this.optionPanel8 = new SNAP.ConfEditor.OptionPanel();
            this.radioOutputGeneratePSSMNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGeneratePSSMAll = new System.Windows.Forms.RadioButton();
            this.radioOutputGeneratePSSMPos = new System.Windows.Forms.RadioButton();
            this.optionPanel7 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputMinPositiveHitsPercent = new System.Windows.Forms.NumericUpDown();
            this.optionPanel6 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputMinPositiveHits = new System.Windows.Forms.NumericUpDown();
            this.optionPanel5 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputMinimumScore = new System.Windows.Forms.NumericUpDown();
            this.optionPanel4 = new SNAP.ConfEditor.OptionPanel();
            this.radioOutputIgnoreReverseRedundancy = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.optionPanel3 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputRedundancyOffset = new System.Windows.Forms.NumericUpDown();
            this.optionPanel2 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputSeedL = new System.Windows.Forms.NumericUpDown();
            this.optionPanel1 = new SNAP.ConfEditor.OptionPanel();
            this.numericOutputSeedN = new System.Windows.Forms.NumericUpDown();
            this.panel24 = new System.Windows.Forms.Panel();
            this.linkLabel26 = new System.Windows.Forms.LinkLabel();
            this.panel23 = new System.Windows.Forms.Panel();
            this.panel22 = new System.Windows.Forms.Panel();
            this.panel21 = new System.Windows.Forms.Panel();
            this.panel17 = new System.Windows.Forms.Panel();
            this.panel16 = new System.Windows.Forms.Panel();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.optionPanel21 = new SNAP.ConfEditor.OptionPanel();
            this.numericHitsCutoff = new System.Windows.Forms.NumericUpDown();
            this.optionPanel20 = new SNAP.ConfEditor.OptionPanel();
            this.radioHitsIncrementsHotspots = new System.Windows.Forms.RadioButton();
            this.radioHitsIncrementsWeighted = new System.Windows.Forms.RadioButton();
            this.radioHitsIncrementsInteger = new System.Windows.Forms.RadioButton();
            this.optionPanel17 = new SNAP.ConfEditor.OptionPanel();
            this.radioHitsTotalCounts = new System.Windows.Forms.RadioButton();
            this.radioHitsGeneCounts = new System.Windows.Forms.RadioButton();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.optionPanel22 = new SNAP.ConfEditor.OptionPanel();
            this.radioScoringCorrectionNone = new System.Windows.Forms.RadioButton();
            this.radioScoringCorrectionFDR = new System.Windows.Forms.RadioButton();
            this.radioScoringCorrectionBonf = new System.Windows.Forms.RadioButton();
            this.optionPanel19 = new SNAP.ConfEditor.OptionPanel();
            this.panelScoringTypeExponential = new System.Windows.Forms.Panel();
            this.linkLabel15 = new System.Windows.Forms.LinkLabel();
            this.numericScoreingExplossBeta = new System.Windows.Forms.NumericUpDown();
            this.linkLabel16 = new System.Windows.Forms.LinkLabel();
            this.numericScoreingExplossAlpha = new System.Windows.Forms.NumericUpDown();
            this.panel4 = new System.Windows.Forms.Panel();
            this.radioScoringHypergeo = new System.Windows.Forms.RadioButton();
            this.radioScoringTypeExponential = new System.Windows.Forms.RadioButton();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.panelPreprocessingReverse = new System.Windows.Forms.Panel();
            this.radioPreprocessingReverse = new System.Windows.Forms.RadioButton();
            this.radioPreprocessingNoReverse = new System.Windows.Forms.RadioButton();
            this.linkLabel13 = new System.Windows.Forms.LinkLabel();
            this.panelSearchType = new System.Windows.Forms.Panel();
            this.radioSearchTypeTable = new System.Windows.Forms.RadioButton();
            this.radioPreprocessingSearchTypeTree = new System.Windows.Forms.RadioButton();
            this.linkLabel22 = new System.Windows.Forms.LinkLabel();
            this.panelPreprocessingType = new System.Windows.Forms.Panel();
            this.radioPreprocessingTypeTable = new System.Windows.Forms.RadioButton();
            this.radioPreprocessingTypeTree = new System.Windows.Forms.RadioButton();
            this.linkLabel10 = new System.Windows.Forms.LinkLabel();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripSplitButton();
            this.addAStepToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripSplitButton();
            this.addAStepToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.linkLabel11 = new System.Windows.Forms.LinkLabel();
            this.numericPreprocessingDepth = new System.Windows.Forms.NumericUpDown();
            this.panelPreprocessingDepth = new System.Windows.Forms.Panel();
            this.toolStripContainer1.ContentPanel.SuspendLayout();
            this.toolStripContainer1.LeftToolStripPanel.SuspendLayout();
            this.toolStripContainer1.TopToolStripPanel.SuspendLayout();
            this.toolStripContainer1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage6.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.panel27.SuspendLayout();
            this.panel26.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.panel28.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.optionPanel18.MyChildPanel.SuspendLayout();
            this.optionPanel18.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panelRandomSampling.MyChildPanel.SuspendLayout();
            this.panelRandomSampling.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericRandomSamplingPredetermined)).BeginInit();
            this.panel2.SuspendLayout();
            this.optionPanel16.MyChildPanel.SuspendLayout();
            this.optionPanel16.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericSamplingRandom)).BeginInit();
            this.panel1.SuspendLayout();
            this.optionPanel15.MyChildPanel.SuspendLayout();
            this.optionPanel15.SuspendLayout();
            this.optionPanel14.MyChildPanel.SuspendLayout();
            this.optionPanel14.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsMidWildcards)).BeginInit();
            this.panelProjectionWildcards.MyChildPanel.SuspendLayout();
            this.panelProjectionWildcards.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsWildcards)).BeginInit();
            this.panelProjectionLength.MyChildPanel.SuspendLayout();
            this.panelProjectionLength.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsLength)).BeginInit();
            this.tabPage2.SuspendLayout();
            this.optionPanel11.MyChildPanel.SuspendLayout();
            this.optionPanel11.SuspendLayout();
            this.optionPanel10.MyChildPanel.SuspendLayout();
            this.optionPanel10.SuspendLayout();
            this.optionPanel9.MyChildPanel.SuspendLayout();
            this.optionPanel9.SuspendLayout();
            this.optionPanel8.MyChildPanel.SuspendLayout();
            this.optionPanel8.SuspendLayout();
            this.optionPanel7.MyChildPanel.SuspendLayout();
            this.optionPanel7.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHitsPercent)).BeginInit();
            this.optionPanel6.MyChildPanel.SuspendLayout();
            this.optionPanel6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHits)).BeginInit();
            this.optionPanel5.MyChildPanel.SuspendLayout();
            this.optionPanel5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinimumScore)).BeginInit();
            this.optionPanel4.MyChildPanel.SuspendLayout();
            this.optionPanel4.SuspendLayout();
            this.optionPanel3.MyChildPanel.SuspendLayout();
            this.optionPanel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputRedundancyOffset)).BeginInit();
            this.optionPanel2.MyChildPanel.SuspendLayout();
            this.optionPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedL)).BeginInit();
            this.optionPanel1.MyChildPanel.SuspendLayout();
            this.optionPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedN)).BeginInit();
            this.panel24.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.optionPanel21.MyChildPanel.SuspendLayout();
            this.optionPanel21.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericHitsCutoff)).BeginInit();
            this.optionPanel20.MyChildPanel.SuspendLayout();
            this.optionPanel20.SuspendLayout();
            this.optionPanel17.MyChildPanel.SuspendLayout();
            this.optionPanel17.SuspendLayout();
            this.tabPage5.SuspendLayout();
            this.optionPanel22.MyChildPanel.SuspendLayout();
            this.optionPanel22.SuspendLayout();
            this.optionPanel19.MyChildPanel.SuspendLayout();
            this.optionPanel19.SuspendLayout();
            this.panelScoringTypeExponential.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossBeta)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossAlpha)).BeginInit();
            this.panel4.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.panelPreprocessingReverse.SuspendLayout();
            this.panelSearchType.SuspendLayout();
            this.panelPreprocessingType.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericPreprocessingDepth)).BeginInit();
            this.panelPreprocessingDepth.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(96, 8);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 18;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this.toolStripContainer1.ContentPanel.Controls.Add(this.tabControl1);
            this.toolStripContainer1.ContentPanel.Size = new System.Drawing.Size(538, 421);
            this.toolStripContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            // 
            // toolStripContainer1.LeftToolStripPanel
            // 
            this.toolStripContainer1.LeftToolStripPanel.Controls.Add(this.toolStrip1);
            this.toolStripContainer1.Location = new System.Drawing.Point(0, 0);
            this.toolStripContainer1.Name = "toolStripContainer1";
            this.toolStripContainer1.Size = new System.Drawing.Size(587, 445);
            this.toolStripContainer1.TabIndex = 2;
            this.toolStripContainer1.Text = "toolStripContainer1";
            // 
            // toolStripContainer1.TopToolStripPanel
            // 
            this.toolStripContainer1.TopToolStripPanel.Controls.Add(this.menuStrip1);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage6);
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Controls.Add(this.tabPage5);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(538, 421);
            this.tabControl1.TabIndex = 15;
            // 
            // tabPage6
            // 
            this.tabPage6.Controls.Add(this.groupBox2);
            this.tabPage6.Controls.Add(this.groupBox1);
            this.tabPage6.Location = new System.Drawing.Point(4, 22);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Size = new System.Drawing.Size(530, 395);
            this.tabPage6.TabIndex = 5;
            this.tabPage6.Text = "Info";
            this.tabPage6.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.AutoSize = true;
            this.groupBox2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox2.Controls.Add(this.panel27);
            this.groupBox2.Controls.Add(this.panel26);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox2.Location = new System.Drawing.Point(0, 48);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(530, 91);
            this.groupBox2.TabIndex = 23;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Section details";
            // 
            // panel27
            // 
            this.panel27.AutoSize = true;
            this.panel27.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel27.Controls.Add(this.txtInfoParameters);
            this.panel27.Controls.Add(this.linkLabel31);
            this.panel27.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel27.Location = new System.Drawing.Point(3, 44);
            this.panel27.Name = "panel27";
            this.panel27.Size = new System.Drawing.Size(524, 44);
            this.panel27.TabIndex = 21;
            // 
            // txtInfoParameters
            // 
            this.txtInfoParameters.Location = new System.Drawing.Point(128, 5);
            this.txtInfoParameters.Multiline = true;
            this.txtInfoParameters.Name = "txtInfoParameters";
            this.txtInfoParameters.Size = new System.Drawing.Size(363, 36);
            this.txtInfoParameters.TabIndex = 19;
            // 
            // linkLabel31
            // 
            this.linkLabel31.AutoSize = true;
            this.linkLabel31.Location = new System.Drawing.Point(13, 5);
            this.linkLabel31.Name = "linkLabel31";
            this.linkLabel31.Size = new System.Drawing.Size(85, 13);
            this.linkLabel31.TabIndex = 13;
            this.linkLabel31.TabStop = true;
            this.linkLabel31.Text = "Parameter String";
            // 
            // panel26
            // 
            this.panel26.AutoSize = true;
            this.panel26.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel26.Controls.Add(this.txtInfoSectionName);
            this.panel26.Controls.Add(this.linkLabel30);
            this.panel26.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel26.Location = new System.Drawing.Point(3, 16);
            this.panel26.Name = "panel26";
            this.panel26.Size = new System.Drawing.Size(524, 28);
            this.panel26.TabIndex = 20;
            // 
            // txtInfoSectionName
            // 
            this.txtInfoSectionName.Location = new System.Drawing.Point(128, 5);
            this.txtInfoSectionName.Name = "txtInfoSectionName";
            this.txtInfoSectionName.Size = new System.Drawing.Size(363, 20);
            this.txtInfoSectionName.TabIndex = 19;
            // 
            // linkLabel30
            // 
            this.linkLabel30.AutoSize = true;
            this.linkLabel30.Location = new System.Drawing.Point(13, 5);
            this.linkLabel30.Name = "linkLabel30";
            this.linkLabel30.Size = new System.Drawing.Size(74, 13);
            this.linkLabel30.TabIndex = 13;
            this.linkLabel30.TabStop = true;
            this.linkLabel30.Text = "Section Name";
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSize = true;
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.panel28);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(530, 48);
            this.groupBox1.TabIndex = 22;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Resource details";
            // 
            // panel28
            // 
            this.panel28.AutoSize = true;
            this.panel28.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel28.Controls.Add(this.txtInfoFilename);
            this.panel28.Controls.Add(this.linkLabel32);
            this.panel28.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel28.Location = new System.Drawing.Point(3, 16);
            this.panel28.Name = "panel28";
            this.panel28.Size = new System.Drawing.Size(524, 29);
            this.panel28.TabIndex = 26;
            // 
            // txtInfoFilename
            // 
            this.txtInfoFilename.Location = new System.Drawing.Point(128, 6);
            this.txtInfoFilename.Name = "txtInfoFilename";
            this.txtInfoFilename.Size = new System.Drawing.Size(363, 20);
            this.txtInfoFilename.TabIndex = 19;
            // 
            // linkLabel32
            // 
            this.linkLabel32.AutoSize = true;
            this.linkLabel32.Location = new System.Drawing.Point(13, 3);
            this.linkLabel32.Name = "linkLabel32";
            this.linkLabel32.Size = new System.Drawing.Size(49, 13);
            this.linkLabel32.TabIndex = 13;
            this.linkLabel32.TabStop = true;
            this.linkLabel32.Text = "Filename";
            // 
            // tabPage1
            // 
            this.tabPage1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.tabPage1.Controls.Add(this.optionPanel18);
            this.tabPage1.Controls.Add(this.panelRandomSampling);
            this.tabPage1.Controls.Add(this.optionPanel16);
            this.tabPage1.Controls.Add(this.optionPanel15);
            this.tabPage1.Controls.Add(this.optionPanel14);
            this.tabPage1.Controls.Add(this.panelProjectionWildcards);
            this.tabPage1.Controls.Add(this.panelProjectionLength);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(530, 395);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Projections";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // optionPanel18
            // 
            this.optionPanel18.ContentLabelText = "Projection Base";
            this.optionPanel18.ContentOverride = false;
            this.optionPanel18.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel18.Location = new System.Drawing.Point(3, 259);
            // 
            // optionPanel18.MyChildPanel
            // 
            this.optionPanel18.MyChildPanel.AutoSize = true;
            this.optionPanel18.MyChildPanel.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.optionPanel18.MyChildPanel.Controls.Add(this.txtProjectionBaseManual);
            this.optionPanel18.MyChildPanel.Controls.Add(this.panel3);
            this.optionPanel18.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel18.MyChildPanel.Enabled = false;
            this.optionPanel18.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel18.MyChildPanel.MinimumSize = new System.Drawing.Size(0, 32);
            this.optionPanel18.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel18.MyChildPanel.Size = new System.Drawing.Size(382, 64);
            this.optionPanel18.MyChildPanel.TabIndex = 14;
            this.optionPanel18.Name = "optionPanel18";
            this.optionPanel18.SettingType = null;
            this.optionPanel18.Size = new System.Drawing.Size(524, 64);
            this.optionPanel18.TabIndex = 35;
            // 
            // txtProjectionBaseManual
            // 
            this.txtProjectionBaseManual.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtProjectionBaseManual.Dock = System.Windows.Forms.DockStyle.Left;
            this.txtProjectionBaseManual.Enabled = false;
            this.txtProjectionBaseManual.Font = new System.Drawing.Font("Courier New", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtProjectionBaseManual.Location = new System.Drawing.Point(0, 32);
            this.txtProjectionBaseManual.Name = "txtProjectionBaseManual";
            this.txtProjectionBaseManual.Size = new System.Drawing.Size(120, 22);
            this.txtProjectionBaseManual.TabIndex = 16;
            this.txtProjectionBaseManual.Text = "**********";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.radioProjectionBaseDefault);
            this.panel3.Controls.Add(this.radioProjectionBaseManual);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel3.Location = new System.Drawing.Point(0, 0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(382, 32);
            this.panel3.TabIndex = 19;
            // 
            // radioProjectionBaseDefault
            // 
            this.radioProjectionBaseDefault.AutoSize = true;
            this.radioProjectionBaseDefault.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionBaseDefault.Checked = true;
            this.radioProjectionBaseDefault.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioProjectionBaseDefault.Location = new System.Drawing.Point(120, 0);
            this.radioProjectionBaseDefault.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioProjectionBaseDefault.Name = "radioProjectionBaseDefault";
            this.radioProjectionBaseDefault.Size = new System.Drawing.Size(120, 32);
            this.radioProjectionBaseDefault.TabIndex = 16;
            this.radioProjectionBaseDefault.TabStop = true;
            this.radioProjectionBaseDefault.Text = "Default";
            this.radioProjectionBaseDefault.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionBaseDefault.UseVisualStyleBackColor = true;
            // 
            // radioProjectionBaseManual
            // 
            this.radioProjectionBaseManual.AutoSize = true;
            this.radioProjectionBaseManual.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionBaseManual.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioProjectionBaseManual.Location = new System.Drawing.Point(0, 0);
            this.radioProjectionBaseManual.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioProjectionBaseManual.Name = "radioProjectionBaseManual";
            this.radioProjectionBaseManual.Size = new System.Drawing.Size(120, 32);
            this.radioProjectionBaseManual.TabIndex = 15;
            this.radioProjectionBaseManual.Text = "Manual";
            this.radioProjectionBaseManual.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionBaseManual.UseVisualStyleBackColor = true;
            this.radioProjectionBaseManual.CheckedChanged += new System.EventHandler(this.radioProjectionBaseManual_CheckedChanged);
            // 
            // panelRandomSampling
            // 
            this.panelRandomSampling.ContentLabelText = "Random Sampling";
            this.panelRandomSampling.ContentOverride = false;
            this.panelRandomSampling.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelRandomSampling.Location = new System.Drawing.Point(3, 195);
            // 
            // panelRandomSampling.MyChildPanel
            // 
            this.panelRandomSampling.MyChildPanel.Controls.Add(this.numericRandomSamplingPredetermined);
            this.panelRandomSampling.MyChildPanel.Controls.Add(this.panel2);
            this.panelRandomSampling.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelRandomSampling.MyChildPanel.Enabled = false;
            this.panelRandomSampling.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.panelRandomSampling.MyChildPanel.Name = "MyChildPanel";
            this.panelRandomSampling.MyChildPanel.Size = new System.Drawing.Size(382, 64);
            this.panelRandomSampling.MyChildPanel.TabIndex = 14;
            this.panelRandomSampling.Name = "panelRandomSampling";
            this.panelRandomSampling.SettingType = null;
            this.panelRandomSampling.Size = new System.Drawing.Size(524, 64);
            this.panelRandomSampling.TabIndex = 34;
            // 
            // numericRandomSamplingPredetermined
            // 
            this.numericRandomSamplingPredetermined.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericRandomSamplingPredetermined.Enabled = false;
            this.numericRandomSamplingPredetermined.Location = new System.Drawing.Point(0, 32);
            this.numericRandomSamplingPredetermined.Name = "numericRandomSamplingPredetermined";
            this.numericRandomSamplingPredetermined.Size = new System.Drawing.Size(52, 20);
            this.numericRandomSamplingPredetermined.TabIndex = 18;
            this.numericRandomSamplingPredetermined.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.radioRandomSamplingRandomize);
            this.panel2.Controls.Add(this.radioRandomSamplingPredetermined);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(382, 32);
            this.panel2.TabIndex = 19;
            // 
            // radioRandomSamplingRandomize
            // 
            this.radioRandomSamplingRandomize.AutoSize = true;
            this.radioRandomSamplingRandomize.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioRandomSamplingRandomize.Checked = true;
            this.radioRandomSamplingRandomize.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioRandomSamplingRandomize.Location = new System.Drawing.Point(121, 0);
            this.radioRandomSamplingRandomize.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioRandomSamplingRandomize.Name = "radioRandomSamplingRandomize";
            this.radioRandomSamplingRandomize.Size = new System.Drawing.Size(120, 32);
            this.radioRandomSamplingRandomize.TabIndex = 16;
            this.radioRandomSamplingRandomize.TabStop = true;
            this.radioRandomSamplingRandomize.Text = "Randomize";
            this.radioRandomSamplingRandomize.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioRandomSamplingRandomize.UseVisualStyleBackColor = true;
            // 
            // radioRandomSamplingPredetermined
            // 
            this.radioRandomSamplingPredetermined.AutoSize = true;
            this.radioRandomSamplingPredetermined.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioRandomSamplingPredetermined.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioRandomSamplingPredetermined.Location = new System.Drawing.Point(0, 0);
            this.radioRandomSamplingPredetermined.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioRandomSamplingPredetermined.Name = "radioRandomSamplingPredetermined";
            this.radioRandomSamplingPredetermined.Size = new System.Drawing.Size(121, 32);
            this.radioRandomSamplingPredetermined.TabIndex = 15;
            this.radioRandomSamplingPredetermined.Text = "Predetermined Seed";
            this.radioRandomSamplingPredetermined.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioRandomSamplingPredetermined.UseVisualStyleBackColor = true;
            this.radioRandomSamplingPredetermined.CheckedChanged += new System.EventHandler(this.radioRandomSamplingPredetermined_CheckedChanged);
            // 
            // optionPanel16
            // 
            this.optionPanel16.ContentLabelText = "Sampling";
            this.optionPanel16.ContentOverride = false;
            this.optionPanel16.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel16.Location = new System.Drawing.Point(3, 131);
            // 
            // optionPanel16.MyChildPanel
            // 
            this.optionPanel16.MyChildPanel.Controls.Add(this.numericSamplingRandom);
            this.optionPanel16.MyChildPanel.Controls.Add(this.panel1);
            this.optionPanel16.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel16.MyChildPanel.Enabled = false;
            this.optionPanel16.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel16.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel16.MyChildPanel.Size = new System.Drawing.Size(382, 64);
            this.optionPanel16.MyChildPanel.TabIndex = 14;
            this.optionPanel16.Name = "optionPanel16";
            this.optionPanel16.SettingType = null;
            this.optionPanel16.Size = new System.Drawing.Size(524, 64);
            this.optionPanel16.TabIndex = 33;
            // 
            // numericSamplingRandom
            // 
            this.numericSamplingRandom.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericSamplingRandom.Location = new System.Drawing.Point(0, 32);
            this.numericSamplingRandom.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericSamplingRandom.Name = "numericSamplingRandom";
            this.numericSamplingRandom.Size = new System.Drawing.Size(60, 20);
            this.numericSamplingRandom.TabIndex = 20;
            this.numericSamplingRandom.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.radioSamplingExaustive);
            this.panel1.Controls.Add(this.radioSamplingRandom);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(382, 32);
            this.panel1.TabIndex = 19;
            // 
            // radioSamplingExaustive
            // 
            this.radioSamplingExaustive.AutoSize = true;
            this.radioSamplingExaustive.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioSamplingExaustive.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioSamplingExaustive.Location = new System.Drawing.Point(120, 0);
            this.radioSamplingExaustive.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioSamplingExaustive.Name = "radioSamplingExaustive";
            this.radioSamplingExaustive.Size = new System.Drawing.Size(120, 32);
            this.radioSamplingExaustive.TabIndex = 16;
            this.radioSamplingExaustive.Text = "Exhaustive";
            this.radioSamplingExaustive.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioSamplingExaustive.UseVisualStyleBackColor = true;
            // 
            // radioSamplingRandom
            // 
            this.radioSamplingRandom.AutoSize = true;
            this.radioSamplingRandom.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioSamplingRandom.Checked = true;
            this.radioSamplingRandom.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioSamplingRandom.Location = new System.Drawing.Point(0, 0);
            this.radioSamplingRandom.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioSamplingRandom.Name = "radioSamplingRandom";
            this.radioSamplingRandom.Size = new System.Drawing.Size(120, 32);
            this.radioSamplingRandom.TabIndex = 14;
            this.radioSamplingRandom.TabStop = true;
            this.radioSamplingRandom.Text = "Random";
            this.radioSamplingRandom.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioSamplingRandom.UseVisualStyleBackColor = true;
            this.radioSamplingRandom.CheckedChanged += new System.EventHandler(this.radioSamplingRandom_CheckedChanged_1);
            // 
            // optionPanel15
            // 
            this.optionPanel15.ContentLabelText = "Outer Wildcards";
            this.optionPanel15.ContentOverride = false;
            this.optionPanel15.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel15.Location = new System.Drawing.Point(3, 99);
            // 
            // optionPanel15.MyChildPanel
            // 
            this.optionPanel15.MyChildPanel.Controls.Add(this.radioProjectionsOuterWildcardsAllow);
            this.optionPanel15.MyChildPanel.Controls.Add(this.radioProjectionsOuterWildcards);
            this.optionPanel15.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel15.MyChildPanel.Enabled = false;
            this.optionPanel15.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel15.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel15.MyChildPanel.Size = new System.Drawing.Size(382, 32);
            this.optionPanel15.MyChildPanel.TabIndex = 14;
            this.optionPanel15.Name = "optionPanel15";
            this.optionPanel15.SettingType = null;
            this.optionPanel15.Size = new System.Drawing.Size(524, 32);
            this.optionPanel15.TabIndex = 32;
            // 
            // radioProjectionsOuterWildcardsAllow
            // 
            this.radioProjectionsOuterWildcardsAllow.AutoSize = true;
            this.radioProjectionsOuterWildcardsAllow.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionsOuterWildcardsAllow.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioProjectionsOuterWildcardsAllow.Location = new System.Drawing.Point(120, 0);
            this.radioProjectionsOuterWildcardsAllow.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioProjectionsOuterWildcardsAllow.Name = "radioProjectionsOuterWildcardsAllow";
            this.radioProjectionsOuterWildcardsAllow.Size = new System.Drawing.Size(120, 32);
            this.radioProjectionsOuterWildcardsAllow.TabIndex = 15;
            this.radioProjectionsOuterWildcardsAllow.Text = "Allow";
            this.radioProjectionsOuterWildcardsAllow.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionsOuterWildcardsAllow.UseVisualStyleBackColor = true;
            this.radioProjectionsOuterWildcardsAllow.CheckedChanged += new System.EventHandler(this.radioProjectionsOuterWildcardsAllow_CheckedChanged);
            // 
            // radioProjectionsOuterWildcards
            // 
            this.radioProjectionsOuterWildcards.AutoSize = true;
            this.radioProjectionsOuterWildcards.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionsOuterWildcards.Checked = true;
            this.radioProjectionsOuterWildcards.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioProjectionsOuterWildcards.Location = new System.Drawing.Point(0, 0);
            this.radioProjectionsOuterWildcards.MinimumSize = new System.Drawing.Size(120, 32);
            this.radioProjectionsOuterWildcards.Name = "radioProjectionsOuterWildcards";
            this.radioProjectionsOuterWildcards.Size = new System.Drawing.Size(120, 32);
            this.radioProjectionsOuterWildcards.TabIndex = 14;
            this.radioProjectionsOuterWildcards.TabStop = true;
            this.radioProjectionsOuterWildcards.Text = "Disallow";
            this.radioProjectionsOuterWildcards.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioProjectionsOuterWildcards.UseVisualStyleBackColor = true;
            // 
            // optionPanel14
            // 
            this.optionPanel14.ContentLabelText = "Middle Wildcards";
            this.optionPanel14.ContentOverride = false;
            this.optionPanel14.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel14.Location = new System.Drawing.Point(3, 67);
            // 
            // optionPanel14.MyChildPanel
            // 
            this.optionPanel14.MyChildPanel.Controls.Add(this.lblProjectionMidWildcardsRange);
            this.optionPanel14.MyChildPanel.Controls.Add(this.numericProjectionsMidWildcards);
            this.optionPanel14.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel14.MyChildPanel.Enabled = false;
            this.optionPanel14.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel14.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel14.MyChildPanel.Size = new System.Drawing.Size(382, 32);
            this.optionPanel14.MyChildPanel.TabIndex = 14;
            this.optionPanel14.Name = "optionPanel14";
            this.optionPanel14.SettingType = null;
            this.optionPanel14.Size = new System.Drawing.Size(524, 32);
            this.optionPanel14.TabIndex = 31;
            // 
            // lblProjectionMidWildcardsRange
            // 
            this.lblProjectionMidWildcardsRange.AutoSize = true;
            this.lblProjectionMidWildcardsRange.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblProjectionMidWildcardsRange.Location = new System.Drawing.Point(60, 0);
            this.lblProjectionMidWildcardsRange.MinimumSize = new System.Drawing.Size(60, 0);
            this.lblProjectionMidWildcardsRange.Name = "lblProjectionMidWildcardsRange";
            this.lblProjectionMidWildcardsRange.Size = new System.Drawing.Size(60, 13);
            this.lblProjectionMidWildcardsRange.TabIndex = 19;
            this.lblProjectionMidWildcardsRange.Text = "(0 - 6)";
            this.lblProjectionMidWildcardsRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsMidWildcards
            // 
            this.numericProjectionsMidWildcards.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericProjectionsMidWildcards.Location = new System.Drawing.Point(0, 0);
            this.numericProjectionsMidWildcards.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numericProjectionsMidWildcards.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericProjectionsMidWildcards.Name = "numericProjectionsMidWildcards";
            this.numericProjectionsMidWildcards.Size = new System.Drawing.Size(60, 20);
            this.numericProjectionsMidWildcards.TabIndex = 17;
            this.numericProjectionsMidWildcards.Tag = 0;
            this.numericProjectionsMidWildcards.ValueChanged += new System.EventHandler(this.numericProjectionsMidWildcards_ValueChanged);
            // 
            // panelProjectionWildcards
            // 
            this.panelProjectionWildcards.ContentLabelText = "Wildcards";
            this.panelProjectionWildcards.ContentOverride = false;
            this.panelProjectionWildcards.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelProjectionWildcards.Location = new System.Drawing.Point(3, 35);
            // 
            // panelProjectionWildcards.MyChildPanel
            // 
            this.panelProjectionWildcards.MyChildPanel.Controls.Add(this.lblProjectionWildcardsRange);
            this.panelProjectionWildcards.MyChildPanel.Controls.Add(this.numericProjectionsWildcards);
            this.panelProjectionWildcards.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelProjectionWildcards.MyChildPanel.Enabled = false;
            this.panelProjectionWildcards.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.panelProjectionWildcards.MyChildPanel.Name = "MyChildPanel";
            this.panelProjectionWildcards.MyChildPanel.Size = new System.Drawing.Size(382, 32);
            this.panelProjectionWildcards.MyChildPanel.TabIndex = 14;
            this.panelProjectionWildcards.Name = "panelProjectionWildcards";
            this.panelProjectionWildcards.SettingType = null;
            this.panelProjectionWildcards.Size = new System.Drawing.Size(524, 32);
            this.panelProjectionWildcards.TabIndex = 30;
            // 
            // lblProjectionWildcardsRange
            // 
            this.lblProjectionWildcardsRange.AutoSize = true;
            this.lblProjectionWildcardsRange.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblProjectionWildcardsRange.Location = new System.Drawing.Point(60, 0);
            this.lblProjectionWildcardsRange.MinimumSize = new System.Drawing.Size(60, 0);
            this.lblProjectionWildcardsRange.Name = "lblProjectionWildcardsRange";
            this.lblProjectionWildcardsRange.Size = new System.Drawing.Size(60, 13);
            this.lblProjectionWildcardsRange.TabIndex = 19;
            this.lblProjectionWildcardsRange.Text = "(0 - 6)";
            this.lblProjectionWildcardsRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsWildcards
            // 
            this.numericProjectionsWildcards.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericProjectionsWildcards.Location = new System.Drawing.Point(0, 0);
            this.numericProjectionsWildcards.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numericProjectionsWildcards.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericProjectionsWildcards.Name = "numericProjectionsWildcards";
            this.numericProjectionsWildcards.Size = new System.Drawing.Size(60, 20);
            this.numericProjectionsWildcards.TabIndex = 17;
            this.numericProjectionsWildcards.Tag = 3;
            this.numericProjectionsWildcards.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.numericProjectionsWildcards.ValueChanged += new System.EventHandler(this.numericProjectionsWildcards_ValueChanged);
            // 
            // panelProjectionLength
            // 
            this.panelProjectionLength.ContentLabelText = "Length";
            this.panelProjectionLength.ContentOverride = false;
            this.panelProjectionLength.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelProjectionLength.Location = new System.Drawing.Point(3, 3);
            // 
            // panelProjectionLength.MyChildPanel
            // 
            this.panelProjectionLength.MyChildPanel.Controls.Add(this.lblProjectionLengthRange);
            this.panelProjectionLength.MyChildPanel.Controls.Add(this.numericProjectionsLength);
            this.panelProjectionLength.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelProjectionLength.MyChildPanel.Enabled = false;
            this.panelProjectionLength.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.panelProjectionLength.MyChildPanel.Name = "MyChildPanel";
            this.panelProjectionLength.MyChildPanel.Size = new System.Drawing.Size(382, 32);
            this.panelProjectionLength.MyChildPanel.TabIndex = 14;
            this.panelProjectionLength.Name = "panelProjectionLength";
            this.panelProjectionLength.SettingType = null;
            this.panelProjectionLength.Size = new System.Drawing.Size(524, 32);
            this.panelProjectionLength.TabIndex = 29;
            this.panelProjectionLength.Load += new System.EventHandler(this.optionPanel12_Load);
            // 
            // lblProjectionLengthRange
            // 
            this.lblProjectionLengthRange.AutoSize = true;
            this.lblProjectionLengthRange.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblProjectionLengthRange.Location = new System.Drawing.Point(60, 0);
            this.lblProjectionLengthRange.MinimumSize = new System.Drawing.Size(60, 0);
            this.lblProjectionLengthRange.Name = "lblProjectionLengthRange";
            this.lblProjectionLengthRange.Size = new System.Drawing.Size(60, 13);
            this.lblProjectionLengthRange.TabIndex = 19;
            this.lblProjectionLengthRange.Text = "(5 - 20)";
            this.lblProjectionLengthRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsLength
            // 
            this.numericProjectionsLength.AutoSize = true;
            this.numericProjectionsLength.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericProjectionsLength.Location = new System.Drawing.Point(0, 0);
            this.numericProjectionsLength.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericProjectionsLength.Minimum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericProjectionsLength.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericProjectionsLength.Name = "numericProjectionsLength";
            this.numericProjectionsLength.Size = new System.Drawing.Size(60, 20);
            this.numericProjectionsLength.TabIndex = 17;
            this.numericProjectionsLength.Tag = 8;
            this.numericProjectionsLength.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.numericProjectionsLength.ValueChanged += new System.EventHandler(this.numericProjectionsLength_ValueChanged);
            // 
            // tabPage2
            // 
            this.tabPage2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.tabPage2.Controls.Add(this.optionPanel11);
            this.tabPage2.Controls.Add(this.optionPanel10);
            this.tabPage2.Controls.Add(this.optionPanel9);
            this.tabPage2.Controls.Add(this.optionPanel8);
            this.tabPage2.Controls.Add(this.optionPanel7);
            this.tabPage2.Controls.Add(this.optionPanel6);
            this.tabPage2.Controls.Add(this.optionPanel5);
            this.tabPage2.Controls.Add(this.optionPanel4);
            this.tabPage2.Controls.Add(this.optionPanel3);
            this.tabPage2.Controls.Add(this.optionPanel2);
            this.tabPage2.Controls.Add(this.optionPanel1);
            this.tabPage2.Controls.Add(this.panel24);
            this.tabPage2.Controls.Add(this.panel23);
            this.tabPage2.Controls.Add(this.panel22);
            this.tabPage2.Controls.Add(this.panel21);
            this.tabPage2.Controls.Add(this.panel17);
            this.tabPage2.Controls.Add(this.panel16);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Size = new System.Drawing.Size(530, 395);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Output";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // optionPanel11
            // 
            this.optionPanel11.ContentLabelText = "Featureset Logging";
            this.optionPanel11.ContentOverride = false;
            this.optionPanel11.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel11.Location = new System.Drawing.Point(0, 337);
            // 
            // optionPanel11.MyChildPanel
            // 
            this.optionPanel11.MyChildPanel.Controls.Add(this.radioOutputGenerateFeaturesetNone);
            this.optionPanel11.MyChildPanel.Controls.Add(this.radioOutputGenerateFeaturesetPos);
            this.optionPanel11.MyChildPanel.Controls.Add(this.radioOutputGenerateFeatureseAll);
            this.optionPanel11.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel11.MyChildPanel.Enabled = false;
            this.optionPanel11.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel11.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel11.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel11.MyChildPanel.TabIndex = 7;
            this.optionPanel11.Name = "optionPanel11";
            this.optionPanel11.SettingType = null;
            this.optionPanel11.Size = new System.Drawing.Size(530, 32);
            this.optionPanel11.TabIndex = 41;
            // 
            // radioOutputGenerateFeaturesetNone
            // 
            this.radioOutputGenerateFeaturesetNone.AutoSize = true;
            this.radioOutputGenerateFeaturesetNone.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeaturesetNone.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateFeaturesetNone.Location = new System.Drawing.Point(240, 0);
            this.radioOutputGenerateFeaturesetNone.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateFeaturesetNone.Name = "radioOutputGenerateFeaturesetNone";
            this.radioOutputGenerateFeaturesetNone.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateFeaturesetNone.TabIndex = 18;
            this.radioOutputGenerateFeaturesetNone.Text = "No";
            this.radioOutputGenerateFeaturesetNone.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeaturesetNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateFeaturesetPos
            // 
            this.radioOutputGenerateFeaturesetPos.AutoSize = true;
            this.radioOutputGenerateFeaturesetPos.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeaturesetPos.Checked = true;
            this.radioOutputGenerateFeaturesetPos.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateFeaturesetPos.Location = new System.Drawing.Point(120, 0);
            this.radioOutputGenerateFeaturesetPos.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateFeaturesetPos.Name = "radioOutputGenerateFeaturesetPos";
            this.radioOutputGenerateFeaturesetPos.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateFeaturesetPos.TabIndex = 17;
            this.radioOutputGenerateFeaturesetPos.TabStop = true;
            this.radioOutputGenerateFeaturesetPos.Text = "Only the best seeds";
            this.radioOutputGenerateFeaturesetPos.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeaturesetPos.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateFeatureseAll
            // 
            this.radioOutputGenerateFeatureseAll.AutoSize = true;
            this.radioOutputGenerateFeatureseAll.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeatureseAll.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateFeatureseAll.Location = new System.Drawing.Point(0, 0);
            this.radioOutputGenerateFeatureseAll.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateFeatureseAll.Name = "radioOutputGenerateFeatureseAll";
            this.radioOutputGenerateFeatureseAll.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateFeatureseAll.TabIndex = 16;
            this.radioOutputGenerateFeatureseAll.Text = "All Seeds";
            this.radioOutputGenerateFeatureseAll.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateFeatureseAll.UseVisualStyleBackColor = true;
            // 
            // optionPanel10
            // 
            this.optionPanel10.ContentLabelText = "Generate SAMPLE Files";
            this.optionPanel10.ContentOverride = false;
            this.optionPanel10.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel10.Location = new System.Drawing.Point(0, 305);
            // 
            // optionPanel10.MyChildPanel
            // 
            this.optionPanel10.MyChildPanel.Controls.Add(this.radioOutputGenerateSampleNone);
            this.optionPanel10.MyChildPanel.Controls.Add(this.radioOutputGenerateSampleAll);
            this.optionPanel10.MyChildPanel.Controls.Add(this.radioOutputGenerateSamplePos);
            this.optionPanel10.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel10.MyChildPanel.Enabled = false;
            this.optionPanel10.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel10.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel10.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel10.MyChildPanel.TabIndex = 7;
            this.optionPanel10.Name = "optionPanel10";
            this.optionPanel10.SettingType = null;
            this.optionPanel10.Size = new System.Drawing.Size(530, 32);
            this.optionPanel10.TabIndex = 40;
            // 
            // radioOutputGenerateSampleNone
            // 
            this.radioOutputGenerateSampleNone.AutoSize = true;
            this.radioOutputGenerateSampleNone.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSampleNone.Checked = true;
            this.radioOutputGenerateSampleNone.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateSampleNone.Location = new System.Drawing.Point(240, 0);
            this.radioOutputGenerateSampleNone.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateSampleNone.Name = "radioOutputGenerateSampleNone";
            this.radioOutputGenerateSampleNone.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateSampleNone.TabIndex = 20;
            this.radioOutputGenerateSampleNone.TabStop = true;
            this.radioOutputGenerateSampleNone.Text = "No";
            this.radioOutputGenerateSampleNone.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSampleNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateSampleAll
            // 
            this.radioOutputGenerateSampleAll.AutoSize = true;
            this.radioOutputGenerateSampleAll.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSampleAll.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateSampleAll.Location = new System.Drawing.Point(120, 0);
            this.radioOutputGenerateSampleAll.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateSampleAll.Name = "radioOutputGenerateSampleAll";
            this.radioOutputGenerateSampleAll.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateSampleAll.TabIndex = 19;
            this.radioOutputGenerateSampleAll.Text = "Yes";
            this.radioOutputGenerateSampleAll.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSampleAll.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateSamplePos
            // 
            this.radioOutputGenerateSamplePos.AutoSize = true;
            this.radioOutputGenerateSamplePos.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSamplePos.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateSamplePos.Location = new System.Drawing.Point(0, 0);
            this.radioOutputGenerateSamplePos.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateSamplePos.Name = "radioOutputGenerateSamplePos";
            this.radioOutputGenerateSamplePos.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateSamplePos.TabIndex = 17;
            this.radioOutputGenerateSamplePos.Text = "Only for positive hits";
            this.radioOutputGenerateSamplePos.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateSamplePos.UseVisualStyleBackColor = true;
            // 
            // optionPanel9
            // 
            this.optionPanel9.ContentLabelText = "Generate MOTIF Files";
            this.optionPanel9.ContentOverride = false;
            this.optionPanel9.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel9.Location = new System.Drawing.Point(0, 273);
            // 
            // optionPanel9.MyChildPanel
            // 
            this.optionPanel9.MyChildPanel.Controls.Add(this.radioOutputGenerateMotifNone);
            this.optionPanel9.MyChildPanel.Controls.Add(this.radioOutputGenerateMotifAll);
            this.optionPanel9.MyChildPanel.Controls.Add(this.radioOutputGenerateMotifPos);
            this.optionPanel9.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel9.MyChildPanel.Enabled = false;
            this.optionPanel9.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel9.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel9.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel9.MyChildPanel.TabIndex = 7;
            this.optionPanel9.Name = "optionPanel9";
            this.optionPanel9.SettingType = null;
            this.optionPanel9.Size = new System.Drawing.Size(530, 32);
            this.optionPanel9.TabIndex = 39;
            // 
            // radioOutputGenerateMotifNone
            // 
            this.radioOutputGenerateMotifNone.AutoSize = true;
            this.radioOutputGenerateMotifNone.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifNone.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateMotifNone.Location = new System.Drawing.Point(240, 0);
            this.radioOutputGenerateMotifNone.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateMotifNone.Name = "radioOutputGenerateMotifNone";
            this.radioOutputGenerateMotifNone.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateMotifNone.TabIndex = 18;
            this.radioOutputGenerateMotifNone.Text = "No";
            this.radioOutputGenerateMotifNone.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateMotifAll
            // 
            this.radioOutputGenerateMotifAll.AutoSize = true;
            this.radioOutputGenerateMotifAll.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifAll.Checked = true;
            this.radioOutputGenerateMotifAll.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateMotifAll.Location = new System.Drawing.Point(120, 0);
            this.radioOutputGenerateMotifAll.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateMotifAll.Name = "radioOutputGenerateMotifAll";
            this.radioOutputGenerateMotifAll.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateMotifAll.TabIndex = 16;
            this.radioOutputGenerateMotifAll.TabStop = true;
            this.radioOutputGenerateMotifAll.Text = "Yes";
            this.radioOutputGenerateMotifAll.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifAll.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateMotifPos
            // 
            this.radioOutputGenerateMotifPos.AutoSize = true;
            this.radioOutputGenerateMotifPos.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifPos.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGenerateMotifPos.Location = new System.Drawing.Point(0, 0);
            this.radioOutputGenerateMotifPos.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGenerateMotifPos.Name = "radioOutputGenerateMotifPos";
            this.radioOutputGenerateMotifPos.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGenerateMotifPos.TabIndex = 17;
            this.radioOutputGenerateMotifPos.Text = "Only for positive hits";
            this.radioOutputGenerateMotifPos.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGenerateMotifPos.UseVisualStyleBackColor = true;
            // 
            // optionPanel8
            // 
            this.optionPanel8.ContentLabelText = "Generate PSSM Files";
            this.optionPanel8.ContentOverride = false;
            this.optionPanel8.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel8.Location = new System.Drawing.Point(0, 241);
            // 
            // optionPanel8.MyChildPanel
            // 
            this.optionPanel8.MyChildPanel.Controls.Add(this.radioOutputGeneratePSSMNone);
            this.optionPanel8.MyChildPanel.Controls.Add(this.radioOutputGeneratePSSMAll);
            this.optionPanel8.MyChildPanel.Controls.Add(this.radioOutputGeneratePSSMPos);
            this.optionPanel8.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel8.MyChildPanel.Enabled = false;
            this.optionPanel8.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel8.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel8.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel8.MyChildPanel.TabIndex = 7;
            this.optionPanel8.Name = "optionPanel8";
            this.optionPanel8.SettingType = null;
            this.optionPanel8.Size = new System.Drawing.Size(530, 32);
            this.optionPanel8.TabIndex = 38;
            // 
            // radioOutputGeneratePSSMNone
            // 
            this.radioOutputGeneratePSSMNone.AutoSize = true;
            this.radioOutputGeneratePSSMNone.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMNone.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGeneratePSSMNone.Location = new System.Drawing.Point(240, 0);
            this.radioOutputGeneratePSSMNone.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGeneratePSSMNone.Name = "radioOutputGeneratePSSMNone";
            this.radioOutputGeneratePSSMNone.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGeneratePSSMNone.TabIndex = 18;
            this.radioOutputGeneratePSSMNone.Text = "No";
            this.radioOutputGeneratePSSMNone.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGeneratePSSMAll
            // 
            this.radioOutputGeneratePSSMAll.AutoSize = true;
            this.radioOutputGeneratePSSMAll.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMAll.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGeneratePSSMAll.Location = new System.Drawing.Point(120, 0);
            this.radioOutputGeneratePSSMAll.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGeneratePSSMAll.Name = "radioOutputGeneratePSSMAll";
            this.radioOutputGeneratePSSMAll.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGeneratePSSMAll.TabIndex = 16;
            this.radioOutputGeneratePSSMAll.Text = "Yes";
            this.radioOutputGeneratePSSMAll.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMAll.UseVisualStyleBackColor = true;
            // 
            // radioOutputGeneratePSSMPos
            // 
            this.radioOutputGeneratePSSMPos.AutoSize = true;
            this.radioOutputGeneratePSSMPos.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMPos.Checked = true;
            this.radioOutputGeneratePSSMPos.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputGeneratePSSMPos.Location = new System.Drawing.Point(0, 0);
            this.radioOutputGeneratePSSMPos.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputGeneratePSSMPos.Name = "radioOutputGeneratePSSMPos";
            this.radioOutputGeneratePSSMPos.Size = new System.Drawing.Size(120, 32);
            this.radioOutputGeneratePSSMPos.TabIndex = 17;
            this.radioOutputGeneratePSSMPos.TabStop = true;
            this.radioOutputGeneratePSSMPos.Text = "Only for positive hits";
            this.radioOutputGeneratePSSMPos.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputGeneratePSSMPos.UseVisualStyleBackColor = true;
            // 
            // optionPanel7
            // 
            this.optionPanel7.ContentLabelText = "Minimum Positive Hits (%)";
            this.optionPanel7.ContentOverride = false;
            this.optionPanel7.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel7.Location = new System.Drawing.Point(0, 209);
            // 
            // optionPanel7.MyChildPanel
            // 
            this.optionPanel7.MyChildPanel.Controls.Add(this.numericOutputMinPositiveHitsPercent);
            this.optionPanel7.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel7.MyChildPanel.Enabled = false;
            this.optionPanel7.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel7.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel7.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel7.MyChildPanel.TabIndex = 7;
            this.optionPanel7.Name = "optionPanel7";
            this.optionPanel7.SettingType = null;
            this.optionPanel7.Size = new System.Drawing.Size(530, 32);
            this.optionPanel7.TabIndex = 37;
            // 
            // numericOutputMinPositiveHitsPercent
            // 
            this.numericOutputMinPositiveHitsPercent.AutoSize = true;
            this.numericOutputMinPositiveHitsPercent.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputMinPositiveHitsPercent.Location = new System.Drawing.Point(0, 0);
            this.numericOutputMinPositiveHitsPercent.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputMinPositiveHitsPercent.Name = "numericOutputMinPositiveHitsPercent";
            this.numericOutputMinPositiveHitsPercent.Size = new System.Drawing.Size(60, 20);
            this.numericOutputMinPositiveHitsPercent.TabIndex = 18;
            this.numericOutputMinPositiveHitsPercent.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // optionPanel6
            // 
            this.optionPanel6.ContentLabelText = "Minimum Positive Hits";
            this.optionPanel6.ContentOverride = false;
            this.optionPanel6.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel6.Location = new System.Drawing.Point(0, 177);
            // 
            // optionPanel6.MyChildPanel
            // 
            this.optionPanel6.MyChildPanel.Controls.Add(this.numericOutputMinPositiveHits);
            this.optionPanel6.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel6.MyChildPanel.Enabled = false;
            this.optionPanel6.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel6.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel6.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel6.MyChildPanel.TabIndex = 7;
            this.optionPanel6.Name = "optionPanel6";
            this.optionPanel6.SettingType = null;
            this.optionPanel6.Size = new System.Drawing.Size(530, 32);
            this.optionPanel6.TabIndex = 36;
            // 
            // numericOutputMinPositiveHits
            // 
            this.numericOutputMinPositiveHits.AutoSize = true;
            this.numericOutputMinPositiveHits.DecimalPlaces = 2;
            this.numericOutputMinPositiveHits.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputMinPositiveHits.Location = new System.Drawing.Point(0, 0);
            this.numericOutputMinPositiveHits.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputMinPositiveHits.Name = "numericOutputMinPositiveHits";
            this.numericOutputMinPositiveHits.Size = new System.Drawing.Size(60, 20);
            this.numericOutputMinPositiveHits.TabIndex = 18;
            this.numericOutputMinPositiveHits.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // optionPanel5
            // 
            this.optionPanel5.ContentLabelText = "Minimum Score";
            this.optionPanel5.ContentOverride = false;
            this.optionPanel5.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel5.Location = new System.Drawing.Point(0, 145);
            // 
            // optionPanel5.MyChildPanel
            // 
            this.optionPanel5.MyChildPanel.Controls.Add(this.numericOutputMinimumScore);
            this.optionPanel5.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel5.MyChildPanel.Enabled = false;
            this.optionPanel5.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel5.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel5.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel5.MyChildPanel.TabIndex = 7;
            this.optionPanel5.Name = "optionPanel5";
            this.optionPanel5.SettingType = null;
            this.optionPanel5.Size = new System.Drawing.Size(530, 32);
            this.optionPanel5.TabIndex = 35;
            // 
            // numericOutputMinimumScore
            // 
            this.numericOutputMinimumScore.AutoSize = true;
            this.numericOutputMinimumScore.DecimalPlaces = 2;
            this.numericOutputMinimumScore.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputMinimumScore.Location = new System.Drawing.Point(0, 0);
            this.numericOutputMinimumScore.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputMinimumScore.Name = "numericOutputMinimumScore";
            this.numericOutputMinimumScore.Size = new System.Drawing.Size(60, 20);
            this.numericOutputMinimumScore.TabIndex = 18;
            this.numericOutputMinimumScore.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // optionPanel4
            // 
            this.optionPanel4.ContentLabelText = "Reverse Redundancy";
            this.optionPanel4.ContentOverride = false;
            this.optionPanel4.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel4.Location = new System.Drawing.Point(0, 113);
            // 
            // optionPanel4.MyChildPanel
            // 
            this.optionPanel4.MyChildPanel.Controls.Add(this.radioOutputIgnoreReverseRedundancy);
            this.optionPanel4.MyChildPanel.Controls.Add(this.radioButton2);
            this.optionPanel4.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel4.MyChildPanel.Enabled = false;
            this.optionPanel4.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel4.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel4.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel4.MyChildPanel.TabIndex = 7;
            this.optionPanel4.Name = "optionPanel4";
            this.optionPanel4.SettingType = null;
            this.optionPanel4.Size = new System.Drawing.Size(530, 32);
            this.optionPanel4.TabIndex = 34;
            // 
            // radioOutputIgnoreReverseRedundancy
            // 
            this.radioOutputIgnoreReverseRedundancy.AutoSize = true;
            this.radioOutputIgnoreReverseRedundancy.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputIgnoreReverseRedundancy.Checked = true;
            this.radioOutputIgnoreReverseRedundancy.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioOutputIgnoreReverseRedundancy.Location = new System.Drawing.Point(120, 0);
            this.radioOutputIgnoreReverseRedundancy.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioOutputIgnoreReverseRedundancy.Name = "radioOutputIgnoreReverseRedundancy";
            this.radioOutputIgnoreReverseRedundancy.Size = new System.Drawing.Size(120, 32);
            this.radioOutputIgnoreReverseRedundancy.TabIndex = 17;
            this.radioOutputIgnoreReverseRedundancy.TabStop = true;
            this.radioOutputIgnoreReverseRedundancy.Text = "Ignore";
            this.radioOutputIgnoreReverseRedundancy.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioOutputIgnoreReverseRedundancy.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioButton2.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioButton2.Location = new System.Drawing.Point(0, 0);
            this.radioButton2.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(120, 32);
            this.radioButton2.TabIndex = 16;
            this.radioButton2.Text = "Check";
            this.radioButton2.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // optionPanel3
            // 
            this.optionPanel3.ContentLabelText = "Redundancy Checking Offset";
            this.optionPanel3.ContentOverride = false;
            this.optionPanel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel3.Location = new System.Drawing.Point(0, 81);
            // 
            // optionPanel3.MyChildPanel
            // 
            this.optionPanel3.MyChildPanel.Controls.Add(this.numericOutputRedundancyOffset);
            this.optionPanel3.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel3.MyChildPanel.Enabled = false;
            this.optionPanel3.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel3.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel3.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel3.MyChildPanel.TabIndex = 7;
            this.optionPanel3.Name = "optionPanel3";
            this.optionPanel3.SettingType = null;
            this.optionPanel3.Size = new System.Drawing.Size(530, 32);
            this.optionPanel3.TabIndex = 33;
            // 
            // numericOutputRedundancyOffset
            // 
            this.numericOutputRedundancyOffset.AutoSize = true;
            this.numericOutputRedundancyOffset.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputRedundancyOffset.Location = new System.Drawing.Point(0, 0);
            this.numericOutputRedundancyOffset.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputRedundancyOffset.Name = "numericOutputRedundancyOffset";
            this.numericOutputRedundancyOffset.Size = new System.Drawing.Size(60, 20);
            this.numericOutputRedundancyOffset.TabIndex = 17;
            this.numericOutputRedundancyOffset.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // optionPanel2
            // 
            this.optionPanel2.ContentLabelText = "Output Seed Length";
            this.optionPanel2.ContentOverride = false;
            this.optionPanel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel2.Location = new System.Drawing.Point(0, 49);
            // 
            // optionPanel2.MyChildPanel
            // 
            this.optionPanel2.MyChildPanel.Controls.Add(this.numericOutputSeedL);
            this.optionPanel2.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel2.MyChildPanel.Enabled = false;
            this.optionPanel2.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel2.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel2.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel2.MyChildPanel.TabIndex = 7;
            this.optionPanel2.Name = "optionPanel2";
            this.optionPanel2.SettingType = null;
            this.optionPanel2.Size = new System.Drawing.Size(530, 32);
            this.optionPanel2.TabIndex = 32;
            // 
            // numericOutputSeedL
            // 
            this.numericOutputSeedL.AutoSize = true;
            this.numericOutputSeedL.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputSeedL.Location = new System.Drawing.Point(0, 0);
            this.numericOutputSeedL.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputSeedL.Name = "numericOutputSeedL";
            this.numericOutputSeedL.Size = new System.Drawing.Size(60, 20);
            this.numericOutputSeedL.TabIndex = 17;
            this.numericOutputSeedL.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            // 
            // optionPanel1
            // 
            this.optionPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.optionPanel1.ContentLabelText = "How Many Seeds To Ouptut";
            this.optionPanel1.ContentOverride = false;
            this.optionPanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel1.Location = new System.Drawing.Point(0, 17);
            // 
            // optionPanel1.MyChildPanel
            // 
            this.optionPanel1.MyChildPanel.Controls.Add(this.numericOutputSeedN);
            this.optionPanel1.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel1.MyChildPanel.Enabled = false;
            this.optionPanel1.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel1.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel1.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel1.MyChildPanel.TabIndex = 7;
            this.optionPanel1.Name = "optionPanel1";
            this.optionPanel1.SettingType = null;
            this.optionPanel1.Size = new System.Drawing.Size(530, 32);
            this.optionPanel1.TabIndex = 31;
            // 
            // numericOutputSeedN
            // 
            this.numericOutputSeedN.AutoSize = true;
            this.numericOutputSeedN.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericOutputSeedN.Location = new System.Drawing.Point(0, 0);
            this.numericOutputSeedN.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericOutputSeedN.Name = "numericOutputSeedN";
            this.numericOutputSeedN.Size = new System.Drawing.Size(60, 20);
            this.numericOutputSeedN.TabIndex = 17;
            this.numericOutputSeedN.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // panel24
            // 
            this.panel24.AutoSize = true;
            this.panel24.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel24.Controls.Add(this.linkLabel26);
            this.panel24.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel24.Location = new System.Drawing.Point(0, 0);
            this.panel24.Name = "panel24";
            this.panel24.Size = new System.Drawing.Size(530, 17);
            this.panel24.TabIndex = 30;
            // 
            // linkLabel26
            // 
            this.linkLabel26.AutoSize = true;
            this.linkLabel26.Location = new System.Drawing.Point(13, 4);
            this.linkLabel26.Name = "linkLabel26";
            this.linkLabel26.Size = new System.Drawing.Size(98, 13);
            this.linkLabel26.TabIndex = 13;
            this.linkLabel26.TabStop = true;
            this.linkLabel26.Text = "Featureset Logging";
            // 
            // panel23
            // 
            this.panel23.AutoSize = true;
            this.panel23.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel23.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel23.Location = new System.Drawing.Point(0, 0);
            this.panel23.Name = "panel23";
            this.panel23.Size = new System.Drawing.Size(530, 0);
            this.panel23.TabIndex = 29;
            // 
            // panel22
            // 
            this.panel22.AutoSize = true;
            this.panel22.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel22.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel22.Location = new System.Drawing.Point(0, 0);
            this.panel22.Name = "panel22";
            this.panel22.Size = new System.Drawing.Size(530, 0);
            this.panel22.TabIndex = 28;
            // 
            // panel21
            // 
            this.panel21.AutoSize = true;
            this.panel21.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel21.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel21.Location = new System.Drawing.Point(0, 0);
            this.panel21.Name = "panel21";
            this.panel21.Size = new System.Drawing.Size(530, 0);
            this.panel21.TabIndex = 27;
            // 
            // panel17
            // 
            this.panel17.AutoSize = true;
            this.panel17.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel17.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel17.Location = new System.Drawing.Point(0, 0);
            this.panel17.Name = "panel17";
            this.panel17.Size = new System.Drawing.Size(530, 0);
            this.panel17.TabIndex = 25;
            // 
            // panel16
            // 
            this.panel16.AutoSize = true;
            this.panel16.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel16.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel16.Location = new System.Drawing.Point(0, 0);
            this.panel16.Name = "panel16";
            this.panel16.Size = new System.Drawing.Size(530, 0);
            this.panel16.TabIndex = 24;
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.optionPanel21);
            this.tabPage4.Controls.Add(this.optionPanel20);
            this.tabPage4.Controls.Add(this.optionPanel17);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(530, 395);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Hit Counting";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // optionPanel21
            // 
            this.optionPanel21.ContentLabelText = "Positive/Negative Cutoff";
            this.optionPanel21.ContentOverride = false;
            this.optionPanel21.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel21.Location = new System.Drawing.Point(0, 64);
            // 
            // optionPanel21.MyChildPanel
            // 
            this.optionPanel21.MyChildPanel.Controls.Add(this.numericHitsCutoff);
            this.optionPanel21.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel21.MyChildPanel.Enabled = false;
            this.optionPanel21.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel21.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel21.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel21.MyChildPanel.TabIndex = 14;
            this.optionPanel21.Name = "optionPanel21";
            this.optionPanel21.SettingType = null;
            this.optionPanel21.Size = new System.Drawing.Size(530, 32);
            this.optionPanel21.TabIndex = 32;
            // 
            // numericHitsCutoff
            // 
            this.numericHitsCutoff.DecimalPlaces = 2;
            this.numericHitsCutoff.Dock = System.Windows.Forms.DockStyle.Left;
            this.numericHitsCutoff.Location = new System.Drawing.Point(0, 0);
            this.numericHitsCutoff.Name = "numericHitsCutoff";
            this.numericHitsCutoff.Size = new System.Drawing.Size(52, 20);
            this.numericHitsCutoff.TabIndex = 18;
            this.numericHitsCutoff.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // optionPanel20
            // 
            this.optionPanel20.ContentLabelText = "Hit Increments";
            this.optionPanel20.ContentOverride = false;
            this.optionPanel20.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel20.Location = new System.Drawing.Point(0, 32);
            // 
            // optionPanel20.MyChildPanel
            // 
            this.optionPanel20.MyChildPanel.Controls.Add(this.radioHitsIncrementsHotspots);
            this.optionPanel20.MyChildPanel.Controls.Add(this.radioHitsIncrementsWeighted);
            this.optionPanel20.MyChildPanel.Controls.Add(this.radioHitsIncrementsInteger);
            this.optionPanel20.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel20.MyChildPanel.Enabled = false;
            this.optionPanel20.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel20.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel20.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel20.MyChildPanel.TabIndex = 14;
            this.optionPanel20.Name = "optionPanel20";
            this.optionPanel20.SettingType = null;
            this.optionPanel20.Size = new System.Drawing.Size(530, 32);
            this.optionPanel20.TabIndex = 31;
            // 
            // radioHitsIncrementsHotspots
            // 
            this.radioHitsIncrementsHotspots.AutoSize = true;
            this.radioHitsIncrementsHotspots.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsHotspots.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioHitsIncrementsHotspots.Location = new System.Drawing.Point(240, 0);
            this.radioHitsIncrementsHotspots.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioHitsIncrementsHotspots.Name = "radioHitsIncrementsHotspots";
            this.radioHitsIncrementsHotspots.Size = new System.Drawing.Size(120, 32);
            this.radioHitsIncrementsHotspots.TabIndex = 18;
            this.radioHitsIncrementsHotspots.Text = "Weighted \nwith Hotspots";
            this.radioHitsIncrementsHotspots.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsHotspots.UseVisualStyleBackColor = true;
            // 
            // radioHitsIncrementsWeighted
            // 
            this.radioHitsIncrementsWeighted.AutoSize = true;
            this.radioHitsIncrementsWeighted.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsWeighted.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioHitsIncrementsWeighted.Location = new System.Drawing.Point(120, 0);
            this.radioHitsIncrementsWeighted.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioHitsIncrementsWeighted.Name = "radioHitsIncrementsWeighted";
            this.radioHitsIncrementsWeighted.Size = new System.Drawing.Size(120, 32);
            this.radioHitsIncrementsWeighted.TabIndex = 17;
            this.radioHitsIncrementsWeighted.Text = "Weighted";
            this.radioHitsIncrementsWeighted.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsWeighted.UseVisualStyleBackColor = true;
            // 
            // radioHitsIncrementsInteger
            // 
            this.radioHitsIncrementsInteger.AutoSize = true;
            this.radioHitsIncrementsInteger.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsInteger.Checked = true;
            this.radioHitsIncrementsInteger.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioHitsIncrementsInteger.Location = new System.Drawing.Point(0, 0);
            this.radioHitsIncrementsInteger.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioHitsIncrementsInteger.Name = "radioHitsIncrementsInteger";
            this.radioHitsIncrementsInteger.Size = new System.Drawing.Size(120, 32);
            this.radioHitsIncrementsInteger.TabIndex = 16;
            this.radioHitsIncrementsInteger.TabStop = true;
            this.radioHitsIncrementsInteger.Text = "Integer";
            this.radioHitsIncrementsInteger.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsIncrementsInteger.UseVisualStyleBackColor = true;
            // 
            // optionPanel17
            // 
            this.optionPanel17.ContentLabelText = "Type";
            this.optionPanel17.ContentOverride = false;
            this.optionPanel17.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel17.Location = new System.Drawing.Point(0, 0);
            // 
            // optionPanel17.MyChildPanel
            // 
            this.optionPanel17.MyChildPanel.Controls.Add(this.radioHitsTotalCounts);
            this.optionPanel17.MyChildPanel.Controls.Add(this.radioHitsGeneCounts);
            this.optionPanel17.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel17.MyChildPanel.Enabled = false;
            this.optionPanel17.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel17.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel17.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel17.MyChildPanel.TabIndex = 14;
            this.optionPanel17.Name = "optionPanel17";
            this.optionPanel17.SettingType = null;
            this.optionPanel17.Size = new System.Drawing.Size(530, 32);
            this.optionPanel17.TabIndex = 29;
            // 
            // radioHitsTotalCounts
            // 
            this.radioHitsTotalCounts.AutoSize = true;
            this.radioHitsTotalCounts.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsTotalCounts.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioHitsTotalCounts.Location = new System.Drawing.Point(120, 0);
            this.radioHitsTotalCounts.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioHitsTotalCounts.Name = "radioHitsTotalCounts";
            this.radioHitsTotalCounts.Size = new System.Drawing.Size(120, 32);
            this.radioHitsTotalCounts.TabIndex = 17;
            this.radioHitsTotalCounts.Text = "Unlimited \n(Total counts)";
            this.radioHitsTotalCounts.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsTotalCounts.UseVisualStyleBackColor = true;
            // 
            // radioHitsGeneCounts
            // 
            this.radioHitsGeneCounts.AutoSize = true;
            this.radioHitsGeneCounts.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsGeneCounts.Checked = true;
            this.radioHitsGeneCounts.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioHitsGeneCounts.Location = new System.Drawing.Point(0, 0);
            this.radioHitsGeneCounts.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioHitsGeneCounts.Name = "radioHitsGeneCounts";
            this.radioHitsGeneCounts.Size = new System.Drawing.Size(120, 32);
            this.radioHitsGeneCounts.TabIndex = 16;
            this.radioHitsGeneCounts.TabStop = true;
            this.radioHitsGeneCounts.Text = "Once per gene \n(Gene counts)";
            this.radioHitsGeneCounts.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.radioHitsGeneCounts.UseVisualStyleBackColor = true;
            // 
            // tabPage5
            // 
            this.tabPage5.Controls.Add(this.optionPanel22);
            this.tabPage5.Controls.Add(this.optionPanel19);
            this.tabPage5.Location = new System.Drawing.Point(4, 22);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Size = new System.Drawing.Size(530, 395);
            this.tabPage5.TabIndex = 4;
            this.tabPage5.Text = "Scoring";
            this.tabPage5.UseVisualStyleBackColor = true;
            // 
            // optionPanel22
            // 
            this.optionPanel22.ContentLabelText = "PValue Correction";
            this.optionPanel22.ContentOverride = false;
            this.optionPanel22.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel22.Location = new System.Drawing.Point(0, 80);
            // 
            // optionPanel22.MyChildPanel
            // 
            this.optionPanel22.MyChildPanel.Controls.Add(this.radioScoringCorrectionNone);
            this.optionPanel22.MyChildPanel.Controls.Add(this.radioScoringCorrectionFDR);
            this.optionPanel22.MyChildPanel.Controls.Add(this.radioScoringCorrectionBonf);
            this.optionPanel22.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel22.MyChildPanel.Enabled = false;
            this.optionPanel22.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel22.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel22.MyChildPanel.Size = new System.Drawing.Size(388, 32);
            this.optionPanel22.MyChildPanel.TabIndex = 14;
            this.optionPanel22.Name = "optionPanel22";
            this.optionPanel22.SettingType = null;
            this.optionPanel22.Size = new System.Drawing.Size(530, 32);
            this.optionPanel22.TabIndex = 29;
            // 
            // radioScoringCorrectionNone
            // 
            this.radioScoringCorrectionNone.AutoSize = true;
            this.radioScoringCorrectionNone.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioScoringCorrectionNone.Location = new System.Drawing.Point(240, 0);
            this.radioScoringCorrectionNone.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioScoringCorrectionNone.Name = "radioScoringCorrectionNone";
            this.radioScoringCorrectionNone.Size = new System.Drawing.Size(120, 32);
            this.radioScoringCorrectionNone.TabIndex = 22;
            this.radioScoringCorrectionNone.Text = "None";
            this.radioScoringCorrectionNone.UseVisualStyleBackColor = true;
            // 
            // radioScoringCorrectionFDR
            // 
            this.radioScoringCorrectionFDR.AutoSize = true;
            this.radioScoringCorrectionFDR.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioScoringCorrectionFDR.Location = new System.Drawing.Point(120, 0);
            this.radioScoringCorrectionFDR.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioScoringCorrectionFDR.Name = "radioScoringCorrectionFDR";
            this.radioScoringCorrectionFDR.Size = new System.Drawing.Size(120, 32);
            this.radioScoringCorrectionFDR.TabIndex = 17;
            this.radioScoringCorrectionFDR.Text = "FDR";
            this.radioScoringCorrectionFDR.UseVisualStyleBackColor = true;
            // 
            // radioScoringCorrectionBonf
            // 
            this.radioScoringCorrectionBonf.AutoSize = true;
            this.radioScoringCorrectionBonf.Checked = true;
            this.radioScoringCorrectionBonf.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioScoringCorrectionBonf.Location = new System.Drawing.Point(0, 0);
            this.radioScoringCorrectionBonf.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioScoringCorrectionBonf.Name = "radioScoringCorrectionBonf";
            this.radioScoringCorrectionBonf.Size = new System.Drawing.Size(120, 32);
            this.radioScoringCorrectionBonf.TabIndex = 16;
            this.radioScoringCorrectionBonf.TabStop = true;
            this.radioScoringCorrectionBonf.Text = "Bonferroni";
            this.radioScoringCorrectionBonf.UseVisualStyleBackColor = true;
            // 
            // optionPanel19
            // 
            this.optionPanel19.ContentLabelText = "Type";
            this.optionPanel19.ContentOverride = false;
            this.optionPanel19.Dock = System.Windows.Forms.DockStyle.Top;
            this.optionPanel19.Location = new System.Drawing.Point(0, 0);
            // 
            // optionPanel19.MyChildPanel
            // 
            this.optionPanel19.MyChildPanel.Controls.Add(this.panelScoringTypeExponential);
            this.optionPanel19.MyChildPanel.Controls.Add(this.panel4);
            this.optionPanel19.MyChildPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionPanel19.MyChildPanel.Enabled = false;
            this.optionPanel19.MyChildPanel.Location = new System.Drawing.Point(142, 0);
            this.optionPanel19.MyChildPanel.Name = "MyChildPanel";
            this.optionPanel19.MyChildPanel.Size = new System.Drawing.Size(388, 80);
            this.optionPanel19.MyChildPanel.TabIndex = 14;
            this.optionPanel19.Name = "optionPanel19";
            this.optionPanel19.SettingType = null;
            this.optionPanel19.Size = new System.Drawing.Size(530, 80);
            this.optionPanel19.TabIndex = 28;
            // 
            // panelScoringTypeExponential
            // 
            this.panelScoringTypeExponential.AutoSize = true;
            this.panelScoringTypeExponential.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelScoringTypeExponential.Controls.Add(this.linkLabel15);
            this.panelScoringTypeExponential.Controls.Add(this.numericScoreingExplossBeta);
            this.panelScoringTypeExponential.Controls.Add(this.linkLabel16);
            this.panelScoringTypeExponential.Controls.Add(this.numericScoreingExplossAlpha);
            this.panelScoringTypeExponential.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelScoringTypeExponential.Location = new System.Drawing.Point(0, 32);
            this.panelScoringTypeExponential.Name = "panelScoringTypeExponential";
            this.panelScoringTypeExponential.Size = new System.Drawing.Size(388, 45);
            this.panelScoringTypeExponential.TabIndex = 24;
            this.panelScoringTypeExponential.Visible = false;
            // 
            // linkLabel15
            // 
            this.linkLabel15.AutoSize = true;
            this.linkLabel15.Location = new System.Drawing.Point(3, 0);
            this.linkLabel15.MinimumSize = new System.Drawing.Size(60, 0);
            this.linkLabel15.Name = "linkLabel15";
            this.linkLabel15.Size = new System.Drawing.Size(60, 13);
            this.linkLabel15.TabIndex = 20;
            this.linkLabel15.TabStop = true;
            this.linkLabel15.Text = "Alpha";
            // 
            // numericScoreingExplossBeta
            // 
            this.numericScoreingExplossBeta.DecimalPlaces = 2;
            this.numericScoreingExplossBeta.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericScoreingExplossBeta.Location = new System.Drawing.Point(63, 22);
            this.numericScoreingExplossBeta.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericScoreingExplossBeta.Name = "numericScoreingExplossBeta";
            this.numericScoreingExplossBeta.Size = new System.Drawing.Size(60, 20);
            this.numericScoreingExplossBeta.TabIndex = 23;
            this.numericScoreingExplossBeta.Value = new decimal(new int[] {
            15,
            0,
            0,
            65536});
            // 
            // linkLabel16
            // 
            this.linkLabel16.AutoSize = true;
            this.linkLabel16.Location = new System.Drawing.Point(3, 22);
            this.linkLabel16.MinimumSize = new System.Drawing.Size(60, 0);
            this.linkLabel16.Name = "linkLabel16";
            this.linkLabel16.Size = new System.Drawing.Size(60, 13);
            this.linkLabel16.TabIndex = 21;
            this.linkLabel16.TabStop = true;
            this.linkLabel16.Text = "Beta";
            // 
            // numericScoreingExplossAlpha
            // 
            this.numericScoreingExplossAlpha.DecimalPlaces = 2;
            this.numericScoreingExplossAlpha.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericScoreingExplossAlpha.Location = new System.Drawing.Point(63, 0);
            this.numericScoreingExplossAlpha.MinimumSize = new System.Drawing.Size(60, 0);
            this.numericScoreingExplossAlpha.Name = "numericScoreingExplossAlpha";
            this.numericScoreingExplossAlpha.Size = new System.Drawing.Size(60, 20);
            this.numericScoreingExplossAlpha.TabIndex = 22;
            this.numericScoreingExplossAlpha.Value = new decimal(new int[] {
            15,
            0,
            0,
            65536});
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.radioScoringHypergeo);
            this.panel4.Controls.Add(this.radioScoringTypeExponential);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel4.Location = new System.Drawing.Point(0, 0);
            this.panel4.MinimumSize = new System.Drawing.Size(0, 32);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(388, 32);
            this.panel4.TabIndex = 0;
            // 
            // radioScoringHypergeo
            // 
            this.radioScoringHypergeo.AutoSize = true;
            this.radioScoringHypergeo.Checked = true;
            this.radioScoringHypergeo.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioScoringHypergeo.Location = new System.Drawing.Point(120, 0);
            this.radioScoringHypergeo.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioScoringHypergeo.Name = "radioScoringHypergeo";
            this.radioScoringHypergeo.Size = new System.Drawing.Size(120, 32);
            this.radioScoringHypergeo.TabIndex = 16;
            this.radioScoringHypergeo.TabStop = true;
            this.radioScoringHypergeo.Text = "Hyper-Geometric";
            this.radioScoringHypergeo.UseVisualStyleBackColor = true;
            // 
            // radioScoringTypeExponential
            // 
            this.radioScoringTypeExponential.AutoSize = true;
            this.radioScoringTypeExponential.Dock = System.Windows.Forms.DockStyle.Left;
            this.radioScoringTypeExponential.Location = new System.Drawing.Point(0, 0);
            this.radioScoringTypeExponential.MinimumSize = new System.Drawing.Size(120, 0);
            this.radioScoringTypeExponential.Name = "radioScoringTypeExponential";
            this.radioScoringTypeExponential.Size = new System.Drawing.Size(120, 32);
            this.radioScoringTypeExponential.TabIndex = 17;
            this.radioScoringTypeExponential.Text = "Exponential";
            this.radioScoringTypeExponential.UseVisualStyleBackColor = true;
            this.radioScoringTypeExponential.CheckedChanged += new System.EventHandler(this.radioScoringTypeExponential_CheckedChanged);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.panelPreprocessingReverse);
            this.tabPage3.Controls.Add(this.panelSearchType);
            this.tabPage3.Controls.Add(this.panelPreprocessingDepth);
            this.tabPage3.Controls.Add(this.panelPreprocessingType);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(530, 395);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Preprocessing & Search";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // panelPreprocessingReverse
            // 
            this.panelPreprocessingReverse.AutoSize = true;
            this.panelPreprocessingReverse.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelPreprocessingReverse.Controls.Add(this.radioPreprocessingReverse);
            this.panelPreprocessingReverse.Controls.Add(this.radioPreprocessingNoReverse);
            this.panelPreprocessingReverse.Controls.Add(this.linkLabel13);
            this.panelPreprocessingReverse.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelPreprocessingReverse.Location = new System.Drawing.Point(0, 78);
            this.panelPreprocessingReverse.Name = "panelPreprocessingReverse";
            this.panelPreprocessingReverse.Size = new System.Drawing.Size(530, 25);
            this.panelPreprocessingReverse.TabIndex = 27;
            // 
            // radioPreprocessingReverse
            // 
            this.radioPreprocessingReverse.AutoSize = true;
            this.radioPreprocessingReverse.Location = new System.Drawing.Point(270, 5);
            this.radioPreprocessingReverse.Name = "radioPreprocessingReverse";
            this.radioPreprocessingReverse.Size = new System.Drawing.Size(43, 17);
            this.radioPreprocessingReverse.TabIndex = 17;
            this.radioPreprocessingReverse.Text = "Yes";
            this.radioPreprocessingReverse.UseVisualStyleBackColor = true;
            // 
            // radioPreprocessingNoReverse
            // 
            this.radioPreprocessingNoReverse.AutoSize = true;
            this.radioPreprocessingNoReverse.Checked = true;
            this.radioPreprocessingNoReverse.Location = new System.Drawing.Point(162, 3);
            this.radioPreprocessingNoReverse.Name = "radioPreprocessingNoReverse";
            this.radioPreprocessingNoReverse.Size = new System.Drawing.Size(39, 17);
            this.radioPreprocessingNoReverse.TabIndex = 16;
            this.radioPreprocessingNoReverse.TabStop = true;
            this.radioPreprocessingNoReverse.Text = "No";
            this.radioPreprocessingNoReverse.UseVisualStyleBackColor = true;
            // 
            // linkLabel13
            // 
            this.linkLabel13.AutoSize = true;
            this.linkLabel13.Location = new System.Drawing.Point(13, 5);
            this.linkLabel13.Name = "linkLabel13";
            this.linkLabel13.Size = new System.Drawing.Size(103, 13);
            this.linkLabel13.TabIndex = 13;
            this.linkLabel13.TabStop = true;
            this.linkLabel13.Text = "Use Reverse Strand";
            // 
            // panelSearchType
            // 
            this.panelSearchType.AutoSize = true;
            this.panelSearchType.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelSearchType.Controls.Add(this.radioSearchTypeTable);
            this.panelSearchType.Controls.Add(this.radioPreprocessingSearchTypeTree);
            this.panelSearchType.Controls.Add(this.linkLabel22);
            this.panelSearchType.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelSearchType.Location = new System.Drawing.Point(0, 54);
            this.panelSearchType.Name = "panelSearchType";
            this.panelSearchType.Size = new System.Drawing.Size(530, 24);
            this.panelSearchType.TabIndex = 26;
            // 
            // radioSearchTypeTable
            // 
            this.radioSearchTypeTable.AutoSize = true;
            this.radioSearchTypeTable.Location = new System.Drawing.Point(270, 4);
            this.radioSearchTypeTable.Name = "radioSearchTypeTable";
            this.radioSearchTypeTable.Size = new System.Drawing.Size(80, 17);
            this.radioSearchTypeTable.TabIndex = 19;
            this.radioSearchTypeTable.Text = "Hash Table";
            this.radioSearchTypeTable.UseVisualStyleBackColor = true;
            // 
            // radioPreprocessingSearchTypeTree
            // 
            this.radioPreprocessingSearchTypeTree.AutoSize = true;
            this.radioPreprocessingSearchTypeTree.Checked = true;
            this.radioPreprocessingSearchTypeTree.Location = new System.Drawing.Point(162, 3);
            this.radioPreprocessingSearchTypeTree.Name = "radioPreprocessingSearchTypeTree";
            this.radioPreprocessingSearchTypeTree.Size = new System.Drawing.Size(76, 17);
            this.radioPreprocessingSearchTypeTree.TabIndex = 18;
            this.radioPreprocessingSearchTypeTree.TabStop = true;
            this.radioPreprocessingSearchTypeTree.Text = "Prefix Tree";
            this.radioPreprocessingSearchTypeTree.UseVisualStyleBackColor = true;
            // 
            // linkLabel22
            // 
            this.linkLabel22.AutoSize = true;
            this.linkLabel22.Location = new System.Drawing.Point(13, 6);
            this.linkLabel22.Name = "linkLabel22";
            this.linkLabel22.Size = new System.Drawing.Size(68, 13);
            this.linkLabel22.TabIndex = 13;
            this.linkLabel22.TabStop = true;
            this.linkLabel22.Text = "Search Type";
            // 
            // panelPreprocessingType
            // 
            this.panelPreprocessingType.AutoSize = true;
            this.panelPreprocessingType.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelPreprocessingType.Controls.Add(this.radioPreprocessingTypeTable);
            this.panelPreprocessingType.Controls.Add(this.radioPreprocessingTypeTree);
            this.panelPreprocessingType.Controls.Add(this.linkLabel10);
            this.panelPreprocessingType.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelPreprocessingType.Location = new System.Drawing.Point(0, 0);
            this.panelPreprocessingType.Name = "panelPreprocessingType";
            this.panelPreprocessingType.Size = new System.Drawing.Size(530, 25);
            this.panelPreprocessingType.TabIndex = 24;
            // 
            // radioPreprocessingTypeTable
            // 
            this.radioPreprocessingTypeTable.AutoSize = true;
            this.radioPreprocessingTypeTable.Location = new System.Drawing.Point(270, 5);
            this.radioPreprocessingTypeTable.Name = "radioPreprocessingTypeTable";
            this.radioPreprocessingTypeTable.Size = new System.Drawing.Size(80, 17);
            this.radioPreprocessingTypeTable.TabIndex = 17;
            this.radioPreprocessingTypeTable.Text = "Hash Table";
            this.radioPreprocessingTypeTable.UseVisualStyleBackColor = true;
            // 
            // radioPreprocessingTypeTree
            // 
            this.radioPreprocessingTypeTree.AutoSize = true;
            this.radioPreprocessingTypeTree.Checked = true;
            this.radioPreprocessingTypeTree.Location = new System.Drawing.Point(159, 4);
            this.radioPreprocessingTypeTree.Name = "radioPreprocessingTypeTree";
            this.radioPreprocessingTypeTree.Size = new System.Drawing.Size(76, 17);
            this.radioPreprocessingTypeTree.TabIndex = 16;
            this.radioPreprocessingTypeTree.TabStop = true;
            this.radioPreprocessingTypeTree.Text = "Prefix Tree";
            this.radioPreprocessingTypeTree.UseVisualStyleBackColor = true;
            this.radioPreprocessingTypeTree.CheckedChanged += new System.EventHandler(this.radioPreprocessingTypeTree_CheckedChanged);
            // 
            // linkLabel10
            // 
            this.linkLabel10.AutoSize = true;
            this.linkLabel10.Location = new System.Drawing.Point(13, 5);
            this.linkLabel10.Name = "linkLabel10";
            this.linkLabel10.Size = new System.Drawing.Size(101, 13);
            this.linkLabel10.TabIndex = 13;
            this.linkLabel10.TabStop = true;
            this.linkLabel10.Text = "Preprocessing Type";
            // 
            // toolStrip1
            // 
            this.toolStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripSeparator1,
            this.toolStripSeparator2,
            this.toolStripButton4});
            this.toolStrip1.Location = new System.Drawing.Point(0, 3);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(49, 118);
            this.toolStrip1.TabIndex = 3;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addAStepToolStripMenuItem});
            this.toolStripButton1.Image = global::ConfEditor.Properties.Resources.PSSM;
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(47, 49);
            this.toolStripButton1.Text = "Init";
            this.toolStripButton1.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            // 
            // addAStepToolStripMenuItem
            // 
            this.addAStepToolStripMenuItem.Name = "addAStepToolStripMenuItem";
            this.addAStepToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.addAStepToolStripMenuItem.Text = "Add a step";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(47, 6);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(47, 6);
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addAStepToolStripMenuItem1});
            this.toolStripButton4.Image = global::ConfEditor.Properties.Resources.PSSM;
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(47, 49);
            this.toolStripButton4.Text = "Final";
            this.toolStripButton4.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            // 
            // addAStepToolStripMenuItem1
            // 
            this.addAStepToolStripMenuItem1.Name = "addAStepToolStripMenuItem1";
            this.addAStepToolStripMenuItem1.Size = new System.Drawing.Size(126, 22);
            this.addAStepToolStripMenuItem1.Text = "Add a step";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(587, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.openToolStripMenuItem.Text = "&Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.saveAsToolStripMenuItem.Text = "Save &As";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.aboutToolStripMenuItem.Text = "&About";
            // 
            // linkLabel11
            // 
            this.linkLabel11.AutoSize = true;
            this.linkLabel11.Location = new System.Drawing.Point(13, 6);
            this.linkLabel11.Name = "linkLabel11";
            this.linkLabel11.Size = new System.Drawing.Size(106, 13);
            this.linkLabel11.TabIndex = 13;
            this.linkLabel11.TabStop = true;
            this.linkLabel11.Text = "Preprocessing Depth";
            // 
            // numericPreprocessingDepth
            // 
            this.numericPreprocessingDepth.Location = new System.Drawing.Point(159, 6);
            this.numericPreprocessingDepth.Name = "numericPreprocessingDepth";
            this.numericPreprocessingDepth.Size = new System.Drawing.Size(52, 20);
            this.numericPreprocessingDepth.TabIndex = 17;
            this.numericPreprocessingDepth.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // panelPreprocessingDepth
            // 
            this.panelPreprocessingDepth.AutoSize = true;
            this.panelPreprocessingDepth.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelPreprocessingDepth.Controls.Add(this.numericPreprocessingDepth);
            this.panelPreprocessingDepth.Controls.Add(this.linkLabel11);
            this.panelPreprocessingDepth.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelPreprocessingDepth.Location = new System.Drawing.Point(0, 25);
            this.panelPreprocessingDepth.Name = "panelPreprocessingDepth";
            this.panelPreprocessingDepth.Size = new System.Drawing.Size(530, 29);
            this.panelPreprocessingDepth.TabIndex = 25;
            // 
            // ConfiGenForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(587, 445);
            this.Controls.Add(this.toolStripContainer1);
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(569, 389);
            this.Name = "ConfiGenForm";
            this.Text = "SNAP Configuration File Editor";
            this.toolStripContainer1.ContentPanel.ResumeLayout(false);
            this.toolStripContainer1.LeftToolStripPanel.ResumeLayout(false);
            this.toolStripContainer1.LeftToolStripPanel.PerformLayout();
            this.toolStripContainer1.TopToolStripPanel.ResumeLayout(false);
            this.toolStripContainer1.TopToolStripPanel.PerformLayout();
            this.toolStripContainer1.ResumeLayout(false);
            this.toolStripContainer1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage6.ResumeLayout(false);
            this.tabPage6.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.panel27.ResumeLayout(false);
            this.panel27.PerformLayout();
            this.panel26.ResumeLayout(false);
            this.panel26.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel28.ResumeLayout(false);
            this.panel28.PerformLayout();
            this.tabPage1.ResumeLayout(false);
            this.optionPanel18.MyChildPanel.ResumeLayout(false);
            this.optionPanel18.MyChildPanel.PerformLayout();
            this.optionPanel18.ResumeLayout(false);
            this.optionPanel18.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panelRandomSampling.MyChildPanel.ResumeLayout(false);
            this.panelRandomSampling.ResumeLayout(false);
            this.panelRandomSampling.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericRandomSamplingPredetermined)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.optionPanel16.MyChildPanel.ResumeLayout(false);
            this.optionPanel16.ResumeLayout(false);
            this.optionPanel16.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericSamplingRandom)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.optionPanel15.MyChildPanel.ResumeLayout(false);
            this.optionPanel15.MyChildPanel.PerformLayout();
            this.optionPanel15.ResumeLayout(false);
            this.optionPanel15.PerformLayout();
            this.optionPanel14.MyChildPanel.ResumeLayout(false);
            this.optionPanel14.MyChildPanel.PerformLayout();
            this.optionPanel14.ResumeLayout(false);
            this.optionPanel14.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsMidWildcards)).EndInit();
            this.panelProjectionWildcards.MyChildPanel.ResumeLayout(false);
            this.panelProjectionWildcards.MyChildPanel.PerformLayout();
            this.panelProjectionWildcards.ResumeLayout(false);
            this.panelProjectionWildcards.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsWildcards)).EndInit();
            this.panelProjectionLength.MyChildPanel.ResumeLayout(false);
            this.panelProjectionLength.MyChildPanel.PerformLayout();
            this.panelProjectionLength.ResumeLayout(false);
            this.panelProjectionLength.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsLength)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.optionPanel11.MyChildPanel.ResumeLayout(false);
            this.optionPanel11.MyChildPanel.PerformLayout();
            this.optionPanel11.ResumeLayout(false);
            this.optionPanel11.PerformLayout();
            this.optionPanel10.MyChildPanel.ResumeLayout(false);
            this.optionPanel10.MyChildPanel.PerformLayout();
            this.optionPanel10.ResumeLayout(false);
            this.optionPanel10.PerformLayout();
            this.optionPanel9.MyChildPanel.ResumeLayout(false);
            this.optionPanel9.MyChildPanel.PerformLayout();
            this.optionPanel9.ResumeLayout(false);
            this.optionPanel9.PerformLayout();
            this.optionPanel8.MyChildPanel.ResumeLayout(false);
            this.optionPanel8.MyChildPanel.PerformLayout();
            this.optionPanel8.ResumeLayout(false);
            this.optionPanel8.PerformLayout();
            this.optionPanel7.MyChildPanel.ResumeLayout(false);
            this.optionPanel7.MyChildPanel.PerformLayout();
            this.optionPanel7.ResumeLayout(false);
            this.optionPanel7.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHitsPercent)).EndInit();
            this.optionPanel6.MyChildPanel.ResumeLayout(false);
            this.optionPanel6.MyChildPanel.PerformLayout();
            this.optionPanel6.ResumeLayout(false);
            this.optionPanel6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHits)).EndInit();
            this.optionPanel5.MyChildPanel.ResumeLayout(false);
            this.optionPanel5.MyChildPanel.PerformLayout();
            this.optionPanel5.ResumeLayout(false);
            this.optionPanel5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinimumScore)).EndInit();
            this.optionPanel4.MyChildPanel.ResumeLayout(false);
            this.optionPanel4.MyChildPanel.PerformLayout();
            this.optionPanel4.ResumeLayout(false);
            this.optionPanel4.PerformLayout();
            this.optionPanel3.MyChildPanel.ResumeLayout(false);
            this.optionPanel3.MyChildPanel.PerformLayout();
            this.optionPanel3.ResumeLayout(false);
            this.optionPanel3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputRedundancyOffset)).EndInit();
            this.optionPanel2.MyChildPanel.ResumeLayout(false);
            this.optionPanel2.MyChildPanel.PerformLayout();
            this.optionPanel2.ResumeLayout(false);
            this.optionPanel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedL)).EndInit();
            this.optionPanel1.MyChildPanel.ResumeLayout(false);
            this.optionPanel1.MyChildPanel.PerformLayout();
            this.optionPanel1.ResumeLayout(false);
            this.optionPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedN)).EndInit();
            this.panel24.ResumeLayout(false);
            this.panel24.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.optionPanel21.MyChildPanel.ResumeLayout(false);
            this.optionPanel21.ResumeLayout(false);
            this.optionPanel21.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericHitsCutoff)).EndInit();
            this.optionPanel20.MyChildPanel.ResumeLayout(false);
            this.optionPanel20.MyChildPanel.PerformLayout();
            this.optionPanel20.ResumeLayout(false);
            this.optionPanel20.PerformLayout();
            this.optionPanel17.MyChildPanel.ResumeLayout(false);
            this.optionPanel17.MyChildPanel.PerformLayout();
            this.optionPanel17.ResumeLayout(false);
            this.optionPanel17.PerformLayout();
            this.tabPage5.ResumeLayout(false);
            this.optionPanel22.MyChildPanel.ResumeLayout(false);
            this.optionPanel22.MyChildPanel.PerformLayout();
            this.optionPanel22.ResumeLayout(false);
            this.optionPanel22.PerformLayout();
            this.optionPanel19.MyChildPanel.ResumeLayout(false);
            this.optionPanel19.MyChildPanel.PerformLayout();
            this.optionPanel19.ResumeLayout(false);
            this.optionPanel19.PerformLayout();
            this.panelScoringTypeExponential.ResumeLayout(false);
            this.panelScoringTypeExponential.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossBeta)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossAlpha)).EndInit();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.panelPreprocessingReverse.ResumeLayout(false);
            this.panelPreprocessingReverse.PerformLayout();
            this.panelSearchType.ResumeLayout(false);
            this.panelSearchType.PerformLayout();
            this.panelPreprocessingType.ResumeLayout(false);
            this.panelPreprocessingType.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericPreprocessingDepth)).EndInit();
            this.panelPreprocessingDepth.ResumeLayout(false);
            this.panelPreprocessingDepth.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.HelpProvider helpProvider1;
        private System.Windows.Forms.ToolStripContainer toolStripContainer1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.RadioButton radioProjectionsOuterWildcardsAllow;
        private System.Windows.Forms.RadioButton radioProjectionsOuterWildcards;
        private System.Windows.Forms.NumericUpDown numericProjectionsMidWildcards;
        private System.Windows.Forms.NumericUpDown numericProjectionsWildcards;
        private System.Windows.Forms.NumericUpDown numericProjectionsLength;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Panel panel24;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeaturesetNone;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeaturesetPos;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeatureseAll;
        private System.Windows.Forms.LinkLabel linkLabel26;
        private System.Windows.Forms.Panel panel23;
        private System.Windows.Forms.RadioButton radioOutputGenerateSamplePos;
        private System.Windows.Forms.Panel panel22;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifNone;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifPos;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifAll;
        private System.Windows.Forms.Panel panel21;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMNone;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMPos;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMAll;
        private System.Windows.Forms.NumericUpDown numericOutputMinPositiveHitsPercent;
        private System.Windows.Forms.Panel panel17;
        private System.Windows.Forms.NumericUpDown numericOutputMinPositiveHits;
        private System.Windows.Forms.Panel panel16;
        private System.Windows.Forms.NumericUpDown numericOutputMinimumScore;
        private System.Windows.Forms.RadioButton radioOutputIgnoreReverseRedundancy;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.NumericUpDown numericOutputRedundancyOffset;
        private System.Windows.Forms.NumericUpDown numericOutputSeedL;
        private System.Windows.Forms.NumericUpDown numericOutputSeedN;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.NumericUpDown numericHitsCutoff;
        private System.Windows.Forms.RadioButton radioHitsTotalCounts;
        private System.Windows.Forms.RadioButton radioHitsGeneCounts;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.RadioButton radioScoringCorrectionNone;
        private System.Windows.Forms.RadioButton radioScoringCorrectionFDR;
        private System.Windows.Forms.RadioButton radioScoringCorrectionBonf;
        private System.Windows.Forms.Panel panelScoringTypeExponential;
        private System.Windows.Forms.LinkLabel linkLabel15;
        private System.Windows.Forms.RadioButton radioScoringTypeExponential;
        private System.Windows.Forms.RadioButton radioScoringHypergeo;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Panel panelPreprocessingReverse;
        private System.Windows.Forms.RadioButton radioPreprocessingReverse;
        private System.Windows.Forms.RadioButton radioPreprocessingNoReverse;
        private System.Windows.Forms.LinkLabel linkLabel13;
        private System.Windows.Forms.Panel panelSearchType;
        private System.Windows.Forms.RadioButton radioSearchTypeTable;
        private System.Windows.Forms.RadioButton radioPreprocessingSearchTypeTree;
        private System.Windows.Forms.LinkLabel linkLabel22;
        private System.Windows.Forms.Panel panelPreprocessingType;
        private System.Windows.Forms.RadioButton radioPreprocessingTypeTable;
        private System.Windows.Forms.RadioButton radioPreprocessingTypeTree;
        private System.Windows.Forms.LinkLabel linkLabel10;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripSplitButton toolStripButton1;
        private System.Windows.Forms.ToolStripMenuItem addAStepToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripSplitButton toolStripButton4;
        private System.Windows.Forms.ToolStripMenuItem addAStepToolStripMenuItem1;
        private System.Windows.Forms.TextBox txtProjectionBaseManual;
        private System.Windows.Forms.RadioButton radioProjectionBaseManual;
        private System.Windows.Forms.NumericUpDown numericRandomSamplingPredetermined;
        private System.Windows.Forms.RadioButton radioRandomSamplingPredetermined;
        private System.Windows.Forms.RadioButton radioSamplingRandom;
        private System.Windows.Forms.Label lblProjectionMidWildcardsRange;
        private System.Windows.Forms.Label lblProjectionWildcardsRange;
        private System.Windows.Forms.RadioButton radioHitsIncrementsHotspots;
        private System.Windows.Forms.RadioButton radioHitsIncrementsWeighted;
        private System.Windows.Forms.RadioButton radioHitsIncrementsInteger;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Panel panel27;
        private System.Windows.Forms.TextBox txtInfoParameters;
        private System.Windows.Forms.LinkLabel linkLabel31;
        private System.Windows.Forms.Panel panel26;
        private System.Windows.Forms.TextBox txtInfoSectionName;
        private System.Windows.Forms.LinkLabel linkLabel30;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel28;
        private System.Windows.Forms.TextBox txtInfoFilename;
        private System.Windows.Forms.LinkLabel linkLabel32;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private Button button1;
        private OptionPanel optionPanel1;
        private OptionPanel optionPanel2;
        private OptionPanel optionPanel3;
        private OptionPanel optionPanel4;
        private OptionPanel optionPanel6;
        private OptionPanel optionPanel5;
        private OptionPanel optionPanel9;
        private OptionPanel optionPanel8;
        private OptionPanel optionPanel7;
        private OptionPanel optionPanel10;
        private RadioButton radioOutputGenerateSampleNone;
        private RadioButton radioOutputGenerateSampleAll;
        private OptionPanel optionPanel11;
        private OptionPanel panelProjectionLength;
        private Label lblProjectionLengthRange;
        private OptionPanel optionPanel14;
        private OptionPanel panelProjectionWildcards;
        private OptionPanel optionPanel16;
        private OptionPanel optionPanel15;
        private OptionPanel panelRandomSampling;
        private Panel panel2;
        private NumericUpDown numericSamplingRandom;
        private Panel panel1;
        private RadioButton radioSamplingExaustive;
        private OptionPanel optionPanel18;
        private Panel panel3;
        private RadioButton radioRandomSamplingRandomize;
        private RadioButton radioProjectionBaseDefault;
        private OptionPanel optionPanel21;
        private OptionPanel optionPanel20;
        private OptionPanel optionPanel17;
        private OptionPanel optionPanel19;
        private Panel panel4;
        private OptionPanel optionPanel22;
        private NumericUpDown numericScoreingExplossBeta;
        private LinkLabel linkLabel16;
        private NumericUpDown numericScoreingExplossAlpha;
        private Panel panelPreprocessingDepth;
        private NumericUpDown numericPreprocessingDepth;
        private LinkLabel linkLabel11;
    }
}