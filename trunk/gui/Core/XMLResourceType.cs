using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP.Resources
{
    /// <summary>
    /// TODO: use immutable pattern
    /// </summary>
    public class ResourceTypeList : SortedList<string, IResourceType>
    {
    }

    /// <summary>
    /// TODO: use immutable pattern
    /// </summary>
    public class ResourceValueList : SortedList<string, IResourceValue>
    {
        /// <summary>
        /// Clones this instance.
        /// </summary>
        /// <returns></returns>
        public ResourceValueList Clone()
        {
            ResourceValueList newList = new ResourceValueList();
            foreach (IResourceValue value in this.Values)
            {
                newList.Add(value.MyType.Name, value.Clone());
            }

            return newList;
        }
    }

    #region IResourceValue

    public interface IResourceValue
    {
        IResourceType MyType
        {
            get;
        }

        /// <summary>
        /// Gets the dynamic property with the specified name.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <returns></returns>
        IResourceValue GetDynamicProperty(string name);

        /// <summary>
        /// Gets the sub values.
        /// </summary>
        /// <value>The sub values.</value>
        ResourceValueList SubValues
        {
            get;
        }

        /// <summary>
        /// Saves the XML.
        /// </summary>
        /// <param name="writer">The writer.</param>
        void SaveToXML(XmlWriter writer);

        /// <summary>
        /// Loads from XML.
        /// </summary>
        /// <param name="node">The node.</param>
        void LoadFromXML(XmlNode node);

        /// <summary>
        /// Clones this instance.
        /// </summary>
        /// <returns></returns>
        IResourceValue Clone();
    }

    #endregion ResourceValue

    #region inteface IResourceType

    public interface IResourceType
    {
        /// <summary>
        /// Gets the typename of this resource type.
        /// <example>
        /// possible values could be
        /// external_ref, internal_ref, numeric etc
        /// </example>
        /// </summary>
        /// <value>The typename.</value>
        string Typename
        {
            get;
        }

        /// <summary>
        /// Gets the name of this resource type instance.
        /// <example>
        /// possible values vould be
        /// Filename, Family, etc
        /// </example>
        /// </summary>
        /// <value>The name.</value>
        string Name
        {
            get;
            set;
        }

        /// <summary>
        /// Gets the name to display on GUI.
        /// </summary>
        /// <value>The name of the display.</value>
        string DisplayName
        {
            get;
            set;
        }

        /// <summary>
        /// Gets the help string associated with this resource type.
        /// </summary>
        /// <value>The help.</value>
        string Help
        {
            get;
            set;
        }

        /// <summary>
        /// Gets the sub types this resource type is composed of.
        /// </summary>
        /// <value>The sub types.</value>
        ResourceTypeList SubTypes
        {
            get;
        }

        /// <summary>
        /// Creates the default value.
        /// </summary>
        /// <returns></returns>
        IResourceValue CreateDefaultValue();

        /// <summary>
        /// Loads the IResourceType from the specified XmlNode.
        /// </summary>
        /// <param name="node">The node.</param>
        void LoadFromXML(XmlNode node);
    }

    #endregion inteface IResourceType

    #region Interface IResourceUI

    public interface IResourceUI
    {
        /// <summary>
        /// Gets my value.
        /// </summary>
        /// <value>My value.</value>
        IResourceValue MyValue
        {
            get;
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="T:IResourceUI"/> is readonly.
        /// </summary>
        /// <value><c>true</c> if readonly; otherwise, <c>false</c>.</value>
        bool Readonly
        {
            get;
            set;
        }

        /// <summary>
        /// Loads from field value.
        /// </summary>
        /// <param name="value">The value.</param>
        void LoadFromFieldValue(IResourceValue value);

        /// <summary>
        /// Saves information to field value.
        /// </summary>
        /// <param name="value">The value.</param>
        void SaveToFieldValue(IResourceValue value);
    }

    #endregion Interface IResourceUI

    #region ResourceType

    public class ResourceType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _displayName;

        private readonly ResourceTypeList _fields = new ResourceTypeList();
        private readonly Dictionary<string, Scripts.Script> _executions = new Dictionary<string, Scripts.Script>();

        private System.Drawing.Color _displayColor;
        #endregion Privates

        #region Properties

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        /// <value>The name.</value>
        public string Name
        {
            get
            {
                return _name;
            }
        }

        /// <summary>
        /// Gets the name of this resource type instance.
        /// <example>
        /// possible values vould be
        /// Filename, Family, etc
        /// </example>
        /// </summary>
        /// <value>The name.</value>
        string IResourceType.Name
        {
            get
            {
                return _name;
            }
            set
            {
                _name = value;
            }
        }



        /// <summary>
        /// Gets or sets the help.
        /// </summary>
        /// <value>The help.</value>
        public string Help
        {
            get
            {
                return _help;
            }
        }

        /// <summary>
        /// Gets the help string associated with this resource type.
        /// </summary>
        /// <value>The help.</value>
        string IResourceType.Help
        {
            get
            {
                return _help;
            }
            set
            {
                _help = value;
            }
        }

        public IDictionary<string, Scripts.Script> Executions
        {
            get
            {
                return _executions;
            }
        }

        /// <summary>
        /// Gets the color of the display.
        /// </summary>
        /// <value>The color of the display.</value>
        public System.Drawing.Color DisplayColor
        {
            get
            {
                return _displayColor;
            }
            set
            {
                _displayColor = value;
            }
        }






        #endregion

        /// <summary>
        /// Returns a <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </returns>
        public override string ToString()
        {
            return Name;
        }

        #region IResourceType Members

        public string Typename
        {
            get
            {
                return "resource_type";
            }
        }

        public string DisplayName
        {
            get
            {
                return _displayName;
            }
            set
            {
                _displayName = value;
            }
        }

        public ResourceTypeList SubTypes
        {
            get
            {
                return this._fields;
            }
        }

        public IResourceValue CreateDefaultValue()
        {
            return new Resource(Guid.NewGuid(), this, "");
        }

        public void LoadFromXML(XmlNode resourceNode)
        {
            XMLResourceTypeFactory.LoadFromXML(resourceNode, this);

            /// if the display color is specified, then load it,
            /// otherwise use a random color
            if (resourceNode.Attributes["display_color"] != null)
                this._displayColor = System.Drawing.Color.FromName(resourceNode.Attributes["display_color"].Value);
            else
            {
                Random random = Controller.Random;
                this._displayColor = System.Drawing.Color.FromArgb(random.Next(256), random.Next(256), random.Next(256), random.Next(256));
            }

            XMLResourceTypeFactory.CreateResourceTypeFields (this.SubTypes, resourceNode);
            foreach (System.Xml.XmlNode node in resourceNode.ChildNodes)
            {
                switch (node.Name)
                {
                    case "execute":
                        Scripts.Script executionType = XMLScriptFactory.CreateScript (node);
                        this.Executions.Add(executionType.Name, executionType);
                        break;

                    default:
                        continue;
                }
            }
        }

        #endregion
    }

    #endregion XMLResourceType
}