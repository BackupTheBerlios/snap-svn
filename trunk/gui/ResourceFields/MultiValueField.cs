using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class MultiValueField : AbstractField
    {
        private List<MultiValueFieldElement> _elements = new List<MultiValueFieldElement>();
        private Resources.FieldType _fieldType = null;
                
        public MultiValueField()
        {
            InitializeComponent();
        }

        public Resources.FieldType FieldType
        {
            get
            {
                return _fieldType;
            }
            set
            {
                if (_fieldType != value)
                {
                    /// remove previous fields
                    panelFields.Controls.Clear();
                    _elements.Clear();

                    _fieldType = value;
                    linkLabel1.Text = _fieldType.Name;
                    for (int i = 0; i < _fieldType.MinOccurs; ++i)
                    {
                        AddElement(false);
                    }
                }

            }
        }

        public override string FieldName
        {
            get
            {
                return _fieldType.Name;
            }
            set
            {
                //base.FieldName = value;
            }
        }

        public override bool Readonly
        {
            get
            {
                return false;
            }
            set
            {
                throw new System.NotImplementedException();
            }
        }

        public override string FieldText
        {
            get
            {
                return "";
            }
            set
            {
                throw new System.NotImplementedException();
            }
        }

        public override bool FieldNameVisible
        {
            get
            {
                return linkLabel1.Visible;
            }
            set {
                linkLabel1.Visible = value;
            }
        }

        public override void LoadFromFieldValue(SNAP.Resources.FieldValueList value)
        {
            for (int i = 0; i < value.Values.Count; ++i)
            {
                if (i >= _elements.Count)
                    AddElement(true);

                // TODO: fix the HACK here
                SNAP.Resources.FieldValueList itemFieldValue = new SNAP.Resources.FieldValueList(value.Type);
                itemFieldValue.Values.Add(value.Values[i]);
                _elements[i].LoadFromFieldValue(itemFieldValue);
            }
        }

        public override void SaveToFieldValue(SNAP.Resources.FieldValueList value)
        {
            foreach (MultiValueFieldElement element in _elements) {
                element.SaveToFieldValue (value);
            }
        }

        #region Implementation

        private void AddElement(bool canRemove)
        {
            MultiValueFieldElement fieldElement = new MultiValueFieldElement ();
            fieldElement.FieldType = this.FieldType;

            fieldElement.ElementIndex = _elements.Count;
            fieldElement.RemoveVisible = canRemove;
            fieldElement.RemoveClick += new EventHandler(fieldElement_RemoveClick);
            fieldElement.UpClick += new EventHandler(fieldElement_UpClick);
            fieldElement.DownClick += new EventHandler(fieldElement_DownClick);
            fieldElement.Dock = DockStyle.Top;
            
            panelFields.Controls.Add(fieldElement);
            _elements.Add(fieldElement);

            /*
            Panel panelField = new System.Windows.Forms.Panel();
            Control field = new SNAP.ResourceFields.ExternalRefField();
            Button btnDown = new System.Windows.Forms.Button();
            Button btnUp = new System.Windows.Forms.Button();
            Button btnRemove = new System.Windows.Forms.Button();
            //panelField.SuspendLayout();
            //this.SuspendLayout();

            // 
            // panelField
            // 
            panelField.Controls.Add(field);
            panelField.Controls.Add(btnDown);
            panelField.Controls.Add(btnUp);
            panelField.Controls.Add(btnRemove);
            panelField.MaximumSize = new Size(0, 26);
            panelField.Dock = System.Windows.Forms.DockStyle.Top;
            panelField.Name = "panelField" + _fieldCount;

            // 
            // field
            // 
            field.Dock = System.Windows.Forms.DockStyle.Fill;
            (field as SNAP.ResourceFields.IField).FieldName = FieldType.Name;
            (field as SNAP.ResourceFields.IField).FieldNameVisible = false;
            field.Name = "field" + _fieldCount;

            // 
            // btnDown
            // 
            btnDown.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            btnDown.BackgroundImage = global::SNAP.ResourceFields.Properties.Resources.images_34_;
            btnDown.Dock = System.Windows.Forms.DockStyle.Left;
            btnDown.Name = "btnDown" + _fieldCount;
            btnDown.Size = new System.Drawing.Size(26, 26);
            // 
            // btnUp
            // 
            btnUp.BackgroundImage = global::SNAP.ResourceFields.Properties.Resources.images_17_;
            btnUp.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            btnUp.Dock = System.Windows.Forms.DockStyle.Left;
            btnUp.Name = "btnUp" + _fieldCount;
            btnUp.Size = new System.Drawing.Size(26, 26);

            if (canRemove)
            {
                // 
                // btnRemove
                // 
                btnRemove.Dock = System.Windows.Forms.DockStyle.Left;
                btnRemove.Font = new System.Drawing.Font("Book Antiqua", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                btnRemove.ForeColor = System.Drawing.Color.DarkRed;
                btnRemove.Name = "btnRemove" + _fieldCount;
                btnRemove.Size = new System.Drawing.Size(26, 26);
                btnRemove.Text = "R";
                btnRemove.Click += new EventHandler(btnRemove_Click);
            }

            // 
            // MultiValueField
            // 
            this.panelFields.Controls.Add(panelField);

            //panelField.ResumeLayout(false);
            //panelField.PerformLayout();
            //ResumeLayout(false);
             */
        }

        void fieldElement_DownClick(object sender, EventArgs e)
        {
            int index = panelFields.Controls.IndexOf((Control)sender);
            if (index > 0)
                panelFields.Controls.SetChildIndex((Control)sender, index - 1);
        }

        void fieldElement_UpClick(object sender, EventArgs e)
        {
            int index = panelFields.Controls.IndexOf((Control)sender);
            if (index < panelFields.Controls.Count)
                panelFields.Controls.SetChildIndex((Control)sender, index + 1);
        }

        void fieldElement_RemoveClick(object sender, EventArgs e)
        {
            MultiValueFieldElement element = (MultiValueFieldElement)sender;
            panelFields.Controls.Remove(element);
            _elements.Remove(element);
            
            for (int i = element.ElementIndex; i < _elements.Count; ++i)
            {
                --_elements[i].ElementIndex;
            }
        }

        /// <summary>
        /// Handles the Click event of the btnRemove control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="T:System.EventArgs"/> instance containing the event data.</param>
        void btnRemove_Click(object sender, EventArgs e)
        {
            Button btnRemove = sender as Button;
            Panel fieldPanel = (Panel)btnRemove.Parent;
            panelFields.Controls.Remove(fieldPanel);
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            AddElement(true);
        }

        #endregion Implementation


    }
}
