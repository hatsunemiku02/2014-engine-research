#include "ShaderRes.h"
#include "FileReader.h"
#include "Shader.h"
#include "GpuProgram.h"
#include "GlesDevice.h"
namespace Resource
{
    //----animedefault
    const char* sgAnime2D = "\
    attribute highp vec4 myVertex;\
    attribute vec2 a_texCoord;\
    varying vec2 v_texCoord;\
    uniform highp vec2 _scale;\
    uniform highp vec2 _pos;\
    void main(void)\
    {\
        highp vec4 myVertextemp = myVertex;\
        myVertextemp.x = myVertex.x*_scale.x;\
        myVertextemp.y = myVertex.y*_scale.y;\
        myVertextemp.xy = myVertextemp.xy+_pos.xy;\
        gl_Position = myVertextemp;\
        v_texCoord = a_texCoord;\
    }\
    VertexPixel\
    uniform sampler2D s_texture;\
    varying mediump vec2 v_texCoord;\
    void main(void)\
    {\
        lowp vec4 color = texture2D(s_texture, v_texCoord);\
        gl_FragColor = color;\
    }";
    //----spritedefault
    const char* sgSprite2D = "\
    attribute highp vec4 myVertex;\
    attribute vec2 a_texCoord;\
    varying vec2 v_texCoord;\
    uniform highp vec2 _scale;\
    uniform highp vec2 _pos;\
    void main(void)\
    {\
    highp vec4 myVertextemp = myVertex;\
    myVertextemp.x = myVertex.x*_scale.x;\
    myVertextemp.y = myVertex.y*_scale.y;\
    myVertextemp.xy = myVertextemp.xy+_pos.xy;\
    gl_Position = myVertextemp;\
    v_texCoord = a_texCoord;\
    }\
    VertexPixel\
    uniform sampler2D s_texture;\
    varying mediump vec2 v_texCoord;\
    void main(void)\
    {\
        lowp vec4 color = texture2D(s_texture, v_texCoord);\
        gl_FragColor = color;\
    }";
    //-----fontdefault
    const char* sgFont = "\
    attribute highp vec4 myVertex;\
    attribute vec2 a_texCoord;\
    varying vec2 v_texCoord;\
    uniform highp vec2 _scale;\
    uniform highp vec2 _pos;\
    void main(void)\
    {\
        highp vec4 myVertextemp = myVertex;\
        myVertextemp.x = myVertex.x*_scale.x;\
        myVertextemp.y = myVertex.y*_scale.y;\
        myVertextemp.xy = myVertextemp.xy+_pos.xy;\
        gl_Position = myVertextemp;\
        v_texCoord = a_texCoord;\
    }\
    VertexPixel\
    uniform sampler2D s_texture;\
    varying mediump vec2 v_texCoord;\
    void main(void)\
    {\
        lowp vec4 color = texture2D(s_texture, v_texCoord);\
        color.x = 1.0;\
        color.y = 1.0;\
        color.z = 1.0;\
        gl_FragColor = color;\
    }";
    
	//----spritedefault
	const char* sgDefault3D = "\
							  attribute  vec4 myVertex;\
							  attribute  vec3 normal;\
							  attribute vec2 a_texCoord;\
							   varying vec2 v_texCoord;\
							  uniform  mat4 g_mvp;\
							  void main(void)\
							  {\
							  vec4 myVertextemp = g_mvp*myVertex;\
							  gl_Position = myVertextemp;\
							  v_texCoord = a_texCoord;\
							  }\
							  VertexPixel\
							  uniform sampler2D s_texture;\
							  varying vec2 v_texCoord;\
							  void main(void)\
							  {\
							  vec4 color = texture2D(s_texture, v_texCoord);\
							  gl_FragColor = color;\
							  }";

    GpuProgramRes::GpuProgramRes()
    {
        
    }
    
    GpuProgramRes::~GpuProgramRes()
    {
        
    }
    
	bool GpuProgramRes::Load( const std::string& path )
	{
		IO::FileReader reader;
		reader.OpenFile(path.c_str());
		long size = reader.GetSize();

		void* buffer = new unsigned char[size];
		reader.Read(size,buffer);
		m_pGpuProgram  =_phraseShader(buffer,size);

		reader.Close();
		delete[] buffer;
		return true;
	}

	bool GpuProgramRes::LoadDefault2D()
	{
		m_pGpuProgram = _phraseShader ((void*)sgSprite2D,strlen(sgSprite2D));
		return true;
	}


	bool GpuProgramRes::LoadDefault3D()
	{
		m_pGpuProgram = _phraseShader ((void*)sgDefault3D,strlen(sgDefault3D));
		return true;
	}


    bool GpuProgramRes::LoadDefaultFont()
    {
        m_pGpuProgram = _phraseShader ((void*)sgFont,strlen(sgFont));
		return true;
    }
	GraphicCore::GpuProgram* GpuProgramRes::_phraseShader( void* buffer,unsigned int length )
	{
		//hack---------------------------------------------
// 		std::string devicename = GraphicCore::GlesDevice::GetInstance().GetDeviceName();
// 		if(devicename=="opengl")
// 		{
// 			std::string shaderstr((char*)buffer); 
// 			//shaderstr.replace("highp","");
// 		}

		//--------------------------------------------------
		std::string shaderall = (char*)buffer;
		int split = shaderall.find("VertexPixel");
		int splitlength = 11;
		std::string vertexShader = shaderall.substr(0,split);
		std::string pixelShader = shaderall.substr(split+splitlength);

		GraphicCore::GLShader vshader;
		vshader.CreateShader(GraphicCore::GLShader::VERTEX,vertexShader.c_str());
		
		GraphicCore::GLShader fshader;
		fshader.CreateShader(GraphicCore::GLShader::FRAGMENT,pixelShader.c_str());
		
		GraphicCore::GpuProgram* ret  = GraphicCore::GpuProgram::CreateGpuPragram(vshader,fshader);
		return ret;
	}

}