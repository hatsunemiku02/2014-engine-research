#include "MemoryReader.h"
namespace IO
{


	

	bool MemoryReader::SetMemory(void* buffer,long size )
	{
		if (m_pBuffer!=buffer)
		{
			m_pBuffer = buffer;
			m_CurrentPos = 0;
		}
		return false;
	}

	int MemoryReader::ToNextStrEnd()
	{
		int pos = m_CurrentPos;

		
	

		return pos-m_CurrentPos;
		
	}

}