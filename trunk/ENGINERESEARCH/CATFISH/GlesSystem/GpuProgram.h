#ifndef GPUPROGRAM_H_
#define GPUPROGRAM_H_
#include "Shader.h"
#include "DrawEnums.h"
#include <map>
#include <string>

namespace GraphicCore
{
	class GlesDevice;
	class RENDERER_API GpuProgram
	{
	public:
		struct UniformParam
		{
			UniformParam(int l,int s,int t,const char* n):
				 loc (l)
				,size(s)
				,type(t)
				,name(n)
				,value(NULL)
				,applied(false)
			{

			}
			int loc;
			int size;
			int type;
			std::string name;
			bool applied;
			void* value;

			unsigned int GetValueSize();
		};

		struct AttributeParam
		{
			AttributeParam(int l,int s,int t,const char* n):
				loc (l)
				,size(s)
				,type(t)
				,name(n)
			{

			}
			int loc;
			int size;
			int type;
			std::string name;
		};
	public:
		GpuProgram();
		~GpuProgram();
		static	GpuProgram* CreateGpuPragram( GLShader& pVertexShd, GLShader& pFragmentShd);
		static	void DestoryGpuPragram(GpuProgram* gpg);
		bool PhraseAttSemetic(const char* _heaedr);



		const std::map<std::string,GpuProgram::AttributeParam>& GetAttMap() const;
		const std::map<std::string,GpuProgram::UniformParam>& GetUniformMap() const;
		bool  SetUniformValue(const std::string& name,const void* value);
		
	protected:
		bool BindAttributeLoc(const AttributeParam& param,int loc);

		bool GetAttributes(std::map<std::string,AttributeParam>& outAttmap);
		bool GetUniforms(std::map<std::string,UniformParam>& outUniformmap);

	protected:
		GLShader m_VertexShader;
		GLShader m_FragmentShader;
		EGLint m_GpuProgram;

		std::map<std::string,AttributeParam> m_AttMap;
		std::map<std::string,UniformParam> m_UniformMap;
		std::map<int,TextureUnit> m_TextureUnitMap;
		friend class GlesDevice;
	private:
	};

	inline const std::map<std::string,GpuProgram::AttributeParam>& GpuProgram::GetAttMap() const
	{
		return m_AttMap;
	}


	inline const std::map<std::string,GpuProgram::UniformParam>& GpuProgram::GetUniformMap() const
	{
		return m_UniformMap;
	}

}

#endif