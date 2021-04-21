#include "_input.h"

#include <windows.h>

_input::_input()
{
    //ctor
        prevMouseX =0;
        prevMouseY =0;
        mouseTranslation =0;
        mouseRotate =0;
        flag =0;
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
            ply->playerPos.x -= 0.03;

            break;
        }
    case VK_RIGHT:
        {
            ply->actionTrigger = ply->WALK_RIGHT;     //DO ACTION ACCORDING TO YOUR SPRITE
            ply->playerPos.x += 0.03;

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

void _input::mouseDown(_LandingPage* lp)
{
    switch(wParam)
    {
        case MK_LBUTTON:    //To continue to game menu from landing page, do a left mouse click
            if (flag == 0)
            {
                flag = 1;
            }
            break;

        case MK_RBUTTON:    //To continue to game menu from landing page, do a right mouse click
            if (flag == 0)
            {
                flag = 1;
            }
            break;
    }

}

void _input::keyPressed(_LandingPage* lp)
{
     switch(wParam)
    {
          case VK_ESCAPE:     //Press Escape to exit from the landing page
            if (flag == 0)
            {
                exit(0);
            }
            break;

        case VK_RETURN:     //Press Enter to continue to game menu from landing page
            if (flag == 0)
            {
                flag = 1;
            }
            break;
    }

}

void _input::keyPressed(_MenuPage* mp)
{
     switch(wParam)
    {
        case 78:  //for key n to start new game
            if (flag == 1)
            {
                flag = 3;
            }
            break;

        case 72:  //value for key h for help
            if (flag == 1)
            {
                flag = 2;
            }
            break;

        case 67:    //value for key c for credits
            if (flag == 1)
            {
                flag = 5;
            }
            break;

        case 69:  //value for key e to exit
        if (flag == 1)
            {
                exit(0);
            }
            break;
    }
}

void _input::keyPressed(_HelpPage* hp)
{
    switch(wParam)
    {
        case VK_ESCAPE:     //Escape key to return to game menu from help page
            if (flag == 2)
            {
                flag = 1;
            }
            break;
    }
}

void _input::keyPressed(_PopUp* popUp)
{
     switch(wParam)
    {
        case VK_RETURN:     //Press Enter to exit to game menu from pop up screen
            if (flag == 4)
            {
                flag = 1;
            }
            break;

        case VK_ESCAPE:     //Press Escape key to pause the game; press escape again to continue
            if (flag == 4)
            {
                flag = 3;
            }
            else if (flag == 3)
            {
                flag = 4;
            }
            break;
    }

}


void _input::keyPressed(_credits* cp)
{
     switch(wParam)
    {
        case VK_ESCAPE:     //Escape key to return to the menu page from credits page
            if (flag == 5)
            {
                flag = 1;
            }
            break;
    }
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
