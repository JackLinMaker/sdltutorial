//
//  TextureManager.hpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <map>



class TextureManager
{
public:
    
    static TextureManager* Instance();
    
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager() {}
    
    static TextureManager* s_pInstance;
    
    std::map<std::string, SDL_Texture*> m_TextureMap;
};

typedef TextureManager TheTextureManager;


#endif /* TextureManager_hpp */
