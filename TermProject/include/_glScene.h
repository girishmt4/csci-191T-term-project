#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_input.h>
#include <_texture.h>
#include <_parallax.h>
#include <_player.h>
#include <_timer.h>
#include <_fallingObject.h>
#include <_collision.h>
#include <_gameMessage.h>
#include <_LandingPage.h>
#include<_HelpPage.h>
#include<_MenuPage.h>
#include<_PopUp.h>
#include <_screenSettings.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <_enemies.h>

using namespace std;


class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int,int);

        float screenWidth,screenHeight;
        bool level1,level2,level3;
        bool doneInitializing;
        bool gameComplete;

        _input *kbMs = new _input();
        _parallax *background = new _parallax();
        _parallax *background1 = new _parallax();
        _timer *timer = new _timer();
        _player *myPly = new _player();
        _fallingObject fallObj[20];
        //_collision *collision = new _collision();
        _gameMessage *msg = new _gameMessage();
        _LandingPage *landp = new _LandingPage();
        _LandingPage *lpdecor = new _LandingPage();
        _MenuPage *menup = new _MenuPage();
        _HelpPage *helpp = new _HelpPage();
        _PopUp *pup = new _PopUp();
        _screenSettings scrnStng[7][7];
        _collision *colsn = new _collision();
        _enemies *enmy = new _enemies();
        string c;
        string h,j,k;
        char* t;
        bool clsn = false, enmClsn = false;
        ostringstream str1;

        int winMsg(HWND,UINT,WPARAM,LPARAM);
        WPARAM wParam;

    protected:

    private:

};

#endif // _GLSCENE_H
