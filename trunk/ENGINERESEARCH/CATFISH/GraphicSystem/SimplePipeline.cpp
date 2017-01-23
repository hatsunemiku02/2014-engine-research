//
//  SimplePipeline.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SimplePipeline.h"
#include "RenderUnit.h"
#include "GlesDevice.h"
#include "Culler2D.h"
#include "Material.h"

namespace GraphicSys
{
    SimplePipeline::SimplePipeline()
    {
        m_pCuller = new Culler2D();
        Culler2D* pCuller2D = (Culler2D*)m_pCuller;
        pCuller2D->SetArea(vector2f(1.0f,1.0f), vector2f(-1.0f,-1.0f));
    }
    SimplePipeline::~SimplePipeline()
    {
        
    }
    void SimplePipeline::RenderAll()
    {
        
        GraphicCore::GlesDevice::GetInstance().EnableState(GraphicCore::RS_BLEND);
        GraphicCore::GlesDevice::GetInstance().SetBlendFun(GraphicCore::BF_ADD);
        GraphicCore::GlesDevice::GetInstance().SetBlendState(GraphicCore::BSS_SRC_ALPHA,GraphicCore::BSD_ONE_MINUS_SRC_ALPHA );
        
        
        
        std::multimap<unsigned int,RenderUnit*>::iterator iter;
        std::multimap<unsigned int,RenderUnit*> _mapRenders;
        
        m_pCuller->Cull(0, _mapRenders);
        
        iter = _mapRenders.begin();
        for(;iter!=_mapRenders.end();iter++)
        {
            iter->second->ApplyParamToGpu();
            GraphicCore::GlesDevice::GetInstance().SetCurrentGPG(iter->second->GetMaterial()->GetGpuPro());
            GraphicCore::GlesDevice::GetInstance().SetCurrentVBO(iter->second->m_pVBO);
            GraphicCore::GlesDevice::GetInstance().SetCurrentIBO(iter->second->m_pIBO);
            GraphicCore::GlesDevice::GetInstance().Draw(GraphicCore::DM_TRIANGLE_LIST,0,-1);
        }
    }
}