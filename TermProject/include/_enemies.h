#ifndef _ENEMIES_H
#define _ENEMIES_H

#include<_common.h>
#include<_texture.h>
#include<_timer.h>

#include<iostream>
#include<GL/gl.h>

using namespace std;

class _enemies
{
    public:
        _enemies();
        virtual ~_enemies();

        vec3 enemyPos;         //enemy position settings
        vec3 enemyScale;       //enemy size
        vec3 vert[4];           //rectangle around enemy

        void enemyInit(float, float, float);      //initialize enemy - passing horizontal and vertical frames from sprite sheet
        void drawEnemy();      //rendering the enemy
        void actions();         //enemy actions
        void autoScroll();

        float xMin,xMax,yMin,yMax;
        float framesX, framesY;
        _timer *timerEnemy = new _timer();
        _texture *enemyImage = new _texture();
        int dir=1;
        bool colEnmTrue, colEnmLeft, colEnmRight, colEnmUp, colEnmBottom;

    protected:

    private:
};

#endif // _ENEMIES_H
