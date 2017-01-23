#ifndef SOUNDSL_H_
#define SOUNDSL_H_ 
#include "SoundDllCommon.h"
#include "SoundData.h"

namespace SoundSys
{
	class SOUND_API SoundSL
	{
	public:
		SoundSL();
		~SoundSL();
		void Play();
		void SetData(const SoundData& data);
	protected:
		SoundData mData;
	private:
	};
}


#endif

