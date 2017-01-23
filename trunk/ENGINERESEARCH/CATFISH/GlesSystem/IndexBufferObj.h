#ifndef INDEXBUFFEROBJ_H_
#define INDEXBUFFEROBJ_H_
#include "GDllCommon.h"
#include "DrawEnums.h"

namespace GraphicCore
{
	/********************************************************************
	Notice: Only short is supported in index here,I don't think I need
	an int index for now. see GlesDevice::DrawIndexed();
	********************************************************************/
	typedef unsigned int GLuint;
	class GlesDevice;
	class RENDERER_API GLIndexBufferObj
	{
	public:
		GLIndexBufferObj();
		~GLIndexBufferObj();

		static GLIndexBufferObj* CreateIndexBuffer(void* indexBuffer,int numb,int sizz,StroageMode mode=SM_STATIC);
		static void DestoryIndexBuffer(GLIndexBufferObj* pIbo);
	private:

	protected:
		GLuint m_IBO;
		unsigned int m_IndexNum;
		unsigned int m_IndexSize;
		friend class GlesDevice;
	};




}
#endif