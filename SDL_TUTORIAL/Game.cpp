//
//  Game.cpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/7.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
    if(s_pInstance == 0)
    {
        s_pInstance = new Game();
        return  s_pInstance;
    }
    
    return s_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init surface\n";
        int flag = 0;
        if(fullscreen)
        {
            flag = SDL_WINDOW_FULLSCREEN;
        }
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n ";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
                
                //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/Image/animate.bmp");
                /*SDL_Surface* pTempSurface = IMG_Load("Assets/Image/animate-alpha.png");
                
                m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
                SDL_FreeSurface(pTempSurface);
                
                SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
                
                m_sourceRectangle.w = 128;
                m_sourceRectangle.h = 82;
                
                m_destinationRectangle.x = m_sourceRectangle.x = 0;
                m_destinationRectangle.y = m_sourceRectangle.y = 0;
               
                m_destinationRectangle.w = m_sourceRectangle.w;
                m_destinationRectangle.h = m_sourceRectangle.h;*/
                
                //m_textureManager.load("Assets/Image/animate-alpha.png", "animate", m_pRenderer);
                if(!TheTextureManager::Instance()->load("Assets/Image/animate-alpha.png", "animate", m_pRenderer))
                {
                    return  false;
                }
                
                TheInputHandler::Instance()->initializeJoysticks();
                
                /*m_go = new GameObject();
                m_player = new GameObject();
                m_enemy = new Enemy();
                
                m_go->load(100, 100, 128, 82, "animate");
                m_player->load(300, 300, 128, 82, "animate");
                m_enemy->load(0, 0, 128, 82, "animate");*/
                
                /*m_player = new Player();
                m_enemy1 = new Enemy();
                m_enemy2 = new Enemy();
                m_enemy3 = new Enemy();
                
                m_gameObjects.push_back(m_player);
                m_gameObjects.push_back(m_enemy1);
                m_gameObjects.push_back(m_enemy2);
                m_gameObjects.push_back(m_enemy3);*/
                
                /*m_gameObjects.push_back(m_go);
                m_gameObjects.push_back(m_player);
                m_gameObjects.push_back(m_enemy);*/
                
                m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
                m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
                
                
            }else
            {
                std::cout << "renderer init fail\n";
                return  false;
            }
        }else
        {
            std::cout << "window init faile\n";
            return  false;
        }
    }else
    {
        std::cout << "SDL init fail\n";
        return  false;
    }
    
    std::cout << "init success\n";
    m_bRunning = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    //SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    //TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
    //TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    
    //m_go.draw(m_pRenderer);
    //m_player.draw(m_pRenderer);
    
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size() ; i++) {
        m_gameObjects[i]->draw();
    }
    
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}

void Game::handleEvents()
{
    /*SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
                
            default:
                break;
        }
    }*/
    
    TheInputHandler::Instance()->update();
}

void Game::update()
{
    //m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
    //m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    //m_go.update();
    //m_player.update();
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size() ; i++) {
        m_gameObjects[i]->update();
    }
}

SDL_Renderer* Game::getRenderer() const
{
    return m_pRenderer;
}

void Game::quit()
{

}







