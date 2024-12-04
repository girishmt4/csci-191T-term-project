#ifndef _OBJECTS_H
#define _OBJECTS_H

#include <string>
#include <GL/gl.h>
#include <GL/glut.h>
#include <_texture.h>

class _objects
{
    public:
        _objects();
        virtual ~_objects();

        float rotateX;
        float rotateY;
        float scaleX, scaleY, scaleZ;

        void initObj();
        void drawObj();
        GLuint tex;
        GLUquadricObj *sphere;
        _texture *objTex = new _texture();

    protected:

    private:
};

#endif // _OBJECTS_H
