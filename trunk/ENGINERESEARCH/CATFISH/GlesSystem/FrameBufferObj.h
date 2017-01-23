#ifndef FRAMEBUFFEROBJ_H_
#define FRAMEBUFFEROBJ_H_


#include "GDllCommon.h"
#include "DrawEnums.h"

typedef unsigned int GLuint;

namespace GraphicCore
{
	class GlesDevice;
	class RENDERER_API FrameBufferObj
	{
	public:
		FrameBufferObj();
		~FrameBufferObj();

		static FrameBufferObj* CreateFBO(PixelFormat pf,int width,int height,bool depth,bool stencil);
		static void DestoryFBO(FrameBufferObj* pFbo);
	protected:

		friend class GlesDevice;

		bool m_HaveDepth;
		bool m_UseDepthTex;
		int m_Width;
		int m_Height;
		PixelFormat m_PixelFormal;

		GLuint m_FrameBuf;
		GLuint m_FrameTexAttached;
		GLuint m_FrameDepthTexAttached;
		GLuint m_FrameDepthRBAttached;
		GLuint m_FrameStencilAttached;
	};
}
#endif