#include <SDL.h>
#include <cstddef>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1200;

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* loadSurface( std::string path );

enum KeySurfacePresses {
    KEY_SURFACE_PRESS_DEFAULT,
    KEY_SURFACE_PRESS_LEFT,
    KEY_SURFACE_PRESS_RIGHT,
    KEY_SURFACE_PRESS_DOWN,
    KEY_SURFACE_PRESS_UP,
    KEY_SURFACE_PRESS_TOTAL
}; // pls don't forget semicolon after enum took me decades to debug

SDL_Surface* gKeySurfacePresses[ KEY_SURFACE_PRESS_TOTAL ];
SDL_Surface* gCurrentSurface = nullptr;

// with this function we initialize creation of window in SDL
bool init() {
   bool success = true; 
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to execute window %s\n", SDL_GetError());
        success = false;
   } else {
       gWindow = SDL_CreateWindow("rpg_game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); // title, default pos, def pos, swidth, sheight, window_shown
       if (gWindow == nullptr) {
            printf("Window creation was failed because of: %s\n", SDL_GetError());
            success = false;
       } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
       }
   }
   return success; // return success cuz we got boolean value over there so function needs to know return is true of false to execute
}

// load media where i created what happenes if someone clicks specific key on the keyboard
bool loadMedia() {
    bool success = true;
    // default image
    gKeySurfacePresses[ KEY_SURFACE_PRESS_DEFAULT ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/bmp_files/map.bmp");
    if(gKeySurfacePresses[ KEY_SURFACE_PRESS_DEFAULT ] == nullptr) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
    // on pressing up button
    gKeySurfacePresses[ KEY_SURFACE_PRESS_UP ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/bmp_files/wallhaven4.bmp");
    if(gKeySurfacePresses[ KEY_SURFACE_PRESS_UP ] == nullptr) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
    
    gKeySurfacePresses[ KEY_SURFACE_PRESS_LEFT ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/bmp_files/wallhaven1.bmp");
    if(gKeySurfacePresses[ KEY_SURFACE_PRESS_LEFT ] == nullptr) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
    
    gKeySurfacePresses[ KEY_SURFACE_PRESS_RIGHT ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/bmp_files/wallhaven2.bmp");
    if(gKeySurfacePresses[ KEY_SURFACE_PRESS_RIGHT ] == nullptr) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }

    gKeySurfacePresses[ KEY_SURFACE_PRESS_DOWN ] = loadSurface("/home/console/Documents/sdl-project/rpg_on_sdl2/bmp_files/wallhaven3.bmp");
    if(gKeySurfacePresses[ KEY_SURFACE_PRESS_DOWN ] == nullptr) {
        printf("failed to load image: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

// load the image on the surface and replaces handwritten const char* myImage 
SDL_Surface* loadSurface( std::string path ) {
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if(loadedSurface == nullptr) {
        printf("failure during loading surface and rendering image: %s\n", path.c_str(),  SDL_GetError());
    } 
    return loadedSurface;
}

void close() {
    // delocate surface
    SDL_FreeSurface(gCurrentSurface);
    gCurrentSurface = nullptr;
    // destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    SDL_Quit();
}

// game loop
int main( int argc, char* args[] ) {
    if(!init()) {
        printf("Failure during executing program: %s\n", SDL_GetError());
    } else if (!loadMedia()) {
        printf("Failure during executing media files %s\n", SDL_GetError());
    } else {

        // don't close before i click the close button
        bool quit = false;
        SDL_Event e;
        gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_DEFAULT ];
        SDL_BlitSurface(gCurrentSurface, nullptr, gScreenSurface, nullptr);
        // update surface
        SDL_UpdateWindowSurface(gWindow);
        while(!quit) {
            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                } else if( e.type == SDL_KEYDOWN ) {
                    switch ( e.key.keysym.sym ) {
                        case SDLK_UP:
                            gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_UP ];
                            break;
                        case SDLK_LEFT:
                            gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_LEFT ];
                            break;
                        case SDLK_RIGHT:
                            gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_RIGHT ];
                            break;
                        case SDLK_DOWN:
                            gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_DOWN ];
                            break;
                        default:
                            gCurrentSurface = gKeySurfacePresses[ KEY_SURFACE_PRESS_DEFAULT ];
                            break;
                    }
                    SDL_BlitSurface(gCurrentSurface, nullptr, gScreenSurface, nullptr);
                    // update surface
                    SDL_UpdateWindowSurface(gWindow);
                }
            }
        }
    }
    // free memory
    close();
    return 0;
}
