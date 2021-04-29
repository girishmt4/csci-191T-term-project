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
bool _collision::isBoundedCollision(_player &one,_screenSettings *a,int i, int j)
{
    float playerXmin = one.playerPos.x - (one.playerScale.x/2.0);
    float playerXmax = one.playerPos.x + (one.playerScale.x/2.0);
    float playerYmin = one.playerPos.y - (one.playerScale.y/2.0);
    float playerYmax = one.playerPos.y + (one.playerScale.y/2.0);
    float tileXmin = (a->scenePos[i][j].x)-(a->sceneScale[i].x/2.0);
    float tileXmax = (a->scenePos[i][j].x)+(a->sceneScale[i].x/2.0);
    float tileYmin = (a->scenePos[i][j].y) - (a->sceneScale[i].y/2.0);
    float tileYmax = (a->scenePos[i][j].y) + (a->sceneScale[i].y/2.0);

         // collision x-axis?
        bool collisionX = (one.playerPos.x + (one.playerScale.x/2.0)) >= ((a->scenePos[i][j].x)-(a->sceneScale[i].x/2.0)) && (a->scenePos[i][j].x + (a->sceneScale[i].x/2.0)) >= (one.playerPos.x -(one.playerScale.x/2.0));
        // collision y-axis?

        bool collisionY = (one.playerPos.y + (one.playerScale.y/2.0)) >= ((a->scenePos[i][j].y)-(a->sceneScale[i].y/2.0)) && (a->scenePos[i][j].y + (a->sceneScale[i].y/2.0)) >= (one.playerPos.y -(one.playerScale.y/2.0));
        // collision only if on both axes
        colTrue= collisionX && collisionY;
        one.colPlyTrue= colTrue;
        if(colTrue)
        {
            if((playerXmax >= tileXmin) && (playerXmin < tileXmin) && (one.playerPos.y >= tileYmin) && (one.playerPos.y <= tileYmax))          //from left
            {
                a->colLeft= true;
                one.colLeft= true;
            }
            if((playerXmax > tileXmax) && (playerXmin <= tileXmax) && (one.playerPos.y >= tileYmin) && (one.playerPos.y <= tileYmax))           //from right
            {
                a->colRight= true;
                one.colRight= true;
            }
            if((playerYmax > tileYmax) && (playerYmin <= tileYmax) && (one.playerPos.x >= tileXmin) && (one.playerPos.x <= tileXmax))           //from top
            {
                a->colUp= true;
                one.colUp= true;
            }
            if((playerYmax >= tileYmin) && (playerYmin < tileYmin) && (one.playerPos.x >= tileXmin) && (one.playerPos.x <= tileXmax))           //from bottom
            {
                a->colBottom=true;
                one.colBottom=true;
            }
        }
        else
        {
            a->colLeft= false;
            a->colRight= false;
            a->colUp= false;
            a->colBottom= false;
            one.colLeft= false;
            one.colRight= false;
            one.colUp= false;
            one.colBottom= false;
            //a.colPlyTrue=false;
        }

    return collisionX && collisionY;

}
bool _collision::isBoundedCollision2(_enemies e, _screenSettings *b, int i, int j)
{
    float enemyXmin = e.enemyPos.x - (e.enemyScale.x/2.0);
    float enemyXmax = e.enemyPos.x + (e.enemyScale.x/2.0);
    float enemyYmin = e.enemyPos.y - (e.enemyScale.y/2.0);
    float enemyYmax = e.enemyPos.y + (e.enemyScale.y/2.0);
    float tileEnmXmin = (b->scenePos[i][j].x)-(b->sceneScale[i].x/2.0);
    float tileEnmXmax = (b->scenePos[i][j].x)+(b->sceneScale[i].x/2.0);
    float tileEnmYmin = (b->scenePos[i][j].y) - (b->sceneScale[i].y/2.0);
    float tileEnmYmax = (b->scenePos[i][j].y) + (b->sceneScale[i].y/2.0);
     // collision x-axis?
        bool ecollisionX = (e.enemyPos.x + (e.enemyScale.x/2.0)) >= ((b->scenePos[i][j].x)-(b->sceneScale[i].x/2.0)) && (b->scenePos[i][j].x + (b->sceneScale[i].x/2.0)) >= (e.enemyPos.x -(e.enemyScale.x/2.0));
        // collision y-axis?

        bool ecollisionY = (e.enemyPos.y + (e.enemyScale.y/2.0)) >= ((b->scenePos[i][j].y)-(b->sceneScale[i].y/2.0)) && (b->scenePos[i][j].y + (b->sceneScale[i].y/2.0)) >= (e.enemyPos.y -(e.enemyScale.y/2.0));
        // collision only if on both axes

        colEnmyTrue= ecollisionX && ecollisionY;
        e.colEnmTrue= colEnmyTrue;
        if(colEnmyTrue)
        {
            if((enemyXmax >= tileEnmXmin) && (enemyXmin < tileEnmXmin) && (e.enemyPos.y >= tileEnmYmin) && (e.enemyPos.y <= tileEnmYmax) )         //from left
            {
                e.colEnmLeft= true;
            }
            else if((enemyXmax > tileEnmXmax) && (enemyXmin <= tileEnmXmax) && (e.enemyPos.y >= tileEnmYmin) && (e.enemyPos.y <= tileEnmYmax))   //from right
            {
                e.colEnmRight= true;
            }
            else if((enemyYmax >= tileEnmYmin) && (enemyYmin < tileEnmYmin) && (e.enemyPos.x >= tileEnmXmin) && (e.enemyPos.x <= tileEnmXmax))   //from bottom
            {
                e.colEnmBottom= true;
            }
            else if((enemyYmax > tileEnmYmax) && (enemyYmin <= tileEnmYmax) && (e.enemyPos.x >= tileEnmXmin) && (e.enemyPos.x <= tileEnmXmax))   //from top
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
            //e.colEnmTrue=false;
        }

    return ecollisionX && ecollisionY;

}


