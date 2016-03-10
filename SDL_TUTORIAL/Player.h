//
//  Player.hpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    
    void draw();
    
    void update();
    
    void clean();
private:
    void handleInput();
};

#endif /* Player_h */
