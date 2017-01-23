#include "IndexBufferObj.h"
#include "GlesDevice.h"
#include "GDebug.h"
#include "OpenglHeader.h"

namespace GraphicCore
{
	GLIndexBufferObj::GLIndexBufferObj()
	{

	}

	GLIndexBufferObj::~GLIndexBufferObj()
	{

	}

	GLIndexBufferObj* GLIndexBufferObj::CreateIndexBuffer( void* indexBuffer,int numb,int sizz,StroageMode mode/*=SM_STATIC*/ )
	{
		GLIndexBufferObj* pOut = new GLIndexBufferObj();
		pOut->m_IndexNum = numb;
		pOut->m_IndexSize = sizz;
		glGenBuffers(1, &(pOut->m_IBO));
		CHECKGLERROR;
		GlesDevice::GetInstance().SetCurrentIBO(pOut);
		CHECKGLERROR;
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pOut->m_IndexNum*pOut->m_IndexSize,indexBuffer, ToGLESStorageMode(mode));
		CHECKGLERROR;
		return pOut;
	}

	void GLIndexBufferObj::DestoryIndexBuffer( GLIndexBufferObj* pIbo )
	{
		pIbo->m_IndexNum = 0;
		pIbo->m_IndexSize = 0;
        GlesDevice::GetInstance().SetCurrentIBO(NULL);
		glDeleteBuffers(1,&pIbo->m_IBO);
	}

}