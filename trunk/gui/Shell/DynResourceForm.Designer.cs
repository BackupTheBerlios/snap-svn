namespace SNAP
{
    partial class DynResourceForm
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
            this.components = new System.ComponentModel.Container();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnApply = new System.Windows.Forms.Button();
            this.panelExecutions = new System.Windows.Forms.FlowLayoutPanel();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cmbResourceType = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.resourceFieldsControl1 = new SNAP.ResourceFields.ResourceFieldsControl();
            this.fieldParent = new SNAP.ResourceFields.FieldDecoratorControl();
            this.fieldName = new SNAP.ResourceFields.FieldDecoratorControl();
            this.panel2.SuspendLayout();
            this.panelExecutions.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.btnOK);
            this.panel2.Controls.Add(this.btnCancel);
            this.panel2.Controls.Add(this.btnApply);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(0, 422);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(632, 24);
            this.panel2.TabIndex = 31;
            // 
            // btnOK
            // 
            this.btnOK.AutoSize = true;
            this.btnOK.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnOK.Location = new System.Drawing.Point(407, 0);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 24);
            this.btnOK.TabIndex = 17;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnCancel.Location = new System.Drawing.Point(482, 0);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 24);
            this.btnCancel.TabIndex = 15;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnApply
            // 
            this.btnApply.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnApply.Location = new System.Drawing.Point(557, 0);
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(75, 24);
            this.btnApply.TabIndex = 16;
            this.btnApply.Text = "Apply";
            this.btnApply.UseVisualStyleBackColor = true;
            this.btnApply.Click += new System.EventHandler(this.btnApply_Click);
            // 
            // panelExecutions
            // 
            this.panelExecutions.AutoScroll = true;
            this.panelExecutions.AutoSize = true;
            this.panelExecutions.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelExecutions.Controls.Add(this.button1);
            this.panelExecutions.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelExecutions.FlowDirection = System.Windows.Forms.FlowDirection.RightToLeft;
            this.panelExecutions.Location = new System.Drawing.Point(0, 393);
            this.panelExecutions.Name = "panelExecutions";
            this.panelExecutions.Size = new System.Drawing.Size(632, 29);
            this.panelExecutions.TabIndex = 30;
            this.panelExecutions.Visible = false;
            // 
            // button1
            // 
            this.button1.AutoSize = true;
            this.button1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.button1.BackColor = System.Drawing.Color.LightBlue;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Location = new System.Drawing.Point(576, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(53, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = false;
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSize = true;
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.fieldParent);
            this.groupBox1.Controls.Add(this.fieldName);
            this.groupBox1.Controls.Add(this.cmbResourceType);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(632, 92);
            this.groupBox1.TabIndex = 32;
            this.groupBox1.TabStop = false;
            // 
            // cmbResourceType
            // 
            this.cmbResourceType.Dock = System.Windows.Forms.DockStyle.Top;
            this.cmbResourceType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbResourceType.FormattingEnabled = true;
            this.cmbResourceType.Location = new System.Drawing.Point(3, 16);
            this.cmbResourceType.Name = "cmbResourceType";
            this.cmbResourceType.Size = new System.Drawing.Size(626, 21);
            this.cmbResourceType.TabIndex = 36;
            this.cmbResourceType.SelectedIndexChanged += new System.EventHandler(this.cmbResourceType_SelectedIndexChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.resourceFieldsControl1);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 92);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(632, 301);
            this.groupBox2.TabIndex = 33;
            this.groupBox2.TabStop = false;
            // 
            // resourceFieldsControl1
            // 
            this.resourceFieldsControl1.AutoScroll = true;
            this.resourceFieldsControl1.AutoSize = true;
            this.resourceFieldsControl1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.resourceFieldsControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.resourceFieldsControl1.Location = new System.Drawing.Point(3, 16);
            this.resourceFieldsControl1.Name = "resourceFieldsControl1";
            this.resourceFieldsControl1.Size = new System.Drawing.Size(626, 282);
            this.resourceFieldsControl1.SubValues = null;
            this.resourceFieldsControl1.TabIndex = 0;
            this.resourceFieldsControl1.Text = "resourceFieldsControl1";
            // 
            // fieldParent
            // 
            this.fieldParent.AutoSize = true;
            this.fieldParent.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.fieldParent.Content = null;
            this.fieldParent.Dock = System.Windows.Forms.DockStyle.Top;
            this.fieldParent.ErrorText = "Error message goes here: a required field has not been filled out blah blah blaha" +
                "hah";
            this.fieldParent.ErrorTextVisible = false;
            this.fieldParent.Location = new System.Drawing.Point(3, 63);
            this.fieldParent.Name = "fieldParent";
            this.fieldParent.Readonly = false;
            this.fieldParent.Size = new System.Drawing.Size(626, 26);
            this.fieldParent.TabIndex = 38;
            // 
            // fieldName
            // 
            this.fieldName.AutoSize = true;
            this.fieldName.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.fieldName.Content = null;
            this.fieldName.Dock = System.Windows.Forms.DockStyle.Top;
            this.fieldName.ErrorText = "Error message goes here: a required field has not been filled out blah blah blaha" +
                "hah";
            this.fieldName.ErrorTextVisible = false;
            this.fieldName.Location = new System.Drawing.Point(3, 37);
            this.fieldName.Name = "fieldName";
            this.fieldName.Readonly = true;
            this.fieldName.Size = new System.Drawing.Size(626, 26);
            this.fieldName.TabIndex = 37;
            // 
            // DynResourceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(632, 446);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.panelExecutions);
            this.Controls.Add(this.panel2);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(640, 480);
            this.MinimumSize = new System.Drawing.Size(480, 320);
            this.Name = "DynResourceForm";
            this.Text = "Resource Details";
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panelExecutions.ResumeLayout(false);
            this.panelExecutions.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnApply;
        private System.Windows.Forms.FlowLayoutPanel panelExecutions;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private SNAP.ResourceFields.FieldDecoratorControl fieldParent;
        private SNAP.ResourceFields.FieldDecoratorControl fieldName;
        private System.Windows.Forms.ComboBox cmbResourceType;
        private System.Windows.Forms.GroupBox groupBox2;
        private SNAP.ResourceFields.ResourceFieldsControl resourceFieldsControl1;
     }
}