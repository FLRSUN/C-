#include <iostream>

using namespace std;
typedef int DateType;

class Arreay{
public:
	Arreay(int sz = 10)
		:_parr(new DateType[sz])
		,_size(sz){
		if (_size > 0){
			_parr = new DateType[_size];
		}
	
	}
	Arreay(const Arreay &p){	
			this->_parr = new DateType[_size];
			memcpy(_parr, p._parr, p._size * sizeof(DateType));
	}
	Arreay& operator=(Arreay &a){
		_parr = new DateType[a._size];
		memcpy(_parr, a._parr, a._size * sizeof(DateType));
		return *this;
	}
	DateType& operator[](int sz){
		_parr[sz] = sz;
		return _parr[sz];
	}
	~Arreay(){
		if (_parr){

			delete[] _parr;
			_parr = NULL;
			_size = 0;
		}
	}
private:
	DateType *_parr;
	int _size;
};

int main(){
	Arreay arr1;
	int i = 0;
	for (i = 0; i < 10; i++){
		arr1[i] = i;
	}
	Arreay arr2(arr1);
	//arr2 = arr1;
	return 0;
}