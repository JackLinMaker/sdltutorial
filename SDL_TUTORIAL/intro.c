//
//  intro.c
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/7.
//  Copyright © 2016年 JackLin. All rights reserved.
//

/*#include <SDL2/SDL.h>
#include <stdio.h>


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int g_bRunning = 0;

int init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    // initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // if succeeded create our window
        g_pWindow = SDL_CreateWindow("chapter 1: Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        
        // if the window creation succeed create our renderer
        if(g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }else
    {
        return 0; // sdl could not initialize;
    }
    
    return 1;
}

void render()
{
    // set to black
    // set to black // this function expects Red, Green, Blue and
    // alpha as color values
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    
    // clear the window to black
    SDL_RenderClear(g_pRenderer);
    
    // show the window
    SDL_RenderPresent(g_pRenderer);

}

int main(int artc, char* args[])
{
    if(init("Chapter 1:Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
    {
        g_bRunning = 1;
    }
    else
    {
        return  1;
    }
    
    while (g_bRunning) {
        render();
    }
    // set a delay before quiting
    SDL_Delay(5000);
    
    // clean up sdl
    SDL_Quit();
    
    return 0;
    
}*/