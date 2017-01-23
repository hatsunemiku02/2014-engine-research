
#include "ScriptSys.h"
// bool fooRet = false;
// 
// lua_State * l = luaL_newstate() ;        //创建lua运行环境
// 
// int ret = 0 ;
// ret = luaL_loadfile(l,"func.lua") ;      //加载lua脚本文件
// 
// ret = lua_pcall(l,0,0,0) ;
// 
// lua_getglobal(l,"width");              //获取lua中定义的变量
// lua_getglobal(l,"height");
// printf("height:%ld width:%ld\n",lua_tointeger(l,-1),lua_tointeger(l,-2)) ;
// lua_pop(l,1) ;                        //恢复lua的栈
// 
// int a = 11 ;
// int b = 12 ;
// lua_getglobal(l,"sum");               //调用lua中的函数sum
// lua_pushinteger(l,a) ;
// lua_pushinteger(l,b) ;
// ret = lua_pcall(l,2,1,0) ;
// 
// printf("sum:%d + %d = %ld\n",a,b,lua_tointeger(l,-1)) ;
// lua_pop(l,1) ;
// 
// const char str1[] = "hello" ;
// const char str2[] = "world" ;
// lua_getglobal(l,"mystrcat");          //调用lua中的函数mystrcat
// lua_pushstring(l,str1) ;
// lua_pushstring(l,str2) ;
// ret = lua_pcall(l,2,1,0) ;
// printf("mystrcat:%s%s = %s\n",str1,str2,lua_tostring(l,-1)) ;
// lua_pop(l,1) ;
// 
// lua_pushcfunction(l,csum) ;         //注册在lua中使用的c函数
// lua_setglobal(l,"csum") ;           //绑定到lua中的名字csum
// 
// lua_getglobal(l,"mysum");           //调用lua中的mysum函数，该函数调用本程序中定义的csum函数实现加法
// lua_pushinteger(l,a) ;
// lua_pushinteger(l,b) ;
// ret = lua_pcall(l,2,1,0) ;
// 
// printf("mysum:%d + %d = %ld\n",a,b,lua_tointeger(l,-1)) ;
// lua_pop(l,1) ;
// 
// lua_close(l) ;                     //释放lua运行环境
// return 0 ;
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}
const char* csRootScriptName = "sdcard/Media/Root.lua";
const char* csUserScriptName = "sdcard/Media/User.lua";
int csum(lua_State* l)
{
	int a = lua_tointeger(l,1) ;
	int b = lua_tointeger(l,2) ;
	lua_pushinteger(l,a+b) ;
	return 1 ;
}

namespace Script
{
	ScriptSys::ScriptSys()
	{

	}

	ScriptSys::~ScriptSys()
	{

	}

	bool ScriptSys::Setup()
	{
		m_pRootScript = new LuaRootScript();
		m_pRootScript->LoadScriptFromDisk(csRootScriptName);

		return true;
	}

	bool ScriptSys::OnLoad()
	{
		return m_pRootScript->OnLoad();
	}

}
