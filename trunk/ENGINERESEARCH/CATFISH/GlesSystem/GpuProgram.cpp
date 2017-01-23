#include "GpuProgram.h"
#include "GlesDevice.h"
#include "OpenglHeader.h"
namespace GraphicCore
{

	unsigned int GpuProgram::UniformParam::GetValueSize()
	{
		switch (type)
		{
		case GL_FLOAT:
			return sizeof(float);
			break;
		case GL_FLOAT_VEC2:
			return sizeof(float)*2;
			break;
		case GL_FLOAT_VEC3:
			return sizeof(float)*3;
			break;
		case GL_FLOAT_VEC4:
			return sizeof(float)*4;
			break;
		case GL_FLOAT_MAT3:
			return sizeof(float)*9;
			break;
		case GL_FLOAT_MAT4:
			return sizeof(float)*16;
			break;
		case GL_SAMPLER_2D:
			return 0;
			break;
		default:
			return 0;
			break;
		}
		return 0;
	}





	GpuProgram::GpuProgram()
		:m_VertexShader()
		,m_FragmentShader()
	{

	}

	GpuProgram::~GpuProgram()
	{

	}

	GpuProgram* GpuProgram::CreateGpuPragram(  GLShader& pVertexShd, GLShader& pFragmentShd )
	{
		GpuProgram* pOut = new GpuProgram();
		pOut->m_VertexShader = pVertexShd;
		pOut->m_FragmentShader = pFragmentShd;
		pOut->m_GpuProgram = glCreateProgram();
		CHECKGLERROR;
		glAttachShader(pOut->m_GpuProgram,pOut->m_VertexShader.m_Shader);
		CHECKGLERROR;
		glAttachShader(pOut->m_GpuProgram,pOut->m_FragmentShader.m_Shader);
		CHECKGLERROR;
		glLinkProgram(pOut->m_GpuProgram);
		CHECKGLERROR;
		int compiled = 0;
		glGetProgramiv(pOut->m_GpuProgram,GL_LINK_STATUS,&compiled);
		if(compiled==0)
		{
			GLint iLen;
			char* pErrorLog = NULL;

			glGetProgramiv(pOut->m_GpuProgram, GL_INFO_LOG_LENGTH, &iLen);

			pErrorLog = new char[iLen];

			glGetProgramInfoLog(pOut->m_GpuProgram, iLen, NULL, pErrorLog);

			glDeleteProgram(pOut->m_GpuProgram);
			MERROR;
		}
		pOut->GetAttributes(pOut->m_AttMap);
		pOut->GetUniforms(pOut->m_UniformMap);
// 		glDeleteShader(pOut->m_VertexShader.m_Shader);
// 		CHECKGLERROR;
// 		glDeleteShader(pOut->m_FragmentShader.m_Shader);
// 		CHECKGLERROR;
		return pOut;
	}

	bool GpuProgram::GetAttributes( std::map<std::string,AttributeParam>& outAttmap )
	{
		GLint AttNum;
		GLint AttNameMaxLen;
		char* AttName;
		glGetProgramiv(m_GpuProgram,GL_ACTIVE_ATTRIBUTES ,&AttNum);
		CHECKGLERROR;
		glGetProgramiv(m_GpuProgram,GL_ACTIVE_ATTRIBUTE_MAX_LENGTH ,&AttNameMaxLen);
		CHECKGLERROR;
		AttName = new char[AttNameMaxLen];

		GLint  size = -1;
		GLenum type = -1;
		int loc = -1;
		for(int i=0;i<AttNum;i++)
		{
			glGetActiveAttrib(m_GpuProgram,i,AttNameMaxLen,NULL,&size,&type,AttName);
			CHECKGLERROR;
			loc =  glGetAttribLocation(m_GpuProgram,AttName);
			CHECKGLERROR;
			outAttmap.insert(std::make_pair(AttName,AttributeParam(loc,size,type,AttName)) );

		}
		delete[] AttName;
		return true;
	}

	bool GpuProgram::GetUniforms( std::map<std::string,UniformParam>& outUniformmap )
	{
		GLint UniformNum;
		GLint UniformNameMaxLen;
		char* UniformName;
		glGetProgramiv(m_GpuProgram,GL_ACTIVE_UNIFORMS,&UniformNum);
		CHECKGLERROR;
		glGetProgramiv(m_GpuProgram,GL_ACTIVE_UNIFORM_MAX_LENGTH,&UniformNameMaxLen);
		CHECKGLERROR;
		UniformName = new char[UniformNameMaxLen];
		GLint  size = -1;
		GLenum type = -1;
		int loc = -1;
		TextureUnit texUnit= TU_TEX0;
		for(int i=0;i<UniformNum;i++)
		{
			glGetActiveUniform(m_GpuProgram,i,UniformNameMaxLen,NULL,&size,&type,UniformName);
			CHECKGLERROR;
			loc =  glGetUniformLocation(m_GpuProgram,UniformName);
			CHECKGLERROR;
			outUniformmap.insert(std::make_pair(UniformName,UniformParam(loc,size,type,UniformName)) );


			if(type == GL_SAMPLER_2D||type == GL_SAMPLER_CUBE)
			{
				m_TextureUnitMap.insert(std::make_pair(loc,texUnit));
				texUnit = (TextureUnit)(texUnit+1);
			}
		}
		delete[] UniformName;
		return true;
	}

	bool GpuProgram::BindAttributeLoc( const AttributeParam& param,int loc )
	{
		IFERROR(GlesDevice::GetInstance().GetMaxVertexAtt()<loc)
		glBindAttribLocation(m_GpuProgram,loc,param.name.c_str());
		CHECKGLERROR;
		return true;
	}

	bool GpuProgram::PhraseAttSemetic( const char* _heaedr )
	{
		return false;
	}

	bool GpuProgram::SetUniformValue(const std::string& name,const void* value)
	{
		std::map<std::string,UniformParam>::iterator itr = m_UniformMap.find(name);
		if(itr==m_UniformMap.end())
		{
			return false;
		}
		GlesDevice::GetInstance().SetCurrentGPG(this);
		std::map<int,TextureUnit>::iterator unitItr;
		switch (itr->second.type)
		{
		case GL_FLOAT:
			glUniform1fv(itr->second.loc,itr->second.size,(GLfloat*)value);
			break;
		case GL_FLOAT_VEC2:
			glUniform2fv(itr->second.loc,itr->second.size,(GLfloat*)value);
			break;
		case GL_FLOAT_VEC3:
			glUniform3fv(itr->second.loc,itr->second.size,(GLfloat*)value);
			break;
		case GL_FLOAT_VEC4:
			glUniform4fv(itr->second.loc,itr->second.size,(GLfloat*)value);
			break;
		case GL_FLOAT_MAT3:
			glUniformMatrix3fv(itr->second.loc,itr->second.size,false,(GLfloat*)value);
			break;
		case GL_FLOAT_MAT4:
			glUniformMatrix4fv(itr->second.loc,itr->second.size,false,(GLfloat*)value);
			break;
		case GL_SAMPLER_2D:
		    unitItr = m_TextureUnitMap.find(itr->second.loc);
			GlesDevice::GetInstance().ActiveTextureUnit(unitItr->second);
			GlesDevice::GetInstance().BindTexture(TT_TEXTURE2D,(GLTexture*)value);
			glUniform1i(itr->second.loc,unitItr->second);
			break;
		default:
			IFERROR(true);
			break;
		}
		CHECKGLERROR;
		return true;
	}

	void GpuProgram::DestoryGpuPragram( GpuProgram* gpg )
	{
		gpg->m_AttMap.clear();
		gpg->m_UniformMap.clear();
		glDeleteProgram(gpg->m_GpuProgram);
	}

}