#ifndef _lua_repository_h
#define _lua_repository_h

#include "../common/lua_common.h"

int lua_git_repository_commondir(lua_State *L);
int lua_git_repository_config (lua_State *L);
int lua_git_repository_config_snapshot (lua_State *L);
int lua_git_repository_detach_head (lua_State *L);
int lua_git_repository_get_namespace(lua_State *L);
int lua_git_repository_head (lua_State *L);
int lua_git_repository_head_detached (lua_State *L);
int lua_git_repository_head_for_worktree (lua_State *L);
int lua_git_repository_head_unborn (lua_State *L);
int lua_git_repository_ident (lua_State *L);
int lua_git_repository_index(lua_State *L);
int lua_git_repository_init (lua_State *L);
int lua_git_repository_is_bare (lua_State *L);
int lua_git_repository_is_empty (lua_State *L);
int lua_git_repository_is_shallow (lua_State *L);
int lua_git_repository_is_worktree (lua_State *L);
int lua_git_repository_message (lua_State *L);
int lua_git_repository_message_remove (lua_State *L);
int lua_git_repository_odb (lua_State *L);
int lua_git_repository_open(lua_State *L);
int lua_git_repository_open_bare(lua_State *L);
int lua_git_repository_open_from_worktree (lua_State *L);
int lua_git_repository_path (lua_State *L);
int lua_git_repository_refdb (lua_State *L);
int lua_git_repository_set_head (lua_State *L);
int lua_git_repository_set_head_detached (lua_State *L);
int lua_git_repository_set_ident (lua_State *L);
int lua_git_repository_set_namespace (lua_State *L);
int lua_git_repository_set_workdir (lua_State *L);
int lua_git_repository_state (lua_State *L);
int lua_git_repository_state_cleanup (lua_State *L);
int lua_git_repository_workdir (lua_State *L);
int lua_git_repository_free (lua_State *L);

#endif
