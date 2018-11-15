#include <iostream>
#include "Boid.h"
#include "Flock.h"
int main()
{
    std::cout << "Particle Main\n";

    Flock f({0,0,0},25); //set max life, setting the number of particles

    for(size_t i = 0; i<20; ++i)  //10 iterations * 20 particles
    {
        f.render();
        f.update();
    }
}

