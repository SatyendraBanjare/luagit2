#include "lua_hashsig.h"

int lua_git_hashsig_create_fromfile (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting 2 argument : (string)path,luagit2_hashsig_options");
	}

	const char *path = luaL_checkstring(L, 1);
	const luagit2_hashsig_options *lua_hashsig_options = (luagit2_hashsig_options *)luaL_checkudata(L, 2, "luagit2_hashsig_options");

	luagit2_hashsig *lua_hashsig = (luagit2_hashsig *)lua_newuserdata(L, sizeof(*lua_hashsig));
	lua_hashsig->hashsig = NULL;

	luaL_newmetatable(L, "luagit2_hashsig");
	lua_setmetatable(L, -2);

	git_hashsig *local_hashsig;
	check_error_long(git_hashsig_create_fromfile(&local_hashsig, path, lua_hashsig_options->hashsig_options),
	    "Error getting describe result for given commit object", NULL);

	lua_hashsig->hashsig = local_hashsig;

	return 1;
}

int lua_git_hashsig_compare (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting 2 argument : luagit2_hashsig,luagit2_hashsig");
	}

	const luagit2_hashsig *lua_hashsig_a = (luagit2_hashsig *)luaL_checkudata(L, 1, "luagit2_hashsig");
	const luagit2_hashsig *lua_hashsig_b = (luagit2_hashsig *)luaL_checkudata(L, 2, "luagit2_hashsig");

	int result = git_hashsig_compare(lua_hashsig_a->hashsig, lua_hashsig_b->hashsig);

	lua_pushinteger(L, result);

	return 1;
}

int lua_git_hashsig_free (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_hashsig");
	}

	const luagit2_hashsig *lua_hashsig = (luagit2_hashsig *)luaL_checkudata(L, 1, "luagit2_hashsig");
	git_hashsig_free(lua_hashsig->hashsig);

	return 1;
}

