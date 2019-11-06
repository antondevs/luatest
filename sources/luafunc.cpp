#include "luafunc.hpp"

int fn_one(lua_State *lua) 
{
    Context* context = (Context*)lua_touserdata(lua, 1);
    
    

	return 0;
}

int fn_two(lua_State *lua) 
{
    Context* context = (Context*)lua_touserdata(lua, 1);
    
    double arg1 = luaL_checknumber (lua, 2);
    double arg2 = luaL_checknumber (lua, 3);

	return 0;
}

int fn_three(lua_State *lua) 
{
    Context* context = (Context*)lua_touserdata(lua, 1);
    
    size_t size = 0;
    const char *string = luaL_checklstring(lua, 2, &size);

	return 0;
}
