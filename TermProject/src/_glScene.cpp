#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

#include <math.h>
//#define YSCREEN 0.8
//#define XSCREEN 1.2

int ii=0;
_glScene::_glScene()
{
    //ctor
    level1 = true;
    level2 = level3 = false;
    doneInitializing = false;
    gameComplete = false;
}


_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    _glLight myLight(GL_LIGHT0);
    if(level1)
    {
        background->parallaxInit("images/parallax1.png");
        background1->parallaxInit("images/level1_pathway.png");
        timer->startTimer();
        myPly->playerInit(8,2,-0.65);
        myPly->plyImage->loadTexture("images/playerAnimated.png");
        for(int i=0;i<20;i++)
        {
            fallObj[i].objTimer->startTimer();
            fallObj[i].objInit(6,4,0.3,level1,level2,level3);
            fallObj[i].objImage->loadTexture("images/fireball.png");
        }
        doneInitializing = true;
    }
    if(level2)
    {
        background->parallaxInit("images/parallax2.png");
        background1->parallaxInit("images/level2_pathway.png");
        timer->startTimer();
        myPly->playerInit(8,2,-0.55);
        myPly->plyImage->loadTexture("images/playerAnimated.png");
        for(int i=0;i<20;i++)
        {
            fallObj[i].objTimer->startTimer();
            fallObj[i].objInit(6,5,0.1,level1,level2,level3);
            fallObj[i].objImage->loadTexture("images/meteor2.png");
        }
        doneInitializing = true;
    }
    if(level3)
    {
        msg->msgInit();
        msg->msgImage->loadTexture("images/unnamed.png");
        background->parallaxInit("images/parallax3.png");
        background1->parallaxInit("images/level3_pathway.png");
        timer->startTimer();
        myPly->playerInit(8,2,-0.9);
        myPly->plyImage->loadTexture("images/playerAnimated.png");
        for(int i=0;i<20;i++)
        {
            fallObj[i].objTimer->startTimer();
            fallObj[i].objInit(8,8,0.1,level1,level2,level3);
            fallObj[i].objImage->loadTexture("images/kisspng-asteroids-sprite-opengameart-org-2d-computer-graph-asteroid-5ad044da44b1d7.0888766115235985542814.png");
        }
        doneInitializing = true;

    }
    landp->landingPageInit("images/landing.png");
    menup->menuPageInit("images/menu.png");
    helpp->helpPageInit("images/help.png");
    pup->popUpInit("images/pause.png");
    lpdecor->landingPageInit("images/rain.png");

    return true;
}

GLint _glScene::drawScene()
{

    if (kbMs->flag == 0)  //Landing page
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Clear screen and depth buffer
        glLoadIdentity();
        glPushMatrix();
        glTranslated(0,0,-8.0);  //placing objects on screen
        glScalef(1.65, 1.4, 1.0);  //scale to fit within the screen

        landp -> renderBack(screenWidth, screenHeight);       //create background for landing page
        lpdecor -> renderBack(screenWidth, screenHeight);  //make rainfall on the landing page
        lpdecor -> scroll(true, "up", 0.0005);  //Rain scrolling on the landing page
        glPopMatrix();
    }

    if (kbMs->flag == 1)  //Menu page
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Clear screen and depth buffer
        glLoadIdentity();
        glPushMatrix();
        glTranslated(0,0,-8.0);  //placing objects on screen
        glScalef(1.65, 1.5, 1.0);  //scale to fit within the screen
        menup -> renderBack(screenWidth, screenHeight);       //create background for game menu screen
        glPopMatrix();
    }

    if (kbMs->flag == 2)  //Help page
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Clear screen and depth buffer
        glLoadIdentity();
        glPushMatrix();
        glTranslated(0,0,-8.0);  //placing objects on the screen
        glScalef(1.65, 1.5, 1.0);  //scale to fit within the screen
        helpp -> renderBack(screenWidth, screenHeight);       //create background for help page
        glPopMatrix();
    }

    if (kbMs->flag == 3)  //Game page
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.2f,0.2f,0.3f);
        glLoadIdentity();

        glPushMatrix();
        glScalef(1.65, 1.5, 1.0);
        glBindTexture(GL_TEXTURE_2D,background->plxTexture->tex);
        background->renderBack(screenWidth,screenHeight);
        glPopMatrix();

        glPushMatrix();
        glScalef(1.65, 1.5, 1.0);
        glBindTexture(GL_TEXTURE_2D,background1->plxTexture->tex);
        background1->renderBack(screenWidth,screenHeight);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,myPly->plyImage->tex);
        myPly->drawPlayer();
        if(timer->getTicks() > 120)
        {
            myPly->actions();

            timer->resetTime();
        }
        glPopMatrix();
        for(int i=0;i<20;i++)
        {
            glPushMatrix();
            glBindTexture(GL_TEXTURE_2D,fallObj[i].objImage->tex);
            fallObj[i].drawObj(level1,level2,level3);

            if((collision->isCollision(*myPly,fallObj[i])) && fallObj[i].objActive)
            {
                fallObj[i].objActive = false;
                myPly->hitCount += 1;
                //fallObj->objPosition.y -= 0.1;
                fallObj[i].objSpeed = -0.03;
                cout<<"Collision happened player hit count is "<<myPly->hitCount<<endl;
                if(myPly->hitCount == 5)
                {
                    doneInitializing = false;
                    initGL();
                    myPly->hitCount = 0;
                }
            }
            fallObj[i].objFallingAction(level1, level2, level3);
            glPopMatrix();
        }

        /*
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Clear screen and depth buffer
        glLoadIdentity();
        glPushMatrix();
        glTranslated(0,0,-8.0);     //placing objects on the screen
        glScalef(33, 33, 1.0);  //scale to fit within the screen

        background -> renderBack(screenWidth, screenHeight);       //create first background for game
        background -> scroll(false, "right", 0.005);      //auto movement of the background for the game background

        background1 -> renderBack(screenWidth, screenHeight);       //create second background for game
        background1 -> scroll(false, "right", 0.0005);      //auto movement of background for the second game background
        glPopMatrix();

        glPushMatrix();
        //glutSolidTeapot(1.5);
        glTranslated(0,0,-8.0);     //placing objects
        modelTeapot -> drawModel();     //drawing model

        glPopMatrix();
        */
    }

    if (kbMs->flag == 4)  //pause game pop-up page
    {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen and Depth buffer
        //glLoadIdentity();
        glPushMatrix();
        //glTranslated(0.0, 0.0, -7.0);  //placing objects on the screen
        glScalef(0.5, 0.5, 1.0);  //pause screen pop-up scaling
        pup -> renderBack(screenWidth, screenHeight);       //create background for pause pop-up screen
        glPopMatrix();
    }

}


void _glScene::resizeGLScene(int width, int height)
{
    screenWidth= width;
    screenHeight=height;

    float aspectRatio = (float)width/(float)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0,aspectRatio,0.1,100);
    glOrtho(-3.0,3.0,-1.5,1.5,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int _glScene::winMsg(HWND	hWnd,			// Handle For This Window
                     UINT	uMsg,			// Message For This Window
					 WPARAM	wParam,			// Additional Message Information
					 LPARAM	lParam)
{kbMs->wParam = wParam;

    switch (uMsg)									// Check For Windows Messages
	{

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{

		    //to move background
		    kbMs->moveEnv(background, 0.005);
            kbMs->moveEnv(background1, 0.015);

		    kbMs->keyPressed(myPly);
		    kbMs->keyPressed(landp);       //Handling key inputs on the landing page
            kbMs->keyPressed(menup);       //Handling key inputs on the menu page
            kbMs->keyPressed(helpp);       //Handling key inputs on the help page
            kbMs->keyPressed(pup);    //Handling key inputs on the game pause pop up screen


			break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
		    kbMs->keyUp();
		    kbMs->keyUp(myPly);
			break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
            {
//                kbMs ->mouseDown(modelTeapot, LOWORD(lParam),HIWORD(lParam));
                kbMs ->mouseDown(landp);

                break;
            }
        case WM_RBUTTONDOWN:
            {
//                kbMs ->mouseDown(modelTeapot, LOWORD(lParam),HIWORD(lParam));
                kbMs ->mouseDown(landp);
              break;
            }
        case WM_MBUTTONDOWN:
            {
                break;
            }
        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            {
                kbMs->mouseUp();
               break;
            }
        case WM_MOUSEMOVE:
            {
//                kbMs ->mouseMove(modelTeapot, LOWORD(lParam),HIWORD(lParam));
               break;
            }

        case WM_MOUSEWHEEL:
            {
//                kbMs->mouseWheel(modelTeapot,(float)GET_WHEEL_DELTA_WPARAM(wParam));
                break;
            }
	}
}
