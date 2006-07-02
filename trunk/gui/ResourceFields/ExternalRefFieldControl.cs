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
    public partial class ExternalRefFieldControl : UserControl, IResourceWinformsUI
    {
        private ExternalRefFieldValue _value;

        public ExternalRefFieldControl()
        {
            InitializeComponent();
        }

        public string Mask
        {
            get
            {
                return MyValue.MyType.Mask;
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
        /// Gets or sets a value indicating whether [read only].
        /// </summary>
        /// <value><c>true</c> if [read only]; otherwise, <c>false</c>.</value>
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

        void IResourceUI.LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            LoadFromFieldValue((ExternalRefFieldValue)value);
        }

        void IResourceUI.SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            SaveToFieldValue((ExternalRefFieldValue)value);
        }

        public void LoadFromFieldValue(SNAP.Resources.ExternalRefFieldValue value)
        {
            _value = value;
            FieldText = value.ToString();
        }

        public void SaveToFieldValue(SNAP.Resources.ExternalRefFieldValue value)
        {
            if (FieldText == null || FieldText.Length == 0)
                throw new SNAP.Resources.FieldException("A required field has not been filled out");

            value.Path = FieldText;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string path = null;
            if (SNAP.Controller.ChooseFile(Mask, out path))
            {
                FieldText = path;
            }
        }

        #region IResourceUI Members

        IResourceValue IResourceUI.MyValue
        {
            get
            {
                return _value;
            }
        }

        public ExternalRefFieldValue MyValue
        {
            get
            {
                return _value;
            }
        }

        #endregion

        #region IResourceWinformsUI Members

        public Control MyControl
        {
            get
            {
                return this;
            }
        }

        #endregion

        #region IResourceWinformsUI Members

        Control IResourceWinformsUI.MyControl
        {
            get {
                return this;
            }
        }

        #endregion
    }
}
