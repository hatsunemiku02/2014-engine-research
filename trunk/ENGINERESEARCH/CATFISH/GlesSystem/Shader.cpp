#include "Shader.h"
#include "GlesDevice.h"
#include "OpenglHeader.h"

namespace GraphicCore
{
	GLShader::GLShader()
		:m_Shader(0),
		m_Type(VERTEX)
	{

	}

	GLShader::~GLShader()
	{
		_destory();
	}

	bool GLShader::CreateShader( GLShader::ShaderType type,const char* content )
	{

		m_Type = type;
		m_Shader = glCreateShader(ToEGLShaderType(m_Type));
		CHECKGLERROR;

		glShaderSource(m_Shader,1,&content,NULL);
		CHECKGLERROR;
		glCompileShader(m_Shader);
		GLint complied = 0;
		glGetShaderiv(m_Shader,GL_COMPILE_STATUS,&complied);
		if(complied==0)
		{
			GLint iLen;
			char* pErrorLog = NULL;

			glGetShaderiv(m_Shader, GL_INFO_LOG_LENGTH, &iLen);

			pErrorLog = new char[iLen];

			glGetShaderInfoLog(m_Shader, iLen, NULL, pErrorLog);
            int i = 0;
            i++;
		
		}
		IFERROR(complied==0)
		return true;
	}

	int GLShader::ToEGLShaderType( GLShader::ShaderType type )
	{
		switch(type)
		{
		case VERTEX:
			return GL_VERTEX_SHADER;
		case FRAGMENT:
			return GL_FRAGMENT_SHADER;
		default:
                MERROR;
		}
		return true;
	}

	void GLShader::_destory()
	{
		if(m_Shader!=0)
		{
			glDeleteShader(m_Shader);
			m_Shader = 0;
		}
	}

}