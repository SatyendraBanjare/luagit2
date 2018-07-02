#include "lua_config_help.h"

// typedef enum {
// 	/** System-wide on Windows, for compatibility with portable git */
// 	GIT_CONFIG_LEVEL_PROGRAMDATA = 1,

// 	/** System-wide configuration file; /etc/gitconfig on Linux systems */
// 	GIT_CONFIG_LEVEL_SYSTEM = 2,

// 	/** XDG compatible configuration file; typically ~/.config/git/config */
// 	GIT_CONFIG_LEVEL_XDG = 3,

// 	/** User-specific configuration file (also called Global configuration
// 	 * file); typically ~/.gitconfig
// 	 */
// 	GIT_CONFIG_LEVEL_GLOBAL = 4,

// 	/** Repository specific configuration file; $WORK_DIR/.git/config on
// 	 * non-bare repos
// 	 */
// 	GIT_CONFIG_LEVEL_LOCAL = 5,

// 	/** Application specific configuration file; freely defined by applications
// 	 */
// 	GIT_CONFIG_LEVEL_APP = 6,

// 	/** Represents the highest level available config file (i.e. the most
// 	 * specific config file available that actually is loaded)
// 	 */
// 	GIT_CONFIG_HIGHEST_LEVEL = -1,
// } git_config_level_t;

int lua_get_config_level_program_data(lua_State *L) {
	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_PROGRAMDATA;
	return 1;
}

int lua_get_config_level_system(lua_State *L) {
	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_SYSTEM;
	return 1;
}

int lua_get_config_level_xdg(lua_State *L) {
	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_XDG;
	return 1;
}

int lua_get_config_level_global(lua_State *L) {
	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_GLOBAL;
	return 1;
}

int lua_get_config_level_local(lua_State *L) {
	luagit2_config_level_t *Cfg_lvl ;
	Cfg_lvl = (luagit2_config_level_t *)lua_newuserdata(L, sizeof(*Cfg_lvl));

	luaL_newmetatable(L, "luagit2_config_level_t");
	lua_setmetatable(L, -2);

	Cfg_lvl->level = GIT_CONFIG_LEVEL_LOCAL;
	return 1;
}

int lua_get_config_entry_name(lua_State *L) {
	const luagit2_config_entry *cfg_entry = (luagit2_config_entry *)lua_touserdata(L, 1);
	const char *entry_name = (cfg_entry->config_entry)->name;
	lua_pushstring(L,entry_name);
	return 1;
}

int lua_get_config_entry_value(lua_State *L) {
	const luagit2_config_entry *cfg_entry = (luagit2_config_entry *)lua_touserdata(L, 1);
	const char *entry_value = (cfg_entry->config_entry)->value;
	lua_pushstring(L,entry_value);
	return 1;
}
