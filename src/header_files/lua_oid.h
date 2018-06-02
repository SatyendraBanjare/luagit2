#ifndef _lua_oid_h
#define _lua_oid_h

#include "../luaC-api/lua.h"
#include "../luaC-api/lualib.h"
#include "../luaC-api/lauxlib.h"
#include "lua_objects.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_oid_fromstr (lua_State *L) {
	luagit2_oid *obj_id;
    const char *string_value = luaL_checkstring(L,1);
	
    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_getmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);
    
    git_oid local_id;
    git_oid_fromstr(&local_id,string_value); 
   	obj_id->oid = local_id;
 
    return 1;
}

static int lua_git_oid_fromstrn (lua_State *L) {
	luagit2_oid *obj_id;
    const char *string_value = luaL_checkstring(L,1);
    size_t length = luaL_checkinteger(L,2);
	
    obj_id = (luagit2_oid *)lua_newuserdata(L, sizeof(*obj_id));

    luaL_getmetatable(L, "luagit2_oid");
    lua_setmetatable(L, -2);
    
    git_oid local_id;
    git_oid_fromstrn(&local_id,string_value,length); 
   	obj_id->oid = local_id;
 
    return 1;
}

static int lua_git_oid_cmp (lua_State *L) {
	const luagit2_oid *oid_A;
	const luagit2_oid *oid_B;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
    oid_B = (luagit2_oid *)lua_touserdata(L, 2);
	int result = git_oid_cmp(&(oid_A->oid),&(oid_B->oid));

	lua_pushinteger(L,result);
    return 1;
}

static int lua_git_oid_ncmp (lua_State *L) {
	const luagit2_oid *oid_A;
	const luagit2_oid *oid_B;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
    oid_B = (luagit2_oid *)lua_touserdata(L, 2);
    size_t length = luaL_checkinteger(L,3);
	int result = git_oid_ncmp(&(oid_A->oid),&(oid_B->oid),length);

	lua_pushinteger(L,result);
    return 1;
}

static int lua_git_oid_fmt (lua_State *L) {
    const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);

    char result_str[GIT_OID_HEXSZ+1];
    result_str[GIT_OID_HEXSZ] = '\0';
    git_oid_fmt(result_str,&(oid_A->oid));

    lua_pushstring(L,result_str);
    return 1;
}

static int lua_git_oid_nfmt (lua_State *L) {
	const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
    size_t length = luaL_checkinteger(L,2);
    char result_str[GIT_OID_HEXSZ+1];
    result_str[GIT_OID_HEXSZ] = '\0';
	git_oid_nfmt(result_str,length,&(oid_A->oid));

	lua_pushstring(L,result_str);
    return 1;
}

static int lua_git_oid_pathfmt (lua_State *L) {
	const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);

    char result_str[GIT_OID_HEXSZ+2];
    result_str[GIT_OID_HEXSZ +1] = '\0';
	git_oid_pathfmt(result_str,&(oid_A->oid));

	lua_pushstring(L,result_str);
    return 1;
}

static int lua_git_oid_iszero (lua_State *L) {
	const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
	int result = git_oid_iszero(&(oid_A->oid));

	lua_pushinteger(L,result);
	return 1; 
}

static int lua_git_oid_strcmp (lua_State *L) {
	const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
	const char *string_to_compare = luaL_checkstring(L,2);
	int result = git_oid_strcmp(&(oid_A->oid),string_to_compare);

	lua_pushinteger(L,result);

    return 1;
}
   
static int lua_git_oid_tostr (lua_State *L) {
    const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
    size_t size_value = luaL_checkinteger(L,2);
    char *string_value ;;
    git_oid_tostr(string_value,size_value,&(oid_A->oid));
    lua_pushstring(L,string_value);
    
    return 1;
}

static int lua_git_oid_tostr_s (lua_State *L) {
    const luagit2_oid *oid_A;

    oid_A = (luagit2_oid *)lua_touserdata(L, 1);
    const char *string_value = git_oid_tostr_s(&(oid_A->oid));

    lua_pushstring(L,string_value);

    return 1;
}

#endif