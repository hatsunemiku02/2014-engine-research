//
//  CullerQuad.cpp
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "CullerQuadTree.h"
#include "RenderUnit.h"
#include "Frustum.h"

namespace GraphicSys
{
	void CullerQuadTree::SetTreeContent( Math::QuatTree<NodeContent>::Node* pNode )
	{
		if(pNode->GetChild(0)==0)
		{
			return;
		}
		Math::BoxAABB box = pNode->GetContent().m_Box;

		Math::BoxAABB boxc[4];
		vector3f center[4];
		vector3f size;
		size[0] = box.GetSize()[0]/2;
		size[1] = box.GetSize()[1];
		size[2] = box.GetSize()[2]/2;

		center[0][0] = (box.GetCenter()[0]+box.GetSize()[0])/2;
		center[0][1] = box.GetCenter()[1];
		center[0][2] = (box.GetCenter()[2]+box.GetSize()[2])/2;

		center[1][0] = (box.GetCenter()[0]-box.GetSize()[0])/2;
		center[1][1] = box.GetCenter()[1];
		center[1][2] = (box.GetCenter()[2]+box.GetSize()[2])/2;

		center[2][0] = (box.GetCenter()[0]+box.GetSize()[0])/2;
		center[2][1] = box.GetCenter()[1];
		center[2][2] = (box.GetCenter()[2]-box.GetSize()[2])/2;

		center[3][0] = (box.GetCenter()[0]-box.GetSize()[0])/2;
		center[3][1] = box.GetCenter()[1];
		center[3][2] = (box.GetCenter()[2]-box.GetSize()[2])/2;

		for(int i=0;i<4;i++)
		{
			boxc[i].Set(size,center[i]);
			NodeContent content;
			content.m_Box = boxc[i];
			pNode->GetChild(i)->SetContent(content);
			SetTreeContent(pNode->GetChild(i));
		}
	}

	void CullerQuadTree::InitQuatTree( const Math::BoxAABB& rootbox,int depth )
	{
		m_Tree.InitQuatTree(depth);
		Math::QuatTree<NodeContent>::Node*  root = m_Tree.GetRoot();
		NodeContent content;
		content.m_Box = rootbox;
		root->SetContent(content);
		SetTreeContent(root);
	}

	void CullerQuadTree::AddRenderUnit( const RenderUnit* pRenderUnit )
	{
		Math::QuatTree<NodeContent>::Node* pNode = GetFixNode(m_Tree.GetRoot(),pRenderUnit->GetBBox());
		if(pNode==0)
		{
			pNode = m_Tree.GetRoot();
		}
		pNode->GetContent().m_pRenderUnits.push_back((RenderUnit* )pRenderUnit);
	}


	void CullerQuadTree::RemoveRenderUnit( const RenderUnit* unit )
	{

	}


	void CullerQuadTree::Cull( void* pararm,std::multimap<unsigned int,RenderUnit*>& outUnits )
	{
		Math::Frustum* pFrustum = (Math::Frustum*)pararm;
		Cull(pFrustum,m_Tree.GetRoot(),outUnits);
	}

	void CullerQuadTree::Cull(Math::Frustum* pararm,Math::QuatTree<NodeContent>::Node* pNode,std::multimap<unsigned int,RenderUnit*>& outUnits )
	{
		Math::ClipStatus ret = pararm->InterSectAABB(pNode->GetContent().m_Box);
		if(ret==Math::OUT)
		{
			return ;
		}
		else if(ret==Math::CONTAIN)
		{
			AddAllUnits(pNode,outUnits);
		}
		else if(ret==Math::CLIP)
		{
			for(std::list<RenderUnit*>::iterator itr= pNode->GetContent().m_pRenderUnits.begin();itr!=pNode->GetContent().m_pRenderUnits.end();itr++)
			{
				if(pararm->InterSectAABB((*itr)->GetBBox())!=Math::OUT)
				{
					outUnits.insert(std::make_pair(1,*itr));
				}	
			}
			if(pNode->GetChild(0)==NULL)
			{
				return ;
			}
			for(int i=0;i<4;i++)
			{
				Cull(pararm,pNode->GetChild(i),outUnits);
			}
		}
	}



	void CullerQuadTree::AddAllUnits( Math::QuatTree<NodeContent>::Node* pNode,std::multimap<unsigned int,RenderUnit*>& outUnits )
	{
		for(std::list<RenderUnit*>::iterator itr= pNode->GetContent().m_pRenderUnits.begin();itr!=pNode->GetContent().m_pRenderUnits.end();itr++)
		{
			outUnits.insert(std::make_pair(1,*itr));
		}
		if(pNode->GetChild(0)==0)
		{
			return ;
		}
		for(int i =0;i<4;i++)
		{
			AddAllUnits(pNode->GetChild(i),outUnits);
		}
	}


	Math::QuatTree<NodeContent>::Node* CullerQuadTree::GetFixNode(Math::QuatTree<NodeContent>::Node* pNode,const Math::BoxAABB& box )
	{
		Math::ClipStatus ret =  pNode->GetContent().m_Box.InterSect(box);
		std::list<int> outcount;

		Math::QuatTree<NodeContent>::Node* pRet = NULL;
		if(ret==Math::CONTAIN)
		{
			if(pNode->GetChild(0)==NULL)
			{
				return pNode;
			}	
			for (int i=0;i<4;i++)
			{
				Math::QuatTree<NodeContent>::Node* pChild = pNode->GetChild(i);
				if(pChild->GetContent().m_Box.InterSect(box)==Math::CONTAIN)
				{
					outcount.push_back(i);
				}
			}
			if(outcount.size()==0)
			{
				return pNode;
			}

			for (std::list<int>::iterator i= outcount.begin();i!=outcount.end();i++)
			{
				pRet = GetFixNode(pNode->GetChild(*i),box);
				if(pRet)
				{
					return pRet;
				}
			}
		}
		

		return pRet;
	}




}