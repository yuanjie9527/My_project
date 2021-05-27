#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
    public:
    MyString();
    MyString(const char * str);
    MyString(const MyString& str);
    ~MyString();

    MyString& operator=(const char* str);
    MyString& operator=(const MyString& str);
    MyString operator+(const MyString& str);

    char& operator[](unsigned int index);
    const char& operator[]( unsigned int index) const;

    friend bool operator>(const MyString &str1,const MyString &str2);
    friend bool operator<(const MyString &str1,const MyString &str2);
    friend bool operator==(const MyString &str1,const MyString &str2);

    friend ostream& operator<<(ostream& os,const MyString& str);
    friend istream& operator>>(istream& is,const MyString& str);

    private:
    char* m_str;

};


#endif