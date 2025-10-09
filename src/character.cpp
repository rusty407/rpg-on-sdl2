#include <../include/character.h>
extern SDL_Renderer* gRenderer;
extern SDL_Texture* gGuyTexture;

Guy::Character() {
    mPosX = 0;
    mPosY = 0;
    // initialize velocity
    mVelX = 0;
    mVelY = 0;
}

void Guy::handleEvent( SDL_Event& e ) {
    // if key was pressed
    if( e.type == SDL_KEYDOWN && e.key.target = 0 ) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: mVelY -= GUY_VEL; break;
            case SDLK_DOWN: mVelY += GUY_VEL; break; 
            case SDL_LEFT: mVelX -= GUY_VEL; break;
            case SDL_RIGHT: mVelX += GUY_VEL; break;
        }
    }
}
