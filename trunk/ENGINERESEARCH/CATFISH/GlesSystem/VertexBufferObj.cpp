


#include "OpenglHeader.h"
#include "VertexBufferObj.h"
#include "GlesDevice.h"
#include "GDebug.h"

namespace GraphicCore
{


	GLVertexBufferObj::GLVertexBufferObj()
	{

	}

	GLVertexBufferObj::~GLVertexBufferObj()
	{

	}

	GLVertexBufferObj* GLVertexBufferObj::CreateVertexBuffer( void* vertexBuffer,int numb, int sizz,const VertexLayout& layout,StroageMode mode/*=SM_STATIC*/ )
	{
		GLVertexBufferObj* pOut = new GLVertexBufferObj();
		pOut->m_VertexLayout = layout;
		pOut->m_VertexNum = numb;
		pOut->m_VertexSize = sizz;
		glGenBuffers(1, &(pOut->m_VBO));
		CHECKGLERROR;
		GlesDevice::GetInstance().SetCurrentVBO(pOut);
		CHECKGLERROR;
		glBufferData(GL_ARRAY_BUFFER, pOut->m_VertexNum*pOut->m_VertexSize,vertexBuffer, ToGLESStorageMode(mode));
		CHECKGLERROR;
		return pOut;
	}

	void GLVertexBufferObj::DestoryVertexBuffer( GLVertexBufferObj* pVbo )
	{
		pVbo->m_VertexSize = 0;
		pVbo->m_VertexNum = 0;
		pVbo->m_VertexLayout.m_Layout.clear();
        GlesDevice::GetInstance().SetCurrentVBO(NULL);
		glDeleteBuffers(1,&pVbo->m_VBO);
	}



}