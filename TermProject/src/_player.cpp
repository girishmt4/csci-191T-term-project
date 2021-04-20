#include "_player.h"

#define YSCREEN 0.8
#define XSCREEN 3.8

_player::_player()
{
    //ctor
    vert[0].x=-0.5;vert[0].y=-0.5;vert[0].z=0.0;
    vert[1].x=0.5;vert[1].y=-0.5;vert[1].z=0.0;
    vert[2].x=0.5;vert[2].y=0.5;vert[2].z=0.0;
    vert[3].x=-0.5;vert[3].y=0.5;vert[3].z=0.0;
    radius = 0.5*0.2;


}

_player::~_player()
{
    //dtor
}
void _player::playerInit(float X, float Y, float yPosition)
{
    playerPos.x=-XSCREEN;
    playerPos.y=yPosition+0.025;
    playerPos.z=-2.0;

    playerScale.x=0.6;
    playerScale.y=0.6;
    playerScale.z=1.0;

    framesX=X;
    framesY=Y;

    xMin=0.0;
    xMax=1.0/framesX;
    yMin=0.0;
    yMax=1.0/framesY;
    hitCount = 0;

    timer->startTimer();

}

void _player::drawPlayer()
{
    glTranslatef(playerPos.x,playerPos.y,playerPos.z);

    glScalef(playerScale.x,playerScale.y,playerScale.z);
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

void _player::actions()
{
    switch(actionTrigger)
    {
        case STAND:
        {
            xMin = xMin;
            xMax = xMax;
            break;
        }
        case WALK_RIGHT:
        {
            yMin=0.0;
            yMax=1.0/framesY;
            if(timer->getTicks() > 100)
            {
                xMin += 1/framesX;
                xMax += 1/framesX;
                timer->resetTime();
            }
            break;
        }
        case WALK_LEFT:
        {
            yMin=1.0/framesY;
            yMax=1.0;
            if(timer->getTicks() > 100)
            {
                xMin -= 1/framesX;
                xMax -= 1/framesX;
                timer->resetTime();
            }
            break;
        }
        case JUMP:
        {
            //cout<<playerPos.y<<endl;
            //cout<<colPlyTrue<<colPlyUp<<endl;
            playerPos.y += jumpSpeed;
            if(jumpSpeed != 0.00)
            {
                jumpSpeed -= gravity;
            }
            if(playerPos.y<plyPosY)        //if(isBoundedCollision() && colUp)
            {
                playerPos.y = plyPosY;
                actionTrigger = STAND;
                jumpSpeed = 0.560;
            }
            break;
        }
        case WALK_LEFT_JUMP:
        {
            playerPos.y += jumpSpeed;
            if(jumpSpeed != 0.00)
            {
                jumpSpeed -= gravity;
            }
            if(playerPos.y<plyPosY)
            {
                playerPos.y = plyPosY;
                actionTrigger = STAND;
                jumpSpeed = 0.560;
            }
            yMin=1.0/framesY;
            yMax=1.0;
            if(timer->getTicks() > 100)
            {
                xMin -= 1/framesX;
                xMax -= 1/framesX;
                timer->resetTime();
            }
            break;
        }
        case WALK_RIGHT_JUMP:
        {
            playerPos.y += jumpSpeed;
            if(jumpSpeed != 0.00)
            {
                jumpSpeed -= gravity;
            }
            //cout<<<<endl;
            if(playerPos.y<plyPosY)
            {

                //playerPos.y = -1.475;
                playerPos.y = plyPosY;
                actionTrigger = STAND;
                jumpSpeed = 0.560;
            }
            yMin=0.0;
            yMax=1.0/framesY;
            if(timer->getTicks() > 100)
            {
                xMin += 1/framesX;
                xMax += 1/framesX;
                timer->resetTime();
            }
            break;
        }
        case DIED:
        {
            break;
        }
    }
}
