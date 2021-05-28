#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include"ReadSTLFile.h"
#include <map>
#include <algorithm>

using namespace std;


int main() {
    ReadSTLFile ReadSTLFile;
    ReadSTLFile.ReadFile("/home/zyj/CLionProjects/CaluSTL/tile.stl");
    //Charmander.stl is bin file
    //tile.stl 20mmRoundedCube.stl are ascii file
    ReadSTLFile.PrintSize();
    ReadSTLFile.PrintInfo();



}