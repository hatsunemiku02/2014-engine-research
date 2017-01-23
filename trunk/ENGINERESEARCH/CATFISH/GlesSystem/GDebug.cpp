#include "GDebug.h"
#include <stdlib.h>
#if __IOS__
#include "Catfish-Prefix.pch"
#endif
#include "OpenglHeader.h"
static int err;
void CheckError()
{
// #if __GL__
// #else
	err = glGetError();
	if(err!=GL_NO_ERROR)
	{
		abort();
	}
//#endif
	
}
