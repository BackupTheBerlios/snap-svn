using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class InternalRefField : UserControl, AbstractField
    {
        private SNAP.Resources.Resource _selectedResource;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:InternalRefField"/> class.
        /// </summary>
        public InternalRefField()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Gets or sets the name of the field.
        /// </summary>
        /// <value>The name of the field.</value>
        public string FieldName
        {
            get
            {
                return this.linkLabel1.Text;
            }
            set
            {
                this.linkLabel1.Text = value;
            }
        }
        /// <summary>
        /// Gets or sets the field text.
        /// </summary>
        /// <value>The field text.</value>
        public string FieldText
        {
            get
            {
                return textBox1.Text;
            }
            set
            {
                textBox1.Text = value;
            }
        }

        /// <summary>
        /// Gets or sets the selected resource.
        /// </summary>
        /// <value>The selected resource.</value>
        public SNAP.Resources.Resource SelectedResource
        {
            get
            {
                return _selectedResource;
            }
            set
            {
                _selectedResource = value;
                if (_selectedResource != null)
                {
                    textBox1.Text = _selectedResource.QualifiedName;
                }
                else
                {
                    textBox1.Text = "";
                }
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="T:InternalRefField"/> is readonly.
        /// </summary>
        /// <value><c>true</c> if readonly; otherwise, <c>false</c>.</value>
        public bool Readonly
        {
            get
            {
                return !button1.Visible;
            }
            set
            {
                button1.Visible = !value;
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether [show field name].
        /// </summary>
        /// <value><c>true</c> if [show field name]; otherwise, <c>false</c>.</value>
        public bool FieldNameVisible
        {
            get
            {
                return linkLabel1.Visible;
            }
            set
            {
                linkLabel1.Visible = value;
            }
        }

        public void LoadFromFieldValue(SNAP.Resources.FieldValue value)
        {
            SelectedResource = (SNAP.Resources.Resource) value.Values[0];
        }

        public void SaveToFieldValue(SNAP.Resources.FieldValue value)
        {
            if (SelectedResource == null)
                throw new System.InvalidOperationException("A required field has not been filled out");

            value.Values.Add(SelectedResource);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            SNAP.Resources.Resource resource = null;
            if (SNAP.Controller.ChooseResource(out resource))
            {
                SelectedResource = resource;
            }

        }
    }
}
