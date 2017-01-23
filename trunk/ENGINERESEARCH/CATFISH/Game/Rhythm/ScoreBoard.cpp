//
//  ScoreBoard.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "ScoreBoard.h"
namespace  MikuGame
{
    ScoreBoard::ScoreBoard()
    {
        
    }
    
    ScoreBoard::~ScoreBoard()
    {
        
    }
    
    void ScoreBoard::SetPropities(int coolCount,int baseCount,int sadCount,int badCount,int totalScore)
    {
        m_CoolCount = coolCount;
        m_BaseCount = baseCount;
        m_SadCount = sadCount;
        m_BadCount = badCount;
        m_TotalCount = totalScore;
    }
    
    void ScoreBoard::Init()
    {
        
    }
    
    void ScoreBoard::Update(double delta)
    {
        
    }
    
    void ScoreBoard::Release()
    {
        
    }
    
}