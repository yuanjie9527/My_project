//
// Created by zyj on 2021/2/12.
//

#ifndef READSTL_TRIANGLESAREA_H
#define READSTL_TRIANGLESAREA_H

#endif //READSTL_TRIANGLESAREA_H

#include<vector>
#include"Point3f.h"
using namespace std;

class TriangMesh
{
public:
    TriangMesh():
    Normal_Vec(0,0,0),
    Vertex_A(0,0,0),
    Vertex_B(0,0,0),
    Vertex_C(0,0,0){};
    TriangMesh(Point3f N,Point3f A,Point3f B,Point3f C);

    ~TriangMesh(){};

private:
    Point3f Normal_Vec;
    Point3f Vertex_A, Vertex_B, Vertex_C;
};

vector<vector<Point3f>> Triangle2Area(vector<vector<Point3f>>);