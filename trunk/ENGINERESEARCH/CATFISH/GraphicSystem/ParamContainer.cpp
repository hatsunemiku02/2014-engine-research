//
//  ParamContainer.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "ParamContainer.h"
#include "Texture.h"
namespace GraphicSys
{

    ParamContainer::ParamContainer()
    {
        
    }
    
    ParamContainer::~ParamContainer()
    {
        
    }
    
    void ParamContainer::SetParam(const std::string& name,const vec2f& vec2)
    {
        std::map<std::string,ParamContainer::vec2f>::iterator itr;
        itr = m_mapVec2Params.find(name);
        if(itr!=m_mapVec2Params.end())
        {
            itr->second = vec2;
        }
        else
        {
            m_mapVec2Params.insert(std::make_pair(name, vec2));
        } 
    }

	void ParamContainer::SetParam( const std::string& name,const ParamContainer::vec4f& vec4 )
	{
		std::map<std::string,ParamContainer::vec4f>::iterator itr;
		itr = m_mapVec4Params.find(name);
		if(itr!=m_mapVec4Params.end())
		{
			itr->second = vec4;
		}
		else
		{
			m_mapVec4Params.insert(std::make_pair(name, vec4));
		}
	}

	void ParamContainer::SetParam( const std::string& name,const matrix44f& mat4 )
	{
		std::map<std::string,matrix44f>::iterator itr;
		itr = m_mapMat4Params.find(name);
		if(itr!=m_mapMat4Params.end())
		{
			itr->second = mat4;
		}
		else
		{
			m_mapMat4Params.insert(std::make_pair(name, mat4));
		}
	}
    
    void ParamContainer::SetParam(const std::string& name,const GraphicCore::GLTexture* tex)
    {
        
        std::map<std::string,GraphicCore::GLTexture*>::iterator itr;
        itr = m_mapTexs.find(name);
        if(itr!=m_mapTexs.end())
        {
            itr->second = (GraphicCore::GLTexture*)tex;
        }
        else
        {
            m_mapTexs.insert(std::make_pair(name, (GraphicCore::GLTexture*)tex));
        }
    }

    const void* ParamContainer::GetParam(const std::string& name) const
    {
        void * ret = NULL;
        ret = (void*)GetParamVec2(name);
		if(!ret)
		{
			ret = (void*)GetParamVec4(name);
		}
		if(!ret)
		{
			ret = (void*)GetParamMat4(name);
		}
        if(!ret)
        {
            ret = (void*)GetTex(name);
        }
        return ret;
    }

    
    const ParamContainer::vec2f* ParamContainer::GetParamVec2(const std::string& name) const
    {
        std::map<std::string,ParamContainer::vec2f>::const_iterator itr;
        itr = m_mapVec2Params.find(name);
        if(itr!=m_mapVec2Params.cend())
        {
            return &itr->second;
        }
        return NULL;
    }
    
    const GraphicCore::GLTexture* ParamContainer::GetTex(const std::string& name) const
    {
        std::map<std::string,GraphicCore::GLTexture*>::const_iterator itr;
        itr = m_mapTexs.find(name);
        if(itr!=m_mapTexs.cend())
        {
            return (*itr).second;
        }
        return NULL;
    }


	const ParamContainer::vec4f* ParamContainer::GetParamVec4( const std::string& name ) const
	{
		std::map<std::string,ParamContainer::vec4f>::const_iterator itr;
		itr = m_mapVec4Params.find(name);
		if(itr!=m_mapVec4Params.cend())
		{
			return &itr->second;
		}
		return NULL;
	}



	const matrix44f* ParamContainer::GetParamMat4( const std::string& name ) const
	{
		std::map<std::string,matrix44f>::const_iterator itr;
		itr = m_mapMat4Params.find(name);
		if(itr!=m_mapMat4Params.cend())
		{
			return &itr->second;
		}
		return NULL;
	}

}