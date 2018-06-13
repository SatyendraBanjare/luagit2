#ifndef _lua_libgit_help
#define _lua_libgit_help

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

int lua_git_libgit2_print_version_data (lua_State *L);

#endif
