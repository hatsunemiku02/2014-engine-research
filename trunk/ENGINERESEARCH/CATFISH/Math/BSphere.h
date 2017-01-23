#pragma once
#include "cmlmath.h"
#include "ClipStatus.h"
namespace Math
{
	class BoxAABB;
	class BSphere
	{
	public:
		BSphere();
		~BSphere();


		void Set(const cml::vector3f& center,float size)
		{
			m_Center = center;
			m_Size = size;
		}

		const cml::vector3f& GetCenter()
		{
			return m_Center;
		}

		float GetSize()
		{
			return m_Size;
		}

		ClipStatus InterSect(const BSphere& sphere);
		ClipStatus InterSect(const BoxAABB& box);
	protected:




		cml::vector3f m_Center;
		float         m_Size;

	};
}