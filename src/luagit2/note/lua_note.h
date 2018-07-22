#ifndef _lua_note_h
#define _lua_note_h

#include "../common/lua_common.h"

int lua_git_note_author (lua_State *L);
int lua_git_note_committer (lua_State *L);
int lua_git_note_commit_create (lua_State *L);
int lua_git_note_create (lua_State *L);
int lua_git_note_free (lua_State *L);
int lua_git_note_message (lua_State *L);
int lua_git_note_id (lua_State *L);
int lua_git_note_commit_remove (lua_State *L);
int lua_git_note_remove (lua_State *L);
int lua_git_note_read (lua_State *L);

#endif
