#include "_finishFlag.h"

_finishFlag::_finishFlag()
{
    //ctor
    vert[0].x=-0.5;vert[0].y=-0.5;vert[0].z=0.0;
    vert[1].x=0.5;vert[1].y=-0.5;vert[1].z=0.0;
    vert[2].x=0.5;vert[2].y=0.5;vert[2].z=0.0;
    vert[3].x=-0.5;vert[3].y=0.5;vert[3].z=0.0;

    radius = 0.5*0.15;
}

_finishFlag::~_finishFlag()
{
    //dtor
}
void _finishFlag::drawFlag()
{
    glTranslatef(flagPosition.x,flagPosition.y,flagPosition.z);
    glScalef(flagSize.x,flagSize.y,flagSize.z);
    glBegin(GL_QUADS);
    glTexCoord2f(xMin,yMax);
    glVertex3f(vert[0].x,vert[0].y,vert[0].z);
    glTexCoord2f(xMax,yMax);
    glVertex3f(vert[1].x,vert[1].y,vert[1].z);
    glTexCoord2f(xMax,yMin);
    glVertex3f(vert[2].x,vert[2].y,vert[2].z);
    glTexCoord2f(xMin,yMin);
    glVertex3f(vert[3].x,vert[3].y,vert[3].z);
    glEnd();
}

void _finishFlag::flagAction()
{
    if(flagTimer->getTicks() > 50)
    {
        xMin += 1.0/framesX;
        xMax += 1.0/framesX;
        yMin = 0.0;
        yMax = 1.0/framesY;
        flagTimer->resetTime();
    }
}

void _finishFlag::flagInit(float X, float Y, float yPosition)
{
    flagPosition.x = 1.3;
    flagPosition.y = yPosition;

    flagPosition.z = -2.0;

    flagSize.x = flagSize.y  = 0.2;
    flagSize.z = 1.0;

    framesX = X;
    framesY = Y;
    xMin=0.0;
    xMax=1.0/framesX;
    yMin=0.0;
    yMax=1.0/framesY;
}
