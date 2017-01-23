#include "Texture.h"
#include "GlesDevice.h"
#include "GDebug.h"
#include "CommonMath.h"
#include "OpenglHeader.h"

namespace GraphicCore
{
	GLTexture::GLTexture()
		:m_Height(0)
		,m_Width(0)
		,m_MipmapNum(0)
		,m_PixelFormat(PF_NONE)
		,m_Type(TT_NONE)
		,m_Texture(-1)
	{

	}

	GLTexture::~GLTexture()
	{
       
	}

	void GLTexture::DestoryTexture( GLTexture* tex )
	{
        
        GlesDevice::GetInstance().BindTexture(tex->m_Type,NULL);
       
		glDeleteTextures(1,&tex->m_Texture);
        CHECKGLERROR;
		tex->m_Height = 0;
		tex->m_Width = 0;
		tex->m_MipmapNum = 0;
		tex->m_PixelFormat = PF_NONE;
		tex->m_Type = TT_NONE;
		tex->m_Texture = -1;

	}


	GLTexture* GLTexture::CreateTexture(TextureType type, void* buffer,unsigned int width,unsigned int height,PixelFormat format,unsigned int mipMapNum)
	{
		GLTexture* pOut = new GLTexture();
		pOut->m_Type = type;
		pOut->m_Width = width;
		pOut->m_Height = height;
		pOut->m_PixelFormat = format;
		pOut->m_MipmapNum = mipMapNum;
		switch (type)
		{
		case TT_TEXTURE2D:
			pOut->CreateTexture2D(buffer);
			break;
		default:
			delete pOut;
			pOut = NULL;
			break;
		}
		return pOut;
	}

	bool GLTexture::CreateTexture2D( void* buffer)
	{
		glGenTextures(1,&m_Texture);
        
		GlesDevice::GetInstance().BindTexture(m_Type,this);
		unsigned int _width = m_Width;
		unsigned int _height = m_Height;
        
        
        
        bool canmipmap = Math::IsPowerOfTwo(m_Width)&&Math::IsPowerOfTwo(m_Height);
        
		for (unsigned int i=0;i<=m_MipmapNum;i++)
		{
			glTexImage2D(GL_TEXTURE_2D, i, ToGLESPixelFormat(m_PixelFormat),_width, _height, 0, ToGLESPixelFormat(m_PixelFormat),
				ToGLESPixelType(m_PixelFormat), buffer);// the gles pixel format should be the same with the input texture.
			CHECKGLERROR;
			ToNextMipMap(buffer,_width,_height,m_PixelFormat);
		}
 	

		if(m_MipmapNum<1&&canmipmap)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
            CHECKGLERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            CHECKGLERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            CHECKGLERROR;
            
			
		}
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            CHECKGLERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            CHECKGLERROR;
            
        }
        
 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        CHECKGLERROR;
 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        CHECKGLERROR;
		return true;
	}

	void GLTexture::ToNextMipMap( void*& buffer,unsigned int& width,unsigned int& height,PixelFormat format )
	{
		buffer = (unsigned char* )buffer +	GetTexMemorySize(format,width,height);
#ifdef max
#undef max
#endif
#define max(r,t)   r > t ? r : t; 
		width  =max(width/2,1) ;
		height =max(height/2,1);
#undef max
	}

	unsigned int GLTexture::GetTexMemorySize( PixelFormat format,unsigned int width,unsigned int height )
	{
		switch(format)
		{
		case PF_A:
		case PF_L:
            return width*height;
		case PF_R8G8B8:
			return width*height*3;
		case PF_LA:
		case PF_R8G8B8A8:
			return width*height*4;
		case PF_R5G6B5:
		case PF_R5G5B5A1:
			return width*height*2;
		}
		return 0; 
	}


}