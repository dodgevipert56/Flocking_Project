#include "Camera.h"
//#include <iostream>


Camera::Camera(const Vec3 &_pos, const Vec3 &_angle) :
                   c_position(_pos), c_angle(_angle)
{

}

Camera::Camera(const size_t &_foc, const size_t &_aoV, const size_t &_foV) :
                focLen(_foc), angleOfView(_aoV), fieldOfView(_foV)
{

}

Vec3 Camera::getPosCam() const
{
    return c_position;
}

void Camera::setPosCam(const Vec3 &_pos)
{
    c_position = _pos;
}


