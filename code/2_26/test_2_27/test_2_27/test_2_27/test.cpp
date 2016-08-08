#include <iostream>

using namespace std;

class Complex{
public:
	Complex(int real=1,int imag=1){
		cout << "构造函数" << endl;
		_real = real;
		_imag = imag;
	}
	Complex(const Complex &d){
		cout << "拷贝构造函数" << endl;
		_real = d._real;
		_imag = d._imag;
	}
	Complex& operator=(Complex &d){
		cout << "=重载" << endl;
		if (this != &d){
			this->_real = d._real;
			this->_imag = d._imag;
		}
		return *this;
	}
	Complex& operator+(Complex &d){
		cout << "+重载" << endl;
		if (this != &d){
			this->_imag = this->_imag + d._imag;
			this->_real = this->_real + d._real;
		}
		return *this;
	}
	Complex& operator*(Complex &d){
		cout << "*重载" << endl;
		if (this != &d){
			this->_real = this->_real * d._real - this->_imag * d._imag;
			this->_imag = this->_real * d._imag + this->_imag * d._real;
		}
		return *this;
	}
	~Complex(){
		cout << "析构函数" << endl;
	}
private:
	int _real;
	int _imag;
};
int main(){
	{
		Complex d1(2,1);
		Complex d2(1, 2);
		Complex d3;
		d3 = d2;
		Complex d4;
		d4 = d3 * d1;
	}
	getchar();
	return 0;
}