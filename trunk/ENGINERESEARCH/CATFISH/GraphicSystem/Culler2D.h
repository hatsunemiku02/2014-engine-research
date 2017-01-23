//
//  Culler2D.h
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_Culler2D_h
#define Catfish_Culler2D_h
#include "Culler.h"
#include "cmlmath.h"

namespace GraphicSys
{
    class RenderUnit;
    class GRAPHIC_API Culler2D:public Culler
    {
    public:
        Culler2D()
        {
            
        }
        ~Culler2D()
        {
            
        }
        
        void SetArea(const vector2f& max,const vector2f& min)
        {
            m_Max = max;
            m_Min = min;
        }
        
        virtual void Cull( void* pararm,std::multimap<unsigned int,RenderUnit*>& outUnits);
		virtual void AddRenderUnit(const RenderUnit* unit)
		{
			m_vecRenderUnit.insert( std::make_pair((intptr_t)unit, (RenderUnit*)unit) );
		}
		virtual void RemoveRenderUnit(const RenderUnit* unit)
		{
			if(m_vecRenderUnit.find((intptr_t)unit)==m_vecRenderUnit.end())
			{
				return;
			}
			m_vecRenderUnit.erase((intptr_t)unit);
		}
    protected:

		std::map<unsigned int,RenderUnit*> m_vecRenderUnit;
        vector2f m_Max;
        vector2f m_Min;
    };
}

#endif
