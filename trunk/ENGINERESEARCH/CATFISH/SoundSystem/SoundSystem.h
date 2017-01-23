#ifndef SOUNDSYSTEM_H_
#define SOUNDSYSTEM_H_ 
#include "SoundDllCommon.h"
#if __ANDROID__
#include "SoundSystemSL.h"
#else 
#include "SoundSystemAL.h"
#endif
namespace SoundSys
{
#if __ANDROID__
	class SoundSystem:public SoundSystemSL
#else
    class SOUND_API SoundSystem:public SoundSystemAL
#endif
	{
	public:
		static SoundSystem& GetInstance()
		{
			static SoundSystem instance;
			return instance;
		}
		~SoundSystem();
	protected:
		SoundSystem();
	private:
	};
}
#endif