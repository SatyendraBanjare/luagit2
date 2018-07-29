#ifndef _lua_revparse_h
#define _lua_revparse_h

#include "../common/lua_common.h"

int lua_git_revparse(lua_State *L);
int lua_git_revparse_single(lua_State *L);

#endif
