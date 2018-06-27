#include "lua_libgit2.h"

int lua_git_libgit2_init (lua_State *L) {
	git_libgit2_init();
	return 1;
}

int lua_git_libgit2_shutdown (lua_State *L) {
	git_libgit2_shutdown();
	return 1;
}

int lua_git_libgit2_features (lua_State *L) {
	check_error_long(git_libgit2_features(),
	    "Error Accessing libgit2 features", NULL);
	int features_number = git_libgit2_features();
	lua_pushinteger(L, features_number);
	return 1;
}

int lua_git_libgit2_version (lua_State *L) {
	libgit_version_data *version_data;

	version_data = (libgit_version_data *)lua_newuserdata(L, sizeof(*version_data));
	version_data->major  = 0;
	version_data->minor = 0;
	version_data->rev = 0;


	luaL_newmetatable(L, "libgit2_version_data");

	lua_setmetatable(L, -2);

	int Major ;
	int Minor ;
	int Rev ;

	git_libgit2_version(&Major, &Minor, &Rev );

	version_data->major = Major;
	version_data->minor = Minor;
	version_data->rev = Rev;

	return 1;

}

int lua_GIT_OPT_GET_MWINDOW_SIZE(lua_State *L) {
	size_t mmap_size ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_MWINDOW_SIZE, &mmap_size),
	    "Error in getting memory map size", NULL);
	lua_pushinteger(L, mmap_size);
	return 1;
}

int lua_GIT_OPT_SET_MWINDOW_SIZE(lua_State *L) {
	size_t size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_MWINDOW_SIZE, size),
	    "Error setting memory map size", NULL);
	return 1;
}

int lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT(lua_State *L) {
	size_t mmap_limit ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT, &mmap_limit),
	    "Error getting memory map limit", NULL);

	lua_pushinteger(L, mmap_limit);
	return 1;
}

int lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT(lua_State *L) {
	int size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_MWINDOW_MAPPED_LIMIT, size),
	    "Error setting memory map limit", NULL);
	return 1;
}


int lua_GIT_OPT_GET_SEARCH_PATH(lua_State *L) {
	git_buf path = {0} ;
	int option_number = luaL_checkinteger(L, 1);

	switch (option_number) {
		case 1:
			check_error_long(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_SYSTEM, &path),
			    "error getting system level search path", NULL);
			break;
		case 2:
			check_error_long(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_GLOBAL, &path),
			    "Error getting global level search path", NULL);
			break;
		case 3:
			check_error_long(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_XDG, &path),
			    "Error getting XDG level search path", NULL);
			break;
		case 4:
			check_error_long(git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_PROGRAMDATA, &path),
			    "Error getting program data level search path", NULL);
			break;
	}

	lua_pushstring(L, path.ptr);
	return 1;
}

int lua_GIT_OPT_SET_SEARCH_PATH(lua_State *L) {
	int option_number = luaL_checkinteger(L, 1);
	const char *path = luaL_checkstring(L, 2);

	switch (option_number) {
		case 1:
			check_error_long(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_SYSTEM, path),
			    "Error Setting system level search path", NULL);
			break;
		case 2:
			check_error_long(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_GLOBAL, path),
			    "Error Setting global level search path", NULL);
			break;
		case 3:
			check_error_long(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_XDG, path),
			    "Error Setting XDG level search path", NULL);
			break;
		case 4:
			check_error_long(git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_PROGRAMDATA, path),
			    "Error Setting program data level search path", NULL);
			break;
	}
	return 1;
}


int lua_GIT_OPT_GET_CACHED_MEMORY(lua_State *L) {
	ssize_t current;
	ssize_t allowed ;
	int option_number = luaL_checkinteger(L, 1);

	check_error_long(git_libgit2_opts(GIT_OPT_GET_CACHED_MEMORY, &current, &allowed),
	    "Error getting cached memory size", NULL);

	switch (option_number) {
		case 1:
			lua_pushinteger(L, current);
			break;
		case 2:
			lua_pushinteger(L, allowed);
			break;
	}

	return 1;
}

int lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT(lua_State *L) {
	luagit2_otype *obj_type = (luagit2_otype *)lua_touserdata(L,1);
	size_t size = luaL_checkinteger(L, 2);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_CACHE_OBJECT_LIMIT, obj_type->otype, size),
	    "Error setting chache limit", NULL);
	return 1;
}

int lua_GIT_OPT_SET_CACHE_MAX_SIZE(lua_State *L) {
	ssize_t	 size = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_CACHE_MAX_SIZE, size),
	    "Error setting maximum cache size ", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_CACHING(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_CACHING, enabled),
	    "Error while enable/disable caching", NULL);
	return 1;
}

int lua_GIT_OPT_GET_TEMPLATE_PATH(lua_State *L) {
	git_buf path = {0};

	check_error_long(git_libgit2_opts(GIT_OPT_GET_TEMPLATE_PATH, &path),
	    "Error getting Template path", NULL);

	lua_pushstring(L, path.ptr);
	return 1;
}

int lua_GIT_OPT_SET_TEMPLATE_PATH(lua_State *L) {
	const char *path = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_TEMPLATE_PATH, path),
	    "Error setting Template path", NULL);
	return 1;
}

int lua_GIT_OPT_SET_USER_AGENT(lua_State *L) {
	const char *user_agent = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_USER_AGENT, user_agent),
	    "Error setting user agent", NULL);
	return 1;
}

int lua_GIT_OPT_GET_WINDOWS_SHAREMODE(lua_State *L) {
	unsigned long value ;
	check_error_long(git_libgit2_opts(GIT_OPT_GET_WINDOWS_SHAREMODE, &value),
	    "Error getting windows share mode", NULL);

	lua_pushnumber(L, value);
	return 1;
}

int lua_GIT_OPT_SET_WINDOWS_SHAREMODE(lua_State *L) {
	unsigned long value = luaL_checknumber(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_WINDOWS_SHAREMODE, value),
	    "Error setting windows share mode", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, enabled),
	    "Error in enable/disable strict object creation", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION, enabled),
	    "Error in enable/disable symbolic ref creation", NULL);
	return 1;
}

int lua_GIT_OPT_SET_SSL_CIPHERS(lua_State *L) {
	const char *ciphers = luaL_checkstring(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_SET_SSL_CIPHERS, ciphers),
	    "Error settting SSL ciphers", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_OFS_DELTA(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_OFS_DELTA, enabled),
	    "Error in enable/disable offset delta", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_FSYNC_GITDIR(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_FSYNC_GITDIR, enabled),
	    "Error in enable/disable fsync gitdir", NULL);
	return 1;
}

int lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION(lua_State *L) {
	int enabled = luaL_checkinteger(L, 1);
	check_error_long(git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, enabled),
	    "Error in enable/disable strich hash verification", NULL);
	return 1;
}