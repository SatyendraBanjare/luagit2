#ifndef _lua_signature_
#define _lua_signature_

#include "../luaC-api/lua.h"
#include "../luaC-api/lualib.h"
#include "../luaC-api/lauxlib.h"
#include "lua_objects.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_signature_default (lua_State *L) {
	luagit2_signature *lua_sign;
	const char *path_to_repository = luaL_checkstring(L,1);
 
    lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
    lua_sign->sign  = NULL;
 
    luaL_getmetatable(L, "luagit2_signature");
    
    lua_setmetatable(L, -2);
    
    git_signature *local_sign_obj;
    git_repository *local_repo = NULL;
    git_repository_open(&local_repo,path_to_repository);
    git_signature_default(&local_sign_obj,local_repo);

   	lua_sign->sign  = local_sign_obj;
 
    return 1;
}

static int lua_git_signature_dup (lua_State *L) {
	luagit2_signature *lua_sign;
	const luagit2_signature *source_sign = (luagit2_signature *)lua_touserdata(L, 1);
 
    lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
    lua_sign->sign  = NULL;
 
    luaL_getmetatable(L, "luagit2_signature");
    
    lua_setmetatable(L, -2);
    
    git_signature *local_sign_obj;
    git_signature_dup(&local_sign_obj,source_sign->sign);

   	lua_sign->sign  = local_sign_obj;
 
    return 1;
}

static int lua_git_signature_from_buffer (lua_State *L) {
	luagit2_signature *lua_sign;
	const char *buf_string = luaL_checkstring(L,1);
 
    lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
    lua_sign->sign  = NULL;
 
    luaL_getmetatable(L, "luagit2_signature");
    
    lua_setmetatable(L, -2);
    
    git_signature *local_sign_obj;
    git_signature_from_buffer(&local_sign_obj,buf_string);

   	lua_sign->sign  = local_sign_obj;
 
    return 1;
}

static int lua_git_signature_now (lua_State *L) {
	luagit2_signature *lua_sign;
	const char *name = luaL_checkstring(L,1);
	const char *email = luaL_checkstring(L,2);

    lua_sign = (luagit2_signature *)lua_newuserdata(L, sizeof(*lua_sign));
    lua_sign->sign  = NULL;
 
    luaL_getmetatable(L, "luagit2_signature");
    
    lua_setmetatable(L, -2);
    
    git_signature *local_sign_obj;
    git_signature_now(&local_sign_obj,name,email);

   	lua_sign->sign  = local_sign_obj;
 
    return 1;
}

#endif