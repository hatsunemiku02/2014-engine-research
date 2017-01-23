
#include "Frustum.h"
#include "RenderUnit.h"
#include "ForwardRenderPipeline.h"
#include "CullerQuadTree.h"
#include "GlesDevice.h"
#include "Camera.h"
#include "Material.h"


namespace GraphicSys
{
	ForwardRenderPipeline::ForwardRenderPipeline()
	{
		m_pCuller = new CullerQuadTree();
		CullerQuadTree* pc = (CullerQuadTree*)m_pCuller;
		Math::BoxAABB box;
		box.Set(vector3f(500,500,500),vector3f(0,0,0));
		pc->InitQuatTree(box,4);

		m_pCamera = new Camera();
	}

	ForwardRenderPipeline::~ForwardRenderPipeline()
	{
		delete m_pCamera;
	}


	void ForwardRenderPipeline::AddRenderUnit( const RenderUnit* unit )
	{
		m_pCuller->AddRenderUnit(unit);
	}

	void ForwardRenderPipeline::RemoveRenderUnit( const RenderUnit* unit )
	{

	}

	void ForwardRenderPipeline::RenderAll()
	{
		std::multimap<unsigned int,RenderUnit*>::iterator iter;
		std::multimap<unsigned int,RenderUnit*> _mapRenders;


		Math::Frustum f;
		f.InitFrustum(m_pCamera->GetView(),m_pCamera->GetProj());

		m_pCuller->Cull(&f, _mapRenders);

		iter = _mapRenders.begin();
		for(;iter!=_mapRenders.end();iter++)
		{
			
			GraphicCore::GlesDevice::GetInstance().SetCurrentGPG(iter->second->GetMaterial()->GetGpuPro());
			iter->second->ApplyParamToGpu();
			GraphicCore::GlesDevice::GetInstance().SetCurrentVBO(iter->second->m_pVBO);
			GraphicCore::GlesDevice::GetInstance().SetCurrentIBO(iter->second->m_pIBO);
			GraphicCore::GlesDevice::GetInstance().Draw(GraphicCore::DM_TRIANGLE_LIST,0,-1);
		}
	}


}