#include "_particles.h"

_particles::_particles()
{
    //ctor
}

_particles::~_particles()
{
    //dtor
}
<<<<<<< Updated upstream
=======

void _particles::drawDrops()
{
    glPointSize(3);

    glBegin(GL_POINTS);
    for(int i=0; i<numDrops; i++)
    {
        if(drops[i].alive)
            glVertex3f(drops[i].posX, drops[i].posY, -2.0);
    }

    glEnd();
}

void _particles::update()
{
    for(int i=0; i<numDrops; i++)
    {
        if(drops[i].alive)
        {
            drops[i].posY + GRAVITY*drops[i].mass < 0.0?
            drops[i].yDir = -drops[i].yDir/1.3:drops[i].yDir += GRAVITY*drops[i].mass;
            drops[i].posX += drops[i].xDir;
            drops[i].posY += drops[i].yDir;
            drops[i].posY < -5 && drops[i].posX > 4.0 ? drops[i].alive = false:NULL;
        }
    }
}

void _particles::particleGenerator()
{
    int i = 0;      //iterator

    int newDrops = (rand()%1000)/20;

    if(numDrops + newDrops > MAX_DROPS)
        newDrops = MAX_DROPS - numDrops;

        for(i = numDrops; i<numDrops + newDrops; i++)
        {
            drops[i].alive = true;
            drops[i].posX = -0.8 + (rand()%1000/1000);
            drops[i].posY = 0.8 + (rand()%1000/1000);
            drops[i].xDir = -0.0075 + (rand()%1000)*25/100000);
            drops[i].yDir = 0.0;
            drops[i].mass = 0.5 + rand()%1000/2000;
        }

        numDrops += newDrops;

        numDrops >= MAX_DROPS?numDrops=0:NULL;

}
>>>>>>> Stashed changes
