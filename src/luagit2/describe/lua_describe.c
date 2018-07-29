#include "lua_describe.h"

int lua_git_describe_commit (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_object");
	}

	const luagit2_object *lua_object = (luagit2_object *)luaL_checkudata(L, 1, "luagit2_object");

	luagit2_describe_result *lua_describe_res = (luagit2_describe_result *)lua_newuserdata(L, sizeof(*lua_describe_res));
	lua_describe_res->describe_result  = NULL;

	luaL_newmetatable(L, "luagit2_describe_result");
	lua_setmetatable(L, -2);

	git_describe_result *local_describe_result;
	check_error_long(git_describe_commit(&local_describe_result, lua_object->object, NULL), // passing NULL for default values
	    "Error getting describe result for given commit object", NULL);

	lua_describe_res->describe_result = local_describe_result;

	return 1;
}

int lua_git_describe_workdir (lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_repository");
	}

	const luagit2_repository *Repo = (luagit2_repository *)luaL_checkudata(L, 1, "luagit2_repository");

	luagit2_describe_result *lua_describe_res = (luagit2_describe_result *)lua_newuserdata(L, sizeof(*lua_describe_res));
	lua_describe_res->describe_result  = NULL;

	luaL_newmetatable(L, "luagit2_describe_result");
	lua_setmetatable(L, -2);

	git_describe_result *local_describe_result;
	check_error_long(git_describe_workdir(&local_describe_result, Repo->repo, NULL), // passing NULL for default values
	    "Error getting describe result for given repo", NULL);

	lua_describe_res->describe_result = local_describe_result;

	return 1;
}

int lua_git_describe_format(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_describe_result");
	}

	const luagit2_describe_result *lua_describe_res = (luagit2_describe_result *)luaL_checkudata(L, 1, "luagit2_describe_result");

	luagit2_buf *lua_buf = (luagit2_buf *)lua_newuserdata(L, sizeof(*lua_buf));
	lua_buf->buf = NULL;

	luaL_newmetatable(L, "luagit2_buf");
	lua_setmetatable(L, -2);

	git_buf local_buf = GIT_BUF_INIT_CONST(NULL, 0);

	check_error_long(git_describe_format(&local_buf, lua_describe_res->describe_result, NULL),
	    "Error formatting describe result to buf ", NULL);

	lua_buf->buf  = &local_buf;

	return 1;
}

int lua_git_describe_result_free(lua_State *L) {

	if (lua_gettop(L) != 1) {
		return luaL_error(L, "expecting 1 argument : luagit2_describe_result");
	}

	luagit2_describe_result *lua_describe_res = (luagit2_describe_result *)luaL_checkudata(L, 1, "luagit2_describe_result");
	git_describe_result_free(lua_describe_res->describe_result);

	return 1;
}