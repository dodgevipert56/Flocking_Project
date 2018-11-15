#include "Obstacle.h"

Obstacle::Obstacle(const Vec3 &_obsPos, const Vec3 &_obsScl, const Vec3 &_obsRot) :
                    m_obsPos(_obsPos), m_obsScl(_obsScl), m_obsRot(_obsRot)
{

}

Vec3 Obstacle::getObsPos() const
{
    return m_obsPos;
}

void Obstacle::setObsPos(const Vec3 &_obsPos)
{
    m_obsPos = _obsPos;
}
