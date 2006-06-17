using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class MultiValueFieldElement : UserControl
    {
        #region Privates

        private SNAP.Resources.FieldType _fieldType;

        #endregion Privates

        #region Constructors

        public MultiValueFieldElement()
        {
            InitializeComponent();
        }

        #endregion Constructors

        #region Events

        public event System.EventHandler RemoveClick;
        public event System.EventHandler UpClick;
        public event System.EventHandler DownClick;

        #endregion Events

        public void LoadFromFieldValue(SNAP.Resources.FieldValueList value)
        {
            field.LoadFromFieldValue(value);
        }
        
        public void SaveToFieldValue(SNAP.Resources.FieldValueList value)
        {
            field.SaveToFieldValue(value);
        }

        #region Properties
        
        public SNAP.Resources.FieldType FieldType
        {
            get
            {
                return _fieldType;
            }
            set
            {
                if (_fieldType == value)
                    return;

                _fieldType = value;
                Controls.Remove( (Control) this.field);
                this.field = null;

                switch (_fieldType.Type)
                {
                    case "text":
                        this.field = new SNAP.ResourceFields.TextField();
                        break;

                    case "internal_ref":
                        this.field = new SNAP.ResourceFields.InternalRefField();
                        break;

                    case "external_ref":
                        this.field = new SNAP.ResourceFields.ExternalRefField();
                        break;

                    default:
                        System.Diagnostics.Trace.Fail("Unknown field type \"" + _fieldType.Type + "\"");
                        break;
                }

                this.field.FieldName = _fieldType.Name;
                //this.field.FieldText = "";

                (this.field as Control).Dock = System.Windows.Forms.DockStyle.Fill;
                this.field.FieldNameVisible = false;
                (this.field as Control).Location = new System.Drawing.Point(78, 0);
                (this.field as Control).Name = "field";
                this.field.Readonly = false;
                (this.field as Control).Size = new System.Drawing.Size(157, 26);

                this.Controls.Add ( (Control) this.field);
                this.Controls.SetChildIndex (this.field, 0);
            }
        }

        public bool RemoveVisible
        {
            get
            {
                return btnRemove.Visible;
            }
            set
            {
                btnRemove.Visible = value;
            }
        }

        public int ElementIndex = 0;

        #endregion Properties

        #region Implementation

        private void btnRemove_Click(object sender, EventArgs e)
        {
            System.EventHandler handler = RemoveClick;
            if (handler != null)
            {
                handler(this, new EventArgs());
            }
        }

        #endregion Implementation

        private void btnDown_Click(object sender, EventArgs e)
        {
            EventHandler downClick = DownClick;
            if (downClick != null)
                downClick(this, e);
        }

        private void btnUp_Click(object sender, EventArgs e)
        {
            EventHandler upClick = UpClick;
            if (upClick != null)
                upClick(this, e);
        }
    }
}
