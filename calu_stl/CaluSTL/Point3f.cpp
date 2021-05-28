//
// Created by zyj on 2021/1/25.
//


#include"Point3f.h"

Point3f::Point3f():x(0),y(0),z(0)
{
}

Point3f::Point3f(float _x, float _y, float _z) :x(_x), y(_y), z(_z)
{
}

int Point3f::SetParam(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    return 0;
}

bool Point3f::operator<(const Point3f &N) const
{
    //Todo
    if(this->x < N.x)
        return true;
    else if(this->x == N.x)
    {
        if(this->y < N.y)
            return true;
        else if(this->y == N.y)
        {
            if(this->z < N.z)
                return true;
            else if(this->z == N.z)
            {
                return false;
            }
            return false;
        }
        return false;
    }
    else return false;
}