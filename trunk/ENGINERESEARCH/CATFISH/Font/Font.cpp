//
//  Font.cpp
//  Catfish
//
//  Created by zh on 14-3-25.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Font.h"
#include "../../freetype/include/ft2build.h"
#include "../../freetype/include/freetype.h"
#include "../../freetype/include/ftglyph.h"
#include "Texture.h"
#include "DrawEnums.h"
using namespace GraphicCore;
namespace FontSys
{
    FontSystem::FontSystem()
    {
        
        
    }
    FontSystem::~FontSystem()
    {
        
    }
    void FontSystem::InitFontSystem(const char* csfont)
    {
        int error = 0;
        error = FT_Init_FreeType(&m_FontLibrary);
        if (error) {
            
        }
        
        error = FT_New_Face( m_FontLibrary,csfont,0,&m_FontFace );
        if(error)
        {
            int i = FT_Err_Unknown_File_Format;
        }
        
        error =  FT_Select_Charmap(m_FontFace, FT_ENCODING_UNICODE);
        if(error)
        {
            int i = FT_Err_Unknown_File_Format;
        }
        error =	FT_Set_Pixel_Sizes(m_FontFace, 16, 16);
        if(error)
        {
            int i = FT_Err_Unknown_File_Format;
        }

    }
    
    void FontSystem::SetFontSize(int w64,int h64,int width,int height)
    {
        
    }
    
    GraphicCore::GLTexture* FontSystem::GetTextureForString(const std::wstring& wstr,unsigned int width,unsigned int height,void* inBuffer)
    {
        for(int i = 0;i<wstr.length();i++)
        {
            loadChar(wstr[i]);
        }
        return GenerateToTexture(width,height,inBuffer);   
    }
    
    
    GraphicCore::GLTexture* FontSystem::GetTextureForString(const std::wstring& wstr,unsigned int width,unsigned int height)
    {
        for(int i = 0;i<wstr.length();i++)
        {
            loadChar(wstr[i]);
        }
        return GenerateToTexture(width,height);
    }
    
    
    void FontSystem::loadChar(wchar_t c)
    {
        int error = 0;
        FT_UInt index = FT_Get_Char_Index( m_FontFace, c );
        error = FT_Load_Glyph(m_FontFace,index , FT_LOAD_DEFAULT);
        //得到字模
        FT_Glyph glyph;
        error =  FT_Get_Glyph( m_FontFace->glyph, &glyph );
        //转化成位图
        error = FT_Render_Glyph( m_FontFace->glyph,   FT_RENDER_MODE_LCD );
        
        FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
        FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
    
        
        FChar fc;
        fc.Height =  16 - bitmap_glyph->bitmap.rows;
        fc.FBitmap = bitmap_glyph;
        fc.HAdvance = m_FontFace->glyph->metrics.horiAdvance;
    
        fc.HBearingX = m_FontFace->glyph->metrics.horiBearingX;
        
        m_vecBitmap.push_back(fc);
    }
    
    void FontSystem::Clear()
    {
        
    }
    GraphicCore::GLTexture* FontSystem::GenerateToTexture(unsigned int width,unsigned int height,void* pTexBuffer)
    {
        PixelFormat format = PF_A;
        unsigned int texSize = height*width;
       
        unsigned int usedWidth = 0;
        unsigned int usedHeight = 0;
        
        memset(pTexBuffer, 0, texSize);
        
        for(int i = 0;i<m_vecBitmap.size();i++)
        {
            FT_Bitmap& bitmap=m_vecBitmap[i].FBitmap->bitmap;
            int _height = bitmap.rows;
            int _width = bitmap.width;
            int _starty = m_vecBitmap[i].Height;
            int _hadcanve = m_vecBitmap[i].HAdvance;
            if(usedWidth+_width>width)
            {
                usedHeight+=_height+_starty;
                usedWidth = 0;
            }
            if(usedHeight+_height+_starty>height)
            {
                break;
            }
            for(int line = 0;line < _height;line++)
            {
                unsigned char* _buffer = (unsigned char*)pTexBuffer;
                
                _buffer += (height-usedHeight-line-_starty-1)*width;
                _buffer += usedWidth;
                
                unsigned char* _bmbuffer = (unsigned char*)(bitmap.buffer);
                _bmbuffer += (line)*_width;
                
                memcpy(_buffer, _bmbuffer, _width);
            }
            usedWidth+=_width;
            FT_Done_Glyph((FT_Glyph)m_vecBitmap[i].FBitmap);
        }
        
        GLTexture* pTex = GLTexture::CreateTexture(TT_TEXTURE2D,pTexBuffer,width,height,format,0);
        
        m_vecBitmap.clear();
        
        return pTex;

    }
    
    GLTexture* FontSystem::GenerateToTexture(unsigned int width,unsigned int height)
    {
        unsigned int texSize = height*width;
        void* pTexBuffer = new unsigned char[texSize];
        GLTexture* pTex = GenerateToTexture(width,height,pTexBuffer);
        delete[] pTexBuffer;
        return pTex;
   /*
        PixelFormat format = PF_A;
        unsigned int texSize = height*width;
        void* pTexBuffer = new unsigned char[texSize];
        unsigned int usedWidth = 0;
        unsigned int usedHeight = 0;
        
        memset(pTexBuffer, 0, texSize);
        
        for(int i = 0;i<m_vecBitmap.size();i++)
        {
            FT_Bitmap& bitmap=m_vecBitmap[i].FBitmap->bitmap;
            int _height = bitmap.rows;
            int _width = bitmap.width;
            int _starty = m_vecBitmap[i].Height;
            int _hadcanve = m_vecBitmap[i].HAdvance;
            if(usedWidth+_width>width)
            {
                usedHeight+=_height+_starty;
                usedWidth = 0;
            }
            if(usedHeight+_height+_starty>height)
            {
                break;
            }
            for(int line = 0;line < _height;line++)
            {
                unsigned char* _buffer = (unsigned char*)pTexBuffer;
                
                _buffer += (height-usedHeight-line-_starty-1)*width;
              //  _buffer += ((line+_starty)*width+   usedHeight*width);
                _buffer += usedWidth;
                
                unsigned char* _bmbuffer = (unsigned char*)(bitmap.buffer);
                _bmbuffer += (line)*_width;
                
                memcpy(_buffer, _bmbuffer, _width);
            }
            usedWidth+=_width;
            FT_Done_Glyph((FT_Glyph)m_vecBitmap[i].FBitmap);
        }
        
        Texture* pTex = Texture::CreateTexture(TT_TEXTURE2D,pTexBuffer,width,height,format,0);
        delete[] pTexBuffer;
        
        m_vecBitmap.clear();
        
        return pTex;
    */
    }
}