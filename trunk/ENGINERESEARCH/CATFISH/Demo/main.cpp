

#include "GpuProgram.h"
#include "Shader.h"
#include "VertexBufferObj.h"
#include "IndexBufferObj.h"
#include "Texture.h"
#include "ResMgr.h"
#include "ImageRes.h"
#include "QuatTree.h"
#include "MeshRes.h"
#include "ShaderRes.h"
#include "PrimitiveGroup.h"
#include "ForwardRenderPipeline.h"
#include "BoxAABB.h"
#include "GlesDevice.h"
#include "Camera.h"
#include "RenderUnit.h"
#include "PlatformDiff.h"
#include "Material.h"

#include <Windows.h>
LRESULT CALLBACK  WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HWND parentWND = GetParent(hwnd);
	switch (message)
	{

	case WM_PAINT:
		hdc = BeginPaint (hwnd, &ps);

		EndPaint (hwnd, &ps);
		return (0);
		break;

	case WM_DESTROY:
		PostQuitMessage (0); 
		return (0);

	
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}
HWND CreateLoaderWindow( unsigned int nWidth,unsigned int nHeight )
{
	extern LRESULT CALLBACK  WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	LPCSTR wndClassName = "GameWindow";
	LPCSTR wndTitle = "MyDemo";

	HINSTANCE hInst = ::GetModuleHandle(0);
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra	= 0;
	wcex.cbWndExtra	= 0;
	wcex.hInstance		= hInst;
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= wndClassName;
	wcex.hIconSm		= NULL;

	RegisterClassEx(&wcex);

	HWND hWnd;
	DWORD dwStyle = 0;

	dwStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_VISIBLE;

	RECT bounds;
	bounds.left = 0;
	bounds.top = 0;
	bounds.right = nWidth;
	bounds.bottom = nHeight;
	AdjustWindowRectEx(&bounds, dwStyle, FALSE, 0);//GetWindowLong(m_Window, GWL_STYLE)

	int windowWidth = bounds.right - bounds.left;
	int windowHeight = bounds.bottom - bounds.top;
	hWnd = CreateWindow(wndClassName, 
		wndTitle,
		dwStyle,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		windowWidth,
		windowHeight,
		NULL, 
		NULL, 
		hInst, 
		NULL);

	ShowWindow(hWnd,SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	return hWnd;
}
using namespace GraphicCore;
int main()
{


	HWND window = CreateLoaderWindow(400,400);

	PlatformDiff::GetInstance().Init(window);

	int height = 0;
	int width = 0;
	PixelFormat format = PF_NONE;
	int mipmaps = 0;
	int size = 0;
	void* buffer = NULL;

	Resource::ResMgr::GetInstance().InitDefaultResource();

	Resource::MeshRes* pMesh =	Resource::ResMgr::GetInstance().GetRes<Resource::MeshRes>("..\\Media\\knight1v_body.mesh");
	GpuProgram* p = Resource::ResMgr::GetInstance().GetRes<Resource::GpuProgramRes>("Default3DShader")->GetGpuProgram();
	Resource::ImageRes* pTex = Resource::ResMgr::GetInstance().GetRes<Resource::ImageRes>("..\\Media\\TTB.png");

	GraphicSys::RenderUnit* pRender = new GraphicSys::RenderUnit();
	pRender->SetVBO(pMesh->GetPrimitiveGroup()->GetVBO(0));
	pRender->SetIBO(pMesh->GetPrimitiveGroup()->GetIBO(0));


	GraphicSys::Material* pMat = new GraphicSys::Material();
	pMat->SetGPUPro(p);
	pRender->SetMaterial(pMat);

	matrix44f view;

	view =(GraphicSys::ForwardRenderPipeline::GetInstance().GetCamera()->GetProj())* (GraphicSys::ForwardRenderPipeline::GetInstance().GetCamera()->GetView());

	pMat->SetParam("g_mvp",view);
	pMat->SetParam("s_texture",pTex->GetTexture());
	Math::BoxAABB b;
	b.Set(vector3f(1,1,1),vector3f(2,2,-2));
	pRender->SetCullParam(0,b);
	GraphicSys::ForwardRenderPipeline::GetInstance().AddRenderUnit(pRender);

	MSG msg;
	while(GetMessage(&msg,0,0,0))
	{
		GlesDevice::GetInstance().Clean();

		GraphicSys::ForwardRenderPipeline::GetInstance().RenderAll();

		PlatformDiff::GetInstance().SwapToScreen();

		PeekMessage(&msg,window,0,0,PM_REMOVE);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}