#include "singlelist.h"
#include <iostream>
using namespace std;

void test(){
	SList s;
	SList s1;
	s.PushFront(1);
	s.PushFront(2);
	s.PushFront(3);
	s.PushFront(4);
	s.PushFront(6);
	s.PushFront(7);
	s.PushFront(8);
	s.PushFront(9);
	cout << s;
	s.Reverse();
	cout << s;
	//s.Sort();
	//s1.PushFront(1);
	//s1.PushFront(2);
	//s1.PushFront(3);
	//s1.PushFront(4);
	//s1.PushFront(6);
	//s1.PushFront(7);
	//s1.PushFront(8);
	//s1.PushFront(9);
	//s1.Sort();
	//cout << s << s1;
	//Node* p = s.Find(4);
	//Node* q = s1.Find(9);
	//q->_next = p;
	//int r = s.CheckCross(s1);
	//Node* ret = s.CheckLoop();
	//Node* entry = s.GetEntryNode(ret);
	//cout << s <<endl;
	//s.PopFront();
	//cout << s;
	//Node* ret = s.Find(1);
	//s.Insert(ret, 5);
	//cout << s;

	//SList s2;
	//s2 = s;
	//cout << s2;
	//cout << s;
}

void test1(){
	SList s;
	s.PushFront(1);
	s.PushFront(2);
	s.PushFront(3);
	s.PushFront(4);
	s.PushFront(5);
	s.PushFront(6);
	s.PushFront(7);
	s.PushFront(8); 
	s.PushFront(9);
	Node* q = s.GetMidNode();
	cout << s << endl;
}
int main(){
	test1();
	getchar();
	return 0;
}