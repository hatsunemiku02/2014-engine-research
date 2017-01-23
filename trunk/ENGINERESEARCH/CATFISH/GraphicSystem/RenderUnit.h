//
//  RenderUnit.h
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_RenderUnit_h
#define Catfish_RenderUnit_h

#include "ParamContainer.h"
#include "BoxAABB.h"

namespace GraphicCore {
    class GpuProgram;
    class GLVertexBufferObj;
    class GLIndexBufferObj;
}


namespace GraphicSys
{
    class Material;
    class SimplePipeline;
    class GRAPHIC_API RenderUnit
    {
    public:
        RenderUnit();
        ~RenderUnit();
        
        void SetMaterial( Material* pMat)
		{
			m_pMaterial = pMat;
		}
        void SetVBO( GraphicCore::GLVertexBufferObj* pVBO)
        {
            m_pVBO = pVBO;
        }
        void SetIBO(GraphicCore::GLIndexBufferObj* pIBO)
        {
            m_pIBO = pIBO;
        }

        void SetCullParam(int lvl,const vector2f& max,const vector2f& min);
        void SetCullParam(int lvl,const vector3f& max,const vector3f& min);

		void SetCullParam(int lvl,const Math::BoxAABB& box)
		{
			m_RenderLevel = lvl;
			m_BBox = box;
		}

        vector3f GetMax()
        {
            return m_BBox.GetMax();
        }
        
        vector3f GetMin()
        {
            return m_BBox.GetMin();
        }
        
		const Math::BoxAABB& GetBBox() const
		{
			return m_BBox;
		}

        int GetRenderLevel()
        {
            return m_RenderLevel;
        }
		Material* GetMaterial()
		{
			return m_pMaterial;
		}
		void ApplyParamToGpu();

    protected:
        
		Material* m_pMaterial;
        GraphicCore::GLVertexBufferObj* m_pVBO;
        GraphicCore::GLIndexBufferObj*  m_pIBO;
        
        int m_RenderLevel;
		Math::BoxAABB m_BBox;
        friend class SimplePipeline;
		friend class ForwardRenderPipeline;
    };
    
}
#endif
