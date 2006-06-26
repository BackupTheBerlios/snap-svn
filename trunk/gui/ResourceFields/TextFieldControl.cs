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
    /*
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
        void LoadFromFieldValue(SNAP.Resources.IResourceValue value);

        /// <summary>
        /// Updates the field.
        /// </summary>
        /// <param name="value">The value.</param>
        void SaveToFieldValue(SNAP.Resources.IResourceValue value);

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
     */


    public partial class TextFieldControl : UserControl, IResourceWinformsUI
    {
        private TextFieldValue _value;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:TextField"/> class.
        /// </summary>
        public TextFieldControl()
        {
            InitializeComponent();
        }

        public TextFieldControl(TextFieldValue value)
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

        #region IResourceUI Members

        public SNAP.Resources.IResourceValue MyValue
        {
            get {
                return _value;
            }
        }

        void IResourceUI.LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            LoadFromFieldValue((TextFieldValue)value);
        }

        public void LoadFromFieldValue(SNAP.Resources.TextFieldValue value)
        {
            _value = value;
            FieldText = value.ToString();
        }

        void IResourceUI.SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            SaveToValue((TextFieldValue)value);
        }

        public void SaveToValue(TextFieldValue value)
        {
            value.Text = FieldText;
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
                return textBox1.Enabled;
            }
            set
            {
                textBox1.Enabled = value;
            }
        }

        #endregion
    }
}

