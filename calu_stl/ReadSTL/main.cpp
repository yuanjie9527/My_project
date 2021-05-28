#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include"ReadSTLFile.h"

using namespace std;


int main() {
    ReadSTLFile ReadSTLFile;
    ReadSTLFile.ReadFile("/home/zyj/CLionProjects/ReadSTL/Charmander.stl");
    ReadSTLFile.PrintInfo();

    return 0;
}
