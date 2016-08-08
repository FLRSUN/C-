#include "doublelist.h"

ostream& operator<<(ostream& os, const DList& s){
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

void DList::PushBack(const DataType& d){
	Node* cur = new Node(d);
	if (_head == NULL){
		_tail = cur;
		_head = _tail;
	}
	else{
		_tail->_next = cur;
		cur->_prev = _tail;
		_tail = cur;
	}
}
void DList::PopBack(){
	if (_head == NULL)
		return;
	if (_head == _tail){
		delete _tail;
		_head = NULL;
		_tail = NULL;
	}
	else{
		Node* del = _tail;
		_tail = del->_prev;
		delete del;
		_tail->_next = NULL;
	}
}
void DList::PushFront(const DataType& d){
	Node* in = new Node(d);
	if (_head == NULL){
		_head = in;
		_tail = _head;
	}
	else{
		in->_next = _head;
		_head = in;
	}

}
void DList::PopFront(){
	if (_head == NULL)
		return;
	if (_head == _tail){
		delete _tail;
		_head = NULL;
		_tail = NULL;
	}
	else{
		_head = _head->_next;
		delete _head->_prev;
		_head->_prev = NULL;
	}
}

Node* DList::Find(const DataType& d){
	Node* cur = _head;
	while (cur){
		if (cur->_data == d)
			return cur;
		cur = cur->_next;
	}
}
void DList::Insert(Node* pos, const DataType& index){
	Node* in = new Node(index);
	if (pos == _tail){
		pos->_next = in;
		in->_prev = pos;
		_tail = in;
		return;
	}
	in->_next = pos->_next;
	pos->_next->_prev = in;
	pos->_next = in;
	in->_prev = pos;
}
void DList::Sort(){
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
void DList::ReMove(const DataType& d){
	Node *cur = _head;
	if (_head->_data == d){
		_head = _head->_next;
		delete _head->_prev;
		_head->_prev = NULL;
		return;
	}
	if (_tail->_data == d){
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
		return;
	}
	Node *p = NULL;
	Node *q = NULL;
	while (cur){
		if (cur->_data == d){
			q = cur->_next;
			p->_next = q;
			q->_prev = p;
			delete cur;
			return;
		}
		p = cur;
		cur = cur->_next;
	}	
}
void DList::ReMoveALL(const DataType& d){
	Node *cur = _head;
	if (_head->_data == d){
		_head = _head->_next;
		delete _head->_prev;
		_head->_prev = NULL;
		return;
	}
	if (_tail->_data == d){
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
		return;
	}
	Node *p = NULL;
	Node *q = NULL;
	while (cur){
		if (cur->_data == d){
			q = cur->_next;
			p->_next = q;
			q->_prev = p;
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
		p = cur;
	    cur = cur->_next;
	}
}

Node* DList::CheckLoop(){
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
Node* DList::GetEntryNode(Node* meet){
	Node* entry = _head;
	Node* p = meet;
	while (entry != p){
		entry = entry->_next;
		p = p->_next;
	}
	return entry;
}
bool DList::CheckCross(DList& s){
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
void DList::Reverse(){
	Node* cur = _head;
	Node* p = cur;
	_tail = p;
	Node* newnode = NULL;
	while (cur){
		p = cur;
		cur = cur->_next;
		p->_next = newnode;
		if (p != _head)
		   newnode->_prev = p;
		newnode = p;
	}
	_head = newnode;
}