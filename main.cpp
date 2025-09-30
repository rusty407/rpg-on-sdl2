//Using SDL and standard IO
#include <SDL.h>
#include <cstddef>
#include <stdio.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground = NULL;

bool init() {
   bool success = true; 
   if(SDL_Init(SDL_INIT_VIDEO < 0) {
        printf("Failed to execute window %d\n", SDL_GetError());
        success = false;
   } else {
       gWindow = SDL_CreateWindow("rpg_game", SDL_POSITION_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
   }
}

bool loadMedia();
void close();

int main( int argc, char* args[] ) {
    if(!init()) {
        printf("Failure during executing program");
    } else if (!loadMedia()) {
        printf("Failure during executing media files");
    } else {};

}
