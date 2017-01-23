//
//  Font.h
//  Catfish
//
//  Created by zh on 14-3-25.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_Font_h
#define Catfish_Font_h
#include <vector>
#include <string>
#include "FontDllCommon.h"
typedef struct FT_LibraryRec_  *FT_Library;
typedef struct FT_FaceRec_     *FT_Face;
typedef struct FT_BitmapGlyphRec_*  FT_BitmapGlyph;
namespace GraphicCore {
    class GLTexture;
}
namespace FontSys
{
    struct FChar
    {
        FT_BitmapGlyph FBitmap;
        int  Height;
        int  HAdvance;
        int  HBearingX;
    };
    
    
    class FONT_API FontSystem
    {
    public:
        static FontSystem& GetInstance()
        {
            static FontSystem instance;
            return instance;
        }
        ~FontSystem();
        
        void InitFontSystem(const char* csfont);
        
        void SetFontSize(int w64,int h64,int width,int height);
        
        GraphicCore::GLTexture* GetTextureForString(const std::wstring& wstr,unsigned int width,unsigned int height);
       
        GraphicCore::GLTexture* GetTextureForString(const std::wstring& wstr,unsigned int width,unsigned int height,void* inBuffer);
        void Clear();
    protected:
        
        void loadChar(wchar_t c);
        GraphicCore::GLTexture* GenerateToTexture(unsigned int width,unsigned int height);
        GraphicCore::GLTexture* GenerateToTexture(unsigned int width,unsigned int height,void* inBuffer);
        FontSystem();
        FT_Library  m_FontLibrary;
        
        FT_Face m_FontFace;
        
        std::vector<FChar> m_vecBitmap;
    };
}
#endif
