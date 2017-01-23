#ifndef LUAROOTSCRIPT_H_
#define LUAROOTSCRIPT_H_
#include "LuaScript.h"
namespace Script
{
	class LuaRootScript:public LuaScript
	{
	public:
		LuaRootScript();
		~LuaRootScript();

		bool OnLoad();

	protected:
	private:
	};

}
#endif