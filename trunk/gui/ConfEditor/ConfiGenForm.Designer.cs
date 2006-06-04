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
            this.toolStripContainer1 = new System.Windows.Forms.ToolStripContainer();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.panel27 = new System.Windows.Forms.Panel();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.linkLabel31 = new System.Windows.Forms.LinkLabel();
            this.panel26 = new System.Windows.Forms.Panel();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.linkLabel30 = new System.Windows.Forms.LinkLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel31 = new System.Windows.Forms.Panel();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.linkLabel35 = new System.Windows.Forms.LinkLabel();
            this.panel28 = new System.Windows.Forms.Panel();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.linkLabel32 = new System.Windows.Forms.LinkLabel();
            this.panel29 = new System.Windows.Forms.Panel();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.linkLabel33 = new System.Windows.Forms.LinkLabel();
            this.panel30 = new System.Windows.Forms.Panel();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.linkLabel34 = new System.Windows.Forms.LinkLabel();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.panel25 = new System.Windows.Forms.Panel();
            this.txtProjectionBaseManual = new System.Windows.Forms.TextBox();
            this.radioProjectionBaseDefault = new System.Windows.Forms.RadioButton();
            this.radioProjectionBaseManual = new System.Windows.Forms.RadioButton();
            this.linkLabel27 = new System.Windows.Forms.LinkLabel();
            this.panelRandomSampling = new System.Windows.Forms.Panel();
            this.numericRandomSamplingPredetermined = new System.Windows.Forms.NumericUpDown();
            this.radioButton32 = new System.Windows.Forms.RadioButton();
            this.radioRandomSamplingPredetermined = new System.Windows.Forms.RadioButton();
            this.linkLabel28 = new System.Windows.Forms.LinkLabel();
            this.panel5 = new System.Windows.Forms.Panel();
            this.numericSamplingRandom = new System.Windows.Forms.NumericUpDown();
            this.radioSamplingRandom = new System.Windows.Forms.RadioButton();
            this.radioButton5 = new System.Windows.Forms.RadioButton();
            this.linkLabel6 = new System.Windows.Forms.LinkLabel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.radioProjectionsOuterWildcardsAllow = new System.Windows.Forms.RadioButton();
            this.radioProjectionsOuterWildcards = new System.Windows.Forms.RadioButton();
            this.linkLabel3 = new System.Windows.Forms.LinkLabel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.lblProjectionMidWildcardsRange = new System.Windows.Forms.Label();
            this.numericProjectionsMidWildcards = new System.Windows.Forms.NumericUpDown();
            this.linkLabel5 = new System.Windows.Forms.LinkLabel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.lblProjectionWildcardsRange = new System.Windows.Forms.Label();
            this.numericProjectionsWildcards = new System.Windows.Forms.NumericUpDown();
            this.linkLabel4 = new System.Windows.Forms.LinkLabel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblProjectionLengthRange = new System.Windows.Forms.Label();
            this.numericProjectionsLength = new System.Windows.Forms.NumericUpDown();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.panel24 = new System.Windows.Forms.Panel();
            this.radioOutputGenerateFeaturesetNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateFeaturesetPos = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateFeatureseAll = new System.Windows.Forms.RadioButton();
            this.linkLabel26 = new System.Windows.Forms.LinkLabel();
            this.panel23 = new System.Windows.Forms.Panel();
            this.radioOutputGenerateSampleNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateSamplePos = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateSampleAll = new System.Windows.Forms.RadioButton();
            this.linkLabel25 = new System.Windows.Forms.LinkLabel();
            this.panel22 = new System.Windows.Forms.Panel();
            this.radioOutputGenerateMotifNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateMotifPos = new System.Windows.Forms.RadioButton();
            this.radioOutputGenerateMotifAll = new System.Windows.Forms.RadioButton();
            this.linkLabel24 = new System.Windows.Forms.LinkLabel();
            this.panel21 = new System.Windows.Forms.Panel();
            this.radioOutputGeneratePSSMNone = new System.Windows.Forms.RadioButton();
            this.radioOutputGeneratePSSMPos = new System.Windows.Forms.RadioButton();
            this.radioOutputGeneratePSSMAll = new System.Windows.Forms.RadioButton();
            this.linkLabel23 = new System.Windows.Forms.LinkLabel();
            this.panel18 = new System.Windows.Forms.Panel();
            this.numericOutputMinPositiveHitsPercent = new System.Windows.Forms.NumericUpDown();
            this.linkLabel20 = new System.Windows.Forms.LinkLabel();
            this.panel17 = new System.Windows.Forms.Panel();
            this.numericOutputMinPositiveHits = new System.Windows.Forms.NumericUpDown();
            this.linkLabel18 = new System.Windows.Forms.LinkLabel();
            this.panel16 = new System.Windows.Forms.Panel();
            this.numericOutputMinimumScore = new System.Windows.Forms.NumericUpDown();
            this.linkLabel17 = new System.Windows.Forms.LinkLabel();
            this.panel8 = new System.Windows.Forms.Panel();
            this.radioOutputIgnoreReverseRedundancy = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.linkLabel8 = new System.Windows.Forms.LinkLabel();
            this.panel7 = new System.Windows.Forms.Panel();
            this.numericOutputRedundancyOffset = new System.Windows.Forms.NumericUpDown();
            this.linkLabel7 = new System.Windows.Forms.LinkLabel();
            this.panel9 = new System.Windows.Forms.Panel();
            this.numericOutputSeedL = new System.Windows.Forms.NumericUpDown();
            this.linkLabel9 = new System.Windows.Forms.LinkLabel();
            this.panel6 = new System.Windows.Forms.Panel();
            this.numericOutputSeedN = new System.Windows.Forms.NumericUpDown();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.panel20 = new System.Windows.Forms.Panel();
            this.radioHitsIncrementsHotspots = new System.Windows.Forms.RadioButton();
            this.radioHitsIncrementsWeighted = new System.Windows.Forms.RadioButton();
            this.radioHitsIncrementsInteger = new System.Windows.Forms.RadioButton();
            this.linkLabel29 = new System.Windows.Forms.LinkLabel();
            this.panel19 = new System.Windows.Forms.Panel();
            this.numericHitsCutoff = new System.Windows.Forms.NumericUpDown();
            this.linkLabel21 = new System.Windows.Forms.LinkLabel();
            this.panel12 = new System.Windows.Forms.Panel();
            this.radioButton9 = new System.Windows.Forms.RadioButton();
            this.radioHitsGeneCounts = new System.Windows.Forms.RadioButton();
            this.linkLabel12 = new System.Windows.Forms.LinkLabel();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.panel15 = new System.Windows.Forms.Panel();
            this.radioScoringCorrectionNone = new System.Windows.Forms.RadioButton();
            this.radioScoringCorrectionFDR = new System.Windows.Forms.RadioButton();
            this.radioScoringCorrectionBonf = new System.Windows.Forms.RadioButton();
            this.linkLabel19 = new System.Windows.Forms.LinkLabel();
            this.panel14 = new System.Windows.Forms.Panel();
            this.panelScoringTypeExponential = new System.Windows.Forms.Panel();
            this.linkLabel15 = new System.Windows.Forms.LinkLabel();
            this.numericScoreingExplossBeta = new System.Windows.Forms.NumericUpDown();
            this.linkLabel16 = new System.Windows.Forms.LinkLabel();
            this.numericScoreingExplossAlpha = new System.Windows.Forms.NumericUpDown();
            this.radioScoringTypeExponential = new System.Windows.Forms.RadioButton();
            this.radioScoringHypergeo = new System.Windows.Forms.RadioButton();
            this.linkLabel14 = new System.Windows.Forms.LinkLabel();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.panel13 = new System.Windows.Forms.Panel();
            this.radioPreprocessingReverse = new System.Windows.Forms.RadioButton();
            this.radioPreprocessingNoReverse = new System.Windows.Forms.RadioButton();
            this.linkLabel13 = new System.Windows.Forms.LinkLabel();
            this.panelSearchType = new System.Windows.Forms.Panel();
            this.radioSearchTypeTable = new System.Windows.Forms.RadioButton();
            this.radioPreprocessingSearchTypeTree = new System.Windows.Forms.RadioButton();
            this.linkLabel22 = new System.Windows.Forms.LinkLabel();
            this.panel11 = new System.Windows.Forms.Panel();
            this.numericPreprocessingDepth = new System.Windows.Forms.NumericUpDown();
            this.linkLabel11 = new System.Windows.Forms.LinkLabel();
            this.panel10 = new System.Windows.Forms.Panel();
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
            this.panel31.SuspendLayout();
            this.panel28.SuspendLayout();
            this.panel29.SuspendLayout();
            this.panel30.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.panel25.SuspendLayout();
            this.panelRandomSampling.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericRandomSamplingPredetermined)).BeginInit();
            this.panel5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericSamplingRandom)).BeginInit();
            this.panel4.SuspendLayout();
            this.panel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsMidWildcards)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsWildcards)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsLength)).BeginInit();
            this.tabPage2.SuspendLayout();
            this.panel24.SuspendLayout();
            this.panel23.SuspendLayout();
            this.panel22.SuspendLayout();
            this.panel21.SuspendLayout();
            this.panel18.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHitsPercent)).BeginInit();
            this.panel17.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHits)).BeginInit();
            this.panel16.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinimumScore)).BeginInit();
            this.panel8.SuspendLayout();
            this.panel7.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputRedundancyOffset)).BeginInit();
            this.panel9.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedL)).BeginInit();
            this.panel6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedN)).BeginInit();
            this.tabPage4.SuspendLayout();
            this.panel20.SuspendLayout();
            this.panel19.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericHitsCutoff)).BeginInit();
            this.panel12.SuspendLayout();
            this.tabPage5.SuspendLayout();
            this.panel15.SuspendLayout();
            this.panel14.SuspendLayout();
            this.panelScoringTypeExponential.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossBeta)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossAlpha)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.panel13.SuspendLayout();
            this.panelSearchType.SuspendLayout();
            this.panel11.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericPreprocessingDepth)).BeginInit();
            this.panel10.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this.toolStripContainer1.ContentPanel.Controls.Add(this.tabControl1);
            this.toolStripContainer1.ContentPanel.Size = new System.Drawing.Size(512, 331);
            this.toolStripContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            // 
            // toolStripContainer1.LeftToolStripPanel
            // 
            this.toolStripContainer1.LeftToolStripPanel.Controls.Add(this.toolStrip1);
            this.toolStripContainer1.Location = new System.Drawing.Point(0, 0);
            this.toolStripContainer1.Name = "toolStripContainer1";
            this.toolStripContainer1.Size = new System.Drawing.Size(561, 355);
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
            this.tabControl1.Size = new System.Drawing.Size(512, 331);
            this.tabControl1.TabIndex = 15;
            // 
            // tabPage6
            // 
            this.tabPage6.Controls.Add(this.groupBox2);
            this.tabPage6.Controls.Add(this.groupBox1);
            this.tabPage6.Location = new System.Drawing.Point(4, 22);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Size = new System.Drawing.Size(504, 305);
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
            this.groupBox2.Location = new System.Drawing.Point(0, 150);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(504, 91);
            this.groupBox2.TabIndex = 23;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Section details";
            // 
            // panel27
            // 
            this.panel27.AutoSize = true;
            this.panel27.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel27.Controls.Add(this.textBox2);
            this.panel27.Controls.Add(this.linkLabel31);
            this.panel27.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel27.Location = new System.Drawing.Point(3, 44);
            this.panel27.Name = "panel27";
            this.panel27.Size = new System.Drawing.Size(498, 44);
            this.panel27.TabIndex = 21;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(128, 5);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(363, 36);
            this.textBox2.TabIndex = 19;
            // 
            // linkLabel31
            // 
            this.linkLabel31.AutoSize = true;
            this.linkLabel31.Location = new System.Drawing.Point(13, 5);
            this.linkLabel31.Name = "linkLabel31";
            this.linkLabel31.Size = new System.Drawing.Size(35, 13);
            this.linkLabel31.TabIndex = 13;
            this.linkLabel31.TabStop = true;
            this.linkLabel31.Text = "Notes";
            // 
            // panel26
            // 
            this.panel26.AutoSize = true;
            this.panel26.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel26.Controls.Add(this.textBox1);
            this.panel26.Controls.Add(this.linkLabel30);
            this.panel26.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel26.Location = new System.Drawing.Point(3, 16);
            this.panel26.Name = "panel26";
            this.panel26.Size = new System.Drawing.Size(498, 28);
            this.panel26.TabIndex = 20;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(128, 5);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(363, 20);
            this.textBox1.TabIndex = 19;
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
            this.groupBox1.Controls.Add(this.panel31);
            this.groupBox1.Controls.Add(this.panel28);
            this.groupBox1.Controls.Add(this.panel29);
            this.groupBox1.Controls.Add(this.panel30);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(504, 150);
            this.groupBox1.TabIndex = 22;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Resource details";
            // 
            // panel31
            // 
            this.panel31.AutoSize = true;
            this.panel31.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel31.Controls.Add(this.textBox6);
            this.panel31.Controls.Add(this.linkLabel35);
            this.panel31.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel31.Location = new System.Drawing.Point(3, 103);
            this.panel31.Name = "panel31";
            this.panel31.Size = new System.Drawing.Size(498, 44);
            this.panel31.TabIndex = 27;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(128, 5);
            this.textBox6.Multiline = true;
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(363, 36);
            this.textBox6.TabIndex = 19;
            // 
            // linkLabel35
            // 
            this.linkLabel35.AutoSize = true;
            this.linkLabel35.Location = new System.Drawing.Point(13, 5);
            this.linkLabel35.Name = "linkLabel35";
            this.linkLabel35.Size = new System.Drawing.Size(35, 13);
            this.linkLabel35.TabIndex = 13;
            this.linkLabel35.TabStop = true;
            this.linkLabel35.Text = "Notes";
            // 
            // panel28
            // 
            this.panel28.AutoSize = true;
            this.panel28.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel28.Controls.Add(this.textBox3);
            this.panel28.Controls.Add(this.linkLabel32);
            this.panel28.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel28.Location = new System.Drawing.Point(3, 74);
            this.panel28.Name = "panel28";
            this.panel28.Size = new System.Drawing.Size(498, 29);
            this.panel28.TabIndex = 26;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(128, 6);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(363, 20);
            this.textBox3.TabIndex = 19;
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
            // panel29
            // 
            this.panel29.AutoSize = true;
            this.panel29.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel29.Controls.Add(this.textBox4);
            this.panel29.Controls.Add(this.linkLabel33);
            this.panel29.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel29.Location = new System.Drawing.Point(3, 45);
            this.panel29.Name = "panel29";
            this.panel29.Size = new System.Drawing.Size(498, 29);
            this.panel29.TabIndex = 25;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(128, 6);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(363, 20);
            this.textBox4.TabIndex = 19;
            // 
            // linkLabel33
            // 
            this.linkLabel33.AutoSize = true;
            this.linkLabel33.Location = new System.Drawing.Point(13, 3);
            this.linkLabel33.Name = "linkLabel33";
            this.linkLabel33.Size = new System.Drawing.Size(36, 13);
            this.linkLabel33.TabIndex = 13;
            this.linkLabel33.TabStop = true;
            this.linkLabel33.Text = "Family";
            // 
            // panel30
            // 
            this.panel30.AutoSize = true;
            this.panel30.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel30.Controls.Add(this.textBox5);
            this.panel30.Controls.Add(this.linkLabel34);
            this.panel30.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel30.Location = new System.Drawing.Point(3, 16);
            this.panel30.Name = "panel30";
            this.panel30.Size = new System.Drawing.Size(498, 29);
            this.panel30.TabIndex = 24;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(128, 6);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(363, 20);
            this.textBox5.TabIndex = 19;
            // 
            // linkLabel34
            // 
            this.linkLabel34.AutoSize = true;
            this.linkLabel34.Location = new System.Drawing.Point(13, 3);
            this.linkLabel34.Name = "linkLabel34";
            this.linkLabel34.Size = new System.Drawing.Size(84, 13);
            this.linkLabel34.TabIndex = 13;
            this.linkLabel34.TabStop = true;
            this.linkLabel34.Text = "Resource Name";
            // 
            // tabPage1
            // 
            this.tabPage1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.tabPage1.Controls.Add(this.panel25);
            this.tabPage1.Controls.Add(this.panelRandomSampling);
            this.tabPage1.Controls.Add(this.panel5);
            this.tabPage1.Controls.Add(this.panel4);
            this.tabPage1.Controls.Add(this.panel3);
            this.tabPage1.Controls.Add(this.panel2);
            this.tabPage1.Controls.Add(this.panel1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(504, 305);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Projections";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // panel25
            // 
            this.panel25.AutoSize = true;
            this.panel25.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel25.Controls.Add(this.txtProjectionBaseManual);
            this.panel25.Controls.Add(this.radioProjectionBaseDefault);
            this.panel25.Controls.Add(this.radioProjectionBaseManual);
            this.panel25.Controls.Add(this.linkLabel27);
            this.panel25.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel25.Location = new System.Drawing.Point(3, 209);
            this.panel25.Name = "panel25";
            this.panel25.Size = new System.Drawing.Size(498, 53);
            this.panel25.TabIndex = 28;
            // 
            // txtProjectionBaseManual
            // 
            this.txtProjectionBaseManual.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtProjectionBaseManual.Font = new System.Drawing.Font("Courier New", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtProjectionBaseManual.Location = new System.Drawing.Point(214, 28);
            this.txtProjectionBaseManual.Name = "txtProjectionBaseManual";
            this.txtProjectionBaseManual.Size = new System.Drawing.Size(100, 22);
            this.txtProjectionBaseManual.TabIndex = 16;
            this.txtProjectionBaseManual.Text = "**********";
            this.txtProjectionBaseManual.Visible = false;
            // 
            // radioProjectionBaseDefault
            // 
            this.radioProjectionBaseDefault.AutoSize = true;
            this.radioProjectionBaseDefault.Checked = true;
            this.radioProjectionBaseDefault.Location = new System.Drawing.Point(134, 6);
            this.radioProjectionBaseDefault.Name = "radioProjectionBaseDefault";
            this.radioProjectionBaseDefault.Size = new System.Drawing.Size(59, 17);
            this.radioProjectionBaseDefault.TabIndex = 14;
            this.radioProjectionBaseDefault.TabStop = true;
            this.radioProjectionBaseDefault.Text = "Default";
            this.radioProjectionBaseDefault.UseVisualStyleBackColor = true;
            // 
            // radioProjectionBaseManual
            // 
            this.radioProjectionBaseManual.AutoSize = true;
            this.radioProjectionBaseManual.Location = new System.Drawing.Point(214, 5);
            this.radioProjectionBaseManual.Name = "radioProjectionBaseManual";
            this.radioProjectionBaseManual.Size = new System.Drawing.Size(60, 17);
            this.radioProjectionBaseManual.TabIndex = 15;
            this.radioProjectionBaseManual.Text = "Manual";
            this.radioProjectionBaseManual.UseVisualStyleBackColor = true;
            // 
            // linkLabel27
            // 
            this.linkLabel27.AutoSize = true;
            this.linkLabel27.Location = new System.Drawing.Point(13, 5);
            this.linkLabel27.Name = "linkLabel27";
            this.linkLabel27.Size = new System.Drawing.Size(81, 13);
            this.linkLabel27.TabIndex = 13;
            this.linkLabel27.TabStop = true;
            this.linkLabel27.Text = "Projection Base";
            // 
            // panelRandomSampling
            // 
            this.panelRandomSampling.AutoSize = true;
            this.panelRandomSampling.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelRandomSampling.Controls.Add(this.numericRandomSamplingPredetermined);
            this.panelRandomSampling.Controls.Add(this.radioButton32);
            this.panelRandomSampling.Controls.Add(this.radioRandomSamplingPredetermined);
            this.panelRandomSampling.Controls.Add(this.linkLabel28);
            this.panelRandomSampling.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelRandomSampling.Location = new System.Drawing.Point(3, 158);
            this.panelRandomSampling.Name = "panelRandomSampling";
            this.panelRandomSampling.Size = new System.Drawing.Size(498, 51);
            this.panelRandomSampling.TabIndex = 27;
            // 
            // numericRandomSamplingPredetermined
            // 
            this.numericRandomSamplingPredetermined.Location = new System.Drawing.Point(214, 28);
            this.numericRandomSamplingPredetermined.Name = "numericRandomSamplingPredetermined";
            this.numericRandomSamplingPredetermined.Size = new System.Drawing.Size(52, 20);
            this.numericRandomSamplingPredetermined.TabIndex = 18;
            this.numericRandomSamplingPredetermined.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericRandomSamplingPredetermined.Visible = false;
            // 
            // radioButton32
            // 
            this.radioButton32.AutoSize = true;
            this.radioButton32.Checked = true;
            this.radioButton32.Location = new System.Drawing.Point(134, 6);
            this.radioButton32.Name = "radioButton32";
            this.radioButton32.Size = new System.Drawing.Size(78, 17);
            this.radioButton32.TabIndex = 14;
            this.radioButton32.TabStop = true;
            this.radioButton32.Text = "Randomize";
            this.radioButton32.UseVisualStyleBackColor = true;
            // 
            // radioRandomSamplingPredetermined
            // 
            this.radioRandomSamplingPredetermined.AutoSize = true;
            this.radioRandomSamplingPredetermined.Location = new System.Drawing.Point(214, 5);
            this.radioRandomSamplingPredetermined.Name = "radioRandomSamplingPredetermined";
            this.radioRandomSamplingPredetermined.Size = new System.Drawing.Size(121, 17);
            this.radioRandomSamplingPredetermined.TabIndex = 15;
            this.radioRandomSamplingPredetermined.Text = "Predetermined Seed";
            this.radioRandomSamplingPredetermined.UseVisualStyleBackColor = true;
            this.radioRandomSamplingPredetermined.CheckedChanged += new System.EventHandler(this.radioRandomSamplingPredetermined_CheckedChanged);
            // 
            // linkLabel28
            // 
            this.linkLabel28.AutoSize = true;
            this.linkLabel28.Location = new System.Drawing.Point(13, 5);
            this.linkLabel28.Name = "linkLabel28";
            this.linkLabel28.Size = new System.Drawing.Size(93, 13);
            this.linkLabel28.TabIndex = 13;
            this.linkLabel28.TabStop = true;
            this.linkLabel28.Text = "Random Sampling";
            // 
            // panel5
            // 
            this.panel5.AutoSize = true;
            this.panel5.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel5.Controls.Add(this.numericSamplingRandom);
            this.panel5.Controls.Add(this.radioSamplingRandom);
            this.panel5.Controls.Add(this.radioButton5);
            this.panel5.Controls.Add(this.linkLabel6);
            this.panel5.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel5.Location = new System.Drawing.Point(3, 106);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(498, 52);
            this.panel5.TabIndex = 26;
            // 
            // numericSamplingRandom
            // 
            this.numericSamplingRandom.Location = new System.Drawing.Point(134, 29);
            this.numericSamplingRandom.Name = "numericSamplingRandom";
            this.numericSamplingRandom.Size = new System.Drawing.Size(52, 20);
            this.numericSamplingRandom.TabIndex = 18;
            this.numericSamplingRandom.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // radioSamplingRandom
            // 
            this.radioSamplingRandom.AutoSize = true;
            this.radioSamplingRandom.Checked = true;
            this.radioSamplingRandom.Location = new System.Drawing.Point(134, 6);
            this.radioSamplingRandom.Name = "radioSamplingRandom";
            this.radioSamplingRandom.Size = new System.Drawing.Size(65, 17);
            this.radioSamplingRandom.TabIndex = 14;
            this.radioSamplingRandom.TabStop = true;
            this.radioSamplingRandom.Text = "Random";
            this.radioSamplingRandom.UseVisualStyleBackColor = true;
            this.radioSamplingRandom.CheckedChanged += new System.EventHandler(this.radioSamplingRandom_CheckedChanged_1);
            // 
            // radioButton5
            // 
            this.radioButton5.AutoSize = true;
            this.radioButton5.Location = new System.Drawing.Point(214, 5);
            this.radioButton5.Name = "radioButton5";
            this.radioButton5.Size = new System.Drawing.Size(77, 17);
            this.radioButton5.TabIndex = 15;
            this.radioButton5.Text = "Exhaustive";
            this.radioButton5.UseVisualStyleBackColor = true;
            // 
            // linkLabel6
            // 
            this.linkLabel6.AutoSize = true;
            this.linkLabel6.Location = new System.Drawing.Point(13, 5);
            this.linkLabel6.Name = "linkLabel6";
            this.linkLabel6.Size = new System.Drawing.Size(50, 13);
            this.linkLabel6.TabIndex = 13;
            this.linkLabel6.TabStop = true;
            this.linkLabel6.Text = "Sampling";
            // 
            // panel4
            // 
            this.panel4.AutoSize = true;
            this.panel4.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel4.Controls.Add(this.radioProjectionsOuterWildcardsAllow);
            this.panel4.Controls.Add(this.radioProjectionsOuterWildcards);
            this.panel4.Controls.Add(this.linkLabel3);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel4.Location = new System.Drawing.Point(3, 81);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(498, 25);
            this.panel4.TabIndex = 20;
            // 
            // radioProjectionsOuterWildcardsAllow
            // 
            this.radioProjectionsOuterWildcardsAllow.AutoSize = true;
            this.radioProjectionsOuterWildcardsAllow.Location = new System.Drawing.Point(214, 5);
            this.radioProjectionsOuterWildcardsAllow.Name = "radioProjectionsOuterWildcardsAllow";
            this.radioProjectionsOuterWildcardsAllow.Size = new System.Drawing.Size(50, 17);
            this.radioProjectionsOuterWildcardsAllow.TabIndex = 15;
            this.radioProjectionsOuterWildcardsAllow.Text = "Allow";
            this.radioProjectionsOuterWildcardsAllow.UseVisualStyleBackColor = true;
            this.radioProjectionsOuterWildcardsAllow.CheckedChanged += new System.EventHandler(this.radioProjectionsOuterWildcardsAllow_CheckedChanged);
            // 
            // radioProjectionsOuterWildcards
            // 
            this.radioProjectionsOuterWildcards.AutoSize = true;
            this.radioProjectionsOuterWildcards.Checked = true;
            this.radioProjectionsOuterWildcards.Location = new System.Drawing.Point(134, 3);
            this.radioProjectionsOuterWildcards.Name = "radioProjectionsOuterWildcards";
            this.radioProjectionsOuterWildcards.Size = new System.Drawing.Size(64, 17);
            this.radioProjectionsOuterWildcards.TabIndex = 14;
            this.radioProjectionsOuterWildcards.TabStop = true;
            this.radioProjectionsOuterWildcards.Text = "Disallow";
            this.radioProjectionsOuterWildcards.UseVisualStyleBackColor = true;
            // 
            // linkLabel3
            // 
            this.linkLabel3.AutoSize = true;
            this.linkLabel3.Location = new System.Drawing.Point(13, 5);
            this.linkLabel3.Name = "linkLabel3";
            this.linkLabel3.Size = new System.Drawing.Size(80, 13);
            this.linkLabel3.TabIndex = 13;
            this.linkLabel3.TabStop = true;
            this.linkLabel3.Text = "Outer wildcards";
            // 
            // panel3
            // 
            this.panel3.AutoSize = true;
            this.panel3.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel3.Controls.Add(this.lblProjectionMidWildcardsRange);
            this.panel3.Controls.Add(this.numericProjectionsMidWildcards);
            this.panel3.Controls.Add(this.linkLabel5);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel3.Location = new System.Drawing.Point(3, 55);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(498, 26);
            this.panel3.TabIndex = 19;
            // 
            // lblProjectionMidWildcardsRange
            // 
            this.lblProjectionMidWildcardsRange.AutoSize = true;
            this.lblProjectionMidWildcardsRange.Location = new System.Drawing.Point(193, 5);
            this.lblProjectionMidWildcardsRange.Name = "lblProjectionMidWildcardsRange";
            this.lblProjectionMidWildcardsRange.Size = new System.Drawing.Size(34, 13);
            this.lblProjectionMidWildcardsRange.TabIndex = 19;
            this.lblProjectionMidWildcardsRange.Text = "(0 - 8)";
            this.lblProjectionMidWildcardsRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsMidWildcards
            // 
            this.numericProjectionsMidWildcards.Location = new System.Drawing.Point(135, 3);
            this.numericProjectionsMidWildcards.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericProjectionsMidWildcards.Name = "numericProjectionsMidWildcards";
            this.numericProjectionsMidWildcards.Size = new System.Drawing.Size(52, 20);
            this.numericProjectionsMidWildcards.TabIndex = 17;
            this.numericProjectionsMidWildcards.Tag = 0;
            this.numericProjectionsMidWildcards.ValueChanged += new System.EventHandler(this.numericProjectionsMidWildcards_ValueChanged);
            // 
            // linkLabel5
            // 
            this.linkLabel5.AutoSize = true;
            this.linkLabel5.Location = new System.Drawing.Point(13, 5);
            this.linkLabel5.Name = "linkLabel5";
            this.linkLabel5.Size = new System.Drawing.Size(88, 13);
            this.linkLabel5.TabIndex = 13;
            this.linkLabel5.TabStop = true;
            this.linkLabel5.Text = "Middle Wildcards";
            // 
            // panel2
            // 
            this.panel2.AutoSize = true;
            this.panel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel2.Controls.Add(this.lblProjectionWildcardsRange);
            this.panel2.Controls.Add(this.numericProjectionsWildcards);
            this.panel2.Controls.Add(this.linkLabel4);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(3, 29);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(498, 26);
            this.panel2.TabIndex = 18;
            // 
            // lblProjectionWildcardsRange
            // 
            this.lblProjectionWildcardsRange.AutoSize = true;
            this.lblProjectionWildcardsRange.Location = new System.Drawing.Point(193, 5);
            this.lblProjectionWildcardsRange.Name = "lblProjectionWildcardsRange";
            this.lblProjectionWildcardsRange.Size = new System.Drawing.Size(34, 13);
            this.lblProjectionWildcardsRange.TabIndex = 19;
            this.lblProjectionWildcardsRange.Text = "(0 - 8)";
            this.lblProjectionWildcardsRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsWildcards
            // 
            this.numericProjectionsWildcards.Location = new System.Drawing.Point(135, 3);
            this.numericProjectionsWildcards.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.numericProjectionsWildcards.Name = "numericProjectionsWildcards";
            this.numericProjectionsWildcards.Size = new System.Drawing.Size(52, 20);
            this.numericProjectionsWildcards.TabIndex = 17;
            this.numericProjectionsWildcards.Tag = 3;
            this.numericProjectionsWildcards.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // linkLabel4
            // 
            this.linkLabel4.AutoSize = true;
            this.linkLabel4.Location = new System.Drawing.Point(13, 5);
            this.linkLabel4.Name = "linkLabel4";
            this.linkLabel4.Size = new System.Drawing.Size(54, 13);
            this.linkLabel4.TabIndex = 13;
            this.linkLabel4.TabStop = true;
            this.linkLabel4.Text = "Wildcards";
            // 
            // panel1
            // 
            this.panel1.AutoSize = true;
            this.panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel1.Controls.Add(this.lblProjectionLengthRange);
            this.panel1.Controls.Add(this.numericProjectionsLength);
            this.panel1.Controls.Add(this.linkLabel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(498, 26);
            this.panel1.TabIndex = 17;
            // 
            // lblProjectionLengthRange
            // 
            this.lblProjectionLengthRange.AutoSize = true;
            this.lblProjectionLengthRange.Location = new System.Drawing.Point(193, 5);
            this.lblProjectionLengthRange.Name = "lblProjectionLengthRange";
            this.lblProjectionLengthRange.Size = new System.Drawing.Size(40, 13);
            this.lblProjectionLengthRange.TabIndex = 18;
            this.lblProjectionLengthRange.Text = "(5 - 20)";
            this.lblProjectionLengthRange.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // numericProjectionsLength
            // 
            this.numericProjectionsLength.Location = new System.Drawing.Point(135, 3);
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
            this.numericProjectionsLength.Name = "numericProjectionsLength";
            this.numericProjectionsLength.Size = new System.Drawing.Size(52, 20);
            this.numericProjectionsLength.TabIndex = 17;
            this.numericProjectionsLength.Tag = 10;
            this.numericProjectionsLength.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericProjectionsLength.ValueChanged += new System.EventHandler(this.numericProjectionsLength_ValueChanged);
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point(13, 5);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(40, 13);
            this.linkLabel2.TabIndex = 13;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "Length";
            // 
            // tabPage2
            // 
            this.tabPage2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.tabPage2.Controls.Add(this.panel24);
            this.tabPage2.Controls.Add(this.panel23);
            this.tabPage2.Controls.Add(this.panel22);
            this.tabPage2.Controls.Add(this.panel21);
            this.tabPage2.Controls.Add(this.panel18);
            this.tabPage2.Controls.Add(this.panel17);
            this.tabPage2.Controls.Add(this.panel16);
            this.tabPage2.Controls.Add(this.panel8);
            this.tabPage2.Controls.Add(this.panel7);
            this.tabPage2.Controls.Add(this.panel9);
            this.tabPage2.Controls.Add(this.panel6);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(504, 305);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Output";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // panel24
            // 
            this.panel24.AutoSize = true;
            this.panel24.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel24.Controls.Add(this.radioOutputGenerateFeaturesetNone);
            this.panel24.Controls.Add(this.radioOutputGenerateFeaturesetPos);
            this.panel24.Controls.Add(this.radioOutputGenerateFeatureseAll);
            this.panel24.Controls.Add(this.linkLabel26);
            this.panel24.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel24.Location = new System.Drawing.Point(3, 269);
            this.panel24.Name = "panel24";
            this.panel24.Size = new System.Drawing.Size(498, 26);
            this.panel24.TabIndex = 30;
            // 
            // radioOutputGenerateFeaturesetNone
            // 
            this.radioOutputGenerateFeaturesetNone.AutoSize = true;
            this.radioOutputGenerateFeaturesetNone.Location = new System.Drawing.Point(390, 6);
            this.radioOutputGenerateFeaturesetNone.Name = "radioOutputGenerateFeaturesetNone";
            this.radioOutputGenerateFeaturesetNone.Size = new System.Drawing.Size(39, 17);
            this.radioOutputGenerateFeaturesetNone.TabIndex = 18;
            this.radioOutputGenerateFeaturesetNone.Text = "No";
            this.radioOutputGenerateFeaturesetNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateFeaturesetPos
            // 
            this.radioOutputGenerateFeaturesetPos.AutoSize = true;
            this.radioOutputGenerateFeaturesetPos.Checked = true;
            this.radioOutputGenerateFeaturesetPos.Location = new System.Drawing.Point(171, 4);
            this.radioOutputGenerateFeaturesetPos.Name = "radioOutputGenerateFeaturesetPos";
            this.radioOutputGenerateFeaturesetPos.Size = new System.Drawing.Size(118, 17);
            this.radioOutputGenerateFeaturesetPos.TabIndex = 17;
            this.radioOutputGenerateFeaturesetPos.TabStop = true;
            this.radioOutputGenerateFeaturesetPos.Text = "Only the best seeds";
            this.radioOutputGenerateFeaturesetPos.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateFeatureseAll
            // 
            this.radioOutputGenerateFeatureseAll.AutoSize = true;
            this.radioOutputGenerateFeatureseAll.Location = new System.Drawing.Point(307, 5);
            this.radioOutputGenerateFeatureseAll.Name = "radioOutputGenerateFeatureseAll";
            this.radioOutputGenerateFeatureseAll.Size = new System.Drawing.Size(69, 17);
            this.radioOutputGenerateFeatureseAll.TabIndex = 16;
            this.radioOutputGenerateFeatureseAll.Text = "All Seeds";
            this.radioOutputGenerateFeatureseAll.UseVisualStyleBackColor = true;
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
            this.panel23.Controls.Add(this.radioOutputGenerateSampleNone);
            this.panel23.Controls.Add(this.radioOutputGenerateSamplePos);
            this.panel23.Controls.Add(this.radioOutputGenerateSampleAll);
            this.panel23.Controls.Add(this.linkLabel25);
            this.panel23.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel23.Location = new System.Drawing.Point(3, 243);
            this.panel23.Name = "panel23";
            this.panel23.Size = new System.Drawing.Size(498, 26);
            this.panel23.TabIndex = 29;
            // 
            // radioOutputGenerateSampleNone
            // 
            this.radioOutputGenerateSampleNone.AutoSize = true;
            this.radioOutputGenerateSampleNone.Checked = true;
            this.radioOutputGenerateSampleNone.Location = new System.Drawing.Point(390, 6);
            this.radioOutputGenerateSampleNone.Name = "radioOutputGenerateSampleNone";
            this.radioOutputGenerateSampleNone.Size = new System.Drawing.Size(39, 17);
            this.radioOutputGenerateSampleNone.TabIndex = 18;
            this.radioOutputGenerateSampleNone.TabStop = true;
            this.radioOutputGenerateSampleNone.Text = "No";
            this.radioOutputGenerateSampleNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateSamplePos
            // 
            this.radioOutputGenerateSamplePos.AutoSize = true;
            this.radioOutputGenerateSamplePos.Location = new System.Drawing.Point(171, 4);
            this.radioOutputGenerateSamplePos.Name = "radioOutputGenerateSamplePos";
            this.radioOutputGenerateSamplePos.Size = new System.Drawing.Size(119, 17);
            this.radioOutputGenerateSamplePos.TabIndex = 17;
            this.radioOutputGenerateSamplePos.Text = "Only for positive hits";
            this.radioOutputGenerateSamplePos.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateSampleAll
            // 
            this.radioOutputGenerateSampleAll.AutoSize = true;
            this.radioOutputGenerateSampleAll.Location = new System.Drawing.Point(307, 5);
            this.radioOutputGenerateSampleAll.Name = "radioOutputGenerateSampleAll";
            this.radioOutputGenerateSampleAll.Size = new System.Drawing.Size(43, 17);
            this.radioOutputGenerateSampleAll.TabIndex = 16;
            this.radioOutputGenerateSampleAll.Text = "Yes";
            this.radioOutputGenerateSampleAll.UseVisualStyleBackColor = true;
            // 
            // linkLabel25
            // 
            this.linkLabel25.AutoSize = true;
            this.linkLabel25.Location = new System.Drawing.Point(13, 4);
            this.linkLabel25.Name = "linkLabel25";
            this.linkLabel25.Size = new System.Drawing.Size(121, 13);
            this.linkLabel25.TabIndex = 13;
            this.linkLabel25.TabStop = true;
            this.linkLabel25.Text = "Generate SAMPLE Files";
            // 
            // panel22
            // 
            this.panel22.AutoSize = true;
            this.panel22.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel22.Controls.Add(this.radioOutputGenerateMotifNone);
            this.panel22.Controls.Add(this.radioOutputGenerateMotifPos);
            this.panel22.Controls.Add(this.radioOutputGenerateMotifAll);
            this.panel22.Controls.Add(this.linkLabel24);
            this.panel22.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel22.Location = new System.Drawing.Point(3, 217);
            this.panel22.Name = "panel22";
            this.panel22.Size = new System.Drawing.Size(498, 26);
            this.panel22.TabIndex = 28;
            // 
            // radioOutputGenerateMotifNone
            // 
            this.radioOutputGenerateMotifNone.AutoSize = true;
            this.radioOutputGenerateMotifNone.Location = new System.Drawing.Point(390, 6);
            this.radioOutputGenerateMotifNone.Name = "radioOutputGenerateMotifNone";
            this.radioOutputGenerateMotifNone.Size = new System.Drawing.Size(39, 17);
            this.radioOutputGenerateMotifNone.TabIndex = 18;
            this.radioOutputGenerateMotifNone.Text = "No";
            this.radioOutputGenerateMotifNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateMotifPos
            // 
            this.radioOutputGenerateMotifPos.AutoSize = true;
            this.radioOutputGenerateMotifPos.Location = new System.Drawing.Point(171, 4);
            this.radioOutputGenerateMotifPos.Name = "radioOutputGenerateMotifPos";
            this.radioOutputGenerateMotifPos.Size = new System.Drawing.Size(119, 17);
            this.radioOutputGenerateMotifPos.TabIndex = 17;
            this.radioOutputGenerateMotifPos.Text = "Only for positive hits";
            this.radioOutputGenerateMotifPos.UseVisualStyleBackColor = true;
            // 
            // radioOutputGenerateMotifAll
            // 
            this.radioOutputGenerateMotifAll.AutoSize = true;
            this.radioOutputGenerateMotifAll.Checked = true;
            this.radioOutputGenerateMotifAll.Location = new System.Drawing.Point(307, 5);
            this.radioOutputGenerateMotifAll.Name = "radioOutputGenerateMotifAll";
            this.radioOutputGenerateMotifAll.Size = new System.Drawing.Size(43, 17);
            this.radioOutputGenerateMotifAll.TabIndex = 16;
            this.radioOutputGenerateMotifAll.TabStop = true;
            this.radioOutputGenerateMotifAll.Text = "Yes";
            this.radioOutputGenerateMotifAll.UseVisualStyleBackColor = true;
            // 
            // linkLabel24
            // 
            this.linkLabel24.AutoSize = true;
            this.linkLabel24.Location = new System.Drawing.Point(13, 4);
            this.linkLabel24.Name = "linkLabel24";
            this.linkLabel24.Size = new System.Drawing.Size(111, 13);
            this.linkLabel24.TabIndex = 13;
            this.linkLabel24.TabStop = true;
            this.linkLabel24.Text = "Generate MOTIF Files";
            // 
            // panel21
            // 
            this.panel21.AutoSize = true;
            this.panel21.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel21.Controls.Add(this.radioOutputGeneratePSSMNone);
            this.panel21.Controls.Add(this.radioOutputGeneratePSSMPos);
            this.panel21.Controls.Add(this.radioOutputGeneratePSSMAll);
            this.panel21.Controls.Add(this.linkLabel23);
            this.panel21.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel21.Location = new System.Drawing.Point(3, 192);
            this.panel21.Name = "panel21";
            this.panel21.Size = new System.Drawing.Size(498, 25);
            this.panel21.TabIndex = 27;
            // 
            // radioOutputGeneratePSSMNone
            // 
            this.radioOutputGeneratePSSMNone.AutoSize = true;
            this.radioOutputGeneratePSSMNone.Location = new System.Drawing.Point(390, 5);
            this.radioOutputGeneratePSSMNone.Name = "radioOutputGeneratePSSMNone";
            this.radioOutputGeneratePSSMNone.Size = new System.Drawing.Size(39, 17);
            this.radioOutputGeneratePSSMNone.TabIndex = 18;
            this.radioOutputGeneratePSSMNone.Text = "No";
            this.radioOutputGeneratePSSMNone.UseVisualStyleBackColor = true;
            // 
            // radioOutputGeneratePSSMPos
            // 
            this.radioOutputGeneratePSSMPos.AutoSize = true;
            this.radioOutputGeneratePSSMPos.Checked = true;
            this.radioOutputGeneratePSSMPos.Location = new System.Drawing.Point(171, 4);
            this.radioOutputGeneratePSSMPos.Name = "radioOutputGeneratePSSMPos";
            this.radioOutputGeneratePSSMPos.Size = new System.Drawing.Size(119, 17);
            this.radioOutputGeneratePSSMPos.TabIndex = 17;
            this.radioOutputGeneratePSSMPos.TabStop = true;
            this.radioOutputGeneratePSSMPos.Text = "Only for positive hits";
            this.radioOutputGeneratePSSMPos.UseVisualStyleBackColor = true;
            // 
            // radioOutputGeneratePSSMAll
            // 
            this.radioOutputGeneratePSSMAll.AutoSize = true;
            this.radioOutputGeneratePSSMAll.Location = new System.Drawing.Point(307, 5);
            this.radioOutputGeneratePSSMAll.Name = "radioOutputGeneratePSSMAll";
            this.radioOutputGeneratePSSMAll.Size = new System.Drawing.Size(43, 17);
            this.radioOutputGeneratePSSMAll.TabIndex = 16;
            this.radioOutputGeneratePSSMAll.Text = "Yes";
            this.radioOutputGeneratePSSMAll.UseVisualStyleBackColor = true;
            // 
            // linkLabel23
            // 
            this.linkLabel23.AutoSize = true;
            this.linkLabel23.Location = new System.Drawing.Point(13, 4);
            this.linkLabel23.Name = "linkLabel23";
            this.linkLabel23.Size = new System.Drawing.Size(108, 13);
            this.linkLabel23.TabIndex = 13;
            this.linkLabel23.TabStop = true;
            this.linkLabel23.Text = "Generate PSSM Files";
            // 
            // panel18
            // 
            this.panel18.AutoSize = true;
            this.panel18.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel18.Controls.Add(this.numericOutputMinPositiveHitsPercent);
            this.panel18.Controls.Add(this.linkLabel20);
            this.panel18.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel18.Location = new System.Drawing.Point(3, 169);
            this.panel18.Name = "panel18";
            this.panel18.Size = new System.Drawing.Size(498, 23);
            this.panel18.TabIndex = 26;
            // 
            // numericOutputMinPositiveHitsPercent
            // 
            this.numericOutputMinPositiveHitsPercent.Location = new System.Drawing.Point(171, 0);
            this.numericOutputMinPositiveHitsPercent.Name = "numericOutputMinPositiveHitsPercent";
            this.numericOutputMinPositiveHitsPercent.Size = new System.Drawing.Size(52, 20);
            this.numericOutputMinPositiveHitsPercent.TabIndex = 18;
            this.numericOutputMinPositiveHitsPercent.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericOutputMinPositiveHitsPercent.ValueChanged += new System.EventHandler(this.numericUpDown11_ValueChanged);
            // 
            // linkLabel20
            // 
            this.linkLabel20.AutoSize = true;
            this.linkLabel20.Location = new System.Drawing.Point(13, 7);
            this.linkLabel20.Name = "linkLabel20";
            this.linkLabel20.Size = new System.Drawing.Size(126, 13);
            this.linkLabel20.TabIndex = 13;
            this.linkLabel20.TabStop = true;
            this.linkLabel20.Text = "Minimum Positive Hits (%)";
            // 
            // panel17
            // 
            this.panel17.AutoSize = true;
            this.panel17.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel17.Controls.Add(this.numericOutputMinPositiveHits);
            this.panel17.Controls.Add(this.linkLabel18);
            this.panel17.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel17.Location = new System.Drawing.Point(3, 146);
            this.panel17.Name = "panel17";
            this.panel17.Size = new System.Drawing.Size(498, 23);
            this.panel17.TabIndex = 25;
            // 
            // numericOutputMinPositiveHits
            // 
            this.numericOutputMinPositiveHits.DecimalPlaces = 2;
            this.numericOutputMinPositiveHits.Location = new System.Drawing.Point(171, 0);
            this.numericOutputMinPositiveHits.Name = "numericOutputMinPositiveHits";
            this.numericOutputMinPositiveHits.Size = new System.Drawing.Size(52, 20);
            this.numericOutputMinPositiveHits.TabIndex = 18;
            this.numericOutputMinPositiveHits.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // linkLabel18
            // 
            this.linkLabel18.AutoSize = true;
            this.linkLabel18.Location = new System.Drawing.Point(13, 7);
            this.linkLabel18.Name = "linkLabel18";
            this.linkLabel18.Size = new System.Drawing.Size(109, 13);
            this.linkLabel18.TabIndex = 13;
            this.linkLabel18.TabStop = true;
            this.linkLabel18.Text = "Minimum Positive Hits";
            // 
            // panel16
            // 
            this.panel16.AutoSize = true;
            this.panel16.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel16.Controls.Add(this.numericOutputMinimumScore);
            this.panel16.Controls.Add(this.linkLabel17);
            this.panel16.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel16.Location = new System.Drawing.Point(3, 123);
            this.panel16.Name = "panel16";
            this.panel16.Size = new System.Drawing.Size(498, 23);
            this.panel16.TabIndex = 24;
            // 
            // numericOutputMinimumScore
            // 
            this.numericOutputMinimumScore.DecimalPlaces = 2;
            this.numericOutputMinimumScore.Location = new System.Drawing.Point(171, 0);
            this.numericOutputMinimumScore.Name = "numericOutputMinimumScore";
            this.numericOutputMinimumScore.Size = new System.Drawing.Size(52, 20);
            this.numericOutputMinimumScore.TabIndex = 18;
            this.numericOutputMinimumScore.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // linkLabel17
            // 
            this.linkLabel17.AutoSize = true;
            this.linkLabel17.Location = new System.Drawing.Point(13, 7);
            this.linkLabel17.Name = "linkLabel17";
            this.linkLabel17.Size = new System.Drawing.Size(79, 13);
            this.linkLabel17.TabIndex = 13;
            this.linkLabel17.TabStop = true;
            this.linkLabel17.Text = "Minimum Score";
            // 
            // panel8
            // 
            this.panel8.AutoSize = true;
            this.panel8.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel8.Controls.Add(this.radioOutputIgnoreReverseRedundancy);
            this.panel8.Controls.Add(this.radioButton2);
            this.panel8.Controls.Add(this.linkLabel8);
            this.panel8.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel8.Location = new System.Drawing.Point(3, 101);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(498, 22);
            this.panel8.TabIndex = 23;
            // 
            // radioOutputIgnoreReverseRedundancy
            // 
            this.radioOutputIgnoreReverseRedundancy.AutoSize = true;
            this.radioOutputIgnoreReverseRedundancy.Checked = true;
            this.radioOutputIgnoreReverseRedundancy.Location = new System.Drawing.Point(171, 2);
            this.radioOutputIgnoreReverseRedundancy.Name = "radioOutputIgnoreReverseRedundancy";
            this.radioOutputIgnoreReverseRedundancy.Size = new System.Drawing.Size(55, 17);
            this.radioOutputIgnoreReverseRedundancy.TabIndex = 17;
            this.radioOutputIgnoreReverseRedundancy.TabStop = true;
            this.radioOutputIgnoreReverseRedundancy.Text = "Ignore";
            this.radioOutputIgnoreReverseRedundancy.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(307, 0);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(56, 17);
            this.radioButton2.TabIndex = 16;
            this.radioButton2.Text = "Check";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // linkLabel8
            // 
            this.linkLabel8.AutoSize = true;
            this.linkLabel8.Location = new System.Drawing.Point(13, 5);
            this.linkLabel8.Name = "linkLabel8";
            this.linkLabel8.Size = new System.Drawing.Size(106, 13);
            this.linkLabel8.TabIndex = 13;
            this.linkLabel8.TabStop = true;
            this.linkLabel8.Text = "Reverse redundancy";
            // 
            // panel7
            // 
            this.panel7.AutoSize = true;
            this.panel7.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel7.Controls.Add(this.numericOutputRedundancyOffset);
            this.panel7.Controls.Add(this.linkLabel7);
            this.panel7.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel7.Location = new System.Drawing.Point(3, 68);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(498, 33);
            this.panel7.TabIndex = 22;
            // 
            // numericOutputRedundancyOffset
            // 
            this.numericOutputRedundancyOffset.Location = new System.Drawing.Point(171, 5);
            this.numericOutputRedundancyOffset.Name = "numericOutputRedundancyOffset";
            this.numericOutputRedundancyOffset.Size = new System.Drawing.Size(52, 20);
            this.numericOutputRedundancyOffset.TabIndex = 17;
            this.numericOutputRedundancyOffset.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // linkLabel7
            // 
            this.linkLabel7.Location = new System.Drawing.Point(13, 2);
            this.linkLabel7.Name = "linkLabel7";
            this.linkLabel7.Size = new System.Drawing.Size(83, 31);
            this.linkLabel7.TabIndex = 13;
            this.linkLabel7.TabStop = true;
            this.linkLabel7.Text = "Redundancy \nChecking Offset";
            // 
            // panel9
            // 
            this.panel9.AutoSize = true;
            this.panel9.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel9.Controls.Add(this.numericOutputSeedL);
            this.panel9.Controls.Add(this.linkLabel9);
            this.panel9.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel9.Location = new System.Drawing.Point(3, 39);
            this.panel9.Name = "panel9";
            this.panel9.Size = new System.Drawing.Size(498, 29);
            this.panel9.TabIndex = 21;
            // 
            // numericOutputSeedL
            // 
            this.numericOutputSeedL.Location = new System.Drawing.Point(171, 6);
            this.numericOutputSeedL.Name = "numericOutputSeedL";
            this.numericOutputSeedL.Size = new System.Drawing.Size(52, 20);
            this.numericOutputSeedL.TabIndex = 17;
            this.numericOutputSeedL.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            // 
            // linkLabel9
            // 
            this.linkLabel9.AutoSize = true;
            this.linkLabel9.Location = new System.Drawing.Point(13, 6);
            this.linkLabel9.Name = "linkLabel9";
            this.linkLabel9.Size = new System.Drawing.Size(103, 13);
            this.linkLabel9.TabIndex = 13;
            this.linkLabel9.TabStop = true;
            this.linkLabel9.Text = "Output Seed Length";
            // 
            // panel6
            // 
            this.panel6.AutoSize = true;
            this.panel6.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel6.Controls.Add(this.numericOutputSeedN);
            this.panel6.Controls.Add(this.linkLabel1);
            this.panel6.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel6.Location = new System.Drawing.Point(3, 3);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(498, 36);
            this.panel6.TabIndex = 18;
            // 
            // numericOutputSeedN
            // 
            this.numericOutputSeedN.Location = new System.Drawing.Point(171, 5);
            this.numericOutputSeedN.Name = "numericOutputSeedN";
            this.numericOutputSeedN.Size = new System.Drawing.Size(52, 20);
            this.numericOutputSeedN.TabIndex = 17;
            this.numericOutputSeedN.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // linkLabel1
            // 
            this.linkLabel1.Location = new System.Drawing.Point(13, 5);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(88, 31);
            this.linkLabel1.TabIndex = 13;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "How Many \nSeeds To Output";
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.panel20);
            this.tabPage4.Controls.Add(this.panel19);
            this.tabPage4.Controls.Add(this.panel12);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(504, 305);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Hit Counting";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // panel20
            // 
            this.panel20.AutoSize = true;
            this.panel20.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel20.Controls.Add(this.radioHitsIncrementsHotspots);
            this.panel20.Controls.Add(this.radioHitsIncrementsWeighted);
            this.panel20.Controls.Add(this.radioHitsIncrementsInteger);
            this.panel20.Controls.Add(this.linkLabel29);
            this.panel20.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel20.Location = new System.Drawing.Point(0, 61);
            this.panel20.Name = "panel20";
            this.panel20.Size = new System.Drawing.Size(504, 36);
            this.panel20.TabIndex = 28;
            // 
            // radioHitsIncrementsHotspots
            // 
            this.radioHitsIncrementsHotspots.AutoSize = true;
            this.radioHitsIncrementsHotspots.Location = new System.Drawing.Point(388, 3);
            this.radioHitsIncrementsHotspots.Name = "radioHitsIncrementsHotspots";
            this.radioHitsIncrementsHotspots.Size = new System.Drawing.Size(89, 30);
            this.radioHitsIncrementsHotspots.TabIndex = 18;
            this.radioHitsIncrementsHotspots.Text = "Weighted \nwith Hotspots";
            this.radioHitsIncrementsHotspots.UseVisualStyleBackColor = true;
            // 
            // radioHitsIncrementsWeighted
            // 
            this.radioHitsIncrementsWeighted.AutoSize = true;
            this.radioHitsIncrementsWeighted.Location = new System.Drawing.Point(273, 10);
            this.radioHitsIncrementsWeighted.Name = "radioHitsIncrementsWeighted";
            this.radioHitsIncrementsWeighted.Size = new System.Drawing.Size(71, 17);
            this.radioHitsIncrementsWeighted.TabIndex = 17;
            this.radioHitsIncrementsWeighted.Text = "Weighted";
            this.radioHitsIncrementsWeighted.UseVisualStyleBackColor = true;
            // 
            // radioHitsIncrementsInteger
            // 
            this.radioHitsIncrementsInteger.AutoSize = true;
            this.radioHitsIncrementsInteger.Checked = true;
            this.radioHitsIncrementsInteger.Location = new System.Drawing.Point(171, 10);
            this.radioHitsIncrementsInteger.Name = "radioHitsIncrementsInteger";
            this.radioHitsIncrementsInteger.Size = new System.Drawing.Size(58, 17);
            this.radioHitsIncrementsInteger.TabIndex = 16;
            this.radioHitsIncrementsInteger.TabStop = true;
            this.radioHitsIncrementsInteger.Text = "Integer";
            this.radioHitsIncrementsInteger.UseVisualStyleBackColor = true;
            // 
            // linkLabel29
            // 
            this.linkLabel29.AutoSize = true;
            this.linkLabel29.Location = new System.Drawing.Point(13, 10);
            this.linkLabel29.Name = "linkLabel29";
            this.linkLabel29.Size = new System.Drawing.Size(75, 13);
            this.linkLabel29.TabIndex = 13;
            this.linkLabel29.TabStop = true;
            this.linkLabel29.Text = "Hit Increments";
            // 
            // panel19
            // 
            this.panel19.AutoSize = true;
            this.panel19.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel19.Controls.Add(this.numericHitsCutoff);
            this.panel19.Controls.Add(this.linkLabel21);
            this.panel19.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel19.Location = new System.Drawing.Point(0, 38);
            this.panel19.Name = "panel19";
            this.panel19.Size = new System.Drawing.Size(504, 23);
            this.panel19.TabIndex = 27;
            // 
            // numericHitsCutoff
            // 
            this.numericHitsCutoff.DecimalPlaces = 2;
            this.numericHitsCutoff.Location = new System.Drawing.Point(171, 0);
            this.numericHitsCutoff.Name = "numericHitsCutoff";
            this.numericHitsCutoff.Size = new System.Drawing.Size(52, 20);
            this.numericHitsCutoff.TabIndex = 18;
            this.numericHitsCutoff.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // linkLabel21
            // 
            this.linkLabel21.AutoSize = true;
            this.linkLabel21.Location = new System.Drawing.Point(13, 7);
            this.linkLabel21.Name = "linkLabel21";
            this.linkLabel21.Size = new System.Drawing.Size(123, 13);
            this.linkLabel21.TabIndex = 13;
            this.linkLabel21.TabStop = true;
            this.linkLabel21.Text = "Positive/Negative Cutoff";
            // 
            // panel12
            // 
            this.panel12.AutoSize = true;
            this.panel12.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel12.Controls.Add(this.radioButton9);
            this.panel12.Controls.Add(this.radioHitsGeneCounts);
            this.panel12.Controls.Add(this.linkLabel12);
            this.panel12.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel12.Location = new System.Drawing.Point(0, 0);
            this.panel12.Name = "panel12";
            this.panel12.Size = new System.Drawing.Size(504, 38);
            this.panel12.TabIndex = 25;
            // 
            // radioButton9
            // 
            this.radioButton9.AutoSize = true;
            this.radioButton9.Location = new System.Drawing.Point(273, 5);
            this.radioButton9.Name = "radioButton9";
            this.radioButton9.Size = new System.Drawing.Size(90, 30);
            this.radioButton9.TabIndex = 17;
            this.radioButton9.Text = "Unlimited \n(Total counts)";
            this.radioButton9.UseVisualStyleBackColor = true;
            // 
            // radioHitsGeneCounts
            // 
            this.radioHitsGeneCounts.AutoSize = true;
            this.radioHitsGeneCounts.Checked = true;
            this.radioHitsGeneCounts.Location = new System.Drawing.Point(171, 3);
            this.radioHitsGeneCounts.Name = "radioHitsGeneCounts";
            this.radioHitsGeneCounts.Size = new System.Drawing.Size(99, 30);
            this.radioHitsGeneCounts.TabIndex = 16;
            this.radioHitsGeneCounts.TabStop = true;
            this.radioHitsGeneCounts.Text = "Once per gene \n(Gene counts)";
            this.radioHitsGeneCounts.UseVisualStyleBackColor = true;
            // 
            // linkLabel12
            // 
            this.linkLabel12.AutoSize = true;
            this.linkLabel12.Location = new System.Drawing.Point(13, 5);
            this.linkLabel12.Name = "linkLabel12";
            this.linkLabel12.Size = new System.Drawing.Size(31, 13);
            this.linkLabel12.TabIndex = 13;
            this.linkLabel12.TabStop = true;
            this.linkLabel12.Text = "Type";
            // 
            // tabPage5
            // 
            this.tabPage5.Controls.Add(this.panel15);
            this.tabPage5.Controls.Add(this.panel14);
            this.tabPage5.Location = new System.Drawing.Point(4, 22);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Size = new System.Drawing.Size(504, 305);
            this.tabPage5.TabIndex = 4;
            this.tabPage5.Text = "Scoring";
            this.tabPage5.UseVisualStyleBackColor = true;
            // 
            // panel15
            // 
            this.panel15.AutoSize = true;
            this.panel15.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel15.Controls.Add(this.radioScoringCorrectionNone);
            this.panel15.Controls.Add(this.radioScoringCorrectionFDR);
            this.panel15.Controls.Add(this.radioScoringCorrectionBonf);
            this.panel15.Controls.Add(this.linkLabel19);
            this.panel15.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel15.Location = new System.Drawing.Point(0, 74);
            this.panel15.Name = "panel15";
            this.panel15.Size = new System.Drawing.Size(504, 23);
            this.panel15.TabIndex = 27;
            // 
            // radioScoringCorrectionNone
            // 
            this.radioScoringCorrectionNone.AutoSize = true;
            this.radioScoringCorrectionNone.Location = new System.Drawing.Point(319, 3);
            this.radioScoringCorrectionNone.Name = "radioScoringCorrectionNone";
            this.radioScoringCorrectionNone.Size = new System.Drawing.Size(51, 17);
            this.radioScoringCorrectionNone.TabIndex = 22;
            this.radioScoringCorrectionNone.Text = "None";
            this.radioScoringCorrectionNone.UseVisualStyleBackColor = true;
            // 
            // radioScoringCorrectionFDR
            // 
            this.radioScoringCorrectionFDR.AutoSize = true;
            this.radioScoringCorrectionFDR.Location = new System.Drawing.Point(245, 3);
            this.radioScoringCorrectionFDR.Name = "radioScoringCorrectionFDR";
            this.radioScoringCorrectionFDR.Size = new System.Drawing.Size(47, 17);
            this.radioScoringCorrectionFDR.TabIndex = 17;
            this.radioScoringCorrectionFDR.Text = "FDR";
            this.radioScoringCorrectionFDR.UseVisualStyleBackColor = true;
            // 
            // radioScoringCorrectionBonf
            // 
            this.radioScoringCorrectionBonf.AutoSize = true;
            this.radioScoringCorrectionBonf.Checked = true;
            this.radioScoringCorrectionBonf.Location = new System.Drawing.Point(135, 3);
            this.radioScoringCorrectionBonf.Name = "radioScoringCorrectionBonf";
            this.radioScoringCorrectionBonf.Size = new System.Drawing.Size(73, 17);
            this.radioScoringCorrectionBonf.TabIndex = 16;
            this.radioScoringCorrectionBonf.TabStop = true;
            this.radioScoringCorrectionBonf.Text = "Bonferroni";
            this.radioScoringCorrectionBonf.UseVisualStyleBackColor = true;
            // 
            // linkLabel19
            // 
            this.linkLabel19.AutoSize = true;
            this.linkLabel19.Location = new System.Drawing.Point(13, 5);
            this.linkLabel19.Name = "linkLabel19";
            this.linkLabel19.Size = new System.Drawing.Size(92, 13);
            this.linkLabel19.TabIndex = 13;
            this.linkLabel19.TabStop = true;
            this.linkLabel19.Text = "PValue Correction";
            // 
            // panel14
            // 
            this.panel14.AutoSize = true;
            this.panel14.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel14.Controls.Add(this.panelScoringTypeExponential);
            this.panel14.Controls.Add(this.radioScoringTypeExponential);
            this.panel14.Controls.Add(this.radioScoringHypergeo);
            this.panel14.Controls.Add(this.linkLabel14);
            this.panel14.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel14.Location = new System.Drawing.Point(0, 0);
            this.panel14.Name = "panel14";
            this.panel14.Size = new System.Drawing.Size(504, 74);
            this.panel14.TabIndex = 26;
            // 
            // panelScoringTypeExponential
            // 
            this.panelScoringTypeExponential.AutoSize = true;
            this.panelScoringTypeExponential.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelScoringTypeExponential.Controls.Add(this.linkLabel15);
            this.panelScoringTypeExponential.Controls.Add(this.numericScoreingExplossBeta);
            this.panelScoringTypeExponential.Controls.Add(this.linkLabel16);
            this.panelScoringTypeExponential.Controls.Add(this.numericScoreingExplossAlpha);
            this.panelScoringTypeExponential.Location = new System.Drawing.Point(245, 26);
            this.panelScoringTypeExponential.Name = "panelScoringTypeExponential";
            this.panelScoringTypeExponential.Size = new System.Drawing.Size(134, 45);
            this.panelScoringTypeExponential.TabIndex = 24;
            this.panelScoringTypeExponential.Visible = false;
            // 
            // linkLabel15
            // 
            this.linkLabel15.AutoSize = true;
            this.linkLabel15.Location = new System.Drawing.Point(3, 0);
            this.linkLabel15.Name = "linkLabel15";
            this.linkLabel15.Size = new System.Drawing.Size(34, 13);
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
            this.numericScoreingExplossBeta.Location = new System.Drawing.Point(79, 22);
            this.numericScoreingExplossBeta.Name = "numericScoreingExplossBeta";
            this.numericScoreingExplossBeta.Size = new System.Drawing.Size(52, 20);
            this.numericScoreingExplossBeta.TabIndex = 23;
            this.numericScoreingExplossBeta.Value = new decimal(new int[] {
            15,
            0,
            0,
            65536});
            this.numericScoreingExplossBeta.ValueChanged += new System.EventHandler(this.numericUpDown13_ValueChanged);
            // 
            // linkLabel16
            // 
            this.linkLabel16.AutoSize = true;
            this.linkLabel16.Location = new System.Drawing.Point(3, 22);
            this.linkLabel16.Name = "linkLabel16";
            this.linkLabel16.Size = new System.Drawing.Size(29, 13);
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
            this.numericScoreingExplossAlpha.Location = new System.Drawing.Point(79, 0);
            this.numericScoreingExplossAlpha.Name = "numericScoreingExplossAlpha";
            this.numericScoreingExplossAlpha.Size = new System.Drawing.Size(52, 20);
            this.numericScoreingExplossAlpha.TabIndex = 22;
            this.numericScoreingExplossAlpha.Value = new decimal(new int[] {
            15,
            0,
            0,
            65536});
            // 
            // radioScoringTypeExponential
            // 
            this.radioScoringTypeExponential.AutoSize = true;
            this.radioScoringTypeExponential.Location = new System.Drawing.Point(245, 3);
            this.radioScoringTypeExponential.Name = "radioScoringTypeExponential";
            this.radioScoringTypeExponential.Size = new System.Drawing.Size(80, 17);
            this.radioScoringTypeExponential.TabIndex = 17;
            this.radioScoringTypeExponential.Text = "Exponential";
            this.radioScoringTypeExponential.UseVisualStyleBackColor = true;
            this.radioScoringTypeExponential.CheckedChanged += new System.EventHandler(this.radioScoringTypeExponential_CheckedChanged);
            // 
            // radioScoringHypergeo
            // 
            this.radioScoringHypergeo.AutoSize = true;
            this.radioScoringHypergeo.Checked = true;
            this.radioScoringHypergeo.Location = new System.Drawing.Point(135, 3);
            this.radioScoringHypergeo.Name = "radioScoringHypergeo";
            this.radioScoringHypergeo.Size = new System.Drawing.Size(104, 17);
            this.radioScoringHypergeo.TabIndex = 16;
            this.radioScoringHypergeo.TabStop = true;
            this.radioScoringHypergeo.Text = "Hyper-Geometric";
            this.radioScoringHypergeo.UseVisualStyleBackColor = true;
            // 
            // linkLabel14
            // 
            this.linkLabel14.AutoSize = true;
            this.linkLabel14.Location = new System.Drawing.Point(13, 5);
            this.linkLabel14.Name = "linkLabel14";
            this.linkLabel14.Size = new System.Drawing.Size(31, 13);
            this.linkLabel14.TabIndex = 13;
            this.linkLabel14.TabStop = true;
            this.linkLabel14.Text = "Type";
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.panel13);
            this.tabPage3.Controls.Add(this.panelSearchType);
            this.tabPage3.Controls.Add(this.panel11);
            this.tabPage3.Controls.Add(this.panel10);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(504, 305);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Preprocessing & Search";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // panel13
            // 
            this.panel13.AutoSize = true;
            this.panel13.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel13.Controls.Add(this.radioPreprocessingReverse);
            this.panel13.Controls.Add(this.radioPreprocessingNoReverse);
            this.panel13.Controls.Add(this.linkLabel13);
            this.panel13.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel13.Location = new System.Drawing.Point(0, 78);
            this.panel13.Name = "panel13";
            this.panel13.Size = new System.Drawing.Size(504, 25);
            this.panel13.TabIndex = 27;
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
            this.panelSearchType.Size = new System.Drawing.Size(504, 24);
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
            // panel11
            // 
            this.panel11.AutoSize = true;
            this.panel11.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel11.Controls.Add(this.numericPreprocessingDepth);
            this.panel11.Controls.Add(this.linkLabel11);
            this.panel11.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel11.Location = new System.Drawing.Point(0, 25);
            this.panel11.Name = "panel11";
            this.panel11.Size = new System.Drawing.Size(504, 29);
            this.panel11.TabIndex = 25;
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
            // panel10
            // 
            this.panel10.AutoSize = true;
            this.panel10.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel10.Controls.Add(this.radioPreprocessingTypeTable);
            this.panel10.Controls.Add(this.radioPreprocessingTypeTree);
            this.panel10.Controls.Add(this.linkLabel10);
            this.panel10.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel10.Location = new System.Drawing.Point(0, 0);
            this.panel10.Name = "panel10";
            this.panel10.Size = new System.Drawing.Size(504, 25);
            this.panel10.TabIndex = 24;
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
            this.menuStrip1.Size = new System.Drawing.Size(561, 24);
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
            this.openToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
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
            // ConfiGenForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(561, 355);
            this.Controls.Add(this.toolStripContainer1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(569, 389);
            this.MinimumSize = new System.Drawing.Size(569, 389);
            this.Name = "ConfiGenForm";
            this.Text = "SNAP Configuration File Editor";
            this.Load += new System.EventHandler(this.ConfiGenForm_Load);
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
            this.panel31.ResumeLayout(false);
            this.panel31.PerformLayout();
            this.panel28.ResumeLayout(false);
            this.panel28.PerformLayout();
            this.panel29.ResumeLayout(false);
            this.panel29.PerformLayout();
            this.panel30.ResumeLayout(false);
            this.panel30.PerformLayout();
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.panel25.ResumeLayout(false);
            this.panel25.PerformLayout();
            this.panelRandomSampling.ResumeLayout(false);
            this.panelRandomSampling.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericRandomSamplingPredetermined)).EndInit();
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericSamplingRandom)).EndInit();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsMidWildcards)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsWildcards)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericProjectionsLength)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.panel24.ResumeLayout(false);
            this.panel24.PerformLayout();
            this.panel23.ResumeLayout(false);
            this.panel23.PerformLayout();
            this.panel22.ResumeLayout(false);
            this.panel22.PerformLayout();
            this.panel21.ResumeLayout(false);
            this.panel21.PerformLayout();
            this.panel18.ResumeLayout(false);
            this.panel18.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHitsPercent)).EndInit();
            this.panel17.ResumeLayout(false);
            this.panel17.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinPositiveHits)).EndInit();
            this.panel16.ResumeLayout(false);
            this.panel16.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputMinimumScore)).EndInit();
            this.panel8.ResumeLayout(false);
            this.panel8.PerformLayout();
            this.panel7.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputRedundancyOffset)).EndInit();
            this.panel9.ResumeLayout(false);
            this.panel9.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedL)).EndInit();
            this.panel6.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericOutputSeedN)).EndInit();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.panel20.ResumeLayout(false);
            this.panel20.PerformLayout();
            this.panel19.ResumeLayout(false);
            this.panel19.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericHitsCutoff)).EndInit();
            this.panel12.ResumeLayout(false);
            this.panel12.PerformLayout();
            this.tabPage5.ResumeLayout(false);
            this.tabPage5.PerformLayout();
            this.panel15.ResumeLayout(false);
            this.panel15.PerformLayout();
            this.panel14.ResumeLayout(false);
            this.panel14.PerformLayout();
            this.panelScoringTypeExponential.ResumeLayout(false);
            this.panelScoringTypeExponential.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossBeta)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericScoreingExplossAlpha)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.panel13.ResumeLayout(false);
            this.panel13.PerformLayout();
            this.panelSearchType.ResumeLayout(false);
            this.panelSearchType.PerformLayout();
            this.panel11.ResumeLayout(false);
            this.panel11.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericPreprocessingDepth)).EndInit();
            this.panel10.ResumeLayout(false);
            this.panel10.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.HelpProvider helpProvider1;
        private System.Windows.Forms.ToolStripContainer toolStripContainer1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.RadioButton radioProjectionsOuterWildcardsAllow;
        private System.Windows.Forms.RadioButton radioProjectionsOuterWildcards;
        private System.Windows.Forms.LinkLabel linkLabel3;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.NumericUpDown numericProjectionsMidWildcards;
        private System.Windows.Forms.LinkLabel linkLabel5;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.NumericUpDown numericProjectionsWildcards;
        private System.Windows.Forms.LinkLabel linkLabel4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.NumericUpDown numericProjectionsLength;
        private System.Windows.Forms.LinkLabel linkLabel2;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Panel panel24;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeaturesetNone;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeaturesetPos;
        private System.Windows.Forms.RadioButton radioOutputGenerateFeatureseAll;
        private System.Windows.Forms.LinkLabel linkLabel26;
        private System.Windows.Forms.Panel panel23;
        private System.Windows.Forms.RadioButton radioOutputGenerateSampleNone;
        private System.Windows.Forms.RadioButton radioOutputGenerateSamplePos;
        private System.Windows.Forms.RadioButton radioOutputGenerateSampleAll;
        private System.Windows.Forms.LinkLabel linkLabel25;
        private System.Windows.Forms.Panel panel22;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifNone;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifPos;
        private System.Windows.Forms.RadioButton radioOutputGenerateMotifAll;
        private System.Windows.Forms.LinkLabel linkLabel24;
        private System.Windows.Forms.Panel panel21;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMNone;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMPos;
        private System.Windows.Forms.RadioButton radioOutputGeneratePSSMAll;
        private System.Windows.Forms.LinkLabel linkLabel23;
        private System.Windows.Forms.Panel panel18;
        private System.Windows.Forms.NumericUpDown numericOutputMinPositiveHitsPercent;
        private System.Windows.Forms.LinkLabel linkLabel20;
        private System.Windows.Forms.Panel panel17;
        private System.Windows.Forms.NumericUpDown numericOutputMinPositiveHits;
        private System.Windows.Forms.LinkLabel linkLabel18;
        private System.Windows.Forms.Panel panel16;
        private System.Windows.Forms.NumericUpDown numericOutputMinimumScore;
        private System.Windows.Forms.LinkLabel linkLabel17;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.RadioButton radioOutputIgnoreReverseRedundancy;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.LinkLabel linkLabel8;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.NumericUpDown numericOutputRedundancyOffset;
        private System.Windows.Forms.LinkLabel linkLabel7;
        private System.Windows.Forms.Panel panel9;
        private System.Windows.Forms.NumericUpDown numericOutputSeedL;
        private System.Windows.Forms.LinkLabel linkLabel9;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.NumericUpDown numericOutputSeedN;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Panel panel19;
        private System.Windows.Forms.NumericUpDown numericHitsCutoff;
        private System.Windows.Forms.LinkLabel linkLabel21;
        private System.Windows.Forms.Panel panel12;
        private System.Windows.Forms.RadioButton radioButton9;
        private System.Windows.Forms.RadioButton radioHitsGeneCounts;
        private System.Windows.Forms.LinkLabel linkLabel12;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.Panel panel15;
        private System.Windows.Forms.RadioButton radioScoringCorrectionNone;
        private System.Windows.Forms.RadioButton radioScoringCorrectionFDR;
        private System.Windows.Forms.RadioButton radioScoringCorrectionBonf;
        private System.Windows.Forms.LinkLabel linkLabel19;
        private System.Windows.Forms.Panel panel14;
        private System.Windows.Forms.Panel panelScoringTypeExponential;
        private System.Windows.Forms.LinkLabel linkLabel15;
        private System.Windows.Forms.NumericUpDown numericScoreingExplossBeta;
        private System.Windows.Forms.LinkLabel linkLabel16;
        private System.Windows.Forms.NumericUpDown numericScoreingExplossAlpha;
        private System.Windows.Forms.RadioButton radioScoringTypeExponential;
        private System.Windows.Forms.RadioButton radioScoringHypergeo;
        private System.Windows.Forms.LinkLabel linkLabel14;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Panel panel13;
        private System.Windows.Forms.RadioButton radioPreprocessingReverse;
        private System.Windows.Forms.RadioButton radioPreprocessingNoReverse;
        private System.Windows.Forms.LinkLabel linkLabel13;
        private System.Windows.Forms.Panel panelSearchType;
        private System.Windows.Forms.RadioButton radioSearchTypeTable;
        private System.Windows.Forms.RadioButton radioPreprocessingSearchTypeTree;
        private System.Windows.Forms.LinkLabel linkLabel22;
        private System.Windows.Forms.Panel panel11;
        private System.Windows.Forms.NumericUpDown numericPreprocessingDepth;
        private System.Windows.Forms.LinkLabel linkLabel11;
        private System.Windows.Forms.Panel panel10;
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
        private System.Windows.Forms.Panel panel25;
        private System.Windows.Forms.TextBox txtProjectionBaseManual;
        private System.Windows.Forms.RadioButton radioProjectionBaseDefault;
        private System.Windows.Forms.RadioButton radioProjectionBaseManual;
        private System.Windows.Forms.LinkLabel linkLabel27;
        private System.Windows.Forms.Panel panelRandomSampling;
        private System.Windows.Forms.NumericUpDown numericRandomSamplingPredetermined;
        private System.Windows.Forms.RadioButton radioButton32;
        private System.Windows.Forms.RadioButton radioRandomSamplingPredetermined;
        private System.Windows.Forms.LinkLabel linkLabel28;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.NumericUpDown numericSamplingRandom;
        private System.Windows.Forms.RadioButton radioSamplingRandom;
        private System.Windows.Forms.RadioButton radioButton5;
        private System.Windows.Forms.LinkLabel linkLabel6;
        private System.Windows.Forms.Label lblProjectionLengthRange;
        private System.Windows.Forms.Label lblProjectionMidWildcardsRange;
        private System.Windows.Forms.Label lblProjectionWildcardsRange;
        private System.Windows.Forms.Panel panel20;
        private System.Windows.Forms.RadioButton radioHitsIncrementsHotspots;
        private System.Windows.Forms.RadioButton radioHitsIncrementsWeighted;
        private System.Windows.Forms.RadioButton radioHitsIncrementsInteger;
        private System.Windows.Forms.LinkLabel linkLabel29;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Panel panel27;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.LinkLabel linkLabel31;
        private System.Windows.Forms.Panel panel26;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.LinkLabel linkLabel30;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel28;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.LinkLabel linkLabel32;
        private System.Windows.Forms.Panel panel29;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.LinkLabel linkLabel33;
        private System.Windows.Forms.Panel panel30;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.LinkLabel linkLabel34;
        private System.Windows.Forms.Panel panel31;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.LinkLabel linkLabel35;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;

    }
}