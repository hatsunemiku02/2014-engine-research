#ifndef _SOUNDDATA_H_
#define _SOUNDDATA_H_

struct SLObjectItf_;
typedef const struct SLObjectItf_ * const * SLObjectItf;
struct SLEngineItf_;
typedef const struct SLEngineItf_ * const * SLEngineItf;
struct SLPlayItf_;
typedef const struct SLPlayItf_ * const * SLPlayItf;
struct SLSeekItf_;
typedef const struct SLSeekItf_ * const * SLSeekItf;
struct SLEnvironmentalReverbItf_;
typedef const struct SLEnvironmentalReverbItf_ * const * SLEnvironmentalReverbItf;
struct SLVolumeItf_;
typedef const struct SLVolumeItf_ * const * SLVolumeItf;
struct SLPlaybackRateItf_;
typedef const struct SLPlaybackRateItf_ * const * SLPlaybackRateItf;
struct SLPitchItf_;
typedef const struct SLPitchItf_ * const * SLPitchItf;

struct SOUND_API SoundData //保存可播放的音乐结构体
{
	bool				m_isLoaded;
	SLObjectItf			m_uriPlayerObject;
	SLPlayItf			m_uriPlayerPlay;
	SLSeekItf			m_uriPlayerSeek;
	SLVolumeItf			m_uriPlayerVolume;
	SLPlaybackRateItf	m_uriPlayerRate;
	SLPitchItf			m_uriPlayerPitch;
	SoundData()
		:m_isLoaded(false),
		m_uriPlayerObject(0),
		m_uriPlayerPlay(0),
		m_uriPlayerSeek(0),
		m_uriPlayerVolume(0)
	{

	}
};


#endif