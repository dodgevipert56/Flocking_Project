#ifndef Camera_H_
#define Camera_H_
#include "Vec3.h"
#include <cstring>


class Camera
{
public:

    Camera() = default;
    Camera(const Vec3 &_pos, const Vec3 &_angle);
    Camera(const size_t &_foc, const size_t &aoV, const size_t &foV);
    Camera (const Camera &) = delete;
    Vec3 getPosCam()const;
    void setPosCam(const Vec3 &_pos);
    Vec3 getAngle()const;
    void setAngle()const;

private:
    Vec3 c_position;
    Vec3 c_angle;
    size_t focLen;
    size_t angleOfView;
    size_t fieldOfView;

};


#endif
