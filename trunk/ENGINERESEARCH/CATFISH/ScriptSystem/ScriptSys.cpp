
#include "ScriptSys.h"
// bool fooRet = false;
// 
// lua_State * l = luaL_newstate() ;        //����lua���л���
// 
// int ret = 0 ;
// ret = luaL_loadfile(l,"func.lua") ;      //����lua�ű��ļ�
// 
// ret = lua_pcall(l,0,0,0) ;
// 
// lua_getglobal(l,"width");              //��ȡlua�ж���ı���
// lua_getglobal(l,"height");
// printf("height:%ld width:%ld\n",lua_tointeger(l,-1),lua_tointeger(l,-2)) ;
// lua_pop(l,1) ;                        //�ָ�lua��ջ
// 
// int a = 11 ;
// int b = 12 ;
// lua_getglobal(l,"sum");               //����lua�еĺ���sum
// lua_pushinteger(l,a) ;
// lua_pushinteger(l,b) ;
// ret = lua_pcall(l,2,1,0) ;
// 
// printf("sum:%d + %d = %ld\n",a,b,lua_tointeger(l,-1)) ;
// lua_pop(l,1) ;
// 
// const char str1[] = "hello" ;
// const char str2[] = "world" ;
// lua_getglobal(l,"mystrcat");          //����lua�еĺ���mystrcat
// lua_pushstring(l,str1) ;
// lua_pushstring(l,str2) ;
// ret = lua_pcall(l,2,1,0) ;
// printf("mystrcat:%s%s = %s\n",str1,str2,lua_tostring(l,-1)) ;
// lua_pop(l,1) ;
// 
// lua_pushcfunction(l,csum) ;         //ע����lua��ʹ�õ�c����
// lua_setglobal(l,"csum") ;           //�󶨵�lua�е�����csum
// 
// lua_getglobal(l,"mysum");           //����lua�е�mysum�������ú������ñ������ж����csum����ʵ�ּӷ�
// lua_pushinteger(l,a) ;
// lua_pushinteger(l,b) ;
// ret = lua_pcall(l,2,1,0) ;
// 
// printf("mysum:%d + %d = %ld\n",a,b,lua_tointeger(l,-1)) ;
// lua_pop(l,1) ;
// 
// lua_close(l) ;                     //�ͷ�lua���л���
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
