#pragma once
#include "ClipStatus.h"
#include "cmlmath.h"
#include "MathDllCommon.h"
namespace Math
{
	class MATH_API BoxAABB
	{

	public:
		BoxAABB()
			:m_center()
			,m_size()
		{

		}

		~BoxAABB()
		{

		}
		void Set(const vector3f& size ,const vector3f& center)
		{
			m_size = size;
			m_center = center;
		}
		ClipStatus InterSect(const BoxAABB& box);
		void Extend(const BoxAABB* box);
		void transform(const cml::matrix44f& m);
		vector4f cornerPoint(int index) const;


		cml::vector3f GetMax() const
		{
			return m_center+m_size;
		}

		cml::vector3f GetMin() const
		{
			return m_center-m_size;
		}

		const cml::vector3f& GetCenter()
		{
			return m_center;
		}

		const cml::vector3f& GetSize()
		{
			return m_size;
		}

	protected:
		cml::vector3f m_center;
		cml::vector3f m_size;
	};

}