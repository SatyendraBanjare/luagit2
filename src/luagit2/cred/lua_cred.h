#ifndef _lua_cred_h
#define _lua_cred_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_cred_default_new (lua_State *L) {
	luagit2_cred_object *cred_obj;

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_default_new(&out);

   	cred_obj->git_cred_object  = out;

    return 1;

}

static int lua_git_cred_ssh_key_from_agent (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L,1);

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_ssh_key_from_agent(&out,username);

   	cred_obj->git_cred_object  = out;

    return 1;

}

static int lua_git_cred_ssh_key_memory_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L,1);
	const char *publickey = luaL_checkstring(L,2);
	const char *privatekey = luaL_checkstring(L,3);
	const char *passphrase = luaL_checkstring(L,4);

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_ssh_key_memory_new(&out,username,publickey,privatekey,passphrase);

   	cred_obj->git_cred_object  = out;

    return 1;

}

static int lua_git_cred_ssh_key_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L,1);
	const char *publickey = luaL_checkstring(L,2);
	const char *privatekey = luaL_checkstring(L,3);
	const char *passphrase = luaL_checkstring(L,4);

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_ssh_key_new(&out,username,publickey,privatekey,passphrase);

   	cred_obj->git_cred_object  = out;

    return 1;

}

static int lua_git_cred_username_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L,1);

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_username_new(&out,username);

   	cred_obj->git_cred_object  = out;

    return 1;

}

static int lua_git_cred_userpass_plaintext_new (lua_State *L) {
	luagit2_cred_object *cred_obj;
	const char *username = luaL_checkstring(L,1);
	const char *password = luaL_checkstring(L,2);

    cred_obj = (luagit2_cred_object *)lua_newuserdata(L, sizeof(*cred_obj));
    cred_obj->git_cred_object  = NULL;

    luaL_getmetatable(L, "luagit2_cred_object");

    lua_setmetatable(L, -2);

    git_cred *out;
    git_cred_userpass_plaintext_new(&out,username,password);

   	cred_obj->git_cred_object  = out;

    return 1;

}

#endif
