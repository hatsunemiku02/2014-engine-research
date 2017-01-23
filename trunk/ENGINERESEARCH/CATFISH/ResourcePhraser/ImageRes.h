#ifndef _IMAGERES_H_
#define _IMAGERES_H_
#include "Res.h"
#include <string>
namespace GraphicCore
{
	class GLTexture;
}
using namespace GraphicCore;
namespace Resource
{
	class ResMgr;
	class RES_API ImageRes:public Res
	{
	public:
		ImageRes();
		~ImageRes();
		GLTexture* GetTexture();
	protected:
		virtual bool Load(const std::string& path);
	protected:
		
		GLTexture* m_pTexture;
		friend class ResMgr;
	private:
	};


	inline GLTexture* ImageRes::GetTexture()
	{
		return m_pTexture;
	}

}
#endif