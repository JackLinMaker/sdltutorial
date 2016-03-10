//
//  Enemy.cpp
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/8.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams):SDLGameObject(pParams)
{
    
}

void Enemy::draw()
{
    
}

void Enemy::update()
{
   
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
    
}