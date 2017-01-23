#include "GDllCommon.h"
namespace GraphicCore
{

	typedef void *EGLConfig;
	typedef void *EGLContext;
	typedef void *EGLDisplay;
	typedef void *EGLSurface;
	typedef void *EGLClientBuffer;



	class RENDERER_API PlatformDiff
	{
	public:
		static PlatformDiff& GetInstance()
		{
			static PlatformDiff instance;
			return instance;
		}
		~PlatformDiff();


		bool Init(void* pWindow);

		void SwapToScreen();
	protected:
		PlatformDiff();


		void* m_pWindowHandle;

		EGLDisplay m_Display;
		EGLConfig m_Config;
		EGLContext m_Context;
		EGLSurface m_Surface;
		void* m_NativeWindow;
	};

}