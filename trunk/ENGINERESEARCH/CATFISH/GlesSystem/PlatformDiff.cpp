#include "PlatformDiff.h"
#include "OpenglHeader.h"
#include "GDebug.h"
namespace GraphicCore
{

#if __IOS__
#elif __GL__
	static const PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),        // Size of this structure
		1,                                    // Version of this structure
		PFD_DRAW_TO_WINDOW |                  // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |                  // Support OpenGL calls in window
		PFD_DOUBLEBUFFER ,                     // Double buffered mode
		PFD_TYPE_RGBA,                        // RGBA Color mode
		24,                                   // Want 24bit color
		0,0,0,0,0,0,                          // Not used to select mode
		0,0,                                  // Not used to select mode
		0,0,0,0,0,                            // Not used to select mode
		32,                                   // Size of depth buffer
		0,                                    // Not used to select mode
		0,                                    // Not used to select mode
		PFD_MAIN_PLANE,                       // Draw in main plane
		0,                                    // Not used to select mode
		0,0,0 };                              // Not used to select mode
#else
	const EGLint pi32ConfigAttribs[] =
	{
		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
		//EGL_BUFFER_SIZE, 32,
		EGL_RED_SIZE, 4,
		EGL_GREEN_SIZE, 4,
		EGL_BLUE_SIZE, 4,
		EGL_ALPHA_SIZE, 4,
		EGL_DEPTH_SIZE, 16,
		EGL_STENCIL_SIZE, 8,
		//EGL_SAMPLE_BUFFERS, 0,
		EGL_NONE
	};
#endif


	PlatformDiff::PlatformDiff()
		:m_pWindowHandle(0)
		,m_Display(0)
		,m_Config(0)
		,m_Context(0)
		,m_Surface(0)
		,m_NativeWindow(0)
	{

	}

	PlatformDiff::~PlatformDiff()
	{

	}

	bool PlatformDiff::Init(void* pWindow)
	{
#if __ANDROID__||__IOS__
#elif __GL__


		m_pWindowHandle = pWindow;
		m_NativeWindow = (void*)GetDC((HWND)m_pWindowHandle);
		int nPixelFormat;

		// Choose a pixel format that best matches that described in pfd
		nPixelFormat = ChoosePixelFormat((HDC)m_NativeWindow, &pfd);
		// Set the pixel format for the device context
		SetPixelFormat((HDC)m_NativeWindow, nPixelFormat, &pfd);

		HGLRC contex = wglCreateContext((HDC)m_NativeWindow);
		wglMakeCurrent((HDC)m_NativeWindow,contex);
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
			char* perror =	(char*)glewGetErrorString(err);
			MERROR;
		}

		if (!GLEW_VERSION_2_0)
		{
			MERROR;
		}
#else
		m_pWindowHandle = pWindow;
		m_NativeWindow = (EGLNativeWindowType)m_pWindowHandle;
		EGLNativeDisplayType hDC = GetDC((EGLNativeWindowType)m_pWindowHandle);
		m_Display = eglGetDisplay(hDC);

		if(m_Display == EGL_NO_DISPLAY)
		{
			m_Display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
		}

		EGLint majorver,minver;
		if(!eglInitialize(m_Display,&majorver,&minver))
		{
			MERROR
			return false;
		}
		eglBindAPI(EGL_OPENGL_ES_API);

		//CHECKGLERROR;
		int iConfigs;
		if(!eglChooseConfig(m_Display,pi32ConfigAttribs,&m_Config,1,&iConfigs)||(iConfigs!=1))
		{
			MERROR
			return false;
		}

		m_Surface = eglCreateWindowSurface(m_Display,m_Config,(EGLNativeWindowType)m_NativeWindow,NULL);
		//CHECKGLERROR;

		EGLint ai32ContextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION,2,EGL_NONE};
		m_Context = eglCreateContext(m_Display,m_Config,NULL,ai32ContextAttribs);
		//CHECKGLERROR;

		eglMakeCurrent(m_Display,m_Surface,m_Surface,m_Context);
		//CHECKGLERROR;
#endif
		return true;
	}
	void PlatformDiff::SwapToScreen()
	{
#if __IOS__||__ANDOIRD__
		
#elif __GL__
		SwapBuffers((HDC)m_NativeWindow);
#else
		eglSwapBuffers(m_Display,m_Surface);
		CHECKGLERROR;
#endif
	}
}