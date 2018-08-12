#include "lua_config_help.h"

int lua_get_config_level_program_data(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting No arguments ");
	}

	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_PROGRAMDATA;
	return 1;
}

int lua_get_config_level_system(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting No arguments ");
	}

	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_SYSTEM;
	return 1;
}

int lua_get_config_level_xdg(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting No arguments ");
	}

	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_XDG;
	return 1;
}

int lua_get_config_level_global(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting No arguments ");
	}

	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_GLOBAL;
	return 1;
}

int lua_get_config_level_local(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting No arguments ");
	}

	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_LOCAL;
	return 1;
}

int lua_get_config_entry_name(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 arguments : luagit2_config_entry");
	}

	const luagit2_config_entry *cfg_entry = (luagit2_config_entry *)luaL_checkudata(L, 1,"luagit2_config_entry");
	const char *entry_name = (cfg_entry->config_entry)->name;
	lua_pushstring(L,entry_name);
	return 1;
}

int lua_get_config_entry_value(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 arguments : luagit2_config_entry");
	}

	const luagit2_config_entry *cfg_entry = (luagit2_config_entry *)luaL_checkudata(L, 1,"luagit2_config_entry");
	const char *entry_value = (cfg_entry->config_entry)->value;
	lua_pushstring(L,entry_value);
	return 1;
}
