

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP {
    internal partial class ResourceForm : Form {
        public ResourceForm() {
            InitializeComponent();
            
            /// load all resource types
            InitializeResourceTypes();
        }

        public ResourceForm(Resources.Resource resource) {
            InitializeComponent();

            if (resource.Parent != null)
                Family = resource.Parent.QualifiedName;
            btnFamilyBrowse.Enabled = false;

            /// name and notes are subject to change
            DisplayName = resource.Name;
            Notes = resource.Notes;

            btnFilenameBrowse.Enabled = false;
            if (resource is Resources.FileResource) {
                Filename = (resource as Resources.FileResource).Filename;
            }

            cmbResourceType.Items.Add(new ResourceTypeItem(resource));
            cmbResourceType.SelectedIndex = 0;
        }

        #region public

        /// <summary>
        /// Gets or sets the family.
        /// </summary>
        /// <value>The family.</value>
        public string Family {
            get {
                return txtFamily.Text;
            }
            set {
                txtFamily.Text = value;
            }
        }

        /// <summary>
        /// Gets or sets the filename.
        /// </summary>
        /// <value>The filename.</value>
        public string Filename {
            get {
                return txtFilename.Text;
            }
            set {
                txtFilename.Text = value;
            }
        }

        /// <summary>
        /// Gets or sets the display name of the resource.
        /// </summary>
        /// <value>The name of the display.</value>
        public string DisplayName {
            get {
                return txtDisplayName.Text;
            }
            set {
                txtDisplayName.Text = value;
            }
        }

        /// <summary>
        /// Gets or sets the notes.
        /// </summary>
        /// <value>The notes.</value>
        public string Notes {
            get {
                return txtNotes.Text;
            }
            set {
                txtNotes.Text = value;
            }
        }

        #endregion public

        #region private

        private void InitializeResourceTypes ()
        {
            /// look for all resources in this assembly
            System.Reflection.Assembly currentAssembly =
                System.Reflection.Assembly.GetAssembly(this.GetType());

            foreach (System.Type type in currentAssembly.GetTypes()) {
                if (type.IsClass && type.IsSubclassOf(typeof(Resources.FileResource))) {
                    System.Reflection.ConstructorInfo ctr = type.GetConstructor(Type.EmptyTypes);
                    Resources.FileResource resourceTemplate = (Resources.FileResource) ctr.Invoke(null);

                    cmbResourceType.Items.Add(new ResourceTypeItem(resourceTemplate));
                }
            }
        }

        private void Resource_Load(object sender, EventArgs e) {
        }

        private void btnFamilyBrowse_Click(object sender, EventArgs e) {
            FamiliesForm familiesForm = new FamiliesForm();
            familiesForm.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e) {
            openFileDialog1.AddExtension = true;
            openFileDialog1.CheckFileExists = true;
            openFileDialog1.CheckPathExists = true;
            //openFileDialog1.DefaultExt = "*.seq, *.fasta";
            openFileDialog1.Filter = "Fasta sequence files (*.seq;*.fasta)|*.SEQ;*.FASTA;|All files (*.*)|*.*";
            openFileDialog1.InitialDirectory = SNAP.Program.CurrentOptions.SeqFolder;
            openFileDialog1.Multiselect = false;
            openFileDialog1.SupportMultiDottedExtensions = true;
            openFileDialog1.Title = "Choose a sequence file";
            openFileDialog1.FileName = "";
            openFileDialog1.ShowDialog();
            txtFilename.Text = openFileDialog1.FileName;
            txtDisplayName.Text = System.IO.Path.GetFileNameWithoutExtension(Filename);
        }

        private void btnOK_Click(object sender, EventArgs e) {
            Resources.Resource resource = null;
            switch (this.cmbResourceType.SelectedItem.ToString ()) {
                case "Sequence File":
                    resource = new Resources.SeqFileResource(
                        txtDisplayName.Text, txtFilename.Text);
                    break;

                case "Weight File":
                    resource = new Resources.WgtFileResource(
                        txtDisplayName.Text, txtFilename.Text);
                    break;
                case "PSSM":
                    break;

                case "Family":
                    resource = new Resources.CompositeResource(txtFilename.Text);
                    break;
            }

            resource.Notes = txtNotes.Text;
            Program.CurrentResources.Root.Add(resource, txtFamily.Text);
            this.DialogResult = DialogResult.OK;
            Close();
        }

        #endregion private

        private class ResourceTypeItem {
            public readonly Resources.Resource _resource;

            public ResourceTypeItem(Resources.Resource resource) {
                _resource = resource;
            }

            public override string ToString() {
                return _resource.Typename; // +" (" + _resource.FileMask + ")"; 
            }
        }
/*
        private void cmbResourceType_SelectedIndexChanged(object sender, EventArgs e)
        {
            ResourceTypeItem item = (ResourceTypeItem) cmbResourceType.SelectedItem;

            foreach (System.Reflection.FieldInfo fieldInfo in item._resource.GetType ().GetFields ())
            {
                foreach (SNAP.Resources.ResourceAttribute attr in fieldInfo.GetCustomAttributes (typeof (SNAP.Resources.ResourceAttribute), false))
                {
                    if (attr is SNAP.Resources.InternalReferenceAttribute)
                    {

                    }
                }
            }
            /*
            System.Reflection.MemberInfo [] members = item._resource.GetType ().FindMembers (
                System.Reflection.MemberTypes.Field | System.Reflection.MemberTypes.Property,
                 System.Reflection.BindingFlags.Default,
                 null,
                 null);

            foreach (System.Reflection.MemberInfo memberInfo in members)
            {
                System.Reflection.pr
                memberInfo.MemberType == System.Reflection.MemberTypes.
            }
             */
    }
}

