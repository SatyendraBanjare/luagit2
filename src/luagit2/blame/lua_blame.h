#ifndef _lua_blame_h
#define _lua_blame_h

#include "../../luaC-api/lua.h"
#include "../../luaC-api/lualib.h"
#include "../../luaC-api/lauxlib.h"
#include "../lua_objects.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <git2.h>

static int lua_git_blame_buffer (lua_State *L) {
	luagit2_blame *lua_blame;
	const luagit2_blame *reference = (luagit2_blame *)lua_touserdata(L, 1);
	const char *buffer = luaL_checkstring(L,2);
	size_t buffer_len = luaL_checkinteger(L,3);

    lua_blame = (luagit2_blame *)lua_newuserdata(L, sizeof(*lua_blame));
    lua_blame->blame = NULL;

    luaL_getmetatable(L, "luagit2_blame");

    lua_setmetatable(L, -2);

    git_blame *local_blame ;
    git_blame_buffer(&local_blame,reference->blame,buffer,buffer_len);
   	lua_blame->blame  = local_blame;

    return 1;
}

static int lua_git_blame_file (lua_State *L) {
	luagit2_blame *lua_blame;
	const luagit2_repository *Repo = (luagit2_repository *)lua_touserdata(L, 1);
	const char *path = luaL_checkstring(L,2);

    lua_blame = (luagit2_blame *)lua_newuserdata(L, sizeof(*lua_blame));
    lua_blame->blame = NULL;

    luaL_getmetatable(L, "luagit2_blame");

    lua_setmetatable(L, -2);

    git_blame *local_blame ;
    git_blame_file(&local_blame,Repo->repo,path,NULL);
   	lua_blame->blame  = local_blame;

    return 1;
}

static int lua_git_blame_get_hunk_byindex (lua_State *L) {
	const luagit2_blame *reference = (luagit2_blame *)lua_touserdata(L, 1);
	uint32_t index = luaL_checkinteger(L,2);

	luagit2_blame_hunk *Blame_Hunk;

	Blame_Hunk = (luagit2_blame_hunk *)lua_newuserdata(L, sizeof(*Blame_Hunk));

    luaL_getmetatable(L, "luagit2_blame_hunk");

    lua_setmetatable(L, -2);

    Blame_Hunk->blame_hunk = git_blame_get_hunk_byindex(reference->blame,index);

    return 1;
}

static int lua_git_blame_get_hunk_byline (lua_State *L) {
	const luagit2_blame *reference = (luagit2_blame *)lua_touserdata(L, 1);
	size_t line_no = luaL_checkinteger(L,2);

	luagit2_blame_hunk *Blame_Hunk;

	Blame_Hunk = (luagit2_blame_hunk *)lua_newuserdata(L, sizeof(*Blame_Hunk));

    luaL_getmetatable(L, "luagit2_blame_hunk");

    lua_setmetatable(L, -2);

    Blame_Hunk->blame_hunk = git_blame_get_hunk_byline(reference->blame,line_no);

    return 1;
}

static int lua_git_blame_get_hunk_count (lua_State *L) {
	const luagit2_blame *reference = (luagit2_blame *)lua_touserdata(L, 1);
    uint32_t count =  git_blame_get_hunk_count(reference->blame);

	lua_pushinteger(L,count);

    return 1;
}
#endif
