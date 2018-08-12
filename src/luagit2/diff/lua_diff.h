#ifndef _lua_diff_h
#define _lua_diff_h

#include "../common/lua_common.h"

int lua_git_diff_init_options (lua_State *L);
int lua_git_diff_get_stats (lua_State *L);
int lua_git_diff_index_to_index (lua_State *L);
int lua_git_diff_index_to_workdir (lua_State *L);
int lua_git_diff_is_sorted_icase (lua_State *L);
int lua_git_diff_merge (lua_State *L);
int lua_git_diff_num_deltas (lua_State *L);
int lua_git_diff_stats_deletions (lua_State *L);
int lua_git_diff_stats_files_changed (lua_State *L);
int lua_git_diff_stats_insertions (lua_State *L);
int lua_git_diff_stats_to_buf (lua_State *L);
int lua_git_diff_to_buf(lua_State *L);
int lua_git_diff_tree_to_index (lua_State *L);
int lua_git_diff_tree_to_tree (lua_State *L);
int lua_git_diff_tree_to_workdir (lua_State *L);
int lua_git_diff_tree_to_workdir_with_index (lua_State *L);


#endif
