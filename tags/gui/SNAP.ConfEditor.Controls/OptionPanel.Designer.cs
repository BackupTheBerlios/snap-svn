namespace SNAP.ConfEditor
{
    partial class OptionPanel
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.ContentLabel = new System.Windows.Forms.LinkLabel();
            this.checkOverride = new System.Windows.Forms.CheckBox();
            this.ContentPanel = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.AutoSize = true;
            this.panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel1.Controls.Add(this.ContentLabel);
            this.panel1.Controls.Add(this.checkOverride);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(142, 32);
            this.panel1.TabIndex = 13;
            // 
            // ContentLabel
            // 
            this.ContentLabel.Dock = System.Windows.Forms.DockStyle.Left;
            this.ContentLabel.Location = new System.Drawing.Point(12, 0);
            this.ContentLabel.MaximumSize = new System.Drawing.Size(130, 0);
            this.ContentLabel.MinimumSize = new System.Drawing.Size(130, 13);
            this.ContentLabel.Name = "ContentLabel";
            this.ContentLabel.Size = new System.Drawing.Size(130, 32);
            this.ContentLabel.TabIndex = 14;
            this.ContentLabel.TabStop = true;
            this.ContentLabel.Text = "How Many Seeds To Ouptut";
            // 
            // checkOverride
            // 
            this.checkOverride.AutoSize = true;
            this.checkOverride.CheckAlign = System.Drawing.ContentAlignment.TopLeft;
            this.checkOverride.Dock = System.Windows.Forms.DockStyle.Left;
            this.checkOverride.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.checkOverride.Location = new System.Drawing.Point(0, 0);
            this.checkOverride.Name = "checkOverride";
            this.checkOverride.Size = new System.Drawing.Size(12, 32);
            this.checkOverride.TabIndex = 13;
            this.checkOverride.TextAlign = System.Drawing.ContentAlignment.TopLeft;
            this.checkOverride.UseVisualStyleBackColor = true;
            this.checkOverride.CheckedChanged += new System.EventHandler(this.checkOverride_CheckedChanged);
            // 
            // ContentPanel
            // 
            this.ContentPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ContentPanel.Enabled = false;
            this.ContentPanel.Location = new System.Drawing.Point(142, 0);
            this.ContentPanel.Name = "ContentPanel";
            this.ContentPanel.Size = new System.Drawing.Size(310, 32);
            this.ContentPanel.TabIndex = 14;
            // 
            // OptionPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.ContentPanel);
            this.Controls.Add(this.panel1);
            this.Name = "OptionPanel";
            this.Size = new System.Drawing.Size(452, 32);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.LinkLabel ContentLabel;
        private System.Windows.Forms.CheckBox checkOverride;
        private System.Windows.Forms.Panel ContentPanel;


    }
}
