#include "lua_ignore.h"

int lua_git_ignore_add_rule(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,(string)rule");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *rule = luaL_checkstring(L, 2);

	check_error_long(git_ignore_add_rule( Repository->repo, rule),
		"Error creating ignore rules for given repo", NULL);
	return 0;
}

int lua_git_ignore_clear_internal_rules(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting exactly 1 argument : luagit2_repository");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");

	check_error_long(git_ignore_clear_internal_rules( Repository->repo), 
		"Error clearing ignore rules for given repo", NULL);
	return 0;
}

int lua_git_ignore_path_is_ignored(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,(string)path");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *path = luaL_checkstring(L, 2);

	int is_ignored;
	check_error_long(git_ignore_path_is_ignored(&is_ignored, Repository->repo, path), 
		"Error creating ignore rules for given repo", NULL);
	lua_pushboolean(L,is_ignored);

	return 1;
}