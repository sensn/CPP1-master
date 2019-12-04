// Things_about_Classes.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <memory>
class MyString {
public:
	MyString();
	~MyString();
	MyString(const MyString& s);              // copy constructor
	MyString& operator= (const MyString& s);  // assignment
	unsigned Getlen(); 
	void Setlen(unsigned t_len);
	// ...
protected:
	unsigned len_=9;
	char* data_;
};
void MyString::Setlen(unsigned t_len) {
	this->len_ = t_len;
}
unsigned MyString::Getlen() { return this->len_; }
MyString::MyString()
	: len_(55u)
	, data_(new char[1])
{
	data_[0] = '\0';
}
MyString::~MyString()
{
	delete[] data_;
}
MyString::MyString(const MyString& s)
	: len_(s.len_)
	, data_(new char[s.len_ + 1u]) //< --Not{ tt{new char[len_ + 1]}tt }
{                    // not len_
memcpy(data_, s.data_, len_ + 1u);
}                          // no issue using len_ in ctor's {body}
int main1()
{
	MyString a;      // default ctor; zero length MyString ("")
	MyString b = a;  // copy constructor
	a.Setlen(15);
	std::cout << a.Getlen();
	std::cout << b.Getlen();
	return 0;
}

