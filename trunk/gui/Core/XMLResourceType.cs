using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP.Resources
{
    #region ResourceType

    public class ResourceType
    {
        #region Privates

        private string _name;
        private string _help;
        private readonly System.Collections.Generic.Dictionary <string, FieldType> _fields = new Dictionary <string, FieldType>();
        private readonly System.Collections.Generic.Dictionary<string, ExecutionType> _executions = new Dictionary<string, ExecutionType>();

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
            private set
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
            private set
            {
                _help = value;
            }
        }

        public IDictionary  <string, FieldType> Fields
        {
            get
            {
                return _fields;
            }
        }

        public IDictionary<string, ExecutionType> Executions
        {
            get
            {
                return _executions;
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
        public static System.Collections.Generic.SortedDictionary <string, ResourceType> LoadTypes(string filename)
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
                        ResourceType resourceType = LoadResourceType (resourceNode);
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

        private static FieldType LoadResourceField (System.Xml.XmlNode fieldNode)
        {
            string fieldName = fieldNode.Attributes["name"].Value;
            string fieldHelp = fieldNode.Attributes["help"].Value;

            int fieldMinOccurs = 1, fieldMaxOccurs = 1;
            if (fieldNode.Attributes["minOccurs"] != null)
            {
                if (fieldNode.Attributes["minOccurs"].Value == "unbounded")
                    fieldMinOccurs = int.MaxValue;
                else
                {
                    fieldMinOccurs = int.Parse(fieldNode.Attributes["minOccurs"].Value);
                    if (fieldMinOccurs > fieldMaxOccurs)
                        fieldMaxOccurs = fieldMinOccurs;
                }
            }

            if (fieldNode.Attributes["maxOccurs"] != null)
            {
                if (fieldNode.Attributes["maxOccurs"].Value == "unbounded")
                    fieldMaxOccurs = int.MaxValue;
                else
                {
                    fieldMaxOccurs = int.Parse(fieldNode.Attributes["minOccurs"].Value);
                }
            }

            System.Diagnostics.Trace.Assert(fieldMaxOccurs >= fieldMinOccurs);

            switch (fieldNode.Name)
            {
                case "text":
                    return new TextFieldType(fieldName, fieldHelp, fieldMinOccurs, fieldMaxOccurs);

                case "internal_ref":
                    return new InternalRefFieldType(fieldName, fieldHelp, fieldMinOccurs, fieldMaxOccurs);

                case "external_ref":
                    string mask = (fieldNode.Attributes["mask"] != null) ? fieldNode.Attributes["mask"].Value : null;
                    return new ExternalRefFieldType(fieldName, fieldHelp, fieldMinOccurs, fieldMaxOccurs, mask);
            }

            System.Diagnostics.Trace.Fail ("unknown field type");
            return null;
        }

        private static ExecutionType LoadResourceExecution(System.Xml.XmlNode node)
        {
            System.Diagnostics.Debug.Assert(node.Name == "execute");
            string name = node.Attributes["name"].Value;
            string help = node.Attributes["help"].Value;
            string bin = node.Attributes["bin"].Value;
            string parameters = node.Attributes["params"].Value;

            ExecutionType execType = new ExecutionType(name, help, bin, parameters);
            foreach (XmlNode output in node.SelectNodes("dynamic_output"))
            {
                execType.DynamicOutputFiles.Add (output.Attributes ["name"].Value);
            }

            return execType;
        }
        
        private static ResourceType LoadResourceType(System.Xml.XmlNode resourceNode)
        {
            System.Diagnostics.Debug.Assert(resourceNode.Name == "resource_type");
            ResourceType resourceType = new ResourceType();
            resourceType.Name = resourceNode.Attributes["name"].Value;
            resourceType.Help = resourceNode.Attributes["help"].Value;

            foreach (System.Xml.XmlNode node in resourceNode.ChildNodes)
            {
                switch (node.Name)
                {
                    case "text":
                    case "internal_ref":
                    case "external_ref":
                    {
                        FieldType fieldType = LoadResourceField (node);
                        resourceType.Fields.Add (fieldType.Name, fieldType);
                    }
                    break;

                    case "execute":
                    {
                        ExecutionType executionType = LoadResourceExecution (node);
                        resourceType.Executions.Add (executionType.Name, executionType);
                    }
                    break;

                    default:
                        continue;
                }
            }

            return resourceType;
        }

        #endregion Save/Load
    }

    #endregion XMLResourceType

    #region FieldTypes

    #region FieldType

    public class FieldType
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:Field"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="type">The type.</param>
        /// <param name="help">The help.</param>
        /// <param name="minOccurs">The min occurs.</param>
        /// <param name="maxOccurs">The max occurs.</param>
        public FieldType(string type, string name, string help, int minOccurs, int maxOccurs)
        {
            Type = type;
            Name = name;
            Help = help;
            MinOccurs = minOccurs;
            MaxOccurs = maxOccurs;
        }

        public readonly string Type;
        public readonly string Name;
        public readonly string Help;
        public readonly int MinOccurs;
        public readonly int MaxOccurs;
    }

    #endregion Field

    #region TextFieldType

    public class TextFieldType : FieldType
    {
        public TextFieldType(string name, string help, int minOccurs, int maxOccurs)
            : base("text", name, help, minOccurs, maxOccurs)
        {
        }
    }

    #endregion TextField

    #region InternalRefFieldType

    public class InternalRefFieldType : FieldType
    {
        public InternalRefFieldType(string name, string help, int minOccurs, int maxOccurs)
            : base("internal_ref", name, help, minOccurs, maxOccurs)
        {
        }
    }

    #endregion InternalRefField

    #region ExternalRefFieldType

    public class ExternalRefFieldType : FieldType
    {
        public ExternalRefFieldType(string name, string help, int minOccurs, int maxOccurs, string mask)
            : base("external_ref", name, help, minOccurs, maxOccurs)
        {
            Mask = mask;
        }

        public string Mask;
    }

    #endregion InternalRefField

    #endregion FieldTypes

    #region ExecutionType

    public class ExecutionType
    {
        public ExecutionType (string name, string help, string bin, string parameters)
        {
            Name = name;
            Help = help;
            Bin = bin;
            Params = parameters;
        }

        public readonly string Name;
        public readonly string Help;
        public readonly string Bin;
        public readonly string Params;

        /// <summary>
        /// Gets a value indicating whether [create folder].
        /// </summary>
        /// <value><c>true</c> if [create folder]; otherwise, <c>false</c>.</value>
        public bool CreateFolder
        {
            get
            {
                return DynamicOutputFiles.Count > 0;
            }
        }
        
        // TODO: make this imutable
        public readonly List<string> DynamicOutputFiles = new List<string>();
    }

    #endregion ExecutionType
}
