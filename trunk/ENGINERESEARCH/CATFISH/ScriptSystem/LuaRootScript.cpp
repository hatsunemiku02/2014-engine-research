#include "LuaRootScript.h"
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}
namespace Script
{
	LuaRootScript::LuaRootScript()
	{

	}

	LuaRootScript::~LuaRootScript()
	{

	}

	bool LuaRootScript::OnLoad()
	{
		lua_getglobal(m_pState,"OnLoad");
		int callret = lua_pcall(m_pState,0,1,0);

		bool ret = lua_toboolean(m_pState,-1);
		lua_pop(m_pState,1) ;
		return ret;
	}

}

