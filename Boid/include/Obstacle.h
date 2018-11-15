#ifndef Obstacle_H_
#define Obstacle_H_
#include "Vec3.h"


class Obstacle
{
public:
    Obstacle() = default;
    Obstacle(const Vec3 &_obsPos, const Vec3 &_obsScl, const Vec3 &_obsRot);
    ~Obstacle()=default;

    Vec3 getObsPos()const;
    void setObsPos(const Vec3 &_obsPos);

    Vec3 getObsScl()const;
    void setObsScl(const Vec3 &_obsScl);

    Vec3 getObsRot()const;
    void setObsRot(const Vec3 &_obsRot);


private:
    Vec3 m_obsPos;
    Vec3 m_obsScl;
    Vec3 m_obsRot;

};

#endif
