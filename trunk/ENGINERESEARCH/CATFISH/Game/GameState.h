//
//  GameState.h
//  Catfish
//
//  Created by zhaohang on 14-4-23.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_GameState_h
#define Catfish_GameState_h
namespace App
{
    enum State
    {
        CLICKTOSTART,
        SELECTOR,
        GAME,
        SCOREBOARD,
    };
    
    class GameState
    {
        
    public:
        virtual void Init() = 0;
        virtual void Update(double delta) = 0;
        virtual void Release() = 0;
        State GetState()
        {
            return m_State;
        }
    protected:
        
        State m_State;
    };
}
#endif
