#include "ImageRes.h"
#include "ImagePhaser.h"
#include "FileReader.h"
#include "Texture.h"
namespace Resource
{
	ImageRes::ImageRes()
	{

	}

	ImageRes::~ImageRes()
	{

	}

	bool ImageRes::Load(const std::string& path )
	{
		m_Path = path;
		IO::FileReader reader;
		reader.OpenFile(path.c_str());
		long size = reader.GetSize();

		void* buffer = new unsigned char[size];
		reader.Read(size,buffer);

		m_pTexture = ResPha::ImagePhraser::GetInstance().Phrase(buffer,size);
		reader.Close();
		delete[] buffer;
		return true;
	}

}