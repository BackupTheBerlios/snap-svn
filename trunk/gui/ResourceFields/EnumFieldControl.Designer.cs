namespace SNAP.ResourceFields
{
    partial class EnumFieldControl
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.verticalFlowLayoutPanel1 = new SNAP.ResourceFields.VerticalFlowLayoutPanel();
            this.fieldPanel1 = new SNAP.ResourceFields.ResourceFieldsControl();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.verticalFlowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // verticalFlowLayoutPanel1
            // 
            this.verticalFlowLayoutPanel1.AutoSize = true;
            this.verticalFlowLayoutPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.verticalFlowLayoutPanel1.Controls.Add(this.fieldPanel1);
            this.verticalFlowLayoutPanel1.Controls.Add(this.flowLayoutPanel1);
            this.verticalFlowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.verticalFlowLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.verticalFlowLayoutPanel1.Name = "verticalFlowLayoutPanel1";
            this.verticalFlowLayoutPanel1.Size = new System.Drawing.Size(433, 128);
            this.verticalFlowLayoutPanel1.TabIndex = 1;
            // 
            // fieldPanel1
            // 
            this.fieldPanel1.AutoSize = true;
            this.fieldPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.fieldPanel1.Location = new System.Drawing.Point(3, 32);
            this.fieldPanel1.Name = "fieldPanel1";
            this.fieldPanel1.Size = new System.Drawing.Size(427, 0);
            this.fieldPanel1.SubValues = null;
            this.fieldPanel1.TabIndex = 3;
            this.fieldPanel1.Visible = false;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.AutoScroll = true;
            this.flowLayoutPanel1.AutoSize = true;
            this.flowLayoutPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.flowLayoutPanel1.Controls.Add(this.radioButton1);
            this.flowLayoutPanel1.Controls.Add(this.radioButton2);
            this.flowLayoutPanel1.Controls.Add(this.radioButton3);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 3);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(427, 23);
            this.flowLayoutPanel1.TabIndex = 2;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(3, 3);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(85, 17);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "radioButton1";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(94, 3);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(85, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "radioButton2";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(185, 3);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(85, 17);
            this.radioButton3.TabIndex = 2;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "radioButton3";
            this.radioButton3.UseVisualStyleBackColor = true;
            // 
            // EnumFieldControl
            // 
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Controls.Add(this.verticalFlowLayoutPanel1);
            this.Name = "EnumFieldControl";
            this.Size = new System.Drawing.Size(433, 128);
            this.Load += new System.EventHandler(this.EnumFieldControl_Load);
            this.verticalFlowLayoutPanel1.ResumeLayout(false);
            this.verticalFlowLayoutPanel1.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private VerticalFlowLayoutPanel verticalFlowLayoutPanel1;
        private ResourceFieldsControl fieldPanel1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;



    }
}
