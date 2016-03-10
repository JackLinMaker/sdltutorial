//
//  Enemy.hpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
    
    Enemy(const LoaderParams* pParams);
    
    void draw();
    
    void update();
    
    void clean();
};


#endif /* Enemy_h */
