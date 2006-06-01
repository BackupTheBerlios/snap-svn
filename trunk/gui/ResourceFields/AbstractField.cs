using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class AbstractField : UserControl
    {
        public AbstractField()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Gets or sets the name of the field.
        /// </summary>
        /// <value>The name of the field.</value>
        public virtual string FieldName
        {
            get
            {
                return "";
            }
            set
            {
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether [show field name].
        /// </summary>
        /// <value><c>true</c> if [show field name]; otherwise, <c>false</c>.</value>
        public virtual bool FieldNameVisible
        {
            get
            {
                return true;
            }
            set
            {
            }
        }

        /// <summary>
        /// Updates the field.
        /// </summary>
        /// <param name="value">The value.</param>
        public virtual void LoadFromFieldValue(SNAP.Resources.FieldValue value)
        {
            throw new System.NotImplementedException();
        }
        /// <summary>
        /// Updates the field.
        /// </summary>
        /// <param name="value">The value.</param>
        public virtual void SaveToFieldValue(SNAP.Resources.FieldValue value)
        {
            throw new System.NotImplementedException();
        }

        /// <summary>
        /// Gets or sets the field text.
        /// </summary>
        /// <value>The field text.</value>
        public virtual string FieldText
        {
            get
            {
                return "";
            }
            set
            {
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="T:TextField"/> is readonly.
        /// </summary>
        /// <value><c>true</c> if readonly; otherwise, <c>false</c>.</value>
        public virtual bool Readonly
        {
            get
            {
                return false;
            }
            set
            {
            }
        }
    }
}
