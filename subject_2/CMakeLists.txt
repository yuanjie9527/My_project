cmake_minimum_required(VERSION 3.10)

project(StrVec)

set(CMAKE_CXX_STANDARD 11)


add_executable(StrVec  main.cpp  MyString.cpp MyString.hpp StrVector.cpp StrVector.hpp)