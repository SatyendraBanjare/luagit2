#ifndef _lua_revwalk_h
#define _lua_revwalk_h

#include "../common/lua_common.h"

int lua_git_revwalk_new(lua_State *L);
int lua_git_revwalk_next (lua_State *L);
int lua_git_revwalk_push (lua_State *L);
int lua_git_revwalk_push_ref (lua_State *L);
int lua_git_revwalk_free (lua_State *L);
int lua_git_revwalk_reset (lua_State *L);
int lua_git_revwalk_push_head (lua_State *L);
int lua_git_revwalk_repository (lua_State *L);

#endif
