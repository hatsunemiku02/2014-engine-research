#include "BoxAABB.h"
#include "CommonMath.h"
#include <assert.h>

namespace Math
{


	ClipStatus BoxAABB::InterSect( const BoxAABB& box )
	{
		if((PointCompare(GetMax(),box.GetMax())>0)&&(PointCompare(GetMin(),box.GetMin())<0))
		{
			return CONTAIN;
		}
		else if ((PointCompare(GetMax(),box.GetMax())<0)&&(PointCompare(GetMin(),box.GetMin())>0))
		{
			return IN;
		}
		float la=m_center[0]-m_size[0], lb=box.m_center[0]-box.m_size[0];
		float ra=m_center[0]+m_size[0], rb=box.m_center[0]+box.m_size[0];
		float fa=m_center[2]+m_size[2], fb=box.m_center[2]+box.m_size[2];
		float ba=m_center[2]-m_size[2], bb=box.m_center[2]-box.m_size[2];
		float ua=m_center[1]+m_size[1], ub=box.m_center[1]+box.m_size[1];
		float da=m_center[1]-m_size[1], db=box.m_center[1]-box.m_size[1];
		if(la>rb || ra<lb || fa<bb || ba>fb || ua<db || da>ub)
		{
			return CLIP;
		}

		return OUT;
	}

	vector4f BoxAABB::cornerPoint( int index ) const
	{
		assert((index >= 0) && (index < 8));
		switch (index)
		{
		case 0:     return vector4f(this->GetMin()[0], this->GetMin()[1], this->GetMin()[2],1);
		case 1:     return vector4f(this->GetMin()[0], this->GetMax()[1], this->GetMin()[2],1);
		case 2:     return vector4f(this->GetMax()[0], this->GetMax()[1], this->GetMin()[2],1);
		case 3:     return vector4f(this->GetMax()[0], this->GetMin()[1], this->GetMin()[2],1);
		case 4:     return vector4f(this->GetMax()[0], this->GetMax()[1], this->GetMax()[2],1);
		case 5:     return vector4f(this->GetMin()[0], this->GetMax()[1], this->GetMax()[2],1);
		case 6:     return vector4f(this->GetMin()[0], this->GetMin()[1], this->GetMax()[2],1);
		default:    return vector4f(this->GetMax()[0], this->GetMin()[1], this->GetMax()[2],1);
		} 
	}

	void BoxAABB::transform( const matrix44f& m )
	{
		vector4f temp;
		vector3f minP(1000000, 1000000,1000000);
		vector3f maxP(-1000000, -1000000, -1000000);        
		int i; 

		for(i = 0; i < 8; ++i)
		{
			// Transform and check extents
			temp =  m * this->cornerPoint(i);
			if (temp[0] > maxP[0])   maxP[0] = temp[0];
			if (temp[1] > maxP[1])   maxP[1] = temp[1];
			if (temp[2] > maxP[2])   maxP[2] = temp[2];
			if (temp[0] < minP[0])   minP[0] = temp[0];
			if (temp[1] < minP[1])   minP[1] = temp[1];
			if (temp[2] < minP[1])   minP[2] = temp[2];
		}    

		this->m_center = (minP+maxP)/2;
		this->m_size = maxP-m_center;
	}

}