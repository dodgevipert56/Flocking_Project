#ifndef Light_H_
#define Light_H_
#include "Vec3.h"
#include <cstring>

class Light
{
public:
    Light() = default;
    Light(const Vec3 &_pos, const Vec3 &_lookA, const Vec3 &_dir);
    Light(const size_t dOff, const size_t inten);

    Vec3 getLightPos()const;
    void setLightPos(const Vec3 &_pos);

    Vec3 getLookAt()const;
    void setLookAt(const Vec3 &_lookA);

    Vec3 getDir()const;
    void setDir(const Vec3 &_dir);

private:
    Vec3 pos;
    Vec3 lookAt;
    Vec3 direction;
    size_t dropOff;
    size_t intesity;

};

#endif
