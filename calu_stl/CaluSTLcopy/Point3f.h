//
// Created by zyj on 2021/1/25.
//

#ifndef READSTL_POINT3F_H
#define READSTL_POINT3F_H

#endif //READSTL_POINT3F_H





//-----------------------------顶点结构体----------------------------------

struct Vertex //顶点结构
{
    Vertex() {}
    Vertex(float x, float y, float z)
    {
        _x = x;  _y = y;  _z = z;
    }
    float _x, _y, _z;
};

class Point3f
{
public:
    Point3f();
    Point3f(float _x,float _y,float _z);
    int SetParam(float _x, float _y, float _z);
    inline Vertex IVertex() const
    {
        return Vertex(x, y, z);
    }
private:
    float x, y, z;
};