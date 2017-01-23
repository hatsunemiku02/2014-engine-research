#pragma once
namespace GraphicCore
{
	class GLVertexBufferObj;
	class GLIndexBufferObj;
}
namespace Sprite
{
	class Primitive2D
	{
	public:
		static Primitive2D& GetInstance()
		{
			static Primitive2D instance;
			return instance;
		}
		~Primitive2D();

		GraphicCore::GLVertexBufferObj* GetVBO()
		{
			return m_pVbo;
		}
		GraphicCore::GLIndexBufferObj* GetIBO()
		{
			return m_pIbo;
		}
	protected:
		GraphicCore::GLVertexBufferObj* m_pVbo ;
		GraphicCore::GLIndexBufferObj* m_pIbo ;
	private:
		Primitive2D();
	};
}