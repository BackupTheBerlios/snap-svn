using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP.Resources
{
    #region NumericFieldType

    public class NumericFieldType : IResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private string _display;

        #endregion Privates

        #region Properties

        public decimal MinValue;
        public decimal MaxValue;
        public decimal DefaultValue;
        public decimal Increment;
        public int DecimalPlaces;

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
                return "numeric";
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
            get {
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
            get {
                throw new System.NotImplementedException();
            }
        }

        /// <summary>
        /// Creates the default value.
        /// </summary>
        /// <returns></returns>
        public IResourceValue CreateDefaultValue()
        {
            return new NumericFieldValue(DefaultValue, this);
        }

        /// <summary>
        /// Loads the IResourceType from the specified XmlNode.
        /// </summary>
        /// <param name="node">The node.</param>
        public void LoadFromXML(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals(Typename));

            ResourceType.LoadFromXML(node, this);

            this.MinValue = decimal.MinValue;
            if (node.Attributes["min"] != null)
                this.MinValue = decimal.Parse(node.Attributes["min"].Value);

            this.MaxValue = decimal.MaxValue;
            if (node.Attributes["max"] != null)
                this.MaxValue = decimal.Parse(node.Attributes["max"].Value);

            if (node.Attributes["default"] != null)
                this.DefaultValue = decimal.Parse(node.Attributes["default"].Value);
            else
            {
                if (node.Attributes["min"] != null)
                {
                    if (node.Attributes["max"] != null)
                    {
                        this.DefaultValue = decimal.Divide((MinValue + MaxValue), 2);
                    }
                    else
                        this.DefaultValue = this.MinValue;
                }
                else if (node.Attributes["max"] != null)
                    this.DefaultValue = this.MaxValue;
                else
                    this.DefaultValue = 0;
            }

            this.Increment = 1;
            if (node.Attributes["increment"] != null)
                this.Increment = decimal.Parse(node.Attributes["increment"].Value);

            this.DecimalPlaces = 0;
            if (node.Attributes["precision"] != null)
                this.DecimalPlaces = int.Parse(node.Attributes["precision"].Value);

            /// the usual properties (name, help etc) are handled by the caller
        }

        #endregion
    }

    #endregion NumericFieldType

    #region NumericFieldValue

    public class NumericFieldValue : IResourceValue
    {
        public decimal Value;
        private readonly NumericFieldType _type;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:NumericValue"/> class.
        /// </summary>
        /// <param name="value">The value.</param>
        public NumericFieldValue(decimal value, NumericFieldType type)
        {
            Value = value;
            _type = type;
        }

        public override string ToString()
        {
            return Value.ToString();
        }

        #region IResourceValue Members

        IResourceValue IResourceValue.GetDynamicProperty(string name)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        ResourceValueList IResourceValue.SubValues
        {
            get { 
                throw new Exception("The method or operation is not implemented."); 
            }
        }

        public void LoadFromXML(System.Xml.XmlNode node)
        {
            this.Value = decimal.Parse (node.Attributes ["value"].Value);
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

        public NumericFieldType MyType
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
        public NumericFieldValue Clone()
        {
            return new NumericFieldValue(this.Value, this._type);
        }

        #endregion
    }

    #endregion NumericFieldValue
}
