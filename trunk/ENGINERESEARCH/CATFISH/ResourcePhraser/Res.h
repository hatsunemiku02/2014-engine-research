#ifndef RES_H_
#define RES_H_
#include "RDllCommon.h"
#include <string>
namespace Resource
{
	class ResMgr;
	class RES_API Res
	{
	public:
		Res();
		~Res();
		virtual bool Load(const std::string& path);
	protected:
		std::string m_Path;
		friend class ResMgr;
	};
}
#endif 