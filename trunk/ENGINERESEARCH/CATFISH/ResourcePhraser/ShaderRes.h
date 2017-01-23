#ifndef _SHADERRES_H_
#define _SHADERRES_H_
#include "Res.h"
#include <string>

namespace GraphicCore
{
	class GpuProgram;
}
namespace Resource
{

	class RES_API GpuProgramRes:public Res
	{
	public:
		GpuProgramRes();
		~GpuProgramRes();

        GraphicCore::GpuProgram* GetGpuProgram()
        {
            return m_pGpuProgram;
        }
	protected:

		virtual bool Load(const std::string& path);
		virtual bool LoadDefault2D();
        virtual bool LoadDefaultFont();
		virtual bool LoadDefault3D();
		GraphicCore::GpuProgram* _phraseShader(void* buffer,unsigned int length);
		GraphicCore::GpuProgram* m_pGpuProgram;

		friend class ResMgr;
	private:
	};

}
#endif