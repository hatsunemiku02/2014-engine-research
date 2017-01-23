#include "MeshRes.h"
#include "FileReader.h"
#include "ObjMeshPhraser.h"
#include "PrimitiveGroup.h"
#include "IndexBufferObj.h"
#include "VertexBufferObj.h"
#include "VertexLayout.h"
#include <string>
#include <assert.h>
#include <map>
/*

vertex format:

PCNTBttttttt
443332222222

index format:

is

*/
namespace Resource
{
	float afVertives[] = 
	{
		-1.0f,-1.0f,0.8f,1.0f,0.0f,0.0f,
		1.0f,-1.0f,0.8f,1.0f,1.0f,0.0f,
		1.0f,1.0f,0.8f,1.0f,1.0f,1.0f,
		-1.0f,1.0f,0.8f,1.0f,0.0f,1.0f,
	};

	unsigned short indexs[] =
	{
		0,1,2,0,2,3
	};

    MeshRes::MeshRes()
    {
        
    }
    MeshRes::~MeshRes()
    {
        
    }
    
	GraphicCore::VertexLayout MeshRes::GetLayout( char* layout )
	{
		std::map<int,GraphicCore::VertexLayout::Ele> ret;
		int length = strlen(layout);

		int loc = 0;
		int offset = 0;
		GraphicCore::VertexLayout::Ele* pEle = NULL;
		for(int i=0;i<length;i++)
		{
			loc = i;
			switch(layout[i])
			{
			case 'P':
// 				pEle = new GraphicCore::VertexLayout::Ele(loc,4,sizeof(float),offset);
// 				ret.insert(std::make_pair(loc,*pEle));
// 				delete pEle;
// 				offset+=4*sizeof(float);
//				break;
			case 'C':
				pEle = new GraphicCore::VertexLayout::Ele(loc,4,sizeof(float),offset);
				ret.insert(std::make_pair(loc,*pEle));
				delete pEle;
				offset+=4*sizeof(float);
				break;
			case 'N':
				pEle = new GraphicCore::VertexLayout::Ele(loc,3,sizeof(float),offset);
				ret.insert(std::make_pair(loc,*pEle));
				delete pEle;
				offset+=3*sizeof(float);
				break;
			case 'T':
				pEle = new GraphicCore::VertexLayout::Ele(loc,3,sizeof(float),offset);
				ret.insert(std::make_pair(loc,*pEle));
				delete pEle;
				offset+=3*sizeof(float);
				break;
			case 'B':
				pEle = new GraphicCore::VertexLayout::Ele(loc,3,sizeof(float),offset);
				ret.insert(std::make_pair(loc,*pEle));
				delete pEle;
				offset+=3*sizeof(float);
				break;
			case 't':
				pEle = new GraphicCore::VertexLayout::Ele(loc,2,sizeof(float),4*sizeof(float));
				ret.insert(std::make_pair(loc,*pEle));
				delete pEle;
				offset+=2*sizeof(float);
				break;
			default: assert(0);
			}

		}
		GraphicCore::VertexLayout VerLayoutRet;
		VerLayoutRet.BuildLayout(ret);
		return VerLayoutRet;
	}

	bool MeshRes::Load( const std::string& path )
	{
		m_Path = path;
		IO::FileReader reader;
		reader.OpenFile(path.c_str());
		long size = reader.GetSize();

		void* buffer = new unsigned char[size];
		reader.Read(size,buffer);

		int headerlength = 0;
		char* headercontent = NULL;
		int vertexbuffersize = 0;
		void* vertexbuffer = NULL;
		int indexbuffersize = 0;
		void* indexbuffer = NULL;
		char* ptr = (char*)buffer;
		int* intconvert = 0;
		intconvert = (int*)ptr;
		headerlength = *intconvert;
		ptr+=sizeof(int);

		headercontent = ptr;
		ptr+=headerlength;

		intconvert = (int*)ptr;
		vertexbuffersize = *intconvert;
		ptr+=sizeof(int);

		vertexbuffer = ptr;
		ptr+=vertexbuffersize;

		intconvert = (int*)ptr;
		indexbuffersize = *intconvert;
		ptr+=sizeof(int);

		indexbuffer = ptr;

		GraphicCore::VertexLayout layout = GetLayout(headercontent);


		m_pPrimitiveGroup = ResPha::ObjMeshPhraser::GetInstance().Phrase((float*)vertexbuffer,vertexbuffersize/4,(unsigned short*)indexbuffer,indexbuffersize/2,layout);

		reader.Close();
		delete[] buffer;
		return true;
	}

	bool MeshRes::LoadDefaultRect()
	{
		std::map<int,GraphicCore::VertexLayout::Ele> layout;
		GraphicCore::VertexLayout::Ele eleVtx(0,4,sizeof(float),0);
		GraphicCore::VertexLayout::Ele eleUV(1,2,sizeof(float),4*sizeof(float));
		layout.insert(std::make_pair(0,eleVtx));
		layout.insert(std::make_pair(1,eleUV));
		GraphicCore::VertexLayout VerLayout;
		VerLayout.BuildLayout(layout);

		m_pPrimitiveGroup = ResPha::ObjMeshPhraser::GetInstance().Phrase(afVertives,24,indexs,6,VerLayout);

		return true;
	}

}