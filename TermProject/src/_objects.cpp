#include "_objects.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


_objects::_objects()
{
    //ctor
    rotateX = 0;
    rotateY = 0;
    scaleX = scaleY = scaleZ = 1.0;
}

_objects::~_objects()
{
    //dtor
}

void _objects::initObj()
{
    sphere = gluNewQuadric();
    gluQuadricTexture(sphere, 1);


    objTex->loadTexture("images/moon.jpg");

}

void _objects::drawObj()
{
    glPushMatrix();
        glTranslatef(-2.0,2,-3.0);

        glRotatef(rotateX, 1, 0, 0);
        glRotatef(rotateY, 0, 1, 0);
        glScalef(scaleX, scaleY, scaleZ);
        glSphere(sphere, 1.0, 40, 40);


    glDisable(GL_LIGHTING);
    glPopMatrix();


}

