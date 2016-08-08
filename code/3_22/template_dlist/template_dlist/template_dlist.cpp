#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node{
	Node(const T& d)
	:_data(d)
	,_next(NULL)
	,_prev(NULL)
	{}
	Node<T>* _next;
	Node<T>* _prev;
	T _data;
};

template <typename T>
class DList{
public:
	DList();
	~DList();
	DList(const DList<T>& s);

	void print();
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();

	Node<T>* Find(const T& d);
	void Insert(Node<T>* pos, const T& index);
	void Sort();
	void ReMove(const T& d);
	void ReMoveAll(const T& d);

	Node<T>* CheckLoop();
	Node<T>* GetEntryNode(Node<T>* meet);
	bool CheckCross(DList<T>& s);
	void Reverse();
private:
	Node<T>* _head;
	Node<T>* _tail;
};
template <typename T>
DList<T>::DList()
:_head(NULL), _tail(NULL)
{}
template <typename T>
DList<T>::~DList(){
	while (_head){
		Node<T>* del = _head;
		_head = del->_next;
		delete del;
	}
	_head = NULL;
	_tail = NULL;
}
//template <typename T>
//DList<T>::DList(const DList<T>& s){
//	Node<T>* _head = new Node<T>(s._head->_data);
//	Node<T>* _tail = new Node<T>(s._tail->_data);
//	if (s._head == NULL){
//		_head = NULL;
//		_tail = NULL;
//		return;
//	}
//	_head->_data = s._head->_data;
//	Node<T>* scur = s._head;
//	Node<T>* precur = _head;
//	while (scur){
//		Node<T>* cur = new Node<T>(scur->_data);
//		precur->_next = cur;
//		cur->_prev = precur;
//		precur = cur;
//		scur = scur->_next;
//	}
//	_tail = precur;
//}
template <typename T>
void DList<T>::PushBack(const T& d){
	Node<T>* newnode = new Node<T>(d);
	if (_head == NULL){
		_head = newnode;
		_tail = _head;
	}
	else{
		_tail->_next = newnode;
		newnode->_prev = _tail;
		_tail = newnode;
	}
}
template <typename T>
void DList<T>::PopBack(){
	if (_head->_next == NULL){
		delete _head;
		_head = NULL;
		_tail = NULL;
		return;
	}
	Node<T>* del = _tail;
	_tail = del->_prev;
	delete del;
	_tail->_next = NULL;
}
template <typename T>
void DList<T>::PushFront(const T& d){
	Node<T>* newnode = new Node<T>(d);
	if (_head == NULL){
		_head = newnode;
		_tail = _head;
	}
	else{
		newnode->_next = _head;
		_head->_prev = newnode;
		_head = newnode;
	}

}
template <typename T>
void DList<T>::PopFront(){
	if (_head->_next == NULL){
		delete _head;
		_head = NULL;
		_tail = _head;
		return;
	}
	Node<T>* del = _head;
	_head = del->_next;
	delete del;
	_head->_prev = NULL;
}
template <typename T>
void DList<T>::print(){
	Node<T>* cur = _head;
	while (cur){
		cout << cur->_data;
		if (cur->_next != NULL)
			cout << "->";
		cur = cur->_next;
	}
	cout <<endl<< "over" << endl;
}
template <typename T>
Node<T>* DList<T>::Find(const T& d){
	Node<T>* cur = _head;
	while (cur){
		if (cur->_data == d)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
template <typename T>
void DList<T>::Insert(Node<T>* pos, const T& index){
	if (pos == _tail){
		PushBack(index);
		return;
	}
	Node<T>* in = new Node<T>(index);
	in->_next = pos->_next;
	pos->_next->_prev = in;
	pos->_next = in;
	in->_prev = pos;

	
}
template <typename T>
void DList<T>::Sort(){
	Node<T>* cur = _head;
	Node<T>* p = NULL;
	for (cur; cur != NULL; cur = cur->_next){
		for (p = cur->_next; p != NULL; p = p->_next){
			if (cur->_data > p->_data){
				T temp = cur->_data;
				cur->_data = p->_data;
				p->_data = temp;
			}
		}
	}
}
template <typename T>
void DList<T>::ReMove(const T& d){
	Node<T>* cur = NULL;
	if ((_head->_data == d) /*&& (_tail->_data == d)*/){
		cur = _head;
		_head = cur->_next;
		delete cur;
		_head->_prev = NULL;
		return;
	}
	cur = _head;
	while (cur){
		if ((cur == _tail)){
			_tail = cur->_prev;
			delete cur;
			_tail->_next = NULL;
			return;
		}
		if (cur->_data == d){
			Node<T>* del = cur;
			cur = cur->_next;
			del->_prev->_next = cur;
			cur->_prev = del->_prev;
			delete del;
			return;
		}
		cur = cur->_next;
	}
}
template <typename T>
void DList<T>::ReMoveAll(const T& d){
	char flage = 0;
	Node<T>* cur = NULL;
	if (_head->_data == d){
		cur = _head;
		_head = cur->_next;
		delete cur;
		_head->_prev = NULL;
		return;
	}
	cur = _head;
	while (cur){
		flage = 0;
		if ((cur == _tail)&&(_tail->_data == d)){
			_tail = cur->_prev;
			delete cur;
			_tail->_next = NULL;
			return;
		}
		if (cur->_data == d){
			flage = 1;
			Node<T>* del = cur;
			cur = cur->_next;
			del->_prev->_next = cur;
			cur->_prev = del->_prev;
			delete del;
		}
		if (flage != 1)
			cur = cur->_next;
	}
}
template <typename T>
Node<T>* CheckLoop(){
	Node<T>* slow = _head;
	Node<T>* fast = _head;
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
template <typename T>
Node<T>* DList<T>::GetEntryNode(Node<T>* meet){
	Node<T>* entry = _head;
	Node<T>* p = meet;
	while (entry != p){
		entry = entry->_next;
		p = p->_next; 
	}
	return entry;
}
template <typename T>
bool DList<T>::CheckCross(DList<T>& s){
	Node<T>* h1 = _head;
	Node<T>* h2 = s._head;
	while (h1 && (h1->_next)){
		h1 = h1->_next;
	}
	while (h2 && (h2->_next)){
		h2 = h2->_next;
	}
	return (h1 == h2);
}
template <typename T>
void DList<T>::Reverse(){
	if (_head == _tail)
		return;
	Node<T>* cur = _head;
	Node<T>*exchange = cur;
	Node<T>* temp;
	while (cur){
		exchange = cur;
		cur = cur->_next;		
		temp = exchange->_next;
		exchange->_next = exchange->_prev;
		exchange->_prev = temp;
	}
	 temp = _head;
	_head = _tail;
	_tail = temp;

}
void test1(){
	DList<string> d;
	d.PushFront("11111");
	d.PushFront("22222");
	d.PushFront("33333");
	d.PushFront("44444");
	d.print();
	d.PopBack();
	d.PopBack();
	d.PopBack();
	d.PopBack();
	d.print();
}
void test2(){
	DList<int> d;
	d.PushBack(6);
	d.PushBack(2);
	d.PushBack(3);
	d.PushBack(4);
	d.PushBack(5);
	d.PushBack(4);

	d.print();
	Node<int>* ret = d.Find(6);
	d.Insert(ret, 4);
	d.Sort();
	d.print();
	d.ReMove(4);
	d.print();
}
void test3(){
	DList<int> d;
	d.PushBack(1);
	d.PushBack(2);
	d.PushBack(3);
	d.PushBack(4);
	d.PushBack(5);
	d.print();
	d.Reverse();
	d.print();
}
void test4(){
	DList<int> d;
	d.PushBack(2);
	d.PushBack(3);
	d.PushBack(4);
	d.print();
	DList<int> d1(d);
	d1.print();
}
int main(){
	test4();
	getchar();
	return 0;
}