//
// Created by zyj on 2021/1/23.
//

#ifndef READSTL_READSTLFILE_H
#define READSTL_READSTLFILE_H

#endif //READSTL_READSTLFILE_H



#include<vector>
#include"Point3f.h"
using namespace std;

class ReadSTLFile
{
public:
    bool ReadFile(const char *cfilename);
    unsigned int NumTri() const;
    vector<Point3f>& PointList();
    vector<vector<Point3f>>& Patch_Collection();
    float Length() const;
    float Width() const;
    float Height() const;
    void PrintInfo();
    void PrintSize()const;
private:
    float length , width , height;
    vector<Point3f> pointList;
    vector<vector<Point3f>> Patch_collection;
    unsigned int unTriangles;
    bool ReadASCII(const char *cfilename);
    bool ReadBinary(const char *cfilename);

    char* memwriter;
    int cpyint(const char*& p);
    float cpyfloat(const char*& p);
};