#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "GDllCommon.h"
#include "DrawEnums.h"
#include "cmlmath.h"

namespace GraphicCore
{
	class GlesDevice;
	class RENDERER_API GLTexture
	{
	public:
		~GLTexture();
		static GLTexture* CreateTexture(TextureType type,void* buffer,unsigned int width,unsigned int height,PixelFormat format,unsigned int mipMapNum);
		static	void DestoryTexture(GLTexture* tex);
        
        int GetWidth() const
        {
            return m_Width;
        }
        
        int GetHeight() const
        {
            return m_Height;
        }
	protected:
		bool CreateTexture2D(void* buffer);
		unsigned int GetTexMemorySize( PixelFormat format,unsigned int width,unsigned int height);
		void ToNextMipMap(void*& buffer,unsigned int& width,unsigned int& height,PixelFormat format);

		friend class GlesDevice;

		unsigned int m_Texture;
		unsigned int m_Width;
		unsigned int m_Height;
		unsigned int m_MipmapNum;
		PixelFormat  m_PixelFormat;
		TextureType  m_Type;
	private:
		GLTexture();
	};
}


#endif