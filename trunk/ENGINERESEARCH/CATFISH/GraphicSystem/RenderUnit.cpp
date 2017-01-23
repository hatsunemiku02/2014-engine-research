//
//  RenderUnit.cpp
//  Catfish
//
//  Created by songqi on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "RenderUnit.h"
#include "GpuProgram.h"
#include "Material.h"
namespace GraphicSys
{
    RenderUnit::RenderUnit()
     :m_pVBO(NULL)
     ,m_pIBO(NULL)
	 ,m_pMaterial(NULL)
    {
        
    }
    RenderUnit::~RenderUnit()
    {
        
    }

    void RenderUnit::SetCullParam(int lvl,const vector2f& max,const vector2f& min)
    {
        m_RenderLevel = lvl;
		vector2f size = (max-min)/2;
		vector2f center = (max+min)/2;
		vector3f size3;
		vector3f center3;
		size3[0] = size[0];
		size3[1] = size[1];
		size3[2] = 1;
		center3[0] = center[0];
		center3[1] = center[1];
		center3[2] = 1;

		m_BBox.Set(size3,center3);
    }

	void RenderUnit::SetCullParam( int lvl,const vector3f& max,const vector3f& min )
	{
		m_RenderLevel = lvl;
		vector3f size3 = (max-min)/2;
		vector3f center3 = (max+min)/2;
		m_BBox.Set(size3,center3);
	}

	void RenderUnit::ApplyParamToGpu()
	{
		m_pMaterial->ApplyParamToGpu();
	}


}