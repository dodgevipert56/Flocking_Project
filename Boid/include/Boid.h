#ifndef Boid_H_
#define Boid_H_
#include "Vec3.h"
#include <cstring>

class Boid
{
public:
    Boid()=default;
    Boid(const Vec3 &_pos, const Vec3 &_dir, const Vec3 &_dirOff, size_t _maxLife);
    ~Boid()=default;
    Boid(const Boid &)=default;
    Boid(Boid &&)=default;
    Boid & operator = (const Boid &)=default;
    Boid & operator = (Boid &&)=default;

    Vec3 getPosition() const;
    void setPosition(const Vec3 &_pos);

    Vec3 cohesion() const;
    Vec3 alignment() const;
    Vec3 separation() const;

    Vec3 getDirection() const;
    void setDirection(const Vec3 &_dir);

    Vec3 getDirOffset() const;
    void setDirOffset(const Vec3 &_dirOff);

    size_t getLife() const;
    size_t getMaxLife() const;
    void setLife(size_t _life);


    Vec3 getColour() const;
    void setColour(const Vec3 &_colour);

    void update();
    void render() const;
    void reset();

private:
    Vec3 m_position;
    Vec3 m_velocity;
    Vec3 m_acceleration;
    Vec3 m_dir;
    Vec3 m_dirOff;
    Vec3 m_colour = {0.0f, 0.0f, 0.0f};
    size_t m_life = 0;
    size_t m_maxLife;


};

#endif
