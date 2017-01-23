#if __IOS__
#include <Opengles/ES2/gl.h>
#elif __GL__ 
#include <windows.h>   
#include <GLEW/glew.h>
#include <GLEW/wglew.h>
#else
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#endif
