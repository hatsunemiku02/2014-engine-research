//
//  Culler.h
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_Culler_h
#define Catfish_Culler_h
#include <map>
#include "GraphicDllCommon.h"
namespace GraphicSys
{
    class RenderUnit;
    class GRAPHIC_API Culler
    {
    public:
        Culler()
        {
            
        }
        ~Culler()
        {
            
        }
		virtual void AddRenderUnit(const RenderUnit* unit) = 0;
		virtual void RemoveRenderUnit(const RenderUnit* unit) = 0;

        virtual void Cull( void* pararm,std::multimap<unsigned int,RenderUnit*>& outUnits) = 0;
    protected:
    
    };
}


#endif
