#include "MyString.hpp"

MyString::MyString()
{
    m_str= new char[1];
    m_str[0]='\0';
}

MyString::MyString(const char * str)
{
    m_str=new char[strlen(str)+1];
    strcpy(m_str,str);
}

MyString::MyString(const MyString& str)
{
    m_str=new char[strlen(str.m_str)+1];
    strcpy(m_str,str.m_str);
}

MyString& MyString::operator=(const char* str)
{
    delete [] m_str;
    m_str=new char[strlen(str)+1];
    strcpy(this->m_str,str);
    return *this;
}

MyString& MyString::operator=(const MyString& str)
{
    if(this==&str) return *this;
    delete [] m_str;
    m_str=new char[strlen(str.m_str)+1];
    strcpy(this->m_str,str.m_str);
}

MyString MyString::operator+(const MyString& str)
{
    MyString temp;
    if(!str.m_str) return *this;
    else if(!this->m_str) return str;
    else
    {
        temp.m_str=new char[strlen(this->m_str)+strlen(str.m_str)+1];
        strcpy(temp.m_str,this->m_str);
        strcat(temp.m_str,str.m_str);
        return temp;
    }
}

char& MyString::operator[](unsigned int index)
{
    return this->m_str[index];
}

const char& MyString::operator[]( unsigned int index) const
{
    return this->m_str[index];
}

bool operator>(const MyString &str1,const MyString &str2)
{
    if(strcmp(str1.m_str,str2.m_str)>0)  return true;
    else return false;
}

bool operator<(const MyString &str1,const MyString &str2)
{
    if(strcmp(str1.m_str,str2.m_str)<0)  return true;
    else return false;
}

bool operator==(const MyString &str1,const MyString &str2)
{
    if(strcmp(str1.m_str,str2.m_str)==0)  return true;
    else return false;
}

ostream& operator<<(ostream& os,const MyString& str)
{
    os<<str.m_str;
}

istream& operator>>(istream& is,const MyString& str)
{
    is>>str.m_str;
    return is;
}

MyString::~MyString()
{
    delete [] m_str;
}