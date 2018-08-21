#ifndef _lua_ignore_h
#define _lua_ignore_h

#include "../common/lua_common.h"

int lua_git_ignore_add_rule(lua_State *L);
int lua_git_ignore_clear_internal_rules(lua_State *L);
int lua_git_ignore_path_is_ignored(lua_State *L);

#endif
