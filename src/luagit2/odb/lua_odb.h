#ifndef _lua_odb_h
#define _lua_odb_h

#include "../common/lua_common.h"

int lua_git_odb_exists(lua_State *L);
int lua_git_odb_free(lua_State *L);
int lua_git_odb_hash(lua_State *L);
int lua_git_odb_hashfile(lua_State *L);
int lua_git_odb_object_free(lua_State *L);
int lua_git_odb_object_id(lua_State *L);
int lua_git_odb_object_size(lua_State *L);
int lua_git_odb_object_type(lua_State *L);
int lua_git_odb_open(lua_State *L);
int lua_git_odb_read(lua_State *L);
int lua_git_odb_refresh(lua_State *L);
int lua_git_odb_write(lua_State *L);

#endif 