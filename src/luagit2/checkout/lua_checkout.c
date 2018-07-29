#include "lua_checkout.h"

int lua_git_checkout_init_options (lua_State *L) {

	if (lua_gettop(L) != 0) {
		return luaL_error(L, "expecting no arguments");
	}

	luagit2_checkout_options *lua_checkout_opts = (luagit2_checkout_options *)lua_newuserdata(L, sizeof(*lua_checkout_opts));

	luaL_newmetatable(L, "luagit2_checkout_options");
	lua_setmetatable(L, -2);

	git_checkout_options local_checkout_opts;
	check_error_long(git_checkout_init_options(&local_checkout_opts, GIT_CHECKOUT_OPTIONS_VERSION),
	    "Error initializing checkout options", NULL);

	lua_checkout_opts->checkout_opts = local_checkout_opts;

	return 1;
}

int lua_git_checkout_head (lua_State *L) {

	if (lua_gettop(L) != 2) {
		return luaL_error(L, "expecting exactly 2 arguments : luagit2_repository,luagit2_checkout_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_checkout_options *lua_checkout_opts = (luagit2_checkout_options *)luaL_checkudata(L, 2, "luagit2_checkout_options");

	check_error_long(git_checkout_head( Repo->repo, &(lua_checkout_opts->checkout_opts)),
	    "Error checking out to HEAD", NULL);

	return 1;
}

int lua_git_checkout_index (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,luagit2_index,luagit2_checkout_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_index *lua_index = (luagit2_index *)luaL_checkudata(L, 2, "luagit2_index");
	const luagit2_checkout_options *lua_checkout_opts = (luagit2_checkout_options *)luaL_checkudata(L, 3, "luagit2_checkout_options");

	check_error_long(git_checkout_index( Repo->repo, lua_index->index, &(lua_checkout_opts->checkout_opts)),
	    "Error checking out index", NULL);

	return 1;
}

int lua_git_checkout_tree (lua_State *L) {

	if (lua_gettop(L) != 3) {
		return luaL_error(L, "expecting exactly 3 arguments : luagit2_repository,luagit2_object,luagit2_checkout_options");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");
	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 2, "luagit2_object");
	const luagit2_checkout_options *lua_checkout_opts = (luagit2_checkout_options *)luaL_checkudata(L, 3, "luagit2_checkout_options");

	check_error_long(git_checkout_tree( Repo->repo, lua_object->object, &(lua_checkout_opts->checkout_opts)),
	    "Error checking out index", NULL);

	return 1;
}
