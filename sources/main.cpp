#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include "context.hpp"
#include "luafunc.hpp"

int main(int argc, char **argv)
{
	lua_State *lua = luaL_newstate();
    luaopen_base(lua);

	lua_pushcfunction(lua, fn_one);
	lua_setglobal(lua, "one");
	lua_pushcfunction(lua, fn_two);
	lua_setglobal(lua, "two");
	lua_pushcfunction(lua, fn_three);
	lua_setglobal(lua, "three");
    
    Context *context = new Context();
    context->fp = fopen("output.txt", "a");
    
    lua_pushlightuserdata(lua, context);
    lua_setglobal(lua, "context");
    
    int res = luaL_loadfile(lua, "main.lua");
    
    res = lua_pcall(lua, 0, 0, 0);
    
    if (res != 0) {
        const char* err = lua_tostring(lua, -1);
        printf("Lua error: %s", err);
    }

    lua_getglobal(lua, "main");
    
    if (lua_pcall(lua, 0, 0, 0))
    {
        const char* err = lua_tostring(lua, -1);
        printf("Lua error: %s", err);
    }
    
    lua_close(lua);
    fclose(context->fp);
    delete context;

    return 0;
}
