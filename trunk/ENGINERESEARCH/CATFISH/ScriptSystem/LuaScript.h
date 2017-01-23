#ifndef LUASCRIPT_H_
#define LUASCRIPT_H_

struct lua_State;
namespace Script
{
	 class LuaScript
	 {
	 public:
		LuaScript();
		~LuaScript();

		bool LoadScriptFromDisk(const char* sname);
		bool LoadScriptFromStr(const char* scontent);

		template<typename T>
		T CallMethod(const char* csmethodid,void** prarms);
	 protected:
		lua_State * m_pState;
	 private:
	 };

    
    
    
// 	 template<typename T>
// 	 T LuaScript::CallMethod<T>( const char* csmethodid,int paramLength,void** params, )
// 	 {
// 		 lua_getglobal(l,csmethodid); 
// 		 for(int i=0;i<paramLength;i++)
// 		 {
// 
// 		 }
// 		 // int a = 11 ;
// 		 // int b = 12 ;
// 		 // lua_getglobal(l,"sum");               //调用lua中的函数sum
// 		 // lua_pushinteger(l,a) ;
// 		 // lua_pushinteger(l,b) ;
// 		 // ret = lua_pcall(l,2,1,0) ;
// 	 }
}
#endif