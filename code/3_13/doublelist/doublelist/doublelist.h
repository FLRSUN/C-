#pragma once

#include <iostream>
using namespace std;

typedef int DataType;

struct Node{
	Node(const DataType &d)
	:_next(NULL), _prev(NULL), _data(d)
	{}
	DataType _data;
	Node* _next;
	Node* _prev;
};

class DList{
	friend ostream& operator<<(ostream& os, const DList& s);
	//friend ostream& operator<<(ostream& os, const Node& s);
public:
	DList()
	:_head(NULL),_tail(NULL)
	{}
	~DList(){
		while (_head){
			Node* del = _head;
			_head = del->_next;
			delete del;
		}
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
	void ReMove(const DataType& d);
	void ReMoveALL(const DataType& d);

	Node* CheckLoop();
	Node* GetEntryNode(Node* meet);
	bool CheckCross(DList& s);
	void Reverse();

private:
	Node* _head;
	Node* _tail;
};