#ifndef SOUNDSYSTEMSL_H_
#define SOUNDSYSTEMSL_H_ 
#include "SoundDllCommon.h"
#include <string>
#include <map>
#include "SoundData.h"


namespace SoundSys
{
	class Sound;

	class SOUND_API SoundSystemSL
	{
	public:
		static SoundSystemSL& GetInstance()
		{
			static SoundSystemSL instance;
			return instance;
		}
		~SoundSystemSL();

		bool InitSoundSystem();
		bool DestorySoundSystem();
		Sound* CreateSound(const std::string& path);
		bool DestorySound(const std::string& path);
	protected:
		std::map<std::string,SoundData> m_SoundDataMap;

		SoundData* GetDataFromCache(const std::string& path);
		bool InsertDataToCache(const std::string& path,const SoundData& data);
		bool IsPlaying(const SoundData& data);
		SLObjectItf mEngineObject;
		SLEngineItf mEngineEngine;

		// output mix interfaces
		SLObjectItf mOutputMixObject;
		SLEnvironmentalReverbItf mOutputMixEnvironmentalReverb;

		SoundSystemSL();

	};
}
#endif