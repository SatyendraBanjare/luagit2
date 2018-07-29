#ifndef _lua_annotated_h
#define _lua_annotated_h

#include "../common/lua_common.h"

int lua_git_annotated_commit_from_ref (lua_State *L);
int lua_git_annotated_commit_from_revspec (lua_State *L);
int lua_git_annotated_commit_lookup (lua_State *L);
int lua_git_annotated_commit_from_fetchhead (lua_State *L);
int lua_git_annotated_commit_id(lua_State *L);
int lua_git_annotated_commit_free (lua_State *L);

#endif
