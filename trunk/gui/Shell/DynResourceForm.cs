using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SNAP.Resources;


namespace SNAP
{
    public partial class DynResourceForm : Form
    {
        #region Constructors

        public DynResourceForm()
        {
            InitializeComponent();
            InitStaticFields(string.Empty, string.Empty);

            foreach (ResourceType type in Controller.CurrentResources.ResourceTypes.Values)
            {
                this.cmbResourceType.Items.Add(type);
            }


            //textField1.FieldText = Guid.NewGuid().ToString ();
        }


        public DynResourceForm(Resources.Resource resource)
        {
            InitializeComponent();
            InitStaticFields(resource.Name, resource.Parent.QualifiedName);

            this.cmbResourceType.Items.Add(resource.MyType);
            cmbResourceType.SelectedIndex = 0;

            /// this must be after the combobox item is changed
            /// because the combobox item change deletes the current resource
            /// and generates a new default resource of the given type
            SelectedResource = resource;

            //fieldFamily.Readonly = true;
            //fieldName.Readonly = true;
            //fieldParent.Readonly = true;
            //fieldName.Readonly = true;

            //textField1.Readonly = true;
            //textField1.FieldText = resource.ID.ToString();
        }



        private void InitStaticFields(string name, string parent)
        {
            TextFieldType nameField = new TextFieldType(
                "Name",
                "The name of the resource"
                );

            InternalRefFieldType familyField = new InternalRefFieldType(
                "Parent name",
                "The fully qualified name of parent of this resource"
                );

            this.fieldName.Content = (SNAP.ResourceFields.IResourceWinformsUI)
                Controller.CreateResourceUI(new TextFieldValue(name, nameField));

            this.fieldParent.Content = (SNAP.ResourceFields.IResourceWinformsUI)
                Controller.CreateResourceUI(new InternalRefFieldValue(parent, familyField));
        }

        #endregion Constructors

        private SNAP.Resources.Resource _resource;

        #region Properties

        /// <summary>
        /// Gets or sets the selected resource.
        /// </summary>
        /// <value>The selected resource.</value>
        public Resource SelectedResource
        {
            get
            {
                return _resource;
            }
            set
            {
                _resource = value;
                resourceFieldsControl1.SubValues = _resource.SubValues;
            }
        }

        /// <summary>
        /// Gets or sets the selected resource parent.
        /// </summary>
        /// <value>The selected resource parent.</value>
        public Resource SelectedResourceParent
        {
            get
            {
                //return fieldFamily.SelectedResource;
                return ((SNAP.Resources.InternalRefFieldValue)fieldParent.MyValue).MyResource;
            }
            set
            {
                //fieldFamily.SelectedResource = value;
                ((SNAP.Resources.InternalRefFieldValue)fieldParent.MyValue).ResourceName = value.QualifiedName;
                fieldParent.LoadFromFieldValue(fieldParent.MyValue);
            }
        }

        #endregion Properties

        #region Implementation

        private void cmbResourceType_SelectedIndexChanged(object sender, EventArgs e)
        {
            panelExecutions.Controls.Clear();
            ResourceType type = (ResourceType)cmbResourceType.SelectedItem;
            SelectedResource = new Resource(Guid.NewGuid(), type, "");

            /// display on the gui all the available executions
            panelExecutions.Visible = type.Executions.Count > 0;
            foreach (SNAP.Resources.Script execType in type.Executions.Values)
            {
                Button execButton = new Button();
                execButton.Name = execType.Name;
                execButton.Text = execType.Name;
                toolTip1.SetToolTip(execButton, execType.Help);

                execButton.AutoSize = true;
                execButton.AutoSizeMode = AutoSizeMode.GrowAndShrink;
                execButton.Click += new EventHandler(execButton_Click);
                execButton.BackColor = Color.LightBlue;
                execButton.FlatStyle = FlatStyle.Popup;

                panelExecutions.Controls.Add(execButton);
            }
        }

        void execButton_Click(object sender, EventArgs e)
        {
            try
            {
                UpdateResource();

                Button execButton = (Button)sender;
                Script execType = SelectedResource.MyType.Executions[execButton.Name];
                execType.Execute(SelectedResource);
                //SNAP.Resources.Execution.Run(execType.Name, SelectedResource);
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }

        public void UpdateResource()
        {
            //SelectedResource.Name = fieldName.FieldText;
            //SelectedResource.Name = fieldName.MyValue.ToString();

            resourceFieldsControl1.UpdateResource();
        }

        /// <summary>
        /// Handles the Click event of the btnOK control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        private void btnOK_Click(object sender, EventArgs e)
        {
            try
            {
                UpdateResource();
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }
        #endregion Implementation
    }
}
