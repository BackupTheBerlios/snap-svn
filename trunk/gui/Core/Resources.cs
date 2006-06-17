using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP
{
    namespace Resources
    {
        #region Events

        /// <summary>
        /// 
        /// </summary>
        public class ResourceEventArgs : System.EventArgs
        {
            public ResourceEventArgs(Resource parent, Resource resource)
            {
                Parent = parent;
                Resource = resource;
            }

            public readonly Resource Parent;
            public readonly Resource Resource;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        public delegate void ResourceEvent(object sender, ResourceEventArgs args);

        #endregion Events

        #region FieldValue

        public interface IScriptableValue
        {
            /// <summary>
            /// Gets the <see cref="T:FieldValue"/> with the specified variable name.
            /// </summary>
            /// <value></value>
            IScriptableValue this[string variableName]
            {
                get;
            }
        }

        public class InternalRefValue : IScriptableValue
        {
            public readonly string ResourceName;

            /// <summary>
            /// Initializes a new instance of the <see cref="T:InternalRefScriptableValue"/> class.
            /// </summary>
            /// <param name="resourceName">Name of the resource.</param>
            public InternalRefValue(string resourceName)
            {
                ResourceName = resourceName;
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
            }

            /// <summary>
            /// Implicit operators the specified value.
            /// </summary>
            /// <param name="value">The value.</param>
            /// <returns></returns>
            public static explicit operator SNAP.Resources.Resource (InternalRefValue value)
            {
                return value.MyResource;
            }

            /// <summary>
            /// Gets the <see cref="T:FieldValue"/> with the specified variable name.
            /// </summary>
            /// <value></value>
            public IScriptableValue this[string variableName]
            {
                get
                {
                    return ((Resource) this)[variableName];
                }
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
        }

        public class ExternalRefValue : IScriptableValue
        {
            public readonly string Path;

            /// <summary>
            /// Initializes a new instance of the <see cref="T:ExternalRefValue"/> class.
            /// </summary>
            /// <param name="path">The path.</param>
            public ExternalRefValue(string path)
            {
                Path = path;
            }

            /// <summary>
            /// Gets the <see cref="T:FieldValue"/> with the specified variable name.
            /// </summary>
            /// <value></value>
            public IScriptableValue this[string variableName]
            {
                get
                {
                    switch (variableName)
                    {
                        case "Folder":
                            return new ExternalRefValue (System.IO.Path.GetDirectoryName (Path));

                        default:
                            throw new System.ArgumentException ("The variable " + variableName + " is invalid for an ExternalRef Field");
                    }
                }
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
        }

        public class TextValue : IScriptableValue
        {
            public readonly string Text;

            /// <summary>
            /// Initializes a new instance of the <see cref="T:TextFieldValue"/> class.
            /// </summary>
            /// <param name="text">The text.</param>
            public TextValue(string text)
            {
                Text = text;
            }

            /// <summary>
            /// Gets the <see cref="T:FieldValue"/> with the specified variable name.
            /// </summary>
            /// <value></value>
            public IScriptableValue this[string variableName]
            {
                get
                {
                    throw new System.ArgumentException ("The variable " + variableName + " is invalid for a Text Field");
                }
            }

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

        }
 
        public class FieldValueList
        {
            public FieldValueList(FieldType type)
            {
                Type = type;
            }

            public readonly FieldType Type;
            public readonly List<IScriptableValue> Values = new List<IScriptableValue>();
        }



        #endregion FieldValue

        #region Resource

        #region ResourceChildren
        
        public class ResourceChildren
        {
            #region Privates
            private SortedDictionary<string, Resource> _resourceDictionary
            {
                get
                {
                    return this.Resource._resourceDictionary;
                }
            }
            private void OnResourceRemoved (ResourceEventArgs args)
            {
                this.Resource.OnResourceRemoved (args);
            }
            private void OnResourceAdded(ResourceEventArgs args)
            {
                this.Resource.OnResourceAdded(args);
            }

            public ResourceChildren(Resource resource)
            {
                this.Resource = resource;
            }
            #endregion Privates

            public readonly Resource Resource;

            /// <summary>
            /// Removes the element with the specified key from the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <param name="key">The key of the element to remove.</param>
            /// <returns>
            /// true if the element is successfully removed; otherwise, false.  This method also returns false if key was not found in the original <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </returns>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            public bool Remove(string key)
            {
                Resource resource = this[key];
                if (resource != null)
                {
                    System.Diagnostics.Debug.Assert(resource.Parent == this.Resource);
                    _resourceDictionary.Remove(key);
                    resource.Parent = null;
                    OnResourceRemoved(new ResourceEventArgs(Resource, resource));
                    return true;
                }
                return false;
            }

            /// <summary>
            /// Adds the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            public void Add(Resource resource)
            {
                System.Diagnostics.Debug.Assert(resource.Parent == null);
                System.Diagnostics.Debug.Assert(!this._resourceDictionary.ContainsValue(resource));

                resource.Parent = Resource;
                this._resourceDictionary.Add(resource.Name, resource);
                OnResourceAdded(new ResourceEventArgs(Resource, resource));
            }

            /// <summary>
            /// Gets or sets the <see cref="T:IResource"/> with the specified key.
            /// </summary>
            /// <value></value>
            public Resource this[string key]
            {
                get
                {
                    Resource resource = null;
                    _resourceDictionary.TryGetValue(key, out resource);
                    return resource;
                }
                set
                {
                    throw new Exception("The method or operation is not implemented.");
                }
            }

            /// <summary>
            /// Gets the count.
            /// </summary>
            /// <value>The count.</value>
            public int Count
            {
                get
                {
                    return _resourceDictionary.Count;
                }
            }

            /// <summary>
            /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <value></value>
            /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
            public ICollection<Resource> Values
            {
                get
                {
                    return _resourceDictionary.Values;
                }
            }
        }

        #endregion ResourceChildren

        public class Resource : IScriptableValue
        {
            #region Constructors

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Resource"/> class.
            /// </summary>
            /// <param name="guid">The GUID.</param>
            /// <param name="type">The type.</param>
            /// <param name="name">The name.</param>
            public Resource(Guid guid, ResourceType type, string name)
            {
                _id  = guid;
                ResourceType = type;
                _name = name;
            }

            #endregion

            #region Privates

            protected Resource _parent;
            protected string _name;
            protected readonly System.Guid _id;
            internal readonly SortedDictionary<string, Resource> _resourceDictionary = new SortedDictionary<string, Resource>();
            public readonly SortedDictionary<string, FieldValueList> Fields = new SortedDictionary<string, FieldValueList> ();

            #endregion

            #region Properties

            public readonly ResourceType ResourceType;

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
                set
                {
                    if (_name.Equals(value))
                        return;

                    Resource parent = Parent;
                    RemoveFromParent ();
                    _name = value;
                    if (parent != null)
                        parent.Children.Add(this);
                }
            }

            /// <summary>
            /// Gets the ID.
            /// </summary>
            /// <value>The ID.</value>
            public Guid ID
            {
                get
                {
                    return _id;
                }
            }

            /// <summary>
            /// Gets or sets the parent.
            /// </summary>
            /// <value>The parent.</value>
            public Resource Parent
            {
                get
                {
                    return _parent;
                }
                internal set
                {
                    _parent = value;
                }
            }

            /// <summary>
            /// Gets the name of the qualified.
            /// </summary>
            /// <value>The name of the qualified.</value>
            public string QualifiedName
            {
                get
                {
                    if (_parent == null)
                        return Name;
                    else
                        return _parent.QualifiedName + "." + Name;
                }
            }

            /// <summary>
            /// Gets the children.
            /// </summary>
            /// <value>The children.</value>
            public ResourceChildren Children
            {
                get
                {
                    return new ResourceChildren(this);
                }
            }

            #endregion Properties

            #region Events

            public event ResourceEvent ResourceAdded;
            public event ResourceEvent ResourceRemoved;

            internal void OnResourceAdded(ResourceEventArgs args)
            {
                if (ResourceAdded != null)
                {
                    ResourceAdded(this, args);
                }
                if (Parent != null)
                    Parent.OnResourceAdded(args);
            }

            internal void OnResourceRemoved(ResourceEventArgs args)
            {
                if (ResourceRemoved != null)
                {
                    ResourceRemoved(this, args);
                }
                if (Parent != null)
                    Parent.OnResourceRemoved(args);
            }

            #endregion Events

            #region Methods

            #region Serialization
            /// <summary>
            /// Writes the XML.
            /// </summary>
            /// <param name="writer">The writer.</param>
            public void WriteXML(System.Xml.XmlTextWriter writer)
            {
                writer.WriteStartElement("resource");
                WriteXMLElement(writer);
                writer.WriteEndElement();
            }

            /// <summary>
            /// Writes the XML element.
            /// </summary>
            /// <param name="writer">The writer.</param>
            virtual protected void WriteXMLElement(System.Xml.XmlTextWriter writer)
            {
                writer.WriteAttributeString("type", this.ResourceType.Name);
                writer.WriteAttributeString("name", _name);
                writer.WriteAttributeString("id", ID.ToString());
                writer.WriteElementString("family", (Parent != null) ? Parent.QualifiedName : "");

                foreach (FieldValueList fieldValues in this.Fields.Values)
                {
                    foreach (object v in fieldValues.Values)
                    {
                        writer.WriteStartElement("field");
                        writer.WriteAttributeString ("name", fieldValues.Type.Name);
                        writer.WriteValue (v.ToString ());
                        writer.WriteEndElement ();
                    }
                }
            }

            #endregion Serialization

            #region Add/Remove

            /// <summary>
            /// Removes the node from it's parent
            /// </summary>
            public void RemoveFromParent()
            {
                if (Parent != null)
                    Parent.Children.Remove(Name);
            }


/*
            /// <summary>
            /// Adds the specified resource.
            /// </summary>
            /// <param name="resource">The resource.</param>
            /// <param name="family">The family.</param>
            public void Add(Resource resource, string absoluteFamily)
            {
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
            private void Add(Resource resource, string[] relativeFamily, int depth)
            {
                if (relativeFamily.Length == depth)
                {
                    Add(resource);
                }
                else
                {
                    string childName = relativeFamily[depth];
                    Resource child = this[childName];
                    if (child == null)
                    {
                        child = new Resource(childName);
                        Add(child);
                    }
                    child.Add(resource, relativeFamily, depth + 1);
                }
            }
 */

            #endregion Add/Remove

            #region IDictionary<string,IResource> Members
            /*
            
            /// <summary>
            /// Adds an element with the provided key and value to the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <param name="key">The object to use as the key of the element to add.</param>
            /// <param name="value">The object to use as the value of the element to add.</param>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
            /// <exception cref="T:System.ArgumentException">An element with the same key already exists in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</exception>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            /// <exception cref="T:System.InvalidArgumentException">values's parent is not this object.</exception>
            public void Add(string key, Resource resource)
            {
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
            public bool ContainsKey(string key)
            {
                return _resourceDictionary.ContainsKey(key);
            }

            /// <summary>
            /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <value></value>
            /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
            public ICollection<string> Keys
            {
                get
                {
                    return this._resourceDictionary.Keys;
                }
            }
             */


            /*

            /// <summary>
            /// Tries the get value.
            /// </summary>
            /// <param name="key">The key.</param>
            /// <param name="value">The value.</param>
            /// <returns></returns>
            public bool TryGetValue(string key, out Resource value)
            {
                return _resourceDictionary.TryGetValue(key, out value);
            }

            /// <summary>
            /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <value></value>
            /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
            public ICollection<Resource> Values
            {
                get
                {
                    return _resourceDictionary.Values;
                }
            }


            */
            #endregion

            #region ICollection<KeyValuePair<string,IResource>> Members
            /*
            
            public void Add(KeyValuePair<string, Resource> item)
            {
                Add(item.Key, item.Value);
            }

            public void Clear()
            {
                throw new Exception("The method or operation is not implemented.");
            }

            public bool Contains(KeyValuePair<string, Resource> item)
            {
                throw new Exception("The method or operation is not implemented.");
            }

            public void CopyTo(KeyValuePair<string, Resource>[] array, int arrayIndex)
            {
                _resourceDictionary.CopyTo(array, arrayIndex);
            }

            public int Count
            {
                get
                {
                    return _resourceDictionary.Count;
                }
            }

            /// <summary>
            /// Gets a value indicating whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.
            /// </summary>
            /// <value></value>
            /// <returns>true if the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only; otherwise, false.</returns>
            public bool IsReadOnly
            {
                get
                {
                    return false;
                }
            }

            public bool Remove(KeyValuePair<string, Resource> item)
            {
                throw new Exception("The method or operation is not implemented.");
            }
            */
            #endregion

            #region IEnumerable<KeyValuePair<string,IResource>> Members
            /*

            public IEnumerator<KeyValuePair<string, Resource>> GetEnumerator()
            {
                return _resourceDictionary.GetEnumerator();
            }
            */
            #endregion

            #endregion Methods

            #region IScriptableValue Members

            public IScriptableValue this[string variableName]
            {
                get
                {
                    if (Fields.ContainsKey(variableName))
                        return Fields[variableName].Values[0];
                    else
                    {
                        switch (variableName)
                        {
                            case "Name":
                                return new TextValue (this.Name);

                            case "ID":
                                return new TextValue (this.ID.ToString());

                            case "Family":
                                return new InternalRefValue (this.Parent.QualifiedName);

                            case "Folder":
                                // TODO: return the folder of the resource
                                throw new System.NotImplementedException();

                            default:
                                // TODO: give a more thoughtful error message
                                throw new System.ArgumentException ("the variable " + variableName + " is invalid for a Resource");
                        }
                    }
                }
            }

            #endregion
        }

        #endregion Resource

        #region DB

        public class DB
        {
            #region Privates

            private SortedDictionary<string, ResourceType> _resourceTypes;
            private SortedDictionary<string, Resource> _resourceList = new SortedDictionary<string, Resource>();

            #endregion Privates

            #region Properties

            public Resource Root = null;

            /// <summary>
            /// Gets the resource types.
            /// </summary>
            /// <value>The resource types.</value>
            public IDictionary<string, ResourceType> ResourceTypes
            {
                get
                {
                    return _resourceTypes;
                }
            }

            #endregion Properties

            #region Methods

            /// <summary>
            /// Loads the resources.
            /// </summary>
            /// <param name="root">The root.</param>
            /// <param name="filename">The filename.</param>
            public void LoadAdditionalResources(Resource root, string filename)
            {
                LoadAdditionalResources(root, filename, false);
            }

            private void LoadAdditionalResources(string filename, bool addToList)
            {
                LoadAdditionalResources(null, filename, addToList);
            }
            private void LoadAdditionalResources(Resource root, string filename, bool addToList)
            {
                /// load the XML file that contains all the resources
                System.Xml.XmlDocument document = new System.Xml.XmlDocument();
                document.Load(filename);
                System.Xml.XmlNode rootNode = document.ChildNodes[1];

                /// 
                foreach (System.Xml.XmlNode node in rootNode.ChildNodes)
                {
                    try
                    {
                        if (node.Name == "resource")
                        {
                            Resource resource = LoadResource(node, root);
                            if (addToList)
                                _resourceList.Add(resource.QualifiedName, resource);
                        }
                    }
                    catch (Exception x)
                    {
                        SNAP.Controller.ShowException(x);
                    }
                }
            }

            /// <summary>
            /// Loads the resources.
            /// </summary>
            public void LoadResources()
            {
                /// clear old DB and load resource types
                _resourceList.Clear();
                _resourceTypes = SNAP.Resources.ResourceType.LoadTypes(
                    Controller.ResourceTypesFile);

                /// create the root resource
                Root = new Resource(new Guid (), _resourceTypes ["Family"], "general");
                _resourceList.Add (Root.QualifiedName, Root);

                /// load the actual resources
                LoadAdditionalResources(Controller.ResourcesFile, true);

                ///
                Root.ResourceAdded += new ResourceEvent(Root_ResourceAdded);
                Root.ResourceRemoved += new ResourceEvent(Root_ResourceRemoved);
            }

            /// <summary>
            /// Adds the resource.
            /// </summary>
            /// <param name="qualifiedParentName">The qualified name of the parent.</param>
            /// <param name="resource">The resource.</param>
            public void AddResource(string qualifiedParentName, Resource resource)
            {
                AddResource (_resourceList [qualifiedParentName], resource);
            }

            /// <summary>
            /// Adds the resource.
            /// </summary>
            /// <param name="parent">The parent.</param>
            /// <param name="resource">The resource.</param>
            public void AddResource(Resource parent, Resource resource)
            {
                System.Diagnostics.Debug.Assert (resource.Parent == null);
                parent.Children.Add(resource);

                /// no need to add to the _resourceList because the adding to the parent
                /// does the job for us
                //_resourceList.Add (resource.QualifiedName, resource);
            }

            /// <summary>
            /// Finds the resource.
            /// </summary>
            /// <param name="qualifiedName">Qualified Name of the resource.</param>
            /// <returns></returns>
            public Resource FindResource(string qualifiedName)
            {
                if (this._resourceList.ContainsKey(qualifiedName))
                    return this._resourceList[qualifiedName];
                return null;
            }

            #endregion Methods

            #region Implementation

            /// <summary>
            /// Handles the ResourceAdded event of the Root control.
            /// </summary>
            /// <param name="sender">The source of the event.</param>
            /// <param name="args">The <see cref="T:SNAP.Resources.CompositeResourceEventArgs"/> instance containing the event data.</param>
            void Root_ResourceAdded(object sender, Resources.ResourceEventArgs args)
            {
                _resourceList.Add(args.Resource.QualifiedName, args.Resource);
                SaveResources();
            }

            private Resource LoadResource(System.Xml.XmlNode node, Resource parent)
            {
                System.Diagnostics.Debug.Assert(node.Name == "resource");

                /// get resource type
                string resourceTypeName = node.Attributes["type"].Value;
                SNAP.Resources.ResourceType resourceType = _resourceTypes[resourceTypeName];

                /// get resource name
                string resourceName = node.Attributes["name"].Value;

                /// get resource id
                /// if the id is not available (for instance when importing an externallay generated resource)
                /// generate a new one instead
                Guid guid = (node.Attributes["id"] != null) ?
                    (new Guid(node.Attributes["id"].Value)) : (Guid.NewGuid());

                /// create the new resource
                Resource resource = new Resource(guid, resourceType, resourceName);

                /// add field values
                foreach (System.Xml.XmlNode fieldNode in node.SelectNodes("field"))
                {
                    string fieldName = fieldNode.Attributes["name"].Value;
                    FieldType fieldType = resource.ResourceType.Fields[fieldName];
                    FieldValueList fieldValue = null;
                    if (!resource.Fields.ContainsKey(fieldName))
                    {
                        fieldValue = new FieldValueList(fieldType);
                        resource.Fields.Add(fieldName, fieldValue);
                    }
                    else
                    {
                        fieldValue = resource.Fields[fieldName];
                    }

                    IScriptableValue value = null;
                    switch (fieldType.Type)
                    {
                        case "internal_ref":
                            value = new InternalRefValue (fieldNode.InnerText);
                            break;

                        case "external_ref":
                            value = new ExternalRefValue (fieldNode.InnerText);
                            break;

                        case "text":
                            value = new TextValue (fieldNode.InnerText);
                            break;

                        default:
                            System.Diagnostics.Debug.Fail (fieldType.Type + " is not a recognized field type");
                            break;
                    }

                    fieldValue.Values.Add(value);
                }

                /// add this node to it's parent
                if (parent == null)
                {
                    string family = node["family"].InnerText;
                    parent = _resourceList[family];
                }
                parent.Children.Add(resource);
                return resource;
            }

            private Resource LoadResource(System.Xml.XmlNode node)
            {
                return LoadResource(node, null);
            }
            void Root_ResourceRemoved(object sender, Resources.ResourceEventArgs args)
            {
                _resourceList.Remove(args.Resource.QualifiedName);
                SaveResources();
            }

            public void SaveResources()
            {
                using (System.Xml.XmlTextWriter writer = new System.Xml.XmlTextWriter(Controller.ResourcesFile, Encoding.UTF8))
                {
                    writer.Formatting = System.Xml.Formatting.Indented;
                    writer.WriteStartDocument();
                    writer.WriteStartElement("resources");

                    foreach (Resource resource in _resourceList.Values)
                    {
                        if (resource != Root)
                            resource.WriteXML(writer);
                    }

                    writer.WriteEndElement();
                    writer.WriteEndDocument();

                    writer.Flush();
                    writer.Close();
                }
            }

            #endregion Implementation
        }

        #endregion DB
    }
}
