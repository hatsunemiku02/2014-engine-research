#include "Sprite2DPipeLine.h"
#include "GlesDevice.h"
#include "Sprite2D.h"
#include "MeshRes.h"
#include "PrimitiveGroup.h"
#include "GpuProgram.h"
#include "ShaderRes.h"
#include "ImageRes.h"
#include <algorithm>

namespace PipeLine
{
    bool __sortcompare(Sprite::Sprite2D* i,Sprite::Sprite2D* j)
    {
        return i->GetLevel()<j->GetLevel();
    }
    

    
    Sprite2DPipeLine::~Sprite2DPipeLine()
    {
        
    }
    
	bool Sprite2DPipeLine::AddSprite( const Sprite::Sprite2D* sprite )
	{
        m_vecSprite2D.push_back(const_cast<Sprite::Sprite2D* >(sprite));
        m_bBeedSort = true;
        return true;
	}

    void Sprite2DPipeLine::RenderAll()
    {
        _sortAll();
        for (int i= 0; i<m_vecSprite2D.size(); i++) {
            m_vecSprite2D[i]->GetGpuProgramRes()->GetGpuProgram()->SetUniformValue("s_texture",m_vecSprite2D[i]->GetTextureRes()->GetTexture());
            
            m_vecSprite2D[i]->GetGpuProgramRes()->GetGpuProgram()->SetUniformValue("_pos",&(m_vecSprite2D[i]->GetPosition()));
            
            m_vecSprite2D[i]->GetGpuProgramRes()->GetGpuProgram()->SetUniformValue("_scale",&(m_vecSprite2D[i]->GetScale()));
            
            GraphicCore::GlesDevice::GetInstance().SetCurrentVBO(m_vecSprite2D[i]->GetMeshRes()->GetPrimitiveGroup()->GetVBO(0));
            GraphicCore::GlesDevice::GetInstance().SetCurrentIBO(m_vecSprite2D[i]->GetMeshRes()->GetPrimitiveGroup()->GetIBO(0));
            GraphicCore::GlesDevice::GetInstance().SetCurrentGPG(m_vecSprite2D[i]->GetGpuProgramRes()->GetGpuProgram());
            GraphicCore::GlesDevice::GetInstance().Draw(GraphicCore::DM_TRIANGLE_LIST,0,-1);
        }
     
    }
    
    void Sprite2DPipeLine::_sortAll()
    {
        if(!m_bBeedSort)
        {
            return;
        }
        std::sort(m_vecSprite2D.begin(), m_vecSprite2D.end(),__sortcompare);
    }

    
}