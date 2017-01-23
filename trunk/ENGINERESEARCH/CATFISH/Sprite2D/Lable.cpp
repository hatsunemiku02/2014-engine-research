//
//  Lable.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Lable.h"
#include "MeshRes.h"
#include "ShaderRes.h"
#include "ResMgr.h"
#include "Font.h"
#include "RenderUnit.h"
#include "SimplePipeline.h"
#include "PrimitiveGroup.h"
#include "GlesDevice.h"
#include "Texture.h"
#include "ImageRes.h"
#include "cavans.h"
namespace Sprite
{
    Lable::Lable()
    :m_pRU(NULL)
    ,m_pTexBuffer(NULL)
    ,m_pTexture(NULL)
    ,m_bShow(false)
    {
        
    }
    
    Lable::~Lable()
    {
        Hide();
        if(m_pTexBuffer)
        {
            delete[] m_pTexBuffer;
            m_pTexBuffer = NULL;
        }
        if(m_pTexture)
        {
            GraphicCore::GLTexture::DestoryTexture(m_pTexture);
            delete m_pTexture;
            m_pTexture = NULL;
        }
        if(m_pRU)
        {
            delete m_pRU;
        }
    }
    
    Lable* Lable::CreateLable(const std::wstring& content,unsigned int width,unsigned int height,const Math::vector2i& pos ,const Math::vector2f& scale,float rot,int lvl)
    {
        Lable* ret = NULL;
        ret = new Lable();
        ret->m_Content = content;
        ret->m_Level = lvl;
        ret->m_Position = pos;
        ret->m_Scale = scale;
        ret->m_Size =  Math::vector2i(width,height);

        ret->m_pTexBuffer = new unsigned char[height*width];
        ret->m_pMeshRectRes = Resource::ResMgr::GetInstance().GetRes<Resource::MeshRes>(Resource::DefaultRect);
        ret->m_pGpuProgramRes = Resource::ResMgr::GetInstance().GetRes<Resource::GpuProgramRes>(Resource::FontShader);
        ret->m_pTexture = FontSys::FontSystem::GetInstance().GetTextureForString(content,width,height,ret->m_pTexBuffer);
        
        Math::vector2i _screenSize = GraphicCore::GlesDevice::GetInstance().GetScreenSize();
        Math::vector2i _cavansSize = Cavans::GetInstance().GetCavansSize();
        
        Math::vector2i _texSize;
        _texSize[0] = ret->m_pTexture->GetWidth();
        _texSize[1] = ret->m_pTexture->GetHeight();
        
        Math::vector2f _sizeScaleFactor ;
        _sizeScaleFactor[0] = (float)_texSize[0]/(float)_cavansSize[0];//*((float)_screenSize.m_x/(float)_cavansSize.m_x);
        _sizeScaleFactor[1] = (float)_texSize[1]/(float)_cavansSize[1];//*((float)_screenSize.m_y/(float)_cavansSize.m_y);
		_sizeScaleFactor[0] = scale[0] * _sizeScaleFactor[0];
		_sizeScaleFactor[1] = scale[1] * _sizeScaleFactor[1];
        
        Math::vector2f _posScaleFactor ;
        _posScaleFactor[0] = (float)pos[0]/(float)_cavansSize[0];//*((float)_screenSize.m_x/(float)_cavansSize.m_x);
        _posScaleFactor[1] = (float)pos[1]/(float)_cavansSize[1];//*((float)_screenSize.m_y/(float)_cavansSize.m_y);
        

        ret->m_pRU = new GraphicSys::RenderUnit();
        ret->m_pRU->SetParam("_pos", _posScaleFactor);
        ret->m_pRU->SetParam("_scale", _sizeScaleFactor);
        ret->m_pRU->SetParam("s_texture", ret->m_pTexture);
        
        ret->m_pRU->SetGPUPro(ret->m_pGpuProgramRes->GetGpuProgram());
        ret->m_pRU->SetVBO( ret->m_pMeshRectRes->GetPrimitiveGroup()->GetVBO(0));
        ret->m_pRU->SetIBO( ret->m_pMeshRectRes->GetPrimitiveGroup()->GetIBO(0));
        
        Math::vector2f max = _posScaleFactor+_sizeScaleFactor;
        Math::vector2f min = _posScaleFactor-_sizeScaleFactor;
        ret->m_pRU->SetCullParam(ret->m_Level, max, min);
        
        return ret;
    }
    
    void Lable::ChangeContent(const std::wstring& content)
    {
        m_Content = content;
               if(m_pTexture)
        {
            GraphicCore::GLTexture::DestoryTexture(m_pTexture);
            
            delete m_pTexture;
            m_pTexture = NULL;
        }
        m_pTexture = FontSys::FontSystem::GetInstance().GetTextureForString(m_Content,m_Size[0],m_Size[1],m_pTexBuffer);
        if(m_pRU)
        {
            m_pRU->SetParam("s_texture", m_pTexture);
            
        }
    }

    void Lable::Show()
    {
        if(m_bShow)
        {
            return;
        }
        
        m_bShow = true;
        GraphicSys::SimplePipeline::GetInstance().AddRenderUnit( this->m_pRU);
    }
    
    void Lable::Hide()
    {
        if(!m_bShow)
        {
            return;
        }
        
        m_bShow = false;
        GraphicSys::SimplePipeline::GetInstance().RemoveRenderUnit( this->m_pRU);
    }

}