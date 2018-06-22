#ifndef _lua_reference_h
#define _lua_reference_h

#include "../common/lua_common.h"

int lua_git_reference_create (lua_State *L);
int lua_git_reference_create_matching (lua_State *L);
int lua_git_reference_dup (lua_State *L);
int lua_git_reference_dwim (lua_State *L);
int lua_git_reference_ensure_log (lua_State *L);
int lua_git_reference_has_log (lua_State *L);
int lua_git_reference_is_branch (lua_State *L);
int lua_git_reference_is_note (lua_State *L);
int lua_git_reference_is_remote (lua_State *L);
int lua_git_reference_is_tag (lua_State *L);
int lua_git_reference_is_valid_name (lua_State *L);
int lua_git_reference_iterator_glob_new (lua_State *L);
int lua_git_reference_iterator_new (lua_State *L);
int lua_git_reference_list (lua_State *L);
int lua_git_reference_lookup (lua_State *L);
int lua_git_reference_name (lua_State *L);
int lua_git_reference_name_to_id (lua_State *L);
int lua_git_reference_next (lua_State *L);
int lua_git_reference_next_name (lua_State *L);
int lua_git_reference_owner (lua_State *L);
int lua_git_reference_peel (lua_State *L);
int lua_git_reference_remove (lua_State *L);
int lua_git_reference_rename (lua_State *L);
int lua_git_reference_resolve (lua_State *L);
int lua_git_reference_set_target (lua_State *L);
int lua_git_reference_symbolic_create (lua_State *L);
int lua_git_reference_symbolic_create_matching (lua_State *L);
int lua_git_reference_symbolic_set_target (lua_State *L);
int lua_git_reference_symbolic_target (lua_State *L);
int lua_git_reference_target (lua_State *L);
int lua_git_reference_target_peel (lua_State *L);
int lua_git_reference_type (lua_State *L);
int lua_git_reference_free (lua_State *L);
int lua_git_reference_iterator_free (lua_State *L);

#endif
