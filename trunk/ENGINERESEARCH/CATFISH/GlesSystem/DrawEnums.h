#ifndef DRAWENUMS_H_
#define DRAWENUMS_H_
namespace GraphicCore
{
	enum DrawMode
	{
		DM_POINTS = 0,
		DM_LINES,                        
		DM_LINE_LOOP,
		DM_LINE_STRIP,
		DM_TRIANGLE_LIST,
		DM_TRIANGLE_STRIP,
		DM_TRIANGLE_FAN,
	};

	int ToGLESDrawMode(DrawMode mode);

	enum StroageMode
	{
		SM_STREAM  ,
		SM_STATIC  ,
		SM_DYNAMIC ,
	};

	int ToGLESStorageMode(StroageMode mode);

	enum RenderState
	{

	};

	enum SamplerState
	{

	};

	enum AddressMode
	{
		AM_WRAP ,
		AM_CLAMP ,
		AM_PINGPANG ,
		AM_BORDER,
	};

	int ToGLESAddressMode(AddressMode mode);

	enum PixelFormat
	{
		PF_NONE = -1,
		PF_A,
		PF_R8G8B8,
		PF_R5G6B5,
		PF_R8G8B8A8,
		PF_R5G5B5A1,
		PF_L,
		PF_LA,
	};

	int ToGLESPixelFormat(PixelFormat format);
	int ToGLESPixelType(PixelFormat format);
	
	enum TextureType
	{
		TT_NONE = -1,
		TT_TEXTURE2D,
	};

	int ToGLESTextureType(TextureType type);

	enum TextureUnit
	{
		TU_NONE = -1,
		TU_TEX0 ,
		TU_TEX1,
		TU_TEX2,
		TU_TEX3,
		TU_TEX4,
		TU_TEX5,
		TU_TEX6,
		TU_TEX7,
		TU_TEX8,
		TU_TEX9,
	};

	int ToGLESTextureUnit(TextureUnit tu);
    
    enum CTRenderState
    {
        RS_NONE = -1,
        RS_BLEND = 0,
        RS_STENCIL_TEST,
        RS_DEPTH_TEST,
        RS_SCISSOR_TEST,
    };
    
    int ToGLESRenderState(CTRenderState rs);
   
    enum CTBlendFun
    {
        BF_ADD = 0,
        BF_SUBTRACT = 1,
        BF_REVERSE_SUNTRACT = 2,
    };
    
    int ToGLESBlendFun(CTBlendFun bf);
    
    enum CTBlendStateSrc
    {
        BSS_ZERO = 0,
        BSS_ONE = 1,
        BSS_DST_COLOR,
        BSS_ONE_MINUS_DST_DST_COLOR ,
        BSS_SRC_ALPHA,
        BSS_SRC_ALPHA_SATURATE,
        BSS_ONE_MINUS_SRC_ALPHA,
        BSS_DST_ALPHA,
        BSS_ONE_MINUS_DST_ALPHA,
    };

    int ToGLESSrcBlendState(CTBlendStateSrc bss);

    enum CTBlendStateDst
    {
        BSD_ZERO = 0,
        BSD_ONE = 1,
        BSD_SRC_COLOR = 2,
        BSD_ONE_MINUS_SRC_COLOR,
        BSD_SRC_ALPHA,
        BSD_ONE_MINUS_SRC_ALPHA,
        BSD_DST_ALPHA,
        BSD_ONE_MINUS_DST_ALPHA,

    };
    
    int ToGLESDstBlendState(CTBlendStateDst bsd);

    
}

































#endif