namespace SNAP {
    partial class SeedSearchForm {
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
            this.txtSeqFile = new System.Windows.Forms.TextBox();
            this.btnSeqBrowse = new System.Windows.Forms.Button();
            this.btnWgtBrowse = new System.Windows.Forms.Button();
            this.txtWgtFile = new System.Windows.Forms.TextBox();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            this.txtName = new System.Windows.Forms.TextBox();
            this.linkLabel3 = new System.Windows.Forms.LinkLabel();
            this.linkLabel4 = new System.Windows.Forms.LinkLabel();
            this.btnConfBrowse = new System.Windows.Forms.Button();
            this.txtConf = new System.Windows.Forms.TextBox();
            this.btnOK = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.automaticNamingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.useSequencesFamilyForWeightsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtSeqFile
            // 
            this.txtSeqFile.Location = new System.Drawing.Point(124, 17);
            this.txtSeqFile.Name = "txtSeqFile";
            this.txtSeqFile.Size = new System.Drawing.Size(239, 20);
            this.txtSeqFile.TabIndex = 0;
            // 
            // btnSeqBrowse
            // 
            this.btnSeqBrowse.AutoSize = true;
            this.btnSeqBrowse.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnSeqBrowse.Location = new System.Drawing.Point(369, 17);
            this.btnSeqBrowse.Name = "btnSeqBrowse";
            this.btnSeqBrowse.Size = new System.Drawing.Size(52, 23);
            this.btnSeqBrowse.TabIndex = 1;
            this.btnSeqBrowse.Text = "Browse";
            this.btnSeqBrowse.UseVisualStyleBackColor = true;
            this.btnSeqBrowse.Click += new System.EventHandler(this.btnSeqBrowse_Click);
            // 
            // btnWgtBrowse
            // 
            this.btnWgtBrowse.AutoSize = true;
            this.btnWgtBrowse.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnWgtBrowse.Location = new System.Drawing.Point(369, 43);
            this.btnWgtBrowse.Name = "btnWgtBrowse";
            this.btnWgtBrowse.Size = new System.Drawing.Size(52, 23);
            this.btnWgtBrowse.TabIndex = 4;
            this.btnWgtBrowse.Text = "Browse";
            this.btnWgtBrowse.UseVisualStyleBackColor = true;
            this.btnWgtBrowse.Click += new System.EventHandler(this.btnWgtBrowse_Click);
            // 
            // txtWgtFile
            // 
            this.txtWgtFile.Location = new System.Drawing.Point(124, 43);
            this.txtWgtFile.Name = "txtWgtFile";
            this.txtWgtFile.Size = new System.Drawing.Size(239, 20);
            this.txtWgtFile.TabIndex = 3;
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(7, 43);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(60, 13);
            this.linkLabel1.TabIndex = 6;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Weight File";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point(7, 17);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(75, 13);
            this.linkLabel2.TabIndex = 7;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "Sequence File";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(124, 69);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(239, 20);
            this.txtName.TabIndex = 9;
            // 
            // linkLabel3
            // 
            this.linkLabel3.AutoSize = true;
            this.linkLabel3.Location = new System.Drawing.Point(7, 69);
            this.linkLabel3.Name = "linkLabel3";
            this.linkLabel3.Size = new System.Drawing.Size(35, 13);
            this.linkLabel3.TabIndex = 10;
            this.linkLabel3.TabStop = true;
            this.linkLabel3.Text = "Name";
            // 
            // linkLabel4
            // 
            this.linkLabel4.AutoSize = true;
            this.linkLabel4.Location = new System.Drawing.Point(7, 95);
            this.linkLabel4.Name = "linkLabel4";
            this.linkLabel4.Size = new System.Drawing.Size(69, 13);
            this.linkLabel4.TabIndex = 13;
            this.linkLabel4.TabStop = true;
            this.linkLabel4.Text = "Configuration";
            // 
            // btnConfBrowse
            // 
            this.btnConfBrowse.AutoSize = true;
            this.btnConfBrowse.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnConfBrowse.Location = new System.Drawing.Point(369, 95);
            this.btnConfBrowse.Name = "btnConfBrowse";
            this.btnConfBrowse.Size = new System.Drawing.Size(52, 23);
            this.btnConfBrowse.TabIndex = 12;
            this.btnConfBrowse.Text = "Browse";
            this.btnConfBrowse.UseVisualStyleBackColor = true;
            this.btnConfBrowse.Click += new System.EventHandler(this.btnConfBrowse_Click);
            // 
            // txtConf
            // 
            this.txtConf.Location = new System.Drawing.Point(124, 95);
            this.txtConf.Name = "txtConf";
            this.txtConf.Size = new System.Drawing.Size(239, 20);
            this.txtConf.TabIndex = 11;
            // 
            // btnOK
            // 
            this.btnOK.AutoSize = true;
            this.btnOK.Location = new System.Drawing.Point(314, 167);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(49, 23);
            this.btnOK.TabIndex = 14;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.optionsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(427, 24);
            this.menuStrip1.TabIndex = 15;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // optionsToolStripMenuItem
            // 
            this.optionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.automaticNamingToolStripMenuItem,
            this.useSequencesFamilyForWeightsToolStripMenuItem});
            this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
            this.optionsToolStripMenuItem.Size = new System.Drawing.Size(56, 20);
            this.optionsToolStripMenuItem.Text = "&Options";
            this.optionsToolStripMenuItem.Click += new System.EventHandler(this.optionsToolStripMenuItem_Click);
            // 
            // automaticNamingToolStripMenuItem
            // 
            this.automaticNamingToolStripMenuItem.Checked = true;
            this.automaticNamingToolStripMenuItem.CheckOnClick = true;
            this.automaticNamingToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.automaticNamingToolStripMenuItem.Name = "automaticNamingToolStripMenuItem";
            this.automaticNamingToolStripMenuItem.Size = new System.Drawing.Size(236, 22);
            this.automaticNamingToolStripMenuItem.Text = "Automatic naming";
            // 
            // useSequencesFamilyForWeightsToolStripMenuItem
            // 
            this.useSequencesFamilyForWeightsToolStripMenuItem.Checked = true;
            this.useSequencesFamilyForWeightsToolStripMenuItem.CheckOnClick = true;
            this.useSequencesFamilyForWeightsToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.useSequencesFamilyForWeightsToolStripMenuItem.Name = "useSequencesFamilyForWeightsToolStripMenuItem";
            this.useSequencesFamilyForWeightsToolStripMenuItem.Size = new System.Drawing.Size(236, 22);
            this.useSequencesFamilyForWeightsToolStripMenuItem.Text = "Use sequence\'s family for weights";
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSize = true;
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.txtName);
            this.groupBox1.Controls.Add(this.txtSeqFile);
            this.groupBox1.Controls.Add(this.linkLabel4);
            this.groupBox1.Controls.Add(this.btnSeqBrowse);
            this.groupBox1.Controls.Add(this.btnConfBrowse);
            this.groupBox1.Controls.Add(this.txtWgtFile);
            this.groupBox1.Controls.Add(this.txtConf);
            this.groupBox1.Controls.Add(this.btnWgtBrowse);
            this.groupBox1.Controls.Add(this.linkLabel3);
            this.groupBox1.Controls.Add(this.linkLabel1);
            this.groupBox1.Controls.Add(this.linkLabel2);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 24);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(427, 137);
            this.groupBox1.TabIndex = 16;
            this.groupBox1.TabStop = false;
            // 
            // btnCancel
            // 
            this.btnCancel.AutoSize = true;
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(369, 167);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(50, 23);
            this.btnCancel.TabIndex = 17;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // SeedSearchForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(427, 194);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.HelpButton = true;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SeedSearchForm";
            this.Text = "Ab initio motif search";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtSeqFile;
        private System.Windows.Forms.Button btnSeqBrowse;
        private System.Windows.Forms.Button btnWgtBrowse;
        private System.Windows.Forms.TextBox txtWgtFile;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.LinkLabel linkLabel2;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.LinkLabel linkLabel3;
        private System.Windows.Forms.LinkLabel linkLabel4;
        private System.Windows.Forms.Button btnConfBrowse;
        private System.Windows.Forms.TextBox txtConf;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem automaticNamingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem useSequencesFamilyForWeightsToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnCancel;
    }
}

