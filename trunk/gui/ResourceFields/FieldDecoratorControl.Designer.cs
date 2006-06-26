namespace SNAP.ResourceFields
{
    partial class FieldDecoratorControl
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
            this.panelRight = new SNAP.ResourceFields.VerticalFlowLayoutPanel();
            this.panelLeft = new SNAP.ResourceFields.VerticalFlowLayoutPanel();
            this.labelError = new System.Windows.Forms.Label();
            this.ContentLabel = new System.Windows.Forms.LinkLabel();
            this.checkOverride = new System.Windows.Forms.CheckBox();
            this.panelLeft.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelRight
            // 
            this.panelRight.AutoSize = true;
            this.panelRight.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelRight.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelRight.Location = new System.Drawing.Point(100, 0);
            this.panelRight.Name = "panelRight";
            this.panelRight.Size = new System.Drawing.Size(360, 13);
            this.panelRight.TabIndex = 28;
            // 
            // panelLeft
            // 
            this.panelLeft.AutoSize = true;
            this.panelLeft.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelLeft.Controls.Add(this.labelError);
            this.panelLeft.Controls.Add(this.ContentLabel);
            this.panelLeft.Controls.Add(this.checkOverride);
            this.panelLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelLeft.Location = new System.Drawing.Point(0, 0);
            this.panelLeft.Name = "panelLeft";
            this.panelLeft.Size = new System.Drawing.Size(100, 121);
            this.panelLeft.TabIndex = 27;
            // 
            // labelError
            // 
            this.labelError.AutoSize = true;
            this.labelError.ForeColor = System.Drawing.Color.Red;
            this.labelError.Location = new System.Drawing.Point(3, 43);
            this.labelError.MaximumSize = new System.Drawing.Size(150, 0);
            this.labelError.Name = "labelError";
            this.labelError.Size = new System.Drawing.Size(94, 65);
            this.labelError.TabIndex = 39;
            this.labelError.Text = "Error message goes here: a required field has not been filled out blah blah blaha" +
                "hah";
            this.labelError.Visible = false;
            // 
            // ContentLabel
            // 
            this.ContentLabel.AutoSize = true;
            this.ContentLabel.Location = new System.Drawing.Point(3, 17);
            this.ContentLabel.Name = "ContentLabel";
            this.ContentLabel.Size = new System.Drawing.Size(94, 26);
            this.ContentLabel.TabIndex = 1;
            this.ContentLabel.TabStop = true;
            this.ContentLabel.Text = "This displays the field name";
            // 
            // checkOverride
            // 
            this.checkOverride.AutoSize = true;
            this.checkOverride.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.checkOverride.Location = new System.Drawing.Point(3, 3);
            this.checkOverride.Name = "checkOverride";
            this.checkOverride.Size = new System.Drawing.Size(94, 11);
            this.checkOverride.TabIndex = 0;
            this.checkOverride.UseVisualStyleBackColor = true;
            // 
            // FieldDecoratorControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Controls.Add(this.panelRight);
            this.Controls.Add(this.panelLeft);
            this.Name = "FieldDecoratorControl";
            this.Size = new System.Drawing.Size(460, 131);
            this.Click += new System.EventHandler(this.FieldDecoratorControl_Click);
            this.panelLeft.ResumeLayout(false);
            this.panelLeft.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private VerticalFlowLayoutPanel panelLeft;
        private System.Windows.Forms.Label labelError;
        private System.Windows.Forms.CheckBox checkOverride;
        private VerticalFlowLayoutPanel panelRight;
        private System.Windows.Forms.LinkLabel ContentLabel;







    }
}
