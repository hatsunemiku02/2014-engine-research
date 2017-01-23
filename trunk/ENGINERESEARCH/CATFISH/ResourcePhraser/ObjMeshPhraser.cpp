/****************************************************************************************************

v ��ʾ����ָ��һ�����㡣 ǰ׺�����3�������ȸ��������ֱ��ʾ�ö����X��Y��Z����ֵ

vt ��ʾ����ָ��һ���������ꡣ��ǰ׺��������������ȸ��������ֱ��ʾ�����������U��Vֵ

vn ��ʾ����ָ��һ��������������ǰ׺�����3�������ȸ��������ֱ��ʾ�÷�������X��Y��Z����ֵ

f ��ʾ����ָ��һ������(Face)��һ������ʵ���Ͼ���һ��������ͼԪ����ǰ׺�еĲ�����ʽ���潫��ϸ���ܡ�

usemtl ��ǰ׺��ֻ����һ���������ò���ָ���˴Ӵ���֮����һ����usemtl��ͷ����֮������б�����ʹ�õĲ������ơ��ò��ʿ����ڴ�OBJ�ļ���������MTL�ļ����ҵ�������Ϣ��

mtllib ��ǰ׺��ֻ����һ���������ò���ָ���˴�OBJ�ļ���ʹ�õĲ��ʿ��ļ�(*.mtl)���ļ�·��


f  1  2  3 �������б�ʾ�Ե�1��2��3�Ŷ������һ�������Ρ�

f  1/3  2/5  3/4 �������б�ʾ�Ե�1��2��3�Ŷ������һ�������Σ����е�һ��������������������ֵΪ3���ڶ���������������������ֵΪ5��������������������������ֵΪ4��

f  1/3/4  2/5/6  3/4/2 �������б�ʾ�Ե�1��2��3�Ŷ������һ�������Σ����е�һ��������������������ֵΪ3���䷨�ߵ�����ֵ��4���ڶ���������������������ֵΪ5���䷨�ߵ�����ֵ��6��������������������������ֵΪ6���䷨�ߵ�����ֵ��2��

f  1//4  2//6  3//2�������б�ʾ�Ե�1��2��3�Ŷ������һ�������Σ��Һ����������ꡣ���е�һ������ķ��ߵ�����ֵ��4���ڶ�������ķ��ߵ�����ֵ��6������������ķ��ߵ�����ֵ��2��





���õ���Obj�ļ����������£�

# Max2Obj Version 4.0 Mar 10th, 2001
#
# object Line01 to come ...
#

v  -9.574153 -2.220963 -2.000000
v  -7.893424 -2.280989 -2.000000
...ʡ��������ͬ��ʽ����
v  -7.195892 -1.380599 -0.980160
v  -9.580536 -1.320573 -1.967912
# 160 vertices

vn  -0.071382 -1.998675 0.014198
vn  -0.035691 -0.999338 0.007099
...ͬ��ʡ��������ͬ��ʽ����
vn  -0.825224 1.736366 -0.551397
vn  0.039418 1.999438 0.026341

# 160 vertex normals
g Line01

s 1
f 1//1 12//12 2//2
f 1//1 11//11 12//12
s 4
f 2//2 13//13 3//3
f 2//2 12//12 13//13
...ͬ����ʡ��������ͬ��ʽ����
s 4
f 160//160 1//1 151//151
f 160//160 10//10 1//1

# 320 faces

*****************************************************************************************************/

#include "ObjMeshPhraser.h"
#include "PrimitiveGroup.h"
#include "IndexBufferObj.h"
#include "VertexBufferObj.h"
#include <vector>


namespace ResPha
{
	
	ObjMeshPhraser::~ObjMeshPhraser()
	{

	}

	ObjMeshPhraser::ObjMeshPhraser()
	{

	}

	GraphicCore::PrimitiveGroup* ObjMeshPhraser::Phrase( void* buffer,unsigned int size )
	{
        return NULL;
	}


	GraphicCore::PrimitiveGroup* ObjMeshPhraser::Phrase(float* vertexbuffer,unsigned int vsize,unsigned short* indexBuffer,unsigned int isize,GraphicCore::VertexLayout& layout)
	{
		GraphicCore::GLVertexBufferObj*	_pVbo = GraphicCore::GLVertexBufferObj::CreateVertexBuffer(vertexbuffer,vsize,sizeof(float),layout);
		GraphicCore::GLIndexBufferObj*	_pIbo = GraphicCore::GLIndexBufferObj::CreateIndexBuffer(indexBuffer,isize,sizeof(unsigned short));
			
		std::vector<GraphicCore::GLVertexBufferObj*> vecVbo;
		vecVbo.push_back(_pVbo);
		std::vector<GraphicCore::GLIndexBufferObj*> vecIbo;
		vecIbo.push_back(_pIbo);

		GraphicCore::PrimitiveGroup* pPGroup =	GraphicCore::PrimitiveGroup::CreatePrimitiveGroup(vecVbo,vecIbo);
		return pPGroup;
	}
}