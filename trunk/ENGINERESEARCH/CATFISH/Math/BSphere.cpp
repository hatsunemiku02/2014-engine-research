#include "BSphere.h"
namespace Math
{


	ClipStatus BSphere::InterSect( const BSphere& sphere )
	{
		return OUT;
	}

	ClipStatus BSphere::InterSect( const BoxAABB& box )
	{
		return OUT;
	}

}