using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public partial class VerticalFlowLayoutPanel : Panel
    {
        protected VerticalFlowLayoutEngine _layoutEngine;
        
        public VerticalFlowLayoutPanel()
        {
            InitializeComponent();
        }

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
            int height = VerticalFlowLayoutEngine.EstimateContainerSize(this);
            //height += 13;

            Size result = new Size(
                Math.Max(width, proposedSize.Width),
                this.AutoSize ? height : Math.Max(height, proposedSize.Height)
                );

            //MessageBox.Show("VerticalFlowLayoutPanel\n" + result.ToString());
            return result;
        }
    }

    public class VerticalFlowLayoutEngine : System.Windows.Forms.Layout.LayoutEngine
    {
        public override void InitLayout(object child, BoundsSpecified specified)
        {
            base.InitLayout(child, specified);
        }

        public static int EstimateContainerSize(Control parent)
        {
            if (!parent.Visible)
                return 0;

            int totalHeight = parent.Padding.Vertical;
            foreach (Control c in parent.Controls)
            {
                // Only apply layout to visible controls.
                if (!c.Visible)
                {
                    continue;
                }

                totalHeight += 
                    c.Margin.Vertical + 
                    c.GetPreferredSize(parent.DisplayRectangle.Size).Height;
            }

            //MessageBox.Show("GetPreferredHeight\n" + totalHeight);
            return totalHeight;
        }
        
        public override bool Layout(object container, LayoutEventArgs layoutEventArgs)
        {
            Control parent = (Control)container;

            // Use DisplayRectangle so that parent.Padding is honored.
            Rectangle parentDisplayRectangle = parent.DisplayRectangle;
            Point nextControlLocation = parentDisplayRectangle.Location;

            for (int i=parent.Controls.Count - 1 ; i>=0 ; --i)
            {
                Control c = parent.Controls[i];
                // Only apply layout to visible controls.
                if (!c.Visible)
                {
                    continue;
                }

                /// docking is not allowed
                c.Dock = DockStyle.None;

                // Respect the margin of the control:
                // shift over the left and the top.
                nextControlLocation.Offset(c.Margin.Left, c.Margin.Top);

                // Set the location of the control.
                c.Location = nextControlLocation;
                
                // Set the autosized controls to their 
                // autosized heights.
                if (c.AutoSize)
                {
                    Size result = c.GetPreferredSize(parentDisplayRectangle.Size);
                    if (c.Height != result.Height)
                        c.Height = result.Height;
                }
                
                /// but set the control's width to be the maximum width possible
                int newWidth = parentDisplayRectangle.Width - c.Margin.Horizontal - parent.Padding.Horizontal;
                if (c.Width != newWidth)
                    c.Width = newWidth;

                // Move X back to the display rectangle origin.
                nextControlLocation.X = parentDisplayRectangle.X;

                // Increment Y by the height of the control 
                // and the bottom margin.
                nextControlLocation.Y += c.Height + c.Margin.Bottom;
            }

            /// if autosize is true, we make the height of the parent big enough
            /// to fit the contents
            if (parent.AutoSize)
            {
                int oldHeight = parent.Height;
                Size parentParentDisplaySize;
                if (parent.Parent != null)
                {
                    parentParentDisplaySize = parent.Parent.DisplayRectangle.Size;
                }
                else
                {
                    parentParentDisplaySize = Size.Empty;
                }

                int newHeight = parent.GetPreferredSize(parentParentDisplaySize).Height;
                if (newHeight != oldHeight)
                    parent.Height = newHeight;
                return newHeight != oldHeight;
            }

            // Optional: Return whether or not the container's 
            // parent should perform layout as a result of this 
            // layout. Some layout engines return the value of 
            // the container's AutoSize property.
            return false;
        }
    }
}
