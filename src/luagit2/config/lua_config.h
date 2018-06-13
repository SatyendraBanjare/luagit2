#ifndef _lua_config_h
#define _lua_config_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_config_delete_entry (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    git_config_delete_entry(parent_cfg->cfg,name);

    return 1;
}

static int lua_git_config_delete_multivar (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    const char *regex = luaL_checkstring(L,3);

    git_config_delete_multivar(parent_cfg->cfg,name,regex);

    return 1;
}

static int lua_git_config_find_global (lua_State *L) {
	luagit2_buf *lua_buf;


    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_find_global(&local_buf);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_find_programdata (lua_State *L) {
	luagit2_buf *lua_buf;


    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_find_programdata(&local_buf);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_find_system (lua_State *L) {
	luagit2_buf *lua_buf;


    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_find_system(&local_buf);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_find_xdg (lua_State *L) {
	luagit2_buf *lua_buf;


    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_find_xdg(&local_buf);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_get_int32 (lua_State *L) {
	const luagit2_config *parent_cfg;
	int32_t out;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    git_config_get_int32(&out,parent_cfg->cfg,name);

   	lua_pushinteger(L,out);
    return 1;
}

static int lua_git_config_get_int64 (lua_State *L) {
	const luagit2_config *parent_cfg;
	int64_t out;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    git_config_get_int64(&out,parent_cfg->cfg,name);

   	lua_pushinteger(L,out);
    return 1;
}

static int lua_git_config_get_bool (lua_State *L) {
	const luagit2_config *parent_cfg;
	int out;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    git_config_get_bool(&out,parent_cfg->cfg,name);

   	lua_pushinteger(L,out);
    return 1;
}

static int lua_git_config_get_path (lua_State *L) {
	luagit2_buf *lua_buf;
	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_get_path(&local_buf,parent_cfg->cfg,name);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_get_string (lua_State *L) {
	const char *value;
	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    git_config_get_string(&value,parent_cfg->cfg,name);

	lua_pushstring(L,value);
    return 1;
}

static int lua_git_config_get_string_buf (lua_State *L) {
	luagit2_buf *lua_buf;
	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);

    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_get_string_buf(&local_buf,parent_cfg->cfg,name);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_open_default (lua_State *L) {
	luagit2_config *lua_cfg;

    lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
    lua_cfg->cfg  = NULL;

    luaL_getmetatable(L, "luagit2_config");

    lua_setmetatable(L, -2);

    git_config *local_config;
    git_config_open_default(&local_config);
   	lua_cfg->cfg  = local_config;

    return 1;
}

static int lua_git_config_open_global (lua_State *L) {
	luagit2_config *lua_cfg;
	luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);

    lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
    lua_cfg->cfg  = NULL;

    luaL_getmetatable(L, "luagit2_config");

    lua_setmetatable(L, -2);

    git_config *local_config;
    git_config_open_global(&local_config,parent_cfg->cfg);
   	lua_cfg->cfg  = local_config;

    return 1;
}

static int lua_git_config_open_level (lua_State *L) {
	luagit2_config *lua_cfg;
	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    luagit2_config_level_t *Level= (luagit2_config_level_t *)lua_touserdata(L, 2);

    lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
    lua_cfg->cfg  = NULL;

    luaL_getmetatable(L, "luagit2_config");

    lua_setmetatable(L, -2);

    git_config *local_config;
    git_config_open_level(&local_config,parent_cfg->cfg,Level->level);
   	lua_cfg->cfg  = local_config;

    return 1;
}

static int lua_git_config_open_ondisk (lua_State *L) {
	luagit2_config *lua_cfg;

    const char *path= luaL_checkstring(L,1);

    lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
    lua_cfg->cfg  = NULL;

    luaL_getmetatable(L, "luagit2_config");

    lua_setmetatable(L, -2);

    git_config *local_config;
    git_config_open_ondisk(&local_config,path);
   	lua_cfg->cfg  = local_config;

    return 1;
}

static int lua_git_config_parse_bool (lua_State *L) {
	const char *value= luaL_checkstring(L,1);
	int out;
    git_config_parse_bool(&out,value);
 	lua_pushinteger(L,out);

    return 1;
}

static int lua_git_config_parse_int32 (lua_State *L) {
	const char *value= luaL_checkstring(L,1);
	int32_t out;
    git_config_parse_int32(&out,value);
 	lua_pushinteger(L,out);

    return 1;
}

static int lua_git_config_parse_int64 (lua_State *L) {
	const char *value= luaL_checkstring(L,1);
	int64_t out;
    git_config_parse_int64(&out,value);
 	lua_pushinteger(L,out);

    return 1;
}

static int lua_git_config_parse_path (lua_State *L) {
	luagit2_buf *lua_buf;
	const char *path_value= luaL_checkstring(L,1);

    lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
    lua_buf->buf  = NULL;

    luaL_getmetatable(L, "luagit2_buf");

    lua_setmetatable(L, -2);

    git_buf local_buf = {0};
    git_config_parse_path(&local_buf,path_value);
   	lua_buf->buf  = &local_buf;

    return 1;
}

static int lua_git_config_set_bool (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    int value= luaL_checkint(L,3);

    git_config_set_bool(parent_cfg->cfg,name,value);

    return 1;
}

static int lua_git_config_set_int32 (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    int32_t value= luaL_checkint(L,3);

    git_config_set_int32(parent_cfg->cfg,name,value);

    return 1;
}

static int lua_git_config_set_int64 (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    int64_t value= luaL_checkint(L,3);

    git_config_set_int64(parent_cfg->cfg,name,value);

    return 1;
}

static int lua_git_config_set_multivar (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    const char *regex = luaL_checkstring(L,3);
    const char *value= luaL_checkstring(L,4);

    git_config_set_multivar(parent_cfg->cfg,name,regex,value);

    return 1;
}

static int lua_git_config_set_string (lua_State *L) {

	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);
    const char *name = luaL_checkstring(L,2);
    const char *value = luaL_checkstring(L,3);

    git_config_set_string(parent_cfg->cfg,name,value);

    return 1;
}

static int lua_git_config_snapshot (lua_State *L) {
	luagit2_config *lua_cfg;
	const luagit2_config *parent_cfg;

    parent_cfg = (luagit2_config *)lua_touserdata(L, 1);

    lua_cfg = (luagit2_config *)lua_newuserdata(L, sizeof(*lua_cfg));
    lua_cfg->cfg  = NULL;

    luaL_getmetatable(L, "luagit2_config");

    lua_setmetatable(L, -2);

    git_config *local_config;
    git_config_snapshot(&local_config,parent_cfg->cfg);
   	lua_cfg->cfg  = local_config;

    return 1;
}



#endif
