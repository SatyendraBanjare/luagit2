#ifndef _lua_index_help_h
#define _lua_index_help_h

#include "../common/lua_common.h"

int lua_git_index_entry_get_path(lua_State *L);
int lua_git_index_entry_get_filemode(lua_State *L);
int lua_git_index_entry_get_filesize(lua_State *L);
int lua_git_index_entry_get_stage(lua_State *L);
int lua_git_index_entry_get_oid_str(lua_State *L);
int lua_git_index_entry_get_dev_inode(lua_State *L);
int lua_git_index_entry_get_UID_GID(lua_State *L);

#endif
