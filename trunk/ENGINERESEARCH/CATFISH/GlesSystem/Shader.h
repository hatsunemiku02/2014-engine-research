#ifndef SHADER_H_
#define SHADER_H_
#include "GDllCommon.h"

typedef int EGLint;

namespace GraphicCore
{
	class GpuProgram;
	class GlesDevice;
	class RENDERER_API GLShader
	{
	public:
		enum ShaderType
		{
			VERTEX,
			FRAGMENT,
		};
		GLShader();
		~GLShader();
		bool CreateShader(GLShader::ShaderType type,const char* content);
		
	protected:
		int ToEGLShaderType(GLShader::ShaderType type);
	protected:

		EGLint m_Shader;
		ShaderType m_Type;

		friend class GpuProgram;
		friend class GlesDevice;
	private:
		void _destory();
	};
}
#endif