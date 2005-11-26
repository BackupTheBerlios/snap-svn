#ifndef   _SeedSearcher_Core_ImplList_h
#define   _SeedSearcher_Core_ImplList_h

#include "Core/Defs.h"

template<class T>
inline void zapPointer(T*& ptr) {
   debug_only (
	   ptr= (T*)0xBAADF00D;
   );
}


template<class Node>
class	Impl1WayNode {
 public:
	Impl1WayNode() {
		zapPointer(forward);
	}
	Impl1WayNode(Node* in) : forward(in) {
	}
	Node* next() const {
		return forward;
	}
	Node* linkTo(Node* inNode) {
		return forward= inNode;
	}
	void unlink() {
		zapPointer(forward);
	}
 protected:
	Node* forward;
};

template<class Data>
class	Impl1WayDataNode : public Impl1WayNode< Impl1WayDataNode<Data> > {
 public:
	Impl1WayDataNode(const Data& in) : data(in) {
	}
	Impl1WayDataNode() {
	}
	Data data;
};

template<class Node>
class	Impl2NodeContext {
 public:
	Impl2NodeContext(Node* in) : first(in), second(in->next()) {
		debug_mustbe(first);
	}
	Impl2NodeContext(Node* inFirst, Node* inSecond) : first(inFirst), second(inSecond) {
	}
	Node* getFirst() {
		return first;
	}
	Node* getSecond() {
		return second;
	}
	bool hasNext() const {
		return first!=second;
	}
	void next() {
		debug_mustbe(second && hasNext());
		first= second;
		second= first->next();
	}
	Node* addFirst(Node* in) {
		insert(in);
		return first= in;
	}
	Node* addSecond(Node* in) {
		insert(in);
		return second= in;
	}
	Node* removeSecond() {
		debug_mustbe(hasNext());
		Node* save= second;
		second= second->next();
		first->linkTo(second);
		save->unlink();
		return save;
	}

 protected:
	Node* first;
	Node* second;

	void insert(Node* in) {
		debug_mustbe(in!=0 && in!=first && in!=second);
		if (first)
			first->linkTo(in);
		in->linkTo(second);
	}
};

enum ImplListNoConstructor {
	implListNoConstructor
};

template<class T>
class	ImplCyclicList {
 public:
	typedef T Node;
	typedef Impl2NodeContext<T> Context;

	ImplCyclicList() : head(0) {
	}
	~ImplCyclicList() {
		debug_mustbe(head==0);
	}
	ImplCyclicList(ImplListNoConstructor) {		// constructor designed for use in statics
	}

	bool empty() const {
		return head==0;
	}

	Node* getFirst() {
		debug_mustbe(head);
		return head->next();
	}

    const Node* getFirst() const {
		debug_mustbe(head);
		return head->next();
    }

	Node* getLast() {
		debug_mustbe(head);
		return head;
	}

    const Node* getLast() const {
		debug_mustbe(head);
		return head;
	}

	void addFirst(Node* in) {
		if (head)
			Context(head).addSecond(in);
		else
			stuffNode(in);
	}
	void addLast(Node* in) {
		if (head)
			head= Context(head).addSecond(in);
		else
			stuffNode(in);
	}
	Node* removeFirst() {
		debug_mustbe(head);
		Context c(head);
		if (c.hasNext()) {
			return c.removeSecond();
		} else {
			Node* result= head;
			head= 0;
			result->unlink();
			return result;
		}
	}

	bool exists(Node* in) const {	// O(N)
		if (!head)
			return false;
		Context c(head);
		if (c.hasNext()) {
			for(; ; c.next()) {
				if (c.getSecond()==in) 
					return true;
				else if (c.getSecond()==head) 
					return false;
			}
		} else 
			return (head==in);
	}

	Node* remove(Node* in) {	// O(N)
		debug_mustbe(head);
		Context c(head);
		if (c.hasNext()) {
			for(; ; c.next()) {
				if (c.getSecond()==in) {
					c.removeSecond();
					if (in==head)
						head= c.getFirst();
					break;
				} if (c.getSecond()==head) {
					debug_mustfail();
					break;
				}
			}
		} else {
			debug_mustbe(head==in);
			head->unlink();
			head= 0;
		}
		return in;
	}
	Node* removeLast() {		// O(N)
		Node* last= getLast();
		remove(last);
		return last;
	}

	class	ReadIterator {
	 public:
		ReadIterator(Node* inHead) {
			init(inHead);
		}
		ReadIterator(ImplCyclicList& inList) {
			init(inList.head);
		}

		bool atEnd() const {
			return cur==0;
		}
		void next() {
			debug_mustbe(cur);
			if (cur==head)
				cur= 0;
			else
				cur= cur->next();
		}
		Node* get() {	//YTD// Should be first??
			debug_mustbe(cur);
			return cur;
		}
		const Node* get() const {	//YTD// Should be first??
			debug_mustbe(cur);
			return cur;
		}
		Node* operator->() {
			return get();
		}

	 protected:
		Node* cur;
		Node* head;

		void init(Node* inHead) {
			head= inHead;
			if (head)
				cur= head->next();
			else
				cur= 0;
		}
	};
	friend class ReadIterator;

	class	ReadIterator_const {
	 public:
		ReadIterator_const(const Node* inHead): head (inHead) {
			init();
		}
		ReadIterator_const(const ImplCyclicList& inList): head (inList.head) {
			init();
		}

		bool atEnd() const {
			return cur==0;
		}
		void next() {
			debug_mustbe(cur);
			if (cur==head)
				cur= 0;
			else
				cur= cur->next();
		}
		const Node* get() const {	//YTD// Should be first??
			debug_mustbe(cur);
			return cur;
		}
		const Node* operator->() {
			return get();
		}

	 protected:
		const Node* cur;
		const Node* head;

		void init() {
			if (head)
				cur= head->next();
			else
				cur= 0;
		}
	};
	friend class ReadIterator_const;

	class	Iterator {
	public:
		Iterator (Node* inHead): head (inHead)
		{
			init ();
		}

		Iterator (ImplCyclicList& inList): head (inList.head)
		{
			init ();
		}

	// adds 'in' after current node
		void add (Node* in) 
		{
			if (cur)
				Context (cur).addSecond (in);
			else {
				in->linkTo (in);
				head = in;
			}
		}

	// removes node after current one
		Node* remove () 
		{
			Context c (cur);
			Node* node = 0;
			if (c.hasNext ()) {
				node = c.removeSecond ();
				if (node == head)
					head = c.getFirst ();
			} else {
				debug_mustfail ();
			}
			return node;
		}

		bool atEnd () const 
		{
			return cur == 0;
		}

		void next () 
		{
			debug_mustbe (cur);
			if (cur == head)
				cur = 0;
			else
				cur = cur->next ();
		}

		const Node* getNext () const
		{
			debug_mustbe (cur);
			if (cur == head)
				return 0;
			else
				return cur->next ();
		}

		Node* get () 
		{	
			debug_mustbe (cur);
			return cur;
		}

		const Node* get () const 
		{
			debug_mustbe(cur);
			return cur;
		}

		Node* operator -> () 
		{
			return get ();
		}

	 protected:
		Node* cur;
		Node*& head;

		void init () 
		{
			if (head)
				cur = head->next ();
			else
				cur = 0;
		}
	};
	friend class Iterator;

 protected:
	Node* head;

	void stuffNode(Node* in) {
		in->linkTo(in);
		head= in;
	}
};


template<class T>
class ImplDataList  {
    //
    // 
    // 
public:
	typedef T Data;
    typedef Impl1WayDataNode <Data*> Node;
    typedef ImplCyclicList <Node> List;

    ImplDataList () {
    }
    ImplDataList (const ImplDataList& in) {
        add (in);
    }
    ~ImplDataList () {
        if (!empty ())  {
            debug_mustfail ();
            reset ();
        }
    }
	bool empty() const {
		return list.empty ();
	}
	Data* getFirst() {
        return list.getFirst ()->data;
	}
    const Data* getFirst() const {
        return list.getFirst ()->data;
    }
	Data* getLast() {
        return list.getLast ()->data; 
	}
    const Data* getLast() const {
        return list.getLast ()->data; 
	}
	void addFirst(Data* in) {
        list.addFirst (new Node (in));
	}
	void addLast(Data* in) {
        list.addLast (new Node (in));
	}
	void addFirstNode(Node* in) {
        list.addFirst (in);
	}
	void addLastNode(Node* in) {
        list.addLast (in);
	}

    void take (ImplDataList& inList)    {
        while (!inList.empty ())
            addLastNode (inList.removeFirstNode ());
    }
    void add (const ImplDataList& inList)    {
        ReadIterator_const it (inList);
        for (; !it.atEnd () ; it.next ())
            addLast (const_cast <Data*> (it.get ()));
    }

	Data* removeFirst () {
        Node* node = list.removeFirst ();
        Data* data = node->data;
        delete node;
        return data;
	}
	Node* removeFirstNode () {
        Node* node = list.removeFirst ();
        return node;
	}
    void reset ()  {
        while (!empty ())   {
            Node* node = list.removeFirst ();
            delete node;
        }
    }

    Data* remove(Node* in) {	// O(N)
        Node* node = list.remove (in);
        if (node)   {
            Data* data = node->data;
            delete node;
            return data;
        }

        debug_mustfail ();
        return NULL;
    }

	class ReadIterator  {
    public:
        ReadIterator(ImplDataList& inList) : list (inList.getList ())  {
		}
		bool atEnd() const {
			return list.atEnd ();
		}
		void next() {
            list.next ();
		}
		Data* get() {
            return list.get ()->data;
        }
		const Data* get() const {
            return list.get ()->data;
		}
		Node* getNode () {
            return list.get ();
        }
		const Node* getNode () const {
            return list.get ();
		}
		Data* operator->() {
			return list.get ()->data;
		}

    private:
        typename List::ReadIterator list;
    };

	class ReadIterator_const  {
    public:
        ReadIterator_const (const ImplDataList& inList) : list (inList.getList ())  {
		}
		bool atEnd() const {
			return list.atEnd ();
		}
		void next() {
            list.next ();
		}
		const Data* get() const {
            return list.get ()->data;
		}
		const Node* getNode () const {
            return list.get ();
		}
		const Data* operator->() const    {
			return list.get ()->data;
		}

    private:
        typename List::ReadIterator_const list;
    };

    List& getList ()    {
        return list;
    }
    const List& getList () const    {
        return list;
    }

private:
    List list;
};



#endif

/* $Header: /home/cvs/Lib/Data/ImplList.h,v 1.20 2000/11/07 05:11:43 yulia Exp $	

Low-level list data structure.

97-12-10 S.O.

(C) Copyright 1996-1998 ArchSys Ltd.
*/

