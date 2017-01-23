#ifndef _OBJMESHPHRASER_H_
#define _OBJMESHPHRASER_H_
#include "Res.h"
namespace GraphicCore
{
	class PrimitiveGroup;
    class VertexLayout;

}
namespace ResPha
{
	class RES_API ObjMeshPhraser
	{
	public:
		static ObjMeshPhraser& GetInstance()
		{
			static ObjMeshPhraser instance;
			return instance;
		}
		
		~ObjMeshPhraser();

		GraphicCore::PrimitiveGroup* Phrase(void* buffer,unsigned int size);

		GraphicCore::PrimitiveGroup* Phrase(float* vertexbuffer,unsigned int vsize,unsigned short* indexBuffer,unsigned int isize,GraphicCore::VertexLayout& layout);
	protected:
	private:
		ObjMeshPhraser();
	};
}
#endif