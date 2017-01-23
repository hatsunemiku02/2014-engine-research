#include "DrawEnums.h"
#include "GDebug.h"
#include "OpenglHeader.h"
namespace GraphicCore
{
	int ToGLESDrawMode( DrawMode mode )
	{
		return mode+GL_POINTS;
	}

	int ToGLESStorageMode( StroageMode mode )
	{
		switch (mode)
		{
		case SM_STREAM:
			return GL_STREAM_DRAW;
		case SM_STATIC:
			return GL_STATIC_DRAW;
		case SM_DYNAMIC:
			return GL_DYNAMIC_DRAW;
		}
		return mode;
	}

	int ToGLESAddressMode(AddressMode mode)
	{
		IFERROR(mode==AM_BORDER);
		switch (mode)
		{
		case AM_WRAP:
			return GL_REPEAT;
		case AM_CLAMP:
			return GL_CLAMP_TO_EDGE;
		case AM_PINGPANG:
			return GL_MIRRORED_REPEAT;
		}
		return mode;
	}

	int ToGLESTextureType( TextureType type )
	{
		switch(type)
		{
		case TT_TEXTURE2D:
			return GL_TEXTURE_2D;
		}
		return 0;
	}

	int ToGLESPixelFormat( PixelFormat format )
	{
		switch (format)
		{
		case PF_R8G8B8:
		case PF_R5G6B5:
			return GL_RGB;
		case PF_R8G8B8A8:
		case PF_R5G5B5A1:
			return GL_RGBA;
		case PF_L:
			return GL_LUMINANCE;
		case PF_A:
			return GL_ALPHA;
		case PF_LA:
			return GL_LUMINANCE_ALPHA;
		case PF_NONE:
			return 0;
		}
	}

	int ToGLESPixelType( PixelFormat format )
	{
		switch (format)
		{
		case PF_R5G6B5:
			return GL_UNSIGNED_SHORT_5_6_5;
		case PF_R5G5B5A1:
			return GL_UNSIGNED_SHORT_5_5_5_1;
		case PF_R8G8B8:	
		case PF_R8G8B8A8:
		case PF_L:
		case PF_A:
		case PF_LA:
			return GL_UNSIGNED_BYTE;
		case PF_NONE:
			return 0;
		}
	}

	int ToGLESTextureUnit( TextureUnit tu )
	{
		if(tu==TU_NONE)
		{
			return 0;
		}
		return tu+GL_TEXTURE0;
	}
    
    int ToGLESRenderState(CTRenderState rs)
    {
        switch (rs)
        {
            case RS_BLEND:
                return GL_BLEND;
            case RS_STENCIL_TEST:
                return GL_STENCIL_TEST;
            case RS_DEPTH_TEST:
                return GL_DEPTH_TEST;
            case RS_SCISSOR_TEST:
                return GL_SCISSOR_TEST;
                
            default:
                return -1;
                
        }
        return -1;
    }

    int ToGLESBlendFun(CTBlendFun bf)
    {
        switch (bf)
        {
            case BF_ADD:
                return GL_FUNC_ADD;
            case BF_SUBTRACT:
                return GL_FUNC_SUBTRACT;
            case BF_REVERSE_SUNTRACT:
                return GL_FUNC_REVERSE_SUBTRACT;
            default:
                return -1;
        }
        return -1;
    }
    
    int ToGLESSrcBlendState(CTBlendStateSrc bss)
    {
        switch(bss)
        {
            case BSS_ZERO:
                return GL_ZERO;
            case BSS_ONE:
                return GL_ONE;
            case BSS_DST_COLOR:
                return GL_DST_COLOR;
            case BSS_ONE_MINUS_DST_DST_COLOR:
                return GL_ONE_MINUS_DST_COLOR;
            case BSS_SRC_ALPHA_SATURATE:
                return GL_SRC_ALPHA_SATURATE;
            case BSS_SRC_ALPHA:
                return GL_SRC_ALPHA;
            case BSS_ONE_MINUS_SRC_ALPHA:
                return GL_ONE_MINUS_SRC_ALPHA;
            case BSS_DST_ALPHA:
                return GL_DST_ALPHA;
            case BSS_ONE_MINUS_DST_ALPHA:
                return GL_ONE_MINUS_DST_ALPHA;
            default:
                return -1;
        }
        return -1;
    }
    
    int ToGLESDstBlendState(CTBlendStateDst bsd)
    {
        switch(bsd)
        {
            case BSD_ZERO:
                return GL_ZERO;
            case BSD_ONE:
                return GL_ONE;
            case BSD_SRC_COLOR:
                return GL_SRC_COLOR;
            case BSD_ONE_MINUS_SRC_COLOR:
                return GL_ONE_MINUS_SRC_COLOR;
            case BSD_SRC_ALPHA:
                return GL_SRC_ALPHA;
            case BSD_ONE_MINUS_SRC_ALPHA:
                return GL_ONE_MINUS_SRC_ALPHA;
            case BSD_DST_ALPHA:
                return GL_DST_ALPHA;
            case BSD_ONE_MINUS_DST_ALPHA:
                return GL_ONE_MINUS_DST_ALPHA;
            default:
                return -1;
        }
        return -1;
        
    }


}