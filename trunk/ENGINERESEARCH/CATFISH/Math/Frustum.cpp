#include "Frustum.h"
#include "BoxAABB.h"
namespace Math
{

	Frustum::Frustum()
	{

	}


	Frustum::~Frustum()
	{

	}

	void Frustum::InitFrustum( const matrix44f& aoViewMatrix,const matrix44f& aoProjMatrix )
	{
		matrix44f loComboMatrix;

		loComboMatrix =  aoProjMatrix*aoViewMatrix;
		//D3DXMatrixMultiply(&loComboMatrix,&aoViewMatrix,&aoProjMatrix);
		// calculate the planes
		// Near
		vector4f* lpPlane = &m_Planes[NEAR];
		lpPlane->operator[](0) = loComboMatrix.data()[3]+ loComboMatrix.data()[2];
		lpPlane->operator[](1) = loComboMatrix.data()[7] + loComboMatrix.data()[6];
		lpPlane->operator[](2) = loComboMatrix.data()[11] + loComboMatrix.data()[10];
		lpPlane->operator[](3) = loComboMatrix.data()[15] + loComboMatrix.data()[14];
		//normalise_plane(lpPlane);

		// Far
		lpPlane = &m_Planes[FAR];
		lpPlane->operator[](0) = loComboMatrix.data()[3] - loComboMatrix.data()[2];
		lpPlane->operator[](1) = loComboMatrix.data()[7] - loComboMatrix.data()[6];
		lpPlane->operator[](2) = loComboMatrix.data()[11] - loComboMatrix.data()[10];
		lpPlane->operator[](3) = loComboMatrix.data()[15] - loComboMatrix.data()[14];
		//normalise_plane(lpPlane);
		//Left
		lpPlane = &m_Planes[LEFT];
		lpPlane->operator[](0) = loComboMatrix.data()[3] + loComboMatrix.data()[0];
		lpPlane->operator[](1) = loComboMatrix.data()[7] + loComboMatrix.data()[4];
		lpPlane->operator[](2) = loComboMatrix.data()[11] + loComboMatrix.data()[8];
		lpPlane->operator[](3) = loComboMatrix.data()[15] + loComboMatrix.data()[12];
		//normalise_plane(lpPlane);
		// Right
		lpPlane = &m_Planes[RIGHT];
		lpPlane->operator[](0) = loComboMatrix.data()[3] - loComboMatrix.data()[0];
		lpPlane->operator[](1) = loComboMatrix.data()[7] - loComboMatrix.data()[4];
		lpPlane->operator[](2) = loComboMatrix.data()[11] - loComboMatrix.data()[8];
		lpPlane->operator[](3) = loComboMatrix.data()[15] - loComboMatrix.data()[12];
		//normalise_plane(lpPlane);
		// Top
		lpPlane = &m_Planes[TOP];
		lpPlane->operator[](0) = loComboMatrix.data()[3] - loComboMatrix.data()[1];
		lpPlane->operator[](1) = loComboMatrix.data()[7] - loComboMatrix.data()[5];
		lpPlane->operator[](2) = loComboMatrix.data()[11] - loComboMatrix.data()[9];
		lpPlane->operator[](3) = loComboMatrix.data()[15] - loComboMatrix.data()[13];
		//normalise_plane(lpPlane);
		// Bottom
		lpPlane = &m_Planes[BOTTOM];
		lpPlane->operator[](0) = loComboMatrix.data()[3] + loComboMatrix.data()[1];
		lpPlane->operator[](1) = loComboMatrix.data()[7] + loComboMatrix.data()[5];
		lpPlane->operator[](2) = loComboMatrix.data()[11] + loComboMatrix.data()[9];
		lpPlane->operator[](3) = loComboMatrix.data()[15] + loComboMatrix.data()[13];
		//normalise_plane(lpPlane);
	}

	ClipStatus Frustum::InterSectAABB( const BoxAABB& bbox )
	{
		int allin = 0;
		for(int i=0;i<Frustum::COUNT;i++)
		{
			int incount = 0;
			for(int j = 0; j < 8; j++)
			{
				vector4f point = bbox.cornerPoint(j);
				if(point[0]*m_Planes[i][0]+point[1]*m_Planes[i][1]+point[2]*m_Planes[i][2]+m_Planes[i][3]>=0)
				{
					incount++;
				}
			}
			if(incount==0)
			{
				return OUT;
			}
			else if(incount==8)
			{
				allin++;
			}
		}
		if(allin==6)
		{
			return CONTAIN;
		}
		return CLIP;
	}

}