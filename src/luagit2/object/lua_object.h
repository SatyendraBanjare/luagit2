#ifndef _lua_object_h
#define _lua_object_h

#include "../common/lua_common.h"

int lua_git_object__size(lua_State *L);
int lua_git_object_free(lua_State *L);
int lua_git_object_id(lua_State *L);
int lua_git_object_lookup(lua_State *L);
int lua_git_object_lookup_bypath(lua_State *L);
int lua_git_object_lookup_prefix(lua_State *L);
int lua_git_object_owner(lua_State *L);
int lua_git_object_short_id (lua_State *L);
int lua_git_object_string2type(lua_State *L);
int lua_git_object_type(lua_State *L);
int lua_git_object_type2string(lua_State *L);
int lua_git_object_typeisloose(lua_State *L);

#endif
