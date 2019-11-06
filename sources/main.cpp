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
    
    Context* context = new Context();
    context->fp = fopen("output.txt", "a");
    Context **userInfoData = (Context **)lua_newuserdata(lua, sizeof(Context));
    *userInfoData = context;
    
    int iErr = luaL_loadfile(lua, "main.lua");
    
    iErr = lua_pcall(lua, 0, 0, 0);
    if (iErr != 0) {
        printf("Error code %i attempting to call function: '%s'\n", iErr, lua_tostring(lua, -1));
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
