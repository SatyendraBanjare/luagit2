#ifndef _lua_status_h
#define _lua_status_h

#include "../common/lua_common.h"

int lua_git_status_list_new(lua_State *L);
int lua_git_status_list_free (lua_State *L);
int lua_git_status_list_entrycount (lua_State *L);
int lua_git_status_byindex(lua_State *L);

#endif
