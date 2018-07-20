#ifndef _lua_hashsig_h
#define _lua_hashsig_h

#include "../common/lua_common.h"

int lua_git_hashsig_create_fromfile (lua_State *L);
int lua_git_hashsig_compare (lua_State *L);
int lua_git_hashsig_free (lua_State *L);

#endif
