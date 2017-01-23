#pragma once
#include "Light.h"
namespace GraphicSys
{
	class DirectionalLight:public Light
	{
	public:
		DirectionalLight();
		~DirectionalLight();


		void SetDirect(const cml::vector3f& dir)
		{
			m_Direction = dir;
		}

		const cml::vector3f& GetDirect() const
		{
			return m_Direction;
		}

	protected:
		cml::vector3f m_Direction;

	private:
	};
}