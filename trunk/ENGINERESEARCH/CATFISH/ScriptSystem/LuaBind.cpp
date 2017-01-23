//
//  LuaBind.cpp
//  Catfish
//
//  Created by zhaohang on 14-7-7.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "LuaBind.h"
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
}

namespace FooScriptBind
{
    static int add(lua_State* L)
    {
        double OP1 = luaL_checknumber(L,1);
        double OP2 = luaL_checknumber(L,2);
        
        
        lua_pushnumber(L,OP1+OP2);
        
        return 1;
    }
    
    
    
    
    
    
    
    static void RegistFoos(lua_State* L)
    {
        lua_register(L,"add",add);
    }
}