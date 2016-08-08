#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class String{
	friend ostream& operator<<(ostream& os, const String &str);
public:
	String(char *str = "")
	:_str(new char[strlen(str) + 5]){
		*(int *)(_str) = 1;
		_str += 4;
		strcpy(_str,str);
	}
	String(const String& str){			
		(*(int *)(str._str - 4))++;
		_str = str._str;
		}
	String& operator=(const String& str){
		if (this != &str){
			if (--(*(int *)(_str - 4)) == 0){
				delete[](_str - 4);
			}			
			_str = str._str;
			++(*(int *)(_str - 4));			
		}
		return *this;
	}
	~String(){
		if (_str != NULL){
			if (--(*(int *)(_str - 4)) == 0){
				_str -= 4;
				delete[] _str;
			}
		}
	}
private:
	char *_str;
};

ostream& operator<<(ostream& os, const String &str){
	os << str._str << endl;
	return os;
}

int main(){

	String str("fghf");
	String str2(str);
	String str3;
	str3 = str;
    cout << str3;
	getchar();
	return 0;
}