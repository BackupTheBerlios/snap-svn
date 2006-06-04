using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class AbstractField : UserControl, IAbstractField
    {
        public AbstractField()
        {
            InitializeComponent();
        }

        #region IAbstractField Members

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

        public virtual void LoadFromFieldValue(SNAP.Resources.FieldValue value)
        {
        }

        public virtual void SaveToFieldValue(SNAP.Resources.FieldValue value)
        {
        }

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

        #endregion
    }
}
