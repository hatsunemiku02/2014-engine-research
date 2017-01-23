//
//  RenderPipeline.h
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_RenderPipeline_h
#define Catfish_RenderPipeline_h
#include <map>
#include "GraphicDllCommon.h"

namespace GraphicSys
{
    class RenderUnit;
    class Culler;
    class GRAPHIC_API RenderPipeline
    {
    public:
        ~RenderPipeline();
        
        virtual void AddRenderUnit(const RenderUnit* unit);
        virtual void RemoveRenderUnit(const RenderUnit* unit);
        
        virtual void RenderAll() = 0;
    protected:
        RenderPipeline();
      
        
        Culler* m_pCuller;
    };

    
}


#endif
