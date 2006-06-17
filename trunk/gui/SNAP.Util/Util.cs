using System.Collections.Generic;

namespace SNAP.Util {

    #region IndexedSortedList

    /// <summary>
    /// A hashtable usually has no concept of order. this means that traversing a hashtable
    /// with the 'foreach' keyword yields an unpredictable order of elements.
    /// 
    /// This IndexedHashyable "remembers" the order in which elements were insrted into the hashtable.
    /// thus using the 'foreach' keyword yields predictable and often very useful results,
    /// such as maintaining order of entries in an INI file.
    /// </summary>
    public class IndexedSortedList <TKey, TValue> : IDictionary<TKey, TValue>
    {
        #region private state
        private List<KeyValuePair<TKey, TValue>> _index;
        private SortedList<TKey, KeyValuePair<int, TValue>> _table;
        #endregion private state

        #region Constructors

        /// <summary>
        /// Initializes a new instance of the <see cref="T:IndexedSortedList&lt;TKey, TValue&gt;"/> class.
        /// </summary>
        public IndexedSortedList()
        {
            _table = new SortedList<TKey, KeyValuePair<int, TValue>>();
            _index = new List<KeyValuePair<TKey, TValue>>();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="T:IndexedSortedList&lt;TKey, TValue&gt;"/> class.
        /// </summary>
        /// <param name="comparer">The comparer.</param>
        public IndexedSortedList (System.Collections.Generic.IComparer <TKey> comparer)
        {
            _table = new SortedList<TKey,KeyValuePair<int,TValue>> (comparer);
            _index = new List<KeyValuePair<TKey, TValue>>();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="T:IndexedSortedList&lt;TKey, TValue&gt;"/> class.
        /// </summary>
        /// <param name="dictionary">The dictionary.</param>
        public IndexedSortedList(IDictionary<TKey, TValue> dictionary)
            : this ()
        {
            foreach (KeyValuePair<TKey, TValue> item in dictionary)
            {
                Add(item);
            }
        }

        #endregion Constructors

        #region Accessors

        /// <summary>
        /// Gets or sets the <see cref="Object"/> with the specified key.
        /// </summary>
        /// <value></value>
        public TValue this[TKey key]
        {
            get
            {
                KeyValuePair <int, TValue> x = _table[key];
                return x.Value;
            }
            set
            {
                KeyValuePair<int, TValue> x = _table[key];
                _table[key] = new KeyValuePair<int, TValue>(x.Key, value);
                _index[x.Key] = new KeyValuePair<TKey, TValue>(key, value);
            }
        }

        /// <summary>
        /// Gets or sets the <see cref="T:TValue"/> at the specified index.
        /// </summary>
        /// <value></value>
        public TValue this[int index]
        {
            get
            {
                return _index[index].Value;
            }
            set
            {
                this[_index[index].Key] = value;
            }
        }

        #endregion Accessors

        #region IList Members

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

        /// <summary>
        /// When implemented by a class, removes the <see cref="T:System.Collections.IList"/>
        /// item at the specified index.
        /// </summary>
        /// <param name="index">The zero-based index of the item to remove.</param>
        /// <exception cref="T:System.ArgumentOutOfRangeException">
        /// 	<paramref name="index"/> is not a valid index in the <see cref="T:System.Collections.IList"/>.</exception>
        /// <exception cref="T:System.NotSupportedException">
        /// 	<para>The <see cref="T:System.Collections.IList"/> is read-only.</para>
        /// 	<para>-or-</para>
        /// 	<para>The <see cref="T:System.Collections.IList"/> has a fixed size.</para>
        /// </exception>
        public void RemoveAt(int index)
        {
            KeyValuePair<TKey, TValue> entry = _index[index];
            _table.Remove(entry.Key);
            _index.RemoveAt(index);
        }

        /// <summary>
        /// Removes the specified key.
        /// </summary>
        /// <param name="key">The key.</param>
        public void Remove(TKey key)
        {
            KeyValuePair <int, TValue> x = _table[key];
            RemoveAt(x.Key);
        }

        /// <summary>
        /// Removes all items from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only. </exception>
        public void Clear()
        {
            _index.Clear();
            _table.Clear();
        }

        public int IndexOf(TKey key)
        {
            KeyValuePair <int, TValue> x = _table[key];
            return x.Key;
        }


        #endregion

        #region ICollection Members

        /// <summary>
        /// Gets the number of elements contained in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <value></value>
        /// <returns>The number of elements contained in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</returns>
        public int Count
        {
            get
            {
                return _index.Count;
            }
        }

        #endregion

        #region IEnumerable Members

        /// <summary>
        /// Returns an enumerator that can iterate through a collection.
        /// </summary>
        /// <returns>
        /// An <see cref="T:System.Collections.IEnumerator"/>
        /// that can be used to iterate through the collection.
        /// </returns>
        public IEnumerator<KeyValuePair <TKey, TValue>> GetEnumerator()
        {
            // TODO:  Add IndexedHashtable.GetEnumerator implementation
            return _index.GetEnumerator();
        }

        #endregion

        #region IDictionary Members
        
        /// <summary>
        /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
        /// </summary>
        /// <value></value>
        /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the values in the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
        public ICollection <TValue> Values
        {
            get
            {
                /// TODO: this returns the wrong type
                throw new System.NotImplementedException();
                //return _table.Values;
            }
        }

        /// <summary>
        /// Adds an element with the provided key and value to the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
        /// </summary>
        /// <param name="key">The object to use as the key of the element to add.</param>
        /// <param name="value">The object to use as the value of the element to add.</param>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IDictionary`2"></see> is read-only.</exception>
        /// <exception cref="T:System.ArgumentException">An element with the same key already exists in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</exception>
        /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
        public void Add(TKey key, TValue value)
        {
            _table.Add(key, new KeyValuePair <int, TValue> (_index.Count, value));
            _index.Add(new KeyValuePair <TKey, TValue> (key, value));

        }

        /// <summary>
        /// Gets an <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.
        /// </summary>
        /// <value></value>
        /// <returns>An <see cref="T:System.Collections.Generic.ICollection`1"></see> containing the keys of the object that implements <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</returns>
        public ICollection <TKey> Keys
        {
            get
            {
                return _table.Keys;
            }
        }

        #endregion

        #region IDictionary<TKey,TValue> Members


        /// <summary>
        /// Determines whether the <see cref="T:System.Collections.Generic.IDictionary`2"></see> contains an element with the specified key.
        /// </summary>
        /// <param name="key">The key to locate in the <see cref="T:System.Collections.Generic.IDictionary`2"></see>.</param>
        /// <returns>
        /// true if the <see cref="T:System.Collections.Generic.IDictionary`2"></see> contains an element with the key; otherwise, false.
        /// </returns>
        /// <exception cref="T:System.ArgumentNullException">key is null.</exception>
        public bool ContainsKey(TKey key)
        {
            return _table.ContainsKey(key);
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
        bool IDictionary<TKey, TValue>.Remove(TKey key)
        {
            throw new System.Exception("The method or operation is not implemented.");
        }

        bool IDictionary <TKey, TValue>.TryGetValue(TKey key, out TValue value)
        {
            KeyValuePair<int, TValue> x;
            if (_table.TryGetValue(key, out x))
            {
                value = x.Value;
                return true;
            }

            value = x.Value;
            return false;
        }

        #endregion

        #region ICollection<KeyValuePair<TKey,TValue>> Members

        /// <summary>
        /// Adds an item to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <param name="item">The object to add to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.</exception>
        public void Add(KeyValuePair<TKey, TValue> item)
        {
            Add(item.Key, item.Value);
        }

        /// <summary>
        /// Determines whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> contains a specific value.
        /// </summary>
        /// <param name="item">The object to locate in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
        /// <returns>
        /// true if item is found in the <see cref="T:System.Collections.Generic.ICollection`1"></see>; otherwise, false.
        /// </returns>
        public bool Contains(KeyValuePair<TKey, TValue> item)
        {
            return _index.Contains(item);
        }

        /// <summary>
        /// Copies the elements of the <see cref="T:System.Collections.Generic.ICollection`1"></see> to an <see cref="T:System.Array"></see>, starting at a particular <see cref="T:System.Array"></see> index.
        /// </summary>
        /// <param name="array">The one-dimensional <see cref="T:System.Array"></see> that is the destination of the elements copied from <see cref="T:System.Collections.Generic.ICollection`1"></see>. The <see cref="T:System.Array"></see> must have zero-based indexing.</param>
        /// <param name="arrayIndex">The zero-based index in array at which copying begins.</param>
        /// <exception cref="T:System.ArgumentOutOfRangeException">arrayIndex is less than 0.</exception>
        /// <exception cref="T:System.ArgumentNullException">array is null.</exception>
        /// <exception cref="T:System.ArgumentException">array is multidimensional.-or-arrayIndex is equal to or greater than the length of array.-or-The number of elements in the source <see cref="T:System.Collections.Generic.ICollection`1"></see> is greater than the available space from arrayIndex to the end of the destination array.-or-Type T cannot be cast automatically to the type of the destination array.</exception>
        public void CopyTo(KeyValuePair<TKey, TValue>[] array, int arrayIndex)
        {
            _index.CopyTo(array, arrayIndex);
        }

        /// <summary>
        /// Removes the first occurrence of a specific object from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <param name="item">The object to remove from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
        /// <returns>
        /// true if item was successfully removed from the <see cref="T:System.Collections.Generic.ICollection`1"></see>; otherwise, false. This method also returns false if item is not found in the original <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </returns>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.</exception>
        public bool Remove(KeyValuePair<TKey, TValue> item)
        {
            if (Contains(item))
            {
                Remove(item.Key);
                return true;
            }

            return false;
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
            return _index.GetEnumerator();
        }

        #endregion
    }

    #endregion IndexedSortedList

    #region ChildList

    public interface IChild<TParent> where TParent:class
    {
        TParent MyParent
        {
            get;
            set;
        }
    }

    public interface IChildList<TChild, TParent> : IList<TChild>, IChild<TParent>
        where TChild : class, IChild<TParent>
        where TParent : class
    {
    }


    public class ChildList<TChild, TParent> : IChildList<TChild, TParent>
        where TChild : class, IChild<TParent>
        where TParent : class
    {
        #region Privates

        private TParent _parent;
        protected IList<TChild> _list;

        #endregion Privates

        #region Constructor

        public ChildList(TParent parent)
        {
            _parent = parent;

            _list = new List<TChild>();
        }

        #endregion Constructor

        #region IList<TChild> Members

        /// <summary>
        /// Determines the index of a specific item in the <see cref="T:System.Collections.Generic.IList`1"></see>.
        /// </summary>
        /// <param name="item">The object to locate in the <see cref="T:System.Collections.Generic.IList`1"></see>.</param>
        /// <returns>
        /// The index of item if found in the list; otherwise, -1.
        /// </returns>
        public int IndexOf(TChild item)
        {
            return _list.IndexOf(item);
        }

        /// <summary>
        /// Inserts an item to the <see cref="T:System.Collections.Generic.IList`1"></see> at the specified index.
        /// </summary>
        /// <param name="index">The zero-based index at which item should be inserted.</param>
        /// <param name="item">The object to insert into the <see cref="T:System.Collections.Generic.IList`1"></see>.</param>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IList`1"></see> is read-only.</exception>
        /// <exception cref="T:System.ArgumentOutOfRangeException">index is not a valid index in the <see cref="T:System.Collections.Generic.IList`1"></see>.</exception>
        public void Insert(int index, TChild item)
        {
            _list.Insert(index, item); 
            item.MyParent = MyParent;
            System.Diagnostics.Debug.Assert(item.MyParent == MyParent);
        }

        /// <summary>
        /// Removes the <see cref="T:System.Collections.Generic.IList`1"></see> item at the specified index.
        /// </summary>
        /// <param name="index">The zero-based index of the item to remove.</param>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.IList`1"></see> is read-only.</exception>
        /// <exception cref="T:System.ArgumentOutOfRangeException">index is not a valid index in the <see cref="T:System.Collections.Generic.IList`1"></see>.</exception>
        public void RemoveAt(int index)
        {
            TChild child = _list [index];
            _list.RemoveAt(index);
            child.MyParent = null;
        }

        /// <summary>
        /// Gets or sets the <see cref="T:TChild"/> at the specified index.
        /// </summary>
        /// <value></value>
        public TChild this[int index]
        {
            get
            {
                return _list[index];
            }
            set
            {
                TChild child = _list [index];
                if (child == value)
                    return;

                _list [index] = value;
                child.MyParent = null;
                value.MyParent = MyParent;
            }
        }

        #endregion

        #region ICollection<TChild> Members

        /// <summary>
        /// Adds an item to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <param name="item">The object to add to the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.</exception>
        public void Add(TChild item)
        {
            _list.Add(item);
            item.MyParent = MyParent;
        }

        /// <summary>
        /// Removes all items from the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <exception cref="T:System.NotSupportedException">The <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only. </exception>
        public void Clear()
        {
            IList<TChild> temp = _list;
            
            ///
            /// TODO: allow customization of list type?
            _list = new List<TChild>();
            foreach (TChild child in temp)
            {
                child.MyParent = null;
            }
        }

        /// <summary>
        /// Determines whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> contains a specific value.
        /// </summary>
        /// <param name="item">The object to locate in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</param>
        /// <returns>
        /// true if item is found in the <see cref="T:System.Collections.Generic.ICollection`1"></see>; otherwise, false.
        /// </returns>
        public bool Contains(TChild item)
        {
            return _list.Contains(item);
        }

        /// <summary>
        /// Copies the elements of the <see cref="T:System.Collections.Generic.ICollection`1"></see> to an <see cref="T:System.Array"></see>, starting at a particular <see cref="T:System.Array"></see> index.
        /// </summary>
        /// <param name="array">The one-dimensional <see cref="T:System.Array"></see> that is the destination of the elements copied from <see cref="T:System.Collections.Generic.ICollection`1"></see>. The <see cref="T:System.Array"></see> must have zero-based indexing.</param>
        /// <param name="arrayIndex">The zero-based index in array at which copying begins.</param>
        /// <exception cref="T:System.ArgumentOutOfRangeException">arrayIndex is less than 0.</exception>
        /// <exception cref="T:System.ArgumentNullException">array is null.</exception>
        /// <exception cref="T:System.ArgumentException">array is multidimensional.-or-arrayIndex is equal to or greater than the length of array.-or-The number of elements in the source <see cref="T:System.Collections.Generic.ICollection`1"></see> is greater than the available space from arrayIndex to the end of the destination array.-or-Type T cannot be cast automatically to the type of the destination array.</exception>
        public void CopyTo(TChild[] array, int arrayIndex)
        {
            _list.CopyTo(array, arrayIndex);
        }

        /// <summary>
        /// Gets the number of elements contained in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.
        /// </summary>
        /// <value></value>
        /// <returns>The number of elements contained in the <see cref="T:System.Collections.Generic.ICollection`1"></see>.</returns>
        public int Count
        {
            get
            {
                return _list.Count;
            }
        }

        /// <summary>
        /// Gets a value indicating whether the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only.
        /// </summary>
        /// <value></value>
        /// <returns>true if the <see cref="T:System.Collections.Generic.ICollection`1"></see> is read-only; otherwise, false.</returns>
        bool ICollection<TChild>.IsReadOnly
        {
            get {
                return _list.IsReadOnly;
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
        public bool Remove(TChild item)
        {
            if (_list.Remove(item))
            {
                item.MyParent = null;
                return true;
            }
            return false;
        }

        #endregion

        #region IEnumerable<TChild> Members

        /// <summary>
        /// Returns an enumerator that iterates through the collection.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.Collections.Generic.IEnumerator`1"></see> that can be used to iterate through the collection.
        /// </returns>
        public IEnumerator<TChild> GetEnumerator()
        {
            return _list.GetEnumerator();
        }

        #endregion

        #region IEnumerable Members

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return _list.GetEnumerator();
        }

        #endregion

        #region IChild<TParent> Members

        /// <summary>
        /// Gets my parent.
        /// </summary>
        /// <value>My parent.</value>
        public TParent MyParent
        {
            get { 
                return _parent;
            }
            set
            {
            }
        }

        #endregion
    }

    #endregion ChildList
}
