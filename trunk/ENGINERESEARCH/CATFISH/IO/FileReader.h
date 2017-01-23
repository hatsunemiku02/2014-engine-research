#ifndef FILEREADER_H_
#define FILEREADER_H_
#include <stdio.h>
#include "IODLLCOMMON.h"
namespace IO
{
	class IO_API FileReader
	{
	public:
		FileReader();
		~FileReader();

		bool OpenFile(const char* file);
		int Seek(long size , int pos = 0);
		int Read(long size,void* buffer);
        
		bool Close();
		long GetSize();
        
        
        long GetPos()
        {
            return m_CurrentPos;
        }
	protected:

		FILE* m_pFile; 
		long m_CurrentPos;
        long m_Size;

	};
}
#endif