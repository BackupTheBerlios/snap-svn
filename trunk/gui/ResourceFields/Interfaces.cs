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
    }
}