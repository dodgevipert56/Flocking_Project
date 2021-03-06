#include <iostream>
#include <gtest/gtest.h>
#include "Boid.h"
#include "Vec3.h"
#include "Flock.h"
#include "Camera.h"
#include "Light.h"
#include "Obstacle.h"

int main(int argc, char **argv) //arg count & array
{
    testing::InitGoogleTest(&argc, argv); // to pass command line args
    return RUN_ALL_TESTS();
}

TEST(Boid, defaultCtor) // Macro, - Test wer gonna run, test case
{
    Boid p;

    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x, 0.0f);
    EXPECT_FLOAT_EQ(pos.y, 0.0f);
    EXPECT_FLOAT_EQ(pos.z, 0.0f);
}

TEST(Camera, defaultCtor)
{
    Camera p;

    auto camPos=p.getPosCam();
    EXPECT_FLOAT_EQ(camPos.x, 0.0f);
    EXPECT_FLOAT_EQ(camPos.y, 0.0f);
    EXPECT_FLOAT_EQ(camPos.z, 0.0f);

}


TEST(Light, defaultCtor)
{
    Light l;

    auto lhtPos=l.getLightPos();
    EXPECT_FLOAT_EQ(lhtPos.x, 0.0f);
    EXPECT_FLOAT_EQ(lhtPos.y, 0.0f);
    EXPECT_FLOAT_EQ(lhtPos.z, 0.0f);

}

TEST(Obstacle, defaultCtor)
{
    Obstacle o;

    auto obsPos=o.getObsPos();
    EXPECT_FLOAT_EQ(obsPos.x, 0.0f);
    EXPECT_FLOAT_EQ(obsPos.y, 0.0f);
    EXPECT_FLOAT_EQ(obsPos.z, 0.0f);

}

TEST(Vec3, defaultCtor) // default ctor
{
    Vec3 a;
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
}

TEST(Flock, defaultCtor)
{
    Flock e;
    EXPECT_TRUE(e.getNumBoids() == 0);
}

TEST(Flock, userCtor)
{
    Flock e(Vec3(0,0,0), 1000);
    EXPECT_TRUE(e.getNumBoids()==1000);
}

TEST(Boid, userCtor)
{
    Boid p(Vec3(1.0f, 0.0f, 1.0f), Vec3(0.0f, -1.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f), 100);
    EXPECT_EQ(p.getMaxLife(), 100);
    EXPECT_TRUE(p.getPosition() == Vec3 (1.0f, 0.0f, 1.0f));
    EXPECT_TRUE(p.getDirection() == Vec3 (0.0f, -1.0f, 0.0f));
    EXPECT_TRUE(p.getDirOffset() == Vec3 (0.0f, 1.0f, 0.0f));
}

TEST(Vec3, userCtor)  //EVERY INSTANCES ARE USING FROM STUCT IN VEC3.H
{
    Vec3 a = {0.2f, -0.2f, 0.0f};
    EXPECT_FLOAT_EQ(a.x, 0.2f);
    EXPECT_FLOAT_EQ(a.y, -0.2f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
}

TEST(Vec3, copyCtor)
{
    Vec3 a = {0.2f, -0.2f, 0.0f};
    auto b = a;
    EXPECT_FLOAT_EQ(a.x, b.x);
    EXPECT_FLOAT_EQ(a.y, b.y);
    EXPECT_FLOAT_EQ(a.z, b.z);
}

TEST(Vec3, plusEquals)
{
    Vec3 a = {1.0f, 2.0f, 3.0f};
    Vec3 b = {1.0f, 1.0f, 1.0f};
    a+=b;
    EXPECT_FLOAT_EQ(a.x, 2.0f);
    EXPECT_FLOAT_EQ(a.y, 3.0f);
    EXPECT_FLOAT_EQ(a.z, 4.0f);
}

TEST(Boid, setPosition)
{
    Boid p;
    p.setPosition({0.5f, -0.2f, 12.303f}); //brace initialisation
    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x, 0.5f);
    EXPECT_FLOAT_EQ(pos.y, -0.2f);
    EXPECT_FLOAT_EQ(pos.z, 12.303f);
}

TEST(Boid, setLife)
{
    Boid l;
    l.setLife(10);
    auto life=l.getLife();
    EXPECT_EQ(life, 10);
}

TEST(Boid, setColour) // Macro, - Test wer gonna run, test case
{
    Boid p;
    p.setColour({0.5f, 0.2f, 1.0f});
    auto c=p.getColour();
    EXPECT_FLOAT_EQ(c.x, 0.5f);
    EXPECT_FLOAT_EQ(c.y, 0.2f);
    EXPECT_FLOAT_EQ(c.z, 1.0f);
}


TEST(Boid, setDir)
{
    Boid d;
    d.setDirection({0.0f, 0.5f, 0.0f});
    auto dir=d.getDirection();
    EXPECT_FLOAT_EQ(dir.x, 0.0f);
    EXPECT_FLOAT_EQ(dir.y, 0.5f);
    EXPECT_FLOAT_EQ(dir.z, 0.0f);
}

TEST(Boid, setDirOffset)
{
    Boid dO;
    dO.setDirOffset({0.0f, 0.0f, 0.0f});
    auto dirO=dO.getDirOffset();
    EXPECT_FLOAT_EQ(dirO.x, 0.0f);
    EXPECT_FLOAT_EQ(dirO.y, 0.0f);
    EXPECT_FLOAT_EQ(dirO.z, 0.0f);
}

TEST(Vec3, equals)
{
    Vec3 a(0.1f, -0.2f, 2.0f);
    Vec3 b(0.1f, -0.2f, 2.0f);
    EXPECT_TRUE(a==b);
}

TEST(Boid, update)
{
    Boid p;
    p.setDirection(Vec3(0,1,0)); // here in TEST its incrementing by 1

    for(int i=0; i<10; ++i)  // 10 here sets with the p.getPosition value, checks if its equal to that
    {
        p.update();
        p.render();
    }
    EXPECT_FLOAT_EQ(p.getPosition().y, 10.0f);
}

TEST(Boid, reset)
{
    Boid p(Vec3 (0.0f, 0.0f, 0.0f), Vec3(0.0f, -1.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f), 100);
    for(size_t i = 0; i<100; ++i)
    {
        p.update();
    }

    auto pos=p.getPosition();
    std::cout<<pos.y<<'\n';
    EXPECT_TRUE(p.getPosition() == Vec3(0.0f, 0.0f, 0.0f));
}
