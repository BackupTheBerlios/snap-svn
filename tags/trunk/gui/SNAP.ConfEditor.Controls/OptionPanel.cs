using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.ComponentModel.Design;


namespace SNAP.ConfEditor
{
    //    [Designer("System.Windows.Forms.Design.ParentControlDesigner, System.Design", typeof(IDesigner))]
    [Designer(typeof(MyUserControlDesigner))]
    public partial class OptionPanel : UserControl
    {
        private SNAP.Engine.SettingType _settingType;
        public OptionPanel()
        {
            InitializeComponent();
//            _panels = new Panel[1];
//            _panels[0] = ContentPanel;
        }

        public SNAP.Engine.SettingType SettingType
        {
            get
            {
                return _settingType;
            }
            set
            {
                _settingType = value;
            }
        }

        public string ContentLabelText
        {
            get
            {
                return ContentLabel.Text;
            }
            set
            {
                ContentLabel.Text = value;
            }
        }
        public bool ContentOverride
        {
            get
            {
                return checkOverride.Checked;
            }
            set
            {
                checkOverride.Checked = value;
            }
        }

        public event EventHandler ContentOverrideChanged;
        public event EventHandler ContentLoad;

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

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
        public Panel MyChildPanel
        {
            get
            {
                return ContentPanel;
            }
        }

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
    }
}
