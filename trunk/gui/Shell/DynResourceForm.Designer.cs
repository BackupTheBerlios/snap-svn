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
            this.verticalFlowLayoutPanel1 = new SNAP.ResourceFields.VerticalFlowLayoutPanel();
            this.panelFields = new SNAP.ResourceFields.ResourceFieldsControl();
            this.verticalFlowLayoutGroupBox1 = new SNAP.ResourceFields.VerticalFlowLayoutGroupBox();
            this.fieldParent = new SNAP.ResourceFields.FieldDecoratorControl();
            this.fieldName = new SNAP.ResourceFields.FieldDecoratorControl();
            this.panel1 = new System.Windows.Forms.Panel();
            this.cmbResourceType = new System.Windows.Forms.ComboBox();
            this.linkLabel4 = new System.Windows.Forms.LinkLabel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.panel2.SuspendLayout();
            this.panelExecutions.SuspendLayout();
            this.verticalFlowLayoutPanel1.SuspendLayout();
            this.verticalFlowLayoutGroupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel3.SuspendLayout();
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
            this.btnApply.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnApply.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnApply.Enabled = false;
            this.btnApply.Location = new System.Drawing.Point(557, 0);
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(75, 24);
            this.btnApply.TabIndex = 16;
            this.btnApply.Text = "Apply";
            this.btnApply.UseVisualStyleBackColor = true;
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
            // verticalFlowLayoutPanel1
            // 
            this.verticalFlowLayoutPanel1.Controls.Add(this.panel3);
            this.verticalFlowLayoutPanel1.Controls.Add(this.verticalFlowLayoutGroupBox1);
            this.verticalFlowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.verticalFlowLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.verticalFlowLayoutPanel1.Name = "verticalFlowLayoutPanel1";
            this.verticalFlowLayoutPanel1.Size = new System.Drawing.Size(632, 393);
            this.verticalFlowLayoutPanel1.TabIndex = 32;
            // 
            // panelFields
            // 
            this.panelFields.Location = new System.Drawing.Point(3, 3);
            this.panelFields.Name = "panelFields";
            this.panelFields.Size = new System.Drawing.Size(618, 201);
            this.panelFields.SubValues = null;
            this.panelFields.TabIndex = 29;
            this.panelFields.TabStop = false;
            // 
            // verticalFlowLayoutGroupBox1
            // 
            this.verticalFlowLayoutGroupBox1.AutoSize = true;
            this.verticalFlowLayoutGroupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.verticalFlowLayoutGroupBox1.BackColor = System.Drawing.Color.LemonChiffon;
            this.verticalFlowLayoutGroupBox1.Controls.Add(this.fieldParent);
            this.verticalFlowLayoutGroupBox1.Controls.Add(this.fieldName);
            this.verticalFlowLayoutGroupBox1.Controls.Add(this.panel1);
            this.verticalFlowLayoutGroupBox1.Location = new System.Drawing.Point(3, 3);
            this.verticalFlowLayoutGroupBox1.Name = "verticalFlowLayoutGroupBox1";
            this.verticalFlowLayoutGroupBox1.Size = new System.Drawing.Size(626, 169);
            this.verticalFlowLayoutGroupBox1.TabIndex = 28;
            this.verticalFlowLayoutGroupBox1.TabStop = false;
            // 
            // fieldParent
            // 
            this.fieldParent.AutoSize = true;
            this.fieldParent.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.fieldParent.Content = null;
            this.fieldParent.Location = new System.Drawing.Point(6, 113);
            this.fieldParent.Name = "fieldParent";
            this.fieldParent.Readonly = false;
            this.fieldParent.Size = new System.Drawing.Size(608, 50);
            this.fieldParent.TabIndex = 34;
            // 
            // fieldName
            // 
            this.fieldName.AutoSize = true;
            this.fieldName.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.fieldName.Content = null;
            this.fieldName.Location = new System.Drawing.Point(6, 57);
            this.fieldName.Name = "fieldName";
            this.fieldName.Readonly = false;
            this.fieldName.Size = new System.Drawing.Size(608, 50);
            this.fieldName.TabIndex = 33;
            // 
            // panel1
            // 
            this.panel1.AutoSize = true;
            this.panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel1.Controls.Add(this.cmbResourceType);
            this.panel1.Controls.Add(this.linkLabel4);
            this.panel1.Location = new System.Drawing.Point(6, 19);
            this.panel1.MaximumSize = new System.Drawing.Size(0, 32);
            this.panel1.MinimumSize = new System.Drawing.Size(0, 32);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(608, 32);
            this.panel1.TabIndex = 28;
            // 
            // cmbResourceType
            // 
            this.cmbResourceType.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cmbResourceType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbResourceType.FormattingEnabled = true;
            this.cmbResourceType.Location = new System.Drawing.Point(70, 0);
            this.cmbResourceType.Name = "cmbResourceType";
            this.cmbResourceType.Size = new System.Drawing.Size(538, 21);
            this.cmbResourceType.TabIndex = 21;
            this.cmbResourceType.SelectedIndexChanged += new System.EventHandler(this.cmbResourceType_SelectedIndexChanged);
            // 
            // linkLabel4
            // 
            this.linkLabel4.Dock = System.Windows.Forms.DockStyle.Left;
            this.linkLabel4.Location = new System.Drawing.Point(0, 0);
            this.linkLabel4.Name = "linkLabel4";
            this.linkLabel4.Size = new System.Drawing.Size(70, 32);
            this.linkLabel4.TabIndex = 20;
            this.linkLabel4.TabStop = true;
            this.linkLabel4.Text = "Resource Type";
            // 
            // panel3
            // 
            this.panel3.AutoScroll = true;
            this.panel3.BackColor = System.Drawing.Color.LemonChiffon;
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel3.Controls.Add(this.panelFields);
            this.panel3.Location = new System.Drawing.Point(3, 178);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(626, 209);
            this.panel3.TabIndex = 30;
            // 
            // DynResourceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(632, 446);
            this.Controls.Add(this.verticalFlowLayoutPanel1);
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
            this.verticalFlowLayoutPanel1.ResumeLayout(false);
            this.verticalFlowLayoutPanel1.PerformLayout();
            this.verticalFlowLayoutGroupBox1.ResumeLayout(false);
            this.verticalFlowLayoutGroupBox1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
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
        private SNAP.ResourceFields.VerticalFlowLayoutPanel verticalFlowLayoutPanel1;
        private SNAP.ResourceFields.ResourceFieldsControl panelFields;
        private SNAP.ResourceFields.VerticalFlowLayoutGroupBox verticalFlowLayoutGroupBox1;
        private SNAP.ResourceFields.FieldDecoratorControl fieldParent;
        private SNAP.ResourceFields.FieldDecoratorControl fieldName;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ComboBox cmbResourceType;
        private System.Windows.Forms.LinkLabel linkLabel4;
        private System.Windows.Forms.Panel panel3;
     }
}