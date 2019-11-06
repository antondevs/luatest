#include "luafunc.hpp"

int fn_one(lua_State *lua) 
{
    Context **userInfo = (Context**)lua_touserdata(lua,lua_upvalueindex( 1 ));
    
    assert(lua_type(lua, 1) == LUA_TUSERDATA);
    Context *context = (Context *) lua_touserdata(lua, 1);
    
    double arg1 = luaL_checknumber (lua, 2);
    double arg2 = luaL_checknumber (lua, 3);

	return 0;
}

int fn_two(lua_State *lua) 
{
    assert(lua_type(lua, 1) == LUA_TUSERDATA);
    Context *context = (Context *) lua_touserdata(lua, 1);
    
    double arg1 = luaL_checknumber (lua, 2);
    double arg2 = luaL_checknumber (lua, 3);

	return 0;
}

int fn_three(lua_State *lua) 
{
    assert(lua_type(lua, 1) == LUA_TUSERDATA);
    Context *context = (Context *) lua_touserdata(lua, 1);
    
    double arg1 = luaL_checknumber (lua, 2);
    double arg2 = luaL_checknumber (lua, 3);

	return 0;
}
