#include <SDL.h>
#include <cstddef>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

enum KeySurfacePresses {
    KEY_SURFACE_PRESS_DEFAULT,
    KEY_SURFACE_PRESS_LEFT,
    KEY_SURFACE_PRESS_RIGHT,
    KEY_SURFACE_PRESS_DOWN,
    KEY_SURFACE_PRESS_UP,
    KEY_SURFACE_PRESS_TOTAL
}

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground = NULL;
SDL_Surface* gKeySurfacePresses[ KEY_SURFACE_PRESS_TOTAL ];
SDL_Surface* gCurentSurface = NULL;
 
// with this function we initialize creation of window in SDL
bool init() {
   bool success = true; 
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to execute window %s\n", SDL_GetError());
        success = false;
   } else {
       gWindow = SDL_CreateWindow("rpg_game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); // title, default pos, def pos, swidth, sheight, window_shown
       if (gWindow == NULL) {
            printf("Window creation was failed because of: %s\n", SDL_GetError());
            success = false;
       } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
       }
   }
   return success; // return success cuz we got boolean value over there so function needs to know return is true of false to execute
}

bool loadMedia() {
    bool success = true;
    // default image
    gKeySurfacePresses[ SDL_SURFACE_PRESS_DEFAULT ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/map.bmp");
    if(gKeySurfacePresses[ SDL_SURFACE_PRESS_DEFAULT ] = NULL) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
    // on pressing up button
    gKeySurfacePresses[ SDL_SURFACE_PRESS_UP ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/guy.bmp");
    if(gKeySurfacePresses[ SDL_SURFACE_PRESS_UP ] = NULL) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
}

// removes handwritten SDL_LoadBMP

SDL_Surface* loadSurface( std::string path ) {
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if(loadedSurface == NULL) {
        printf("failure during loading surface and rendering image: %s\n", path.c_str(),  SDL_GetError());
    } 
    return loadedSurface;
}

void close() {
    // delocate surface
    SDL_FreeSurface(gBackground);
    gBackground = NULL;
    // destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
}

int main( int argc, char* args[] ) {
    if(!init()) {
        printf("Failure during executing program: %s\n", SDL_GetError());
    } else if (!loadMedia()) {
        printf("Failure during executing media files %s\n", SDL_GetError());
    } else {
        SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
        // update surface
        SDL_UpdateWindowSurface(gWindow);
        // don't close before i click the close button
        SDL_Event e;
        bool quit = false;
        while(!quit) {
            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                }
            }
        }
    }
    // free memory
    close();
    return 0;
}
