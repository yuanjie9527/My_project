#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include"ReadSTLFile.h"

using namespace std;


int main() {
    ReadSTLFile ReadSTLFile;
    ReadSTLFile.ReadFile("/home/zyj/CLionProjects/STLfile/Charmander.stl");
    ReadSTLFile.PrintInfo();

    return 0;
}
