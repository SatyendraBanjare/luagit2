#ifndef _lua_index_h
#define _lua_index_h

#include "../common/lua_common.h"

int lua_git_index_add(lua_State *L);
int lua_git_index_add_bypath(lua_State *L);
int lua_git_index_caps(lua_State *L);
int lua_git_index_checksum(lua_State *L);
int lua_git_index_conflict_add(lua_State *L);
int lua_git_index_conflict_cleanup(lua_State *L);
int lua_git_index_entry_is_conflict(lua_State *L);
int lua_git_index_entry_stage(lua_State *L);
int lua_git_index_entrycount(lua_State *L);
int lua_git_index_find(lua_State *L);
int lua_git_index_find_prefix(lua_State *L);
int lua_git_index_get_byindex(lua_State *L);
int lua_git_index_get_bypath(lua_State *L);
int lua_git_index_has_conflicts(lua_State *L);
int lua_git_index_open(lua_State *L);
int lua_git_index_owner (lua_State *L);
int lua_git_index_path(lua_State *L);
int lua_git_index_read(lua_State *L);
int lua_git_index_read_tree(lua_State *L);
int lua_git_index_remove(lua_State *L);
int lua_git_index_remove_bypath(lua_State *L);
int lua_git_index_remove_directory(lua_State *L);
int lua_git_index_set_caps(lua_State *L);
int lua_git_index_set_version(lua_State *L);
int lua_git_index_version(lua_State *L);
int lua_git_index_write(lua_State *L);
int lua_git_index_write_tree(lua_State *L);
int lua_git_index_write_tree_to(lua_State *L);
int lua_git_index_free(lua_State *L);

#endif
