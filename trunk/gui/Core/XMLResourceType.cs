using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP.Resources
{
    public class ResourceTypeList : SortedList<string, IResourceType>
    {
    }

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
        private readonly System.Collections.Generic.Dictionary<string, Script> _executions = new Dictionary<string, Script>();

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

        public IDictionary<string, Script> Executions
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

        #region Save/Load

        /// <summary>
        /// Loads the types.
        /// </summary>
        /// <param name="filename">The filename.</param>
        /// <returns></returns>
        public static System.Collections.Generic.SortedDictionary<string, ResourceType> LoadTypes(string filename)
        {
            System.Collections.Generic.SortedDictionary<string, ResourceType> list = new SortedDictionary<string, ResourceType>();

            System.Xml.XmlDocument document = new System.Xml.XmlDocument();
            document.Load(filename);

            System.Xml.XmlNode rootNode = document.ChildNodes[1];
            foreach (System.Xml.XmlNode resourceNode in rootNode.ChildNodes)
            {
                try
                {
                    if (resourceNode.Name == "resource_type")
                    {
                        ResourceType resourceType = LoadResourceType(resourceNode);
                        list.Add(resourceType.Name, resourceType);
                    }
                }
                catch (Exception x)
                {
                    SNAP.Controller.ShowException(x);
                }
            }
            return list;
        }
        private static IResourceType LoadResourceField(System.Xml.XmlNode fieldNode)
        {
            IResourceType field = null;
            switch (fieldNode.Name)
            {
                case "text":
                    field = new TextFieldType();
                    break;

                case "internal_ref":
                    field = new InternalRefFieldType();
                    break;


                case "external_ref":
                    field = new ExternalRefFieldType();
                    break;

                case "numeric":
                    field = new NumericFieldType();
                    break;

                case "enum":
                    field = new EnumFieldType();
                    break;
            }

            if (field != null)
                field.LoadFromXML(fieldNode);

            return field;
        }

        private static Script.IStep LoadExportStep(System.Xml.XmlNode exportNode)
        {
            System.Diagnostics.Debug.Assert(exportNode.Name.Equals("export"));
            string type = exportNode.Attributes["type"].Value;

            Script.IExportStep export = null;
            switch (type)
            {
                case "params":
                    {
                        string filename = exportNode.Attributes["name"].Value;
                        export = new Script.ParamsExport(filename);
                    }
                    break;

                default:
                    throw new System.ArgumentException("The export type " + type + " is invalid");
            }

            foreach (XmlNode fieldNode in exportNode.ChildNodes)
            {
                switch (fieldNode.Name)
                {
                    case "path":
                        {
                            string name = fieldNode.Attributes["name"].Value;
                            string value = fieldNode.Attributes["value"].Value;
                            Script.PathExportField field = new Script.PathExportField(
                                name,
                                value);

                            export.Fields.Add(field);
                        }
                        break;

                    case "text":
                        {
                            string name = fieldNode.Attributes["name"].Value;
                            string value = fieldNode.Attributes["value"].Value;
                            Script.TextExportField field = new Script.TextExportField(
                                name,
                                value);

                            export.Fields.Add(field);
                        }
                        break;

                    default:
                        throw new System.ArgumentException("The export type " + fieldNode.Name + " is invalid");
                }
            }

            return export;
        }

        private static Script.ConditionalStep LoadConditionalStep(XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name.Equals("conditional"));
            switch (node.FirstChild.Name)
            {
                case "if":
                    break;

                case "if_not":
                    break;

                default:
                    break;
            }

            switch (node.FirstChild.NextSibling.Name)
            {
                case "then":
                    break;

                default:
                    break;
            }

            if (node.FirstChild.NextSibling.NextSibling != null) {
                switch (node.FirstChild.NextSibling.NextSibling.Name)
                {
                    case "else":
                        break;

                    default:
                        break;
                }
            }

            return null;
        }

        private static Script LoadResourceExecution(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name == "execute");
            string name = node.Attributes["name"].Value;
            string help = node.Attributes["help"].Value;

            Script execType = new Script(name, help);
            foreach (XmlNode stepNode in node.ChildNodes)
            {
                switch (stepNode.Name)
                {
                    case "run":
                        {
                            string bin = stepNode.Attributes["bin"].Value;
                            string parameters = stepNode.Attributes["params"].Value;
                            execType.Steps.Add(new Script.ExecuteStep(bin, parameters));
                        }
                        break;

                    case "import":
                        {
                            string filename = stepNode.Attributes["name"].Value;
                            execType.Steps.Add(new Script.ImportStep(filename));
                        }
                        break;

                    case "export":
                        {
                            execType.Steps.Add(LoadExportStep(stepNode));
                        }
                        break;

                    case "conditional":
                        {
                            execType.Steps.Add(LoadConditionalStep(stepNode));
                        }
                        break;

                    default:
                        throw new System.ArgumentException("The step type " + stepNode.Name + " is invalid");
                }
            }

            return execType;
        }

        internal static void LoadResourceFields(IDictionary<string, IResourceType> container, XmlNode fieldParentNode)
        {
            foreach (System.Xml.XmlNode node in fieldParentNode.ChildNodes)
            {
                IResourceType fieldType = LoadResourceField(node);
                if (fieldType != null)
                    container.Add(fieldType.Name, fieldType);
            }
        }

        private static ResourceType LoadResourceType(System.Xml.XmlNode resourceNode)
        {
            System.Diagnostics.Debug.Assert(resourceNode.Name == "resource_type");
            ResourceType resourceType = new ResourceType();
            resourceType.LoadFromXML(resourceNode);
            return resourceType;
        }

        /// <summary>
        /// Loads from XML, the common properties which all resource types share
        /// </summary>
        /// <param name="resourceType">Type of the resource.</param>
        public static void LoadFromXML(XmlNode node, IResourceType resourceType)
        {
            if (node.Attributes["name"] == null)
                throw new System.Xml.XmlException("The resource_type node does not contain a 'name' attribute at " + node.BaseURI);

            resourceType.Name = node.Attributes["name"].Value;

            if (node.Attributes["help"] != null)
                resourceType.Help = node.Attributes["help"].Value;
            else
            {
                resourceType.Help = string.Empty;
            }

            if (node.Attributes["display_name"] != null)
                resourceType.DisplayName = node.Attributes["display_name"].Value;
            else
                resourceType.DisplayName = resourceType.Name;
        }

        #endregion Save/Load

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
            ResourceType.LoadFromXML(resourceNode, this);

            /// if the display color is specified, then load it,
            /// otherwise use a random color
            if (resourceNode.Attributes["display_color"] != null)
                this._displayColor = System.Drawing.Color.FromName(resourceNode.Attributes["display_color"].Value);
            else
            {
                Random random = Controller.Random;
                this._displayColor = System.Drawing.Color.FromArgb(random.Next(256), random.Next(256), random.Next(256), random.Next(256));
            }

            LoadResourceFields(this.SubTypes, resourceNode);
            foreach (System.Xml.XmlNode node in resourceNode.ChildNodes)
            {
                switch (node.Name)
                {
                    case "execute":
                        Script executionType = LoadResourceExecution(node);
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