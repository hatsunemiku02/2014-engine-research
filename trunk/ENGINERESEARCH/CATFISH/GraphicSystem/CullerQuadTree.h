//
//  CullerQuad.h
//  Catfish
//
//  Created by zhaohang on 14-3-31.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_CullerQuad_h
#define Catfish_CullerQuad_h
#include "Culler.h"
#include "BoxAABB.h"
#include "QuatTree.h"
#include <list>
namespace	Math
{
	class Frustum;
}
namespace GraphicSys
{
	class RenderUnit;

	struct NodeContent
	{
		NodeContent()
			:m_pRenderUnits(0)
			,m_Box()
		{

		}

		~NodeContent()
		{
			m_pRenderUnits.clear();
		}
		Math::BoxAABB m_Box;
		std::list<RenderUnit*> m_pRenderUnits;
	};


	class GRAPHIC_API CullerQuadTree:public Culler
	{
	public:
		CullerQuadTree()
			:m_Tree()
		{

		}
		~CullerQuadTree()
		{

		}

		void InitQuatTree(const Math::BoxAABB& rootbox,int depth);

		virtual void AddRenderUnit(const RenderUnit* unit) ;
		virtual void RemoveRenderUnit(const RenderUnit* unit) ;
		

		virtual void Cull( void* pararm,std::multimap<unsigned int,RenderUnit*>& outUnits);
	protected:
		void Cull( Math::Frustum* pararm,Math::QuatTree<NodeContent>::Node* pNode,std::multimap<unsigned int,RenderUnit*>& outUnits );
		void AddAllUnits(Math::QuatTree<NodeContent>::Node* pNode,std::multimap<unsigned int,RenderUnit*>& outUnits);
		void SetTreeContent(Math::QuatTree<NodeContent>::Node* pNode);
		Math::QuatTree<NodeContent>::Node* GetFixNode(Math::QuatTree<NodeContent>::Node* pNode,const Math::BoxAABB& box);
	protected:
		Math::QuatTree<NodeContent> m_Tree;

	
	};
}


#endif
