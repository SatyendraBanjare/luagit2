#ifndef _lua_config_h
#define _lua_config_h

#include "../common/lua_common.h"

int lua_git_config_delete_entry (lua_State *L);
int lua_git_config_delete_multivar (lua_State *L);
int lua_git_config_find_global (lua_State *L);
int lua_git_config_find_programdata (lua_State *L);
int lua_git_config_find_system (lua_State *L);
int lua_git_config_find_xdg (lua_State *L);
int lua_git_config_get_int32 (lua_State *L);
int lua_git_config_get_int64 (lua_State *L);
int lua_git_config_get_bool (lua_State *L);
int lua_git_config_get_path (lua_State *L);
int lua_git_config_get_string (lua_State *L);
int lua_git_config_get_string_buf (lua_State *L);
int lua_git_config_open_default (lua_State *L);
int lua_git_config_open_global (lua_State *L);
int lua_git_config_open_level (lua_State *L);
int lua_git_config_open_ondisk (lua_State *L);
int lua_git_config_parse_bool (lua_State *L);
int lua_git_config_parse_int32 (lua_State *L);
int lua_git_config_parse_int64 (lua_State *L);
int lua_git_config_parse_path (lua_State *L);
int lua_git_config_set_bool (lua_State *L);
int lua_git_config_set_int32 (lua_State *L);
int lua_git_config_set_int64 (lua_State *L);
int lua_git_config_set_multivar (lua_State *L);
int lua_git_config_set_string (lua_State *L);
int lua_git_config_snapshot (lua_State *L);
int lua_git_config_free (lua_State *L);

#endif
