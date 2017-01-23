#ifndef GLESDEVICE_H_
#define GLESDEVICE_H_
#include "GDllCommon.h"

#include <string>
#include <vector>
#include "GDebug.h"
#include "DrawEnums.h"
#include "cmlmath.h"




//typedef NativeWindowType;
//typedef void *EGLNativeWindowType;


typedef int  GLint;

namespace GraphicCore
{
	class GpuProgram;
	class GLVertexBufferObj;
	class GLIndexBufferObj;
	class GLTexture;
	class FrameBufferObj;

	class RENDERER_API GlesDevice
	{
	public:
		static GlesDevice& GetInstance()
		{
			static GlesDevice instance;
			return instance;
		}
		~GlesDevice();

		int GetMaxVertexAtt();

		int GetMaxTextureUnit();
		
		void GetExtentions();

		void SetPixelUnpackAlignment(int align);   

		bool ActiveTextureUnit(TextureUnit unit);

		void BindTexture(TextureType type,GLTexture* tex);

		void BindFrameBuffer(FrameBufferObj* pFbo);
	
		void SetCurrentVBO( GLVertexBufferObj* vbo);

		void SetCurrentIBO( GLIndexBufferObj* ibo);

		void SetCurrentGPG( GpuProgram* gpg);

		void Clean();

		void SetViewPort(int left,int top,int width,int height );

		void Draw(DrawMode mode ,int start,int num);
        
        void EnableState(CTRenderState rs);
        
        void DisableState(CTRenderState rs);
        
        void SetBlendFun(CTBlendFun bf);
        
        void SetBlendState(CTBlendStateSrc bss,CTBlendStateDst bsd);
        
        void SetScreenSize(const cml::vector2i& size)
        {
            m_ScreenSize = size;
        }
        const cml::vector2i& GetScreenSize() const
        {
            return m_ScreenSize;
        }
        
		std::string GetDeviceName();

	protected:
		void BeforeDraw();
		void DrawCurrent(DrawMode mode ,int start,int num);
		void AfterDraw();

		void BindCurrentAttLayout();
		void UnBindCurrentAttLayout();
		void DrawIndexed(DrawMode mode ,int start,int num);
		void DrawUnindexed(DrawMode mode ,int start,int num);
	protected:

		GLint m_MaxVertexAttribs; 
		GLint m_MaxTextureUnits; 

		std::vector<std::string> m_ExtensionArr;

		GLTexture* m_pBindedTexture[8];
		TextureUnit m_ActivedTexUnit;

		GLVertexBufferObj* m_pCurrentVBO;
		GLIndexBufferObj* m_pCurrentIBO;
		GpuProgram* m_pCurrentGPG;
        FrameBufferObj* m_pFrameBufferObj;

        CTBlendFun m_BlendFoo;
        CTBlendStateSrc m_SrcBlendState;
        CTBlendStateDst m_DstBlendState;
        cml::vector2i m_ScreenSize;
	private:
		GlesDevice();
	};
}
#endif