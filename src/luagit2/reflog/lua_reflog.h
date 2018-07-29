#ifndef _lua_reflog_h
#define _lua_reflog_h

#include "../common/lua_common.h"

int lua_git_reflog_read(lua_State *L);
int lua_git_reflog_entrycount(lua_State *L);
int lua_git_reflog_free(lua_State *L);
int lua_git_reflog_entry_byindex(lua_State *L);
int lua_git_reflog_entry_committer(lua_State *L);
int lua_git_reflog_entry_message(lua_State *L);
int lua_git_reflog_entry_id_new (lua_State *L);
int lua_git_reflog_entry_id_old (lua_State *L);
int lua_git_reflog_delete(lua_State *L);
int lua_git_reflog_drop(lua_State *L);
int lua_git_reflog_append(lua_State *L);

#endif
