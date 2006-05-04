using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    public partial class FamiliesForm : Form {
        public FamiliesForm() {
            InitializeComponent();
            BuildTree();
        }

        #region public

        /// <summary>
        /// Gets the selected resource.
        /// </summary>
        /// <value>The selected resource.</value>
        internal Resources.Resource SelectedResource {
            get {
                return (Resources.Resource) treeView1.SelectedNode.Tag;
            }
        }

        #endregion public

        #region Implementation

        private void button1_Click(object sender, EventArgs e) {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e) {
            ResourceForm resourceForm = new ResourceForm();
            resourceForm.Family = ((Resources.Resource)treeView1.SelectedNode.Tag).QualifiedName;
            if (resourceForm.ShowDialog() == DialogResult.OK) {
                /// TODO: do this more economically, by adding only
                /// the new items
                BuildTree();
            }
        }

        private void BuildTree() {
            treeView1.Nodes.Clear();
            BuildTree(null, Program.CurrentResources.Root);
        }

        private void BuildTree(System.Windows.Forms.TreeNode parent, SNAP.Resources.Resource resource) {
            TreeNode treeNode = CreateTreeNode(resource);

            /// recursively build the descendants
            Resources.CompositeResource compositeResource = resource as Resources.CompositeResource;
            if (compositeResource != null) {
                foreach (Resources.Resource childResource in compositeResource.Values) {
                    BuildTree(treeNode, childResource);
                }
            }

            AddNode(parent, treeNode);
        }

        private TreeNode CreateTreeNode(Resources.Resource resource) {
            TreeNode treeNode = new TreeNode(resource.Name);
            treeNode.Name = resource.Name;
            treeNode.Tag = resource;
            switch (resource.GetType().Name) {
                case "CompositeResource":
                    treeNode.BackColor = this.lblFamilyColor.BackColor;
                    break;
                case "SeqFileResource":
                    treeNode.BackColor = this.lblSequenceColor.BackColor;
                    break;
                case "WgtFileResource":
                    treeNode.BackColor = this.lblWeightColor.BackColor;
                    break;
            }

            /// TODO: change the color of node according to type
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
            Program.CurrentResources.LoadResources();
            BuildTree();
        }

        private void label2_Click(object sender, EventArgs e) {
            colorDialog1.ShowDialog();
            lblSequenceColor.BackColor = colorDialog1.Color;
            BuildTree();
        }

        private void label3_Click(object sender, EventArgs e) {
            colorDialog1.ShowDialog();
            lblWeightColor.BackColor = colorDialog1.Color;
            BuildTree();
        }

        private void label1_Click(object sender, EventArgs e) {
            colorDialog1.ShowDialog();
            lblFamilyColor.BackColor = colorDialog1.Color;
            BuildTree();

        }

        private void button6_Click(object sender, EventArgs e) {
            Resources.CompositeResource parent = null;
            
            /// only composite resources can have a sub-resource
            if (treeView1.SelectedNode != null)
                parent = ((Resources.CompositeResource)treeView1.SelectedNode.Tag);
            else
                parent = (Resources.CompositeResource)this.treeView1.Nodes[0].Tag;

            Resources.CompositeResource resource = new Resources.CompositeResource (
                "new family");
            int attempt = 2;
            while(parent[resource.Name] != null) {
                /// this family already exists in the parent, try another one
                resource.Name = "new family " + attempt++;
            }

            parent.Add(resource);

            TreeNode treeNode = CreateTreeNode(resource);
            AddNode(treeView1.SelectedNode, treeNode);
            treeView1.SelectedNode.Expand();
            treeNode.BeginEdit();

            /// TODO: add this to the resource tree?
        }

        private void treeView1_AfterLabelEdit(object sender, NodeLabelEditEventArgs e) {
            if (e.Label != null) {
                if (!e.Node.Name.Equals(e.Label)) {
                    e.Node.Text = e.Label;
                    e.Node.Name = e.Label;
                    ((Resources.Resource)e.Node.Tag).Name = e.Label;
                    /// TODO: update this in the resource tree
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
                resource.Parent.Remove (resource.Name);
                treeView1.SelectedNode.Remove();
            }
        }

        private void FamiliesForm_Load(object sender, EventArgs e) {
            treeView1.SelectedNode = treeView1.Nodes[0];
            treeView1.SelectedNode.Expand();

        }

        private void treeView1_NodeMouseDoubleClick(object sender, TreeNodeMouseClickEventArgs e) {
            Resources.Resource resource = (Resources.Resource) e.Node.Tag;
            ResourceForm form = new ResourceForm(resource);
            form.ShowDialog();
        }

        #endregion Implementation
    }
}
