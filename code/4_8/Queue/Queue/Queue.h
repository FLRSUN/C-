#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node{
	Node(const T& data)
	:_data(data),_next(NULL){}
	T _data;
	Node<T>* _next;
};

template <class T>
class Queue{
public:
	Queue()
	:_head(NULL), _tail(NULL){}
	~Queue(){
		if (_head){
			if (_head == _tail)
				delete _head;
			else{
				delete _head;
				_head = NULL;
				delete _tail;
				_tail = NULL;
			}			
		}
	}
	void Push( T indexdata){
		Node<T>* index = new Node<T>(indexdata);
		if (_head == NULL){
			_head = index;
			_tail = _head;
			return;
		}
		_tail->_next = index;
		_tail = index;
	}
	void Pop(){
		if (!Empty()){
			_head = _head->_next;
		}
	}
	void Print(){
		if (!Empty()){
			Node<T>* cur = _head;
			while (cur){
				cout << cur->_data;
				if (cur->_next)
					cout << "->";
				cur = cur->_next;
			}
			cout << endl;
		}
	}
	T& Front(){
		return _head->_data;
	}
	T& Back(){
		return _tail->_data;
	}
	size_t Size(){
		if (!Empty()){
			size_t size = 0;
			Node<T>* cur = _head;
			while (cur){
				size++;
				cur = cur->_next;
			}
			return size;
		}
		return 0;
	}
	bool Empty(){
		if (_head)
			return false;
		return true;
	}

protected:
	Node<T>* _head;
	Node<T>* _tail;
//	size_t _size;
};