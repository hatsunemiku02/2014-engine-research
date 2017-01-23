#include "ScriptSys.h"
#include "GpuProgram.h"
#include "Shader.h"
#include "GlesDevice.h"
#include "VertexBufferObj.h"
#include "IndexBufferObj.h"
#include "Texture.h"
#include "ResMgr.h"
#include "ImageRes.h"
#include "Sound.h"
#include "SoundSystem.h"
#include <jni.h>
#include <android/log.h>
float afVertives[] = 
{
	-1.0f,-0.6f,0.8f,1.0f,0.0f,0.0f,
	1.0f,-0.6f,0.8f,1.0f,1.0f,0.0f,
	1.0f,0.6f,0.8f,1.0f,1.0f,1.0f,
	-1.0f,0.6f,0.8f,1.0f,0.0f,1.0f,
};

unsigned short indexs[] =
{
	0,1,2,0,2,3
};

unsigned char pixels[4 * 3] =
{
	255, 0, 0, // Red
	0, 255, 0, // Green
	0, 0, 255, // Blue
	255, 255, 0 // Yellow
};


const char* vs = "\
					attribute highp vec4 myVertex;\
					attribute vec2 a_texCoord;\
					varying vec2 v_texCoord;\
					void main(void)\
					{\
					gl_Position = myVertex;\
				    v_texCoord = a_texCoord;\
					}";
	
const char* ps = "\
				 uniform sampler2D s_texture;\
				 varying mediump vec2 v_texCoord;\
				 void main(void)\
				 {\
				 lowp vec4 color = texture2D(s_texture, v_texCoord);\
				 mediump float r = color.r; \
				 color.r = color.b;\
				 color.b = r;\
				 gl_FragColor = color;\
				 }";

using namespace GraphicCore;
using namespace SoundSys;
VertexBufferObj* vbo = 0 ;
IndexBufferObj* ibo = 0;
GpuProgram* p = 0;
int init()
{


	SoundSystem::GetInstance().InitSoundSystem();
	Sound* psound = SoundSystem::GetInstance().CreateSound("sdcard/Media/s.mp3");
	psound->Play();
// 	Script::ScriptSys::Instance().Setup();
// 	Script::ScriptSys::Instance().OnLoad();
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","IN INIT!");

	GlesDevice::GetInstance().SetPixelUnpackAlignment(1);
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","set pixel pack!");
	
	std::map<int,VertexLayout::Ele> layout;
	VertexLayout::Ele eleVtx(0,4,sizeof(float),0);
	VertexLayout::Ele eleUV(1,2,sizeof(float),4*sizeof(float));
	layout.insert(std::make_pair(0,eleVtx));
	layout.insert(std::make_pair(1,eleUV));
	VertexLayout VerLayout;
	VerLayout.BuildLayout(layout);
	vbo = VertexBufferObj::CreateVertexBuffer(afVertives,24,sizeof(float),VerLayout);
	ibo = IndexBufferObj::CreateIndexBuffer(indexs,6,sizeof(unsigned short));
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER INIT ibo and vbo!");
	Shader vshader;
	vshader.CreateShader(Shader::VERTEX,vs);
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER INIT vs");
	Shader fshader;
	fshader.CreateShader(Shader::FRAGMENT,ps);
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER INIT ps");
	p = GpuProgram::CreateGpuPragram(vshader,fshader);
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER INIT Shader!");

	int height = 0;
	int width = 0;
	PixelFormat format = PF_NONE;
	int mipmaps = 0;
	int size = 0;
	void* buffer = NULL;
	Resource::ImageRes* pTex = Resource::ResMgr::GetInstance().GetRes<Resource::ImageRes>("sdcard/Media/TTB.png");

	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER INIT pic!");
	p->SetUniformValue("s_texture",pTex->GetTexture());
	__android_log_print(ANDROID_LOG_INFO,"CATFISH","AFTER set pic value!");
	return 0;
}
int ww,hh;
int run()
{
		GlesDevice::GetInstance().Clean();
		GlesDevice::GetInstance().SetCurrentVBO(vbo);
		GlesDevice::GetInstance().SetCurrentIBO(ibo);
		GlesDevice::GetInstance().SetCurrentGPG(p);
		GlesDevice::GetInstance().Draw(DM_TRIANGLE_LIST,0,-1);

return 0;

}
void RenderFrame()
{
	run();
}

void CleanUp()
{
		
}


extern "C" {

	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeConfig(JNIEnv*  env, jobject thiz, jstring gamedir, jstring scenename);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeStorage(JNIEnv*  env, jobject thiz, jint type, jstring pakagename, jstring apklocation);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeSetAndroidNaviveValues(JNIEnv*  env, jobject thiz, jstring uuid);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h,jfloat dpiw,jfloat dpih);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeRender(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnPause(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnResume(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnStop(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesBegin(JNIEnv * env, jobject obj, jint pIDs, jfloat pXs, jfloat pYs);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesMove(JNIEnv * env, jobject obj, jintArray pIDs, jfloatArray pXs, jfloatArray pYs);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesEnd(JNIEnv * env, jobject obj, jint pIDs, jfloat pXs, jfloat pYs);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesCancel(JNIEnv * env, jobject obj, jintArray pIDs, jfloatArray pXs, jfloatArray pYs);
	JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeKeyDown(JNIEnv * env, jobject obj, jint pKeyCode);
};	

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeConfig(JNIEnv*  env, jobject thiz, jstring gamedir, jstring scenename)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeStorage(JNIEnv*  env, jobject thiz, jint type, jstring pakagename , jstring apklocation)
{

}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeSetAndroidNaviveValues( JNIEnv* env,jobject thiz, jstring uuid )
{

}
JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv* env, jobject thiz, jint w, jint h, jfloat dpiw,jfloat dpih)
{
	ww = w;
	hh = h;
	init();
}
JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeRender(JNIEnv * env, jobject obj)
{
	RenderFrame();
}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesBegin(JNIEnv * env, jobject obj, jint pIDs, jfloat pXs, jfloat pYs)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesMove(JNIEnv * pEnv, jobject obj, jintArray pIDs, jfloatArray pXs, jfloatArray pYs)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesEnd(JNIEnv * env, jobject obj, jint pIDs, jfloat pXs, jfloat pYs)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeTouchesCancel(JNIEnv * env, jobject obj, jintArray pIDs, jfloatArray pXs, jfloatArray pYs)
{
	
}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnPause(JNIEnv * env, jobject obj)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnResume(JNIEnv * env, jobject obj)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeKeyDown(JNIEnv * env, jobject obj, jint pKeyCode)
{

}

JNIEXPORT void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeOnStop(JNIEnv * env, jobject obj)
{

}