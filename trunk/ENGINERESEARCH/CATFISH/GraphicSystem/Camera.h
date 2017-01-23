#include "cmlmath.h"
namespace GraphicSys
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void SetView(const cml::matrix44f& view)
		{
			m_View = view;
		}

		void SetProj(const cml::matrix44f& proj)
		{
			m_Proj = proj;
		}

		const cml::matrix44f& GetView()
		{
			return m_View;
		}

		const cml::matrix44f& GetProj()
		{
			return m_Proj;
		}
	protected:
		cml::matrix44f m_View;
		cml::matrix44f m_Proj;
	};
}