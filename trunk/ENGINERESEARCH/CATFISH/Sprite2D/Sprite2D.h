#pragma once
#include <string>
#include "Primitive2D.h"
#include "../Math/cmlmath.h"
namespace Resource
{
    class ImageRes;
    class MeshRes;
    class GpuProgramRes;
}
namespace GraphicSys
{
    class RenderUnit;
}
namespace Sprite
{
  
	class Sprite2D
	{
	public:
		Sprite2D();
		~Sprite2D();

        static Sprite2D* CreateSprite2D(const std::string& texPath,const Math::vector2i& pos ,const Math::vector2f& scale,float rot,int lvl);
        
        void Show();
        void Hide();
		void SetPosition(const Math::vector2i& pos);
		void SetScale(const Math::vector2f& scale);
		void SetRotation(float rot);
		void SetLevel(int lvl);
		void SetTexture(const std::string& texPath);
        
        Resource::MeshRes* GetMeshRes()
        {
            return m_pMeshRectRes;
        }
        Resource::GpuProgramRes* GetGpuProgramRes()
        {
            return m_pGpuProgramRes;
        }
        Resource::ImageRes* GetTextureRes()
        {
            return m_pTextureRes;
        }
        Math::vector2i& GetPosition()
        {
            return m_Position;
        }
        Math::vector2f& GetScale()
        {
            return m_Scale;
        }
        
        int GetLevel()
        {
            return m_Level;
        }
	protected:

		Math::vector2i m_Position; // this pos is pixel
		Math::vector2f m_Scale;
		float m_Rotation;
		int m_Level;//display level
        Resource::ImageRes* m_pTextureRes;
        Resource::MeshRes* m_pMeshRectRes;
        Resource::GpuProgramRes* m_pGpuProgramRes;
        
        GraphicSys::RenderUnit* m_pRU;
        
        bool m_bShow;
	private:

	};

}