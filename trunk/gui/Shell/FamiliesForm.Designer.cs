namespace SNAP {
    partial class FamiliesForm {
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Yeast");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Young Clean");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Fungi", new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2});
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Plant");
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Vertebrate");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Invertebrate");
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("General", new System.Windows.Forms.TreeNode[] {
            treeNode3,
            treeNode4,
            treeNode5,
            treeNode6});
            this.btnSelect = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            this.txtFamilyName = new System.Windows.Forms.TextBox();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.btnResourceAdd = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showEmptyFamiliesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.reloadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnRemove = new System.Windows.Forms.Button();
            this.btnFamilyAdd = new System.Windows.Forms.Button();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.panelLegend = new System.Windows.Forms.Panel();
            this.lblWeightColor = new System.Windows.Forms.Label();
            this.lblSequenceColor = new System.Windows.Forms.Label();
            this.lblFamilyColor = new System.Windows.Forms.Label();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.groupBox1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.panelLegend.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnSelect
            // 
            this.btnSelect.Location = new System.Drawing.Point(285, 16);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(75, 23);
            this.btnSelect.TabIndex = 1;
            this.btnSelect.Text = "Select";
            this.btnSelect.UseVisualStyleBackColor = true;
            this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSize = true;
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.btnCancel);
            this.groupBox1.Controls.Add(this.comboBox1);
            this.groupBox1.Controls.Add(this.linkLabel2);
            this.groupBox1.Controls.Add(this.txtFamilyName);
            this.groupBox1.Controls.Add(this.linkLabel1);
            this.groupBox1.Controls.Add(this.btnSelect);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox1.Location = new System.Drawing.Point(0, 298);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(654, 87);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(285, 45);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 5;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // comboBox1
            // 
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.Items.AddRange(new object[] {
            "All Resource Types"});
            this.comboBox1.Location = new System.Drawing.Point(65, 44);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(214, 21);
            this.comboBox1.TabIndex = 4;
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point(12, 44);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(33, 13);
            this.linkLabel2.TabIndex = 3;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "Mask";
            // 
            // txtFamilyName
            // 
            this.txtFamilyName.Location = new System.Drawing.Point(65, 16);
            this.txtFamilyName.Name = "txtFamilyName";
            this.txtFamilyName.Size = new System.Drawing.Size(214, 20);
            this.txtFamilyName.TabIndex = 2;
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(12, 16);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(35, 13);
            this.linkLabel1.TabIndex = 0;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Name";
            // 
            // btnResourceAdd
            // 
            this.btnResourceAdd.AutoSize = true;
            this.btnResourceAdd.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnResourceAdd.BackColor = System.Drawing.Color.Lavender;
            this.btnResourceAdd.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnResourceAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnResourceAdd.Location = new System.Drawing.Point(0, 40);
            this.btnResourceAdd.Name = "btnResourceAdd";
            this.btnResourceAdd.Size = new System.Drawing.Size(150, 40);
            this.btnResourceAdd.TabIndex = 2;
            this.btnResourceAdd.Text = "+\nResource";
            this.btnResourceAdd.UseVisualStyleBackColor = false;
            this.btnResourceAdd.Click += new System.EventHandler(this.btnResourceAdd_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.viewToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(654, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.showEmptyFamiliesToolStripMenuItem,
            this.reloadToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(41, 20);
            this.viewToolStripMenuItem.Text = "&View";
            // 
            // showEmptyFamiliesToolStripMenuItem
            // 
            this.showEmptyFamiliesToolStripMenuItem.Checked = true;
            this.showEmptyFamiliesToolStripMenuItem.CheckOnClick = true;
            this.showEmptyFamiliesToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.showEmptyFamiliesToolStripMenuItem.Name = "showEmptyFamiliesToolStripMenuItem";
            this.showEmptyFamiliesToolStripMenuItem.Size = new System.Drawing.Size(171, 22);
            this.showEmptyFamiliesToolStripMenuItem.Text = "Show empty families";
            // 
            // reloadToolStripMenuItem
            // 
            this.reloadToolStripMenuItem.Name = "reloadToolStripMenuItem";
            this.reloadToolStripMenuItem.Size = new System.Drawing.Size(171, 22);
            this.reloadToolStripMenuItem.Text = "Reload";
            // 
            // groupBox2
            // 
            this.groupBox2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox2.Controls.Add(this.groupBox3);
            this.groupBox2.Controls.Add(this.panel1);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Right;
            this.groupBox2.Location = new System.Drawing.Point(498, 24);
            this.groupBox2.MinimumSize = new System.Drawing.Size(80, 192);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(156, 274);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.AutoSize = true;
            this.panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel1.Controls.Add(this.btnRemove);
            this.panel1.Controls.Add(this.btnResourceAdd);
            this.panel1.Controls.Add(this.btnFamilyAdd);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(3, 16);
            this.panel1.MinimumSize = new System.Drawing.Size(74, 108);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(150, 120);
            this.panel1.TabIndex = 11;
            // 
            // btnRemove
            // 
            this.btnRemove.AutoSize = true;
            this.btnRemove.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnRemove.BackColor = System.Drawing.Color.Lavender;
            this.btnRemove.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnRemove.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRemove.Location = new System.Drawing.Point(0, 80);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(150, 40);
            this.btnRemove.TabIndex = 11;
            this.btnRemove.Text = "-\nRemove";
            this.btnRemove.UseVisualStyleBackColor = false;
            this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
            // 
            // btnFamilyAdd
            // 
            this.btnFamilyAdd.AutoSize = true;
            this.btnFamilyAdd.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnFamilyAdd.BackColor = System.Drawing.Color.Lavender;
            this.btnFamilyAdd.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnFamilyAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnFamilyAdd.Location = new System.Drawing.Point(0, 0);
            this.btnFamilyAdd.Name = "btnFamilyAdd";
            this.btnFamilyAdd.Size = new System.Drawing.Size(150, 40);
            this.btnFamilyAdd.TabIndex = 9;
            this.btnFamilyAdd.Text = "+\nFamily";
            this.btnFamilyAdd.UseVisualStyleBackColor = false;
            this.btnFamilyAdd.Click += new System.EventHandler(this.button6_Click);
            // 
            // treeView1
            // 
            this.treeView1.CheckBoxes = true;
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.LabelEdit = true;
            this.treeView1.Location = new System.Drawing.Point(0, 24);
            this.treeView1.Name = "treeView1";
            treeNode1.BackColor = System.Drawing.Color.Bisque;
            treeNode1.Name = "General.Fungi.Yeast";
            treeNode1.Text = "Yeast";
            treeNode2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            treeNode2.ForeColor = System.Drawing.Color.MidnightBlue;
            treeNode2.Name = "Node0";
            treeNode2.Text = "Young Clean";
            treeNode3.Name = "General.Fungi";
            treeNode3.Text = "Fungi";
            treeNode4.Name = "Node3";
            treeNode4.Text = "Plant";
            treeNode5.Name = "Node4";
            treeNode5.Text = "Vertebrate";
            treeNode6.Name = "Node5";
            treeNode6.Text = "Invertebrate";
            treeNode7.Name = "General";
            treeNode7.Text = "General";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode7});
            this.treeView1.ShowNodeToolTips = true;
            this.treeView1.Size = new System.Drawing.Size(498, 274);
            this.treeView1.TabIndex = 9;
            this.treeView1.NodeMouseDoubleClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.treeView1_NodeMouseDoubleClick);
            this.treeView1.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.treeView1_AfterLabelEdit);
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect_1);
            // 
            // groupBox3
            // 
            this.groupBox3.AutoSize = true;
            this.groupBox3.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox3.Controls.Add(this.panelLegend);
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Location = new System.Drawing.Point(3, 136);
            this.groupBox3.MinimumSize = new System.Drawing.Size(74, 64);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(150, 135);
            this.groupBox3.TabIndex = 12;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Legend";
            // 
            // panelLegend
            // 
            this.panelLegend.AutoScroll = true;
            this.panelLegend.AutoSize = true;
            this.panelLegend.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panelLegend.Controls.Add(this.lblWeightColor);
            this.panelLegend.Controls.Add(this.lblSequenceColor);
            this.panelLegend.Controls.Add(this.lblFamilyColor);
            this.panelLegend.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelLegend.Location = new System.Drawing.Point(3, 16);
            this.panelLegend.Name = "panelLegend";
            this.panelLegend.Size = new System.Drawing.Size(144, 116);
            this.panelLegend.TabIndex = 0;
            // 
            // lblWeightColor
            // 
            this.lblWeightColor.BackColor = System.Drawing.Color.LightSkyBlue;
            this.lblWeightColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblWeightColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblWeightColor.Location = new System.Drawing.Point(0, 30);
            this.lblWeightColor.Name = "lblWeightColor";
            this.lblWeightColor.Size = new System.Drawing.Size(144, 15);
            this.lblWeightColor.TabIndex = 17;
            this.lblWeightColor.Text = "Weight Nodes";
            // 
            // lblSequenceColor
            // 
            this.lblSequenceColor.BackColor = System.Drawing.Color.LightSeaGreen;
            this.lblSequenceColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblSequenceColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblSequenceColor.Location = new System.Drawing.Point(0, 15);
            this.lblSequenceColor.Name = "lblSequenceColor";
            this.lblSequenceColor.Size = new System.Drawing.Size(144, 15);
            this.lblSequenceColor.TabIndex = 16;
            this.lblSequenceColor.Text = "Sequence Nodes";
            // 
            // lblFamilyColor
            // 
            this.lblFamilyColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblFamilyColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblFamilyColor.Location = new System.Drawing.Point(0, 0);
            this.lblFamilyColor.Name = "lblFamilyColor";
            this.lblFamilyColor.Size = new System.Drawing.Size(144, 15);
            this.lblFamilyColor.TabIndex = 15;
            this.lblFamilyColor.Text = "Family Nodes";
            // 
            // FamiliesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.White;
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(654, 385);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(442, 363);
            this.Name = "FamiliesForm";
            this.Text = "Families";
            this.Load += new System.EventHandler(this.FamiliesForm_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.panelLegend.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.TextBox txtFamilyName;
        private System.Windows.Forms.Button btnResourceAdd;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showEmptyFamiliesToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Button btnFamilyAdd;
        private System.Windows.Forms.ToolStripMenuItem reloadToolStripMenuItem;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnRemove;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.LinkLabel linkLabel2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Panel panelLegend;
        private System.Windows.Forms.Label lblWeightColor;
        private System.Windows.Forms.Label lblSequenceColor;
        private System.Windows.Forms.Label lblFamilyColor;
        private System.Windows.Forms.ToolTip toolTip1;
    }
}