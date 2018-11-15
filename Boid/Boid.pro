TARGET=Boid
SOURCES +=  src/main.cpp \
            src/Boid.cpp \
            src/Flock.cpp \
            src/Light.cpp \
            src/Camera.cpp \
            src/BoundBox.cpp \
            src/Obstacle.cpp
            src/Scene.cpp

#QMAKE_CXX = clang++
HEADERS += \
            include/Vec3.h \
            include/Flock.h \
            include/Boid.h \
            include/Light.h \
            include/Camera.h \
            include/Scene.h \
            include/Obstacle.h \
            include/BoundBox.h


INCLUDEPATH += include
cache()
