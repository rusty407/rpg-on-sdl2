#include <SDL.h>
#include <SDL_image.h>
// #include <cstddef>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;

SDL_Window* gWindow = nullptr;
SDL_Texture* loadTexture( std::string path );
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gTexture = nullptr; 

SDL_Texture* gCurrentTexture = nullptr;

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
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if(gRenderer == nullptr) {
                printf("failed to created renderer because: %s\n", SDL_GetError());
            } 
            else {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if( !IMG_Init(imgFlags) & imgFlags ) {
                    printf("couldn't initialize the png file: %s\n", SDL_GetError());
                    success = false;
                }
            }
        }
    }
    return success; // return success cuz we got boolean value over there so function needs to know return is true of false to execute
}

// load media where i created what happenes if someone clicks specific key on the keyboard
bool loadMedia() {
    bool success = true;
    gTexture = loadTexture("/home/console/Documents/sdl-project/rpg_on_sdl2/png_files/map.png");
    return success;
}

// load the image on the surface and replaces handwritten const char* myImage 
SDL_Texture* loadTexture( std::string path ) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if(loadedSurface == nullptr) {
        printf("failure during loading surface and rendering image: %s\n", path.c_str(),  IMG_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if (newTexture == nullptr) {
            printf("failure during rendering image: %s\n", SDL_GetError());
        }
       // remove the old surface
       SDL_FreeSurface( loadedSurface );
    }
    // updates and return the image
    return newTexture;
}

void close() {
    // delocate surface
    SDL_DestroyTexture( gTexture );
    gTexture = nullptr;
    // destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    IMG_Quit();
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
        gCurrentTexture = gTexture; 
        while(!quit) {
            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                } 
            }
            SDL_SetRenderDrawColor( gRenderer, 0xA6, 0x88, 0x81, 0xFF);
            // clears screen
            SDL_RenderClear(gRenderer);
            // render texture on canvas 
            SDL_RenderCopy( gRenderer, gCurrentTexture, nullptr, nullptr);
            // update screen
           
            // render the cube
            // SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
            // SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF);
            // SDL_RenderFillRect( gRenderer, &fillRect );
            //
            // // render green color
            //
            // SDL_Rect outlineRect= { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
            // SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF);
            // SDL_RenderDrawRect( gRenderer, &outlineRect );
            //
            // SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF);
            // SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
            //
            // SDL_SetRenderDrawColor(gRenderer, 0x00, 0x12, 0x83, 0x71);
            // for(int i = 0; i < SCREEN_HEIGHT; i += 4){
            //     SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i);
            // }
            
            // SDL_Rect topLeftViewPort;
            // topLeftViewPort.x = 0;
            // topLeftViewPort.y = 0;
            // topLeftViewPort.w = SCREEN_WIDTH / 2;
            // topLeftViewPort.h = SCREEN_HEIGHT / 2;
            //
            // SDL_RenderSetViewport( gRenderer, &topLeftViewPort );
            // SDL_RenderCopy( gRenderer, gTexture, nullptr, nullptr);


            SDL_RenderPresent(gRenderer);

        }
    }
    // free memory
    close();
    return 0;
}
