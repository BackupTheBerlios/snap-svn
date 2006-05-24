using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    namespace Resources {
        #region ResourceDictionary

        internal class ResourceDictionary : SortedDictionary<string, Resource> {
        }

        #endregion ResourceDictionary

        #region CompositeResource

        internal class CompositeResource : Resource, System.Collections.Generic.IDictionary<string, Resource> {

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

            public override string Typename {
                get {
                    return "Family Resource";
                }
            }

            public override void Validate()
            {
            }

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
                Resource resource = this[key];
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
                    _resourceDicationary.TryGetValue(key, out resource);
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
                    string childName = relativeFamily[depth];
                    CompositeResource child =
                        (CompositeResource)this[childName];
                    if (child == null) {
                        child = new CompositeResource(childName);
                        Add(child);
                    }
                    child.Add(resource, relativeFamily, depth + 1);
                }
            }
        }


        #endregion CompositeResource
    }
}
