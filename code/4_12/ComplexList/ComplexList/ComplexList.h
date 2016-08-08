#pragma once
#include <iostream>
using namespace std;

template <class T>
struct ComplexListNode{
	ComplexListNode(const T& d)
	:_data(d),_next(NULL),_random(NULL)
	{}
	T _data;
	ComplexListNode<T>* _next;
	ComplexListNode<T>* _random;
};

template <class T>
class ComplexList{
public:
	ComplexList()
	:_head(NULL),_tail(NULL)
	{}
	ComplexList(ComplexList<T>& cp){
		DoubleComplexList(cp);  //复制节点，子节点连接在父节点之后；
		CopyRandom(cp);         //复制_random;
		CopyComplexList(cp);    //拆分cp链表，获得新链表；
	}
	~ComplexList(){
		if (_head){
			ComplexListNode<T>* cur = _head;
			while (cur->_next != NULL){
				ComplexListNode<T>* del = cur;
				cur = cur->_next;
				delete del;
			}
			delete cur;
			_head = _tail = NULL;
		}
	}
	void PushBack(const T& d){
		if (_head == NULL){
			_head = _tail = new ComplexListNode<T>(d);
		}
		else{
			_tail->_next = new ComplexListNode<T>(d);
			_tail = _tail->_next;
		}
	}
	void PopBack(){
		if (_head != _tail){
			ComplexListNode<T>* cur = _head;
			while (cur->_next != _tail){
				cur = cur->_next;
			}
			delete _tail;
			_tail = cur;
			_tail->_next = NULL;
		}
		else if (_head == _tail){
			delete _head;
			_head = _tail = NULL;
		}
	}
	ComplexListNode<T>* GetComplexListNode(const T& d){
		if (_head){
			ComplexListNode<T>* cur = _head;
			{
				while (cur->_data != d){
					cur = cur->_next;
				}
			}
			return cur;
		}
	}
protected:
	void DoubleComplexList(ComplexList<T>& cp){
		ComplexListNode<T>* cur = cp._head;
		while (cur){
			ComplexListNode<T>* NewNode = new ComplexListNode<T>(cur->_data);
			NewNode->_next = cur->_next;
			cur->_next = NewNode;
			cur = cur->_next->_next;
		}
	}
	void CopyRandom(ComplexList<T>& cp){
		if (cp._head){
			ComplexListNode<T>* cur = cp._head;
			while (cur){
				if (cur->_random != NULL){
					cur->_next->_random = cur->_random->_next;
				}
				cur = cur->_next->_next;
			}
		}
	}
	void CopyComplexList(ComplexList<T>& cp){
		ComplexListNode<T>* cur = cp._head;    //控制cp链表的当前节点
		_head = cur->_next;
		cur->_next = cur->_next->_next;        //cur指向第二个节点，并且跳过新链表的头节点
		cur = cur->_next;
		ComplexListNode<T>* cur2 = _head;	   //控制新链表的当前结节点
		while (cur != cp._tail){
			cur2->_next = cur->_next;          //连接新链表
			cur2 = cur2->_next;                //cur指向新节点
			cur->_next = cur->_next->_next;    //连接cp链表
			cur = cur->_next;                  //移动至下一节点
		}
		cur2->_next = cp._tail->_next;
		cp._tail->_next = NULL;
		_tail = cur2->_next;
		_tail->_next = NULL;
	}
protected:
	ComplexListNode<T>* _head;
	ComplexListNode<T>* _tail;
};