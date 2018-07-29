#include "lua_revparse.h"

int lua_git_revparse(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository, (string)spec");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *spec = luaL_checkstring(L, 2);

	luagit2_revspec *lua_revspec = (luagit2_revspec *)lua_newuserdata(L, sizeof(*lua_revspec));
	lua_revspec->revspec = NULL;

	luaL_newmetatable(L, "luagit2_revspec");
	lua_setmetatable(L, -2);

	git_revspec local_revspec = {0};
	check_error_long(git_revparse(&local_revspec, Repository->repo, spec),
	    "Error parsing revision for given spec", NULL);

	lua_revspec->revspec  = &local_revspec;

	return 1;
}

int lua_git_revparse_single(lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository, (string)spec");
	}

	const luagit2_repository *Repository = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const char *spec = luaL_checkstring(L, 2);

	luagit2_object *lua_object = (luagit2_object *)lua_newuserdata(L, sizeof(*lua_object));
	lua_object->object = NULL;

	luaL_newmetatable(L, "luagit2_object");
	lua_setmetatable(L, -2);

	git_object *local_obj;

	check_error_long(git_revparse_single(&local_obj, Repository->repo, spec),
	    "Error parsing revision for given single spec ", NULL);
	lua_object->object = local_obj;

	return 1;
}
