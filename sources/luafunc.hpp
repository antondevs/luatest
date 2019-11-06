#ifndef __LUAFUNC_H
#define __LUAFUNC_H

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <assert.h>
#include "context.hpp"

int fn_one(lua_State *lua);
int fn_two(lua_State *lua);
int fn_three(lua_State *lua); 

#endif
