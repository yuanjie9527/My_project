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
    ReadSTLFile.ReadFile("/home/zyj/CLionProjects/STLfile/shape_cube_210422_104237.stl");
    //Charmander.stl Psyduck.stl zinorgebody.stl------- bin file
    //tile.stl 20mmRoundedCube.stl shape_cube_210422_104237.stl -------- ascii file
    ReadSTLFile.PrintSize();
    ReadSTLFile.PrintInfo();




}