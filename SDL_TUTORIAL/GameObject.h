//
//  GameObject.hpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};

#endif /* GameObject_h */
