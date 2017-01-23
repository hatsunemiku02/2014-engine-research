//////////////////////////////////////////////////////////////////////////////////////
//
//						The Bohge Engine License (BEL)
//
//	Copyright (c) 2011-2014 Peng Zhao
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in 
//	all copies or substantial portions of the Software. And the logo of 
//	Bohge Engine shall be displayed full screen for more than 3 seconds 
//	when the software is started. Copyright holders are allowed to develop 
//	game edit based on Bohge Engine, The edit must be released under the MIT 
//	open source license if it is going to be published. In no event shall 
//	copyright holders be prohibited from using any code of Bohge Engine 
//	to develop any other analogous game engines.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//
//////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////
//	3DMath的拆分实现，请不要单独引用该头文件	//
//////////////////////////////////////////////
#ifndef VECTOR2
#define VECTOR2
#include "CommonMath.h"
namespace Math
{
	template<typename T>
	class vector2
	{
	public:
		typedef T value_type;
	public:
		union
		{
			struct	{ T	m_x, m_y; };
			struct	{ T	m_u, m_v; };
			T	data[2];
		};
	public:
		static vector2& Zero()
		{
			static vector2 zero(0,0);
			return zero;
		}
	public:
		inline vector2():m_x(0),m_y(0){}
		inline vector2(T u, T v):m_x(u),m_y(v){}
		inline vector2& operator= (const vector2& input)
		{
			data[0] = input.data[0];
			data[1] = input.data[1];
			return *this;
		}
		//vector2
		inline vector2& operator+= (const vector2& input)
		{
			m_x+=input.m_x;
			m_y+=input.m_y;
			return *this;
		}
		inline vector2& operator-= (const vector2& input)
		{
			m_x-=input.m_x;
			m_y-=input.m_y;
			return *this;
		}
		inline vector2& operator*= (const vector2& input)
		{
			m_x*=input.m_x;
			m_y*=input.m_y;
			return *this;
		}
		inline vector2& operator/= (const vector2& input)
		{
			m_x/=input.m_x;
			m_y/=input.m_y;
			return *this;
		}
		inline vector2 operator* (const vector2& input) const
		{
			return vector2( m_x*input.m_x , m_y*input.m_y );
		}
		inline vector2 operator+ (const vector2& input) const
		{
			return vector2( m_x+input.m_x , m_y+input.m_y );
		}
		inline vector2 operator- (const vector2& input) const
		{
			return vector2( m_x-input.m_x , m_y-input.m_y );
		}
		inline vector2 operator/ (const vector2& input) const
		{
			return vector2( m_x/input.m_x , m_y/input.m_y );
		}
		//矩阵
        /*		inline vector2& operator*= (const Matrix22<T>& m)
         {
         T x = m_x * m.a11 + m_y * m.a21;
         T y = m_x * m.a12 + m_y * m.a22;
         m_x = x;
         m_y = y;
         return *this;
         }
         inline vector2 operator* (const Matrix22<T>& m) const
         {
         return vector2( m_x * m.a11 + m_y * m.a21 , m_x * m.a12 + m_y * m.a22 );
         }
         */
		//取值
		inline T& operator[] ( int i )
		{
			return data[i];
		}
		inline vector2 operator- () const
		{
			return vector2( -m_x , -m_y );
		}
		//单个的数字
		inline vector2 operator/ (T num) const
		{
			return vector2( m_x/num , m_y/num );
		}
		friend inline vector2<T> operator* (T lhs, const vector2<T>& rhs )
		{
			return vector2( rhs.m_x*lhs , rhs.m_y*lhs );
		}
        friend inline vector2<T> operator* (const vector2<T>& rhs, T lhs )
		{
			return vector2( rhs.m_x*lhs , rhs.m_y*lhs );
		}
		inline vector2 operator- (T num) const
		{
			return vector2( m_x-num , m_y-num );
		}
		inline vector2 operator+ (T num) const
		{
			return vector2( m_x+num , m_y+num );
		}
		inline vector2& operator*= (T num)
		{
			m_x*=num;
			m_y*=num;
			return *this;
		}
		inline vector2& operator/= (T num)
		{
			m_x/=num;
			m_y/=num;
			return *this;
		}
		inline vector2& operator+= (T num)
		{
			m_x+=num;
			m_y+=num;
			return *this;
		}
		inline vector2& operator-= (T num)
		{
			m_x-=num;
			m_y-=num;
			return *this;
		}
		//逻辑
		inline bool operator == (const vector2& rhs) const
		{
			return Math::isEqual( m_x, rhs.m_x) & Math::isEqual( m_y, rhs.m_y );
		}
		inline bool operator != (const vector2& rhs) const
		{
			return !( *this == rhs );
		}
        // 		inline T Dot( const vector2& rhs ) const
        // 		{
        // 			return Math::Dot( *this, rhs );
        // 		}
        // 		inline vector2& NormalizeSelf()
        // 		{
        // 			Math::Normalize( *this, *this );
        // 			return *this;
        // 		}
        // 		inline vector2 Normalize()
        // 		{
        // 			vector2 temp;
        // 			Math::Normalize( *this, temp );
        // 			return temp;
        // 		}
		inline T Length() const
		{
			return Math::Sqrt( m_x*m_x + m_y*m_y );
		}
		inline T LengthPow() const
		{
			return m_x*m_x + m_y*m_y;
		}
	public:
		inline const T* GetVectorArray() const
		{
			return data;
		}
		static unsigned int Size()
		{
			return 2;
		}
		static unsigned int BitSize()
		{
			return 2 * sizeof(T);
		}
	};
}


#endif
#include "CommonMath.h"

