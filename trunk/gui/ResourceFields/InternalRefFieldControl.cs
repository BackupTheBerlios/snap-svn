using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using SNAP.Resources;

namespace SNAP.ResourceFields
{
    public partial class InternalRefFieldControl : UserControl, IResourceWinformsUI
    {
        private InternalRefFieldValue _value;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:InternalRefField"/> class.
        /// </summary>
        public InternalRefFieldControl()
        {
            InitializeComponent();
        }

        public InternalRefFieldControl(InternalRefFieldValue value)
            : this ()
        {
            LoadFromFieldValue(value);
        }

        /// <summary>
        /// Gets or sets the field text.
        /// </summary>
        /// <value>The field text.</value>
        public  string FieldText
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
                return _value.MyResource;
            }
            set
            {
                _value.MyResource = value;
                if (SelectedResource != null)
                {
                    textBox1.Text = SelectedResource.QualifiedName;
                }
                else
                {
                    textBox1.Text = "";
                }
            }
        }

        void IResourceUI.LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            LoadFromFieldValue((InternalRefFieldValue)value);
        }

        public void LoadFromFieldValue(InternalRefFieldValue value)
        {
            _value = value;
        }

        void IResourceUI.SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            SaveToFieldValue((InternalRefFieldValue)value);
        }

        public void SaveToFieldValue(InternalRefFieldValue value)
        {
            if (SelectedResource == null)
                throw new System.InvalidOperationException("A required field has not been filled out");

            ((SNAP.Resources.InternalRefFieldValue) value).ResourceName = SelectedResource.QualifiedName;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            SNAP.Resources.Resource resource = null;
            if (SNAP.Controller.ChooseResource(out resource))
            {
                SelectedResource = resource;
            }

        }

        #region IResourceUI Members

        public IResourceValue MyValue
        {
            get {
                return _value;
            }
        }

        #endregion

        #region IResourceWinformsUI Members

        public Control MyControl
        {
            get {
                return this;
            }
        }

        #endregion

        #region IResourceUI Members


        public bool Readonly
        {
            get
            {
                return button1.Enabled;
            }
            set
            {
                button1.Enabled = value;
            }
        }

        #endregion
    }
}
