//
//StrVector.hpp
//C++ test
//
//Created by  朱元杰  on  2021/3/23.
// Copyright  2021  朱元杰   All  rights reserved.


#ifndef STRVECTOR_HPP
#define STRVECTOR_HPP

#include<vector>
#include<iostream>
#include<memory>
#include<initializer_list>
#include<string>
#include<new>
#include<stdio.h>
#include<iterator>
#include<numeric>


class StrVector{
    friend std::ostream& operator<<(std::ostream&,const StrVector&);
public:
    StrVector():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVector(const StrVector&);
    StrVector(std::initializer_list<std::string> i1);
    ~StrVector();
    StrVector& operator=(const StrVector&);
    void push_back(const std::string&);
    void resize(size_t);
    size_t size(){return first_free-elements;}
    size_t capcity(){return cap-elements;}
    std::string *begin() const{return elements;}
    std::string *end() const{return first_free;}

    private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc(){if(size()==capcity()) reallocate();}
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;

};






#endif