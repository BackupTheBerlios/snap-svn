using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public interface IAbstractField
    {
        /// <summary>
        /// Gets or sets the name of the field.
        /// </summary>
        /// <value>The name of the field.</value>
        string FieldName
        {
            get;
            set;
        }

        /// <summary>
        /// Gets or sets a value indicating whether [show field name].
        /// </summary>
        /// <value><c>true</c> if [show field name]; otherwise, <c>false</c>.</value>
        bool FieldNameVisible
        {
            get;
            set;
        }

        /// <summary>
        /// Updates the field.
        /// </summary>
        /// <param name="value">The value.</param>
        void LoadFromFieldValue(SNAP.Resources.FieldValueList value);

        /// <summary>
        /// Updates the field.
        /// </summary>
        /// <param name="value">The value.</param>
        void SaveToFieldValue(SNAP.Resources.FieldValueList value);

        /// <summary>
        /// Gets or sets the field text.
        /// </summary>
        /// <value>The field text.</value>
        string FieldText
        {
            get;
            set;
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="T:TextField"/> is readonly.
        /// </summary>
        /// <value><c>true</c> if readonly; otherwise, <c>false</c>.</value>
        bool Readonly
        {
            get;
            set;
        }
    }


    public partial class TextField : AbstractField
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:TextField"/> class.
        /// </summary>
        public TextField()
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
        /// Gets or sets a value indicating whether this <see cref="T:TextField"/> is readonly.
        /// </summary>
        /// <value><c>true</c> if readonly; otherwise, <c>false</c>.</value>
        public override bool Readonly
        {
            get
            {
                return textBox1.ReadOnly;
            }
            set
            {
                textBox1.ReadOnly = value;
            }
        }

        public override void LoadFromFieldValue(SNAP.Resources.FieldValueList value)
        {
            FieldText = value.Values[0].ToString ();
        }

        public override void SaveToFieldValue(SNAP.Resources.FieldValueList field)
        {
            field.Values.Add(new SNAP.Resources.TextValue (FieldText));
        }
    }
}

