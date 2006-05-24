using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    namespace Resources {

        public class ReferenceAttribute : System.Attribute {
            public ReferenceAttribute (string shortName, string longDescription)
            {
            }

            public readonly string FieldName;
            public readonly string FieldDescription;
        }
        
        public class InternalReferenceAttribute : ReferenceAttribute {
            public InternalReferenceAttribute (string shortName, string longDescription)
                : base (shortName, longDescription)
            {
            }
        }

        public class ExternalReferenceAttribute : ReferenceAttribute {
            public ExternalReferenceAttribute (string shortName, string longDescription)
                : base (shortName, longDescription)
            {
            }
        }

        class Miew
        {
            //[SNAP.Resources.InteralReference ("short name", "description")]
            string Family;

            //[SNAP.Resources.ExternalReference]
            string File;
        }

        #region Resource

        internal abstract class Resource {

            #region Privates

            protected CompositeResource _parent;
            protected string _name;
            protected string _notes;
            protected System.Guid _id;

            #endregion Privates

            #region Constructors

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Resource"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            public Resource(string name) {
                _name = name;
                _id = Guid.NewGuid();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Resource"/> class.
            /// </summary>
            /// <param name="id">The id.</param>
            /// <param name="name">The name.</param>
            public Resource(System.Guid id, string name) {
                _name = name;
                _id = id;
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Resource"/> class.
            /// </summary>
            /// <param name="xmlnode">The xmlnode.</param>
            public Resource(System.Xml.XmlNode xmlnode) {
                _name = xmlnode.Attributes["name"].Value;
                _id = new Guid(xmlnode["id"].InnerText);
                _notes = xmlnode["notes"].InnerText;
            }

            public Resource()
            {
            }

            #endregion

            #region IResource Members

            /// <summary>
            /// Gets or sets the name.
            /// </summary>
            /// <value>The name.</value>
            public string Name {
                get {
                    return _name;
                }
                set {
                    CompositeResource parent  = Parent;
                    Remove ();
                    _name = value;
                    if (parent != null)
                        parent.Add(this);
                }
            }

            /// <summary>
            /// Gets or sets the notes.
            /// </summary>
            /// <value>The notes.</value>
            public string Notes {
                get {
                    return _notes;
                }
                set {
                    _notes = value;
                }
            }

            /// <summary>
            /// Gets the ID.
            /// </summary>
            /// <value>The ID.</value>
            public Guid ID {
                get {
                    return _id;
                }
            }

            /// <summary>
            /// Gets or sets the parent.
            /// </summary>
            /// <value>The parent.</value>
            public CompositeResource Parent {
                get {
                    return _parent;
                }
                internal set {
                    _parent = value;
                }
            }

            /// <summary>
            /// Gets the name of the qualified.
            /// </summary>
            /// <value>The name of the qualified.</value>
            public string QualifiedName {
                get {
                    if (_parent == null)
                        return Name;
                    else
                        return _parent.QualifiedName + "." + Name;
                }
            }

            /// <summary>
            /// Removes the node from it's parent
            /// </summary>
            public void Remove() {
                if (Parent != null) 
                    Parent.Remove(Name);
            }

            /// <summary>
            /// Writes the XML.
            /// </summary>
            /// <param name="writer">The writer.</param>
            public void WriteXML(System.Xml.XmlTextWriter writer) {
                writer.WriteStartElement("resource");
                WriteXMLElement(writer);
                writer.WriteEndElement();
            }

            /// <summary>
            /// Writes the XML element.
            /// </summary>
            /// <param name="writer">The writer.</param>
            virtual protected void WriteXMLElement(System.Xml.XmlTextWriter writer) {
                writer.WriteAttributeString("type", GetType().FullName);
                writer.WriteAttributeString("name", _name);
                writer.WriteElementString("family", (Parent != null)? Parent.QualifiedName : "");
                writer.WriteElementString("notes", Notes);
                writer.WriteElementString("id", ID.ToString());
            }

            public abstract string Typename {
                get;
            }

            /// <summary>
            /// throws an exception if the resource is not properly initialized
            /// TODO: perhaps provide a more structured way to do this
            /// </summary>
            public abstract void Validate ();

            #endregion
        }

        #endregion Resource

        #region Events

        /// <summary>
        /// 
        /// </summary>
        internal class ResourceEventArgs : System.EventArgs {
            public ResourceEventArgs(CompositeResource parent, Resource resource) {
                Parent = parent;
                Resource = resource;
            }

            public readonly CompositeResource Parent;
            public readonly Resource Resource;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        internal delegate void ResourceEvent(object sender, ResourceEventArgs args);

        #endregion Events

        internal class DB {

            /// <summary>
            /// Handles the ResourceAdded event of the Root control.
            /// </summary>
            /// <param name="sender">The source of the event.</param>
            /// <param name="args">The <see cref="T:SNAP.Resources.CompositeResourceEventArgs"/> instance containing the event data.</param>
            void Root_ResourceAdded(object sender, Resources.ResourceEventArgs args) {
                _resourceList.Add(args.Resource);
                SaveResources();
            }

            /// <summary>
            /// represents a list of resources
            /// </summary>
            public class ResourceList : System.Collections.Generic.List<Resource> {
            }

            private ResourceList _resourceList = new ResourceList();
            public CompositeResource Root = null;


            internal void LoadResources() {
                Root = new CompositeResource("general");

                System.Xml.XmlDocument document = new System.Xml.XmlDocument();
                document.Load(Program.CurrentOptions.ResourcesFile);
                System.Xml.XmlNode rootNode = document.ChildNodes[1];
                foreach (System.Xml.XmlNode node in rootNode.ChildNodes) {
                    try {
                        if (node.Name == "resource") {
                            string resourceTypeName = node.Attributes["type"].Value;
                            System.Type resourceType = System.Type.GetType(resourceTypeName);
                            if (resourceType == null) {
                            }

                            /// every resource-type must have a constructor which receives as a single parameter = an XMLNode
                            System.Reflection.ConstructorInfo ctor = resourceType.GetConstructor(new Type[] { typeof(System.Xml.XmlNode) });
                            Resource resource = (Resource)ctor.Invoke(new object[] { node });

                            string family = node["family"].InnerText;
                            AddResource(resource, family);
                            _resourceList.Add(resource);
                        }
                    }
                    catch (Exception x) {
                        Util.ShowException(x);
                    }
                }

                Root.ResourceAdded += new ResourceEvent(Root_ResourceAdded);
                Root.ResourceRemoved += new ResourceEvent(Root_ResourceRemoved);
            }

            void Root_ResourceRemoved(object sender, Resources.ResourceEventArgs args) {
                _resourceList.Remove(args.Resource);
                SaveResources();
            }

            internal void SaveResources() {
                using (System.Xml.XmlTextWriter writer = new System.Xml.XmlTextWriter(Program.CurrentOptions.ResourcesFile, Encoding.UTF8)) {
                    writer.Formatting = System.Xml.Formatting.Indented;
                    writer.WriteStartDocument();
                    writer.WriteStartElement("resources");

                    foreach (Resource resource in _resourceList) {
                        resource.WriteXML(writer);
                    }

                    writer.WriteEndElement();
                    writer.WriteEndDocument();

                    writer.Flush();
                    writer.Close();
                }
            }

            private void AddResource(Resource resource, string family) {
                Root.Add(resource, family);
            }
        }
    }
}

#region obsolete

#if false

#region IResource
/*
        internal interface Resource {
            /// <summary>
            /// Gets or sets the name.
            /// </summary>
            /// <value>The name.</value>
            string Name {
                get;
                set;
            }

            /// <summary>
            /// Gets or sets the notes.
            /// </summary>
            /// <value>The notes.</value>
            string Notes {
                get;
                set;
            }
            /// <summary>
            /// Gets the ID.
            /// </summary>
            /// <value>The ID.</value>
            System.Guid ID {
                get;
            }

            /// <summary>
            /// Gets the parent.
            /// </summary>
            /// <value>The parent.</value>
            ICompositeResource Parent {
                get;
            }

            /// <summary>
            /// Gets the name of the qualified.
            /// </summary>
            /// <value>The name of the qualified.</value>
            string QualifiedName {
                get;
            }

            /// <summary>
            /// Writes the XML.
            /// </summary>
            /// <param name="writer">The writer.</param>
            void WriteXML(System.Xml.XmlTextWriter writer);
        }
         */

#endregion IResource

#region IFileResource
/*
        internal interface IFileResource {
            string Filename {
                get;
            }
        }
         */

#endregion IFileResource

#region ICompositeResource


/*
/// <summary>
/// 
/// </summary>
internal interface ICompositeResource : Resource, System.Collections.Generic.IDictionary<string, Resource> {
    /// <summary>
    /// Adds the specified resource.
    /// </summary>
    /// <param name="resource">The resource.</param>
    void Add(Resource resource);

    /// <summary>
    /// Raised when a resource is added.
    /// events are also propagated up the tree
    /// </summary>
    event CompositeResourceEvent ResourceAdded;
}
 */

#endregion ICompositeResource

#endif

#endregion obsolete