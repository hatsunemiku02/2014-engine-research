#ifndef _PRIMITIVEGROUP_H_
#define _PRIMITIVEGROUP_H_

#include <vector>
#include "GDllCommon.h"
namespace GraphicCore
{
	class GLVertexBufferObj;
	class GLIndexBufferObj;
	class RENDERER_API PrimitiveGroup
	{
	public:
		PrimitiveGroup();
		~PrimitiveGroup();

		static PrimitiveGroup* CreatePrimitiveGroup(const std::vector<GLVertexBufferObj*>& vecVBO,const std::vector<GLIndexBufferObj*>& vecIBO);
        
        unsigned int GetSubMeshCount()
        {
            return m_pVecVBO.size();
        }
        GLVertexBufferObj* GetVBO(unsigned int index)
        {
            return m_pVecVBO[index];
        }
        
        GLIndexBufferObj* GetIBO(unsigned int index)
        {
            return   m_pVecIBO[index];
        }

	protected:
		std::vector<GLVertexBufferObj*> m_pVecVBO;
		std::vector<GLIndexBufferObj*> m_pVecIBO;
	private:
	};

}
#endif