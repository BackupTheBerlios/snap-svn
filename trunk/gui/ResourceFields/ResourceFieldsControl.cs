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
    public partial class ResourceFieldsControl : VerticalFlowLayoutGroupBox
    {
        public ResourceFieldsControl()
        {
            InitializeComponent();
        }

        private SNAP.Resources.ResourceValueList _values;
        public readonly SortedDictionary<string, IResourceUI> UIFields = new SortedDictionary<string, IResourceUI>();

        public SNAP.Resources.ResourceValueList SubValues
        {
            get
            {
                return _values;
            }
            set
            {
                if (_values == value)
                    return;

                _values = value;
                this.SuspendLayout();

                /// remove all fields from the panel
                foreach (IResourceUI field in UIFields.Values)
                {
                    //groupFields.Controls.Remove((Control)field);
                    Controls.Remove((Control)field);
                }

                this.UIFields.Clear();

                /// display on the gui all the available fields
                this.Visible = _values.Values.Count > 0;
                foreach (SNAP.Resources.IResourceValue field in _values.Values)
                {
                    SNAP.Resources.IResourceType fieldType = field.MyType;
                    IResourceWinformsUI newField = (IResourceWinformsUI)
                        Controller.CreateResourceUI(field);

                    /// wrap the field with a decorative panel
                    newField = new FieldDecoratorControl(newField);

                    //newField.MyControl.Dock = DockStyle.Top;
                    newField.MyControl.AutoSize = true;
                    //this.groupFields.Controls.Add(newField.MyControl);
                    Controls.Add(newField.MyControl);

                    /// TODO: tooltip
                    //this.toolTip1.SetToolTip((Control)newField, field.Help);

                    /// add this field to the list of fields
                    this.UIFields.Add(fieldType.Name, newField);
                }

                this.ResumeLayout();
                //this.PerformLayout();
            }
        }

        public void UpdateResource()
        {
            System.Diagnostics.Debug.Assert(_values!= null);

            /// fill in additional fields
            foreach (IResourceUI fieldControl in this.UIFields.Values)
            {
                fieldControl.SaveToFieldValue(fieldControl.MyValue);
            }
        }
    }
}
