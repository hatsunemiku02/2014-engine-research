#ifndef IMAGEPHASER_H_
#define IMAGEPHASER_H_

#include "DrawEnums.h"
#include "RDllCommon.h"
namespace GraphicCore
{
	class GLTexture;
}
namespace ResPha
{
	class ImagePhraser
	{
	public:
		static ImagePhraser& GetInstance()
		{
			static ImagePhraser instance;
			return instance;
		}
		~ImagePhraser();
		void Init();
		void Destory();
		GraphicCore::GLTexture* Phrase(void* buffer,unsigned int size);
	protected:
		ImagePhraser();
	};
	class RES_API ImageLoader
	{
	public:
		static ImageLoader& GetInstance()
		{
			static ImageLoader instance;
			return instance;
		}
		~ImageLoader();

		void LoadImageFromDisk(int& width,int& height,GraphicCore::PixelFormat& format,int& mimaps,int& size,void*& buffer);
		void GetTexBuffer(void* buffer);
	protected:
		ImageLoader();
	};
}
#endif