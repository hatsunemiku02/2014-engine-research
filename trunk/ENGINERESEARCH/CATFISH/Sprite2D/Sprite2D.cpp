#include "Sprite2D.h"
#include "ResMgr.h"
#include "ImageRes.h"
#include "Sprite2DPipeLine.h"
#include "MeshRes.h"
#include "ShaderRes.h"
#include "RenderUnit.h"
#include "SimplePipeline.h"
#include "ImageRes.h"
#include "PrimitiveGroup.h"
#include "GlesDevice.h"
#include "Texture.h"
#include "ImageRes.h"
#include "cavans.h"
namespace Sprite
{
    Sprite2D::Sprite2D()
    :m_pRU(NULL)
    ,m_bShow(false)
    {
        
    }
    Sprite2D::~Sprite2D()
    {
        Hide();
        if(m_pRU)
        {
            
            delete m_pRU;
        }

    }
    Sprite2D* Sprite2D::CreateSprite2D(const std::string& texPath,const Math::vector2i& pos ,const Math::vector2f& scale,float rot,int lvl)
    {
        Sprite2D* ret = new Sprite2D();
        ret->m_pMeshRectRes = Resource::ResMgr::GetInstance().GetRes<Resource::MeshRes>(Resource::DefaultRect);
        ret->m_pGpuProgramRes = Resource::ResMgr::GetInstance().GetRes<Resource::GpuProgramRes>(Resource::Sprite2DShader);
        
        ret->SetTexture(texPath);
        ret->SetPosition(pos);
        ret->SetScale(scale);
        ret->SetRotation(rot);
        ret->SetLevel(lvl);

        Math::vector2i _screenSize = GraphicCore::GlesDevice::GetInstance().GetScreenSize();
        Math::vector2i _cavansSize = Cavans::GetInstance().GetCavansSize();
        
        Math::vector2i _texSize;
        _texSize[0] = ret->m_pTextureRes->GetTexture()->GetWidth();
        _texSize[1] = ret->m_pTextureRes->GetTexture()->GetHeight();
        
        Math::vector2f _sizeScaleFactor ;
        _sizeScaleFactor[0] = ((float)_texSize[0]/(float)_cavansSize[0]);//*((float)_screenSize.m_x/(float)_cavansSize.m_x);
        _sizeScaleFactor[1] = ((float)_texSize[1]/(float)_cavansSize[1]);//*((float)_screenSize.m_y/(float)_cavansSize.m_y);
        _sizeScaleFactor[0] = scale[0] * _sizeScaleFactor[0];
		_sizeScaleFactor[1] = scale[1] * _sizeScaleFactor[1];

        Math::vector2f _posScaleFactor ;
        _posScaleFactor[0] = ((float)pos[0]/(float)_cavansSize[0]);//*((float)_screenSize.m_x/(float)_cavansSize.m_x);
        _posScaleFactor[1] = ((float)pos[1]/(float)_cavansSize[1]);//*((float)_screenSize.m_y/(float)_cavansSize.m_y);

        
        ret->m_pRU = new GraphicSys::RenderUnit();
        ret->m_pRU->SetParam("_pos", _posScaleFactor);
        ret->m_pRU->SetParam("_scale", _sizeScaleFactor);
        ret->m_pRU->SetParam("s_texture", ret->m_pTextureRes->GetTexture());
        
        ret->m_pRU->SetGPUPro(ret->m_pGpuProgramRes->GetGpuProgram());
        ret->m_pRU->SetVBO( ret->m_pMeshRectRes->GetPrimitiveGroup()->GetVBO(0));//only one and must be one
        ret->m_pRU->SetIBO( ret->m_pMeshRectRes->GetPrimitiveGroup()->GetIBO(0));
        
        Math::vector2f max = _posScaleFactor+_sizeScaleFactor;
        Math::vector2f min = _posScaleFactor-_sizeScaleFactor;
        ret->m_pRU->SetCullParam(ret->m_Level, max, min);
        
        
        return ret;
    }
    void Sprite2D::Show()
    {
        if(m_bShow)
        {
            return;
        }
        m_bShow = true;
        GraphicSys::SimplePipeline::GetInstance().AddRenderUnit( this->m_pRU);
    }
    
    void Sprite2D::Hide()
    {
        if(!m_bShow)
        {
            return;
        }

        m_bShow = false;
        GraphicSys::SimplePipeline::GetInstance().RemoveRenderUnit( this->m_pRU);
    }

	void Sprite2D::SetPosition( const Math::vector2i& pos )
	{
		m_Position = pos;
        if(m_pRU)
        {
            Math::vector2i _cavansSize = Cavans::GetInstance().GetCavansSize();
            Math::vector2i _screenSize = GraphicCore::GlesDevice::GetInstance().GetScreenSize();
   
            Math::vector2f _posScaleFactor ;
            _posScaleFactor[0] = (float)pos[0]/(float)_cavansSize[0];
            _posScaleFactor[1] = (float)pos[1]/(float)_cavansSize[1];

            m_pRU->SetParam("_pos", _posScaleFactor);
        }
	}

	void Sprite2D::SetScale( const Math::vector2f& scale )
	{
		m_Scale = scale;
        if(m_pRU)
        {
            Math::vector2i _screenSize = GraphicCore::GlesDevice::GetInstance().GetScreenSize();
            Math::vector2i _cavansSize = Cavans::GetInstance().GetCavansSize();
            Math::vector2i _texSize;
            _texSize[0] = m_pTextureRes->GetTexture()->GetWidth();
            _texSize[0] = m_pTextureRes->GetTexture()->GetHeight();
            
            Math::vector2f _sizeScaleFactor ;
            _sizeScaleFactor[0] = ((float)_texSize[0]/(float)_cavansSize[0]);//*((float)_screenSize.m_x/(float)_cavansSize.m_x);
            _sizeScaleFactor[1] = ((float)_texSize[1]/(float)_cavansSize[1]);//*((float)_screenSize.m_y/(float)_cavansSize.m_y);
			_sizeScaleFactor[0] = scale[0] * _sizeScaleFactor[0];
			_sizeScaleFactor[1] = scale[1] * _sizeScaleFactor[1];

            m_pRU->SetParam("_scale", _sizeScaleFactor);
        }
	}

	void Sprite2D::SetRotation( float rot )
	{
		m_Rotation = rot;
	}

	void Sprite2D::SetLevel( int lvl )
	{
		m_Level = lvl;
	}

	void Sprite2D::SetTexture( const std::string& texPath )
	{
		m_pTextureRes = Resource::ResMgr::GetInstance().GetRes<Resource::ImageRes>(texPath.c_str());
        if(m_pRU)
        {
             m_pRU->SetParam("s_texture", m_pTextureRes->GetTexture());
        }
 
	}
    
}