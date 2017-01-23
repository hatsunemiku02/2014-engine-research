#include "ResMgr.h"
#include "ImagePhaser.h"
#include "ShaderRes.h"
#include "MeshRes.h"
namespace Resource
{


	ResMgr::~ResMgr()
	{

	}

	ResMgr::ResMgr()
	{

	}

	void ResMgr::InitPhasers()
	{
		ResPha::ImagePhraser::GetInstance().Init();
	}

	void ResMgr::DestoryPhasers()
	{
		ResPha::ImagePhraser::GetInstance().Destory();
	}
    
    void ResMgr::SetBaseDic(const char* basePath)
    {
        m_strBasePath = basePath;
    }

    const std::string& ResMgr::GetBaseDic()
    {
        return m_strBasePath;
    }
    
	void ResMgr::InitDefaultResource()
	{

		{
			std::string allpath = m_strBasePath+std::string(Default3DShader);
			GpuProgramRes* pGpuProgram = new GpuProgramRes();
			pGpuProgram->LoadDefault3D();
			int hash = BKDRHash(const_cast<char*>(allpath.c_str()));
			m_ResMap.insert(std::make_pair(hash,(Res*)pGpuProgram));
		}
		/*
		{
			std::string allpath = m_strBasePath+std::string(Sprite2DShader);
			GpuProgramRes* pGpuProgram = new GpuProgramRes();
			pGpuProgram->LoadDefault2D();
			int hash = BKDRHash(const_cast<char*>(allpath.c_str()));
			m_ResMap.insert(std::make_pair(hash,(Res*)pGpuProgram));
		}
        
        {
            std::string allpath = m_strBasePath+std::string(FontShader);
		    GpuProgramRes* pGpuProgram = new GpuProgramRes();
		    pGpuProgram->LoadDefaultFont();
		    int hash = BKDRHash(const_cast<char*>(allpath.c_str()));
		    m_ResMap.insert(std::make_pair(hash,(Res*)pGpuProgram));
            
        }

		*/
        {
            std::string allpath = m_strBasePath+std::string(DefaultRect);
		    MeshRes* pRect = new MeshRes();
		    pRect->LoadDefaultRect();
		    int hash = BKDRHash(const_cast<char*>(allpath.c_str()));
		    m_ResMap.insert(std::make_pair(hash,(Res*)pRect));
        }
	}

}