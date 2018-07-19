#ifndef _lua_checkout_h
#define _lua_checkout_h

#include "../common/lua_common.h"

int lua_git_checkout_init_options (lua_State *L);
int lua_git_checkout_head (lua_State *L);
int lua_git_checkout_index (lua_State *L);
int lua_git_checkout_tree (lua_State *L);

#endif
