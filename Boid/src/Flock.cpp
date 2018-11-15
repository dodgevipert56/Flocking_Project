#include <iostream>
#include <Flock.h>
#include "Vec3.h"
#include <random>

size_t Flock::getNumBoids() const
{
    return m_numBoids;
}

Flock::Flock(const Vec3 &_pos, size_t _numBoids)
{
    m_pos = _pos;
    m_numBoids = _numBoids;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
    std::uniform_real_distribution<float> disOff(-0.5f, 0.5f);

    std::uniform_real_distribution<float> pos(-50.0f, 50.0f);

    std::uniform_int_distribution<size_t> life(5, 100); // set max life

    for(size_t i =0; i<_numBoids; ++i)
    {
        m_Boids.push_back(Boid(Vec3(pos(gen), pos(gen), pos(gen)), Vec3(dis(gen), dis(gen), dis(gen)), Vec3(disOff(gen), dis(gen), dis(gen)), life(gen)));
    }
}

void Flock::update()      // is mutable
{
    for(auto &b : m_Boids)
        b.update();
}

void Flock::render() const  // doesnt modify
{
    for(auto &b : m_Boids)
        b.render();
}


