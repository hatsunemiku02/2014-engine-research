#include "LuaScript.h"
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}
namespace Script
{
	LuaScript::LuaScript()
	{

	}

	LuaScript::~LuaScript()
	{

	}

	bool LuaScript::LoadScriptFromDisk( const char* sname )
	{
		m_pState = luaL_newstate();
		if(m_pState==NULL)
		{
			return NULL;
		}

		int ret = 0;
		ret = luaL_loadfile(m_pState,sname);
		lua_pcall(m_pState, 0, 0, 0);
        return ret;
	}

	bool LuaScript::LoadScriptFromStr( const char* scontent )
	{
		m_pState = luaL_newstate();
		if(m_pState==NULL)
		{
			return NULL;
		}

		int ret = 0;
		ret = luaL_loadstring(m_pState,scontent);
		lua_pcall(m_pState, 0, 0, 0);
        return ret;
	}

}

