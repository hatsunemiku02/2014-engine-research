#include "VertexLayout.h"
namespace GraphicCore
{
	VertexLayout::VertexLayout()
		:m_Stride(0)
		,m_Layout()
	{

	}

	VertexLayout::~VertexLayout()
	{

	}


	void VertexLayout::BuildLayout(const std::map<int,Ele>& layout)
	{
		IFERROR(layout.find(0)==layout.end());
		m_Layout = layout;
		std::map<int,Ele>::iterator itr = m_Layout.begin();
		for(;itr!=m_Layout.end();itr++)
		{
			m_Stride+=itr->second.size*itr->second.unitSize;
		}
	}
}
