#ifndef Flock_H
#define Flock_H
#include <vector>
#include "Boid.h"


class Flock
{
    public :
        Flock() = default;
        Flock(const Vec3 &_pos, size_t _numBoids);
        Flock (const Flock &) = delete;
        void render() const;
        void update();
        size_t getNumBoids() const;

    private:
        size_t m_numBoids = 0;
        std::vector<Boid> m_Boids; // vector header
        Vec3 m_pos;
};

#endif
