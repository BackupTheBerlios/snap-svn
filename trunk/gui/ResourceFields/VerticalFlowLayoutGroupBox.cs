using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class VerticalFlowLayoutGroupBox : GroupBox
    {
        protected VerticalFlowLayoutEngine _layoutEngine;
        
        public override System.Windows.Forms.Layout.LayoutEngine LayoutEngine
        {
            get
            {
                if (_layoutEngine == null)
                    _layoutEngine = new VerticalFlowLayoutEngine();

                return _layoutEngine;
            }
        }

        public override Size GetPreferredSize(Size proposedSize)
        {
            if (!this.Visible)
                return Size.Empty;

            proposedSize = base.GetPreferredSize(proposedSize);
            int width = this.Width;

            /// add 13 to avoid having the bounds of the groupbox painted on
            /// this magic number was discovered empirically by observing how much
            /// longer is a group box than a single control it contains
            /// when the contained control has a DockStyle.Fill 
            int height = VerticalFlowLayoutEngine.EstimateContainerSize(this) + 13;

            Size result = new Size(
                Math.Max(width, proposedSize.Width),
                this.AutoSize ? height : Math.Max(height, proposedSize.Height)
                );

            //MessageBox.Show("VerticalFlowLayoutPanel\n" + result.ToString());
            return result;
        }

        protected override void SetClientSizeCore(int x, int y)
        {
            /// add 13 to avoid having the bounds of the groupbox painted on
            /// this magic number was discovered empirically by observing how much
            /// longer is a group box than a single control it contains
            /// when the contained control has a DockStyle.Fill 
            this.Size = new Size(x, y + 13);
        }
    }
}
