#include "FrameBufferObj.h"
#include "GDebug.h"
#include "GlesDevice.h"
#include "OpenglHeader.h"
namespace GraphicCore
{
	FrameBufferObj::FrameBufferObj()
		:m_HaveDepth(false)
		,m_UseDepthTex(false)
		,m_Width(0)
		,m_Height(0)
		,m_FrameBuf(0)
		,m_FrameTexAttached(0)
		,m_FrameDepthTexAttached(0)
		,m_FrameDepthRBAttached(0)
		,m_FrameStencilAttached(0)
	{

	}

	FrameBufferObj::~FrameBufferObj()
	{

	}

	FrameBufferObj* FrameBufferObj::CreateFBO( PixelFormat pf,int width,int height,bool depth,bool stencil )
	{
		FrameBufferObj* ret = new FrameBufferObj();
		ret->m_Width = width;
		ret->m_Height = height;
		ret->m_PixelFormal = pf;
		glGenFramebuffers(1, &ret->m_FrameBuf);
		CHECKGLERROR;
		GlesDevice::GetInstance().BindFrameBuffer(ret);
		glGenTextures(1, &ret->m_FrameTexAttached);
		CHECKGLERROR;
		glTexImage2D(GL_TEXTURE_2D, 0, ToGLESPixelFormat(ret->m_PixelFormal), ret->m_Width, ret->m_Height, 0, ToGLESPixelType(ret->m_PixelFormal), GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ret->m_FrameTexAttached, NULL);


		if (ret->m_UseDepthTex)
		{
			glGenTextures(1, &ret->m_FrameDepthTexAttached);
			CHECKGLERROR;

			glBindTexture(GL_TEXTURE_2D, ret->m_FrameDepthTexAttached);
			CHECKGLERROR;

			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, ret->m_Width, ret->m_Height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, ret->m_FrameDepthTexAttached, NULL);

			CHECKGLERROR;
		}
		else
		{
			glGenRenderbuffers(1, &ret->m_FrameDepthRBAttached);
			CHECKGLERROR;

			glBindRenderbuffer(GL_RENDERBUFFER, ret->m_FrameDepthRBAttached);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, ret->m_Width, ret->m_Height);

			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, ret->m_FrameDepthRBAttached);
			CHECKGLERROR;

			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
#if 0 //|| __OSX__
	//´´½¨Ä£°åRender buffer
	
		glGenRenderbuffers(1, &ret->m_FrameStencilAttached);
		CHECKGLERROR;

		glBindRenderbuffer(GL_RENDERBUFFER,ret->m_FrameStencilAttached);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, ret->m_Width, ret->m_Height);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, ret->m_FrameStencilAttached);
		CHECKGLERROR;

		glBindRenderbuffer(GL_RENDERBUFFER, 0);

#endif


#if __OSX__
	GlesDevice::GetInstance().BindFrameBuffer(1);
#else
	GlesDevice::GetInstance().BindFrameBuffer(NULL);
#endif

	GlesDevice::GetInstance().BindTexture(TT_TEXTURE2D,NULL);
	return ret;
	}

	void FrameBufferObj::DestoryFBO( FrameBufferObj* pFbo )
	{
		if (pFbo->m_FrameBuf > 0)
		{
			glDeleteFramebuffers(1, &pFbo->m_FrameBuf);
			pFbo->m_FrameBuf = 0;
		}

		if (pFbo->m_FrameTexAttached > 0)
		{
			glDeleteTextures(1, &pFbo->m_FrameTexAttached);
			pFbo->m_FrameTexAttached = 0;
		}

		if (pFbo->m_FrameDepthTexAttached > 0)
		{
			glDeleteTextures(1, &pFbo->m_FrameDepthTexAttached);
			pFbo->m_FrameDepthTexAttached = 0;
		}

		if (pFbo->m_FrameDepthRBAttached > 0)
		{
			glDeleteRenderbuffers(1, &pFbo->m_FrameDepthRBAttached);
			pFbo->m_FrameDepthRBAttached = 0;
		}

		if (pFbo->m_FrameStencilAttached > 0)
		{
			glDeleteRenderbuffers(1, &pFbo->m_FrameStencilAttached);
			pFbo->m_FrameStencilAttached = 0;
		}

#ifdef __OSX__
		GlesDevice::GetInstance().BindFrameBuffer(1);
#else
		GlesDevice::GetInstance().BindFrameBuffer(0);
#endif
		GlesDevice::GetInstance().BindTexture(TT_TEXTURE2D,NULL);
	}

}