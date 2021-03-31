#ifndef _FINISHFLAG_H
#define _FINISHFLAG_H

#include <_common.h>
#include <_texture.h>
#include <_timer.h>
class _finishFlag
{
    public:
        _finishFlag();
        virtual ~_finishFlag();

        void drawFlag();
        void flagAction();
        void flagInit(float,float,float);

        vec3 flagPosition;
        vec3 flagSize;
        vec3 vert[4];           //rectangle around object


        _timer *flagTimer = new _timer();
        _texture *flagImage = new _texture();

        float xMin,xMax,yMin,yMax;
        float framesX, framesY;
        float flagSpeed;
        float radius;

    protected:

    private:
};

#endif // _FINISHFLAG_H
