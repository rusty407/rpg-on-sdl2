//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBasicMap = NULL;

bool init() {
   return 0; 
}

bool loadMedia() {
    return 0;
}

void close(); 

int main( int argc, char* args[] ) {
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            // Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            // Update the window
            SDL_UpdateWindowSurface(gWindow);

            // Keep window open until close button is clicked
            SDL_Event e;
            bool quit = false;
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT) quit = true;
                }
            }
        }
}
