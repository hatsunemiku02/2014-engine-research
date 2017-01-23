//
//  EngineShell.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "EngineShell.h"
#include "GlesDevice.h"
#include "ResMgr.h"
#include "SoundSystem.h"
#include "Font.h"
#include "cavans.h"
#include "Timer.h"
#include "SimplePipeline.h"
#include "Input.h"
#include "JobMgr.h"

#include "StageLoader.h"

#include "MikuGame.h"

namespace App
{
    void EngineShell::InitEngine(int width ,int height,int cwidth ,int cheight,const char* basedir)
    {
        GraphicCore::GlesDevice::GetInstance().SetScreenSize(Math::vector2<int>( width, height));
        
        GraphicCore::GlesDevice::GetInstance().SetPixelUnpackAlignment(1);
        
        Sprite::Cavans::GetInstance().SetSize(cwidth, cheight);
        
        Resource::ResMgr::GetInstance().SetBaseDic(basedir);
        
        Resource::ResMgr::GetInstance().InitDefaultResource();
        
        SoundSys::SoundSystem::GetInstance().InitSoundSystem();
        
        std::string charpath = Resource::ResMgr::GetInstance().GetBaseDic()+std::string("/Media/tt.TTF");
        FontSys::FontSystem::GetInstance().InitFontSystem(charpath.c_str());
        
        Threads::JobMgr::GetInstance().Init();
        
        m_pGame = new MikuGame::MikuGameApp();
        m_pGame->Init();
    }
    
    void EngineShell::UpdateEngine()
    {
        Timer::GetInstance().Update();
        SoundSys::SoundSystem::GetInstance().UpDate();
        
        m_pGame->Update();
        
        GraphicCore::GlesDevice::GetInstance().Clean();
        GraphicSys::SimplePipeline::GetInstance().RenderAll();
        
        App::Input::GetInstance().Clear();

    }

}