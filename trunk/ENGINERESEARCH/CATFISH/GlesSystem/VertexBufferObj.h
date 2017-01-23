#ifndef VERTEXBUFFEROBJ_H_
#define VERTEXBUFFEROBJ_H_
#include "DrawEnums.h"
#include "VertexLayout.h"
namespace GraphicCore
{
	/***********************************************************
	we decide that the attribute's semetic to loc is as :
	0 : position
	1 : color
	2 : normal
	3 : tangent
	4 : binormal 
	5 : tex0
	........
	if one of the att is empty,the loc after it will come
	to front.
	************************************************************/
	typedef unsigned int GLuint;
	class GlesDevice;
	class RENDERER_API GLVertexBufferObj
	{
	public:
		GLVertexBufferObj();
		~GLVertexBufferObj();
		static	GLVertexBufferObj* CreateVertexBuffer(void* vertexBuffer,int numb, int sizz,const VertexLayout& layout,StroageMode mode=SM_STATIC);
		static void  DestoryVertexBuffer(GLVertexBufferObj* pVbo);
// 		template<typename T> Flush( T* vertex )
// 		{
// 			m_VertexLayout = T::GetLayout();
// 		}
	protected:
		GLuint m_VBO;
		VertexLayout m_VertexLayout;
		unsigned int m_VertexNum;
		unsigned int m_VertexSize;
		friend class GlesDevice;
	};

// 	class Vertex
// 	{
// 	public:
// 		static VertexLayout GetLayout()
// 		{
// 			return;
// 		}
// 	};
// 	class VertexColor
// 	{
// 	public:
// 		static VertexLayout GetLayout()
// 		{
// 			return Vertex::GetLayout() + ..;
// 		}
// 	};
}
#endif