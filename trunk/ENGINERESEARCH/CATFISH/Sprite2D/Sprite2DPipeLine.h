#pragma once
#include <vector>
namespace Sprite
{
    class Sprite2D;
}
namespace PipeLine
{
	
	class Sprite2DPipeLine
	{
	public:
		static Sprite2DPipeLine& GetInstance()
		{
			static Sprite2DPipeLine instance;
			return instance;
		}
		~Sprite2DPipeLine();

		bool AddSprite(const Sprite::Sprite2D* sprite);
        
        void RenderAll();
	protected:
        
        void _sortAll();
        
        
        std::vector<Sprite::Sprite2D*> m_vecSprite2D;
        bool m_bBeedSort;
	private:
	};
}