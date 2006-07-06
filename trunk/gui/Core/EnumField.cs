using System.Collections.Generic;
using System.Xml;

namespace SNAP.Resources
{
    #region EnumElementFieldType

    /// <summary>
    /// 
    /// </summary>
    public class EnumElementFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;
        private readonly ResourceTypeList _fields = new ResourceTypeList();

        #endregion Privates

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
            get
            {
                return "enum_element";
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
        public ResourceTypeList SubTypes
        {
            get {
                return _fields;
            }
        }

        /// <summary>
        /// Creates the default value.
        /// </summary>
        /// <returns></returns>
        IResourceValue IResourceType.CreateDefaultValue()
        {
            return new EnumElementFieldValue(this);
        }

        /// <summary>
        /// Creates the default value.
        /// </summary>
        /// <returns></returns>
        public EnumElementFieldValue CreateDefaultValue()
        {
            return new EnumElementFieldValue(this);
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals(Typename));
            XMLResourceTypeFactory.LoadFromXML(node, this);
            XMLResourceTypeFactory.CreateResourceTypeFields (this.SubTypes, node);
        }

        #endregion
    }

    #endregion EnumValue

    #region EnumFieldType

    /// <summary>
    /// 
    /// </summary>
    public class EnumFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;

        private readonly ResourceTypeList _elements = new ResourceTypeList();

        #endregion Privates

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
                return "enum";
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

        public string Name {
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

        public string Help
        {
            get
            {
                return _help;
            }
        }

        /// <summary>
        /// Gets the sub types this resource type is composed of.
        /// </summary>
        /// <value>The sub types.</value>
        public ResourceTypeList SubTypes
        {
            get {
                return _elements;
            }
        }

        public IResourceValue CreateDefaultValue()
        {
            return new EnumFieldValue(this);
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals(Typename));
            XMLResourceTypeFactory.LoadFromXML(node, this);

            /// add all the elements of the enum
            foreach (XmlNode elementNode in node.SelectNodes ("enum_element"))
            {
                EnumElementFieldType elementType = new EnumElementFieldType();
                elementType.LoadFromXML(elementNode);
                this._elements.Add(elementType.Name, elementType);
            }
        }

        #endregion
    }

    #endregion EnumFieldType

    #region EnumFieldValue

    public class EnumFieldValue : IResourceValue
    {
        #region Privates

        private readonly EnumFieldType _type;
        private readonly ResourceValueList _elements;
        private int _selectedElementIndex;

        #endregion Privates

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="T:EnumFieldValue"/> class.
        /// </summary>
        /// <param name="type">The type.</param>
        public EnumFieldValue(EnumFieldType type)
            : this (new ResourceValueList (), type)
        {
            foreach (EnumElementFieldType elementType in _type.SubTypes.Values)
            {
                _elements.Add(elementType.Name, elementType.CreateDefaultValue());
            }

            if (_elements.Count > 0)
                SelectedElementIndex = 0;
        }

        internal EnumFieldValue(ResourceValueList elements, EnumFieldType type)
        {
            _type = type;
            _elements = elements;
            if (_elements.Count > 0)
                SelectedElementIndex = 0;
        }

        #endregion Constructors

        /// <summary>
        /// Gets the selected element.
        /// </summary>
        /// <value>The selected element.</value>
        public EnumElementFieldValue SelectedElement
        {
            get
            {
                return (EnumElementFieldValue) _elements.Values[_selectedElementIndex];
            }
        }

        public int SelectedElementIndex
        {
            get
            {
                return _selectedElementIndex;
            }
            set
            {
                _selectedElementIndex = value;
            }
        }

        #region IResourceValue Members

        /// <summary>
        /// Gets my type.
        /// </summary>
        /// <value>My type.</value>
        public IResourceType MyType
        {
            get {
                return _type;
            }
        }

        public IResourceValue GetDynamicProperty(string name)
        {
            switch (name)
            {
                case "Selected":
                    return SelectedElement;

                case "Name":
                    return new TextFieldValue(MyType.Name, new TextFieldType("name", ""));

                case "DisplayName":
                    return new TextFieldValue(MyType.DisplayName, new TextFieldType("display_name", ""));

                default:
                    throw new System.ArgumentOutOfRangeException();
            }
        }

        public ResourceValueList SubValues
        {
            get {
                return _elements;
            }
        }

        public void SaveToXML(System.Xml.XmlWriter writer)
        {
            writer.WriteStartElement("field");
            writer.WriteAttributeString("name", MyType.Name);
            writer.WriteAttributeString("value", SelectedElement.MyType.Name);

            SelectedElement.SaveToXML(writer);

            writer.WriteEndElement();
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            string selectedElementName = node.Attributes["value"].Value;
            int index = _elements.IndexOfKey(selectedElementName);
            if (index < 0)
                throw new FieldException("The enum \"" + this.MyType.DisplayName + "\" does not contain the enum element " + selectedElementName);

            SelectedElementIndex = index;
            SelectedElement.LoadFromXML(node);
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
        public EnumFieldValue Clone()
        {
            EnumFieldValue newValue = new EnumFieldValue(
                this._elements.Clone(),
                this._type
            );

            newValue._selectedElementIndex = this._selectedElementIndex;
            return newValue;
        }

        #endregion
    }

    #endregion EnumFieldValue

    #region EnumElementFieldValue

    public class EnumElementFieldValue : IResourceValue
    {
        #region Privates

        private readonly EnumElementFieldType _type;
        private ResourceValueList _fields;

        #endregion Privates

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="T:EnumElementFieldValue"/> class.
        /// </summary>
        /// <param name="type">The type.</param>
        public EnumElementFieldValue(EnumElementFieldType type)
            : this (new ResourceValueList(), type)
        {
            foreach (IResourceType fieldType in type.SubTypes.Values)
            {
                this.SubValues.Add(fieldType.Name, fieldType.CreateDefaultValue());
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="T:EnumElementFieldValue"/> class.
        /// </summary>
        /// <param name="fields">The fields.</param>
        /// <param name="type">The type.</param>
        internal EnumElementFieldValue(ResourceValueList fields, EnumElementFieldType type)
        {
            _type = type;
            _fields = fields;
        }

        #endregion Constructor

        #region IResourceValue Members

        /// <summary>
        /// Gets my type.
        /// </summary>
        /// <value>My type.</value>
        public IResourceType MyType
        {
            get {
                return _type;
            }
        }

        /// <summary>
        /// Gets the dynamic property with the specified name.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <returns></returns>
        public IResourceValue GetDynamicProperty(string name)
        {
            switch (name)
            {
                case "Name":
                    return new TextFieldValue(MyType.Name, new TextFieldType("name", ""));

                case "DisplayName":
                    return new TextFieldValue(MyType.DisplayName, new TextFieldType("display_name", ""));

                default:
                    if (SubValues.ContainsKey (name))
                        return SubValues[name];
                    
                    throw new System.ArgumentOutOfRangeException();
            }
        }

        /// <summary>
        /// Gets the sub values.
        /// </summary>
        /// <value>The sub values.</value>
        public ResourceValueList SubValues
        {
            get {
                return this._fields;
            }
            set
            {
                this._fields = value;
            }
        }

        public void SaveToXML(System.Xml.XmlWriter writer)
        {
            foreach (IResourceValue value in SubValues.Values)
            {
                value.SaveToXML(writer);
            }
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            foreach (XmlNode fieldNode in node.SelectNodes("field"))
            {
                string fieldName = fieldNode.Attributes["name"].Value;
                SubValues[fieldName].LoadFromXML(fieldNode);
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
        public EnumElementFieldValue Clone()
        {
            EnumElementFieldValue newValue = new EnumElementFieldValue(
                this._fields.Clone(),
                this._type
                );

            return newValue;
        }

        #endregion
    }

    #endregion EnumElementFieldValue
}