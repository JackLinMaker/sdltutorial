//
//  InputHandler.h
//  SDL_TUTORIAL
//
//  Created by JackLin on 16/2/10.
//  Copyright © 2016年 JackLin. All rights reserved.
//

#ifndef InputHandler_h
#define InputHandler_h

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "Vector2D.h"

const int m_joystickDeadZone = 10000;

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        
        return s_pInstance;
    }
    
    void initializeJoysticks();
    
    bool joysticksInitialised()
    {
        return m_bJoysticksInitialised;
    }
    
    void update();
    
    void clean();
    
    int xvalue(int joy, int stick);
    
    int yvalue(int joy, int stick);
    
    bool getButtonState(int joy, int buttonNumber);
    
private:
    
    InputHandler() {};
    
    ~InputHandler() {};
    
    static InputHandler* s_pInstance;
    
    bool m_bJoysticksInitialised;
    
    std::vector<SDL_Joystick*> m_joysticks;
    
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    
    std::vector<std::vector<bool>> m_buttonStates;
};

typedef InputHandler TheInputHandler;

#endif /* InputHandler_h */
