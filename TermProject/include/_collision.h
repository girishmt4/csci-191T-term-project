#ifndef _COLLISION_H
#define _COLLISION_H

#include<math.h>
#include<iostream>
#include<conio.h>
#include<_screenSettings.h>
#include<_player.h>
#include<GL/gl.h>
#include<_enemies.h>

using namespace std;
class _collision
{
    public:
        _collision();
        virtual ~_collision();

        bool isLinearCollision(float,float);
        bool isRadialCollision(float,float,float,float,float,float);
        bool isCircleRayCollision(float,float,float,float,float);
        bool isCubic(float,float,float,float);
        bool isSphereCollision(float,float, float,float);
        bool isCollisionFloor(float,float,float);
        bool isBoundedCollision(_player &,_screenSettings, int, int);
        bool isBoundedCollision2(_enemies &,_screenSettings, int, int);
        bool colTrue,colEnmyTrue;

    protected:

    private:
};

#endif // _COLLISION_H
