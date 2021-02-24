#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Mystring
{
public:
	Mystring(const char* str = nullptr);
	~Mystring();
	Mystring(const Mystring& s);
	bool operator==(const Mystring& s);
	Mystring& operator=(const Mystring& s);
	Mystring operator+(const Mystring& s)const;
	Mystring& operator+=(const Mystring& s);
	inline size_t size()const;
	const char* c_str() const;//将string转为char
public:
	typedef char* iterator;
	iterator begin();
	iterator end();
	void push_back(const char c);
	void append(const char* str);
	void clear();
	size_t capacity()const;
	bool empty()const;
	void resize(size_t newsize, char c = '\0');
	void reserve(size_t newCapacity);

	char& operator[](size_t index)const;
	// 返回字符 c 在字符串中第一次出现的位置
	size_t find(char c, size_t pos = 0)const;
	// 返回字符串 str 在字符串中第一次出现的位置
	size_t find(char* str, size_t pos = 0)const;

	string& insert(size_t pos, char c);
	string& insert(size_t pos, char* str);

	string& erase(size_t pos, size_t len);
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
Mystring::iterator Mystring::begin() {
	return _str;
}
Mystring::iterator Mystring::end() {
	return (_str + _size);
}
void Mystring::push_back(const char c){
	_size += 1;
}
Mystring::Mystring(const char* str) {
	if (str == nullptr) {
		_size = 0;
		_str = new char[1];
		*_str = '\0';
	}
	else {
		int len = strlen(str);
		_str = new char[len + 1];
		strcpy(_str, str); // 会拷贝 源字符串最后的 \0
	}
}
Mystring::~Mystring() {
	_size = 0;
	delete[] _str;
}
Mystring::Mystring(const Mystring& s) {
	_size = s.size();
	_str = new char[_size + 1];
	strcpy(_str, s.c_str());
}

bool Mystring::operator==(const Mystring& s) {
	if (_size == s.size() && strcmp(_str, s.c_str()) == 0)
		return true;
	return false;
}
Mystring& Mystring::operator=(const Mystring& s) {
	if (*this == s)
		return *this;
	delete[]_str;
	_size = s.size();
	_str = new char[s.size() + 1];
	strcpy(_str, s.c_str());
}
Mystring Mystring::operator+(const Mystring& str) const//+操作符3步
{//新建对象包括新空间，拷贝两个数据，返回新空间
	Mystring newstring;
	newstring._size = _size + str.size();
	newstring._str = new char[newstring._size + 1];
	strcpy(newstring._str, _str);
	strcat(newstring._str, str.c_str());
	return newstring;
}

Mystring& Mystring::operator+=(const Mystring& str)//+=操作符5步
{//重分配新空间，拷贝两个数据，删除自己原空间，赋值为新空间，返回引用
	_size += str.size();//成员_size是实际长度
	char* newstring = new char[_size + 1];
	strcpy(newstring, _str);
	strcat(newstring, str.c_str());
	delete[] _str;
	_str = newstring;
	return *this;
}
inline size_t Mystring::size()const {
	return _size;
}
inline const char* Mystring::c_str()const {
	return _str;
}

