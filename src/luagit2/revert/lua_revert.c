#include "lua_revert.h"

int lua_git_revert(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,luagit2_commit");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_commit *lua_commit = (luagit2_commit *)luaL_checkudata(L, 2, "luagit2_commit");

	check_error_long(git_revert(Repository->repo, lua_commit->commit, NULL), // passing null to do with default values
	    "Error doing a git revert for given commit ", NULL);

	return 0;
}
