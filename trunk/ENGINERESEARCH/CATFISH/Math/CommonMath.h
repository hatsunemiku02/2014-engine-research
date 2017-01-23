#pragma once
#include "cmlmath.h"
#include <math.h>

namespace Math
{
	inline bool isEqual(float x,float y)
	{
		return x==y;
	}

	inline float Sqrt(float x)
	{
		return sqrt(x);
	}
    
    inline bool IsPowerOfTwo(int size)
    {
        return (size & (size -1)) == 0;
    }

	inline int PointCompare(const cml::vector3f& left,const cml::vector3f& right)
	{
		if(left[0]>right[0]&&left[1]>right[1]&&left[2]>right[2])
		{
			return 1;
		}
		else if(left[0]<right[0]&&left[1]<right[1]&&left[2]<right[2])
		{

		}
	
		return 0;
		
	}
	
    inline bool IsInRect(const vector2i& pos , int size, const vector2i& center )
    {
        if( pos[0]+size>center[0]&&pos[1]+size>center[1])
        {
            if( pos[0]-size<center[0]&&pos[1]-size<center[1])
            {
                
                return true;
            }
        }
        return false;
    }
    
	inline void normalise_plane( vector4f* in)
	{
		
		
	}
}