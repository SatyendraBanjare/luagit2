#ifndef _lua_describe_h
#define _lua_describe_h

#include "../common/lua_common.h"

int lua_git_describe_commit (lua_State *L);
int lua_git_describe_workdir (lua_State *L);
int lua_git_describe_format(lua_State *L);
int lua_git_describe_result_free(lua_State *L);

#endif
