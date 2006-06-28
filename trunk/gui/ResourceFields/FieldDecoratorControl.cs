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
    //    [Designer("System.Windows.Forms.Design.ParentControlDesigner, System.Design", typeof(IDesigner))]
//    [Designer(typeof(ResourceTypeDesigner))]
    public partial class FieldDecoratorControl : UserControl, IResourceWinformsUI
    {
        private IResourceWinformsUI _resource;
        //private SNAP.Engine.SettingType _settingType;
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

                    //panelRight.Controls.Add(value.MyControl);
                    tableLayoutPanel1.Controls.Add(value.MyControl, 2, 0);
                    /*
                    value.MyControl.MinimumSize = new Size(
                        value.MyControl.Parent.Width - value.MyControl.Margin.Horizontal,
//                        (int)ColumnStyles[2].Width - value.MyControl.Margin.Horizontal,
                        //value.MyControl.Height
                        40
                        );
                     */
                    ContentLabel.Text = value.MyValue.MyType.DisplayName;

                    //DetermineSize();
                }
            }
        }

        #region Designer
        /*
        Panel[] _panels;
        public int Layers
        {
            get
            {
                return _panels.Length;
            }
            set
            {
                if (value < 1)
                    return;

                Panel[] newPanels = new Panel[value];
                for (int i = 0; i < _panels.Length && i < newPanels.Length; ++i)
                    newPanels[i] = _panels[i];

                for (int i = _panels.Length; i < newPanels.Length; ++i)
                {
                    newPanels[i] = new Panel();
                    newPanels[i].Dock = DockStyle.Top;
                    this.Controls.Add(newPanels[i]);
                }
            }
        }
         */


        /*
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
        public Panel MyChildPanel
        {
            get
            {
                return ContentPanel;
            }
        }
         * 

        class MyUserControlDesigner : System.Windows.Forms.Design.ControlDesigner
        {
            public override void Initialize(IComponent comp)
            {
                base.Initialize(comp);
                OptionPanel uc = (OptionPanel)comp;
                EnableDesignMode (uc.MyChildPanel, "MyChildPanel");
            }

        }

        #endregion Designer

        private void checkOverride_CheckedChanged(object sender, EventArgs e)
        {
            ContentPanel.Enabled = checkOverride.Checked;

            EventHandler handler = ContentOverrideChanged;
            if (handler != null)
                handler(this, EventArgs.Empty);
        }
         */

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
            catch (Exception x)
            {
                labelError.Text = x.Message;
                labelError.Visible = true;
                throw;
            }
            finally
            {
                //DetermineSize();
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

        private void FieldDecoratorControl_Click(object sender, EventArgs e)
        {
            if (!Readonly)
                this.checkOverride.Checked = true;

        }

        private void FieldDecoratorControl_SizeChanged(object sender, EventArgs e)
        {
            SuspendLayout();
            /// set the table to the required width
            tableLayoutPanel1.MinimumSize = new Size(this.ClientSize.Width, 0);
            tableLayoutPanel1.MaximumSize = new Size(this.ClientSize.Width, 0);
            ResumeLayout();
            //MessageBox.Show(tableLayoutPanel1.Size.ToString());
        }
    }
    #endregion Designer
/*
    internal class ResourceTypeDesigner : System.Windows.Forms.Design.ControlDesigner
    {
        public override System.ComponentModel.Design.DesignerVerbCollection Verbs
        {
            get
            {
                DesignerVerbCollection v = new DesignerVerbCollection();
                v.Add(new DesignerVerb("Edit ResourceType", new EventHandler
                (SampleVerbHandler)));
                return v;
            }
        }
        private void SampleVerbHandler(object sender, System.EventArgs e)
        {
            Form form = new Form();
            PropertyGrid grid = new PropertyGrid ();
            SNAP.Resources.IResourceType resourceType = new SNAP.Resources.TextFieldType();
            grid.SelectedObject = resourceType;
            grid.Dock = DockStyle.Fill;
            form.Controls.Add(grid);
            form.ShowDialog();
            ((OptionPanel) this.Control ).Content = (IResourceWinformsUI)
                Controller.CreateResourceUI (resourceType.CreateDefaultValue ());
        }

    }
*/
}
