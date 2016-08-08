//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Sqlist{
//public:
//	Sqlist<T>()
//		: _size(0), _capacity(10), _data(new T[_capacity])
//	{}
//	~Sqlist<T>(){
//		delete[] _data;
//	}
//private:
//	T* _data;
//	int _size;
//	int _capacity;
//};
//
//
//int main(){
//	Sqlist<int>s;
//	return 0;
//}

namespace N1
{
	int a;
	int b;
	namespace N2
	{
		int c;
		int d;
		void fun()
		{
			N1::a = 10;
		}
	}
}