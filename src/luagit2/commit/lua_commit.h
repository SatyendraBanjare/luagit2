#ifndef _lua_commit_h
#define _lua_commit_h

#include "../common/lua_common.h"

int lua_git_commit_author (lua_State *L);
int lua_git_commit_body (lua_State *L);
int lua_git_commit_committer (lua_State *L);
int lua_git_commit_extract_signature (lua_State *L);
int lua_git_commit_header_field (lua_State *L);
int lua_git_commit_lookup (lua_State *L);
int lua_git_commit_lookup_prefix (lua_State *L);
int lua_git_commit_message (lua_State *L);
int lua_git_commit_message_encoding (lua_State *);
int lua_git_commit_message_raw (lua_State *L);
int lua_git_commit_nth_gen_ancestor (lua_State *L);
int lua_git_commit_parent (lua_State *L);
int lua_git_commit_parent_id (lua_State *L);
int lua_git_commit_parentcount (lua_State *L);
int lua_git_commit_raw_header (lua_State *L);
int lua_git_commit_summary (lua_State *L);
int lua_git_commit_time (lua_State *L);
int lua_git_commit_tree (lua_State *L);
int lua_git_commit_tree_id (lua_State *L);
int lua_git_commit_free (lua_State *L);
int lua_git_commit_id(lua_State *L);

int lua_git_commit_create_update_head (lua_State *L);
int lua_git_commit_create_update_none (lua_State *L);
int lua_git_commit_create_with_signature (lua_State *L);
int lua_git_commit_create_initial (lua_State *L);

#endif
