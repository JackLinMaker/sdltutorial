//
//  Game.h
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/7.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef Game_h
#define Game_h


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>




class Game
{
public:
    static Game* Instance();
    
    ~Game() {}
    
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit();
    
    bool running() {return m_bRunning;}
    
    SDL_Renderer* getRenderer() const;
    
private:
    
    Game() {}
    
    static Game* s_pInstance;
    
    
    
    bool m_bRunning;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    int m_currentFrame;
    //TextureManager m_textureManager;
    //GameObject m_go;
    //Player m_player;
    
    std::vector<GameObject*> m_gameObjects;
    
    /*Player* m_player;
    GameObject* m_enemy1;
    GameObject* m_enemy2;
    GameObject* m_enemy3;*/
    
};

typedef Game TheGame;


#endif /* Game_h */
