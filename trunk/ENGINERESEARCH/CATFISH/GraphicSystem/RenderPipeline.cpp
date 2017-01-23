//
//  RenderPipeline.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "RenderPipeline.h"
#include "Culler.h"
namespace GraphicSys
{
    RenderPipeline::RenderPipeline()
        :m_pCuller(NULL)
    {
        
    }
    RenderPipeline::~RenderPipeline()
    {
        
    }

	void RenderPipeline::AddRenderUnit( const RenderUnit* unit )
	{
		m_pCuller->AddRenderUnit(unit);
	}

	void RenderPipeline::RemoveRenderUnit( const RenderUnit* unit )
	{
		m_pCuller->RemoveRenderUnit(unit);
	}




}