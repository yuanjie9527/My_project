#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include"ReadSTLFile.h"
#include <map>
#include <algorithm>

using namespace std;


int main() {
    ReadSTLFile ReadSTLFile;
    ReadSTLFile.ReadFile("/home/zyj/CLionProjects/CaluSTL/STLfile/shape_cube_210422_104237.stl");
    //Charmander.stl Psyduck.stl zinorgebody.stl------- bin file
    //tile.stl 20mmRoundedCube.stl shape_cube_210422_104237.stl -------- ascii file
//    ReadSTLFile.PrintSize();
//    ReadSTLFile.PrintInfo();
string s="123 456";
string s0="0123456";
    strcpy(s,s0);

auto i=s.find("1");
auto s_e=s.erase(s.begin(),s.begin()+1);

cout<<i<<endl;
    cout<<"s:"<<s<<endl;
    cout<<"*s_e:"<<*s_e<<endl;

}