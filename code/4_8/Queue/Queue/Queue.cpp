#include"Queue.h"

void test(){
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Print();
	//q.Pop();
	//q.Pop();
	//q.Pop();
	//q.Pop();
	//q.Pop();
	//q.Print();
	Queue<int> q1;
	int ret = q.Back();
	size_t ret1 = q1.Size();
	cout << ret1;
}

int main(){
	test();
	getchar();
	return 0;
}