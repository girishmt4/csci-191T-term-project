#ifndef _COLLISION_H
#define _COLLISION_H

#include <_player.h>
#include <_fallingObject.h>

class _collision
{
    public:
        _collision();
        virtual ~_collision();

        bool isCollision(_player,_fallingObject);

    protected:

    private:
};

#endif // _COLLISION_H
