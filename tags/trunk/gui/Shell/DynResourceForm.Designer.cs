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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.cmbResourceType = new System.Windows.Forms.ComboBox();
            this.linkLabel4 = new System.Windows.Forms.LinkLabel();
            this.textField1 = new SNAP.ResourceFields.TextField();
            this.fieldFamily = new SNAP.ResourceFields.InternalRefField();
            this.fieldName = new SNAP.ResourceFields.TextField();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnApply = new System.Windows.Forms.Button();
            this.groupFields = new System.Windows.Forms.GroupBox();
            this.panelExecutions = new System.Windows.Forms.FlowLayoutPanel();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.groupFields.SuspendLayout();
            this.panelExecutions.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.panel1);
            this.groupBox1.Controls.Add(this.textField1);
            this.groupBox1.Controls.Add(this.fieldFamily);
            this.groupBox1.Controls.Add(this.fieldName);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(442, 131);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.cmbResourceType);
            this.panel1.Controls.Add(this.linkLabel4);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(3, 90);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(436, 28);
            this.panel1.TabIndex = 25;
            // 
            // cmbResourceType
            // 
            this.cmbResourceType.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cmbResourceType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbResourceType.FormattingEnabled = true;
            this.cmbResourceType.Location = new System.Drawing.Point(70, 0);
            this.cmbResourceType.Name = "cmbResourceType";
            this.cmbResourceType.Size = new System.Drawing.Size(366, 21);
            this.cmbResourceType.TabIndex = 21;
            this.cmbResourceType.SelectedIndexChanged += new System.EventHandler(this.cmbResourceType_SelectedIndexChanged);
            // 
            // linkLabel4
            // 
            this.linkLabel4.Dock = System.Windows.Forms.DockStyle.Left;
            this.linkLabel4.Location = new System.Drawing.Point(0, 0);
            this.linkLabel4.Name = "linkLabel4";
            this.linkLabel4.Size = new System.Drawing.Size(70, 28);
            this.linkLabel4.TabIndex = 20;
            this.linkLabel4.TabStop = true;
            this.linkLabel4.Text = "Resource Type";
            // 
            // textField1
            // 
            this.textField1.Dock = System.Windows.Forms.DockStyle.Top;
            this.textField1.FieldName = "ID";
            this.textField1.FieldNameVisible = true;
            this.textField1.FieldText = "";
            this.textField1.Location = new System.Drawing.Point(3, 65);
            this.textField1.Name = "textField1";
            this.textField1.Readonly = true;
            this.textField1.Size = new System.Drawing.Size(436, 25);
            this.textField1.TabIndex = 24;
            // 
            // fieldFamily
            // 
            this.fieldFamily.Dock = System.Windows.Forms.DockStyle.Top;
            this.fieldFamily.FieldName = "Family";
            this.fieldFamily.FieldNameVisible = true;
            this.fieldFamily.FieldText = "";
            this.fieldFamily.Location = new System.Drawing.Point(3, 41);
            this.fieldFamily.Name = "fieldFamily";
            this.fieldFamily.Readonly = true;
            this.fieldFamily.SelectedResource = null;
            this.fieldFamily.Size = new System.Drawing.Size(436, 24);
            this.fieldFamily.TabIndex = 23;
            // 
            // fieldName
            // 
            this.fieldName.Dock = System.Windows.Forms.DockStyle.Top;
            this.fieldName.FieldName = "Name";
            this.fieldName.FieldNameVisible = true;
            this.fieldName.FieldText = "";
            this.fieldName.Location = new System.Drawing.Point(3, 16);
            this.fieldName.Name = "fieldName";
            this.fieldName.Readonly = false;
            this.fieldName.Size = new System.Drawing.Size(436, 25);
            this.fieldName.TabIndex = 22;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.btnOK);
            this.panel2.Controls.Add(this.btnCancel);
            this.panel2.Controls.Add(this.btnApply);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(0, 264);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(442, 23);
            this.panel2.TabIndex = 20;
            // 
            // btnOK
            // 
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnOK.Location = new System.Drawing.Point(217, 0);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 17;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnCancel.Location = new System.Drawing.Point(292, 0);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 15;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // btnApply
            // 
            this.btnApply.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnApply.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnApply.Enabled = false;
            this.btnApply.Location = new System.Drawing.Point(367, 0);
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(75, 23);
            this.btnApply.TabIndex = 16;
            this.btnApply.Text = "Apply";
            this.btnApply.UseVisualStyleBackColor = true;
            // 
            // groupFields
            // 
            this.groupFields.AutoSize = true;
            this.groupFields.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupFields.Controls.Add(this.panelExecutions);
            this.groupFields.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupFields.Location = new System.Drawing.Point(0, 131);
            this.groupFields.Name = "groupFields";
            this.groupFields.Size = new System.Drawing.Size(442, 133);
            this.groupFields.TabIndex = 23;
            this.groupFields.TabStop = false;
            this.groupFields.Visible = false;
            // 
            // panelExecutions
            // 
            this.panelExecutions.AutoScroll = true;
            this.panelExecutions.AutoSize = true;
            this.panelExecutions.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelExecutions.Controls.Add(this.button1);
            this.panelExecutions.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelExecutions.FlowDirection = System.Windows.Forms.FlowDirection.RightToLeft;
            this.panelExecutions.Location = new System.Drawing.Point(3, 101);
            this.panelExecutions.Name = "panelExecutions";
            this.panelExecutions.Size = new System.Drawing.Size(436, 29);
            this.panelExecutions.TabIndex = 23;
            this.panelExecutions.Visible = false;
            // 
            // button1
            // 
            this.button1.AutoSize = true;
            this.button1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.button1.BackColor = System.Drawing.Color.LightBlue;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Location = new System.Drawing.Point(380, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(53, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = false;
            // 
            // DynResourceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(442, 287);
            this.Controls.Add(this.groupFields);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.groupBox1);
            this.Name = "DynResourceForm";
            this.Text = "Resource Details";
            this.groupBox1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.groupFields.ResumeLayout(false);
            this.groupFields.PerformLayout();
            this.panelExecutions.ResumeLayout(false);
            this.panelExecutions.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnApply;
        private SNAP.ResourceFields.TextField fieldName;
        private SNAP.ResourceFields.TextField textField1;
        private SNAP.ResourceFields.InternalRefField fieldFamily;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ComboBox cmbResourceType;
        private System.Windows.Forms.LinkLabel linkLabel4;
        private System.Windows.Forms.GroupBox groupFields;
        private System.Windows.Forms.FlowLayoutPanel panelExecutions;
        private System.Windows.Forms.Button button1;
    }
}