namespace SNAP.Resources
{
    #region InternalRefFieldType

    public class InternalRefFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;

        #endregion Privates

        #region Constructors

        public InternalRefFieldType()
        {
        }

        public InternalRefFieldType(string name, string help)
        {
            _name = name;
            _help = help;
            _display = _name;
        }

        #endregion Constructors

        #region IResourceType Members

        public string Typename
        {
            get
            {
                return "internal_ref";
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
        public string Name
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
        /// Gets the name to display on GUI.
        /// </summary>
        /// <value>The name of the display.</value>
        public string DisplayName
        {
            get
            {
                return _display;
            }
            set
            {
                _display = value;
            }
        }

        /// <summary>
        /// Gets the help string associated with this resource type.
        /// </summary>
        /// <value>The help.</value>
        public string Help
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

        ResourceTypeList IResourceType.SubTypes
        {
            get { throw new System.Exception("The method or operation is not implemented."); }
        }

        public InternalRefFieldValue CreateDefaultValue()
        {
            /// TODO: implement this more cleverly
            return new InternalRefFieldValue(string.Empty, this);
        }

        IResourceValue IResourceType.CreateDefaultValue()
        {
            return this.CreateDefaultValue();
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals(Typename));
            ResourceType.LoadFromXML(node, this);

        }

        #endregion
    }

    #endregion InternalRefField

    #region InternalRefValue

    public class InternalRefFieldValue : IResourceValue
    {
        public string ResourceName;
        private readonly InternalRefFieldType _type;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:InternalRefScriptableValue"/> class.
        /// </summary>
        /// <param name="resourceName">Name of the resource.</param>
        public InternalRefFieldValue(string resourceName, InternalRefFieldType type)
        {
            ResourceName = resourceName;
            _type = type;
        }

        /// <summary>
        /// Gets my resource.
        /// </summary>
        /// <value>My resource.</value>
        public SNAP.Resources.Resource MyResource
        {
            get
            {
                return SNAP.Controller.CurrentResources.FindResource(ResourceName);
            }
            set
            {
                ResourceName = value.QualifiedName;
            }
        }

        /// <summary>
        /// Implicit operators the specified value.
        /// </summary>
        /// <param name="value">The value.</param>
        /// <returns></returns>
        public static explicit operator SNAP.Resources.Resource(InternalRefFieldValue value)
        {
            return value.MyResource;
        }

        /// <summary>
        /// Returns a <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </returns>
        public override string ToString()
        {
            return ResourceName;
        }

        #region IResourceValue Members

        public IResourceValue GetDynamicProperty(string variableName)
        {
            return MyResource.GetDynamicProperty(variableName);
        }

        ResourceValueList IResourceValue.SubValues
        {
            get { 
                throw new System.Exception("The method or operation is not implemented."); 
            }
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            this.ResourceName = node.Attributes ["value"].Value;
        }

        public void SaveToXML(System.Xml.XmlWriter writer)
        {
            writer.WriteStartElement("field");
            writer.WriteAttributeString("name", MyType.Name);
            writer.WriteAttributeString("value", ToString());
            writer.WriteEndElement();
        }

        #endregion

        public IResourceType MyType
        {
            get
            {
                return _type;
            }
        }
    }

    #endregion InternalRefValue
}