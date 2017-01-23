
#include "FrameBufferObj.h"
#include "VertexBufferObj.h"
#include "IndexBufferObj.h"
#include "GpuProgram.h"
#include "Texture.h"
#include "OpenglHeader.h"
#if __ANDROID__
#include <android/log.h>
#endif
#include "GlesDevice.h"
namespace GraphicCore
{


	GlesDevice::GlesDevice()
		:m_MaxVertexAttribs(-1)
		,m_MaxTextureUnits(-1)
		,m_ActivedTexUnit(TU_NONE)
		,m_pCurrentVBO(0)
		,m_pCurrentIBO(0)
		,m_pCurrentGPG(0)
	{
        for(int i=0;i<8;i++)
        {
            m_pBindedTexture[i] = 0;
        }
       
	}

	GlesDevice::~GlesDevice()
	{

	}

	void GlesDevice::GetExtentions()
	{

	}

	void GlesDevice::SetPixelUnpackAlignment( int align )
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, align);
		CHECKGLERROR;
	}

	bool GlesDevice::ActiveTextureUnit( TextureUnit unit )
	{
		if (m_ActivedTexUnit > GetMaxTextureUnit())
		{
			return false;
		}
		else if(m_ActivedTexUnit == unit)
		{
			return true;
		}
		m_ActivedTexUnit = unit;
		glActiveTexture(ToGLESTextureUnit(m_ActivedTexUnit));
        CHECKGLERROR;
		return true;
	}

	void GlesDevice::BindTexture( TextureType type,GLTexture* tex )
	{
		if(m_pBindedTexture[m_ActivedTexUnit]&&tex&&m_pBindedTexture[m_ActivedTexUnit]->m_Texture==tex->m_Texture)
		{
			return;
		}
		m_pBindedTexture[m_ActivedTexUnit] = tex;
        if (m_pBindedTexture[m_ActivedTexUnit]==NULL)
        {
            glBindTexture(ToGLESTextureType(type),0);
        }
        else
        {
            glBindTexture(ToGLESTextureType(type),m_pBindedTexture[m_ActivedTexUnit]->m_Texture);
        }
        CHECKGLERROR;
	}

	void GlesDevice::BindFrameBuffer( FrameBufferObj* pFbo )
	{
		if (pFbo != m_pFrameBufferObj)
		{
			m_pFrameBufferObj = pFbo;
			glBindFramebuffer(GL_FRAMEBUFFER, m_pFrameBufferObj->m_FrameBuf);
			
			CHECKGLERROR;
		}
	}

	void GlesDevice::SetCurrentVBO( GLVertexBufferObj* vbo )
	{
        
		if(m_pCurrentVBO&&vbo&&vbo->m_VBO==m_pCurrentVBO->m_VBO)
		{
			return;
		}
		m_pCurrentVBO = vbo;
        if(m_pCurrentVBO==NULL)
        {
            glBindBuffer(GL_ARRAY_BUFFER,0);
        }
        else
        {
            glBindBuffer(GL_ARRAY_BUFFER,m_pCurrentVBO->m_VBO);
        }
		CHECKGLERROR;
	}


	void GlesDevice::SetCurrentIBO(  GLIndexBufferObj* ibo )
	{
		if(m_pCurrentIBO&&ibo&&ibo->m_IBO==m_pCurrentIBO->m_IBO)
		{
			return;
		}
		m_pCurrentIBO = ibo;
        if(m_pCurrentIBO==NULL)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        }
        else
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_pCurrentIBO->m_IBO);
        }
		CHECKGLERROR;

	}


	void GlesDevice::SetCurrentGPG( GpuProgram* gpg )
	{
		if(m_pCurrentGPG&&gpg&&gpg->m_GpuProgram==m_pCurrentGPG->m_GpuProgram)
		{
			return;
		}
		m_pCurrentGPG = gpg;
        if(m_pCurrentGPG==NULL)
        {
            glUseProgram(0);
        }
        else
        {
            glUseProgram(m_pCurrentGPG->m_GpuProgram);
        }
		
		CHECKGLERROR;
	}

	void GlesDevice::Draw( DrawMode mode ,int start,int num )
	{
		BeforeDraw();
		DrawCurrent(mode,start,num);
		AfterDraw();
	}


	void GlesDevice::BindCurrentAttLayout()
	{
		IFERROR(m_pCurrentGPG==NULL);
		IFERROR(m_pCurrentVBO==NULL);
	
		std::map<std::string,GpuProgram::AttributeParam>::iterator itr;
		void* pVertex = NULL;
		unsigned int offset = 0;
		for(itr = m_pCurrentGPG->m_AttMap.begin();itr!=m_pCurrentGPG->m_AttMap.end();itr++)
		{
			glEnableVertexAttribArray(itr->second.loc);
			CHECKGLERROR;
			std::map<int,VertexLayout::Ele>::iterator layoutItr;
			layoutItr = m_pCurrentVBO->m_VertexLayout.m_Layout.find(itr->second.loc);
			pVertex = (char *)NULL +  layoutItr->second.offset;
			glVertexAttribPointer(itr->second.loc, layoutItr->second.size, GL_FLOAT, GL_FALSE, m_pCurrentVBO->m_VertexLayout.m_Stride, pVertex);
			CHECKGLERROR;
		}
	}

	void GlesDevice::UnBindCurrentAttLayout()
	{
		IFERROR(m_pCurrentGPG==NULL);
		IFERROR(m_pCurrentVBO==NULL);
		std::map<std::string,GpuProgram::AttributeParam>::iterator itr;
		for(itr = m_pCurrentGPG->m_AttMap.begin();itr!=m_pCurrentGPG->m_AttMap.end();itr++)
		{
			glDisableVertexAttribArray(itr->second.loc);
			CHECKGLERROR;
		}
		m_pCurrentGPG = NULL;
		m_pCurrentVBO = NULL;
	}

    
    void GlesDevice::EnableState(CTRenderState rs)
    {
        glEnable(ToGLESRenderState(rs));
        CHECKGLERROR;
    }
    
    void GlesDevice::DisableState(CTRenderState rs)
    {
        glDisable(ToGLESRenderState(rs));
        CHECKGLERROR;
    }
    
	void GlesDevice::SetBlendFun(CTBlendFun bf)
    {
        if(m_BlendFoo!=bf)
        {
            m_BlendFoo = bf;
            glBlendEquation(ToGLESBlendFun(m_BlendFoo));
            CHECKGLERROR;
        }

    }
    
    void GlesDevice::SetBlendState(CTBlendStateSrc bss,CTBlendStateDst bsd)
    {
        if(m_SrcBlendState!=bss||m_DstBlendState!=bsd)
        {
            m_SrcBlendState = bss;
            m_DstBlendState = bsd;
            glBlendFunc(ToGLESSrcBlendState(m_SrcBlendState), ToGLESDstBlendState(m_DstBlendState));
        }
       
    }
    
	void GlesDevice::BeforeDraw()
	{
		IFERROR(m_pCurrentGPG==NULL);
		IFERROR(m_pCurrentVBO==NULL);
		BindCurrentAttLayout();
	}


	void GlesDevice::DrawCurrent( DrawMode mode ,int start,int num )
	{

		if(m_pCurrentIBO)
		{
			DrawIndexed(mode,start,num);
		}
		else
		{
			DrawUnindexed(mode,start,num);
		}
	}

	void GlesDevice::AfterDraw()
	{
		UnBindCurrentAttLayout();
		CHECKGLERROR;
		if(m_pCurrentIBO)
		{
			CHECKGLERROR;
			m_pCurrentIBO = NULL;
		}
	}

	void GlesDevice::DrawIndexed( DrawMode mode ,int start,int num )
	{
		IFERROR(m_pCurrentIBO==NULL);
		int drawnum = -1==num?m_pCurrentIBO->m_IndexNum:num;
		glDrawElements(mode,drawnum ,GL_UNSIGNED_SHORT,(char*)NULL+start );
		CHECKGLERROR;
	}

	void GlesDevice::DrawUnindexed( DrawMode mode ,int start,int num )
	{
		int numperVertex = m_pCurrentVBO->m_VertexLayout.m_Layout.find(0)->second.size;

		int drawnum = -1==num?m_pCurrentVBO->m_VertexNum/numperVertex:num;
		glDrawArrays(mode, start, drawnum);
	}

	void GlesDevice::Clean()
	{
		glClearColor(0.3f,0.8f,0.8f,1.0f);
		CHECKGLERROR;
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		CHECKGLERROR;
	}

	int GlesDevice::GetMaxTextureUnit()
	{
		if(m_MaxTextureUnits==-1)
		{
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &m_MaxTextureUnits);

		}
		return m_MaxTextureUnits;
	}

	int GlesDevice::GetMaxVertexAtt()
	{
		if(m_MaxVertexAttribs==-1)
		{
			glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &m_MaxVertexAttribs);

		}
		return m_MaxVertexAttribs;
	}

	void GlesDevice::SetViewPort( int left,int top,int width,int height )
	{
		glViewport(left,top,width,height);
	}

	std::string GlesDevice::GetDeviceName()
	{
#if __GL__
		return "opengl";
#elif
		return "glse";
#endif
	}


}

