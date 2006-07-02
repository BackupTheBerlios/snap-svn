using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.ComponentModel.Design;


namespace SNAP.ResourceFields
{
    public partial class FieldDecoratorControl : UserControl, IResourceWinformsUI
    {
        #region Privates

        private IResourceWinformsUI _resource;

        #endregion Privates

        #region Constructor

        public FieldDecoratorControl()
        {
            InitializeComponent();
//            _panels = new Panel[1];
//            _panels[0] = ContentPanel;
        }

        public FieldDecoratorControl(IResourceWinformsUI content)
            : this ()
        {
            Content = content;
        }

        #endregion Constructor

        #region Additional Methods & Properties

        public IResourceWinformsUI Content
        {
            get
            {
                return _resource;
            }
            set
            {
                if (_resource != null)
                {
                    //panelRight.Controls.Remove(
                    tableLayoutPanel1.Controls.Remove (_resource.MyControl);
                }

                _resource = value;
                if (value != null)
                {
                    //value.MyControl.Dock = DockStyle.Fill;
                    value.MyControl.Dock = DockStyle.Top;
                    value.MyControl.AutoSize = true;
                    
                    System.Reflection.PropertyInfo autoSizeModeProperty = 
                        value.MyControl.GetType ().GetProperty ("AutoSizeMode", typeof(AutoSizeMode));
                    if (autoSizeModeProperty != null)
                    {
                        autoSizeModeProperty.SetValue(value.MyControl, AutoSizeMode.GrowAndShrink, null);
                    }

                    tableLayoutPanel1.Controls.Add(value.MyControl, 2, 0);
                    ContentLabel.Text = value.MyValue.MyType.DisplayName;
                }
            }
        }

        /// <summary>
        /// Gets or sets the error text.
        /// </summary>
        /// <value>The error text.</value>
        public string ErrorText
        {
            get
            {
                return labelError.Text;
            }
            set
            {
                labelError.Text = value;
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether [error text visible].
        /// </summary>
        /// <value><c>true</c> if [error text visible]; otherwise, <c>false</c>.</value>
        public bool ErrorTextVisible
        {
            get
            {
                return labelError.Visible;
            }
            set
            {
                labelError.Visible = value;
            }
        }

        #endregion Additional Methods & Properties

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
            get {
                return _resource.MyValue;
            }
        }

        public void LoadFromFieldValue(SNAP.Resources.IResourceValue value)
        {
            _resource.LoadFromFieldValue(value);
        }

        public void SaveToFieldValue(SNAP.Resources.IResourceValue value)
        {
            labelError.Visible = false;
            try
            {
                _resource.SaveToFieldValue(value);
            }
            catch (SNAP.Resources.FieldException x)
            {
                labelError.Text = x.Message;
                labelError.Visible = true;
                throw;
            }
        }

        #endregion

        #region IResourceUI Members


        public bool Readonly
        {
            get
            {
                return checkOverride.Enabled;
            }
            set
            {
                if (Content != null)
                    Content.Readonly = value;

                if (value)
                {
                    this.checkOverride.Checked = false;
                    this.checkOverride.Enabled = false;
                    this.checkOverride.FlatStyle = FlatStyle.Popup;
                }
                else
                {
                    this.checkOverride.Enabled = true;
                    this.checkOverride.FlatStyle = FlatStyle.Flat;
                }
            }
        }

        #endregion

        #region Implementation

        private void FieldDecoratorControl_Click(object sender, EventArgs e)
        {
            if (!Readonly)
                this.checkOverride.Checked = true;

        }

        #endregion Implementation
    }
}
