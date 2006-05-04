using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    internal class Resources {

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

        #region Resource

        internal class Resource {

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

            #endregion

            #region IResource Members

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

            public string Notes {
                get {
                    return _notes;
                }
                set {
                    _notes = value;
                }
            }

            public Guid ID {
                get {
                    return _id;
                }
            }

            public CompositeResource Parent {
                get {
                    return _parent;
                }
                internal set {
                    _parent = value;
                }
            }

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

            virtual protected void WriteXMLElement(System.Xml.XmlTextWriter writer) {
                writer.WriteAttributeString("type", GetType().FullName);
                writer.WriteAttributeString("name", _name);
                writer.WriteElementString("family", (Parent != null)? Parent.QualifiedName : "");
                writer.WriteElementString("notes", Notes);
                writer.WriteElementString("id", ID.ToString());
            }

            #endregion
        }

        #endregion Resource

        #region FileResource

        internal class FileResource : Resource {

            #region Privates
            protected string _filename;
            #endregion Privates

            #region Constructor

            /// <summary>
            /// Initializes a new instance of the <see cref="T:FileResource"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            /// <param name="filename">The filename.</param>
            public FileResource(string name, string filename)
                : base(name) {
                _filename = filename;
            }

            public FileResource(System.Xml.XmlNode xmlnode)
                : base(xmlnode) {
                _filename = xmlnode["filename"].InnerText;
            }

            #endregion

            override protected void WriteXMLElement(System.Xml.XmlTextWriter writer) {
                base.WriteXMLElement(writer);
                writer.WriteElementString("filename", _filename);
            }

            #region IFileResource Members

            public string Filename {
                get {
                    return _filename;
                }
            }

            #endregion
        }

        #endregion FileResource

        #region SeqFileResource

        internal class SeqFileResource : FileResource {
            #region Constructors
            /// <summary>
            /// Initializes a new instance of the <see cref="T:SeqFileResource"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            /// <param name="filename">The filename.</param>
            public SeqFileResource(string name, string filename)
                : base(name, filename) {
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:SeqFileResource"/> class.
            /// </summary>
            /// <param name="xmlnode">The xmlnode.</param>
            public SeqFileResource(System.Xml.XmlNode xmlnode)
                : base(xmlnode) {
            }

            #endregion
        }

        #endregion SeqFileResource

        #region WgtFileResource

        public class WgtFileResource : FileResource {
            #region Constructors

            /// <summary>
            /// Initializes a new instance of the <see cref="T:WgtFileResource"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            /// <param name="filename">The filename.</param>
            public WgtFileResource(string name, string filename)
                : base(name, filename) {
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:WgtFileResource"/> class.
            /// </summary>
            /// <param name="xmlnode">The xmlnode.</param>
            public WgtFileResource(System.Xml.XmlNode xmlnode)
                : base(xmlnode) {
            }
            #endregion
        }

        #endregion WgtFileResource

        #region ResourceDictionary

        internal class ResourceDictionary : SortedDictionary<string, Resource> {
        }

        #endregion ResourceDictionary

        #region CompositeResource
        
        internal class CompositeResource : Resource, System.Collections.Generic.IDictionary <string, Resource> {

            #region Privates
            protected ResourceDictionary _resourceDicationary = new ResourceDictionary();
            #endregion

            #region Constructors

            /// <summary>
            /// Initializes a new instance of the <see cref="T:CompositeResource"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            public CompositeResource(string name)
                : base(name) {
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:CompositeResource"/> class.
            /// </summary>
            /// <param name="xmlnode">The xmlnode.</param>
            public CompositeResource(System.Xml.XmlNode xmlnode)
                : base(xmlnode) {
            }

            #endregion

            #region ICompositeResource Members

            /// <summary>
            /// Adds the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            public void Add(Resource resource) {
                System.Diagnostics.Debug.Assert(resource.Parent == null);

                resource.Parent = this;
                this._resourceDicationary.Add(resource.Name, resource);       
                OnResourceAdded(new ResourceEventArgs(this, resource));
            }

            public event ResourceEvent ResourceAdded;
            public event ResourceEvent ResourceRemoved;

            protected void OnResourceAdded(ResourceEventArgs args) {
                if (ResourceAdded != null) {
                    ResourceAdded(this, args);
                }
                if (Parent != null)
                    Parent.OnResourceAdded(args);
            }

            protected void OnResourceRemoved(ResourceEventArgs args) {
                if (ResourceRemoved != null) {
                    ResourceRemoved(this, args);
                }
                if (Parent != null)
                    Parent.OnResourceRemoved(args);
            }



            #endregion

            #region IDictionary<string,IResource> Members

            /// <summary>
            /// Adds an element with the provided key and value to the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <param name="key">The object to use as the key of the element to add.</param>
            /// <param name="value">The object to use as the value of the element to add.</param>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
            /// <exception cref="T:System.ArgumentException">An element with the same key already exists in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</exception>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            /// <exception cref="T:System.InvalidArgumentException">values's parent is not this object.</exception>
            public void Add(string key, Resource resource) {
                System.Diagnostics.Debug.Assert(key.Equals(resource.Name));
                Add(resource);
            }

            /// <summary>
            /// Determines whether the <see cref="T:System.Collections.Generic.IDictionary`2"></see> contains an element with the specified key.
            /// </summary>
            /// <param name="key">The key to locate in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</param>
            /// <returns>
            /// true if the <see cref="T:System.Collections.Generic.IDictionary`2"></see> contains an element with the key; otherwise, false.
            /// </returns>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            public bool ContainsKey(string key) {
                return _resourceDicationary.ContainsKey(key);
            }

            /// <summary>
            /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <value></value>
            /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
            public ICollection<string> Keys {
                get {
                    return this._resourceDicationary.Keys;
                }
            }

            /// <summary>
            /// Removes the element with the specified key from the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <param name="key">The key of the element to remove.</param>
            /// <returns>
            /// true if the element is successfully removed; otherwise, false.  This method also returns false if key was not found in the original <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </returns>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            public bool Remove(string key) {
                Resource resource = this [key];
                if (resource != null) {
                    System.Diagnostics.Debug.Assert(resource.Parent == this);
                    _resourceDicationary.Remove(key);
                    resource.Parent = null;
                    OnResourceRemoved(new ResourceEventArgs(this, resource));
                    return true;
                }
                return false;
            }

            /// <summary>
            /// Tries the get value.
            /// </summary>
            /// <param name="key">The key.</param>
            /// <param name="value">The value.</param>
            /// <returns></returns>
            public bool TryGetValue(string key, out Resource value) {
                return _resourceDicationary.TryGetValue(key, out value);
            }

            /// <summary>
            /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <value></value>
            /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
            public ICollection<Resource> Values {
                get {
                    return _resourceDicationary.Values;
                }
            }

            /// <summary>
            /// Gets or sets the <see cref="T:IResource"/> with the specified key.
            /// </summary>
            /// <value></value>
            public Resource this[string key] {
                get {
                    Resource resource = null;
                    _resourceDicationary.TryGetValue (key, out resource);
                    return resource;
                }
                set {
                    throw new Exception("The method or operation is not implemented.");
                }
            }

            #endregion

            #region ICollection<KeyValuePair<string,IResource>> Members

            public void Add(KeyValuePair<string, Resource> item) {
                Add(item.Key, item.Value);
            }

            public void Clear() {
                throw new Exception("The method or operation is not implemented.");
            }

            public bool Contains(KeyValuePair<string, Resource> item) {
                throw new Exception("The method or operation is not implemented.");
            }

            public void CopyTo(KeyValuePair<string, Resource>[] array, int arrayIndex) {
                _resourceDicationary.CopyTo(array, arrayIndex);
            }

            public int Count {
                get {
                    return _resourceDicationary.Count;
                }
            }

            /// <summary>
            /// Gets a value indicating whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.
            /// </summary>
            /// <value></value>
            /// <returns>true if the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only; otherwise, false.</returns>
            public bool IsReadOnly {
                get {
                    return false;
                }
            }

            public bool Remove(KeyValuePair<string, Resource> item) {
                throw new Exception("The method or operation is not implemented.");
            }

            #endregion

            #region IEnumerable<KeyValuePair<string,IResource>> Members

            public IEnumerator<KeyValuePair<string, Resource>> GetEnumerator() {
                return _resourceDicationary.GetEnumerator();
            }

            #endregion

            #region IEnumerable Members

            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
                return _resourceDicationary.GetEnumerator();
            }

            #endregion

            /// <summary>
            /// Adds the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            /// <param name="family">The family.</param>
            public void Add(Resource resource, string absoluteFamily) {
                string qualifiedName = this.QualifiedName;
                System.Diagnostics.Debug.Assert(absoluteFamily.StartsWith(qualifiedName));
                /// remove our qualified name, leaving only the relative path
                string[] relativeFamily =
                    absoluteFamily.Substring(qualifiedName.Length).Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries);

                Add(resource, relativeFamily, 0);
            }

            /// <summary>
            /// Adds the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            /// <param name="relativeFamily">The relative family.</param>
            /// <param name="depth">The depth.</param>
            private void Add(Resource resource, string[] relativeFamily, int depth) {
                if (relativeFamily.Length == depth) {
                    Add(resource);
                }
                else {
                    string childName = relativeFamily [depth];
                    CompositeResource child = 
                        (CompositeResource) this [childName];
                    if (child == null) {
                        child = new CompositeResource(childName);
                        Add(child);
                    }
                    child.Add(resource, relativeFamily, depth + 1);
                }
            }
        }
         

        #endregion CompositeResource

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
