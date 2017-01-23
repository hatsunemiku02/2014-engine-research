#include "Camera.h"
namespace GraphicSys
{


	Camera::Camera()
	{
		matrix_look_at_RH(m_View,vector3f(0,0,6),vector3f(0,0,0),vector3f(0,1,0));
	
		matrix_perspective_xfov_RH(m_Proj,1.5f,1.0f,1.f,1000.f,cml::z_clip_zero);
	}

	Camera::~Camera()
	{

	}

}