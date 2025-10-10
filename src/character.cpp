#include "../include/character.h"
extern SDL_Renderer* gRenderer;
extern LTexture gGuyTexture;

Guy::Guy() {
    mPosX = 0;
    mPosY = 0;
    // initialize velocity
    mVelX = 0;
    mVelY = 0;
}

void Guy::handleEvent( SDL_Event& e ) {
    // if key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: mVelY -= GUY_VEL; break;
            case SDLK_DOWN: mVelY += GUY_VEL; break; 
            case SDLK_LEFT: mVelX -= GUY_VEL; break;
            case SDLK_RIGHT: mVelX += GUY_VEL; break;
        } // if the key was released
    } else if( e.type == SDL_KEYUP && e.key.repeat == 0 ) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: mVelY += GUY_VEL; break;
            case SDLK_DOWN: mVelY -= GUY_VEL; break; 
            case SDLK_LEFT: mVelX += GUY_VEL; break;
            case SDLK_RIGHT: mVelX -= GUY_VEL; break;
        }
    }
}

void Guy::render(){
    // shows the character 
    gGuyTexture.render( mPosX, mPosY );
}
