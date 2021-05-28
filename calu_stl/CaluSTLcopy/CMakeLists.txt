cmake_minimum_required(VERSION 3.17)
project(CaluSTL)

set(CMAKE_CXX_STANDARD 14)

add_executable(CaluSTL main.cpp ReadSTLFile.cpp ReadSTLFile.h Point3f.cpp Point3f.h TrianglesArea.h TrianglesArea.cpp)