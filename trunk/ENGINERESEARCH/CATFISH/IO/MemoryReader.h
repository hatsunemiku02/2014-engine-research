#ifndef MEMORYREADER_H_
#define MEMORYREADER_H_

#include <stdio.h>
#include <string>
#include "IODLLCOMMON.h"
namespace IO
{
	class IO_API MemoryReader
	{


	public:
		MemoryReader();
		~MemoryReader();

		bool SetMemory(void* buffer,long size);


	protected:
		int ToNextStrEnd();
		void* m_pBuffer; 
		long m_CurrentPos;
	};
}


#endif