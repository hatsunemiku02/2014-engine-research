#include "Res.h"
namespace Resource
{
	Res::Res()
	{

	}

	Res::~Res()
	{

	}

	bool Res::Load( const std::string& path )
	{
		m_Path = path;
        return false;
	}

}