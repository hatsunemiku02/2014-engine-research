#include "Material.h"
#include "GpuProgram.h"
#include "ParamContainer.h"
namespace GraphicSys
{
	Material::Material()
	{
		m_pParam = new ParamContainer();
	}

	Material::~Material()
	{
		delete m_pParam;
	}

	void Material::SetParam(const std::string& name,const cml::vector2f& vec2)
	{

		m_pParam->SetParam(name, vec2);
	}

	void Material::SetParam( const std::string& name,const cml::vector4f& vec4 )
	{
		m_pParam->SetParam(name,vec4);
	}

	void Material::SetParam( const std::string& name,const matrix44f& mat4 )
	{
		m_pParam->SetParam(name,mat4);
	}

	void Material::SetParam(const std::string& name,const GraphicCore::GLTexture* tex)
	{
		m_pParam->SetParam(name, tex);
	}

	void Material::ApplyParamToGpu()
	{
		const std::map<std::string,GraphicCore::GpuProgram::UniformParam>& paramMap =  m_pGpuProgram->GetUniformMap();

		std::map<std::string,GraphicCore::GpuProgram::UniformParam>::const_iterator itr = paramMap.cbegin();

		for(;itr!=paramMap.cend();itr++)
		{
			m_pGpuProgram->SetUniformValue(itr->first, m_pParam->GetParam(itr->first));
		}
	}



}