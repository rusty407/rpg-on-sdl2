#include <SDL.h>
#include <cstddef>
#include <stdio.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground = NULL;


// with this function we initialize creation of window in SDL
bool init() {
   bool success = true; 
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to execute window %s\n", SDL_GetError());
        success = false;
   } else {
       gWindow = SDL_CreateWindow("rpg_game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
       if (gWindow == NULL) {
            printf("Window creation was failed because of: %s\n", SDL_GetError());
            success = false;
       } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
       }
   }
   return success; // return success cuz we got boolean value over there so function needs to know return is true of false to execute
}

bool loadMedia(); 
//void close();

int main( int argc, char* args[] ) {
    if(!init()) {
        printf("Failure during executing program");
    } else if (!loadMedia()) {
        printf("Failure during executing media files");
    } else {};

}
