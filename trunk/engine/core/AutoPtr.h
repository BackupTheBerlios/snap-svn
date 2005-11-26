#ifndef _SeedSearcher_AutoPtr_h
#define _SeedSearcher_AutoPtr_h


template<class T>
class	GenPtr {
 public:
	T& operator*() const {
		debug_mustbe(ptr);
		return *get();
	}
	T* operator->() const {
		debug_mustbe(ptr);
		return get();
	}
 	T* get() const {
		return ptr;
	}
	operator T*() const{
		return ptr;
	}
	
	void set(T* in) {
		ptr= in;
	}
 protected:
	GenPtr(T* inPtr) : ptr(inPtr) {
	}
	GenPtr() {
		debug_only(ptr= (T*)0xDEADBEEF);
	}
	T* ptr;
};



template<class T>
class DefaultPtrOwner {
 public:
	static void acquire(T*) {
	}
 	static void release(T* ptr) {
 		delete ptr;
 	}
};

template<class T>
class ArrayPtrOwner {
 public:
 	static void acquire(T*) {
	}
	static void release(T* ptr) {
 		delete [] ptr;
 	}
};


template<class T>
class DummyPtrOwner {
 public:
    static void acquire(T*) {}
    static void release(T*) {}
};


template<class T, class Owner=DefaultPtrOwner<T> >
class	AutoPtr : public GenPtr<T> {
 public:
	AutoPtr(T* in= 0) : GenPtr<T>(in) {
		// in is already acquired
	}
	AutoPtr(const AutoPtr<T, Owner>& in) : GenPtr<T>(in.ptr) {
        // like in the C++ standard, the 'in' parameter is const, so we
        // can use it in STL containers and algorithms,
        // but remove the constness of the 'in' parameter
        // so we can tranfer ownership,
		const_cast<AutoPtr<T, Owner>&>(in).release();
	} 
	~AutoPtr() {
		reset(0);
	}
	AutoPtr& operator=(const AutoPtr<T, Owner>& in) {
        // see above comment
		reset(const_cast <AutoPtr<T, Owner>&> (in).release());
		return *this;
	}
	// Takes ownership of 'in'
	AutoPtr& operator=(T* in) {
		reset(in);
		return *this;
	}
	bool valid() const {	//YTD// Should live in GenPtr.h?
		return ptr!=0;
	}
	T* release() {
		T* result= ptr;
		ptr= 0;
		return result;
	}
	void dispose() {
		reset(0);
	}

 protected:
	void reset(T* in= 0) {
		// do it in this order
		// to prevent premature object dispose for 'x=x' statements
		Owner::acquire(in);
		Owner::release(ptr);
		ptr= in;
	}
};

template<class T>
class ArrayAutoPtr : public AutoPtr<T, ArrayPtrOwner<T> > {
 public:
 	ArrayAutoPtr(T in[]=0) : AutoPtr<T, ArrayPtrOwner<T> >(in) {
 	}

	ArrayAutoPtr& operator=(T* in) {
		reset(in);
		return *this;
	}
};

/*
Unfortunately the STL auto_ptr<> and array_auto_ptr<> are not specified by the standard 
and are not implemented consistently between the STL vendors. We have to run our own.

*/

#endif

//
// File        : $RCSfile: $ 
//               $Workfile: AutoPtr.h $
// Version     : $Revision: 6 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:45 $ 
// Description :
//	The Core library contains contains basic definitions and classes
// which are useful to any highly-portable applications
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
//

