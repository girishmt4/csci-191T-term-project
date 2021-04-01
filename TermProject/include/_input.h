#ifndef _INPUT_H
#define _INPUT_H

#include<windows.h>
#include<_parallax.h>
#include<_player.h>
#include <_LandingPage.h>
#include<_HelpPage.h>
#include<_MenuPage.h>
#include<_PopUp.h>
class _input
{
    public:
        _input();
        virtual ~_input();
         void keyPressed(_player*);

         void moveEnv(_parallax *,float);
         void keyUp();
         void keyUp(_player*);


//         void mouseDown(_model*,float, float);
        void mouseUp();
//         void mouseWheel(_model*,float);
//         void mouseMove(_model*,float,float);
        void mouseDown(_LandingPage*);

         void keyPressed(_LandingPage*);
         void keyPressed(_MenuPage*);
         void keyPressed(_HelpPage*);
         void keyPressed(_PopUp*);

         float prevMouseX;
         float prevMouseY;
         bool mouseTranslation;
         bool mouseRotate;
         int flag;

         WPARAM wParam;
    protected:

    private:
};

#endif // _INPUT_H
