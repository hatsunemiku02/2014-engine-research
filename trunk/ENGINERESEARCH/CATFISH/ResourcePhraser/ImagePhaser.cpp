#include "ImagePhaser.h"
#include "Texture.h"
#include "FreeImage.h"


using namespace GraphicCore;

namespace ResPha
{
	ImageLoader::~ImageLoader()
	{

	}

	ImageLoader::ImageLoader()
	{

	}

	void ImageLoader::LoadImageFromDisk( int& width,int& height,GraphicCore::PixelFormat& format,int& mimaps,int& size,void*& buffer  )
	{
		//≥ı ºªØFreeImage
	
		FreeImage_Initialise(false);

		FIBITMAP * bmp = FreeImage_Load(FIF_PNG,"..\\Media\\TTB.png",BMP_DEFAULT);

	
		if( bmp)
		{
			    FreeImage_Save(FIF_BMP, bmp, "whtm.bmp", BMP_DEFAULT);
		}

	
		width = FreeImage_GetWidth(bmp);
		height = FreeImage_GetHeight(bmp);
		unsigned int srcPitch = FreeImage_GetPitch(bmp);
		
		int ByteWidth = FreeImage_GetLine(bmp);

		
		unsigned bpp = FreeImage_GetBPP(bmp);
		
		FREE_IMAGE_TYPE imageType = FreeImage_GetImageType(bmp);
		FREE_IMAGE_COLOR_TYPE colourType = FreeImage_GetColorType(bmp);

		FreeImage_GetColorsUsed(bmp);
		buffer = FreeImage_GetBits(bmp);
		if(bpp==32)
		{
			format = GraphicCore::PF_R8G8B8A8;
		}
// 		FreeImage_Unload(bmp);
// 		
	}

	void ImageLoader::GetTexBuffer( void* buffer )
	{

	}

	ImagePhraser::ImagePhraser()
	{

	}

	ImagePhraser::~ImagePhraser()
	{

	}

	void ImagePhraser::Init()
	{
		FreeImage_Initialise(false);
	}

	void ImagePhraser::Destory()
	{
		FreeImage_DeInitialise();
	}

	GLTexture* ImagePhraser::Phrase(void* buffer,unsigned int size )
	{
		FIMEMORY * mem = FreeImage_OpenMemory((BYTE*)buffer,size);
		
		int fileType = FIF_UNKNOWN;
		fileType = FreeImage_GetFileTypeFromMemory(mem);
	

		FIBITMAP* bmp = FreeImage_LoadFromMemory( (FREE_IMAGE_FORMAT)fileType, mem );

		int width = FreeImage_GetWidth(bmp);
		int height = FreeImage_GetHeight(bmp);
		unsigned int srcPitch = FreeImage_GetPitch(bmp);
		int ByteWidth = FreeImage_GetLine(bmp);

        unsigned int __size = FreeImage_GetDIBSize(bmp);
		unsigned bpp = FreeImage_GetBPP(bmp);

		FREE_IMAGE_TYPE imageType = FreeImage_GetImageType(bmp);
		FREE_IMAGE_COLOR_TYPE colourType = FreeImage_GetColorType(bmp);

		FreeImage_GetColorsUsed(bmp);
		void* imagebuffer = FreeImage_GetBits(bmp);

		GraphicCore::PixelFormat format = GraphicCore::PF_NONE;
        switch (bpp) {
            case 32:
                format = GraphicCore::PF_R8G8B8A8;
                break;
            case 24:
                format = GraphicCore::PF_R8G8B8;
                break;
            case 8:
                format = GraphicCore::PF_R8G8B8;
                break;
            default:
                break;
        }

		GLTexture* pTex = GLTexture::CreateTexture(TT_TEXTURE2D,imagebuffer,width,height,format,0);

		 FreeImage_Unload(bmp);
		 FreeImage_CloseMemory(mem);
		 return pTex;
	}

}