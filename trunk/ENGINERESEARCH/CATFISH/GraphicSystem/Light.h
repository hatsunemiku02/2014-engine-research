#pragma once
#include "cmlmath.h"
namespace GraphicSys
{

	class Light
	{
	public:
		Light();
		~Light();

		void SetPosition(const cml::vector3f& pos)
		{
			m_Position = pos;
		}

		const cml::vector3f& GetPosition() const
		{
			return m_Position;
		}

		void SetIntensity(float intensity)
		{
			m_Intensity;
		}

		int GetIntensity()
		{
			return m_Intensity;
		}
	protected:
		cml::vector3f m_Position;
		float         m_Intensity;

	private:
	};
}