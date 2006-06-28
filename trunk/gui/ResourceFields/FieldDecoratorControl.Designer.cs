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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.checkOverride = new System.Windows.Forms.CheckBox();
            this.ContentLabel = new System.Windows.Forms.LinkLabel();
            this.labelError = new System.Windows.Forms.Label();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 100F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.checkOverride, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.ContentLabel, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.labelError, 0, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(559, 39);
            this.tableLayoutPanel1.TabIndex = 30;
            // 
            // checkOverride
            // 
            this.checkOverride.AutoSize = true;
            this.checkOverride.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.checkOverride.Location = new System.Drawing.Point(3, 3);
            this.checkOverride.Name = "checkOverride";
            this.checkOverride.Size = new System.Drawing.Size(12, 11);
            this.checkOverride.TabIndex = 42;
            this.checkOverride.UseVisualStyleBackColor = true;
            // 
            // ContentLabel
            // 
            this.ContentLabel.AutoSize = true;
            this.ContentLabel.Location = new System.Drawing.Point(21, 0);
            this.ContentLabel.Name = "ContentLabel";
            this.ContentLabel.Size = new System.Drawing.Size(88, 26);
            this.ContentLabel.TabIndex = 1;
            this.ContentLabel.TabStop = true;
            this.ContentLabel.Text = "This displays the field name";
            // 
            // labelError
            // 
            this.labelError.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.labelError, 3);
            this.labelError.ForeColor = System.Drawing.Color.Red;
            this.labelError.Location = new System.Drawing.Point(3, 26);
            this.labelError.Name = "labelError";
            this.labelError.Size = new System.Drawing.Size(399, 13);
            this.labelError.TabIndex = 39;
            this.labelError.Text = "Error message goes here: a required field has not been filled out blah blah blaha" +
                "hah";
            this.labelError.Visible = false;
            // 
            // FieldDecoratorControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "FieldDecoratorControl";
            this.Size = new System.Drawing.Size(559, 280);
            this.Click += new System.EventHandler(this.FieldDecoratorControl_Click);
            this.SizeChanged += new System.EventHandler(this.FieldDecoratorControl_SizeChanged);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label labelError;
        private System.Windows.Forms.LinkLabel ContentLabel;
        private System.Windows.Forms.CheckBox checkOverride;








    }
}
