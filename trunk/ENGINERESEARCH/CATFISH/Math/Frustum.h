#pragma once
#include "CommonMath.h"
#include "ClipStatus.h"
#include "MathDllCommon.h"
namespace Math
{
	class BoxAABB;
}

namespace Math
{
	/*

	Left= (v0 + v3).
	Right =(v3 - v0)
	Bottom =(v3 + v1)
	Top = (v3 - v1 )
	Near = (v2)
	Far = (v3 - v2)


	*/
	

	class MATH_API Frustum
	{
	public:
		enum FRUSTUMPLANE
		{
			NEAR,
			FAR,
			TOP,
			BOTTOM,
			LEFT,
			RIGHT,
			COUNT,
		};
	public:
		Frustum();
		~Frustum();


		void InitFrustum(const matrix44f& aoViewMatrix,const matrix44f& aoProjMatrix);

		ClipStatus InterSectAABB(const BoxAABB& bbox);
	protected:
		vector4f m_Planes[COUNT];

	};
}