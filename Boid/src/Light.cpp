#include "Light.h"
#include <iostream>


Light::Light(const Vec3 &_pos, const Vec3 &_lookA, const Vec3 &_dir) :
                   pos(_pos), lookAt(_lookA), direction(_dir)
{

}

Vec3 Light::getLightPos() const
{
    return pos;
}

void Light::setLightPos(const Vec3 &_pos )
{
    pos = _pos;
}
