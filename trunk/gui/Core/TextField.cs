namespace SNAP.Resources
{
    #region TextFieldType

    public class TextFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;

        #endregion Privates

        #region Constructors

        public TextFieldType()
        {
        }

        public TextFieldType(string name, string help)
        {
            _name = name;
            _help = help;
            _display = _name;
        }

        #endregion Constructors

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
                return "text";
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

        IResourceValue IResourceType.CreateDefaultValue()
        {
            return this.CreateDefaultValue();
        }

        public TextFieldValue CreateDefaultValue()
        {
            return new TextFieldValue(string.Empty, this);
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals(this.Typename));

            ResourceType.LoadFromXML(node, this);
        }

        #endregion
    }

    #endregion TextField

    #region TextValue

    public class TextFieldValue : IResourceValue
    {
        #region Privates

        public string Text;
        private TextFieldType _type;

        #endregion Privates

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="T:TextFieldValue"/> class.
        /// </summary>
        /// <param name="text">The text.</param>
        public TextFieldValue(string text, TextFieldType type)
        {
            Text = text;
            _type = type;
        }

        #endregion Constructors

        #region Methods

        /// <summary>
        /// Returns a <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
        /// </returns>
        public override string ToString()
        {
            return Text;
        }

        #endregion Methods

        #region IResourceValue Members

        IResourceValue IResourceValue.GetDynamicProperty(string name)
        {
            throw new System.Exception("The method or operation is not implemented.");
        }

        ResourceValueList IResourceValue.SubValues
        {
            get { throw new System.Exception("The method or operation is not implemented."); }
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            this.Text = node.Attributes["value"].Value;
        }

        public void SaveToXML(System.Xml.XmlWriter writer)
        {
            writer.WriteStartElement("field");
            writer.WriteAttributeString("name", MyType.Name);
            writer.WriteAttributeString("value", ToString());
            writer.WriteEndElement();
        }

        public IResourceType MyType {
            get {
                return _type;
            }
        }

        #endregion
    }

    #endregion TextValue
}