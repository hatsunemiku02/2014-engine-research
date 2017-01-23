#ifndef SCRIPTSYS_H_
#define SCRIPTSYS_H_


#include "LuaRootScript.h"
#include "ScriptDefines.h"
#include "SDLLCommon.h"
namespace Script
{
	class SCRIPT_API ScriptSys
	{
	public:
		static ScriptSys&  Instance()
		{
			static ScriptSys instance;
			return instance;
		}
		~ScriptSys();
		bool Setup();

		bool OnLoad();
	protected:

		LuaRootScript* m_pRootScript;

	private:
		ScriptSys();
	};
}

#endif