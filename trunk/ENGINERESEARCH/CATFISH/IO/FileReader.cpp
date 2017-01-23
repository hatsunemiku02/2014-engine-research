#include "FileReader.h"

namespace IO
{

	FileReader::FileReader()
		:m_pFile(NULL)
		,m_CurrentPos(0)
        ,m_Size(-1)
	{

	}

	FileReader::~FileReader()
	{

	}
	bool FileReader::OpenFile( const char* file )
	{
		m_pFile = fopen(file,"rb");
		if(m_pFile)
		{
			return true;
		}
		return false;
	}

	int FileReader::Seek( long size ,int pos)
	{
        switch(pos)
        {
            case SEEK_CUR:
                m_CurrentPos+=size;
                break;
            case SEEK_SET:
                m_CurrentPos=size;
                break;
            case SEEK_END:
                m_CurrentPos=GetSize()+size;
                break;
        }
		
		if (m_CurrentPos<0)
		{
			return -1;
		}
		
		return fseek(m_pFile,size,pos);
	}

	int FileReader::Read( long size,void* buffer )
	{
		int count =	fread(buffer,1,size,m_pFile);
		m_CurrentPos+=size;
		
		return count;
	}

	bool FileReader::Close()
	{
		fclose(m_pFile);
		m_pFile = 0;
		return true;
	}

	long FileReader::GetSize()
	{
        if(m_Size==-1)
        {
            long cur = ftell(m_pFile);
            fseek(m_pFile,0,SEEK_END);
            long size =	ftell(m_pFile);
            fseek(m_pFile,cur,SEEK_SET);
            m_Size =size;
        }
		return m_Size;
	}


}