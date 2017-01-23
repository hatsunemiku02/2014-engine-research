#include "PrimitiveGroup.h"
#include "VertexBufferObj.h"
#include "IndexBufferObj.h"
namespace GraphicCore
{
	PrimitiveGroup::PrimitiveGroup()
	{

	}

	PrimitiveGroup::~PrimitiveGroup()
	{

	}

	PrimitiveGroup* PrimitiveGroup::CreatePrimitiveGroup( const std::vector<GLVertexBufferObj*>& vecVBO ,const std::vector<GLIndexBufferObj*>& vecIBO)
	{
		PrimitiveGroup* pOut = new PrimitiveGroup();
		pOut->m_pVecVBO = vecVBO;
		pOut->m_pVecIBO = vecIBO;
		return pOut;
	}

}