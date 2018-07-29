#include "lua_libgit2.h"

int lua_git_libgit2_init (lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	git_libgit2_init();
	return 1;
}

int lua_git_libgit2_shutdown (lua_State *L) {
	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	git_libgit2_shutdown();
	return 1;
}

int lua_git_libgit2_features (lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	check_error_long(git_libgit2_features(),
	    "Error Accessing libgit2 features", NULL);
	int features_number = git_libgit2_features();
	lua_pushinteger(L, features_number);
	return 1;
}

int lua_git_libgit2_version (lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	int Major, Minor, Rev ;

	git_libgit2_version(&Major, &Minor, &Rev );

	lua_pushinteger(L, Major);
	lua_pushinteger(L, Minor);
	lua_pushinteger(L, Rev);

	return 3;

}

int lua_GIT_OPT_GET_MWINDOW_SIZE(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	size_t mmap_size ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_MWINDOW_SIZE, &mmap_size),
	    "Error in getting memory map size", NULL);
	lua_pushinteger(L, mmap_size);
	return 1;
}

int lua_GIT_OPT_SET_MWINDOW_SIZE(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: size");
	}

	size_t size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_MWINDOW_SIZE, size),
	    "Error setting memory map size", NULL);
	return 1;
}

int lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	size_t mmap_limit ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT, &mmap_limit),
	    "Error getting memory map limit", NULL);

	lua_pushinteger(L, mmap_limit);
	return 1;
}

int lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument: size");
	}

	int size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_MWINDOW_MAPPED_LIMIT, size),
	    "Error setting memory map limit", NULL);
	return 1;
}

int lua_GIT_OPT_GET_SEARCH_PATH(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : search_path_level");
	}

	git_buf path = GIT_BUF_INIT_CONST(NULL, 0);
	git_config_level_t cfg_lvl = 0;

	const char *option = luaL_checkstring(L, 1);

	if ((cfg_lvl = (strcasecmp(option, "system") == 0 ? GIT_CONFIG_LEVEL_SYSTEM : 0)) != 0 ) {
		goto push_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "global") == 0 ? GIT_CONFIG_LEVEL_GLOBAL : 0)) != 0 ) {
		goto push_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "xdg") == 0 ? GIT_CONFIG_LEVEL_XDG : 0)) != 0 ) {
		goto push_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "programdata") == 0 ? GIT_CONFIG_LEVEL_PROGRAMDATA : 0)) != 0 ) {
		goto push_val;
	}

push_val : {
		check_error_long(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, cfg_lvl, &path),
		    "error getting search path", "Unsupported option, must be one of : system, global, xdg, programdata");

		lua_pushstring(L, path.ptr);
		return 1;
	}

	luaL_error(L, "Unsupported option, must be one of : system, global, xdg, programdata");
	return 0;
}

int lua_GIT_OPT_SET_SEARCH_PATH(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : search_path_level, path");
	}

	git_config_level_t cfg_lvl = 0;
	const char *option = luaL_checkstring(L, 1);
	const char *path = luaL_checkstring(L, 2);

	if ((cfg_lvl = (strcasecmp(option, "system") == 0 ? GIT_CONFIG_LEVEL_SYSTEM : 0)) != 0 ) {
		goto set_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "global") == 0 ? GIT_CONFIG_LEVEL_GLOBAL : 0)) != 0 ) {
		goto set_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "xdg") == 0 ? GIT_CONFIG_LEVEL_XDG : 0)) != 0 ) {
		goto set_val;
	}
	if ((cfg_lvl = (strcasecmp(option, "programdata") == 0 ? GIT_CONFIG_LEVEL_PROGRAMDATA : 0)) != 0 ) {
		goto set_val;
	}

set_val : {
		check_error_long(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, cfg_lvl, path),
		    "error setting search path", "Unsupported option, must be one of : system, global, xdg, programdata");
		return 1;
	}

	luaL_error(L, "Unsupported option, must be one of : system, global, xdg, programdata");
	return 0;
}


int lua_GIT_OPT_GET_CACHED_MEMORY(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	ssize_t current, allowed ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_CACHED_MEMORY, &current, &allowed),
	    "Error getting cached memory size", NULL);

	lua_pushinteger(L, current);
	lua_pushinteger(L, allowed);

	return 2;
}

int lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 argument : luagit2_otype, size");
	}

	luagit2_otype *obj_type = (luagit2_otype *)luaL_checkudata(L, 1, "luagit2_otype");
	size_t size = luaL_checkinteger(L, 2);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_CACHE_OBJECT_LIMIT, obj_type->otype, size),
	    "Error setting cache limit", NULL);
	return 1;
}

int lua_GIT_OPT_SET_CACHE_MAX_SIZE(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : size");
	}

	ssize_t	 size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_CACHE_MAX_SIZE, size),
	    "Error setting maximum cache size ", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_CACHING(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_CACHING, enabled),
	    "Error while enable/disable caching", NULL);
	return 1;
}

int lua_GIT_OPT_GET_TEMPLATE_PATH(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	git_buf path = GIT_BUF_INIT_CONST(NULL, 0);

	check_error_long(git_libgit2_opts(GIT_OPT_GET_TEMPLATE_PATH, &path),
	    "Error getting Template path", NULL);

	lua_pushstring(L, path.ptr);
	return 1;
}

int lua_GIT_OPT_SET_TEMPLATE_PATH(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : path");
	}

	const char *path = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_TEMPLATE_PATH, path),
	    "Error setting Template path", NULL);
	return 1;
}

int lua_GIT_OPT_SET_USER_AGENT(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : user_agent");
	}

	const char *user_agent = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_USER_AGENT, user_agent),
	    "Error setting user agent", NULL);
	return 1;
}

int lua_GIT_OPT_GET_WINDOWS_SHAREMODE(lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	unsigned long value ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_WINDOWS_SHAREMODE, &value),
	    "Error getting windows share mode", NULL);

	lua_pushnumber(L, value);
	return 1;
}

int lua_GIT_OPT_SET_WINDOWS_SHAREMODE(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : value");
	}

	unsigned long value = luaL_checknumber(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_WINDOWS_SHAREMODE, value),
	    "Error setting windows share mode", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, enabled),
	    "Error in enable/disable strict object creation", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION, enabled),
	    "Error in enable/disable symbolic ref creation", NULL);
	return 1;
}

int lua_GIT_OPT_SET_SSL_CIPHERS(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : ciphers");
	}

	const char *ciphers = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_SSL_CIPHERS, ciphers),
	    "Error setting SSL ciphers", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_OFS_DELTA(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_OFS_DELTA, enabled),
	    "Error in enable/disable offset delta", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_FSYNC_GITDIR(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_FSYNC_GITDIR, enabled),
	    "Error in enable/disable fsync gitdir", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : enable/disable");
	}

	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, enabled),
	    "Error in enable/disable strict hash verification", NULL);
	return 1;
}
