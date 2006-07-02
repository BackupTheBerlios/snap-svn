using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using SNAP.Resources;

namespace SNAP {
    public partial class FamiliesForm : Form {
        public FamiliesForm()
            : this(new InternalRefFieldType.Mask[] { new InternalRefFieldType.Mask("All Resource Types (*)", "*") })
        {
        }

        public FamiliesForm(IEnumerable<InternalRefFieldType.Mask> masks)
        {
            InitializeComponent();
            BuildTree();

            /// setup the mask
            this.comboBox1.Items.Clear();
            foreach (InternalRefFieldType.Mask mask in masks)
                this.comboBox1.Items.Add (mask);

            this.comboBox1.SelectedIndex = 0;

            /// setup the legend
            panelLegend.Controls.Clear();
            foreach (ResourceType type in Controller.CurrentResources.ResourceTypes.Values)
            {
                Label colorLabel = new Label();
                colorLabel.Name = type.Name;
                colorLabel.Text = type.DisplayName;
                colorLabel.BackColor = type.DisplayColor;
                //colorLabel.AutoSize = true;
                colorLabel.Dock = DockStyle.Top;
                colorLabel.BorderStyle = BorderStyle.FixedSingle;
                colorLabel.Click += new EventHandler(colorLabel_Click);
                panelLegend.Controls.Add(colorLabel);
            }
        }

        void colorLabel_Click(object sender, EventArgs e)
        {
            Label colorLabel = (Label)sender;
            colorDialog1.AllowFullOpen = true;
            colorDialog1.AnyColor = true;
            colorDialog1.Color = colorLabel.BackColor;
            colorDialog1.FullOpen = true;
            if (colorDialog1.ShowDialog(this) == DialogResult.OK)
            {
                colorLabel.BackColor = colorDialog1.Color;
                Controller.CurrentResources.ResourceTypes[colorLabel.Name].DisplayColor = colorDialog1.Color;
                /// TODO: save the change to the XML
                BuildTree();
            }
            
        }

        #region public

        /// <summary>
        /// Gets the selected resource.
        /// </summary>
        /// <value>The selected resource.</value>
        internal Resources.Resource SelectedResource
        {
            get {
                if (treeView1.SelectedNode == null)
                    return null;

                return (Resources.Resource) treeView1.SelectedNode.Tag;
            }
            set {
                TreeNode [] nodes = treeView1.Nodes.Find(value.QualifiedName, true);
                treeView1.SelectedNode = (nodes.Length > 0) ? nodes[0] : null;
                    
            }
        }

        #endregion public

        #region Implementation

        private void btnSelect_Click(object sender, EventArgs e) {
            if (SelectedResource == null)
            {
                SelectedResource = Controller.CurrentResources.FindResource(this.txtFamilyName.Text);
                if (SelectedResource == null) 
                    return;
            }

            InternalRefFieldType.Mask mask = (InternalRefFieldType.Mask) this.comboBox1.SelectedItem;
            if (mask.IsAccepted(SelectedResource.MyType))
            {
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
        }

        private void btnResourceAdd_Click(object sender, EventArgs e) {
            DynResourceForm resourceForm = new DynResourceForm();
            resourceForm.SelectedResourceParent = ((Resources.Resource)treeView1.SelectedNode.Tag);
            if (resourceForm.ShowDialog() == DialogResult.OK) {
                Controller.CurrentResources.AddResource(
                    resourceForm.SelectedResourceParent, resourceForm.SelectedResource);

                /// only rebuild the tree from the parent onwards
                TreeNode childNode = CreateTreeNode(resourceForm.SelectedResource);
                BuildTree(childNode);
                AddNode(treeView1.SelectedNode, childNode);
                treeView1.SelectedNode.Expand();
                childNode.Expand();
            }
        }

        private void BuildTree() {
            treeView1.Nodes.Clear();
            TreeNode rootNode = CreateTreeNode(Controller.CurrentResources.Root);
            treeView1.Nodes.Add(rootNode);
            BuildTree(rootNode);
        }

        private void BuildTree(System.Windows.Forms.TreeNode parent)
        {
            parent.Nodes.Clear();

            Resource resource = (SNAP.Resources.Resource)parent.Tag;
            /// recursively build the descendants
            foreach (Resources.Resource childResource in resource.Children.Values) {
                TreeNode childNode = CreateTreeNode(childResource);
                AddNode(parent, childNode);
                BuildTree(childNode);
            }
        }

        private void SetupNode (TreeNode node)
        {
            Resource resource = (SNAP.Resources.Resource) node.Tag;
            node.Name = resource.QualifiedName;
            node.Text = resource.Name;
            node.BackColor = resource.MyType.DisplayColor;
            node.ToolTipText = resource.ToString();
        }

        private TreeNode CreateTreeNode(Resources.Resource resource) {
            TreeNode treeNode = new TreeNode ();
            treeNode.Tag = resource;
            SetupNode (treeNode);

            return treeNode;
        }

        private void AddNode(TreeNode parent, TreeNode treeNode) {
            /// add it to the parent
            if (parent != null)
                parent.Nodes.Add(treeNode);
            else
                treeView1.Nodes.Add(treeNode);
        }

        private void button4_Click(object sender, EventArgs e) {
            //Program.CurrentResources.SaveResources(@"C:\SNAP.res");
        }

        private void button5_Click(object sender, EventArgs e) {
            Controller.CurrentResources.LoadResources();
            BuildTree();
        }

        private void button6_Click(object sender, EventArgs e) {
            Resources.Resource parent = null;
            
            /// only composite resources can have a sub-resource
            if (treeView1.SelectedNode != null)
                parent = ((Resources.Resource)treeView1.SelectedNode.Tag);
            else
                parent = (Resources.Resource)this.treeView1.Nodes[0].Tag;

            Resources.Resource resource = new Resources.Resource (
                Guid.NewGuid (),
                Controller.CurrentResources.ResourceTypes["Family"],
                "new family");
            int attempt = 2;
            while(parent.Children[resource.Name] != null) {
                /// this family already exists in the parent, try another one
                resource.Name = "new family " + attempt++;
            }

            parent.Children.Add(resource);

            TreeNode treeNode = CreateTreeNode(resource);
            AddNode(treeView1.SelectedNode, treeNode);
            treeView1.SelectedNode.Expand();
            treeNode.BeginEdit();

            // TODO: add this to the resource tree?
        }

        private void treeView1_AfterLabelEdit(object sender, NodeLabelEditEventArgs e) {
            if (e.Label != null) {
                if (!e.Node.Name.Equals(e.Label)) {
                    e.Node.Text = e.Label;
                    e.Node.Name = e.Label;
                    ((Resources.Resource)e.Node.Tag).Name = e.Label;
                    // TODO: update this in the resource tree
                }
            }
        }

        private void treeView1_AfterSelect_1(object sender, TreeViewEventArgs e) {
            txtFamilyName.Text = ((Resources.Resource)e.Node.Tag).QualifiedName;
        }

        private void btnRemove_Click(object sender, EventArgs e) {
            Resources.Resource resource = (Resources.Resource)treeView1.SelectedNode.Tag;
            string qualifiedname = resource.QualifiedName;
            if (System.Windows.Forms.MessageBox.Show (this, "This will remove the " + qualifiedname + " resource and all its sub-resources. Are you sure?",
                "Removing resources",
                MessageBoxButtons.OKCancel,
                MessageBoxIcon.Question,
                MessageBoxDefaultButton.Button2
            ) == DialogResult.OK)
            {
                resource.MyParent.Children.Remove(resource.Name);
                treeView1.SelectedNode.Remove();
            }
        }

        private void FamiliesForm_Load(object sender, EventArgs e) {
            treeView1.SelectedNode = treeView1.Nodes[0];
            treeView1.SelectedNode.Expand();

        }

        private void treeView1_NodeMouseDoubleClick(object sender, TreeNodeMouseClickEventArgs e) {
            Resources.Resource resource = (Resources.Resource) e.Node.Tag;
            DynResourceForm form = new DynResourceForm(resource);
            if (form.ShowDialog() == DialogResult.OK)
            {
                Controller.CurrentResources.SaveResources();
                SetupNode(e.Node);
                BuildTree(e.Node);
            }
        }

        #endregion Implementation

        private void btnImport_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.AddExtension = true;
            dialog.CheckFileExists = true;
            dialog.CheckPathExists = true;
            dialog.Filter = "SNAP Resources File (*.xml) | *.xml";
            dialog.Multiselect = false;
            dialog.DefaultExt = "xml";
            dialog.DereferenceLinks = true;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    Controller.CurrentResources.LoadAdditionalResources(
                        SelectedResource, 
                        dialog.FileName);
                }
                catch (Exception x)
                {
                    Controller.ShowException(x);
                }
            }
        }
    }
}
