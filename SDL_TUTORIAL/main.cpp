/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include "Game.h"

Game* g_game = 0;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            
            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );
            
            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }
    
    //Destroy window
    SDL_DestroyWindow( window );
    
    //Quit SDL subsystems
    SDL_Quit();
    
    return 0;
}*/

const int FPS = 60;
const int DELAY_TIME = 1000.0F / FPS;

int main(int argc, char* argv[])
{
    
    Uint32 frameStart, frameTime;
    
    std::cout << "game init attempt...\n";
    if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
    {
        std::cout << "game init success...\n";
        while (TheGame::Instance()->running()) {
            
            frameStart = SDL_GetTicks();
            
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;
            
            if(frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
            
            
        }
    }else
    {
        std::cout << "game init failure ... " << SDL_GetError() << "\n";
        return -1;
    }
    
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    
    return 0;
}

