#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Stack{
public:
	Stack()
		:_data(new T[3]), _top(0), _capacity(3), _mi()
	{}
	Stack(const Stack<T>& s)
	:_top(s._top),_capacity(s._capacity){
		NewClass(s);
	}
	~Stack(){
		if (_data){
			delete _data;
			_data = NULL;
			_top = 0;
			_capacity = 0;
		}
	}
	void Push(const T data){
		CheckCapacity();
		if (_top == 0){
			_min = data;
			_mi.push(data);
		}			
		_data[_top++] = data;
		if (_min > _data[_top - 1]){
			_min = _data[_top - 1];	
			_mi.push(_data[_top - 1]);
		}	
	}
	void Pop(){
		if (_top != 0){
			if (_data[_top - 1] == _mi.top())
				_mi.pop();
				_top--;
		}
	}
	void Print(){
		if (_top){
			for (size_t i = 0; i < _top; ++i){
				cout << _data[i];
				if (i != _top-1 )
					cout << " ";
			}
		}
		cout << endl;
	}
	Stack<T>& operator=(const Stack<T>& s){
		NewClass(s);
		_top = s._top;
		_capacity = s._capacity;
		return *this;
	}
	bool Empty(){
		return !_top;
	}
	size_t Size(){
		return _top;
	}
	T& GetMin(){
		return _min;
	}
	T& Getmin(){
		return _mi.top();
	}
protected:
	void CheckCapacity(){
		if (_top == _capacity){
			_capacity *= 2;
			T* temp = new T[_capacity];
			size_t i = 0;
			for (i = 0; i < _top; ++i){
				temp[i] = _data[i];
			}
			delete _data;
			_data = temp;
		}
	}
	void NewClass(const Stack<T>& s){
		delete _data;
		_data = new T[s._capacity];
		_min = s._min;
		_mi = s._mi;
		for (size_t i = 0; i < s._top; ++i){
			_data[i] = s._data[i];
		}
	}
protected:
	T* _data;
	size_t _top;
	size_t _capacity;
	T _min;           //false
	stack<T> _mi;     //right
};