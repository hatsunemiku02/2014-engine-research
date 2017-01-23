//
//  Culler2D.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Culler2D.h"
#include "RenderUnit.h"




namespace GraphicSys
{
    void Culler2D::Cull( void* pararm,std::multimap<unsigned int,RenderUnit*>& outUnits)
    {
        outUnits.clear();
        std::map<unsigned int,RenderUnit*>::const_iterator iter;
        iter = m_vecRenderUnit.cbegin();
        for(;iter!=m_vecRenderUnit.end();iter++)
        {
            if( iter->second->GetMin()[0]>m_Max[0]&&iter->second->GetMin()[1]>m_Max[1])
            {
                continue;
            }
            if( iter->second->GetMax()[0]<m_Min[0]&&iter->second->GetMax()[1]<m_Min[1])
            {
                continue;
            }
            outUnits.insert(std::make_pair(iter->second->GetRenderLevel(),iter->second));
        }

    }


}