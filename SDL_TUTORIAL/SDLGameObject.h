//
//  SDLGameObject.hpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef SDLGameObject_h
#define SDLGameObject_h

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    Vector2D m_position;
    
    int m_width;
    int m_height;
    
    int m_currentRow;
    int m_currentFrame;
    
    std::string m_textureID;
    
    Vector2D m_velocity;
    
    Vector2D m_acceleration;
    
};

#endif /* SDLGameObject_h */
