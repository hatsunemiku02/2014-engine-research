//
//  EasyPipeline.h
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_SimplePipeline_h
#define Catfish_SimplePipeline_h

#include "RenderPipeline.h"


namespace GraphicSys
{
    class RenderUnit;
    class GRAPHIC_API SimplePipeline:public RenderPipeline
    {
    public:
        static SimplePipeline& GetInstance()
        {
            static SimplePipeline instance;
            return instance;
        }
        ~SimplePipeline();
        
        virtual void RenderAll();
    protected:
        SimplePipeline();
        
                
    };
    
}
#endif
