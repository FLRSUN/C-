#include "Stack.h"

typedef unsigned long long ULL;
void test(){
	Stack<int> s;
	s.Push(10);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(-10);
	s.Push(6);
	s.Push(-5);
	s.Push(8);
	s.Push(-1);
	s.Push(1);

	//s.Pop();
	cout << "s : " << endl;
	s.Print();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();

	//s.Pop();


	s.Print();
	Stack<int> s2;
	s2 = s;
	//cout << "s2 : ";
	//s2.Print();
	cout << "min:"<<s2.GetMin() << endl;
	cout << "min:" << s2.Getmin() << endl;


}
ULL Fib(ULL n){
	return n < 2 ? n : (Fib(n - 1) + Fib(n - 2));
}
ULL Fib1(ULL n){
	if (n < 2)
		return n;
	int a = 1;
	int b = 1;
	int c = 1;
	for (int i = 3; i < n + 1; ++i){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
void test1(){
	stack<int>  a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);

}
int main(){
	test();
	//cout << Fib1(52) << endl;
	getchar();
	return 0;
}