#pragma once

#include <iostream>
using namespace std;

typedef int DataType;

struct Node{
	Node(const DataType &d)
	:_data(d), _next(NULL)
	{}
	DataType _data;
	Node * _next;
};

class SList{
	friend ostream& operator<<(ostream& os, const SList& s);
	//friend ostream& operator<<(ostream& os, const Node& s);
public:
	SList()
		: _head(NULL), _tail(NULL)
	{}
	SList(const SList& s){
		Node *cur = s._head;
		while (cur){
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	//SList& operator=(SList s){
	//	swap(_head, s._head);
	//	swap(_tail, s._tail);
	//	return *this;
	//}
	~SList(){
		if (_head == NULL)
			return;
		Node *cur = _head;
		while (cur->_next != NULL){
			Node *del = cur;
			cur = cur->_next;
			delete del;
		}
		delete cur;
		_head = NULL;
		_tail = NULL;
	}
public:
	void PushBack(const DataType& d);
	void PopBack();
	void PushFront(const DataType& d);
	void PopFront();

	Node* Find(const DataType& d);
	void Insert(Node* pos, const DataType& index);
	void Sort();

	Node* CheckLoop();
	Node* GetEntryNode(Node* meet);
	bool CheckCross(SList& s);
	void Reverse();

	Node* GetMidNode();
	Node* GetMidNode(Node* begin, Node* end);
	Node* SList::BinarySearch();
private:
	DataType _data;
	Node* _head;
	Node* _tail;
};