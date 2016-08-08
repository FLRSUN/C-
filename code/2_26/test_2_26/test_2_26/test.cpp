#include <iostream>
using namespace std;

////函数重载
//int add(int a, int b){
//	return a + b;
//}
//
//float add(float a, float b){
//	return a + b;
//}
//
//int main(){
//	//int a = 10;
//	//int b = 20;
//	float a = 1.0;
//	float b = 2.5;
//	cout << "a + b = " << a + b << endl;
//	getchar();
//	return 0;
//}

////引用
//void swap(int& a, int& b){
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//	int &c = a;
//	cout << "old a = " << a << " b = " << b << endl;
//	swap(a, b);
//	cout << "new a = " << a << " b = " << b << endl;
//	getchar();
//	return 0;
//}

////class
//
//class Date{
//public:
//	void Display(int year, int month, int day);
//	//void Display(int year,int month,int day){
//	//	cout << year << "-" << month << "-" << day << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//void Date::Display(int year,int month,int day){
//	cout << year << "-" << month << "-" << day << endl;
//}
//
//class A {
//	char a;
//	double b;
//};
//class B{
//	char a;
//	A b;
//	char c;
//};
//int main(){
//	/*Date d;
//	d.Display(2013,2,23);*/
//	cout << "sizeof(A) = " << sizeof(A) << endl;
//	cout << "sizeof(B) = " << sizeof(B) << endl;
//	getchar();
//	return 0;
//}

 //构造函数
class Date{
public:
	Date(int year=1994,int month=3,int day=5){  //全缺省 也可不缺省，也可无参数 
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d1;
	Date d2(2016, 2, 27);
	getchar();
	return 0;
}