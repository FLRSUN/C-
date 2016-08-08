#pragma once

#include <iostream>
using namespace std;

template <class T>
class AutoPtr{
public:
	AutoPtr(T* ap)
	:_ptr(ap)
	{}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	~AutoPtr(){
		if (_ptr){
			delete _ptr;
			_ptr = NULL;
		}
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap){
		if (this != &ap){
			delete _ptr;
			_ptr = NULL;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*(){  
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
//protected:
	T* _ptr;

};

//template <class T>
//class AutoPtr{
//public:
//	AutoPtr(T* ptr)
//		:_ptr(ptr), _use(true)
//	{}
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr), _use(ap._use)
//	{
//		ap._use = false;
//	}
//	~AutoPtr(){
//		if (_use == true)
//			delete _ptr;
//	}
//	T& operator*(){
//		return *_ptr;
//	}
//	T* operator->(){
//		return _ptr;
//	}
////protected:
//	T* _ptr;
//	bool _use;
//};

template <class T>
class ScopedPtr{
public:
	ScopedPtr(T* ptr = (new T))
	:_ptr(ptr){}
	~ScopedPtr(){
		if (_ptr){
			delete _ptr;
			_ptr = NULL;
		}
	}
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
protected:                       //防拷贝：只声明，不实现。
	ScopedPtr(ScopedPtr<T>& sp);
	ScopedPtr<T>& operator=(ScopedPtr<T>& sp);
protected:
	T* _ptr;
};

template <class T>
class ScopedArry{
public:
	ScopedArry(T* ptr)
	:_ptr(ptr){
	}
	~ScopedArry(){
		if (_ptr){
			delete[] _ptr;
			_ptr = NULL;
		}
	}
	T& operator[](const int index){
		return _ptr[index];
	}
protected:                        //防拷贝：只声明，不实现。
	ScopedArry(ScopedArry<T>& T);
	ScopedArry<T>& operator=(ScopedArry<T>& sa);
protected:
	T* _ptr;
};

template <class T>
class SharePtr{
public:
	SharePtr(T* ptr = (new T))
		:_ptr(ptr), _count(new int(1))
	{}
	SharePtr(SharePtr<T>& sp)
		:_ptr(sp._ptr), _count(sp._count){
		++(*_count);
	}
	SharePtr<T>& operator=(const SharePtr<T>& sp){
		if(_ptr != sp._ptr){
			if(--(*_count) == 0){
				delete _ptr;
				_ptr = NULL;
			}
			_ptr = sp._ptr;
			_count = sp._count;
			(*_count)++;
		}
		return *this;
	}
	SharePtr<T>& operator=(SharePtr<T> sp){
		swap(_ptr, sp._ptr);
		swap(_count, sp._count);
		return *this;
	}
	~SharePtr(){
		if (--(*_count) == 0){
			delete _ptr;
			_ptr = NULL;
			delete _count;
			*_count = 0;
		}
	}
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
protected:
	T* _ptr;
	int* _count;
};

template <class T>
class SharedArry{
public:
	SharedArry(T* ptr )
	:_ptr(ptr),_count(new int(1))
	{}
	~SharedArry(){
		if (--(*_count) == 0){
			delete[] _ptr;
			_ptr = NULL;
			delete _count;
			_count = NULL;
		}
	}
	SharedArry(const SharedArry<T>& sa)
	:_ptr(sa._ptr),_count(sa._count){
		(*_count)++;
	}


	SharedArry<T>& operator=(SharedArry<T> sa){
		swap(_ptr, sa._ptr);
		swap(_count, sa._count);
		return *this;
	}

	T& operator[](const int index){
		return _ptr[index];
	}

protected:
	T* _ptr;
	int* _count;
};

//template <class T>
//class BaseSp{
//	friend class SharedPtr;
//
//	BaseSp(T* pt)
//	:ptr(pt),_count(1){}
//	~BaseSp(){
//		delete ptr;
//	}
//	T* ptr;
//	int _count;
//};
//template <class T>
//class SharedPtr{
//	SharedPtr(T *ptr,T i)
//	:_ptr(ptr),_value(i)
//	{}
//	SharedPtr(const SharedPtr<T>& sp)
//	:_ptr(sp._ptr),_value(sp._value){
//		_ptr->_count++;
//	}
//	~SharedPtr(){
//		if (--_ptr->_count == 0)
//			delete _ptr;
//	}
//protected:
//	BaseSp *_ptr;
//	T _value;
//};

//class BaseSp{
//	friend class SharedPtr;
//
//	BaseSp(int* pt)
//	:ip(pt),_count(1){}
//	~BaseSp(){
//		delete ip;
//	}
//	int* ip;
//	int _count;
//};
//class SharedPtr{
//	SharedPtr(BaseSp *ptr, int i)
//	:_ptr(ptr),_value(i)
//	{}
//	SharedPtr(const SharedPtr& sp)
//	:_ptr(sp._ptr),_value(sp._value){
//		_ptr->_count++;
//	}
//	~SharedPtr(){
//		if (--_ptr->_count == 0)
//			delete _ptr;
//	}
//protected:
//	BaseSp *_ptr;
//	int _value;
//};