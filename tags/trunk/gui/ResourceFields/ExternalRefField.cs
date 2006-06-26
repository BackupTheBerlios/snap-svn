using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class ExternalRefField : AbstractField
    {
        public string Mask = null;

        public ExternalRefField()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Gets or sets the name of the field.
        /// </summary>
        /// <value>The name of the field.</value>
        public override string FieldName
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
        public override string FieldText
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
        public override bool Readonly
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
        public override bool FieldNameVisible
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

        public override void LoadFromFieldValue(SNAP.Resources.FieldValueList value)
        {
            FieldText = value.Values[0].ToString();
        }

        public override void SaveToFieldValue(SNAP.Resources.FieldValueList value)
        {
            if (FieldText == null || FieldText.Length == 0)
                throw new System.InvalidOperationException("A required field has not been filled out");

            value.Values.Add(new SNAP.Resources.ExternalRefValue (FieldText));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string path = null;
            if (SNAP.Controller.ChooseFile (Mask, out path))
            {
                FieldText = path;
            }
        }
    }
}
