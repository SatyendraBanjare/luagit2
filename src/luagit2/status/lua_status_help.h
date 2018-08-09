#ifndef _lua_status_help_h
#define _lua_status_help_h

#include "../common/lua_common.h"

int lua_git_status_type(lua_State *L);
int lua_get_status_wkdir_file_paths( lua_State *L);
int lua_get_status_index_file_paths( lua_State *L);

#endif
