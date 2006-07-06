using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP
{
    namespace Resources
    {
        #region Resource

        #region ResourceChildren
        
        /*
        public class ResourceChildren : IDictionary <string, Resource>
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
            
            #region Useful interface

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

            #endregion Useful interface

            #region IDictionary<string,Resource> Members

            /// <summary>
            /// Adds an element with the provided key and value to the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
            /// </summary>
            /// <param name="key">The object to use as the key of the element to add.</param>
            /// <param name="value">The object to use as the value of the element to add.</param>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
            /// <exception cref="T:System.ArgumentException">An element with the same key already exists in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</exception>
            /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
            void IDictionary<string,Resource>.Add(string key, Resource value)
            {
                System.Diagnostics.Trace.Assert(value.Name.Equals(key));
                Add(value);
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
                get {
                    return _resourceDictionary.Keys;
                }
            }

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

            #endregion

            #region ICollection<KeyValuePair<string,Resource>> Members

            /// <summary>
            /// Adds an item to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
            /// </summary>
            /// <param name="item">The object to add to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.</exception>
            void ICollection<KeyValuePair<string,Resource>>.Add(KeyValuePair<string, Resource> item)
            {
                (this as IDictionary<string,Resource>).Add(item.Key, item.Value);
            }

            void ICollection<KeyValuePair<string,Resource>>.Clear()
            {
                throw new Exception("The method or operation is not implemented.");
            }

            /// <summary>
            /// Determines whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> contains a specific value.
            /// </summary>
            /// <param name="item">The object to locate in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
            /// <returns>
            /// true if item is found in the <see cref="T:System.Collections.Generic.ICollection`1"></see>; otherwise, false.
            /// </returns>
            bool ICollection<KeyValuePair<string, Resource>>.Contains(KeyValuePair<string, Resource> item)
            {
                throw new Exception("The method or operation is not implemented.");
            }

            /// <summary>
            /// Copies the elements of the <see cref="T:System.Collections.Generic.ICollection`1"></see> to an <see cref="T:System.Array"></see>, starting at a particular <see cref="T:System.Array"></see> index.
            /// </summary>
            /// <param name="array">The one-dimensional <see cref="T:System.Array"></see> that is the destination of the elements copied from <see cref="T:System.Collections.Generic.ICollection`1"></see>. The <see cref="T:System.Array"></see> must have zero-based indexing.</param>
            /// <param name="arrayIndex">The zero-based index in array at which copying begins.</param>
            /// <exception cref="T:System.ArgumentOutOfRangeException">arrayIndex is less than 0.</exception>
            /// <exception cref="T:System.ArgumentNullException">array is null.</exception>
            /// <exception cref="T:System.ArgumentException">array is multidimensional.-or-arrayIndex is equal to or greater than the length of array.-or-The number of elements in the source <see cref="T:System.Collections.Generic.ICollection`1"></see> is greater than the available space from arrayIndex to the end of the destination array.-or-Type T cannot be cast automatically to the type of the destination array.</exception>
            void ICollection<KeyValuePair<string, Resource>>.CopyTo(KeyValuePair<string, Resource>[] array, int arrayIndex)
            {
                _resourceDictionary.CopyTo (array, arrayIndex);
            }

            /// <summary>
            /// Gets a value indicating whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.
            /// </summary>
            /// <value></value>
            /// <returns>true if the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only; otherwise, false.</returns>
            bool ICollection<KeyValuePair<string, Resource>>.IsReadOnly
            {
                get
                {
                    throw new Exception("The method or operation is not implemented.");
                }
            }

            /// <summary>
            /// Removes the first occurrence of a specific object from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
            /// </summary>
            /// <param name="item">The object to remove from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
            /// <returns>
            /// true if item was successfully removed from the <see cref="T:System.Collections.Generic.ICollection`1"></see>; otherwise, false. This method also returns false if item is not found in the original <see cref="T:System.Collections.Generic.ICollection`1"></see>.
            /// </returns>
            /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.</exception>
            bool ICollection<KeyValuePair<string, Resource>>.Remove(KeyValuePair<string, Resource> item)
            {
                throw new Exception("The method or operation is not implemented.");
            }

            #endregion

            #region IEnumerable<KeyValuePair<string,Resource>> Members

            /// <summary>
            /// Returns an enumerator that iterates through the collection.
            /// </summary>
            /// <returns>
            /// A <see cref="T:System.Collections.Generic.IEnumerator`1"></see> that can be used to iterate through the collection.
            /// </returns>
            public IEnumerator<KeyValuePair<string, Resource>> GetEnumerator()
            {
                return _resourceDictionary.GetEnumerator();
            }

            #endregion

            #region IEnumerable Members

            /// <summary>
            /// Returns an enumerator that iterates through a collection.
            /// </summary>
            /// <returns>
            /// An <see cref="T:System.Collections.IEnumerator"></see> object that can be used to iterate through the collection.
            /// </returns>
            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
            {
                return _resourceDictionary.GetEnumerator();
            }

            #endregion
        }

        */

        #endregion ResourceChildren

        public class ResourceChildren : SNAP.Util.ChildDictionary<string, Resource, Resource>
        {
            public ResourceChildren(Resource parent)
                : base (parent)
            {
            }
            public void Add(Resource resource)
            {
                Add(resource.Name, resource);
            }

            protected override void OnChildAdded(Resource child)
            {
                base.OnChildAdded(child);
                if (MyParent.MyParent != null)
                    MyParent.MyParent.Children.OnChildAdded(child);
            }

            protected override void OnChildRemoved(Resource child)
            {
                base.OnChildRemoved(child);
                if (MyParent.MyParent != null)
                    MyParent.MyParent.Children.OnChildRemoved(child);
            }
        }

        #region class Resource

        public class Resource : IResourceValue, SNAP.Util.IChild <Resource>
        {
            #region Constructors

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Resource"/> class.
            /// </summary>
            /// <param name="guid">The GUID.</param>
            /// <param name="type">The type.</param>
            /// <param name="name">The name.</param>
            public Resource(Guid guid, ResourceType type, string name)//, Resource parent)
            {
                _id  = guid;
                _type = type;
                _name = name;
                this._resourceDictionary = new ResourceChildren (this);
                //_parent = parent;

                foreach (IResourceType fieldType in _type.SubTypes.Values)
                {
                    _fields.Add(fieldType.Name, fieldType.CreateDefaultValue());
                }
            }

            

            #endregion

            #region Privates
            
            private readonly ResourceType _type;
            protected Resource _parent;
            protected string _name;
            protected readonly System.Guid _id;
            internal readonly ResourceChildren _resourceDictionary;   
            private readonly ResourceValueList _fields = new ResourceValueList();

            #endregion

            #region Properties

            IResourceType IResourceValue.MyType
            {
                get
                {
                    return _type;
                }
            }

            public ResourceType MyType
            {
                get
                {
                    return _type;
                }
            }

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

                    Resource parent = MyParent;
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
                    return this._resourceDictionary;
                }
            }

            #endregion Properties

            #region Methods

            #region Add/Remove

            /// <summary>
            /// Removes the node from it's parent
            /// </summary>
            public void RemoveFromParent()
            {
                if (MyParent != null)
                    MyParent.Children.Remove(Name);
            }

            #endregion Add/Remove

            /// <summary>
            /// Returns a <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
            /// </summary>
            /// <returns>
            /// A <see cref="T:System.String"></see> that represents the current <see cref="T:System.Object"></see>.
            /// </returns>
            public override string ToString()
            {
                StringBuilder builder = new StringBuilder ();
                builder.AppendFormat ("{0} : {1}\n", Name, MyType.DisplayName);
                foreach (IResourceValue value in this.SubValues.Values) {
                    builder.AppendFormat ("{0}= {1}\n", value.MyType.DisplayName, value.ToString ());
                }

                return builder.ToString();
            }

            #endregion Methods

            #region IResourceValue Members

            public IResourceValue GetDynamicProperty(string variableName)
            {
                if (_fields.ContainsKey(variableName))
                    return _fields[variableName];
                else
                {
                    switch (variableName)
                    {
                        case "Name":
                            /// TODO dynamically generat the resource type
                            return new TextFieldValue(this.Name, null);

                        case "ID":
                            /// TODO dynamically generat the resource type
                            return new TextFieldValue(this.ID.ToString(), null);

                        case "Family":
                            /// TODO dynamically generat the resource type
                            return new InternalRefFieldValue(this.MyParent.QualifiedName, null);

                        case "Folder":
                            // TODO: return the folder of the resource
                            throw new System.NotImplementedException();

                        default:
                            // TODO: give a more thoughtful error message
                            throw new System.ArgumentException("the variable " + variableName + " is invalid for a Resource");
                    }
                }
            }

            public ResourceValueList SubValues
            {
                get
                {
                    return this._fields;
                }
            }

            public void LoadFromXML(System.Xml.XmlNode node)
            {
                throw new Exception("The method or operation is not implemented.");
            }

            public void SaveToXML(XmlWriter writer)
            {
                writer.WriteStartElement("resource");

                writer.WriteAttributeString("type", this.MyType.Name);
                writer.WriteAttributeString("name", _name);
                writer.WriteAttributeString("id", ID.ToString());
                writer.WriteElementString("family", (MyParent != null) ? MyParent.QualifiedName : "");

                foreach (IResourceValue value in this._fields.Values)
                {
                    value.SaveToXML(writer);
                }

                writer.WriteEndElement();
            }

            /// <summary>
            /// Clones this instance.
            /// </summary>
            /// <returns></returns>
            IResourceValue IResourceValue.Clone()
            {
                throw new System.Exception("Not implemented");
            }

            #endregion

            #region IChild<Resource> Members

            public Resource MyParent
            {
                get
                {
                    return _parent;
                }
                set
                {
                    _parent = value;
                }
            }

            #endregion
        }

        #endregion class Resource

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

                XMLResourceTypeFactory factory = new XMLResourceTypeFactory(Controller.ResourceTypesFile);
                _resourceTypes = factory.CreateResourceTypes();

                /// create the root resource
                Root = new Resource(new Guid (), _resourceTypes ["Family"], "general");
                _resourceList.Add (Root.QualifiedName, Root);

                /// load the actual resources
                if (!System.IO.File.Exists (Controller.ResourcesFile)) 
                {
                    /// if the file doesnt exist, create the empty file
                    SaveResources ();
                }

                try
                {
                    LoadAdditionalResources(Controller.ResourcesFile, true);
                }
                catch (Exception x)
                {
                    Controller.ShowException("The file " + Controller.ResourcesFile + " could not be loaded. it may be corrupt. we recommend shutting the program down to avoid data loss.", x);
                }

                ///
                Root.Children.ChildAdded += new SNAP.Util.ChildEvent<Resource>(Root_ResourceAdded);
                Root.Children.ChildRemoved += new SNAP.Util.ChildEvent<Resource>(Root_ResourceRemoved);
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
                System.Diagnostics.Debug.Assert(resource.MyParent == null);
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

            public void RemoveResource(string qualifiedName)
            {
                RemoveResource  (_resourceList [qualifiedName]);
                SaveResources();
            }
            private void RemoveResource (Resource resource)
            {
                foreach (Resource child in resource.Children.Values)
                {
                    RemoveResource (child);
                }

                _resourceList.Remove(resource.QualifiedName);
            }

            #endregion Methods

            #region Implementation

            /// <summary>
            /// Handles the ResourceAdded event of the Root control.
            /// </summary>
            /// <param name="sender">The source of the event.</param>
            /// <param name="args">The <see cref="T:SNAP.Resources.CompositeResourceEventArgs"/> instance containing the event data.</param>
            void Root_ResourceAdded(object sender, SNAP.Util.ChildEventArgs<Resource> args)
            {
                _resourceList.Add(args.Child.QualifiedName, args.Child);
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

                /// create the new resource,
                /// fields are initialized to default values
                Resource resource = new Resource(guid, resourceType, resourceName);

                /// update field values using the information in the file
                foreach (System.Xml.XmlNode fieldNode in node.SelectNodes("field"))
                {
                    string fieldName = fieldNode.Attributes["name"].Value;
                    IResourceType fieldType = resource.MyType.SubTypes [fieldName];
                    IResourceValue fieldValue = null;
                    
                    System.Diagnostics.Debug.Assert (resource.SubValues.ContainsKey(fieldName));
                    fieldValue = resource.SubValues [fieldName];
                    fieldValue.LoadFromXML(fieldNode);
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

            internal Resource LoadResource(System.Xml.XmlNode node)
            {
                return LoadResource(node, null);
            }
            void Root_ResourceRemoved(object sender, SNAP.Util.ChildEventArgs<Resource> args)
            {
                System.Diagnostics.Debug.Assert(args.Child.MyParent != null);
                RemoveResource (args.Child);
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
                            resource.SaveToXML (writer);
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
