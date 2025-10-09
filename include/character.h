#pragma once
#include <SDL.h> 

class Guy {
    public:
        static const int GUY_WIDTH= 64;
        static const int GUY_HEIGHT = 64;
        static const int GUY_VEL = 5;

        // initialization of variable
        Character();

        // handle event
        void handleEvent( SDL_Event& e );

        // moves the character
        void move();

        // renders the character
        void render();

    private:
        // position of character
        int mPosX, mPosY;
        // velocity of character
        int mVelX, mVelY;
};
