#ifndef _lua_config_help
#define _lua_config_help

#include "../common/lua_common.h"

int lua_get_config_level_program_data(lua_State *L);
int lua_get_config_level_system(lua_State *L);
int lua_get_config_level_xdg(lua_State *L);
int lua_get_config_level_global(lua_State *L);
int lua_get_config_level_local(lua_State *L);
int lua_get_config_entry_name(lua_State *L);
int lua_get_config_entry_value(lua_State *L);

#endif
