using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SNAP.Resources;

namespace SNAP.ResourceFields
{
    public partial class NumericFieldControl : UserControl, IResourceWinformsUI
    {
        private NumericFieldValue _value;

        public NumericFieldControl()
        {
            InitializeComponent();
        }

        public  string FieldText
        {
            get
            {
                return this.numericUpDown1.Value.ToString();
            }
            set
            {
                this.numericUpDown1.Value = decimal.Parse(value);
            }
        }

        void IResourceUI.LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            this.LoadFromFieldValue((NumericFieldValue)value);
        }
        
        public void LoadFromFieldValue(NumericFieldValue value)
        {
            this.numericUpDown1.Minimum = value.MyType.MinValue;
            this.numericUpDown1.Maximum = value.MyType.MaxValue;
            this.numericUpDown1.DecimalPlaces = value.MyType.DecimalPlaces;
            this.numericUpDown1.Increment = value.MyType.Increment;
            this.numericUpDown1.Value = value.Value;
            _value = value;
        }

        public  void SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            System.Diagnostics.Debug.Assert(value.MyType is Resources.NumericFieldType);
            ((SNAP.Resources.NumericFieldValue)value).Value = numericUpDown1.Value;
        }

        public decimal MinValue
        {
            get {
                return numericUpDown1.Minimum;
            }
            set {
                numericUpDown1.Minimum = value;
            }
        }

        public decimal MaxValue
        {
            get {
                return numericUpDown1.Maximum;
            }
            set {
                numericUpDown1.Maximum = value;
            }
        }
        public decimal Increment
        {
            get
            {
                return numericUpDown1.Increment;
            }
            set
            {
                numericUpDown1.Increment = value;
            }
        }
        public int DecimalPlaces {
            get {
                return numericUpDown1.DecimalPlaces;
            }
            set {
                numericUpDown1.DecimalPlaces = value;
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

        public void SetToolTip(ToolTip provider)
        {
            provider.SetToolTip(this.numericUpDown1, _value.MyType.ToString());
        }

        #endregion

        #region IResourceUI Members


        public bool Readonly
        {
            get
            {
                return numericUpDown1.Enabled;
            }
            set
            {
                numericUpDown1.Enabled = value;
            }
        }

        #endregion
    }
}

