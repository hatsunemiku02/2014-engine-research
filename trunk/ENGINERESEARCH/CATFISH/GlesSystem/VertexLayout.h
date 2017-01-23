#ifndef VERTEXLAYOUT_H_
#define VERTEXLAYOUT_H_
#include "GDllCommon.h"
#include "GDebug.h"
#include <map>
namespace GraphicCore
{
	/********************************************************************
	I decide to add a front to the shader's to give semetic to the 
	attributes,like:
	[
		verticesPos:Position
		verticesNor:Normal
		verticesTex:Texcoord0
	]
	like this, I can manully bind the atts to the loc I defined in file
	VertexBufferObj.h , so users don't need to care about the sequence of
	declearation 
	********************************************************************/
	class GlesDevice;
	class GLVertexBufferObj;
	class RENDERER_API VertexLayout
	{
	public:
		struct Ele
		{
			Ele(int l,int si,int us,int of)
				:loc(l)
				,size(si)
				,unitSize(us)
				,offset(of)
			{

			}
			int loc;
			int size;
			int unitSize;
			int offset;
		};
	public:
		VertexLayout();
		~VertexLayout();
		void BuildLayout(const std::map<int,Ele>& layout);
	protected:
		std::map<int,Ele> m_Layout;//k:locate v:size.
		int m_Stride;
		friend class GlesDevice;
		friend class GLVertexBufferObj;
	};


}

#endif