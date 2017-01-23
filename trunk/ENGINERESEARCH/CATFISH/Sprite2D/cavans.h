//
//  cavans.h
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__cavans__
#define __Catfish__cavans__
#include "../Math/cmlmath.h"
namespace Sprite
{
    class Cavans
	{
	public:
        static Cavans& GetInstance()
        {
            static Cavans instance;
            return instance;
        }
        ~Cavans()
        {
            
        }
        
        
        void SetSize(int width,int height)
        {
            m_CavanceSize[0] = width;
            m_CavanceSize[1] = height;
        }
        
        const Math::vector2i& GetCavansSize() const
        {
            return m_CavanceSize;
        }
	protected:
        Cavans()
        {
            
        }
        Math::vector2i m_CavanceSize;
        
     
	private:
      
	};
}

#endif /* defined(__Catfish__cavans__) */
