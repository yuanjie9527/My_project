//
// Created by zyj on 2021/1/23.
//

#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),  (mode)))==NULL
#endif

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include"ReadSTLFile.h"
#include <sstream>

using namespace std;

bool ReadSTLFile::ReadFile(const char *cfilename)
{
    FILE * pFile;
    long lSize;
    char* buffer;
    size_t result;

    /* 若要一个byte不漏地读入整个文件，只能采用二进制方式打开 */
    fopen_s(&pFile,cfilename, "rb");
    if (pFile == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }

    /* 获取文件大小 */
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    /* 分配内存存储整个文件 */
    buffer = (char*)malloc(sizeof(char)*lSize);
    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        exit(2);
    }

    /* 将文件拷贝到buffer中 */
    result = fread(buffer, 1, lSize, pFile);
    if (result != lSize)
    {
        fputs("Reading error", stderr);
        exit(3);
    }


    /* 结束演示，关闭文件并释放内存 */
    fclose(pFile);

    ios::sync_with_stdio(false);
    if (buffer[79]!='\0')//判断格式
    {
        ReadASCII(buffer);
    }
    else
    {
        ReadBinary(buffer);
    }
    ios::sync_with_stdio(true);

    free(buffer);
    return true;
}

bool ReadSTLFile::ReadASCII(const char *buffer)
{
    unTriangles = 0;
    float x, y, z;
    float max_x, max_y, max_z , min_x, min_y, min_z;
    int i;
    vector<Point3f> Point3;
    string name, useless;
    stringstream ss(buffer);
    ss >> name >> name;
    ss.get();
    do {
        ss >> useless;
        if (useless != "facet")
            break;
        ss >> useless >> x >> y >> z;
        Point3.push_back(Point3f(x, y, z));
        getline(ss, useless);
        for (i = 0; i < 3; i++)
        {
            ss >> useless >> x >> y >> z;
            max_x=max(max_x,x);
            max_y=max(max_y,y);
            max_z=max(max_z,z);
            min_x=min(min_x,x);
            min_y=min(min_y,y);
            min_z=min(min_z,z);
            Point3.push_back(Point3f(x, y, z));
        }
        Patch_collection.push_back(Point3);
        length=max_x-min_x;
        width=max_y-min_y;
        height=max_z-min_z;
        Point3.clear();
        unTriangles++;
        getline(ss, useless);
        getline(ss, useless);
        getline(ss, useless);
    } while (1);
    return true;
}

bool ReadSTLFile::ReadBinary(const char *buffer)
{
    const char* p = buffer;
    char name[80];
    float max_x, max_y, max_z , min_x, min_y, min_z;
    int i, j;
    vector<Point3f> Point3;
    memcpy(name, p, 80);
    p += 80;
    unTriangles= cpyint(p);
    for (i = 0; i < unTriangles; i++)
    {
        Point3.push_back(Point3f(cpyfloat(p), cpyfloat(p), cpyfloat(p)));
        for (j = 0; j < 3; j++)//读取三顶点
        {
            Point3.push_back(Point3f(cpyfloat(p), cpyfloat(p), cpyfloat(p)));
            max_x=max(max_x,Point3.at(j).IVertex()._x);
            max_y=max(max_y,Point3.at(j).IVertex()._y);
            max_z=max(max_z,Point3.at(j).IVertex()._z);
            min_x=min(min_x,Point3.at(j).IVertex()._x);
            min_y=min(min_y,Point3.at(j).IVertex()._y);
            min_z=min(min_z,Point3.at(j).IVertex()._z);
        }
        p += 2;//跳过尾部标志
        Patch_collection.push_back(Point3);
        length=max_x-min_x;
        width=max_y-min_y;
        height=max_z-min_z;
        Point3.clear();
    }
    return true;
}

int ReadSTLFile::NumTri()
{
    return unTriangles;
}

float ReadSTLFile::Length()
{
    return length;
}

float ReadSTLFile::Width()
{
    return width;
}

float ReadSTLFile::Height()
{
    return height;
}

vector<Point3f>& ReadSTLFile::PointList()
{
    return pointList;
}

vector<vector<Point3f>>& ReadSTLFile::Patch_Collection()
{
    return Patch_collection;
}

void ReadSTLFile::PrintInfo()
{
    cout << "面片个数:" <<NumTri() << endl;
    cout << "长*宽*高:" << Length() <<"*"<< Width() <<"*"<< Height() <<endl;
  //   for (unsigned long i=0;i<Patch_Collection().size();i++)
  //  {
  //      for (int j=0;j<Patch_Collection().at(i).size();j++)
  //          cout << Patch_Collection().at(i).at(j).IVertex()._x << ","
  //               << Patch_Collection().at(i).at(j).IVertex()._y << ","
  //               << Patch_Collection().at(i).at(j).IVertex()._z << "  " ;
  //      cout << endl;
  //  }

}

int ReadSTLFile::cpyint(const char*& p)
{
    int cpy;
    memwriter = (char*)&cpy;
    memcpy(memwriter, p, 4);
    p += 4;
    return cpy;
}
float ReadSTLFile::cpyfloat(const char*& p)
{
    float cpy;
    memwriter = (char*)&cpy;
    memcpy(memwriter, p, 4);
    p += 4;
    return cpy;
}