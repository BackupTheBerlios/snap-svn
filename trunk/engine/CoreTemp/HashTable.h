#ifndef _SeedSearcher_Core_HashTable_h
#define _SeedSearcher_Core_HashTable_h

#include "Defs.h"

template<class Parm, class Result>
class Functor1R {
 public:
	Result operator()(Parm inParm) {
		return call(inParm);
	}
	virtual Result call(Parm inParm)= 0;
};


template<class Value>
class RangeForwardIter {
 public:
	RangeForwardIter(Value* inLow, Value* inHigh) : cur(inLow-1), last(inHigh) {
	}
   bool hasNext () const {
      return (cur+1) < last;
   }
   bool next () {
		return ++cur < last;
	}
	Value& operator*() {
		return *cur;
	}
	Value* get() const {
		return cur;
	}

 private:
	Value* cur, *last;
};

typedef unsigned int HashValue;

template <class Entry>
struct DefaultDeallocator {
   static void dispose (Entry* entry) {
      delete entry;
   }
};

template<class Entry, class D = DefaultDeallocator <Entry> >
class HashTable {
	typedef Entry* TableItem;
	typedef typename Entry::Key Key;
	typedef RangeForwardIter<TableItem> TableIter;
   
   //
	//
	void constraints(Entry* entry) {
		Key key= entry->getKey();
		bool result= entry->fitsKey(key);
		Entry* next= entry->next();
		entry->setNext(next);
		HashValue hash= Entry::hash(entry->getKey());
	}

 public:
	typedef Entry Node;
	typedef Functor1R<Entry*,bool> Visitor;
   typedef D Deallocator;

	HashTable(size_t inSize): _table(0), _size(0), _count(0)  
	{
		_table= makeTable(inSize);
		_size= inSize;
	}

	~HashTable() 
	{
		clear ();
		delete[] _table;
	}

	void add(Entry* in) 
	{
		debug_mustbe(find(in->getKey())==0);
		TableItem& root= tableLookup(in->getKey());
		in->setNext(root);
		root= in;
		_count++;
	}

	void clear (bool iterateElements = true)
	{
      if (iterateElements) {
		   TableIter tabI(_table, _table+_size);
		   while(tabI.next ()) {
			   for(Entry* entry= *tabI; entry; ) {
				   Entry* nextOne= entry->next();
               Deallocator::dispose (entry);
				   *tabI= nextOne;
				   _count--;
				   entry= nextOne;
			   }
		   }
      }
      else {
         //
         // just zero out the table without calling dtors
         TableIter tabI(_table, _table+_size);
		   while(tabI.next ()) {
            *tabI = NULL;
         }
      }
	}

	//	Compatibility name
	void insert(Entry* in) {
		add(in);
	}

	void remove(const Key& inKey) {
		TableItem& root= tableLookup(inKey);
		for(Entry* entry= root, *prev=0, *nextEntry; entry; 
			prev= entry, entry= nextEntry) {
			nextEntry= entry->next();
			if (entry->fitsKey(inKey)) {
				if (prev)
					prev->setNext(nextEntry);
				else
					root= entry->next();
            Deallocator::dispose (entry);
				_count--;
				return;
			}
		}
		debug_mustfail();
	}

	void detach(Entry* inEntry) {
		TableItem& head= tableLookup(inEntry->getKey());
		for(Entry* entry= head, *prev=0; entry; 
			prev= entry, entry= entry->next()) {
			if (entry==inEntry) {
				if (prev)
					prev->setNext(entry->next());
				else
					head= entry->next();
				_count--;
				return;
			}
		}
		debug_mustfail();	// The entry was not found
	}

	void visitAll_const (Visitor& inVisitor) const {
		TableIter tabI(table, table+size);
		while(tabI.next()) {
			for(Entry* entry= *tabI, *prev= 0; entry; ) {
				Entry* nextOne= entry->next();
			#if ENV_BUGS & ENV_MICROSOFT
				if (inVisitor.operator()(entry)) {
			#else
				if (inVisitor(entry)) {
			#endif
					prev= entry;
				} else {
					debug_mustfail ();
				}
				entry= nextOne;
			}
		} 
	}

	void visitAll(Visitor& inVisitor) {
		TableIter tabI(_table, _table + _size);
		while(tabI.next()) {
			for(Entry* entry= *tabI, *prev= 0; entry; ) {
				Entry* nextOne= entry->next();
			#if ENV_BUGS & ENV_MICROSOFT
				if (inVisitor.operator()(entry)) {
			#else
				if (inVisitor(entry)) {
			#endif
					prev= entry;
				} else {
					if (prev)
						prev->setNext(nextOne);
					else
						*tabI= nextOne;

					_count--;
				}
				entry= nextOne;
			}
		}
	}

   class Iterator {
   public:
      Iterator (HashTable& table) 
      : _tableIt (table._table, table._table + table.getTableSize ()), _entry (NULL)
      {
         next ();
      }

      bool hasNext () const {
         return (_entry != NULL);
      }

      void next () {
         if (_entry != NULL)
            _entry = _entry->next ();

         while ((_entry == NULL) && _tableIt.hasNext ()) {
            _tableIt.next ();
            _entry = *_tableIt;
         }
      }

      Entry* operator->() const{
		   return _entry;
	   }
	   Entry& operator*() const{
		   return _entry;
	   }
	   Entry* get() const {
		   return _entry;
	   }

   private:
      TableIter _tableIt;
      Entry* _entry;
   };

   friend class Iterator;


	Entry* find(const Key& inKey) const {
		return find(inKey, Entry::hash(inKey));
	}
	
	Entry* find(const Key& inKey, HashValue inHash) const {
      //
      // this is used to make sure the hash function performs
      // somewhat adequately
      debug_only (
         int index=0;
         int reasonableChainLength = static_cast <int> (
            4 * tmax (2.0, ((double) _count + 1) / (_size)));
      );
      
      Entry* entry= _table[hash2Index(inHash)];
		for(; entry; entry= entry->next()) {
			if (entry->fitsKey(inKey))
				return entry;

         debug_mustbe (++index <= reasonableChainLength);
		}
		return 0;
	}

	void resize(size_t inNewSize) {
	  TableItem* oldTable= _table;
	  size_t oldSize= _size;
	  _table= makeTable(inNewSize);
	  _size= inNewSize;
	  
	  TableIter tabI(oldTable, oldTable+oldSize);
	  while(tabI.next()) {
	    for(Entry* entry= *tabI; entry; ) {
	      do {
		Entry* nextOne= entry->next();
		entry->setNext(0);
		insert(entry);
		entry = nextOne;
	      }
	      while (entry);
	    }
	  }

	  delete[] oldTable;
	}

   size_t getTableSize () const {
      return _size;
   }

	size_t getSize() const {	// YTD: change name: size->tabSize, getSize() -> size()
		return _count;
	}

 protected:
	TableItem* _table;
	size_t _size;
	size_t _count;

	size_t hash2Index(HashValue inValue) const {
		return inValue % _size;
	}
	TableItem& tableLookup(const Key& inKey) const {
		return _table[hash2Index(Entry::hash(inKey))];
	}
	Entry* createLink(Entry* first, Entry* next) {
		if (first)
			first->setNext(next);
		return first;
	}

	static TableItem* makeTable(size_t inSize) {
		TableItem* table= new TableItem[inSize];
		TableIter tabI(table, table + inSize);
		while(tabI.next()) {
			debug_mustbe(table<=tabI.get() && tabI.get() < (table+inSize));
			*tabI= 0;
		}
		return table;
	}
};

//	Default definitions. Use them unless you have a reason to not to.
//	Example:
//		typedef HashTable< HashTableEntry<int, string> > MyHash;
//		MyHash table;

template<class Key>
class	HashKeyEntry {
 public:
	HashKeyEntry(const Key& inKey) : key(inKey) {
	}
	const Key& getKey() const {
		return key;
	}
	bool fitsKey(const Key& in) {
		return in==key;
	}
	static HashValue hash(const Key& inKey) {
		return defaultHashFunction(inKey);
	}

 protected:
	Key key;
};

template<class InKey, class InValue>
class	HashKeyValueEntry : public HashKeyEntry<InKey> {
 public:
	typedef InKey Key;
	typedef InValue Value;

	HashKeyValueEntry(const Key& inKey, Value inValue) : 
		HashKeyEntry<Key>(inKey), value(inValue) {
	}

	Value value;
};

template<class Entry>
class	HashLinkEntry {
 public:
	HashLinkEntry() : hashLink(0) {
	}

	Entry* next() const {
		return hashLink;
	}
	void setNext(Entry* inLink) {
		hashLink= inLink;
	}

 protected:
	Entry* hashLink;
};

template<class _Key, class _Value>
class	HashTableEntry : public HashKeyEntry<_Key> {
 public:
  typedef _Key Key;
  typedef _Value Value;

	HashTableEntry(Key inKey, Value inValue) : 
		HashKeyEntry<Key>(inKey), value(inValue), link(0) {
	}

	HashTableEntry* next() const {
		return link;
	}
	void setNext(HashTableEntry* in) {
		link= in;
	}

	Value value;

 protected:
	HashTableEntry* link;
};

inline HashValue defaultHashFunction(long inValue) {
	return (inValue * 314159236) ^ 271764387;
}

inline HashValue defaultHashFunction(const void* inValue) {
	return defaultHashFunction((long)inValue);
}

HashValue defaultHashFunction(const char* inStr, size_t inSize);

#endif








