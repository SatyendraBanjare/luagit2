#ifndef _lua_libgit2_h
#define _lua_libgit2_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h> 

static int lua_git_libgit2_init (lua_State *L) {
    git_libgit2_init();
    return 1;
}

static int lua_git_libgit2_shutdown (lua_State *L) {
    git_libgit2_shutdown();
    return 1;
}

static int lua_git_libgit2_features (lua_State *L) {
    int features_number = git_libgit2_features();
    lua_pushinteger(L , features_number);
    return 1;
} 
 
static int lua_git_libgit2_version (lua_State *L) {
	libgit_version_data *version_data;
 
    version_data = (libgit_version_data *)lua_newuserdata(L, sizeof(*version_data));
    version_data->major  = 0;
    version_data->minor = 0;
    version_data->rev = 0;
 
    
    luaL_getmetatable(L, "libgit2_version_data");
    
    lua_setmetatable(L, -2);

	int Major ;
	int Minor ;
	int Rev ;
    
    git_libgit2_version(&Major , &Minor ,&Rev );
    
    version_data->major = Major;
   	version_data->minor = Minor;
   	version_data->rev = Rev;
 
    return 1;

}

static int lua_GIT_OPT_GET_MWINDOW_SIZE(lua_State *L){
	int *mmap_size ;
	git_libgit2_opts(GIT_OPT_GET_MWINDOW_SIZE, mmap_size);
 	
 	int MMap_Size = *mmap_size;
 	lua_pushinteger(L,MMap_Size); 
	return 1;
}

static int lua_GIT_OPT_SET_MWINDOW_SIZE(lua_State *L){
	int size = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_SET_MWINDOW_SIZE, size);
	return 1;
}

static int lua_GIT_OPT_GET_MWINDOW_MAPPED_LIMIT(lua_State *L){
	int *mmap_limit ;
	git_libgit2_opts(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT, mmap_limit);
 	
 	int MMap_Limit = *mmap_limit;
 	lua_pushinteger(L,MMap_Limit); 
	return 1;
}

static int lua_GIT_OPT_SET_MWINDOW_MAPPED_LIMIT(lua_State *L){
	int size = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_SET_MWINDOW_MAPPED_LIMIT, size);
	return 1;
}


static int lua_GIT_OPT_GET_SEARCH_PATH(lua_State *L){
	git_buf path = {0} ;
	int option_number = luaL_checkint(L,1);

	switch(option_number)
	{
		case 1: git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_SYSTEM, &path);
		    	break;
		case 2: git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_GLOBAL, &path);
		    	break;
		case 3: git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_XDG, &path);
		    	break;
		case 4: git_libgit2_opts(GIT_OPT_GET_SEARCH_PATH, GIT_CONFIG_LEVEL_PROGRAMDATA, &path);
		    	break;
	}

 	lua_pushstring(L,path.ptr); 
	return 1;
}

static int lua_GIT_OPT_SET_SEARCH_PATH(lua_State *L){
	int option_number = luaL_checkint(L,1);
	const char *path = luaL_checkstring(L,2);

	switch(option_number)
	{
		case 1: git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_SYSTEM, path);
		    	break;
		case 2: git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_GLOBAL, path);
		    	break;
		case 3: git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_XDG, path);
		    	break;
		case 4: git_libgit2_opts(GIT_OPT_SET_SEARCH_PATH, GIT_CONFIG_LEVEL_PROGRAMDATA, path);
		    	break;
	}
	return 1;
}


static int lua_GIT_OPT_GET_CACHED_MEMORY(lua_State *L){
	ssize_t *current; ssize_t *allowed ;
	int option_number = luaL_checkint(L,1);

	git_libgit2_opts(GIT_OPT_GET_CACHED_MEMORY, current , allowed);

	switch(option_number)
	{
		case 1: lua_pushinteger(L,*current); 
		    	break;
		case 2: lua_pushinteger(L,*allowed); 
		    	break;
	}

	return 1;
}

static int lua_GIT_OPT_SET_CACHE_OBJECT_LIMIT(lua_State *L){
	int size = luaL_checkint(L,1);
	git_otype type;
	git_libgit2_opts(GIT_OPT_SET_CACHE_OBJECT_LIMIT,type, size);
	return 1;
}

static int lua_GIT_OPT_SET_CACHE_MAX_SIZE(lua_State *L){
	ssize_t	 size = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_SET_CACHE_MAX_SIZE, size);
	return 1;
}

static int lua_GIT_OPT_ENABLE_CACHING(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_CACHING, enabled);
	return 1;
}

static int lua_GIT_OPT_GET_TEMPLATE_PATH(lua_State *L){
	git_buf path = {0};

	git_libgit2_opts(GIT_OPT_GET_TEMPLATE_PATH, &path);

 	lua_pushstring(L,path.ptr); 
	return 1;
}

static int lua_GIT_OPT_SET_TEMPLATE_PATH(lua_State *L){
	const char *path = luaL_checkstring(L,1);
	git_libgit2_opts(GIT_OPT_SET_TEMPLATE_PATH, path);
	return 1;
}

static int lua_GIT_OPT_SET_USER_AGENT(lua_State *L){
	const char *user_agent = luaL_checkstring(L,1);
	git_libgit2_opts(GIT_OPT_SET_USER_AGENT, user_agent);
	return 1;
}

static int lua_GIT_OPT_GET_WINDOWS_SHAREMODE(lua_State *L){
	unsigned long *value ;
	git_libgit2_opts(GIT_OPT_GET_WINDOWS_SHAREMODE, value);
 	
 	int Value = *value;
 	lua_pushnumber(L,Value); 
	return 1;
}

static int lua_GIT_OPT_SET_WINDOWS_SHAREMODE(lua_State *L){
	unsigned long value = luaL_checklong(L,1);
	git_libgit2_opts(GIT_OPT_SET_WINDOWS_SHAREMODE, value);
	return 1;
}

static int lua_GIT_OPT_ENABLE_STRICT_OBJECT_CREATION(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_STRICT_OBJECT_CREATION, enabled);
	return 1;
}

static int lua_GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION, enabled);
	return 1;
}

static int lua_GIT_OPT_SET_SSL_CIPHERS(lua_State *L){
	const char *ciphers = luaL_checkstring(L,1);
	git_libgit2_opts(GIT_OPT_SET_SSL_CIPHERS, ciphers);
	return 1;
}

static int lua_GIT_OPT_ENABLE_OFS_DELTA(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_OFS_DELTA, enabled);
	return 1;
}

static int lua_GIT_OPT_ENABLE_FSYNC_GITDIR(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_FSYNC_GITDIR, enabled);
	return 1;
}

static int lua_GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION(lua_State *L){
	int enabled = luaL_checkint(L,1);
	git_libgit2_opts(GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION, enabled);

	return 1;
}

#endif
