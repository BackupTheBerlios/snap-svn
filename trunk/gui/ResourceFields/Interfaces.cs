using SNAP.Resources;
using System.Windows.Forms;

namespace SNAP.ResourceFields
{
    public interface IResourceWinformsUI : IResourceUI
    {
        /// <summary>
        /// Gets my control.
        /// </summary>
        /// <value>My control.</value>
        Control MyControl
        {
            get;
        }

        /// <summary>
        /// Sets the tool tip for this control.
        /// </summary>
        /// <param name="provider">The provider.</param>
        void SetToolTip(ToolTip provider);
    }
}