TARGET = BoidTests
SOURCES += main.cpp \
            ../Boid/src/Boid.cpp \ #linker error without it
            ../Boid/src/Flock.cpp \
            ../Boid/src/Light.cpp \
            ../Boid/src/Camera.cpp


LIBS += -lgtest
INCLUDEPATH += ../Boid/include
#QMAKE_CXX = clang++

cache()
