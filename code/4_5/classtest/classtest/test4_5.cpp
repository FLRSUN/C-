#include <iostream>
#include <fstream>
using namespace std;


class A{
	int a;
};

void WriteFile(const char* fileName)
{
	// 1.打开⽂件
	ofstream ofs(fileName, ofstream::out);
	// 2.写⼊⽂件
	string buf("hello\n");
	ofs.write(buf.c_str(), buf.length());
	ofs.put('w');
	ofs.put('o');
	ofs.put('r');
	ofs.put('l');
	ofs.put('d');
	ofs.close();
}
void ReadFile(const char* fileName)
{
	// 1.打开⽂件
	ifstream ifs(fileName, ifstream::in);
	// 2.⼀个字符⼀个字符读取⽂件
	char c;
	cout << "get:";
	while (ifs.get(c))
		cout << c;
	cout << endl;
	ifs.close();
	cout << "------------------------"<<endl;
	// 3.⼀⾏⼀⾏读取⽂件
	char buf[256];
	ifs.open(fileName, ifstream::in);
	//ifs.seekg(ifs.beg);                   //重新设置文件指针  begin end 相对位置
	ifs.seekg(ios_base::beg);
	ifs.getline(buf, 256);
	cout << "GetLine:" << buf << endl;
	ifs.getline(buf, 256);
	cout << buf << endl;
}

void Test1()
{
	int i = 1;
	// 隐式类型转换
	double d = static_cast<int>(i);  
	printf("%d, %.2f\n", i, d);
	int* p = &i;
	// 显⽰的强制类型转换
	int address = (int)p;
	printf("%x, %d\n", p, address);
}
void Test2()
{
	int i = 1;
	double d = static_cast< double>(i);
	printf("%d, %.2f\n", i, d);
}
typedef void(*FUNC)(); //函数指针
int DoSomething(int i)
{
	cout << "DoSomething:"<<i << endl;
	return 0;
}
void Test3()
{
	//
	// reinterpret_cast可以编译器以FUNC的定义⽅式去看待DoSomething函数
	// 所以⾮常的BUG，下⾯转换函数指针的代码是不可移植的，所以不建议这样⽤
	// C++不保证所有的函数指针都被⼀样的使⽤，所以这样⽤有时会产⽣不确定的结果
	//
	FUNC f = reinterpret_cast< FUNC>(DoSomething);
	f();
}
void Test7()
{
	volatile const int a = 2;
	int* p = const_cast< int*>(&a);
	*p = 3;
	cout << a << endl;
}

class A{
public:
	int _a;
};

class B :public A{
public:
	int _b;
};

void Test(){
	A a;
	B b;
	A* pa = &a;
	B* pb = &b;

	//pb = pa; NO

	pb = (B*)pa;

	//pb->_b = 10;  NO
}

int main(){

	//cerr << "cerr" << endl;

	//clog << "clog" << endl;
	//A a;
	//cout << a <<endl;;
	//WriteFile("Text.txt");
	//ReadFile("Text.txt");
	Test();
	int a = 1;
	//const int b = a;
	//const int c = 3;

	//int b = 2;
	//int *const p = &a;
	//const int *p1 = &a;
	//int *p2 = &b;

	getchar();
	return 0;
}