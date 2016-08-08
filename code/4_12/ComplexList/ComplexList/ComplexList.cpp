#include "ComplexList.h"

void test(){
	ComplexList<int> a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
	a.PushBack(6);
	a.PushBack(7);
	ComplexListNode<int>* r1 = a.GetComplexListNode(2);
	ComplexListNode<int>* r2 = a.GetComplexListNode(5);
	r1->_random = r2;

	ComplexList<int> s(a);

	//a.PopBack();
	//a.PopBack();
	//a.PopBack();
 //   ComplexListNode<int>* r1 = a.GetComplexListNode(2);
	//ComplexListNode<int>* r2 = a.GetComplexListNode(5);
	//r1->_random = r2;
}

int main(){
	test();
	return 0;
}