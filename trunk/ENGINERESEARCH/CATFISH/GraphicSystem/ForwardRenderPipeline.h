#include "RenderPipeline.h"
namespace GraphicCore
{
	class FrameBufferObj;
}

namespace GraphicSys
{
	class Camera;
	
	class GRAPHIC_API ForwardRenderPipeline:public RenderPipeline
	{
	public:
		static ForwardRenderPipeline& GetInstance()
		{
			static ForwardRenderPipeline instance;
			return instance;
		}
		~ForwardRenderPipeline();

		virtual void AddRenderUnit(const RenderUnit* unit);

		virtual void RemoveRenderUnit(const RenderUnit* unit);

		virtual void RenderAll();

		Camera* GetCamera()
		{
			return m_pCamera;
		}
	protected:
		ForwardRenderPipeline();
		Camera* m_pCamera;
		GraphicCore::FrameBufferObj* m_pDepthBuffer;
		GraphicCore::FrameBufferObj* m_pSwapBuffer;
	};

}