#include "_collision.h"

_collision::_collision()
{
    //ctor
}

_collision::~_collision()
{
    //dtor
}

bool _collision::isLinearCollision(float x1, float x2)
{
   if(fabs(x1-x2<0.1))return true;
   return false;
}

bool _collision::isRadialCollision(float x1, float y1, float x2, float y2, float r1, float r2)
{
    if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))<r1+r2)return true;
    return false;
}

bool _collision::isCircleRayCollision(float, float, float, float, float)
{

}

bool _collision::isCubic(float, float, float, float)
{

}

bool _collision::isSphereCollision(float, float, float, float)
{

}

bool _collision::isCollisionFloor(float, float, float)
{

}
bool _collision::isBoundedCollision(_player &one,_screenSettings a,int i, int j)
{

         // collision x-axis?
        bool collisionX = (one.playerPos.x + (one.playerScale.x/2.0)) >= ((a.scenePos[i][j].x)-(a.sceneScale[i].x/2.0)) && (a.scenePos[i][j].x + (a.sceneScale[i].x/2.0)) >= (one.playerPos.x -(one.playerScale.x/2.0));
        // collision y-axis?

        bool collisionY = (one.playerPos.y + (one.playerScale.y/2.0)) >= ((a.scenePos[i][j].y)-(a.sceneScale[i].y/2.0)) && (a.scenePos[i][j].y + (a.sceneScale[i].y/2.0)) >= (one.playerPos.y -(one.playerScale.y/2.0));
        // collision only if on both axes
        colTrue= collisionX && collisionY;
        one.colPlyTrue= colTrue;
        if(colTrue)
        {
            if((one.playerPos.x + (one.playerScale.x/2.0)) >=  ((a.scenePos[i][j].x)-(a.sceneScale[i].x/2.0)) )         //from left
            {
                one.colLeft= true;
            }
            else if((a.scenePos[i][j].x + (a.sceneScale[i].x/2.0)) >= (one.playerPos.x -(one.playerScale.x/2.0)))   //from right
            {
                one.colRight= true;
            }
            else if((one.playerPos.y + (one.playerScale.y/2.0)) >= ((a.scenePos[i][j].y)-(a.sceneScale[i].y/2.0)))   //from bottom
            {
                one.colBottom= true;
            }
            else if((a.scenePos[i][j].y + (a.sceneScale[i].y/2.0)) >= (one.playerPos.y -(one.playerScale.y/2.0)))   //from top
            {
                one.colUp=true;
            }
        }
        else
        {
            one.colLeft= false;
            one.colRight= false;
            one.colUp= false;
            one.colBottom= false;
            one.colPlyTrue=false;
        }

    return collisionX && collisionY;

}
bool _collision::isBoundedCollision2(_enemies &e, _screenSettings b, int i, int j)
{
     // collision x-axis?
        bool ecollisionX = (e.enemyPos.x + (e.enemyScale.x/2.0)) >= ((b.scenePos[i][j].x)-(b.sceneScale[i].x/2.0)) && (b.scenePos[i][j].x + (b.sceneScale[i].x/2.0)) >= (e.enemyPos.x -(e.enemyScale.x/2.0));
        // collision y-axis?

        bool ecollisionY = (e.enemyPos.y + (e.enemyScale.y/2.0)) >= ((b.scenePos[i][j].y)-(b.sceneScale[i].y/2.0)) && (b.scenePos[i][j].y + (b.sceneScale[i].y/2.0)) >= (e.enemyPos.y -(e.enemyScale.y/2.0));
        // collision only if on both axes
        colEnmyTrue= ecollisionX && ecollisionY;
        e.colEnmTrue= colEnmyTrue;
        if(colEnmyTrue)
        {
            if((e.enemyPos.x + (e.enemyScale.x/2.0)) >=  ((b.scenePos[i][j].x)-(b.sceneScale[i].x/2.0)) )         //from left
            {
                e.colEnmLeft= true;
            }
            else if((b.scenePos[i][j].x + (b.sceneScale[i].x/2.0)) >= (e.enemyPos.x -(e.enemyScale.x/2.0)))   //from right
            {
                e.colEnmRight= true;
            }
            else if((e.enemyPos.y + (e.enemyScale.y/2.0)) >= ((b.scenePos[i][j].y)-(b.sceneScale[i].y/2.0)))   //from bottom
            {
                e.colEnmBottom= true;
            }
            else if((b.scenePos[i][j].y + (b.sceneScale[i].y/2.0)) >= (e.enemyPos.y -(e.enemyScale.y/2.0)))   //from top
            {
                e.colEnmUp=true;
            }
        }
        else
        {
            e.colEnmLeft= false;
            e.colEnmRight= false;
            e.colEnmUp= false;
            e.colEnmBottom= false;
            e.colEnmTrue=false;
        }

    return ecollisionX && ecollisionY;

}


