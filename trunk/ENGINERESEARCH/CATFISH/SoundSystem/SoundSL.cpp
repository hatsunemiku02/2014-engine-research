#if __ANDROID__
#include "SoundSL.h"
#include <SLES/OpenSLES.h>
namespace SoundSys
{
	
	SoundSL::SoundSL()
	{

	}

	SoundSL::~SoundSL()
	{

	}

	void SoundSL::Play()
	{
		(*mData.m_uriPlayerPlay)->SetPlayState(mData.m_uriPlayerPlay, SL_PLAYSTATE_PLAYING );
	}

	void SoundSL::SetData( const SoundData& data )
	{
		mData = data;
	}

}
#endif