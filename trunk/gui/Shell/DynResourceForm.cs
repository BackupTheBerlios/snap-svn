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
        }


        public DynResourceForm(Resources.Resource resource)
        {
            InitializeComponent();
            InitStaticFields(
                resource.Name,
                (resource.MyParent != null) ? resource.MyParent.QualifiedName : string.Empty
                );

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
                if (_resource == value)
                    return;

                _resource = value;

                /// we clone the subvalues of the resource
                /// to avoid partial updates to the resource - 
                /// e.g. updating only some fields of a resource
                /// when some fields have errors or are incomplete.
                /// this allows us to do resource updates transactionally
                resourceFieldsControl1.SubValues = _resource.SubValues.Clone ();
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
            catch (FieldException)
            {
                /// ignore field exceptions, they are handled on a lower level
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }

        public void UpdateResource()
        {
            fieldName.SaveToFieldValue(fieldName.MyValue);
            string name = fieldName.MyValue.ToString();
            
            /// check that a name has been specified
            if (string.IsNullOrEmpty(name))
            {
                fieldName.ErrorText = "The name field must be specified";
                fieldName.ErrorTextVisible = true;
                throw new FieldException(fieldName.ErrorText);
            }
            else if (SelectedResource.MyParent != null)
            {
                /// check that the parent doesnt have another resource with the same name
                if (SelectedResource.MyParent.Children.ContainsKey(name))
                {
                    if (SelectedResource.MyParent.Children[name] != SelectedResource)
                    {
                        fieldName.ErrorText = "The parent node " + SelectedResource.MyParent.Name + "  already contains a resource named " + name;
                        fieldName.ErrorTextVisible = true;
                        throw new FieldException(fieldName.ErrorText);
                    }
                }
            }

            resourceFieldsControl1.UpdateResource();

            /// if we got here, it means that all the fields were updated successfully.
            /// so we can copy back the results to the resource
            /// (remember: the subvalues were cloned)
            foreach (IResourceValue value in resourceFieldsControl1.SubValues.Values)
            {
                SelectedResource.SubValues[value.MyType.Name] = value;
            }

            SelectedResource.Name = fieldName.MyValue.ToString();
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
            catch (SNAP.Resources.FieldException)
            {
                /// ignore field exceptions, they are handled in a lower level
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }

        private void btnApply_Click(object sender, EventArgs e)
        {
            try
            {
                UpdateResource();
            }
            catch (SNAP.Resources.FieldException)
            {
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }

        #endregion Implementation
    }
}
