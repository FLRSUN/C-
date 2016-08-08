#include "doublelist.h"

void test(){
	DList d;
	
	d.PushFront(1);

	d.PushFront(2);
	d.PushFront(3);
	d.PushFront(4);
	d.PushFront(5);
	cout << d;
	d.Reverse();
	cout << d;
	//d.Sort();
	//cout << d;
	//Node *ret = d.Find(4); 
	//d.Insert(ret, 5);
	//cout << d;
	//d.ReMoveALL(3);
	//cout << d;
	//d.PopFront();
	//cout << d;
	//d.PopFront();
	//cout << d;
	//d.PopFront();
	//cout << d;
	//d.PopFront();
	//cout << d;
}

int main(){
	test();
	getchar();
	return 0;
}