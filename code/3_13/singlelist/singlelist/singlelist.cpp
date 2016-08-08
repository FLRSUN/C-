#include "singlelist.h"
using namespace std;

ostream& operator<<(ostream& os, const SList& s){
	Node* cur = s._head;
	while (cur != NULL){
		os << cur->_data;
		if (cur->_next != NULL)
			cout << "->";
		cur = cur->_next;
	}
	cout << "  OVER" << endl;
	return os;
}
//ostream& operator<<(ostream& os, const Node& node){
//	os << node._data << endl;
//	return os;
//}


void SList::PushBack(const DataType& d){
	Node *newnode = new Node(d);
	if (_head == NULL){
		_tail = newnode;
		_head = _tail;
	}
	else{
		_tail->_next = newnode;
		_tail = newnode;
	}
}
void SList::PopBack(){
	
	if (_head == NULL)
		return;
	else{
		Node *cur = _head;
		while (cur->_next != _tail){
			cur = cur->_next;
		}
		delete _tail;
		_tail = cur;
		cur->_next = NULL;
	}
}
void SList::PushFront(const DataType& d){
	Node* newnode = new Node(d);
	if (_head == NULL){
		_tail = newnode;
		_head = _tail;
	}
	else{
		newnode->_next = _head;
		_head = newnode;
	}
}
void SList::PopFront(){
	if (_head == NULL)
		return;
	else{
		Node *del = _head;
		_head = del->_next;
		delete del;
	}
}

Node* SList::Find(const DataType& d){
	Node* cur = _head;
	while (cur){
		if (cur->_data == d)
			return cur;
		cur = cur->_next;
	}	
}
void SList::Insert(Node* pos, const DataType& index){
	Node* in = new Node(index);
	if (pos == _tail){
		_tail->_next = in;
		_tail = in;
		return;
	}
	in->_next = pos->_next;
	pos->_next = in;
}

void SList::Sort(){
	Node *cur = _head;
	Node *q = cur;
	for (cur; cur != NULL; cur = cur->_next){
		for (q = cur->_next; q != NULL; q = q->_next){
			if (q->_data < cur->_data){
				DataType temp = q->_data;
				q->_data = cur->_data;
				cur->_data = temp;
			}
		}
	}
}

Node* SList::CheckLoop(){
	Node* slow = _head;
	Node* fast = _head;
	while (fast->_next){
		if (fast->_next->_next){
			fast = fast->_next->_next;
			slow = slow->_next;
			if (slow == fast)
				return slow;
		}
		else
			fast = fast->_next;
	}
}

Node* SList::GetEntryNode(Node* meet){
	Node* entry = _head;
	Node* p = meet;
	while (entry != p){
		entry = entry->_next;
		p = p->_next;
	}
	return entry;
}

bool SList::CheckCross(SList& s){
	Node* h1 = _head;
	Node* h2 = s._head;
	while (h1 && (h1->_next)){
		h1 = h1->_next;
	}
	while (h2 && (h2->_next)){
		h2 = h2->_next;
	}
	return (h1 == h2);
}
void SList::Reverse(){
	Node* cur = _head;
	Node* p = cur;
	_tail = _head;
	Node* newnode = NULL;
	while (cur){
		p = cur;
		cur = cur->_next;
		p->_next = newnode;
		newnode = p;
	}
	_head = newnode;
}

Node* SList::GetMidNode(){
	if (_head == NULL)
		return NULL;
	Node* fast = _head;
	Node* mid = _head;
	//while (fast->_next != NULL){        //奇数
	//	if (fast->_next->_next != NULL) //偶数
	//	{
	//		fast = fast->_next->_next;
	//		mid = mid->_next;
	//	}
	//	else{
	//		fast = fast->_next;
	//	}	
	//}
	while (fast != _tail){        //奇数
		if (fast->_next != _tail) //偶数
		{
			fast = fast->_next->_next;
			mid = mid->_next;
		}
		else{
			fast = fast->_next;
		}
	}
	return mid;
}

Node* SList::GetMidNode(Node* begin, Node* end){
	if (_head == NULL)
		return NULL;
	Node* fast = begin;
	Node* mid = begin;
	while (fast != end){        //奇数
		if (fast->_next != end) //偶数
		{
			fast = fast->_next->_next;
			mid = mid->_next;
		}
		else{
			fast = fast->_next;
		}
	}
	return mid;
}