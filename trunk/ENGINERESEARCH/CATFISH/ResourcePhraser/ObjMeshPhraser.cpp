/****************************************************************************************************

v 表示本行指定一个顶点。 前缀后跟着3个单精度浮点数，分别表示该定点的X、Y、Z坐标值

vt 表示本行指定一个纹理坐标。此前缀后跟着两个单精度浮点数。分别表示此纹理坐标的U、V值

vn 表示本行指定一个法线向量。此前缀后跟着3个单精度浮点数，分别表示该法向量的X、Y、Z坐标值

f 表示本行指定一个表面(Face)。一个表面实际上就是一个三角形图元。此前缀行的参数格式后面将详细介绍。

usemtl 此前缀后只跟着一个参数。该参数指定了从此行之后到下一个以usemtl开头的行之间的所有表面所使用的材质名称。该材质可以在此OBJ文件所附属的MTL文件中找到具体信息。

mtllib 此前缀后只跟着一个参数。该参数指定了此OBJ文件所使用的材质库文件(*.mtl)的文件路径


f  1  2  3 这样的行表示以第1、2、3号顶点组成一个三角形。

f  1/3  2/5  3/4 这样的行表示以第1、2、3号顶点组成一个三角形，其中第一个顶点的纹理坐标的索引值为3，第二个顶点的纹理坐标的索引值为5，第三个顶点的纹理坐标的索引值为4。

f  1/3/4  2/5/6  3/4/2 这样的行表示以第1、2、3号顶点组成一个三角形，其中第一个顶点的纹理坐标的索引值为3，其法线的索引值是4；第二个顶点的纹理坐标的索引值为5，其法线的索引值是6；第三个顶点的纹理坐标的索引值为6，其法线的索引值是2。

f  1//4  2//6  3//2这样的行表示以第1、2、3号顶点组成一个三角形，且忽略纹理坐标。其中第一个顶点的法线的索引值是4；第二个顶点的法线的索引值是6；第三个顶点的法线的索引值是2。





我拿到的Obj文件，内容如下：

# Max2Obj Version 4.0 Mar 10th, 2001
#
# object Line01 to come ...
#

v  -9.574153 -2.220963 -2.000000
v  -7.893424 -2.280989 -2.000000
...省略若干相同格式的行
v  -7.195892 -1.380599 -0.980160
v  -9.580536 -1.320573 -1.967912
# 160 vertices

vn  -0.071382 -1.998675 0.014198
vn  -0.035691 -0.999338 0.007099
...同样省略若干相同格式的行
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
...同样的省略若干相同格式的行
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