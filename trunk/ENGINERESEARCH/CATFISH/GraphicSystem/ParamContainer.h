//
//  ParamContainer.h
//  Catfish
//
//  Created by zhaohang on 14-3-29.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_ParamContainer_h
#define Catfish_ParamContainer_h
#include <map>
#include <string>
#include "cmlmath.h"
#include "GraphicDllCommon.h"
namespace GraphicCore {
    class GLTexture;
}
namespace GraphicSys
{
    class RenderUnit;
    class GRAPHIC_API ParamContainer
    {
        typedef vector2f vec2f;
		typedef vector4f vec4f;
        friend class RenderUnit;
    public:
        
        ParamContainer();
        ~ParamContainer();
        
        void SetParam(const std::string& name,const ParamContainer::vec2f& vec2);
		void SetParam(const std::string& name,const ParamContainer::vec4f& vec4);
		void SetParam(const std::string& name,const matrix44f& mat4);
        void SetParam(const std::string& name,const GraphicCore::GLTexture* tex);
        
        const void* GetParam(const std::string& name) const;
        const vec2f* GetParamVec2(const std::string& name) const;
		const vec4f* GetParamVec4(const std::string& name) const;
		const matrix44f* GetParamMat4(const std::string& name) const;
        const GraphicCore::GLTexture* GetTex(const std::string& name) const;
        
    protected:
        
        
        std::map<std::string,ParamContainer::vec2f> m_mapVec2Params;
		std::map<std::string,ParamContainer::vec4f> m_mapVec4Params;
		std::map<std::string,matrix44f> m_mapMat4Params;
        std::map<std::string,GraphicCore::GLTexture*> m_mapTexs;
        
    };
    
}

#endif
