#pragma once
#include "GraphicDllCommon.h"
#include <string>
#include "cmlmath.h"

namespace GraphicCore
{
	class GLTexture;
	class GpuProgram;
}

namespace GraphicSys
{
	class ParamContainer;
	class GRAPHIC_API Material
	{
	public:
		Material();
		~Material();
		void SetParam(const std::string& name,const cml::vector2f& vec2);
		void SetParam(const std::string& name,const cml::vector4f& vec4);
		void SetParam(const std::string& name,const cml::matrix44f& mat4);
		void SetParam(const std::string& name,const GraphicCore::GLTexture* tex);

		void SetGPUPro(GraphicCore::GpuProgram* pGpu)
		{
			m_pGpuProgram  = pGpu;
		}
		GraphicCore::GpuProgram* GetGpuPro()
		{

			return m_pGpuProgram;
		}

		void ApplyParamToGpu();
	protected:

		ParamContainer* m_pParam;
		GraphicCore::GpuProgram*    m_pGpuProgram;

	private:
	};
}