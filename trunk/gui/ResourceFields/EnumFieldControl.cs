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
    public partial class EnumFieldControl : UserControl, IResourceWinformsUI
    {
        private SNAP.Resources.EnumFieldValue _value;
        private SortedList<string, RadioButton> _radioButtons = new SortedList<string,RadioButton> ();

        public EnumFieldControl()
        {
            InitializeComponent();
        }

        void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton radioButton = (RadioButton)sender;
            if (!radioButton.Checked)
                return;

            EnumElementFieldValue selectedEnumElement = 
                (EnumElementFieldValue) _value.SubValues[radioButton.Name];

            fieldPanel1.SubValues = selectedEnumElement.SubValues;
            fieldPanel1.Visible = (selectedEnumElement.SubValues.Count > 0);
        }

        #region IResourceWinformsUI Members

        public Control MyControl
        {
            get {
                return this;
            }
        }

        #endregion

        #region IResourceUI Members

        public SNAP.Resources.IResourceValue MyValue
        {
            get
            {
                return _value;
            }
        }

        void IResourceUI.LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            LoadFromFieldValue((EnumFieldValue)value);
        }

        void IResourceUI.SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            SaveToFieldValue((EnumFieldValue)value);

        }

        public void LoadFromFieldValue(EnumFieldValue value)
        {
            _value = value;

            _radioButtons.Clear();
            flowLayoutPanel1.Controls.Clear();
            //fieldPanel1.Controls.Clear();

            foreach (EnumElementFieldValue v in _value.SubValues.Values)
            {
                RadioButton radioButton = new RadioButton();

                radioButton.Name = v.MyType.Name;
                radioButton.Text = v.MyType.DisplayName;
                radioButton.AutoSize = true;

                /// TODO: handle tool tip
                radioButton.CheckedChanged += new EventHandler(radioButton_CheckedChanged);

                _radioButtons.Add(radioButton.Name, radioButton);
                flowLayoutPanel1.Controls.Add(radioButton);
            }

            _radioButtons[_value.SelectedElement.MyType.Name].Checked = true;
        }

        public void SaveToFieldValue(EnumFieldValue value)
        {
            int index = -1;
            for (int i=0 ; i<_radioButtons.Count ; ++i) {
                if (_radioButtons.Values[i].Checked)
                    index = i;
            }
            fieldPanel1.UpdateResource();

            _value.SelectedElementIndex = index;
            _value.SelectedElement.SubValues = fieldPanel1.SubValues.Clone();
        }

        #endregion

        #region IResourceUI Members


        public bool Readonly
        {
            get
            {
                throw new Exception("The method or operation is not implemented.");
            }
            set
            {
                throw new Exception("The method or operation is not implemented.");
            }
        }

        #endregion

        private void EnumFieldControl_Load(object sender, EventArgs e)
        {

        }
    }
}

