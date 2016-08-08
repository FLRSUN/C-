#define _CRT_SECURE_NO_WARNINGS 1;

#include <iostream>
#include <assert.h>

using namespace std;

class String{
	friend ostream& operator<<(ostream& os, const String& str); 
public:
	String(char * str = "")
		:_str(new char [sizeof(str) + 1]){
		strcpy(_str, str);
	}
	//String(const String &str)                 //´«Í³Ð´·¨
	//:_str(new char[(sizeof(str._str) + 1)]){
	//	strcpy(_str, str._str);
	//}
	//String& operator=(const String& str){
	//	if ( this != &str){
	//		delete[] _str;
	//		_str = new char[sizeof(str._str) + 1];
	//		strcpy(_str, str._str);
	//	}
	//}
	String(const String &str)
	:_str(NULL){
		String temp(str._str);
		swap(_str,temp._str);
	}
	String& operator=(String str){
		swap(_str, str._str);
		return *this;
	}
	~String(){
		if (_str != NULL){
			delete[] _str;
			_str = NULL;
		}
	}
public:
	bool operator==(const String & s){
		if (SameStr(_str,s._str))
			return true;
		else
			return false;
	}
	bool operator>(const String & s){
		if (Compare(_str, s._str))
			return true;
		else
			return false;
	}
	bool operator<(const String & s){
		return ((_str > s._str));
	}	
	void PushBack(char ch){
		char *str = new char[sizeof(this->_str) + 1];
		strcpy(str, _str);
		delete[] _str;
		char *temp = str;
		this->_str = str;
		while (*temp){
			*temp++;
		}
		*temp = ch;
		*(temp + 1) = '\0';
	}
	void insert(int pos, char ch);
	void insert(int pos, char* str);
	void insert(int pos, const String &str);
public:
	bool SameStr(const char* s1, const char* s2){
		assert(s1);
		assert(s2);
		while ((*s1) == (*s2)){
			s1++;
			s2++;
			if ((*s1 == '\0') && (*s2 == '\0'))
				return  true;
		}		
	  return false;
	}
	bool Compare(const char *s1, const char *s2){
		assert(s1);
		assert(s2);
		int ret;
		while (*s1++ == *s2++)
	    ret = *s1 - *s2;
		if (ret > 0)
		    return true;
		else 
		   return false;
	}
private:
	char *_str;
};
ostream& operator<<(ostream& os, const String& str){
	os << str._str << endl;
	return os;
}

int main(){
	{
		/*String a("abc");
		cout << a;
		String b(a);
		cout << b;
		String c;
		cout << c;
		c = a;*/
		String a("ac");
		String b("ad");
		/*int ret = (a < b);
		cout << ret << endl;
		cout << a;
		cout << b;*/
		a.PushBack('d');
		a.PushBack('d');		
		cout << a;
		getchar();
		/*cout << c;*/
	}
	getchar();
	return 0;
}