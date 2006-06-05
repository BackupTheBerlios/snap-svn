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
        #region Privates

        private readonly SortedDictionary<string, SNAP.ResourceFields.AbstractField> Fields = new SortedDictionary<string,SNAP.ResourceFields.AbstractField> ();
        private Resource _selectedResource = null;

        #endregion Privates

        #region Constructors

        public DynResourceForm()
        {
            InitializeComponent();

            foreach (ResourceType type in ResourceType.LoadTypes(Controller.ResourceTypesFile).Values)
            {
                this.cmbResourceType.Items.Add(type);
            }

            textField1.FieldText = Guid.NewGuid().ToString ();
        }

        public DynResourceForm(Resources.Resource resource)
        {
            InitializeComponent();

            this.cmbResourceType.Items.Add(resource.ResourceType);
            cmbResourceType.SelectedIndex = 0;
            
            /// this must be after the combobox item is changed
            /// because the combobox item change deletes the current resource
            /// and generates a new default resource of the given type
            SelectedResource = resource;

            fieldFamily.Readonly = true;
            fieldFamily.SelectedResource = resource.Parent;

            fieldName.Readonly = true;
            fieldName.FieldText = resource.Name;

            textField1.Readonly = true;
            textField1.FieldText = resource.ID.ToString();

            /// now fill in the field values 
            foreach (FieldValue fieldValue in SelectedResource.Fields.Values)
            {
                this.Fields[fieldValue.Type.Name].LoadFromFieldValue(fieldValue);
            }

        }

        #endregion Constructors

        #region Properties

        /// <summary>
        /// Gets or sets the selected resource.
        /// </summary>
        /// <value>The selected resource.</value>
        public Resource SelectedResource
        {
            get
            {
                return _selectedResource;
            }
            set
            {
                _selectedResource = value;
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
                return fieldFamily.SelectedResource;
            }
            set
            {
                fieldFamily.SelectedResource = value;
            }
        }

        /// <summary>
        /// Gets or sets the family.
        /// </summary>
        /// <value>The family.</value>
        public Resources.Resource Family
        {
            get
            {
                return fieldFamily.SelectedResource;
            }
            set
            {
                fieldFamily.SelectedResource = value;
            }
        }

        #endregion Properties

        #region Implementation

        private void cmbResourceType_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (SNAP.ResourceFields.AbstractField field in Fields.Values)
            {
                groupFields.Controls.Remove((Control)field);
            }
            this.Fields.Clear();
            panelExecutions.Controls.Clear();

            ResourceType type = (ResourceType)cmbResourceType.SelectedItem;
            
            SelectedResource = new Resource(Guid.NewGuid(), type, "");

            /// display on the gui all the available fields
            groupFields.Visible = type.Fields.Values.Count > 0;
            foreach (FieldType field in type.Fields.Values)
            {
                if (field.MinOccurs != 1 || field.MaxOccurs != 1)
                {
                    SNAP.ResourceFields.MultiValueField newField = new SNAP.ResourceFields.MultiValueField();
                    newField.FieldType = field;
                    newField.Dock = DockStyle.Top;
                    this.groupFields.Controls.Add(newField);
                    this.toolTip1.SetToolTip(newField, field.Help);
                    
                    /// add this field to the list of fields
                    this.Fields.Add (field.Name, newField);
                }
                else
                {
                    SNAP.ResourceFields.AbstractField newField = null;
                    switch (field.Type)
                    {
                        case "text":
                            newField = new SNAP.ResourceFields.TextField();
                            break;

                        case "internal_ref":
                            newField = new SNAP.ResourceFields.InternalRefField ();
                            break;
                        case "external_ref":
                            newField = new SNAP.ResourceFields.ExternalRefField();
                            (newField as SNAP.ResourceFields.ExternalRefField).Mask = 
                                (field as ExternalRefFieldType).Mask;
                            break;

                        default:
                            break;
                    }

                    newField.FieldName = field.Name;
                    newField.FieldText = "";
                    (newField as Control).Dock = DockStyle.Top;
                    this.groupFields.Controls.Add( (Control) newField);
                    this.toolTip1.SetToolTip((Control)newField, field.Help);

                    /// add this field to the list of fields
                    this.Fields.Add(field.Name, newField);
                }
            }

            /// display on the gui all the available executions
            panelExecutions.Visible = type.Executions.Count > 0;
            foreach (SNAP.Resources.ExecutionType execType in type.Executions.Values)
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
                ExecutionType execType = SelectedResource.ResourceType.Executions[execButton.Name];
                SNAP.Resources.Execution.Run(execType.Name, SelectedResource);
            }
            catch (Exception x)
            {
                Controller.ShowException(x);
            }
        }

        public void UpdateResource()
        {
            System.Diagnostics.Debug.Assert(SelectedResource != null);

            SelectedResource.Name = fieldName.FieldText;

            /// fill in additional fields
            foreach (SNAP.ResourceFields.AbstractField fieldControl in this.Fields.Values)
            {
                FieldValue fieldValue = null;
                if (!SelectedResource.Fields.ContainsKey(fieldControl.FieldName))
                {
                    // TODO: make this simpler
                    fieldValue =
                        new FieldValue(SelectedResource.ResourceType.Fields[fieldControl.FieldName]);
                    SelectedResource.Fields[fieldControl.FieldName] = fieldValue;
                }
                else
                {
                    fieldValue = SelectedResource.Fields[fieldControl.FieldName];
                }

                fieldValue.Values.Clear();
                fieldControl.SaveToFieldValue(fieldValue);
            }
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