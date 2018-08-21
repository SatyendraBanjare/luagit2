#include "lua_blame.h"

int lua_git_blame_buffer (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_blame,buffer(string),buffer_length(int)");
	}


	luagit2_blame *lua_blame;
	const luagit2_blame *reference = (luagit2_blame *)luaL_checkudata(L, 1,"luagit2_blame");
	const char *buffer = luaL_checkstring(L, 2);
	size_t buffer_len = luaL_checkinteger(L, 3);

	lua_blame = (luagit2_blame *)lua_newuserdata(L, sizeof(*lua_blame));
	lua_blame->blame = NULL;

	luaL_newmetatable(L, "luagit2_blame");

	lua_setmetatable(L, -2);

	git_blame *local_blame ;
	check_error_long(git_blame_buffer(&local_blame, reference->blame, buffer, buffer_len),
	    "Error in generating blame buffer", NULL);
	lua_blame->blame  = local_blame;

	return 1;
}

int lua_git_blame_file (lua_State *L) {


	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,path(string)");
	}

	luagit2_blame *lua_blame;
	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1,"luagit2_repository");
	const char *path = luaL_checkstring(L, 2);

	lua_blame = (luagit2_blame *)lua_newuserdata(L, sizeof(*lua_blame));
	lua_blame->blame = NULL;

	luaL_newmetatable(L, "luagit2_blame");

	lua_setmetatable(L, -2);

	git_blame *local_blame ;
	check_error_long(git_blame_file(&local_blame, Repo->repo, path, NULL),
	    "Error In generating blame for the given file", NULL);
	lua_blame->blame  = local_blame;

	return 1;
}

int lua_git_blame_get_hunk_byindex (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_blame,index_num(int)");
	}

	const luagit2_blame *reference = (luagit2_blame *)luaL_checkudata(L, 1,"luagit2_blame");
	uint32_t index = luaL_checkinteger(L, 2);

	luagit2_blame_hunk *Blame_Hunk;

	Blame_Hunk = (luagit2_blame_hunk *)lua_newuserdata(L, sizeof(*Blame_Hunk));

	luaL_newmetatable(L, "luagit2_blame_hunk");

	lua_setmetatable(L, -2);

	Blame_Hunk->blame_hunk = git_blame_get_hunk_byindex(reference->blame, index);

	return 1;
}

int lua_git_blame_get_hunk_byline (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_blame,line_num(int)");
	}

	const luagit2_blame *reference = (luagit2_blame *)luaL_checkudata(L, 1,"luagit2_blame");
	size_t line_no = luaL_checkinteger(L, 2);

	luagit2_blame_hunk *Blame_Hunk;

	Blame_Hunk = (luagit2_blame_hunk *)lua_newuserdata(L, sizeof(*Blame_Hunk));

	luaL_newmetatable(L, "luagit2_blame_hunk");

	lua_setmetatable(L, -2);

	Blame_Hunk->blame_hunk = git_blame_get_hunk_byline(reference->blame, line_no);

	return 1;
}

int lua_git_blame_get_hunk_count (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blame");
	}

	const luagit2_blame *reference = (luagit2_blame *)luaL_checkudata(L, 1,"luagit2_blame");
	uint32_t count =  git_blame_get_hunk_count(reference->blame);

	lua_pushinteger(L, count);

	return 1;
}

int lua_git_blame_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument(s) : luagit2_blame");
	}

	const luagit2_blame *reference = (luagit2_blame *)luaL_checkudata(L, 1,"luagit2_blame");
	git_blame_free(reference->blame);

	return 1;
}
