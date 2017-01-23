#ifndef _MESHRES_H_
#define _MESHRES_H_

#include "Res.h"


namespace GraphicCore
{
	class PrimitiveGroup;
	class VertexLayout;
}
namespace Resource
{

	class RES_API MeshRes:public Res
	{
	public:
		MeshRes();
		~MeshRes();

        GraphicCore::PrimitiveGroup*  GetPrimitiveGroup()
        {
            return m_pPrimitiveGroup;
        }
	protected:

		virtual bool Load(const std::string& path);
		bool LoadDefaultRect();
		GraphicCore::PrimitiveGroup* m_pPrimitiveGroup;


		GraphicCore::VertexLayout GetLayout(char* layout);

		friend class ResMgr;
	private:
	};

}
#endif