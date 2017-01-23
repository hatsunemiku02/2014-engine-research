#if __ANDROID__
#include "SoundSystemSL.h"
#include <SLES/OpenSLES.h>
#include "Sound.h"
#include "../Common/Debug.h"
namespace SoundSys
{
	static const SLEnvironmentalReverbSettings gReverbSettings = SL_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR;
	static const int MaxSoundCound = 28;

	SoundSystemSL::SoundSystemSL()
	{

	}


	SoundSystemSL::~SoundSystemSL()
	{

	}

	bool SoundSystemSL::InitSoundSystem()
	{
		SLresult result;
		result = slCreateEngine(&mEngineObject, 0, NULL, 0, NULL, NULL);
		result = (*mEngineObject)->Realize(mEngineObject, SL_BOOLEAN_FALSE);

		result = (*mEngineObject)->GetInterface(mEngineObject, SL_IID_ENGINE, &mEngineEngine);

		const SLInterfaceID ids[1] = {SL_IID_ENVIRONMENTALREVERB};
		const SLboolean req[1] = {SL_BOOLEAN_FALSE};
		result = (*mEngineEngine)->CreateOutputMix(mEngineEngine, &mOutputMixObject, 1, ids, req);
		result = (*mOutputMixObject)->Realize(mOutputMixObject, SL_BOOLEAN_FALSE);
	
		result = (*mOutputMixObject)->GetInterface(mOutputMixObject, SL_IID_ENVIRONMENTALREVERB,
			&mOutputMixEnvironmentalReverb);
		if (SL_RESULT_SUCCESS == result) {
			result = (*mOutputMixEnvironmentalReverb)->SetEnvironmentalReverbProperties(
				mOutputMixEnvironmentalReverb, &gReverbSettings);
		}
		return true;
	}

	bool SoundSystemSL::DestorySoundSystem()
	{
		if(mOutputMixObject)//Çå³ýÉè±¸
		{
			(*mOutputMixObject)->Destroy(mOutputMixObject);
			mOutputMixObject = NULL;
		}
		if(mEngineObject)
		{
			(*mEngineObject)->Destroy(mEngineObject);
			mEngineObject = NULL;
		}
		return true;
	}

	Sound* SoundSystemSL::CreateSound(const std::string& path )
	{
		GetDataFromCache(path);
		SoundData data;

		SLresult result;

		// config audio source
		char* cp= new char[path.length() + 1];
		memcpy( cp, path.c_str(), path.length() + 1);
		SLDataLocator_URI loc_uri = {SL_DATALOCATOR_URI, (SLchar *)cp };
		SLDataFormat_MIME format_mime = {SL_DATAFORMAT_MIME, NULL, SL_CONTAINERTYPE_UNSPECIFIED};
		SLDataSource audioSrc = {&loc_uri, &format_mime};

		// config audio sink
		SLDataLocator_OutputMix loc_outmix = {SL_DATALOCATOR_OUTPUTMIX, mOutputMixObject};
		SLDataSink audioSnk = {&loc_outmix, NULL};

		// create audio player
		const SLInterfaceID ids[2] = {SL_IID_SEEK, SL_IID_VOLUME};
		const SLboolean req[2] = {SL_BOOLEAN_TRUE,SL_BOOLEAN_TRUE};
		result = (*mEngineEngine)->CreateAudioPlayer(mEngineEngine, &data.m_uriPlayerObject, &audioSrc, &audioSnk, 2, ids, req);


		// realize the player
		result = (*data.m_uriPlayerObject)->Realize(data.m_uriPlayerObject, SL_BOOLEAN_FALSE);
		if (SL_RESULT_SUCCESS != result) {
			
			(*data.m_uriPlayerObject)->Destroy(data.m_uriPlayerObject);
			data.m_uriPlayerObject = NULL;
			data.m_isLoaded = false;
			Sound* ssl = new Sound();
			ssl->SetData(data);
			return ssl;
		}

		// get the play interface
		result = (*data.m_uriPlayerObject)->GetInterface(data.m_uriPlayerObject, SL_IID_PLAY, &data.m_uriPlayerPlay);
	
		// get the seek interface
		result = (*data.m_uriPlayerObject)->GetInterface(data.m_uriPlayerObject, SL_IID_SEEK, &data.m_uriPlayerSeek);
	
		// get the volume interface
		result = (*data.m_uriPlayerObject)->GetInterface(data.m_uriPlayerObject, SL_IID_VOLUME, &data.m_uriPlayerVolume);
	
		result = (*data.m_uriPlayerObject)->GetInterface(data.m_uriPlayerObject, SL_IID_PITCH, &data.m_uriPlayerPitch);
		if ( SL_RESULT_SUCCESS != result )
		{
			data.m_uriPlayerPitch = NULL;
	
		}

		result = (*data.m_uriPlayerObject)->GetInterface(data.m_uriPlayerObject, SL_IID_PLAYBACKRATE, &data.m_uriPlayerRate);
		if ( SL_RESULT_SUCCESS != result )
		{
			data.m_uriPlayerRate = NULL;
		}
		delete [] cp;
		data.m_isLoaded = true;

		InsertDataToCache(path,data);

		Sound* ssl = new Sound();
		ssl->SetData(data);
		return ssl;

	}

	SoundData* SoundSystemSL::GetDataFromCache( const std::string& path )
	{
		std::map<std::string,SoundData>::iterator itr;
		itr = m_SoundDataMap.find(path);
		if (itr!=m_SoundDataMap.end())
		{
			return &(*itr).second;
		}
		return NULL;
	}

	bool SoundSystemSL::InsertDataToCache( const std::string& path,const SoundData& data )
	{
		if( GetDataFromCache(path) != NULL )
		{
			return false;
		}
		if( m_SoundDataMap.size()>MaxSoundCound )
		{
			std::map<std::string,SoundData>::iterator itr = m_SoundDataMap.begin();
			for (;itr!=m_SoundDataMap.end();itr++)
			{
				if (!IsPlaying(itr->second))
				{
					break;
				}
			}
			IFERROR(itr==m_SoundDataMap.end());
			DestorySound(itr->first);
		}
		m_SoundDataMap.insert(std::make_pair(path,data));
	}

	bool SoundSystemSL::DestorySound( const std::string& path )
	{
		SoundData* sd = GetDataFromCache(path);
		if (sd!=NULL)
		{
			(*sd->m_uriPlayerObject)->Destroy(sd->m_uriPlayerObject);
			sd->m_uriPlayerObject = NULL;
			sd->m_uriPlayerPitch = NULL;
			sd->m_uriPlayerPlay = NULL;
			sd->m_uriPlayerRate = NULL;
			sd->m_uriPlayerSeek = NULL;
			sd->m_uriPlayerVolume = NULL;
			m_SoundDataMap.erase(path);
			return true;
		}
		return false;
	}

	bool SoundSystemSL::IsPlaying( const SoundData& data )
	{
		if ( data.m_isLoaded )
		{
			SLuint32 state;
			(*data.m_uriPlayerPlay)->GetPlayState(data.m_uriPlayerPlay, &state);
			return  SL_PLAYSTATE_PLAYING == state;
		}
	}

}
#endif
