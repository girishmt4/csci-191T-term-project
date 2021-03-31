#include "_input.h"

_input::_input()
{
    //ctor
        prevMouseX =0;
        prevMouseY =0;
        mouseTranslation =0;
        mouseRotate =0;
}

_input::~_input()
{
    //dtor
}


void _input::keyPressed(_player* ply)
{
    switch(wParam)
    {
    case VK_LEFT:
        {
            ply->actionTrigger = ply->WALK_LEFT;
            ply->playerPos.x -= 0.01;

            break;
        }
    case VK_RIGHT:
        {
            ply->actionTrigger = ply->WALK_RIGHT;     //DO ACTION ACCORDING TO YOUR SPRITE
            ply->playerPos.x += 0.01;

            break;
        }
    case VK_UP:
        {

            break;
        }
    case VK_DOWN:
        {

            break;
        }
    }
}

void _input::moveEnv(_parallax* plx, float speed)
{
    switch(wParam)
    {
    case VK_LEFT:
             plx->xMax -=speed;
             plx->xMin -=speed;

        break;
    case VK_RIGHT:
             plx->xMax +=speed;
             plx->xMin +=speed;
        break;

    case VK_UP:
             //plx->yMax +=speed;
             //plx->yMin +=speed;

        break;
    case VK_DOWN:
             //plx->yMax -=speed;
             //plx->yMin -=speed;
        break;


    }
}


void _input::keyUp()
{
    switch (wParam)
    {
        default: break;
    }
}

void _input::keyUp(_player* ply)
{
    ply->actionTrigger = ply->STAND;
}

/*
void _input::mouseDown(_model* mdl, float x, float y)
{
     prevMouseX =x;
     prevMouseY =y;

     switch(wParam)
     {
     case MK_LBUTTON:
        mouseRotate = true;
        break;

     case MK_RBUTTON:
        mouseTranslation = true;
        break;

      default: break;
     }
}
*/

void _input::mouseUp()
{
    mouseRotate = false;
    mouseTranslation = false;
}

/*
void _input::mouseWheel(_model* mdl, float delta )
{
     mdl->zoom +=delta/100;
}
*/
/*
void _input::mouseMove(_model* mdl, float x, float y)
{
       if(mouseRotate){
        mdl->rotateX += (x-prevMouseX)/3;
        mdl->rotateY += (y-prevMouseY)/3;

       }
       if(mouseTranslation){

          mdl->xPos +=(x-prevMouseX)/100;
          mdl->yPos -=(y-prevMouseY)/100;
       }
       prevMouseX =x;
       prevMouseY =y;
}

*/
