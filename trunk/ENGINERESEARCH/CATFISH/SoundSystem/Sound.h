#ifndef SOUND_H_
#define SOUND_H_ 
#if __ANDROID__
#include "SoundSL.h"
#else
#include "SoundAL.h"
#endif
namespace SoundSys
{
#if __ANDROID__
	class Sound:public SoundSL
#else
    class Sound:public SoundAL
#endif
	{
	public:
		Sound();
		~Sound();
	};
}

#endif