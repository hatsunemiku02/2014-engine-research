//
//  Lable.h
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_Lable_h
#define Catfish_Lable_h
#include <string>
#include "Font.h"
#include "../Math/cmlmath.h"
namespace Resource
{
    class MeshRes;
    class GpuProgramRes;
}
namespace GraphicCore {
    class GLTexture;
}
namespace GraphicSys
{
    class RenderUnit;
}
namespace Sprite
{
    class Lable
    {
    public:
        Lable();
        ~Lable();
        

        static Lable* CreateLable(const std::wstring& content,unsigned int width,unsigned int height,const Math::vector2i& pos ,const Math::vector2f& scale,float rot,int lvl);
        
        void ChangeContent(const std::wstring& content);
        void Show();
        void Hide();

    protected:   
        Math::vector2i m_Position; // this pos is from -1 --- 1
		Math::vector2f m_Scale;
        Math::vector2i m_Size;
		float m_Rotation;
		int m_Level;//display level
        std::wstring m_Content;
        void*        m_pTexBuffer;
        
        Resource::MeshRes* m_pMeshRectRes;
        Resource::GpuProgramRes* m_pGpuProgramRes;
        GraphicCore::GLTexture* m_pTexture;
        GraphicSys::RenderUnit* m_pRU;
        bool m_bShow;
    };
    
}
#endif
