#include "_collision.h"
#include <math.h>
#include <algorithm>

using namespace std;

_collision::_collision()
{
    //ctor
}

_collision::~_collision()
{
    //dtor
}
bool _collision::isCollision(_player ply,_fallingObject obj)
{
    if(sqrt(pow(ply.playerPos.x-obj.objPosition.x,2)+pow(ply.playerPos.y-obj.objPosition.y,2))<ply.radius+obj.radius)
        return true;
    return false;
}

