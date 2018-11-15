#include "Boid.h"
#include <iostream>

Vec3 Boid::getPosition() const
{
    return m_position;
}

Vec3 Boid::getDirection() const
{
    return m_dir;
}

Vec3 Boid::getDirOffset() const
{
    return m_dirOff;
}

Boid::Boid(const Vec3 &_pos, const Vec3 &_dir, const Vec3 &_dirOff, size_t _maxLife) :
                   m_position(_pos), m_dir(_dir), m_dirOff(_dirOff), m_maxLife(_maxLife) // ctor initialisation list
{

}

size_t Boid::getMaxLife()const
{
    return m_maxLife;
}

void Boid::setPosition(const Vec3 &_pos)
{
    m_position = _pos;
}

size_t Boid::getLife() const  // getting the life which stores
{
    return  m_life;
}

void Boid::setLife(size_t _life)
{
    m_life = _life;
}

Vec3 Boid::getColour() const
{
    return m_colour;
}

void Boid::setColour(const Vec3 &_colour)
{
    m_colour = _colour;
}


void Boid::setDirection(const Vec3 &_dir)
{
    m_dir = _dir;
}

void Boid::setDirOffset(const Vec3 &_dirOff)
{
    m_dir = _dirOff;
}

/*
Vec3 Boid::cohesion(const )
{

}
*/

void Boid::update()
{


    // giving more random movement as a test
    if(m_position.x > 10)
        m_dir.x += m_dirOff.z;
    else if(m_position.y < -10)
        m_dir.z -= m_dirOff.y;
    else if(m_position.z > 10)
        m_dir.y += m_dirOff.x;
    else
        m_dir += m_dirOff;

    m_position += m_dir;


    if(++m_life >= m_maxLife) // same as m_life++ or ++m_life
    {
        //reset
        m_position = Vec3(0.0f, 0.0f, 0.0f);
        m_life = 0;
    }
}

void Boid::render() const
{
    std::cout << m_position.x << ' ' << m_position.y << ' ' << m_position.z << '\n';
    std::cout << m_life << '\n';
}


