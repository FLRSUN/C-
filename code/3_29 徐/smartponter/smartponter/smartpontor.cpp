#include <string>
#include"smart.h"


struct A{
	int a = 10;
};

void test1(){

	AutoPtr<int> ap(new int(1));
	AutoPtr<int> ap1(ap);

	//ap1 = ap;
	*ap1 = 10;
	//AutoPtr<int> ap2(ap1);
	AutoPtr<A> ap3(new A);
	ap3->a = 30;
}

void test2(){
	ScopedPtr<int> sp(new int(1));
	ScopedPtr<int> sp1;

}
void test3(){
	SharePtr<int> sp(new int(1));
	SharePtr<int> sp1(sp);
	SharePtr<int> sp5(sp);
	SharePtr<int> sp6(sp);
	SharePtr<int> sp7(sp);

	SharePtr<int> sp3(new int(2));
	SharePtr<int> sp4(sp3);
	SharePtr<int> sp8(sp3);
	SharePtr<int> sp9(sp3);
	SharePtr<int> sp10(sp3);

	//sp3 = sp1;
	//*sp3 = 20;
}

void test4(){
	ScopedArry<int> sa(new int[10]);
	int i = 0;
	sa[0] = 1;
	for (i = 0; i < 10; i++){
		sa[i] = i;
	}
}
void test5(){
 	SharedArry<int> sa(new int[10]);
	SharedArry<int> sa1(sa);
	sa[0] = 10;
	SharedArry<int> sa2(new int[10]);
	SharedArry<int> sa3(sa2);
	sa2 = sa;
}

//void test(){
//	SharedPtr sp(new int(2));
//}
void test(){
	AutoPtr<int> ap1(new int(1));
	//DoSomthing();
	{
		AutoPtr<int> ap2(ap1);
	}
	*ap1._ptr = 2;
}
int main(){
	test();
	return 0;
}