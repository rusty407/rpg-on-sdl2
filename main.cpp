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
    bool success = true;

     //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia() {
     //Loading success flag
    bool success = true;

    //Load splash image
    gBasicMap = SDL_LoadBMP( "/home/console/Documents/sdl-project/rpg_on_sdl2/vectoraith_tileset_farmingsims_terrain_fall_expanded.bmp" );
    if( gBasicMap == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "/home/console/Documents/sdl-project/rpg_on_sdl2/vectoraith_tileset_farmingsims_terrain_fall_expanded.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close() {
      //Deallocate surface
    SDL_FreeSurface( gBasicMap );
    gBasicMap = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

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
            SDL_BlitSurface(gBasicMap, NULL, gScreenSurface, NULL);

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
}
