#ifndef LUADOMAIN_H_
#define LUADOMAIN_H_
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}
#include "LuaScript.h"
namespace Script
{
	class LuaDomain
	{
	public:
		LuaDomain(lua_State * pState);
		~LuaDomain();

		


	

	private:
	
	};



}

#endif