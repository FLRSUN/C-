#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

#define DEFAULT_CAPACITY 2
class String{
	friend ostream& operator<<(ostream& os, const String& str);
public:
	String(char *str = "")

		:_str(new char[sizeof(str)+1 + DEFAULT_CAPACITY])
		, _size(strlen(str))
		, _capacity(strlen(str) + 1 + DEFAULT_CAPACITY){
		strcpy(_str, str);
	}
	String( String &str)
	:_str(NULL),_size(str._size),_capacity(str._capacity){
		swap(_str,str._str);
	}
	String& operator=(String& str){
		swap(_size,str._size);
		swap(_capacity, str._capacity);
		swap(_str,str._str);
		return *this;
	}
	~String(){
		if (_str != NULL){
			_size = 0;
			_capacity = 0;
			delete[] _str;
		}
	}
public:
	bool OverCapacity(char *str){
		if (_capacity < (strlen(str) + strlen(_str) + 2  ))
			return true;
		else
			return false;
	}
	void IncreaseCapacity(char *str){
		char* temp = new char[strlen(_str) + strlen(str) + 2];
		_capacity = _capacity + strlen(str);
		strcpy(temp,_str);
		swap(_str,temp);
		delete[] temp;
	}
public:
	void insert(int pos, char ch){
		if (OverCapacity(&ch))
			IncreaseCapacity(&ch);
		int end = strlen(_str);
		char *temp = _str;
		while (*temp){
			temp++;
		}
		while (end >= pos){
			*(temp + 1) = *temp;
			temp--;
			end--;
		}
		_str[pos] = ch;
		_size++;		
	}
	void insert(int pos, char* str){
		if (OverCapacity(str))
			IncreaseCapacity(str);
		int end = strlen(_str);
		char *temp = _str;
		while (*temp){
			temp++;
		}
		while (end >= pos){
			*(temp + strlen(str)) = *temp;
			temp--;
			end--;
		}
		strncpy((_str + pos), str,strlen(str));
		_size += strlen(str);
	}
	void insert(int pos, const String &str){

	}
	void PushBack(char* ch){
		insert(_size,ch);
	}
private:
	char *_str;
	int _size;
	int _capacity;
};

ostream& operator<<(ostream& os, const String& str){
	os << str._str << endl;
	os << str._size << endl;
	os << str._capacity << endl;
	return os;
}

int main(){
	String str1("worde!");
	cout << str1;
	str1.insert(2, 'f');
	//str1.PushBack("a");
	cout << str1;
	/*String str2(str1);
	cout << str2;
	String str3;
	cout << str3;
	str3 = str2;
	cout << str3;*/
	getchar();
	return 0;
}