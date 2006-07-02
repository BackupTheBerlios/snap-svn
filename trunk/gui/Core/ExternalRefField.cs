namespace SNAP.Resources
{
    #region ExternalRefFieldType

    public class ExternalRefFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;

        #endregion Privates

        #region Properties

        public string Mask;

        #endregion Properties

        #region IResourceType Members

        /// <summary>
        /// Gets the typename of this resource type.
        /// <example>
        /// possible values could be
        /// external_ref, internal_ref, numeric etc
        /// </example>
        /// </summary>
        /// <value>The typename.</value>
        public string Typename
        {
            get {
                return "external_ref";
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
            get {
                return _name;
            }
            set
            {
                _name = value;
            }
        }

        public string Name
        {
            get
            {
                return _name;
            }
        }

        /// <summary>
        /// Gets the name to display on GUI.
        /// </summary>
        /// <value>The name of the display.</value>
        public string DisplayName
        {
            get {
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
            get {
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

        /// <summary>
        /// Gets the sub types this resource type is composed of.
        /// </summary>
        /// <value>The sub types.</value>
        ResourceTypeList IResourceType.SubTypes
        {
            get { throw new System.Exception("The method or operation is not implemented."); }
        }

        public IResourceValue CreateDefaultValue()
        {
            return new ExternalRefFieldValue("", this);
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            SNAP.Resources.ResourceType.LoadFromXML (node, this);

            Mask = string.Empty;
            if (node.Attributes["mask"] != null)
                Mask = node.Attributes["mask"].Value;
        }

        #endregion
    }
    #endregion

    #region ExternalRefFieldValue

    public class ExternalRefFieldValue : IResourceValue
    {
        public string Path;
        private readonly ExternalRefFieldType _type;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:ExternalRefValue"/> class.
        /// </summary>
        /// <param name="path">The path.</param>
        public ExternalRefFieldValue(string path, ExternalRefFieldType type)
        {
            Path = path;
            _type = type;
        }

        /// <summary>
        /// Returns a <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </returns>
        public override string ToString()
        {
            return Path;
        }

        #region IResourceValue Members

        public IResourceValue GetDynamicProperty(string variableName)
        {
            switch (variableName)
            {
                case "Folder":
                    /// TODO: dynamically create the resource type
                    return new ExternalRefFieldValue(System.IO.Path.GetDirectoryName(Path), null);

                default:
                    throw new System.ArgumentException("The variable " + variableName + " is invalid for an ExternalRef Field");
            }
        }

        ResourceValueList IResourceValue.SubValues
        {
            get { throw new System.Exception("The method or operation is not implemented."); }
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            this.Path = node.Attributes["value"].Value;
        }

        public void SaveToXML(System.Xml.XmlWriter writer)
        {
            writer.WriteStartElement("field");
            writer.WriteAttributeString("name", MyType.Name);
            writer.WriteAttributeString("value", ToString());
            writer.WriteEndElement();
        }

        IResourceType IResourceValue.MyType
        {
            get
            {
                return _type;
            }
        }

        public ExternalRefFieldType MyType
        {
            get
            {
                return _type;
            }
        }

        /// <summary>
        /// Clones this instance.
        /// </summary>
        /// <returns></returns>
        IResourceValue IResourceValue.Clone()
        {
            return this.Clone();
        }

        /// <summary>
        /// Clones this instance.
        /// </summary>
        /// <returns></returns>
        public ExternalRefFieldValue Clone()
        {
            return new ExternalRefFieldValue (this.Path, this._type);
        }

        #endregion
    }

    #endregion ExternalRefValue
}
    